#include "mypipe.h"

mypipe::mypipe(){
    auto status{pipe(fd.data())};

    if (status < 0){
        exit(1);
    }
}

mypipe::~mypipe(){
    close(fd[0]);
    close(fd[1]);
}

void mypipe::redirect(){
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
}  

std::string mypipe::read(){
    std::array<char, 512> buffer;
    std::size_t bytes;
    bytes = ::read(fd[0], buffer.data(), buffer.size());

    if (bytes > 0){
        return std::string(buffer.data(), bytes);
    }
    return {};
}

