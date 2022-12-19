#pragma once
#include <cstdint>

template <typename T>
class CUtlVector {
public:
	// non const indexing
	constexpr T& operator[](size_t index) noexcept
	{
		return memory[index];
	}

	// const indexing
	constexpr const T& operator[](size_t index) const noexcept
	{
		return memory[index];
	}

	T* memory;
	std::int32_t allocCount;
	std::int32_t growSize;
	std::int32_t size;
	T* elments;
};
