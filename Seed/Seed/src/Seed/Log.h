#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Seed {

	class SEED_API Log {
	public: 
		static void init(); 

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger;  };
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger;  };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger; 
		static std::shared_ptr<spdlog::logger> s_ClientLogger; 
	};

}

#define SD_CORE_TRACE(...) ::Seed::Log::getCoreLogger()->trace(__VA_ARGS__)
#define SD_CORE_INFO(...) ::Seed::Log::getCoreLogger()->info(__VA_ARGS__)
#define SD_CORE_WARN(...) ::Seed::Log::getCoreLogger()->warn(__VA_ARGS__)
#define SD_CORE_ERROR(...) ::Seed::Log::getCoreLogger()->error(__VA_ARGS__)
#define SD_CORE_CRITAL(...) ::Seed::Log::getCoreLogger()->critical(__VA_ARGS__)

#define SD_TRACE(...) ::Seed::Log::getClientLogger()->trace(__VA_ARGS__)
#define SD_INFO(...) ::Seed::Log::getClientLogger()->info(__VA_ARGS__)
#define SD_WARN(...) ::Seed::Log::getClientLogger()->warn(__VA_ARGS__)
#define SD_ERROR(...) ::Seed::Log::getClientLogger()->error(__VA_ARGS__)
#define SD_CRITAL(...) ::Seed::Log::getClientLogger()->critical(__VA_ARGS__)
