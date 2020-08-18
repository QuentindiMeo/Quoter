/*
** PERSONAL PROJECT, 2020
** quoter
** File description:
** quoter list authors
*/

#include <algorithm>
#include <list>
#include "Errors.hpp"
#include "Quoter.hpp"

static bool isInList(const std::list<std::string>& list, const std::string& a)
{
    std::string s = a.substr((a[1] == ' ' ? 2 : 1),
                             a.find(';') - (a[1] == ' ' ? 2 : 1));

    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    for (std::string sa : list) {
        std::string aa = sa.substr((sa[1] == ' ' ? 2 : 1),
                                   sa.find(';') - (sa[1] == ' ' ? 2 : 1));
        std::transform(aa.begin(), aa.end(), aa.begin(), ::tolower);
        if (s == aa)
            return (true);
    }
    return (false);
}

return_values_t Quoter::listAuthors(void)
{
    std::ifstream f(this->qfile);
    std::string s;
    std::list<std::string> authors = {};

    if (!f.is_open())
        throw (QError(ERR_INV_OPN));
    while (std::getline(f, s)) {
        trim(s);
        if (s.length() > 1 && s[0] == '-')
            if (!isInList(authors, s))
                authors.push_back(s.substr(0, s.find(";")));
    }
    authors.sort();
    std::cout << "\n Here is a list of the authors that can be found in \033[3m"
              << this->qfile << "\033[0m:\n" << std::endl;
    for (std::string a : authors) {
        std::cout << " " << a[0] << (a[1] == ' ' ? "" : " ") << "\033[1;34m";
        std::cout << a.substr(1, a.length()) <<   "\033[0m"  << std::endl;
    }
    std::cout << std::endl;
    return (SUCCESS);
}
