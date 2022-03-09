#include "Player.h"

Player::Player() : name(""), score(0) {}

Player::Player(const string& n, int s) : name(n), score(s) {}

void Player::setName(const string& n)
{
    name = n;
}
void Player::setScore(int s)
{
    score = s;
}

string Player::getName() const
{
    return name;
} 

int Player::getScore() const
{
    return score;
}