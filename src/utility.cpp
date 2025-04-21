#include "utility.h"


// Converts vector of strings to vector of char* (C-style strings)
std::vector<char*> castArgs(const std::vector<std::string>& cmd){
    std::vector<char*> charVector;

    for (const auto& str : cmd)
    {
        charVector.push_back(const_cast<char*>(str.c_str()));
    }
    charVector.push_back(nullptr);
    return charVector;
}

std::vector<std::string> cmd2vec(const std::string& command, char delimiter){
    std::vector<std::string> result;
    std::string word;
    std::stringstream cmd(command);

    while(std::getline(cmd, word, delimiter))
    {
       if (!word.empty())
       {
            result.push_back(word);
       }
    }
    
    return result;
}