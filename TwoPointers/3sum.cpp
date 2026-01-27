#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to find all unique triplets that sum to 0
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // Sort array

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; // Skip duplicates

            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0){
                    j++;
                } else if(sum > 0){
                    k--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // Skip duplicates
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> testCases = {
        {-1, 0, 1, 2, -1, -4},
        {0, 0, 0, 0},
        {1, 2, -2, -1},
        {-2, 0, 1, 1, 2}
    };

    for(auto nums : testCases) {
        cout << "Input array: ";
        for(int num : nums) cout << num << " ";
        cout << "\n";

        vector<vector<int>> result = solution.threeSum(nums);

        cout << "Triplets summing to 0:\n";
        for(auto &triplet : result){
            cout << "[";
            for(int i = 0; i < triplet.size(); i++){
                cout << triplet[i];
                if(i < triplet.size() - 1) cout << ", ";
            }
            cout << "]\n";
        }
        cout << "\n";
    }

    return 0;
}