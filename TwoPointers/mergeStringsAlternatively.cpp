#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Function to merge two strings alternately
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        int m = word1.length();
        int n = word2.length();
        string ans = "";

        // Merge characters alternately
        while(i < m && j < n){
            ans += word1[i];
            ans += word2[j];
            i++;
            j++;
        }

        // Append remaining characters from word1
        while(i < m){
            ans += word1[i];
            i++;
        }

        // Append remaining characters from word2
        while(j < n){
            ans += word2[j];
            j++;
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Test cases
    string testCases[][2] = {
        {"abc", "pqr"},
        {"ab", "pqrs"},
        {"abcd", "pq"}
    };

    for(auto &testCase : testCases) {
        string word1 = testCase[0];
        string word2 = testCase[1];
        cout << "word1: \"" << word1 << "\", word2: \"" << word2 << "\"\n";
        cout << "Merged: \"" << solution.mergeAlternately(word1, word2) << "\"\n\n";
    }

    return 0;
}