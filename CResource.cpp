#include "CResource.h"

TypedArray<CResourceTag> CResource::get_tags() const
{
    return tags;
}

void CResource::set_tags(const TypedArray<CResourceTag>& tags_)
{
    this->tags = tags_;
}

void CResource::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_tags", "tags"), &CResource::set_tags);
    ClassDB::bind_method(D_METHOD("get_tags"), &CResource::get_tags);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "tags",  PROPERTY_HINT_ARRAY_TYPE, MAKE_RESOURCE_TYPE_HINT("CResourceTag")), "set_tags", "get_tags");
}
