#include "../PCH.h"
#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace VL 
{
    std::shared_ptr<spdlog::logger> Log::m_logger;

    void Log::init() 
    {
        // Log Pattern: TIMESTAMP LOGGER_NAME: LOG_MSG
		// See https://github.com/gabime/spdlog/wiki/3.-Custom-formatting
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// Define colors/level for core logger
		m_logger = spdlog::stdout_color_mt("VL");
		m_logger->set_level(spdlog::level::trace);
    }
}