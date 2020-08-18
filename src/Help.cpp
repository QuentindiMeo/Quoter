/*
** PERSONAL PROJECT, 2020
** quoter
** File description:
** quoter help
*/

#include "Quoter.hpp"

static void help2(void)
{
    std::cout << "\033[1m--list\033[0m\n\t\tList all authors in the quotes "
    "source file  alphabetically\n\t\tand exit.\n\n\t\033[1m-q\033[0m \033[4m"
    "file\033[0m\n\t\tChange the quotes source file to \033[4mfile\033[0m.\n\n"
    "\t\033[1m-s \033[0m\033[4mfile\033[0m\n\t\tChange the quotes save file to "
    "\033[4mfile\033[0m.\n\n\t\033[1m--seek\033[0m=\033[4mPATTERN\033[0m\n\t\t"
    "Find a quote that has \033[4mPATTERN\033[0m in its text field.\n\n\t"
    "\033[1m--from\033[0m=\033[4mPATTERN\033[0m\n\t\tFind a quote that has "
    "\033[4mPATTERN\033[0m in the quote's reference.\n\n\t\033[1m--nomd, --no-"
    "markdown\033[0m\n\t\tDisable the program's pseudo-Markdown formatting.\n\n"
    "\t\033[1m-h, --help\033[0m\n\t\tDisplay this help and exit.\n\n   \033[1m"
    "Quotes file content sample:\033[0m\n\t\"I am a quote\"\n\t- Me\n\n\t\"I am"
    " a long quote, _oh\n\tyes_ a very long one\"\n\t-someone; somewhere\n\n   "
    "\033[1mExit status:\033[0m\n\t0\tif everything went as expected,\n\t84\t"
    "if   anything went wrong (file opening, empty file...).\n\n \033[1mAUTHOR"
    "\033[0m\n\tWritten by Quentin di Meo.\n\n \033[1mREPORTING BUGS\033[0m\n\t"
    "Report any bug or functioning error to <quentin.di-meo@epitech.eu>\n"
              << std::endl;
}

return_values_t help(const char *bin)
{
    std::cout << "\n\tWelcome to your friendly quotes dispenser.\n\n \033[1m"
    "USAGE\033[0m\n\t" << bin << " [\033[4mOPTION\033[0m]...\n\n \033[1m"
    "DESCRIPTION\033[0m\n\tI wrote this for it to display a quote in my ter"
    "minal every time I\n\topen it, which will mostly happen in the morning. "
    "Feel free to use\n\tit and even tweak it as you wish.  I think it can be "
    "a good way to\n\tinspire you every once in a while!\n\n\tA save file aims "
    "to prevent  the  program  from printing the exact\n\tsame quote twice in a"
    " row. The program was designed to support the\n\taddition of the name of a"
    " book,  song  or  movie after the name of\n\twhom the quote is from.  Note"
    " that \033[1m--seek\033[0m and \033[1m--from\033[0m are both case\n\tin"
    "sensitive.\n\n\tThis program also supports pseudo-Markdown with  '_' and "
    "'__' that\n\ttoggle  italic  and  bold  priting when text is put in "
    "between two\n\toccurrences of those tags.\n\n\t";
    help2();
    return (SUCCESS);
}
