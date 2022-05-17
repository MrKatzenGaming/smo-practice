/**
 * @file SoundArchivePlayer.h
 * @brief Basic sound player from a sound archive.
 */

#pragma once

#include "detail/AdvancedWaveSoundRuntime.h"
#include "detail/SequenceSoundRuntime.h"
#include "detail/SoundArchiveManager.h"
#include "detail/StreamSoundRuntime.h"
#include "detail/WaveSoundRuntime.h"

namespace nn
{
    namespace atk
    {
        class SoundArchivePlayer
        {
        public:
            SoundArchivePlayer();

            virtual ~SoundArchivePlayer();

            bool IsAvailable() const;
            void Finalize();
            void StopAllSound(s32, bool);
            void DisposeInstances();

            nn::atk::detail::SoundArchiveManager mArchiveManager;
            nn::atk::detail::SequenceSoundRuntime mSeqSoundRuntime;
            nn::atk::detail::WaveSoundRuntime mWaveSoundRuntime;
            nn::atk::detail::AdvancedWaveSoundRuntime mAdvancedWaveSound;
            nn::atk::detail::StreamSoundRuntime mStreamSoundRuntime;
            u64 _290;
            u32 _298;
            u8 _29C[0x2E8-0x29C];
        };
    };
};
