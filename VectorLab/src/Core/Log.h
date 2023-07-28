#pragma once

#include "Base.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace VL
{
    class Log 
    {
    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger>& GetLogger() { return m_logger; }
    private:
        static std::shared_ptr<spdlog::logger> m_logger;
    };
}

#define VL_TRACE(...)::VL::Log::GetLogger()->trace(__VA_ARGS__)
#define VL_INFO(...)::VL::Log::GetLogger()->info(__VA_ARGS__)
#define VL_WARN(...)::VL::Log::GetLogger()->warn(__VA_ARGS__)
#define VL_ERROR(...)::VL::Log::GetLogger()->error(__VA_ARGS__)
#define VL_FATAL(...)::VL::Log::GetLogger()->fatal(__VA_ARGS__)