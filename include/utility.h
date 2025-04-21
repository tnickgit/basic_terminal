#pragma once
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

// Converts vector of strings to vector of char* (C-style strings)
std::vector<char*> castArgs(const std::vector<std::string>& cmd);

// Converts a command string to a vector of words
std::vector<std::string> cmd2vec(const std::string& command, char delimiter = ' ');

