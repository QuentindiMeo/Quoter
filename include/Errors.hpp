/*
** PERSONAL PROJECT, 2020
** quoter
** File description:
** quoter errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

static const std::string ERR_INV_PRM =
                         "Try './quoter --help' for more information.";
static const std::string ERR_INV_OPN =
                         "Error: quotes file couldn't be opened.";
static const std::string ERR_INV_SAV =
                         "Error: couldn't create save file to avoid dup's.";
static const std::string ERR_VAL_EMP =
                         "Error: seems like there is no quote for me to pick.";
static const std::string ERR_UNK = "Unknown error.";

class QError : public std::exception
{
public:
    ~QError();
    QError(std::string const &message = ERR_UNK);

    const char *what() const noexcept override { return (this->msg.c_str()); }
private:
    std::string msg;
};

#endif /* !ERRORS_HPP_ */
