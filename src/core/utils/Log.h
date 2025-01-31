#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>

enum class LogLevel {
  INFO,
  INITIALIZE,
  LOG_WARNING,
  LOG_ERROR
};

inline void log(LogLevel level, std::string msg) {
  std::string output = "";

  switch (level) {
    case LogLevel::INFO:
      output = "[INFO]: "; break;
    case LogLevel::INITIALIZE:
      output = "[INIT]: "; break;
    case LogLevel::LOG_WARNING:
      output = "[WARNING]: "; break;
    case LogLevel::LOG_ERROR:
      output = "[ERROR]: "; break;
  }

  output += msg;

  std::cout << output << std::endl;
}

inline void log_with_stack(LogLevel level, std::string msg, std::string file, long line) {
  log(level, msg);
  std::cout << "[STACK] File: " << file <<  std::endl;
  std::cout << "[STACK] Line: " << line << std::endl;
}

#ifdef DEBUG

#define LOG(msg) log(LogLevel::INFO, msg)
#define LOG_INIT(msg) log(LogLevel::INITIALIZE, msg)
#define WARNING(msg) log(LogLevel::LOG_WARNING, msg)
#define ERROR(msg) log(LogLevel::LOG_ERROR, msg); __debugbreak

#define STACK_LOG(msg) log_with_stack(LogLevel::LOG_INFO, msg, __FILE__, __LINE__)
#define STACK_LOG_INIT(msg) log_with_stack(LogLevel::LINITIALIZE, msg, __FILE__, __LINE__)
#define STACK_WARNING(msg) log_with_stack(LogLevel::LOG_WARNING, msg, __FILE__, __LINE__)
#define STACK_ERROR(msg) log_with_stack(LogLevel::LOG_ERROR, msg, __FILE__, __LINE__)

#else

#define LOG(msg)
#define LOG_INIT(msg)
#define WARNING(msg)
#define ERROR(msg)

#define STACK_LOG(msg)
#define STACK_LOG_INIT(msg)
#define STACK_WARNING(msg)
#define STACK_ERROR(msg)

#endif


#endif //LOG_H
