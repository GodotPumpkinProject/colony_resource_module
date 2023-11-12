#include "ResourceServer.h"


void ColonyResourceServer::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("AddResource", "resource", "count"), &ColonyResourceServer::AddResource);
    ClassDB::bind_method(D_METHOD("RemoveResource", "resource", "count"), &ColonyResourceServer::RemoveResource);
    ClassDB::bind_method(D_METHOD("GetResourceCount", "resource"), &ColonyResourceServer::GetResourceCount);
    ClassDB::bind_method(D_METHOD("AddResourceList", "resourceList"), &ColonyResourceServer::AddResourceList);
    ClassDB::bind_method(D_METHOD("RemoveResourceList", "resourceList"), &ColonyResourceServer::RemoveResourceList);
    ClassDB::bind_method(D_METHOD("HasResourceQuantity", "resourceList"), &ColonyResourceServer::HasResourceQuantity);
    ClassDB::bind_method(D_METHOD("GetResources"), &ColonyResourceServer::GetResources);
    ClassDB::bind_method(D_METHOD("PrintObject"), &ColonyResourceServer::PrintObject);
    ADD_SIGNAL(MethodInfo("resources_update"));

}

void ColonyResourceServer::AddResource(const Ref<CResource> resource, float count)
{
    if (resource.is_null()){ return; }
    
    if (this->resourceMap.find(resource) == this->resourceMap.end())
    {
        this->resourceMap.emplace(resource, count);
    }
    else
    {
        this->resourceMap[resource] += count;
    }

    emit_signal("resources_update");
}

void ColonyResourceServer::RemoveResource(const Ref<CResource> resource, float count)
{
    if (resource.is_null()){ return; }
    
    if (this->resourceMap.find(resource) == this->resourceMap.end())
    {
        print_error("Attempted to remove resource which did not exist.  Name=" + resource->get_name());
    }
    else
    {
        this->resourceMap[resource] -= count;
        if (this->resourceMap[resource] < 0)
        {
            print_error("Reduced count below zero for Name=" + resource->get_name());
        }
    }
    emit_signal("resources_update");
    
}

float ColonyResourceServer::GetResourceCount(const Ref<CResource> resource)
{
    if (resource.is_null()){ return 0; }
    
    if (this->resourceMap.find(resource) != this->resourceMap.end())
    {
        return this->resourceMap[resource];
    }
    return 0;
}

void ColonyResourceServer::PrintObject()
{
    print_line("Printing Resource Server Contents");
    for (auto iter = this->resourceMap.begin(); iter != this->resourceMap.end(); ++iter)
    {
        auto k = iter->first;
        print_line(" {" + k->get_resource_name() + "} = " + itos(this->resourceMap[k]));
    }
}

void ColonyResourceServer::AddResourceList(const Ref<CResourceCountList> resourceList)
{
    if (resourceList.is_null()){ return; }
    
    for (auto r : resourceList->GetResources())
    {
        this->AddResource(r->get_resource(), r->get_count());
    }
}

void ColonyResourceServer::RemoveResourceList(const Ref<CResourceCountList> resourceList)
{
    if (resourceList.is_null()){ return; }
    
    for (auto r : resourceList->GetResources())
    {
        this->RemoveResource(r->get_resource(), r->get_count());
    }
}

bool ColonyResourceServer::HasResourceQuantity(const Ref<CResourceCountList> resourceList)
{
    if (resourceList.is_null()){ return true; }
    
    for (auto r : resourceList->GetResources())
    {
        if (GetResourceCount(r->get_resource()) <r->get_count()){ return false;}
    }
    return true;
}

Ref<CResourceCountList> ColonyResourceServer::LackingResourceQuantity(const Ref<CResourceCountList> resourceList)
{
    if (resourceList.is_null()){ return NULL; }
    
    Ref<CResourceCountList> returnList = Ref<CResourceCountList>(memnew(CResourceCountList()));
    
    for (auto r : resourceList->GetResources())
    {
        // If we do not have enough (positive)
        const auto lackingAmount = r->get_count() - GetResourceCount(r->get_resource()) ;
        if (lackingAmount > 0.0)
        {
            returnList->add_resource(r);
        }
        // Else do nothing as resource is not a constraint.
    }
    return returnList;
}

Ref<CResourceCountList> ColonyResourceServer::GetResources()
{
    Ref<CResourceCountList> returnList = Ref<CResourceCountList>(memnew(CResourceCountList()));
    
    for (auto iter = this->resourceMap.begin(); iter != this->resourceMap.end(); ++iter)
    {
        auto i1 = iter->first;
        auto i2 = iter->second;
        
        CResourceCount* t = memnew(CResourceCount(iter->first, i2));
        Ref<CResourceCount> c = Ref<CResourceCount>(t);

        returnList->add_resource( c );
    }
    return returnList;
}


ColonyResourceServer::ColonyResourceServer()
{
    ColonyResourceServer::singleton = this;
}
