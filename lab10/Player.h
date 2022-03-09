#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
    private:
        string name;
        int score;
    public:
        Player();
        Player(const string& n, int s);
        void setName(const string& n);
        void setScore(int s);
        string getName() const;
        int getScore() const;
};
#endif