#include "CVisualDescription.h"

Ref<Texture2D> CVisualDescription::get_icon() const
{
    return icon;
}

void CVisualDescription::set_icon(const Ref<Texture2D> icon_)
{
    this->icon = icon_;
}

void CVisualDescription::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_icon", "icon"), &CVisualDescription::set_icon);
    ClassDB::bind_method(D_METHOD("get_icon"), &CVisualDescription::get_icon);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "icon", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_icon", "get_icon");
}
