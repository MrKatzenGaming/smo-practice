/**
 * @file instance.h
 * @brief NEX Instance Controllers.
 */
#pragma once

#include "RootObject.h"

namespace nn {
    namespace nex
    {
        class InstanceTable;

        class InstanceControl : public nn::nex::RootObject
        {
        public:
            InstanceControl(u32, u32);

            u32 mInstanceContext;
            u32 mInstanceType;
            void* mDelegateInstance;
            bool mIsValidControl;
            u8 _19; // probably padding
            u8 _1A;
            u8 _1B;

            static nn::nex::InstanceTable* s_oInstanceTable;
        };

        class InstanceTable : public nn::nex::RootObject
        {
        public:
            InstanceTable();

            virtual ~InstanceTable();

            bool AddInstance(nn::nex::InstanceControl *, u32, u32);
            void DelInstance(nn::nex::InstanceControl *, u32, u32);
            u32 CreateContext();
            bool DeleteContext(u32);
            void AllocateExtraContexts(u64 size);
            void FreeExtraContexts();
            u32 GetHighestID() const;
            u32 FindInstanceContext(nn::nex::InstanceControl *, u32);

            u8 _0[0x94];
        };
    };
};
