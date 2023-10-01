#pragma once
#include "CVisualDescription.h"
#include "core/io/resource.h"


class CResourceTag : public CVisualDescription
{
    GDCLASS(CResourceTag, CVisualDescription);

protected:
    static void _bind_methods();

public:
    CResourceTag() {};
    ~CResourceTag() {};
    
};

inline void CResourceTag::_bind_methods()
{
}
