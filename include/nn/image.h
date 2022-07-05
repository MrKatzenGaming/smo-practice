/**
 * @file image.h
 * @brief JPEG decoding library.
 */

#pragma once

#include "types.h"

namespace nn {
    namespace image
    {
        // there's probably more
        enum JpegStatus
        {
            OK = 0,
            INVALID_FORMAT = -32,
            UNSUPPORTED_FORMAT = -33,
            OUT_OF_MEMORY = -64,
        };

        enum PixelFormat
        {
            RGBA32,
            RGB24
        };

        enum ProcessStage
        {
            UNREGISTERED = 0,
            REGISTERED = 1,
            ANALYZED = 2
        };

        struct Dimension
        {
            f32 width;
            f32 height;
        };

        class JpegDecoder
        {
        public:
            JpegDecoder();
            virtual ~JpegDecoder();

            void SetImageData(void const *source, u64 size);
            nn::image::JpegStatus Analyze();
            nn::image::Dimension GetAnalyzedDimension() const;
            s64 GetAnalyzedWorkBufferSize() const;
            JpegStatus Decode(void *out, s64, s32 alignment, void *, s64);

            nn::image::ProcessStage mProcessStage;
            void* mData;
            s64 mSize;
            s32 _18;
            nn::image::PixelFormat mFormat;
            Dimension mImgDimensions;
            s64 _28;
            // rest is related to EXIF processing
        };
    };
};
