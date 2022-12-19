#include "misc.h"

// access global variables
#include "../core/globals.h"

// access interfaces
#include "../core/interfaces.h"

void hacks::RunBunnyHop(CUserCmd* cmd) noexcept
{
	if (!(globals::localPlayer->GetFlags() & CEntity::FL_ONGROUND))
		cmd->buttons &= ~CUserCmd::IN_JUMP;
}
