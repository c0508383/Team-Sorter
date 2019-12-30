#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <iostream>
using namespace std;

class Team{
    private:
        string name;
        int wins;
        int ties;
        int losses;
    public:
        Team();
        Team(string name, int wins, int ties, int losses);
        
        bool operator<(const Team& rhs);
        bool operator==(const Team& rhs);

        string getName()const;
        int getWins()const;
        int getTies()const;
        int getLosses()const;
};
std::ostream& operator << (std::ostream& os, const Team& t);

#endif