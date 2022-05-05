class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p)
    {
        set<vector<int>> visited;

        for (int i = 0; i < nums.size(); i++)
        {
            int count = 0;
            vector<int> currSubArray;

            for (int j = i; j < nums.size(); j++)
            {
                currSubArray.push_back(nums[j]);
                if (nums[j] % p == 0)
                    count++;

                if (count > k)
                    break;

                visited.insert(currSubArray);
            }
        }

        return visited.size();
    }
};