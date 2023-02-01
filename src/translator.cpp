#include <iostream>
#include <vector>

std::vector<std::string> make_exit_commands()
{
    std::vector<std::string> cmds;
    cmds.__emplace_back("quit");
    cmds.__emplace_back("q");
    cmds.__emplace_back("exit");
    cmds.__emplace_back("e");

    return cmds;
}

int main()
{

    std::string cmd;
    auto cmds = make_exit_commands();
    std::cout << "This is a translator, but it does nothing for now..." << std::endl;
    while (true)
    {
        std::cin >> cmd;
        for (auto c : cmds)
        {
            if (cmd == c)
            {
                std::cout << "quit ..." << std::endl;
                exit(0);
            }
        }
        std::cout << cmd << std::endl;
    }

    return 0;
}