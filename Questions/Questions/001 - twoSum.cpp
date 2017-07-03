#include "001 - twoSum.h"
#include "config.h"

using namespace std;

vector<int> Solution001::twoSum(vector<int>& nums, int target)
{
    vector<int> result;
    unordered_map<int, int> hashMap;

    for (int i = 0; i < nums.size(); i++)
    {
        if (hashMap.count(target - nums[i]) != 0)
        {
            result.push_back(hashMap.find(target - nums[i])->second);
            result.push_back(i);
            break;
        }

        hashMap.insert(pair<int, int>(nums[i], i));
    }

    return result;
}

