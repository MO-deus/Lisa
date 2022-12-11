
#pragma once

#include <memory>
#include "Grim_core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Grim {


class GRIM_API Log
{
private:
	static std::shared_ptr<spdlog::logger> sp_CoreLogger;
	static std::shared_ptr<spdlog::logger> sp_ClientLogger;

public:
	static void Init();

	// returns the core(engines) logger object , sp: shared_pointer.
	inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return sp_CoreLogger; }

	// returns the client using the engine logger object , sp: shared_pointer.
	inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return sp_ClientLogger; }
};

// Core logger macros for different types of messages
#define GRIM_CORE_TRACE(...)	::Grim::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GRIM_CORE_INFO(...)		::Grim::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GRIM_CORE_WARN(...)		::Grim::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GRIM_CORE_ERROR(...)	::Grim::Log::GetCoreLogger()->error(__VA_ARGS__)

// Client logger macros for different types of messages
#define GRIM_CLIENT_TRACE(...)		::Grim::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GRIM_CLIENT_INFO(...)		::Grim::Log::GetClientLogger()->info(__VA_ARGS__)
#define GRIM_CLIENT_WARN(...)		::Grim::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GRIM_CLIENT_ERROR(...)		::Grim::Log::GetClientLogger()->error(__VA_ARGS__)

}
