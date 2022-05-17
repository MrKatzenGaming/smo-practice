/**
 * @file GameDataFile.h
 * @brief Holds data for an individual save file.
 */

#pragma once

#include "game/Player/PlayerHitPointData.h"
#include "sead/math/seadVector.h"
#include "sead/prim/seadSafeString.h"
#include <sead/container/seadPtrArray.h>
#include <sead/time/seadDateTime.h>
#include "types.h"
#include "game/StageScene/ChangeStageInfo.h"
#include "GameProgressData.h"


class Shine;
struct GameDataShine {
    sead::BufferedSafeString mStageName;
    unsigned char gap1[0x80];
    sead::BufferedSafeString mObjId;
    unsigned char gap2[0x80];
    const char* sVar2;
    sead::BufferedSafeString mObjectName;
    unsigned char gap3[0x40];
    sead::Vector3f mHintTrans;
    sead::Vector3f mTrans;
    unsigned char gap4[0x20];
    int mMainScenarioNo;
    int mWorldId;
    bool mIsMoonRock;
    bool mIsGot;
    bool mIsAchievementShine;
    bool mIsGrand;
    bool mIsShopShine;
    int iVar2;
    int mHintStatus;
    int iVar4;
    sead::DateTime mGetTime;
    int mUniqueId;
    sead::SafeString mOptionalId;
    unsigned char gap5[0x28];
    unsigned int mProgressBitFlag;
    bool mDisableHintById;
    bool bVar3;
};

struct GameDataShineList {
    GameDataShine mShineData[1024];
};

class GameDataHolder;
class ChangeStageInfo;
class ShineInfo;
class UniqObjInfo;
class SphinxQuizData;
class TimeBalloonSaveData;
class WorldWarpTalkData;
class VisitStageData;
class MoonRockData;
class BossSaveData;
class AchievementSaveData;
class SearchAmiiboDataTable;
class NetworkUploadFlag;
class SequenceDemoSkipData;
class HintPhotoData;
class ShopTalkData;
class RaceRecord;
class GameDataFile {
public:
    void wearCostume(char const *);
    void wearCap(char const *);
    void changeNextStage(ChangeStageInfo const*, int);
    PlayerHitPointData* getPlayerHitPointData() const;
    bool isGotShine(const ShineInfo*) const;
    void setGotShine(const ShineInfo*);
    int calcGetShineNumByObjectNameOrOptionalId(const char *, int);
    void calcShineIndexTableNameUnlockable(int* table, int* count, int worldId);

