#pragma once

#include "al/gfx/DrawSystemInfo.h"

namespace aal {
    struct IAudioFrameProcess;
} // namespace aal

namespace al {
    struct NetworkSystem;
    struct HtmlViewer;
    struct EffectSystem;
    struct LayoutSystem;
    struct MessageSystem;
    struct GamePadSystem;
    struct AudioSystem;
    struct WaveVibrationHolder; // :: aal::IAudioFrameProcess;
} // namespace al

struct ProjectNfpDirector;
struct ApplicationMessageReceiver;
struct Application;

class GameSystemInfo {
public:
    void *gap1;
    al::EffectSystem *mEffectSys;
    al::LayoutSystem *mLayoutSys;
    al::MessageSystem *mMessageSys;
    al::NetworkSystem *mNetworkSys;
    al::AudioSystem *mAudioSys;
    al::GamePadSystem *mGamePadSys;
    al::DrawSystemInfo *mDrawSystemInfo;
    ProjectNfpDirector *mProjNfpDirector;
    al::HtmlViewer *mHtmlViewer;
    ApplicationMessageReceiver *mMessageReciever;
    al::WaveVibrationHolder *mWaveVibrationHolder;
    void *gap2;
};
