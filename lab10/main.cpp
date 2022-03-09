#include "Player.cpp"
#include <iostream>
using namespace std;

Player* addPlayer(Player* players, int& numPlayers);
void printPlayers(Player* players, int numPlayers);
void searchPlayers(Player* players, int numPlayers);
Player* removePlayer(Player* players, int& numPlayers);

int main()
{
    char option;
    Player* players = NULL; // array of players
    int numPlayers = 0;
    
    do
    {
        cout << "Enter an option." << endl;
		cout << "--------------------------------" << endl;
        cout << "a. Add new player and score." << endl; 
        cout << "b. Print all players and scores." << endl;
        cout << "c. Search for a player's score." << endl; 
        cout << "d. Remove a player." << endl;
        cout << "e. Quit." << endl;
		cout << "--------------------------------" << endl;
        cout << "OPTION: ";

        cin >> option;
        if (option == 'a')
        {
            players = addPlayer(players, numPlayers);
        }
        else if (option == 'b')
        {
            printPlayers(players, numPlayers);
        }
        else if (option == 'c')
        {
            searchPlayers(players, numPlayers);
        }
        else if (option == 'd')
        {
            players = removePlayer(players, numPlayers);
        }
        cout << endl;
    } while (option != 'e');

    // Clean up dynamic memory 
    // << YOUR CODE >>
    return 0;
}

Player* addPlayer(Player* players, int& numPlayers)
{
    // << YOUR CODE >>
    return players;
}

void printPlayers(Player* players, int numPlayers)
{
    // << YOUR CODE >>
}

void searchPlayers(Player* players, int numPlayers)
{
    // << YOUR CODE >>
}

Player* removePlayer(Player* players, int& numPlayers)
{
    // << YOUR CODE >>
    return players;
}
