#pragma once

class CEntity;
namespace globals
{
	inline CEntity* localPlayer = nullptr;

	// update the local player pointer
	void UpdateLocalPlayer() noexcept;
}
