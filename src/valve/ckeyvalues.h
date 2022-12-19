#pragma once
#include "../util/memory.h"

class CKeyValues {
public:
	// https://gitlab.com/KittenPopo/csgo-2018-source/-/blob/main/tier1/keyvalues.cpp#L3652
	static CKeyValues* FromString(const char* name, const char* value) noexcept
	{
		static std::uintptr_t functionAddress =
			memory::RelativeToAbsolute(reinterpret_cast<std::uintptr_t>(memory::keyValuesFromString));

		CKeyValues* kv;

		__asm
		{
			push 0
			mov edx, value			// second param goes in edx
			mov ecx, name			// first param in ecx
			call functionAddress	// call the func with ecx, edx
			add esp, 4
			mov kv, eax				// value is stored in eax, move it into kv
		}

		return kv;
	}
};
