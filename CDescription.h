#pragma once

#include "core/io/resource.h"

class CDescription : public Resource
{
public:
    String get_resource_name() const;
    void set_resource_name(const String& name_);
    String get_short_description() const;
    void set_short_description(const String& short_description_);
    String get_full_description() const;
    void set_full_description(const String& full_description_);

private:
    GDCLASS(CDescription, Resource);

    String resource_name;
    String short_description;
    String full_description;
    
protected:
    static void _bind_methods();

public:
    CDescription() {};
    ~CDescription() {};
};
