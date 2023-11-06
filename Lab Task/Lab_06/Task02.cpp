#include <iostream>
#include <ctime>
using namespace std;

class PlayerTournament
{
private:
    int tournaments;
    int *matches;
    int **p;

public:
    PlayerTournament();
    ~PlayerTournament();
    PlayerTournament(const PlayerTournament &);
    PlayerTournament &operator=(const PlayerTournament &);
    PlayerTournament &operator+=(const int &);
    friend ostream &operator<<(ostream &, const PlayerTournament &);
    friend istream &operator>>(istream &, PlayerTournament &);
};

PlayerTournament::PlayerTournament()
{
    tournaments = rand() % 10 + 1;
    p = new int *[tournaments];
    matches = new int[tournaments];
    for (int i = 0; i < tournaments; i++)
    {
        matches[i] = rand() % 5 + 1;
    }

    for (int i = 0; i < tournaments; i++)
    {
        p[i] = new int[matches[i]];
        for (int j = 0; j < matches[i]; j++)
        {
            p[i][j] = rand() % 201;
        }
    }
}

PlayerTournament::PlayerTournament(const PlayerTournament &orig)
{
    tournaments = orig.tournaments;
    matches = new int[tournaments];
    p = new int *[tournaments];

    for (int i = 0; i < tournaments; i++)
    {
        matches[i] = orig.matches[i];
        p[i] = new int[matches[i]];
        for (int j = 0; j < matches[i]; j++)
        {
            p[i][j] = orig.p[i][j];
        }
    }
}

PlayerTournament &PlayerTournament::operator=(const PlayerTournament &orig)
{
    if (this != &orig)
    {
        // Clean up existing data
        for (int i = 0; i < tournaments; i++)
        {
            delete[] p[i];
        }
        delete[] p;
        delete[] matches;

        // Copy data from orig
        tournaments = orig.tournaments;
        matches = new int[tournaments];
        p = new int *[tournaments];

        for (int i = 0; i < tournaments; i++)
        {
            matches[i] = orig.matches[i];
            p[i] = new int[matches[i]];
            for (int j = 0; j < matches[i]; j++)
            {
                p[i][j] = orig.p[i][j];
            }
        }
    }
    return *this;
}

PlayerTournament::~PlayerTournament()
{
    for (int i = 0; i < tournaments; ++i)
    {
        delete[] p[i];
    }
    delete[] p;
    delete[] matches;
}

PlayerTournament &PlayerTournament::operator+=(const int &k)
{
    int *newmatches = new int[tournaments + 1];
    for (int i = 0; i < tournaments; i++)
    {
        newmatches[i] = matches[i];
    }
    newmatches[tournaments] = k;

    int **newp = new int *[tournaments + 1];
    for (int i = 0; i < tournaments; i++)
    {
        newp[i] = new int[matches[i]];
        for (int j = 0; j < matches[i]; j++)
        {
            newp[i][j] = p[i][j];
        }
    }
    newp[tournaments] = new int[k];
    for (int i = 0; i < k; i++)
    {
        newp[tournaments][i] = rand() % 201;
    }

    for (int i = 0; i < tournaments; i++)
    {
        delete[] p[i];
    }
    delete[] p;
    delete[] matches;
    tournaments++;
    matches = newmatches;
    p = newp;

    return *this;
}

ostream &operator<<(ostream &out, const PlayerTournament &orig)
{
    out << orig.tournaments << " tournaments" << endl;
    for (int i = 0; i < orig.tournaments; i++)
    {
        out << "tournament " << i + 1 << " : ";
        out << orig.matches[i] << " matches." << endl;
        out << "Scores: ";
        for (int j = 0; j < orig.matches[i]; j++)
        {
            out << orig.p[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

istream &operator>>(istream &in, PlayerTournament &orig)
{
    in >> orig.tournaments;
    for (int i = 0; i < orig.tournaments; i++)
    {
        in >> orig.matches[i];
        for (int j = 0; j < orig.matches[i]; j++)
        {
            in >> orig.p[i][j];
        }
    }
    return in;
}

int main()
{
    srand(time(0));
    PlayerTournament p1[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Player: " << i + 1 << " : " << p1[i];
    }

    p1[2] += 5;
    cout << "Player 2 after +=: " << p1[2];
}
