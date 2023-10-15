#pragma once
#include "CResource.h"
#include "core/object/object.h"

/// \brief List of resources which can be serialized or edited. 
class CResourceCountList : public Resource
{
    GDCLASS(CResourceCountList, Resource);

    Vector<Ref<CResourceCount>> resources;

protected:
    static void _bind_methods();

public:
    TypedArray<CResourceCount> get_resources() const;
    void set_resources(const TypedArray<CResourceCount> resourceList);
    void add_resource(const Ref<CResourceCount> addResource);
    
    Vector<Ref<CResourceCount>> GetResources() { return this->resources; }

    CResourceCountList()
    {
    };

    ~CResourceCountList() override
    {
    };
};