    ShineInfo* mShineInfo1;
    void* gap1;
    ShineInfo* mLatestGetShineInfo;
    int* mShopShine;
    int* piVar1;
    int iVar2;
    sead::FixedSafeString<128> sVar1;
    sead::FixedSafeString<128> sVar2;
    sead::FixedSafeString<128> sVar3;
    sead::FixedSafeString<128> mCheckpointName;
    sead::FixedSafeString<128> sVar4;
    sead::FixedSafeString<128> mStageNameCurrent;
    sead::FixedSafeString<128> sVar5;
    bool bVar1;
    bool bVar2;
    bool* mWorldWarpHoleThrough;
    unsigned char gap9[0x20];
    UniqObjInfo** uVar1;
    sead::FixedSafeString<128> sVar6;
    unsigned char gap10[0x18];
    void* gap11;
    unsigned char gap12[0x60];
    int* mPayShineNum;
    bool mIsPayShineAllInAllWorld;
    int mKeyNum;
    int mOpenDoorLockNum;
    UniqObjInfo** uVar2;
    UniqObjInfo** uVar3;
    sead::FixedSafeString<128>* mPlantedSeeds;
    int mCoinNum;
    int mTotalCoinNum;
    int mPlayerJumpCount;
    int mPlayerThrowCapCount;
    int* mUseCoinCollectNum;
    int* gap13;
    bool mIsPlayDemoOpening;
    bool mIsEnableCap;
    bool bVar3;
    bool* mSessionMemberNum;
    int mSessionEventProgress;
    bool mIsPayCoinToSphinx;
    SphinxQuizData* mSphinxQuizData;
    bool* mTalkLocalLanguage;
    bool mIsHintNpcFirstTalk;
    bool mIsKinopioBrigadeNpcFirstTalk;
    int mCapStatusForJango;
    int iVar9;
    int mJangoCount;
    TimeBalloonSaveData* mTimeBalloonSaveData;
    sead::FixedSafeString<64> mWorldTravellingStatus;
    bool mIsStartWorldTravelingPeach;
    bool mIsPlayAlreadyWorldWarp;
    bool mIsTalkFirstAmiiboNpc;
    bool mIsUnlockAchievement;
    WorldWarpTalkData* mWorldWarpTalkData;
    VisitStageData* mVisitStageData;
    GameProgressData *mGameProgressData;
    MoonRockData* mMoonRockData;
    BossSaveData* mBossSaveData;
    AchievementSaveData* mAchievementSaveData;
    SearchAmiiboDataTable* mSearchAmiiboDataTable;
    NetworkUploadFlag* mNetworkUploadFlag;
    SequenceDemoSkipData* mSequenceDemoSkipData;
    HintPhotoData* mHintPhotoData;
    ulong mPlayTimeTotal;
    sead::SafeString* psVar1;
    sead::SafeString* psVar2;
    sead::SafeString* psVar3;
    sead::SafeString* psVar4;
    sead::FixedSafeString<64> mCurrentClothName;
    sead::FixedSafeString<64> mCurrentCapName;
    bool mIsCostumeRandom;
    bool mIsCapRandom;
    void* gap17;
    bool mIsRideSphinx;
    bool mIsRideMotorcycle;
    int* mScenarioNo;
    sead::PtrArray<RaceRecord> arr1;
    unsigned char gap18[0x8];
    int mJumpingRopeBestCount;
    int iVar1;
    bool mIsExistRecordJumpingRope;
    int mVolleyballBestCount;
    int mVolleyballDayCount;
    bool mIsExistRecordVolleyball;
    bool bVar28;
    int mNextWorldId;
    int mPrevWorldId;
    bool mIsPlayDemoPlayerDownForBattleKoopaAfter;
    void* gap19;
    bool mIsKidsMode;
    unsigned char gap20[0x7];
    int iVar3;
    void* gap21;
    bool mIsTalkKakku;
    bool mIsTalkWorldTravelingPeach;
    bool mIsTalkCollectBgmNpc;
    int mTokimekiMayorNpcFavorabilityRating;
    bool mFirstNetwork;
    GameDataHolder* mDataHolder;
    int* mShineNum;
    PlayerHitPointData* mHitPointData;
    sead::FixedSafeString<128> mStageNameNext;
    bool mIsStageHakoniwa;
    bool bVar5;
    int iVar4;
    sead::FixedSafeString<128> sVar9;
    GameDataShineList* mShineList;
    sead::PtrArrayImpl arr2;
    int iVar5;
    int** ppiVar1;
    sead::PtrArrayImpl arr3;
    int iVar6;
    int iVar7;
    sead::SafeString sVar10;
    int mWorldId;
    int mWorldId2;  // maybe wrong
    int iVar8;
    bool bVar6;
    bool bVar7;
    bool bVar23;
    void* gap24;
    bool bVar8;
    bool bVar9;
    bool bVar10;
    int* mShinesPreMoonRock;
    int* mShinesPostMoonRock;
    unsigned char gap25[0xc];
    bool bVar11;
    ChangeStageInfo* uVar4;
    ChangeStageInfo* uVar5;
    bool bVar12;
    bool bVar13;
    unsigned char gap26[0xa];
    int mRaceRivalLevel;
    int mLastRaceRanking;
    void* gap27;
    ShopTalkData* mShopTalkData;
    void* gap28;
    bool mShowExplainCheckpointFlag;
    unsigned char gap29[0x8];
    sead::Vector3f mHomeTrans;
    bool bVar14;
    sead::Vector3f vVar2;
    bool bVar15;
    sead::Vector3f vVar3;
    bool bVar16;
    sead::Vector3f vVar4;
    bool bVar17;
    sead::Vector3f vVar5;
    bool bVar18;
    sead::Vector3f vVar6;
    bool bVar19;
    sead::Vector3f vVar7;
    bool bVar20;
    sead::Vector3f vVar8;
    bool bVar21;
    sead::Vector3f vVar9;
    bool bVar22;
    sead::Vector3f mPoetterTrans;
    bool mIsExistPoetter;
    sead::Vector3f vVar10;
    bool bVar24;
    sead::Vector3f vVar11;
    bool bVar25;
    void* gap30;
    unsigned char gap31[0x8];
    void* gap32;
    unsigned char gap33[0xc];
    bool bVar26;
    bool bVar27;
};
