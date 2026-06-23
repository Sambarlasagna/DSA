class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> cnt(26, 0);

        for (char c : tasks)
            cnt[c - 'A']++;

        priority_queue<int> pq;

        for (int x : cnt)
            if (x)
                pq.push(x);

        queue<pair<int, int>> q;

        int time = 0;

        while (!pq.empty() || !q.empty())
        {

            time++;

            while (!q.empty() && q.front().second <= time)
            {
                pq.push(q.front().first);
                q.pop();
            }

            if (!pq.empty())
            {
                int cur = pq.top();
                pq.pop();

                cur--;

                if (cur > 0)
                    q.push({cur, time + n + 1});
            }
        }

        return time;
    }
};