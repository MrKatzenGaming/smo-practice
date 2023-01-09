#pragma once

#include "al/util.hpp"
#include <sead/math/seadMatrix.h>
#include <sead/math/seadQuat.h>
#include <sead/math/seadVector.h>

namespace al {
class LiveActor;

class ActorPoseKeeperBase {
public:
    ActorPoseKeeperBase();

    virtual const sead::Vector3f& getRotate() const;
    virtual const sead::Vector3f& getScale() const;
    virtual const sead::Vector3f& getVelocity() const;
    virtual const sead::Vector3f& getFront() const;
    virtual const sead::Vector3f& getUp() const;
    virtual const sead::Quatf& getQuat() const;
    virtual const sead::Vector3f& getGravity() const;
    virtual const sead::Matrix34f& getMtx() const;
    virtual sead::Vector3f* getRotatePtr();
    virtual sead::Vector3f* getScalePtr();
    virtual sead::Vector3f* getVelocityPtr();
    virtual sead::Vector3f* getFrontPtr();
    virtual sead::Vector3f* getUpPtr();
    virtual sead::Quatf* getQuatPtr();
    virtual sead::Vector3f* getGravityPtr();
    virtual sead::Matrix34f* getMtxPtr();
    virtual void updatePoseTrans(const sead::Vector3f &) = 0;
    virtual void updatePoseRotate(const sead::Vector3f &) = 0;
    virtual void updatePoseQuat(const sead::Quatf &) = 0;
    virtual void updatePoseMtx(const sead::Matrix34f *) = 0;
    virtual void copyPose(const al::ActorPoseKeeperBase *);
    virtual void calcBaseMtx(sead::Matrix34f *) = 0;

    sead::Vector3f mTrans;

    static const sead::Vector3f sDefaultVelocity;
};

class ActorPoseKeeperTRSV : public ActorPoseKeeperBase {
public:
    virtual const sead::Vector3f& getRotate() const;
    virtual const sead::Vector3f& getScale() const;
    virtual const sead::Vector3f& getVelocity() const;

    virtual sead::Vector3f* getRotatePtr();
    virtual sead::Vector3f* getScalePtr();
    virtual sead::Vector3f* getVelocityPtr();

    virtual void updatePoseTrans(const sead::Vector3f &);
    virtual void updatePoseRotate(const sead::Vector3f &);
    virtual void updatePoseQuat(const sead::Quatf &);
    virtual void updatePoseMtx(const sead::Matrix34f *);

    virtual void calcBaseMtx(sead::Matrix34f *);

    sead::Vector3f mRotation;
    sead::Vector3f mScale;
    sead::Vector3f mVelocity;
};

class ActorPoseKeeperTRMSV : public ActorPoseKeeperBase {
public:
    virtual const sead::Vector3f& getRotate() const;
    virtual const sead::Vector3f& getScale() const;
    virtual const sead::Vector3f& getVelocity() const;
    virtual const sead::Matrix34f& getMtx() const;

    virtual sead::Vector3f* getRotatePtr();
    virtual sead::Vector3f* getScalePtr();
    virtual sead::Vector3f* getVelocityPtr();
    virtual sead::Matrix34f* getMtxPtr();

    virtual void updatePoseTrans(const sead::Vector3f &);
    virtual void updatePoseRotate(const sead::Vector3f &);
    virtual void updatePoseQuat(const sead::Quatf &);
    virtual void updatePoseMtx(const sead::Matrix34f *);

    virtual void calcBaseMtx(sead::Matrix34f *);

    sead::Vector3f mRotation;
    sead::Vector3f mScale;
    sead::Vector3f mVelocity;
    sead::Matrix34f mMtx;
};

class ActorPoseKeeperTRGMSV : public ActorPoseKeeperBase {
public:
    virtual const sead::Vector3f& getRotate() const;
    virtual const sead::Vector3f& getScale() const;
    virtual const sead::Vector3f& getVelocity() const;
    virtual const sead::Vector3f& getGravity() const;
    virtual const sead::Matrix34f& getMtx() const;

    virtual sead::Vector3f* getRotatePtr();
    virtual sead::Vector3f* getScalePtr();
    virtual sead::Vector3f* getVelocityPtr();
    virtual sead::Vector3f* getGravityPtr();
    virtual sead::Matrix34f* getMtxPtr();

    virtual void updatePoseTrans(const sead::Vector3f &);
    virtual void updatePoseRotate(const sead::Vector3f &);
    virtual void updatePoseQuat(const sead::Quatf &);
    virtual void updatePoseMtx(const sead::Matrix34f *);
    
    virtual void calcBaseMtx(sead::Matrix34f *);

    sead::Vector3f mRotate;
    sead::Vector3f mGravity;
    sead::Vector3f mScale;
    sead::Vector3f mVelocity;
    sead::Matrix34f mMtx;
};

class ActorPoseKeeperTFSV : public ActorPoseKeeperBase {
public:
    virtual const sead::Vector3f& getScale() const;
    virtual const sead::Vector3f& getVelocity() const;
    virtual const sead::Vector3f& getFront() const;

    virtual sead::Vector3f* getScalePtr();
    virtual sead::Vector3f* getVelocityPtr();
    virtual sead::Vector3f* getFrontPtr();

    virtual void updatePoseTrans(const sead::Vector3f &);
    virtual void updatePoseRotate(const sead::Vector3f &);
    virtual void updatePoseQuat(const sead::Quatf &);
    virtual void updatePoseMtx(const sead::Matrix34f *);
    
    virtual void calcBaseMtx(sead::Matrix34f *);

