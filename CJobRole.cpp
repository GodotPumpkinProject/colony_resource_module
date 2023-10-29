#include "CJobRole.h"


void CJobRole::_bind_methods()
{
    ;
}

void CJobRoleCount::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_count", "count"), &CJobRoleCount::set_count);
    ClassDB::bind_method(D_METHOD("get_count"), &CJobRoleCount::get_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "count"), "set_count", "get_count");

    ClassDB::bind_method(D_METHOD("set_job", "job"), &CJobRoleCount::set_job);
    ClassDB::bind_method(D_METHOD("get_job"), &CJobRoleCount::get_job);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "resource", PROPERTY_HINT_RESOURCE_TYPE,"CJobRole"), "set_job", "get_job");
}
