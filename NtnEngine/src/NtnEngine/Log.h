#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>

namespace NTN
{
    class Log 
    {
    public:
        enum class Level 
        {
            INFO,
            WARNING,
            ERROR
        };

        static void Init()
        {
            s_coreLogger = "NTN Engine";
            s_clientLogger = "SandBox";
        }

        static void PrintTime() {
            std::time_t now = std::time(nullptr);
            std::tm localTime;
            localtime_s(&localTime, &now);
            std::cout << "[" << std::put_time(&localTime, "%T") << "] ";
        }

        static void Info(const std::string& message) {
            SetColor(32); // Green color for INFO
            PrintTime();
            std::cout << s_coreLogger << ": " << message << std::endl;
            ResetColor();
        }

        static void Warning(const std::string& message) {
            SetColor(33); // Yellow color for WARNING
            PrintTime();
            std::cout << s_coreLogger << ": " << message << std::endl;
            ResetColor();
        }

        static void Error(const std::string& message) {
            SetColor(31); // Red color for ERROR
            PrintTime();
            std::cout << s_coreLogger << ": " << message << std::endl;
            ResetColor();
        }

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

    std::string Log::s_coreLogger;
    std::string Log::s_clientLogger;
}
