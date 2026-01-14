#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// O(N) & O(k)
bool containsDuplicateII(vector<int>& nums, int k)
{
    unordered_set<int> window;

    for (int i = 0; i < nums.size(); i++)
    {
        if (window.count(nums[i])) return true;

        window.insert(nums[i]);
        if (window.size() > k)
            window.erase(nums[i - k]);
    }

    return false;
}

/*
// O(N) & O(N)
bool containsDuplicateII(vector<int>& nums, int k)
{
    unordered_map<int, int> map;

    for(int i = 0; i < nums.size(); i++)
    {
        if(map.count(nums[i]) && abs(map[nums[i]] - i) <= k) return true;

        map[nums[i]] = i;
    }
    
    return false;
}
*/

int main()
{
    vector<int> nums = {15, 7, 6, 11, 6};
    int k = 1;

    if (containsDuplicateII(nums, k))
        cout << "Contains Duplicate" << endl;
    else
        cout << "No Duplicate Found." << endl;

    return 0;
}
