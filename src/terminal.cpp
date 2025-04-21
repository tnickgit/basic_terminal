#include "terminal.h"


int run_cmd(std::vector<char*> argv)
{
    mypipe pipe;

    auto pid = fork();

    if (pid == -1){
        perror("fork failed");
        return -1;
    }

    if (pid == 0) {
        std::cout << "\n[child] PID = " << getpid();
        std::cout <<" -execvp\n" << std::flush;
        execvp(argv[0], argv.data());
        perror("exec failed");
        exit(127);
    }

    int status{0};
    if (waitpid(pid, &status, 0) == -1)
    {
        perror("waitpid failed");
        return -1;
    }
    return status;

}

void terminal_app()
{
    std::string input;
    mypipe pipe;
    while (true)
    {
        std::cout << "command: ";
        std::getline(std::cin, input);

        if (input == "exit")
        {
            std::cout << "Terminating execution" << std::endl;
            break;
        }
        if (input.empty())
        {
            continue;
        }
        
        auto cmd = cmd2vec(input);
        auto argv = castArgs(cmd);
        

        run_cmd(argv);
    }

}
