/*
** PERSONAL PROJECT, 2020
** quoter
** File description:
** quoter display functions
*/

#include "Quoter.hpp"

static void displayQuoted(std::string& qtd, bool markdown_on)
{
    std::string loc = "";

    qtd = qtd.substr((qtd[1] == ' ' ? 2 : 1), qtd.length());
    if (qtd.find(';') != std::string::npos) {
        loc = qtd.substr(qtd.find(';') + 1, qtd.length());
        if (loc[0] == ' ')
            loc = loc.substr(1, loc.length());
    }
    if (!loc.length()) {
        if (qtd[0] == '?')
            std::cout << "- " << qtd << std::endl;
        else
            std::cout << "- \033[1;34m" << qtd << "\033[0m" << std::endl;
    } else {
        if (markdown_on)
            formatLine(loc);
        std::cout << "- \033[1;34m" << qtd.substr(0, qtd.find(';'))
                  <<   "\033[0m, \033[1;33m" << loc << "\033[0m" << std::endl;
    }
}

void Quoter::display(void)
{
    std::cout << "\n Here is quote " << this->idx << " for you today:\n"
              << std::endl;
    if (this->markdown)
        for (uint i = 0; i < this->quote.size(); i++)
            formatLine(this->quote[i]);
    this->quote[this->quote.size() - 1] += "\033[0m";
    for (uint i = 0; i < this->quote.size() - 1; i++) {
        if (i) std::cout << " ";
        std::cout << " " << this->quote[i] << std::endl;
    }
    displayQuoted(this->quote[this->quote.size() - 1], this->markdown);
    std::cout << std::endl;
}
