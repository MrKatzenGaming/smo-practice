#include "al/util.hpp"
#include "smo/tas.h"
#include "smo/ui.h"
#include "smo/util.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include "game/StageScene/ChangeStageInfo.h"
#include <nn/mem.h>
#include "rs/util.hpp"
#include <sead/prim/seadSafeString.h>
#include "smo/packet.h"
#include <str.h>
#include <mem.h>
#include <nn/init.h>

namespace smo {
    u32 OutPacketLog::calcLen()
    {
        return strlen(message) + 1;
    }

    void OutPacketLog::construct(u8* dst)
    {
        *dst = type;
        strcpy((char*) dst + 1, message);
    }

    void InPacketPlayerScriptInfo::parse(const u8* data, u32 len)
    {
        smo::TasHolder& h = smo::TasHolder::instance();
        if (h.isRunning) return;
        scriptName = (char*) alloc(len + 1);
        smo::memcpy(scriptName, data, len);
        scriptName[len] = '\0';
    }

    void InPacketPlayerScriptInfo::on(Server &server)
    {
        smo::TasHolder& h = smo::TasHolder::instance();
        if (h.isRunning) return;
        h.setScriptName(scriptName);
        if (h.frames)
        {
            dealloc(h.frames);
            h.frames = nullptr;
        }
        h.frameCount = 0;
    }

    void InPacketPlayerTeleport::parse(const u8* data, u32 len)
    {
        pos.x = *(float*) &data[0];
        pos.y = *(float*) &data[4];
        pos.z = *(float*) &data[8];
    }

    void InPacketPlayerTeleport::on(Server &server)
    {
        StageScene* stageScene = smo::PracticeUI::instance().getStageScene();
        if (!stageScene) return;
        PlayerActorHakoniwa* player = static_cast<PlayerActorHakoniwa*>(rs::getPlayerActor(stageScene));
        player->startDemoPuppetable();
        al::setTrans(player, pos);
        player->endDemoPuppetable();
    }

    void InPacketPlayerGo::parse(const u8* data, u32 len)
    {
        nn::mem::StandardAllocator* m = nn::init::GetAllocator();

        scenario = *(signed char*) &data[0];
        u8 stageLength = data[1];
        u8 entranceLength = data[2];

        stageName = (char*) m->Allocate(stageLength + 1);
        smo::memcpy(stageName, &data[3], stageLength);
        stageName[stageLength] = '\0';

        entrance = (char*) m->Allocate(entranceLength + 1);
        smo::memcpy(entrance, &data[3 + stageLength], entranceLength);
        entrance[entranceLength] = '\0';

        startScript = data[len - 1];
    }

    void InPacketPlayerGo::on(Server& server)
    {
        nn::mem::StandardAllocator* m = nn::init::GetAllocator();
        StageScene* stageScene = smo::PracticeUI::instance().getStageScene();
        if (!stageScene)
        {
            if (entrance) m->Free(entrance);
            if (stageName) m->Free(stageName);
        }
        
        ChangeStageInfo info = ChangeStageInfo(stageScene->mDataHolder, entrance, stageName, false, scenario, {0});
        stageScene->mDataHolder->changeNextStage(&info, 0);

        if (entrance) m->Free(entrance);
        if (stageName) m->Free(stageName);

        if (startScript && smo::TasHolder::instance().frames) smo::TasHolder::instance().startPending = true;
    }

    void InPacketPlayerScriptData::parse(const u8* data, u32 len)
    {
        smo::TasHolder& h = smo::TasHolder::instance();
        if (h.isRunning) return;
        size_t cur = h.frameCount;
        if (h.frames)
        {
            h.frameCount += len / sizeof(smo::TasFrame);
            h.frames = (smo::TasFrame*) realloc(h.frames, h.frameCount * sizeof(smo::TasFrame));
        }
        else
        {
            h.frames = (smo::TasFrame*) alloc(len);
            h.frameCount = len / sizeof(smo::TasFrame);
        }
        smo::memcpy(&h.frames[cur], data, len);
    }

    void InPacketPlayerScriptData::on(Server& server) {}
}
