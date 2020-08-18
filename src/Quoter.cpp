/*
** PERSONAL PROJECT, 2020
** quoter
** File description:
** main quoter
*/

#include <cstring>
#include "Errors.hpp"
#include "Quoter.hpp"

Quoter::Quoter(int ac, char **av) : qfile(QFILE), sfile(SFILE), markdown(true), seeking(false), listA(false), pattern(""), autwork(""), quotes{}
{
    this->catchParameters(ac, av);

    std::ifstream f(this->qfile);
    std::string s;

    if (!f.is_open())
        throw (QError(ERR_INV_OPN));
    for (this->size = 0; std::getline(f, s);) {
        trim(s);
        if (s.length() && s != "\"\"" && s != "-" && s != " " && s != "\" \"")
            this->size++;
    }
    f.close();
    this->size /= 2;
    if (!this->size)
        throw (QError(ERR_VAL_EMP));
}
Quoter::~Quoter(void){}
const bool Quoter::get_listA(void) const { return (this->listA); };

QError::QError(const std::string& e) : msg(e) {}
QError::~QError(void) {}

int main(int ac, char **av)
{
    if (ac == 2 && (!strcmp(av[1], "-h") || !strcmp(av[1], "--help")))
        return (help(av[0]));
    try {
        Quoter quoter(ac, av);
        srand(time(NULL));
        if (quoter.get_listA())
            return (quoter.listAuthors());
        while (quoter.process() == FAILURE);
    } catch (const QError &e) {
        std::cout << e.what() << std::endl;
        return (FAILURE);
    }
    return (SUCCESS);
}
