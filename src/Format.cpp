/*
** PERSONAL PROJECT, 2020
** quoter
** File description:
** quoter formatting functions
*/

#include <string>

static void formatItal(std::string& line, bool& openI, bool& openB)
{
    while (line.find("_") != std::string::npos) {
        if (!openI) {
            line = line.substr(0, line.find("_")) + "\033[3m" +
                   line.substr(line.find("_") + 1, line.length());
            openI = true;
        } else if (openB) {
            line = line.substr(0, line.find("_")) + "\033[0m\033[1m" +
                   line.substr(line.find("_") + 1, line.length());
            openI = false;
        } else {
            line = line.substr(0, line.find("_")) + "\033[0m" +
                   line.substr(line.find("_") + 1, line.length());
            openI = false;
        }
    }
}

static void formatBold(std::string& line, bool& openI, bool& openB)
{
    while (line.find("__") != std::string::npos) {
        if (!openB) {
            line = line.substr(0, line.find("__")) + "\033[1m" +
                   line.substr(line.find("__") + 2, line.length());
            openB = true;
        } else if (openI) {
            line = line.substr(0, line.find("__")) + "\033[0m\033[3m" +
                   line.substr(line.find("__") + 2, line.length());
            openB = false;
        } else {
            line = line.substr(0, line.find("__")) + "\033[0m" +
                   line.substr(line.find("__") + 2, line.length());
            openB = false;
        }
    }
}

static void formatBoth(std::string& line, bool& openI, bool& openB)
{
    while (line.find("___") != std::string::npos) {
        if (!openI && !openB) {
            line = line.substr(0, line.find("___")) + "\033[3m\033[1m" +
                   line.substr(line.find("___") + 3, line.length());
            openI = true; openB = true;
        } else {
            line = line.substr(0, line.find("___")) + "\033[0m" +
                   line.substr(line.find("___") + 3, line.length());
            openI = false; openB = false;
        }
    }
}

void formatLine(std::string& line)
{
    static bool first =  true;
    static bool openI = false;
    static bool openB = false;

    if (first) {
        line = "\033[0m" + line;
        first = false;
    }
    formatBoth(line, openI, openB);
    formatBold(line, openI, openB);
    formatItal(line, openI, openB);
}
