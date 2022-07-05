#pragma once

#include <sead/prim/seadSafeString.h>

namespace al {
    
    template<int T>
    class StringTmp : public sead::BufferedSafeString {
    public:
        inline StringTmp() : sead::BufferedSafeString(this->mTop, T) {
            assureTerminationImpl_();
        }
    };
}
