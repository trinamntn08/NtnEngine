#pragma once
#include"Core.h"

namespace NTN
{
    class NTN_API Log
    {
    public:
        enum class Level {
            INFO,
            WARNING,
            ERROR_OCCURRED
        };

        static void Init() {
            s_coreLogger = "NTN Engine";
            s_clientLogger = "SandBox";
        }

        static void PrintTime() {
            std::time_t now = std::time(nullptr);
            std::tm localTime;
            localtime_s(&localTime, &now);
            std::cout << "[" << std::put_time(&localTime, "%T") << "] ";
        }

        static void Info(const std::string& logger, const std::string& message) {
            SetColor(37); // Green color for INFO
            PrintTime();
            std::cout << logger << ": " << message << std::endl;
            ResetColor();
        }

        static void Warning(const std::string& logger, const std::string& message) {
            SetColor(33); // Yellow color for WARNING
            PrintTime();
            std::cout << logger << ": " << message << std::endl;
            ResetColor();
        }

        static void Error(const std::string& logger, const std::string& message) {
            SetColor(31); // Red color for ERROR
            PrintTime();
            std::cout << logger << ": " << message << std::endl;
            ResetColor();
        }

        static std::string getCoreLogger() { return s_coreLogger; }
        static std::string getClientLogger() { return s_clientLogger; }

    private:
        static void SetColor(int colorCode) {
            std::cout << "\033[" << colorCode << "m";
        }

        static void ResetColor() {
            std::cout << "\033[0m";
        }

        static std::string s_coreLogger;
        static std::string s_clientLogger;
    };


#define NTN_CORE_INFO(...) ::NTN::Log::Info(::NTN::Log::getCoreLogger(), __VA_ARGS__)
#define NTN_CORE_WARNING(...) ::NTN::Log::Warning(::NTN::Log::getCoreLogger(), __VA_ARGS__)
#define NTN_CORE_ERROR(...) ::NTN::Log::Error(::NTN::Log::getCoreLogger(), __VA_ARGS__)

#define NTN_CLIENT_INFO(...) ::NTN::Log::Info(::NTN::Log::getClientLogger(), __VA_ARGS__)
#define NTN_CLIENT_WARNING(...) ::NTN::Log::Warning(::NTN::Log::getClientLogger(), __VA_ARGS__)
#define NTN_CLIENT_ERROR(...) ::NTN::Log::Error(::NTN::Log::getClientLogger(), __VA_ARGS__)


}
