#pragma once

#include "al/area/AreaObjGroup.h"
#include "al/area/AreaObj.h"
#include "al/collision/HitInfo.h"
#include "al/LiveActor/LiveActorKit.h"
#include "al/PlayerHolder/PlayerHolder.h"
#include "al/scene/Scene.h"
#include "al/util.hpp"
#include "game/StageScene/StageScene.h"

#include <sead/gfx/seadPrimitiveRenderer.h>
#include <agl/DrawContext.h>


float calcFadeoff(al::LiveActor const *actor, sead::Vector3f pos2);
// bool tryDrawAreaGroup(al::Scene *curScene, char const *area, bool isDrawSolid, sead::Color4f wire, sead::Color4f solid, sead::Color4f cyl);
void drawAreaObjGroup(sead::PrimitiveRenderer* renderer, al::AreaObjGroup *group, bool isDrawSolid = false, sead::Color4f wire = sead::Color4f(0.0f, 1.0f, 0.0f, 0.1f), sead::Color4f solid = sead::Color4f(0.0f, 1.0f, 0.0f, 0.1f), sead::Color4f cyl = sead::Color4f(0.0f, 1.0f, 0.0f, 0.1f));
void drawAreaObj(sead::PrimitiveRenderer* renderer, al::AreaObj* area, bool isDrawSolid = false, sead::Color4f wire = sead::Color4f(0.0f, 1.0f, 0.0f, 0.5f), sead::Color4f solid = sead::Color4f(0.0f, 1.0f, 0.0f, 0.1f), sead::Color4f cyl = sead::Color4f(0.0f, 1.0f, 0.0f, 0.1f));
void drawHitInfo(sead::PrimitiveRenderer* renderer, al::HitInfo* hitInfo, sead::Color4f wire = sead::Color4f(0.96f, 0.96f, 0.86f, 0.8f), sead::Color4f solid = sead::Color4f(1.0f, 0.1f, 0.1f, 0.3f));

