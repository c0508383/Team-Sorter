#include "Team.h"

Team::Team(){
    name = "";
    wins = 0;
    ties = 0;
    losses = 0;
}
Team::Team(string name, int wins, int ties, int losses){
    this->name = name;
    this->wins = wins;
    this->ties = ties;
    this->losses = losses;
}

bool Team::operator<(const Team& rhs){
    if(wins == rhs.getWins() && ties == rhs.getTies() && losses == rhs.getLosses()){
        if(name < rhs.getName())
            return true;
    }
    if(wins > rhs.getWins())
        return true;
    else if(wins == rhs.getWins() && ties > rhs.getTies())
        return true;
    else if(ties == rhs.getTies() && losses < rhs.getLosses())
        return true;

    return false;
}
bool Team::operator==(const Team& rhs){
    if(rhs.getName() == name)
        return true;
    
    return false;
}
 std::ostream& operator << (std::ostream& os,const Team& t)
{
    os << t.getName() << " W:" << t.getWins() << " T:" << t.getTies() << " L:" << t.getLosses();
    return os;
}  

string Team::getName()const{return name;}
int Team::getWins()const{return wins;}
int Team::getTies()const{return ties;}
int Team::getLosses()const{return losses;}