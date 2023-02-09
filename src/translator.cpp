#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <sstream>
#include <fstream>
#include <cstdlib>

void add(std::map<std::string, std::string> &dic, std::string w1, std::string w2)
{
    dic.emplace(w1, w2);
    std::cout << w1 << " => " << w2 << std::endl;
}

bool in_vector(std::vector<std::string> tab, std::string word)
{
    for (auto c : tab)
    {
        if (c == word)
        {
            return true;
        }
    }

    return false;
}

std::string translation_of(std::map<std::string, std::string> dic, std::string word)
{
    auto it = dic.find(word);
    if (it != dic.end())
    {
        return it->second;
    }
    else
    {
        return "";
    }
}

void add_to_history(std::list<std::string> &histo, std::string add_line)
{
    histo.emplace_back(add_line);
}

void print_list(std::map<std::string, std::string> dic)
{

    for (auto it = dic.begin(); it != dic.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void save(std::string file_name, std::list<std::string> history)
{
    std::ofstream file;
    file.open(file_name);
    if (!file)
    {
        std::cerr << "Error !" << std::endl;
        return;
    }
    else
    {
        for (auto i : history)
        {
            file << i << std::endl;
        }
        file.close();
    }
}

std::vector<std::string> get_lines(std::string file_name)
{
    std::ifstream file;
    file.open(file_name);
    if (!file)
    {
        std::cerr << "Error !" << std::endl;
        return {};
    }
    else
    {
        std::string line;
        std::vector<std::string> list_lines;
        while (std::getline(file, line))
        {
            list_lines.emplace_back(line);
        }
        file.close();
        return list_lines;
    }
}

std::vector<std::string> cut_string(std::string line)
{
    std::vector<std::string> tab_line;
    std::string tmp;
    std::stringstream s(line);

    while (s >> tmp)
    {
        tab_line.__emplace_back(tmp);
    }

    return tab_line;
}

bool check_command_size(int size, int wanted_size, std::string message)
{
    if (size != wanted_size)
    {
        std::cout << "usage : " << message << std::endl;
        return false;
    }
    return true;
}

void translator(std::map<std::string, std::string> &dic,
                std::vector<std::string> tab_line,
                std::list<std::string> &history)
{
    // récupération de la ligne de commandes

    // add translation between 2 words
    if (tab_line[0] == "add")
    {
        if (check_command_size(tab_line.size(), 3, "add w1 w2"))
        {
            add(dic, tab_line[1], tab_line[2]);
            auto line = tab_line[0] + " " + tab_line[1] + " " + tab_line[2];
            add_to_history(history, line);
        }
    }

    // get the translation
    if (tab_line[0] == "translate")
    {
        if (check_command_size(tab_line.size(), 2, "translate w"))
        {
            auto t_word = translation_of(dic, tab_line[1]);
            std::cout << (t_word == "" ? "???" : t_word) << std::endl;
        }
    }

    // print all the map
    if (tab_line[0] == "print")
    {
        for (auto it = dic.begin(); it != dic.end(); ++it)
        {
            std::cout << it->first << " : " << it->second << std::endl;
        }
    }

    // save the history to a file
    if (tab_line[0] == "save")
    {
        if (check_command_size(tab_line.size(), 2, "save filename"))
        {
            save(tab_line[1], history);
        }
    }

    if (tab_line[0] == "load")
    {
        if (check_command_size(tab_line.size(), 2, "load filename"))
        {
            auto lines = get_lines(tab_line[1]);
            if (lines.empty())
            {
                std::cout << "Empty file" << std::endl;
            }
            else
            {
                for (auto line : lines)
                {
                    auto tab = cut_string(line);
                    translator(dic, tab, history);
                }
            }
        }
    }

    // clear the content of the history
    if (tab_line[0] == "clear")
    {
        dic.clear();
        history.clear();
    }

    // removes all the reference to word
    if (tab_line[0] == "remove")
    {
        if (check_command_size(tab_line.size(), 2, "remove word"))
        {
            for (auto it = dic.begin(); it != dic.end();)
            {
                if (it->first == tab_line[1] || it->second == tab_line[1])
                {
                    std::cout << "removing..." + it->first << std::endl;
                    it = dic.erase(it);
                }
                else
                    ++it;
            }
        }
    }
}

int main()
{

    std::string cmd;
    // dictionaire de traduction
    std::map<std::string, std::string> dic;

    std::vector<std::string> cmdsToExit = {"quit", "q", "exit", "e"};
    std::string tmp;

    // ligne de commande
    std::vector<std::string> tab_line;

    // historique
    std::list<std::string> history;

    while (true)
    {

        std::getline(std::cin, cmd);

        tab_line = cut_string(cmd);

        // check la liste des commandes pour quitter

        if (in_vector(cmdsToExit, tab_line[0]))
        {
            std::cout << "quit ... " << std::endl;
            exit(0);
        }

        translator(dic, tab_line, history);
    }

    return 0;
}