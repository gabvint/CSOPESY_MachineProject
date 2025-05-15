#pragma once
#include <string>
#include <unordered_map>
#include <functional>

using CommandFunction = std::function<void()>;

// Returns a map of command strings to command functions
std::unordered_map<std::string, CommandFunction> getCommandMap();

// Command handler function declarations
void handleExit();
void handleClear();
void handleInitialize();
void handleScreen();
void handleSchedulerTest();
void handleSchedulerStop();
void handleReportUtil();