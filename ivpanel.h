#pragma once
#include "../util/memory.h"

class IVPanel
{
public:
	constexpr const char* GetName(std::uint32_t panel) noexcept
	{
		return memory::Call<const char*>(this, 36, panel);
	}
};
