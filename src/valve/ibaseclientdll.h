#pragma once
#include "../util/memory.h"

#include "cclientclass.h"

class IBaseClientDLL
{
public:
	constexpr CClientClass* GetAllClasses() noexcept
	{
		return memory::Call<CClientClass*>(this, 8);
	}
};
