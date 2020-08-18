/*
** PERSONAL PROJECT, 2020
** quoter
** File description:
** quoter setup
*/

#include <stdlib.h>
#include <getopt.h>
#include "Errors.hpp"
#include "Quoter.hpp"

std::string Quoter::do_switch(char c, const char *optarg)
{
    switch (c) {
    case 'l' :
        this->listA = true;
        break;
    case 'q' :
        this->qfile = optarg;
        break;
    case 's' :
        this->sfile = optarg;
        break;
    case 'm' :
        this->markdown = false;
        break;
    case 'f' :
        this->seeking = true;
        this->autwork = optarg;
        break;
    case 'w' :
        this->seeking = true;
        this->pattern = optarg;
        break;
    case '?' :
        return ("");
        break;
    }
    return ("All good!");
}

static struct option *set_longopts(void)
{
    struct option *longopts =
           static_cast<struct option *>(malloc(sizeof(struct option) * 4));

    longopts[0] = {"list", no_argument,       NULL, 'l'};
    longopts[1] = {"seek", required_argument, NULL, 'w'};
    longopts[2] = {"from", required_argument, NULL, 'f'};
    longopts[3] = {"nomd", no_argument,       NULL, 'm'};
    longopts[4] = longopts[4];
    longopts[4].name = "no-markdown";
    return (longopts);
}

void Quoter::catchParameters(int ac, char **av)
{
    char c = 0;
    std::string ret_v;
    struct option *longopts = set_longopts();

    do {
        c = getopt_long(ac, av, "q:s:", longopts, NULL);
        if (c == ERROR)
            break;
        ret_v = this->do_switch(c, optarg);
        if (!ret_v.length()) {
            free(longopts);
            throw (QError(ERR_INV_PRM));
        }
    } while (c != END_OF_ARGS);
    free(longopts);
}
