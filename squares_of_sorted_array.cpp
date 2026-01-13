class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        vector<int> result(nums.size(), 0);
        for (int x = n - 1; x >= 0; x--)
        {
            if (abs(nums[i]) > abs(nums[j]))
            {
                result[x] = nums[i] * nums[i];
                i++;
            }
            else
            {
                result[x] = nums[j] * nums[j];
                j--;
            }
        }
        return result;
    }
};