#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct News
{
    int id;
    int mTime;
    int mDealy;
    int cancelTime;
};

struct User
{
    int id;
    int mTime;
};

struct cmp
{
    bool operator()(News a, News b)
    {
        int aStart = a.mTime + a.mDealy;
        int bStart = b.mTime + b.mDealy;
        if( aStart == bStart )
        {
            return a.id < b.id;
        }
        else
        {
            return aStart < bStart;
        }
    }
};

unordered_map<int, vector<News>> users;
unordered_map<int, vector<User>> channels;

void init(int N, int K)
{
    users.clear();
    channels.clear();
}

void registerUser(int mTime, int mUID, int mNum, int mChannelIDs[])
{
    for (int i = 0; i < mNum; i++)
    {
        User user = { mUID, mTime };
        channels[mChannelIDs[i]].push_back(user);
    }
}

int offerNews(int mTime, int mNewsID, int mDelay, int mChannelID)
{
    int result = 0;
    for (auto &user : channels[mChannelID])
    {
        News news = { mNewsID, mTime, mDelay, 1000000000};
        users[user.id].push_back(news);  
        if(user.mTime <= mTime)
        {
            result++;
        }
    }

    return result;
}

void cancelNews(int mTime, int mNewsID)
{
    for (auto &newsV : users)
    {
        for (auto &news : newsV.second)
        {
            if(news.id == mNewsID)
            {
                if(news.cancelTime == -1) 
                {
                    continue;
                }
                // 등록하고 알림 전
                if(mTime < news.mTime + news.mDealy)
                {
                    news.cancelTime = -1;
                }
                // 알림 후
                else if(news.mTime + news.mDealy <= mTime && mTime < news.cancelTime)
                {
                    news.cancelTime = mTime;
                }
            }
        }
    }
}

int checkUser(int mTime, int mUID, int mRetIDs[])
{
    priority_queue<News, vector<News>, cmp> pq;
    int result = 0;
    
    for (auto &news : users[mUID])
    {
        // 알림을 받고 취소하기 전
        if(news.mTime + news.mDealy <= mTime && mTime < news.cancelTime)
        {
            result++;
            pq.push(news);
            news.cancelTime = -1;
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        if(pq.empty())
        {
            break;
        }
        mRetIDs[i] = pq.top().id;
        pq.pop();
    }

    return result;
}