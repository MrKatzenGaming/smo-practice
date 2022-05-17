#pragma once

namespace al
{
    class ByamlHeader
    {
    public:
        short getTag() const;
        bool isInvertOrder() const;
        short getVersion() const;
        int getHashKeyTableOffset() const;
        int getStringTableOffset() const;
        int getDataOffset() const;

        union
        {
            int _0;
            unsigned short mTag, mVersion;
        };

        int mHashKeyOffset;
        int mStringTableOffset;
        int mDataOffset;
    };
};