    sead::Vector3f mFront;
    sead::Vector3f mScale;
    sead::Vector3f mVelocity;
};

class ActorPoseKeeperTFUSV : public ActorPoseKeeperTFSV {
public:
    virtual const sead::Vector3f& getUp() const;

    virtual sead::Vector3f* getUpPtr();

    virtual void updatePoseTrans(const sead::Vector3f &);
    virtual void updatePoseRotate(const sead::Vector3f &);
    virtual void updatePoseQuat(const sead::Quatf &);
    virtual void updatePoseMtx(const sead::Matrix34f *);
    
    virtual void calcBaseMtx(sead::Matrix34f *);

    sead::Vector3f mUp;
    bool mIsFrontUp;
};

class ActorPoseKeeperTFGSV : public ActorPoseKeeperTFSV {
public:
    virtual const sead::Vector3f& getGravity() const;

    virtual sead::Vector3f* getGravityPtr();

    virtual void updatePoseTrans(const sead::Vector3f &);
    virtual void updatePoseRotate(const sead::Vector3f &);
    virtual void updatePoseQuat(const sead::Quatf &);
    virtual void updatePoseMtx(const sead::Matrix34f *);
    
    virtual void calcBaseMtx(sead::Matrix34f *);

    sead::Vector3f mGravity;
};

class ActorPoseKeeperTQSV : public ActorPoseKeeperBase {
public:
    virtual const sead::Vector3f& getScale() const;
    virtual const sead::Vector3f& getVelocity() const;
    virtual const sead::Quatf& getQuat() const;

    virtual sead::Vector3f* getScalePtr();
    virtual sead::Vector3f* getVelocityPtr();
    virtual sead::Quatf* getQuatPtr();

    virtual void updatePoseTrans(const sead::Vector3f &);
    virtual void updatePoseRotate(const sead::Vector3f &);
    virtual void updatePoseQuat(const sead::Quatf &);
    virtual void updatePoseMtx(const sead::Matrix34f *);
    
    virtual void calcBaseMtx(sead::Matrix34f *);

    sead::Quatf mQuat;
    sead::Vector3f mScale;
    sead::Vector3f mVelocity;
};

class ActorPoseKeeperTQGSV : public ActorPoseKeeperBase {
public:
    virtual const sead::Vector3f& getScale() const;
    virtual const sead::Vector3f& getVelocity() const;
    virtual const sead::Quatf& getQuat() const;
    virtual const sead::Vector3f& getGravity() const;

    virtual sead::Vector3f* getScalePtr();
    virtual sead::Vector3f* getVelocityPtr();
    virtual sead::Quatf* getQuatPtr();
    virtual sead::Vector3f* getGravityPtr();

    virtual void updatePoseTrans(const sead::Vector3f &);
    virtual void updatePoseRotate(const sead::Vector3f &);
    virtual void updatePoseQuat(const sead::Quatf &);
    virtual void updatePoseMtx(const sead::Matrix34f *);
    
    virtual void calcBaseMtx(sead::Matrix34f *);

    sead::Quatf mQuat;
    sead::Vector3f mGravity;
    sead::Vector3f mScale;
    sead::Vector3f mVelocity;
};

class ActorPoseKeeperTQGMSV : public ActorPoseKeeperBase {
public:
    virtual const sead::Vector3f& getScale() const;
    virtual const sead::Vector3f& getVelocity() const;
    virtual const sead::Quatf& getQuat() const;
    virtual const sead::Vector3f& getGravity() const;
    virtual const sead::Matrix34f& getMtx() const;

    virtual sead::Vector3f* getScalePtr();
    virtual sead::Vector3f* getVelocityPtr();
    virtual sead::Quatf* getQuatPtr();
    virtual sead::Vector3f* getGravityPtr();
    virtual sead::Matrix34f* getMtxPtr();

    virtual void updatePoseTrans(const sead::Vector3f &);
    virtual void updatePoseRotate(const sead::Vector3f &);
    virtual void updatePoseQuat(const sead::Quatf &);
    virtual void updatePoseMtx(const sead::Matrix34f *);
    
    virtual void calcBaseMtx(sead::Matrix34f *);

    sead::Quatf mQuat;
    sead::Vector3f mGravity;
    sead::Vector3f mScale;
    sead::Vector3f mVelocity;
    sead::Matrix34f mMtx;
};


void initActorPoseT(al::LiveActor*, sead::Vector3f const&);
void initActorPoseTR(al::LiveActor*, sead::Vector3f const&, sead::Vector3f const&);
void initActorPoseTRSV(al::LiveActor*);
void initActorPoseTRMSV(al::LiveActor*);
void initActorPoseTRGMSV(al::LiveActor*);
void initActorPoseTFSV(al::LiveActor*);
void initActorPoseTFUSV(al::LiveActor*);
void initActorPoseTFGSV(al::LiveActor*);
void initActorPoseTQSV(al::LiveActor*);
void initActorPoseTQGSV(al::LiveActor*);
void initActorPoseTQGMSV(al::LiveActor*);

typedef void (*initPose)(al::LiveActor* actor);
}

static al::NameToCreator<al::initPose> poseInits[] = { 
    {"TRSV", &al::initActorPoseTRSV},
    {"TRMSV", &al::initActorPoseTRMSV},
    {"TRGMSV", &al::initActorPoseTRGMSV},
    {"TFSV", &al::initActorPoseTFSV},
    {"TFUSV", &al::initActorPoseTFUSV},
    {"TFGSV", &al::initActorPoseTFGSV},
    {"TQSV", &al::initActorPoseTQSV},
    {"TQGSV", &al::initActorPoseTQGSV},
    {"TQGMSV", &al::initActorPoseTQGMSV}
};
