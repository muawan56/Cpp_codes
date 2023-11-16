#include <iostream>
#include <fstream>
#include <cstring>

class Player
{
public:
    char firstName[30];
    char lastName[30];
    int totalRuns;
    double average;

    Player() : totalRuns(0), average(0.0)
    {
        memset(firstName, 0, sizeof(firstName));
        memset(lastName, 0, sizeof(lastName));
    }

    Player(const char *fName, const char *lName, int runs, double avg)
        : totalRuns(runs), average(avg)
    {
        strncpy(firstName, fName, 30);
        firstName[30] = '\0'; // Ensure null-termination

        strncpy(lastName, lName, 30);
        lastName[30] = '\0'; // Ensure null-termination
    }

    void show() const
    {
        std::cout << "Player Details:\n"
                  << "Name: " << firstName << " " << lastName << "\n"
                  << "Total Runs: " << totalRuns << "\n"
                  << "Average: " << average << "\n\n";
    }
};

class PlayerList
{
private:
    Player players[100]; // Assuming a maximum of 100 players in the list
    int count;

public:
    PlayerList() : count(0) {}

    void sortPlayers()
    {
        // ... (Implementation for sorting players)
    }

    // Function to get the player at a specific index
    const Player &getPlayer(int index) const
    {
        return players[index];
    }
};

class Team
{
private:
    char teamName[31];
    Player teamPlayers[11];

public:
    Team(const char *tName, const PlayerList &playerList)
    {
        strncpy(teamName, tName, 30);
        teamName[30] = '\0'; // Ensure null-termination

        // Assuming that the players are already sorted in the playerList
        for (int i = 0; i < 11; ++i)
        {
            teamPlayers[i] = playerList.getPlayer(i);
        }
    }

    void show() const
    {
        std::cout << "Team Name: " << teamName << "\n\n";
        std::cout << "Team Players:\n";
        for (int i = 0; i < 11; ++i)
        {
            std::cout << i + 1 << ". ";
            teamPlayers[i].show();
        }
    }
};

int main()
{
    PlayerList list;

    // Assuming that the players are sorted before creating the team
    list.sortPlayers();

    Team team("ABCDEF", list);
    team.show();

    return 0;
}
