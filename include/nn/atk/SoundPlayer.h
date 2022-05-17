/**
 * @file SoundPlayer.h
 * @brief Sound player.
 */

#pragma once

#include "types.h"

namespace nn
{
    namespace atk
    {
        enum PauseMode
        {

        };

        class SoundPlayer
        {
        public:
            SoundPlayer();
            ~SoundPlayer();

            void StopAllSound(s32);
            void Update();
            void DoFreePlayerHeap();
            void detail_SortPriorityList(bool);
            void PauseAllSound(s32, bool);
            void PauseAllSound(bool, s32, nn::atk::PauseMode);
            void SetVolume(f32 vol);
            void SetLowPassFilterFrequency(f32 filterFreq);
            void SetBiquadFilter(s32 filterType, f32 baseFreq);
            void SetDefaultOutputLine(u32 line);

            void detail_SetPlayableSoundLimit(s32 limit);
            bool CanPlaySound(s32);

            u64 _0;
            u64 _8;
            u64 _10;
            u64 _18;
            u64 _20;
            u64 _28;
            u64 _30;
            u64 _38;
            s32 _40;
            s32 mPlayableSoundCount;
            s32 _48;
            f32 mVolume;
            f32 mLowPassFreq;
            s32 mFilterType;
            f32 mBaseFreq;
            u32 mDefaultOutputLine;
            f32 mOutputVolume;
            u64 _64;
            u64 _6C;
        };
    };
};
