#include "CResource.h"

TypedArray<CResourceTag> CResource::get_tags() const
{
    return tags;
}

void CResource::set_tags(const TypedArray<CResourceTag>& tags_)
{
    this->tags = tags_;
}

void CResourceCount::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_count", "count"), &CResourceCount::set_count);
    ClassDB::bind_method(D_METHOD("get_count"), &CResourceCount::get_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "count"), "set_count", "get_count");

    ClassDB::bind_method(D_METHOD("set_resource", "resource"), &CResourceCount::set_resource);
    ClassDB::bind_method(D_METHOD("get_resource"), &CResourceCount::get_resource);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "resource", PROPERTY_HINT_RESOURCE_TYPE,"CResource"), "set_resource", "get_resource");
}


void CResource::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_tags", "tags"), &CResource::set_tags);
    ClassDB::bind_method(D_METHOD("get_tags"), &CResource::get_tags);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "tags", PROPERTY_HINT_ARRAY_TYPE, MAKE_RESOURCE_TYPE_HINT("CResourceTag")), "set_tags", "get_tags");
}
