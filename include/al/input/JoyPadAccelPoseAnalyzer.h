#pragma once

#include <sead/math/seadVector.h>

namespace al {

class JoyPadAccelPoseAnalyzer {
public:
    class HistoryInfo {
    public:
        void calcHistory(sead::Vector3f const&, sead::Vector3f const&, float);

        unsigned char padding_0[0x60];
        float hist0;
        unsigned char padding_1[0x70 - 0x64];
        float hist1;
        unsigned char padding_2[0x1c];
    };

    class PoseAxisDir {
    public:
        void calcHistory(sead::Vector3f const&, sead::Vector3f const&);

        unsigned char padding_1[0x88];
        sead::Vector2f unkVec0;
        unsigned char padding_0[0x98 - (0x88 + 0x8)];
    };

    bool isSwingAnyHand() const;
    bool isSwingDoubleHandSameDir() const;
    bool isSwingDoubleHand() const;
    bool isSwingDoubleHandReverseDir() const;
    bool isSwingDoubleHandReverseInsideDir() const;
    bool isSwingDoubleHandReverseOutsideDir() const;
    bool isSwingLeftHand() const;
    bool isSwingRightHand() const;
    void setSwingBorder(float, float);
    void update();
    sead::Vector2f getSwingDirDoubleHandSameDir() const;

    int mControllerPort;                // port of the controller
    int mAccelDeviceNum;                // number of accelerometers
    bool gap00;                         // unknown
    bool mSwingLeft;                    // shaking the left joycon
    bool mSwingRight;                   // shaking the right joycon
    bool mSwingAny;                     // shaking anything
    sead::Vector2f mSwingBorder;        // Border to trigger a motion shake
    sead::Vector2f mAccelLeftVel;       // Accelerometer of the Left Joycon
    sead::Vector2f mAccelRightVel;      // Accelerometer of the Right Joycon
    sead::Vector2f mAccelCombinedVel;   // Combined vectors of the left and right joycons
    sead::Vector2f mAccelLeftAccel;     // Acceleration of the left joycon
    sead::Vector2f mAccelRightAccel;    // Acceleration of the right joycon
    sead::Vector2f mGyroRoll;           // Roll of the gyroscope, each component is left/right joycon.
    unsigned char padding_0[0x4];
    HistoryInfo mHistoryLeft;           // History info of the left joycon
    HistoryInfo mHistoryRight;          // History info of the right joycon
    bool gap01;                         // unknown
    unsigned char padding_1[0x7];
    PoseAxisDir unknown0;
    PoseAxisDir unknown1;
    PoseAxisDir unknown2;
};

}   // namespace al
