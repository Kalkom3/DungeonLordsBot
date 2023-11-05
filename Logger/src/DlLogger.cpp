#include "DlLogger.h"

#include <ios>

bool LoggingConfig::s_printToConsole = false;
logLevel LoggingConfig::s_logLevel = DEBUG;
std::filesystem::path LoggingConfig::s_logFilePath = "";

DlLogger::DlLogger()
{

}

DlLogger::DlLogger(logLevel type, std::filesystem::path logPath)
{
    msglevel = type;
    if (LoggingConfig::s_printToConsole)
    {
        operator << ("[" + GetLabel(type) + "]>");
    }

    logFile.open(GetLogFilePath(logPath), std::ios::out | std::ios::app | std::ios::ate);

    if (logFile.is_open())
    {
        if (msglevel >= LoggingConfig::s_logLevel)
        {
            logFile.seekp(std::ios::end);
            logFile << ("[" + GetLabel(type) + "]>");
        }
    }
    else
    {
        operator << ("LOG FILE FATAL ERROR");
    }
}

DlLogger::~DlLogger()
{
    if (opened) {
        if (LoggingConfig::s_printToConsole)
        {
            std::cerr << "\n";
        }
        logFile << "\n";
        logFile.close();
    }
    opened = false;
}

std::filesystem::path DlLogger::GetLogFilePath(std::filesystem::path logsDirPath)
{
    if (!LoggingConfig::s_logFilePath.empty())
    {
        return LoggingConfig::s_logFilePath;
    }

    std::filesystem::path sourcePath = std::filesystem::current_path();
    std::filesystem::path absolutePath = sourcePath.parent_path() / logsDirPath;
    if (!std::filesystem::exists(absolutePath))
    {
        std::filesystem::create_directory(absolutePath);
    }

    auto dirIter = std::filesystem::directory_iterator(absolutePath);

    int fileCount = std::count_if(
        begin(dirIter),
        end(dirIter),
        [](auto& entry) { return entry.is_regular_file(); }
    );

    LoggingConfig::s_logFilePath = absolutePath / ("Logs_" + std::to_string(fileCount + 1) + ".txt");
    return absolutePath / ("Logs_" + std::to_string(fileCount + 1) + ".txt");
}

std::string DlLogger::GetLabel(logLevel type)
{
    std::string label;
    switch (type) {
    case DEBUG: label = "DEBUG"; break;
    case INFO:  label = "INFO "; break;
    case WARN:  label = "WARN "; break;
    case ERROR: label = "ERROR"; break;
    }
    return label;
}