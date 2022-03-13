#include "Player.h"
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
    delete [] players;
    return 0;
}

Player* addPlayer(Player* players, int& numPlayers)
{
    Player* temp = new Player[numPlayers + 1];
    int count = 0;
    while (count < numPlayers) {
	    temp[count] = players[count];
	    count++;
    }
    string playername;
    int playerscore;
    cout << "Enter New Player Name: ";
    cin >> playername;
    cout << "Enter New Player Score: ";
    cin >> playerscore;
    temp[numPlayers] = Player(playername, playerscore);
    delete [] players;
    players = temp;
    numPlayers++;
    return players;
}

void printPlayers(Player* players, int numPlayers)
{
    for (int i = 0; i < numPlayers; i++){
        cout << players[i].getName() << " has a score of " << players[i].getScore() << endl;
    }
    cout << "enter anything to continue: ";
    string temp;
    cin >> temp;
}

void searchPlayers(Player* players, int numPlayers)
{
	string name;
	cout << "Give a player name: ";
	cin >> name;
	for (int i = 0; i < numPlayers; i++) {
		if (players[i].getName() == name) {
			cout << "Player " << name << " has a score of " << players[i].getScore() << endl;
			return;
		}
	}
	cout << "Player not found" << endl;
    // << YOUR CODE >>
}

Player* removePlayer(Player* players, int& numPlayers)
{
    // << YOUR CODE >>
	string remove;
	cout << "Enter player name to remove: ";
	cin >> remove;
	int loop = 0;
	while (loop < numPlayers) {
		if (players[loop].getName() == remove) {
			break;
		}
		loop++;
	}
	if (loop == numPlayers) {
		cout << "Player not found!";
		return players;
	}

	return players;
}
