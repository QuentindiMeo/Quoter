/*
** PERSONAL PROJECT, 2020
** quoter
** File description:
** quoter seeking functions
*/

#include "Errors.hpp"
#include "Quoter.hpp"

static uint findIdx(const std::vector<std::vector<std::string>>& q,
                    const std::vector<std::string>& v)
{
    uint idx = 1;

    for (std::vector<std::string> aq : q) {
        if (aq == v)
            break;
        idx++;
    }
    return (idx);
}

void Quoter::pickSeeked(void)
{
    this->quote = this->quotes[rand() % this->quotes.size()];
    this->idx = findIdx(this->allquotes, this->quote);
    this->size = this->quotes.size();
}

void Quoter::setupSeeked(void)
{
    trim(this->pattern);
    trim(this->autwork);
    this->quotes = this->allquotes;
    for (uint i = 0; i < this->quotes.size(); i++)
        if (pattern != "" && !patternFound(this->quotes[i], pattern)) {
            this->quotes.erase(this->quotes.begin() + i);
            i--;
        }
    for (uint i = 0; i < this->quotes.size(); i++)
        if (autwork != "" && !autworkFound(this->quotes[i], autwork)) {
            this->quotes.erase(this->quotes.begin() + i);
            i--;
        }
    if (!this->quotes.size())
        throw (QError(ERR_VAL_EMP));
}
