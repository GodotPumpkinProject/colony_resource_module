#include "ResourceServer.h"


void ColonyResourceServer::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("AddResource", "resource", "count"), &ColonyResourceServer::AddResource);
    ClassDB::bind_method(D_METHOD("RemoveResource", "resource", "count"), &ColonyResourceServer::RemoveResource);
    ClassDB::bind_method(D_METHOD("GetResourceCount", "resource"), &ColonyResourceServer::GetResourceCount);
    ClassDB::bind_method(D_METHOD("AddResourceList", "resourceList"), &ColonyResourceServer::AddResourceList);
    ClassDB::bind_method(D_METHOD("RemoveResourceList", "resourceList"), &ColonyResourceServer::RemoveResourceList);
    ClassDB::bind_method(D_METHOD("HasResourceList", "resourceList"), &ColonyResourceServer::HasResourceList);
    ClassDB::bind_method(D_METHOD("PrintObject"), &ColonyResourceServer::PrintObject);
}

void ColonyResourceServer::AddResource(const Ref<CResource> resource, int count)
{
    if (this->resourceMap.find(resource) == this->resourceMap.end())
    {
        this->resourceMap.emplace(resource, count);
    }
    else
    {
        this->resourceMap[resource] += count;
    }
}

void ColonyResourceServer::RemoveResource(const Ref<CResource> resource, int count)
{
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
}

int ColonyResourceServer::GetResourceCount(const Ref<CResource> resource)
{
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

void ColonyResourceServer::AddResourceList(const Ref<CResourceCountList>& resourceList)
{
    for (auto r : resourceList->GetResources())
    {
        this->AddResource(r->get_resource(), r->get_count());
    }
}

void ColonyResourceServer::RemoveResourceList(const Ref<CResourceCountList>& resourceList)
{
    for (auto r : resourceList->GetResources())
    {
        this->RemoveResource(r->get_resource(), r->get_count());
    }
}

void ColonyResourceServer::HasResourceList(const Ref<CResourceCountList>& resourceList)
{
    throw std::logic_error("Not implemented");
}


ColonyResourceServer::ColonyResourceServer()
{
    ColonyResourceServer::singleton = this;
}
