#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(string s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    // Main function to check if string can be palindrome after removing at most one character
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while(start < end) {
            if(s[start] == s[end]){
                start++;
                end--;
            } else {
                // Try removing either character
                return isPalindrome(s, start + 1, end) || isPalindrome(s, start, end - 1);
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    string testCases[] = {
        "abca",
        "racecar",
        "abcdef"
    };

    for(const auto &s : testCases) {
        cout << "Input: \"" << s << "\"\n";
        cout << "Output: " << (solution.validPalindrome(s) ? "true" : "false") << "\n\n";
    }

    return 0;
}