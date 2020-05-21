#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Midgar 
{
	class MIDGAR_API Log
	{
	public:
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return engineLogger; }
		static void Init();
	private:
		static std::shared_ptr<spdlog::logger> clientLogger;
		static std::shared_ptr<spdlog::logger> engineLogger;
	};
}

#define MG_CORE_TRACE(...) ::Midgar::Log::GetEngineLogger()-trace(__VA_ARGS__)
#define MG_CORE_INFO(...)  ::Midgar::Log::GetEngineLogger()->info(__VA_ARGS__)
#define MG_CORE_WARN(...)  ::Midgar::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define MG_CORE_ERROR(...) ::Midgar::Log::GetEngineLogger()->error(__VA_ARGS__)
#define MG_CORE_FATAL(...) ::Midgar::Log::GetEngineLogger()->fatal(__VA_ARGS__)

#define MG_TRACE(...) ::Midgar::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MG_INFO(...)  ::Midgar::Log::GetClientLogger()->info(__VA_ARGS__)
#define MG_WARN(...)  ::Midgar::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MG_ERROR(...) ::Midgar::Log::GetClientLogger()->error(__VA_ARGS__)
#define MG_FATAL(...) ::Midgar::Log::GetClientLogger()->fatal(__VA_ARGS__)