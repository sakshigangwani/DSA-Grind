#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_set<int> window;

    for (int i = 0; i < nums.size(); i++)
    {
        if (window.find(nums[i]) != window.end())
        {
            return true;
        }

        window.insert(nums[i]);

        if (window.size() > k)
        {
            window.erase(nums[i - k]);
        }
    }

    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    if (containsNearbyDuplicate(nums, k))
    {
        cout << "Duplicate exists within distance " << k << endl;
    }
    else
    {
        cout << "No duplicate within distance " << k << endl;
    }

    return 0;
}