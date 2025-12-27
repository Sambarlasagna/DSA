// Soln 1 : -
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int maxx = 0;
        int count = 0;
        if (nums.size() == 0)
        {
            return 0;
        }
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] == 1)
            {
                cout << count << " ";
                count++;
            }
            else if (nums[i] - nums[i - 1] == 0)
            {
            }
            else
            {
                maxx = max(count + 1, maxx);
                count = 0;
            }
        }
        maxx = max(count + 1, maxx);
        return maxx;
    }
};