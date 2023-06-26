#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Voyager {

	class VOYAGER_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define VGR_CORE_TRACE(...)      ::Voyager::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VGR_CORE_INFO(...)       ::Voyager::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VGR_CORE_WARN(...)       ::Voyager::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VGR_CORE_ERROR(...)      ::Voyager::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VGR_CORE_CRITICAL(...)   ::Voyager::Log::GetCoreLogger()->critical(__VA_ARGS__)
							     
// Client log macros		     
#define VGR_TRACE(...)           ::Voyager::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VGR_INFO(...)            ::Voyager::Log::GetClientLogger()->info(__VA_ARGS__)
#define VGR_WARN(...)            ::Voyager::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VGR_ERROR(...)           ::Voyager::Log::GetClientLogger()->error(__VA_ARGS__)
#define VGR_CRITICAL(...)        ::Voyager::Log::GetClientLogger()->critical(__VA_ARGS__)