# godot_template_module
Resource management for the colony side of the game. 

## CResource
Base resource type, intended for all resource needs in the game. 

## CResourceTag
Tags in resource form - they can be easily assigned to CResource's list function.  

## CResourceCount
Type containing a ref of CResource and an integer quantity count.

## CResourceCountList
Type containing a vector of CResourceCount.  

## ColonyResourceServer
Singleton containing a separate implementation of CResourceCountList. 
Additional runtime protection to avoid negative values.
