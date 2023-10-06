#include "CResourceList.h"


void CResourceCountList::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_resources", "resourceList"), &CResourceCountList::set_resources);
    ClassDB::bind_method(D_METHOD("get_resources"), &CResourceCountList::get_resources);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "resources", PROPERTY_HINT_ARRAY_TYPE, MAKE_RESOURCE_TYPE_HINT("CResourceCount")), "set_resources",
        "get_resources");
}

TypedArray<CResourceCount> CResourceCountList::get_resources() const
{
    TypedArray<CResourceCount> returnList = {};
    for (auto r : this->resources)
    {
        returnList.append(r);
    }
    return returnList;
}

void CResourceCountList::set_resources(const TypedArray<CResourceCount>& resourceList)
{
    this->resources = {};
    for (int i = 0; i < resourceList.size(); ++i)
    {
        this->resources.append(resourceList[i]);
    }
}
