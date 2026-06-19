class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<vector<int>> pq;

        for (vector<int> v : points)
        {
            pq.push({v[0] * v[0] + v[1] * v[1], v[0], v[1]});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<vector<int>> v;
        while (!pq.empty())
        {
            v.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }
        return v;
    }
};