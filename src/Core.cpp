/*
** PERSONAL PROJECT, 2020
** quoter
** File description:
** quoter core functions
*/

#include <sys/stat.h>
#include "Errors.hpp"
#include "Quoter.hpp"

void Quoter::gotThatToday(void)
{
    std::string rm = "rm -f ";

    rm += this->sfile;
    system(rm.c_str());

    std::ofstream sav(this->sfile);

    if (!sav.is_open())
        throw (QError(ERR_INV_SAV));
    sav << std::to_string(this->idx) << "\n";
}

bool Quoter::saidYesterday(void)
{
    std::ifstream sav(this->sfile);
    std::string s;
    struct stat sb;
 
    if (stat(this->sfile.c_str(), &sb) != ERROR && S_ISDIR(sb.st_mode))
        throw (QError(ERR_INV_SAV));
    if (!sav.is_open() || this->size == 1)
        return (false);
    std::getline(sav, s);
    return (this->idx == std::stoi(s) ? true : false);
}

void Quoter::getNextQuote(std::ifstream& file)
{
    std::string s;

    this->quote = {};
    while (std::getline(file, s)) {
        trim(s);
        if (!s.length())
            continue;
        if (s == "\"\"" || s == " " || s == "-" || s == "\" \"")
            continue;
        quote.push_back(s);
        if (s[0] == '-')
            break;
    }
    this->allquotes.push_back(this->quote);
}

return_values_t Quoter::process(void)
{
    std::ifstream file(this->qfile);

    this->idx = rand() % this->size + 1;
    for (uint i = 0; i < (this->seeking ? this->size : this->idx); i++)
        this->getNextQuote(file);
    if (this->seeking) {
        this->setupSeeked();
        this->pickSeeked();
    }
    file.close();
    if (this->saidYesterday())
        return (FAILURE);
    this->display();
    this->gotThatToday();
    return (SUCCESS);
}
