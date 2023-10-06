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
    std::map<Ref<CResource>, int> resourceMap;

protected:
    static void _bind_methods();

public:
    inline static ColonyResourceServer* singleton;
    static ColonyResourceServer* get_singleton() { return singleton; };

    void AddResource(const Ref<CResource> resource, int count);
    void RemoveResource(const Ref<CResource> resource, int count);
    int GetResourceCount(const Ref<CResource>);

    void PrintObject();

    void AddResourceList(const Ref<CResourceCountList>& resourceList);
    void RemoveResourceList(const Ref<CResourceCountList>& resourceList);
    void HasResourceList(const Ref<CResourceCountList>& resourceList);

    ColonyResourceServer();

    ~ColonyResourceServer() override
    {
    };
};


#endif // GODOT_RESOURCESERVER_H
