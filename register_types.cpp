/**************************************************************************/
/*  register_types.cpp                                                    */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include "register_types.h"

#include "CJobRole.h"
#include "CResource.h"
#include "CResourceTag.h"
#include "CVisualDescription.h"
#include "ResourceServer.h"
#include "colony_colonists/ColonistServer.h"
#include "core/object/class_db.h"

//#include "colony_resourcesClass.h"

void initialize_colony_resources_module(ModuleInitializationLevel p_level)
{
    if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        GDREGISTER_CLASS(CVisualDescription);
        GDREGISTER_CLASS(CDescription);
        GDREGISTER_CLASS(CResource);
        GDREGISTER_CLASS(CResourceTag);
        GDREGISTER_CLASS(CResourceCount);
        GDREGISTER_CLASS(CResourceCountList);
        GDREGISTER_CLASS(ColonyResourceServer);
        GDREGISTER_CLASS(CJobRole);
        GDREGISTER_CLASS(CJobRoleCount);
        GDREGISTER_CLASS(ColonistServer);
    }

    if (p_level == MODULE_INITIALIZATION_LEVEL_SERVERS)
    {
        resourceServer = memnew(ColonyResourceServer);
        Engine::get_singleton()->add_singleton(Engine::Singleton("GetColonyResourceServer", ColonyResourceServer::get_singleton()));
    }

}

void uninitialize_colony_resources_module(ModuleInitializationLevel p_level)
{
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        return;
    }
    // Nothing to do here in this example.
}
