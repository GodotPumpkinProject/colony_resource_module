#pragma once
#include "CResourceTag.h"
#include "CVisualDescription.h"
#include "common/debug.h"
#include "core/io/resource.h"
#include "core/variant/typed_array.h"


/// \brief Godot Resource describing a common 'resource' such as 'wood' or 'stone'.
class CResource : public CVisualDescription
{
    GDCLASS(CResource, CVisualDescription);

    /// \brief List of tags associated with this resource.
    TypedArray<CResourceTag> tags;

    Ref<CResource> parentResource;
    
protected:
    static void _bind_methods();

public:
    TypedArray<CResourceTag> get_tags() const;
    void set_tags(const TypedArray<CResourceTag>& tags_);

    Ref<CResource> GetParentResource(){return this->parentResource;}
    void SetParentResource(const Ref<CResource> newParentResource){ this->parentResource = newParentResource;}
    CResource()
    {
    };

    ~CResource() override
    {
    };
};


/// \brief Reference to a CResource and a numerical count quantity.  Can be used to describe '7' 'wood'. 
struct CResourceCount : public Resource
{
    GDCLASS(CResourceCount, Resource);

    Ref<CResource> resource;
    int count = 0;

protected:
    static void _bind_methods();

public:
    int get_count() { return count; }
    void set_count(const int c) { count = c; }

    Ref<CResource> get_resource() { return resource; }
    
    void set_resource(const Ref<CResource> r) { resource = r; }

    void add_count(int addCount){this->count += addCount;}

    void add_count(CResourceCount r){ this->count += r.get_count();}
    
//     Common assignments
    CResourceCount operator +=(const CResourceCount& b) const
    {
        assert(this->resource == b.resource);
        return CResourceCount(this->resource, this->count + b.count);
    }
    
    CResourceCount operator -=(const CResourceCount& b) const
    {
        assert(this->resource == b.resource);
        return CResourceCount(this->resource, this->count + b.count);
    }


    CResourceCount()
    {
    };

    CResourceCount(Ref<CResource> r, int c)
    {
        this->resource = r;
        this->count    = c;
    };

    ~CResourceCount() override
    {
    };
};
