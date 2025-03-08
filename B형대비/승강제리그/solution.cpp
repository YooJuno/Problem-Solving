#include <set>

struct Player
{
    int id;
    int ability;

    bool operator<(const Player &next) const
    {
        if (ability == next.ability)
        {
            return id < next.id;
        }
        return ability > next.ability;
    }
};

int numOfPlayer;
int numOfLeague;
int lenOfLeague;
std::set<Player> s[10];

void init(int N, int L, int mAbility[])
{
    for (int i = 0; i < L; i++)
    {
        s[i].clear();
    }

    numOfPlayer = N;
    numOfLeague = L;
    lenOfLeague = numOfPlayer / numOfLeague;
    

    for (int i = 0; i < N; i++)
    {
        s[i / lenOfLeague].insert({ i, mAbility[i] });
    }
}

int move()
{
    int result = 0;
    Player lowInPre;
    Player highInNow;
    Player TempL;
    Player TempR;

    for (int i = 1; i < numOfLeague; i++)
    {

        auto preBack = prev(s[i - 1].end());
        auto nowFront = s[i].begin();

        lowInPre = *preBack;
        highInNow = *nowFront;

        result += (lowInPre.id + highInNow.id);

        s[i - 1].erase(lowInPre);
        s[i - 1].insert(highInNow);

        if (i > 1)
        {
            s[i - 1].erase(TempR);
            s[i - 1].insert(TempL);
        }

        TempL = lowInPre;
        TempR = highInNow;
    }

    s[numOfLeague - 1].erase(TempR);
    s[numOfLeague - 1].insert(TempL);

    return result;
}

int trade()
{
    int result = 0;
    Player midInPre;
    Player highInNow;
    Player TempL;
    Player TempR;

    for (int i = 1; i < numOfLeague; i++)
    {
        auto preMid = next(s[i - 1].begin(), lenOfLeague/2);
        auto nowFront = s[i].begin();

        midInPre = *preMid;
        highInNow = *nowFront;

        result += (midInPre.id + highInNow.id);

        s[i - 1].erase(midInPre);
        s[i - 1].insert(highInNow);

        if (i > 1)
        {
            s[i - 1].erase(TempR);
            s[i - 1].insert(TempL);
        }

        TempL = midInPre;
        TempR = highInNow;
    }

    s[numOfLeague - 1].erase(TempR);
    s[numOfLeague - 1].insert(TempL);

    return result;
}