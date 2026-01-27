#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Merge nums2 into nums1 in-place
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;          // Last index of initial nums1
        int j = n - 1;          // Last index of nums2
        int k = m + n - 1;      // Last index of merged array

        // Merge from the end
        while(j >= 0){
            if(i >= 0 && nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};

int main() {
    Solution solution;

    // Example test cases
    vector<pair<vector<int>, vector<int>>> testCases = {
        {{1,2,3,0,0,0}, {2,5,6}},    // nums1 has extra space
        {{1}, {}},                    // nums2 empty
        {{0}, {1}}                    // nums1 empty space for nums2
    };

    vector<int> m_values = {3, 1, 0};
    vector<int> n_values = {3, 0, 1};

    for(int t = 0; t < testCases.size(); t++) {
        vector<int> nums1 = testCases[t].first;
        vector<int> nums2 = testCases[t].second;
        int m = m_values[t];
        int n = n_values[t];

        cout << "Before merge:\n";
        cout << "nums1: ";
        for(int num : nums1) cout << num << " ";
        cout << "\nnums2: ";
        for(int num : nums2) cout << num << " ";
        cout << "\n";

        solution.merge(nums1, m, nums2, n);

        cout << "After merge:\nnums1: ";
        for(int num : nums1) cout << num << " ";
        cout << "\n\n";
    }

    return 0;
}