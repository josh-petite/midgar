#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Midgar
{
	std::shared_ptr<spdlog::logger> Log::engineLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		clientLogger = spdlog::stdout_color_mt("CLIENT");
		clientLogger->set_level(spdlog::level::trace);

		engineLogger = spdlog::stdout_color_mt("MIDGAR");
		engineLogger->set_level(spdlog::level::trace);
	}
}