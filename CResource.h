#pragma once
#include "CResourceTag.h"
#include "CVisualDescription.h"
#include "core/io/resource.h"
#include "core/variant/typed_array.h"


class CResource : public CVisualDescription
{
    GDCLASS(CResource, CVisualDescription);

    TypedArray<CResourceTag> tags;

protected:
    static void _bind_methods();
    
public:
    TypedArray<CResourceTag> get_tags() const;
    void set_tags(const TypedArray<CResourceTag>& tags_);

    CResource() {};
    ~CResource() {};
    
};
