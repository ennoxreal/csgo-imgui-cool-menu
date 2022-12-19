#pragma once
#include <cstdint>

class IGlobalVars
{
public:
	float realTime;
	std::int32_t frameCount;
	float absFrameTime;
	float absFrameStartTime;
	float currentTime;
	float frameTime;
	std::int32_t maxClients;
	std::int32_t tickCount;
	float intervalPerTick;
	float interpolationAmount;
	std::int32_t frameSimulationTicks;
	std::int32_t networkProtocol;
	void* saveData;
	bool client;
	bool remoteClient;
	std::int32_t timestampNetworkingBase;
	std::int32_t timestampRandomizeWindow;
};
