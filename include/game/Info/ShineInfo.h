#pragma once

#include <sead/prim/seadSafeString.h>

#include "al/LiveActor/LiveActor.h"
#include "al/util.hpp"

struct ShineData; // unused class identical to this one (maybe)
struct QuestInfo;
struct UniqObjInfo;

namespace al {
    class IUseMessageSystem;
}

class ShineInfo {
    public:
        ShineInfo(void);

        void clear(void);
        void init(const char *, const char *, const char *, QuestInfo const *info, int shineId);
        void initForHintPhoto(const al::LiveActor *, const al::IUseMessageSystem *, const al::ActorInitInfo &);
        bool isEmpty(void) const;
        bool isEqual(const ShineInfo *) const;
        bool isEqual(const ShineData *) const;
        void writeShineData(ShineData *) const;
        void readShineData(ShineData *);
        void readShineData(const UniqObjInfo *);
        void copyShineInfo(const ShineInfo *);

        sead::FixedSafeString<128> stageName = sead::FixedSafeString<128>();
        sead::FixedSafeString<128> objectId = sead::FixedSafeString<128>();
        sead::FixedSafeString<128> scenObjId = sead::FixedSafeString<128>();

        int shineId;
        const QuestInfo *curQuest;
        bool unkA;
        unsigned long timeDay;
};
