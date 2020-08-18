/*
** PERSONAL PROJECT, 2020
** quoter
** File description:
** quoter headers
*/

#ifndef QUOTER_HPP_
#define QUOTER_HPP_

#include <fstream>
#include <iostream>
#include <vector>

static const std::string QFILE = "quotes.txt";
static const std::string SFILE = "quotes.sav";

typedef enum {
    SUCCESS = 0,
    FAILURE = 84,
    ERROR = -1,
    END_OF_ARGS = -1,
} return_values_t;

typedef	unsigned int uint;

class Quoter
{
public:
    Quoter(int ac, char **av);
    ~Quoter(void);

    void            display(void);
    void       gotThatToday(void);
    bool      saidYesterday(void);
    void         pickSeeked(void);
    void        setupSeeked(void);
    void       getNextQuote(std::ifstream& file);
    return_values_t process(void);

    return_values_t listAuthors(void);
    const bool        get_listA(void) const;

    std::string do_switch(char c, const char *optarg);
    void        catchParameters(int ac, char **av);
private:
    std::string qfile;
    std::string sfile;
    bool listA;
    bool markdown;
    bool seeking;
    std::string autwork;
    std::string pattern;
    uint size;
    uint idx;
    std::vector<std::vector<std::string>> allquotes;
    std::vector<std::vector<std::string>> quotes;
    std::vector<std::string> quote;
};

bool autworkFound(const std::vector<std::string>& v, const std::string& s);
bool patternFound(const std::vector<std::string>& v, const std::string& s);

void formatLine(std::string& line);

void trim(std::string& s);
return_values_t help(const char *bin);

#endif /* !QUOTER_HPP_ */
