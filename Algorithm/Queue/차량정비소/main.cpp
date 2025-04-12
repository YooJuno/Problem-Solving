#include <iostream>
#include <queue>

using namespace std;

struct Customer
{
    int arriveTime;
    int idx;
    int remainingTime;
    int num1;
    int num2;
};

struct CMP1
{
    bool operator()(Customer c1, Customer c2)
    {
        return c1.arriveTime > c2.arriveTime;
    }
};

struct CMP2
{
    bool operator()(Customer c1, Customer c2)
    {
        return c1.num1 > c2.num1;
    }
};

int N, M, K, A, B;
int ai[9];
int bj[9];
queue<Customer> pqRegister;
priority_queue<Customer, vector<Customer>, CMP2> pqRepairing;

Customer regeisters[10];
Customer repairings[10];

bool isCounseling[10];
bool isRepairing[10];

void Init()
{
    while(!pqRegister.empty())
    {
        pqRegister.pop();
    }
    while(!pqRepairing.empty())
    {
        pqRepairing.pop();
    }
}

void Input()
{
    cin >> N >> M >> K >> A >> B;
    for (int j = 1; j <= N; j++)
    {
        cin >> ai[j];
    }
    for (int j = 1; j <= M; j++)
    {
        cin >> bj[j];
    }
    for (int j = 1; j <= K; j++)
    {
        int t; cin >> t;
        pqRegister.push({t, j, 0, 0, 0});
    }
}

int main()
{
    freopen("./sample_input.txt", "r", stdin);

    int T; cin >> T;
    for (int test_case = 1; test_case <= T; test_case++)
    {
        Init();
        Input();

        int result = 0;

        while(true)
        {
            for (int i = 1; i <= N; i++)
            {
                if(isCounseling[i] == false)
                {
                    isCounseling[i] = true;
                    regeisters[i] = pqRegister.front();
                    regeisters[i].remainingTime = ai[i];
                    regeisters[i].num1 = i;
                    
                    pqRegister.pop();
                }
                else
                {
                    regeisters[i].remainingTime--;
                    if(regeisters[i].remainingTime == 0)
                    {
                        pqRepairing.push(regeisters[i]);
                        isCounseling[i] = false;
                    }
                }
            }
            
            for (int i = 1; i <= M; i++)
            {
                if(isRepairing[i] == false)
                {
                    isRepairing[i] = true;
                    repairings[i] = pqRepairing.top();
                    repairings[i].remainingTime = bj[i];
                    repairings[i].num2 = i;
                    
                    pqRepairing.pop();
                }
                
                else
                {
                    repairings[i].remainingTime--;
                    if(repairings[i].remainingTime == 0)
                    {
                        if(repairings[i].num1 == A && repairings[i].num2 == B)
                        {
                            result += repairings[i].idx;
                        }
                        isRepairing[i] = false;
                    }
                }
            }

            if(pqRegister.empty() && pqRepairing.empty())
            {
                break;
            }
        }

        cout << (result == 0) ? -1 : result;
    }

    return 0;
}