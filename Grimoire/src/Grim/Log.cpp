
#include "Log.h"

namespace Grim {

	std::shared_ptr<spdlog::logger> Log::sp_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::sp_ClientLogger;

	void Log::Init()
	{
		// pattern format for message : %T - thread id, %n-logger name, %v-user text, %$-some messaage.
		spdlog::set_pattern("%^[%T]-%D %n: %v%$");
		sp_CoreLogger = spdlog::stderr_color_mt("GRIMOIRE");
		sp_CoreLogger->set_level(spdlog::level::trace);

		sp_ClientLogger = spdlog::stderr_color_mt("LISA");
		sp_ClientLogger->set_level(spdlog::level::trace);

	}
}