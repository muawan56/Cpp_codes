#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

char *copyString(char *t, const char *s)
{
    for (int i = 0; true; i++)
    {
        t[i] = s[i];
        if (s[i] == 0)
            return t;
    }
}

class Player
{
    char fName[11], sName[12], country[13], span[10];
    int noOfMatches, noOfInnings, noOfNotOuts, runs, highest;
    double average, ballsFaced, strikeRate;
    int noOf100s, noOf50s, noOfZeros, noOf4s, noOf6s;

public:
    Player() {}

    void readValues(ifstream &in)
    {
        in >> fName >> sName >> country >> span;
        in.clear();
        in >> noOfMatches >> noOfInnings >> noOfNotOuts >> runs >> highest;
        in >> average >> ballsFaced >> strikeRate >> noOf100s >> noOf50s;
        in >> noOfZeros >> noOf4s >> noOf6s;
    }

    const char *getFirstName() const { return fName; }
    int getRuns() const { return runs; }

    Player(const Player &other)
    {
        copyString(fName, other.fName);
        copyString(sName, other.sName);
        copyString(country, other.country);
        copyString(span, other.span);
        noOfMatches = other.noOfMatches;
        noOfInnings = other.noOfInnings;
        noOfNotOuts = other.noOfNotOuts;
        runs = other.runs;
        highest = other.highest;
        average = other.average;
        ballsFaced = other.ballsFaced;
        strikeRate = other.strikeRate;
        noOf100s = other.noOf100s;
        noOf50s = other.noOf50s;
        noOfZeros = other.noOfZeros;
        noOf4s = other.noOf4s;
        noOf6s = other.noOf6s;
    }

    Player &operator=(const Player &other)
    {
        if (this != &other)
        {
            copyString(fName, other.fName);
            copyString(sName, other.sName);
            copyString(country, other.country);
            copyString(span, other.span);
            noOfMatches = other.noOfMatches;
            noOfInnings = other.noOfInnings;
            noOfNotOuts = other.noOfNotOuts;
            runs = other.runs;
            highest = other.highest;
            average = other.average;
            ballsFaced = other.ballsFaced;
            strikeRate = other.strikeRate;
            noOf100s = other.noOf100s;
            noOf50s = other.noOf50s;
            noOfZeros = other.noOfZeros;
            noOf4s = other.noOf4s;
            noOf6s = other.noOf6s;
        }
        return *this;
    }

    void showIthPlayer() const
    {
        cout << setw(11) << left << fName << setw(13) << left << sName << setw(15) << left << country
             << setw(9) << left << span << setw(5) << noOfMatches << setw(5) << noOfInnings
             << setw(5) << noOfNotOuts << setw(5) << runs << setw(5) << highest << setw(7) << average
             << setw(5) << ballsFaced << setw(7) << strikeRate << setw(5) << noOf100s << setw(5)
             << noOf50s << setw(5) << noOfZeros << setw(5) << noOf4s << setw(5) << noOf6s << "\n";
    }
};

class PlayersList
{
    int playersCount;
    Player *players;

public:
    PlayersList()
    {
        ifstream in("T20.txt");
        if (in.fail())
        {
            cout << "Error";
            playersCount = 0;
            return;
        }

        in >> playersCount;
        players = new Player[playersCount];
        for (int i = 0; i < playersCount; ++i)
        {
            players[i].readValues(in);
        }
        in.close();
    }

    void searchByFirstName(const char *nam) const
    {
        for (int i = 0; i < playersCount; ++i)
        {
            if (strcmp(players[i].getFirstName(), nam) == 0)
            {
                players[i].showIthPlayer();
                return;
            }
        }
        cout << "Player is not in the list." << endl;
    }

    void showPlayersGreaterThanEqualRuns(int runs) const
    {
        for (int i = 0; i < playersCount; ++i)
        {
            if (players[i].getRuns() >= runs)
            {
                players[i].showIthPlayer();
            }
        }
    }

    void sortPlayers()
    {
        // Bubble sort
        for (int i = 0; i < playersCount - 1; ++i)
        {
            for (int j = 0; j < playersCount - i - 1; ++j)
            {
                if (players[j].getRuns() < players[j + 1].getRuns())
                {
                    swap(players[j], players[j + 1]);
                }
            }
        }
    }

    void showAll() const
    {
        printHeading();
        for (int i = 0; i < playersCount; ++i)
        {
            players[i].showIthPlayer();
        }
    }

    ~PlayersList()
    {
        delete[] players;
    }

private:
    void printHeading() const
    {
        cout << " Name           Country           Span      MC  IC   NO  RS   HS  AVE   BF   SR  100s 50s 0's 4s  6s\n";
        cout << "-----------------------------------------------------------------------------------------------------\n";
    }
};

int main()
{
    int temp;
    PlayersList list;
    list.searchByFirstName("Babar");
    cin >> temp;
    list.showPlayersGreaterThanEqualRuns(25000);
    cin >> temp;
    list.showPlayersGreaterThanEqualRuns(2500);
    cin >> temp;
    list.sortPlayers();
    list.showAll();
    return 0;
}
