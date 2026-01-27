#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Remove duplicates in-place and return new length
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0; // Handle empty array

        int i = 0; // Slow pointer
        for(int j = 1; j < n; j++){ // Fast pointer
            if(nums[i] != nums[j]){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        return i + 1;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> testCases = {
        {1,1,2},
        {0,0,1,1,1,2,2,3,3,4},
        {1,2,3,4,5},
        {},
        {1,1,1,1}
    };

    for(auto nums : testCases) {
        cout << "Original array: ";
        for(int num : nums) cout << num << " ";
        cout << "\n";

        int newLength = solution.removeDuplicates(nums);

        cout << "After removing duplicates: ";
        for(int i = 0; i < newLength; i++) cout << nums[i] << " ";
        cout << "\nNew length: " << newLength << "\n\n";
    }

    return 0;
}