#pragma once
#include <unistd.h>
#include <sys/wait.h>
#include <string>
#include <iostream>
#include <array>

//mypipe.h

// Class mypipe provides a simple wrapper around a Unix pipe,
// allowing redirection of standard output and capturing of output via read()

class mypipe{
    private:
        // File descriptors for the pipe
        // fd[0] is the read end of the pipe, fd[1] is the write end
        std::array<int, 2> fd;

    public:
        // Constructor: Creates a unidirectional pipe using pipe().
        mypipe();
        
        // Destructor: Closes both ends of the pipe to release resources
        ~mypipe();

        // redirect(): Redirects standard output (STDOUT) to the pipe's write end.
        // This allows capturing output that would normally go to the console.
        void redirect();

        // read(): Reads data from the pipe's read end and returns it as a std::string.
        // Typically used to capture the output that was redirected into the pipe.
        std::string read();
};

