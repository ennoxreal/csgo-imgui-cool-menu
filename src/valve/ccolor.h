#pragma once
#include <cstdint>

class CColor 
{
public:
	constexpr CColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 255) :
		r(r), g(g), b(b), a(a) { }

	static CColor Red(std::uint8_t a = 255) { return { 255, 0, 0, a }; }
	static CColor Green(std::uint8_t a = 255) { return { 0, 255, 0, a }; }
	static CColor Blue(std::uint8_t a = 255) { return { 0, 0, 255, a }; }
	static CColor Black(std::uint8_t a = 255) { return { 0, 0, 0, a }; }
	static CColor White(std::uint8_t a = 255) { return { 255, 255, 255, a }; }

	std::uint8_t r{ }, g{ }, b{ }, a{ };
};
