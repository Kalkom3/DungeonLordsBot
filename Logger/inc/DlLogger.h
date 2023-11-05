#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>

#define LOG(level) DlLogger(level,"Logs")

enum logLevel {
    DEBUG,
    INFO,
    WARN,
    ERROR
};

struct LoggingConfig
{
    static bool s_printToConsole;
    static logLevel s_logLevel;
    static std::filesystem::path s_logFilePath;
};


class DlLogger {
public:
    DlLogger();
    DlLogger(logLevel type, std::filesystem::path logPath); 
    ~DlLogger();


    template<class T>
    DlLogger& operator<<(const T& msg) 
    {
        if (msglevel >= LoggingConfig::s_logLevel) 
        {
            if (LoggingConfig::s_printToConsole)
            {
                std::cerr << msg;
            }
            logFile << msg;
            opened = true;
        }
        return *this;
    }
private:
    std::filesystem::path GetLogFilePath(std::filesystem::path logsDirPath);
    std::string GetLabel(logLevel type);
    std::ofstream logFile;
    bool opened = false;
    logLevel msglevel = DEBUG;
};
