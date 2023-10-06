#pragma once
#include "CDescription.h"
#include "core/io/image.h"
#include "core/io/resource.h"
#include "scene/resources/texture.h"

/// \brief Adds UI graphics.
class CVisualDescription : public CDescription
{
    GDCLASS(CVisualDescription, CDescription);
    Ref<Texture2D> icon;

public:
    Ref<Texture2D> get_icon() const;
    void set_icon(const Ref<Texture2D> icon_);

protected:
    static void _bind_methods();

public:
    CVisualDescription()
    {
    };

    ~CVisualDescription() override
    {
    };
};
