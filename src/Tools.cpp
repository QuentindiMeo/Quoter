/*
** PERSONAL PROJECT, 2020
** quoter
** File description:
** quoter tools
*/

#include <algorithm>
#include <string>
#include <vector>

bool autworkFound(const std::vector<std::string>& v, const std::string& s)
{
    std::string a = v[v.size() - 1];
    std::string b = s;

    std::transform(a.begin(), a.end(), a.begin(), ::tolower);
    std::transform(b.begin(), b.end(), b.begin(), ::tolower);
    return (a.find(b) != std::string::npos);
}

bool patternFound(const std::vector<std::string>& v, const std::string& s)
{
    std::string b = s;

    std::transform(b.begin(), b.end(), b.begin(), ::tolower);
    for (uint i = 0; i < v.size() - 1; i++) {
        std::string a = v[i];

        std::transform(a.begin(), a.end(), a.begin(), ::tolower);
        if (a.find(b) != std::string::npos)
            return (true);
    }
    return (false);
}

static void replaceS(std::string &s, const std::string& t, const std::string& n)
{
    for (std::size_t pos = s.find(t); pos != std::string::npos; pos = s.find(t))
        s.replace(pos, t.length(), n);
}

void trim(std::string& s)
{
    uint i = 0;

    if (!s.length())
        return;
    replaceS(s, "\t", " ");
    replaceS(s, "  ", " ");
    for (char c : s) {
        if (c != ' ' && c != '\t') break;
        i++;
    }
    s = s.substr(i, s.length());
    for (i = s.length() - 1; i && (s[i] == ' ' || s[i] == '\t'); i--);
    s = s.substr(0, i + 1);
}
