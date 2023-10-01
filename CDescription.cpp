#include "CDescription.h"

String CDescription::get_resource_name() const
{
    return resource_name;
}

void CDescription::set_resource_name(const String& name_)
{
    this->resource_name = name_;
}

String CDescription::get_short_description() const
{
    return short_description;
}

void CDescription::set_short_description(const String& short_description_)
{
    this->short_description = short_description_;
}

String CDescription::get_full_description() const
{
    return full_description;
}

void CDescription::set_full_description(const String& full_description_)
{
    this->full_description = full_description_;
}

void CDescription::_bind_methods()
{
    // Name
    ClassDB::bind_method(D_METHOD("set_resource_name", "resource_name"), &CDescription::set_resource_name);
    ClassDB::bind_method(D_METHOD("get_resource_name"), &CDescription::get_resource_name);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "resource_name"), "set_resource_name", "get_resource_name");
    // Short Description
    ClassDB::bind_method(D_METHOD("set_short_description", "short_description"), &CDescription::set_short_description);
    ClassDB::bind_method(D_METHOD("get_short_description"), &CDescription::get_short_description);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "short_description"), "set_short_description", "get_short_description");
    // Full Description
    ClassDB::bind_method(D_METHOD("set_full_description", "full_description"), &CDescription::set_full_description);
    ClassDB::bind_method(D_METHOD("get_full_description"), &CDescription::get_full_description);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "full_description"), "set_full_description", "get_full_description");
}
