#pragma once

#include <nn/account.h>


namespace al {
class AccountHolder {
public:
    virtual ~AccountHolder();

    nn::account::UserHandle* mUserHandle;
    nn::account::Uid mUid;
    unsigned char gap1[0x8];
    bool mIsValid;
};
}
