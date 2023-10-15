#pragma once
#include "core/io/resource.h"
#include "core/variant/typed_array.h"


/// \brief Godot Resource for basic jobs for the purpose of allocation.
class CJobRole : public Resource
{
    GDCLASS(CJobRole, Resource);

protected:
    static void _bind_methods();

public:
   
    CJobRole()
    {
    };

    ~CJobRole() override
    {
    };
};


/// \brief Reference to CJobRole  with an additional count. Intended for buildings describing how many work there.
struct CJobRoleCount : public Resource
{
    GDCLASS(CJobRoleCount, Resource);

    Ref<CJobRole> job;
    int count = 0;

protected:
    static void _bind_methods();

public:
    int get_count() { return count; }
    void set_count(const int c) { count = c; }

    Ref<CJobRole> get_job() { return job; }
    
    void set_resource(const Ref<CJobRole> r) { job = r; }


    CJobRoleCount()
    {
    };

    CJobRoleCount(Ref<CJobRole> r, int c)
    {
        this->job = r;
        this->count    = c;
    };

    ~CJobRoleCount() override
    {
    };
};
