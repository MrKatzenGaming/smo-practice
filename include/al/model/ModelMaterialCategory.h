#pragma once

namespace al {
class ModelCtrl;
class Resource;
class MaterialCategoryKeeper;

class ModelMaterialCategory {
public:
    static void tryCreate(al::ModelCtrl*, al::Resource const*, const char*, al::MaterialCategoryKeeper*);
};
}
