#ifndef GODOT_RESOURCESERVER_H
#define GODOT_RESOURCESERVER_H
#include <map>

#include "CResource.h"
#include "CResourceList.h"
#include "core/object/class_db.h"
#include "core/object/object.h"


/// \brief Server handling player resource count in a singleton.
/// 
class ColonyResourceServer : public Object
{
    GDCLASS(ColonyResourceServer, Object);

private:
    std::map<Ref<CResource>, float> resourceMap;

protected:
    static void _bind_methods();

public:
    inline static ColonyResourceServer* singleton;
    static ColonyResourceServer* get_singleton() { return singleton; };

    /// \brief Adds resource to server.  Adds key if does not exist.
    void AddResource(const Ref<CResource> resource, float count);

    /// \brief Removes resource if it exists.  If resource exists and count would decrement it below 0 prints an error.
    void RemoveResource(const Ref<CResource> resource, float count);

    /// \brief Returns count of resources.  If key does not exist returns 0.
    float GetResourceCount(const Ref<CResource>);

    /// \brief Debug printing of each key and quantity.
    void PrintObject();

    /// \brief Adds each resource in list.
    void AddResourceList(const Ref<CResourceCountList> resourceList);

    /// \brief Subtracts each resource in list.  See RemoveResource.
    void RemoveResourceList(const Ref<CResourceCountList> resourceList);

    /// \brief Returns true if all resources in 'resourceList' exists and 
    bool HasResourceQuantity(const Ref<CResourceCountList> resourceList);

    /// \brief Returns a list of resources which failed to have suffeciant quantities on this server.  
    Ref<CResourceCountList> LackingResourceQuantity(const Ref<CResourceCountList> resourceList);

    /// \brief Returns a list of resources as CountList type.
    Ref<CResourceCountList> GetResources();

    ColonyResourceServer();

    ~ColonyResourceServer() override
    {
    };
};


#endif // GODOT_RESOURCESERVER_H
