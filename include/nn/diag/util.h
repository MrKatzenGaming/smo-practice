#pragma once

namespace nn {
    namespace diag
    {
        struct ModuleInfo
        {
            const char* modulePath;
            uintptr_t moduleAddr;
            size_t moduleSize;
        };

        size_t GetRequiredBufferSizeForGetAllModuleInfo();
        int GetAllModuleInfo(nn::diag::ModuleInfo **, void *, unsigned long);
    };
};
