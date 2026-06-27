class Twitter
{
public:
    int timer = 0;

    unordered_map<int, set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {}

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {

        priority_queue<vector<int>> pq;

        if (!tweets[userId].empty())
        {
            int idx = tweets[userId].size() - 1;

            pq.push({tweets[userId][idx].first,  // time
                     tweets[userId][idx].second, // tweetId
                     userId,
                     idx});
        }

        for (int followee : following[userId])
        {

            if (!tweets[followee].empty())
            {

                int idx = tweets[followee].size() - 1;

                pq.push({tweets[followee][idx].first,
                         tweets[followee][idx].second,
                         followee,
                         idx});
            }
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10)
        {

            auto cur = pq.top();
            pq.pop();

            int tweetId = cur[1];
            int user = cur[2];
            int idx = cur[3];

            ans.push_back(tweetId);

            idx--;

            if (idx >= 0)
            {
                pq.push({tweets[user][idx].first,
                         tweets[user][idx].second,
                         user,
                         idx});
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        following[followerId].erase(followeeId);
    }
};