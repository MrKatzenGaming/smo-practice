#pragma once

#include "al/byaml/ByamlSave.h"

class GameConfigData : public al::ByamlSave {
public:
    int mCameraStickSensitivityLevel;
    bool mIsCameraReverseInputH;
    bool mIsCameraReverseInputV;
    bool mIsValidCameraGyro;
    int mCameraGyroSensitivityLevel;
    bool mIsUseOpenListAdditionalButton;
    bool mIsValidPadRumble;
    int mPadRumbleLevel;
};
