////////////////////////////////////////////////////////////////////////////
//	Module 		: script_sound_type.h
//	Created 	: 28.06.2004
//  Modified 	: 28.06.2004
//	Author		: Dmitriy Iassenev
//	Description : Script sound type
////////////////////////////////////////////////////////////////////////////

#pragma once
#include "../xrScripts/script_export_space.h"

enum ESoundTypes;

typedef enum_exporter_lib<ESoundTypes> SCRIPTS_API CScriptSoundType;
add_to_type_list(CScriptSoundType)
#undef script_type_list
#define script_type_list save_type_list(CScriptSoundType)