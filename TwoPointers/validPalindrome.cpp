#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Convert uppercase letters to lowercase
    char isLowerCase(char ch){
        if(ch >= 'A' && ch <= 'Z'){
            return ch + 32;
        }
        return ch;
    }

    // Check if the character is alphanumeric
    bool isAlphaNum(char ch){
        if((ch >= '0' && ch <= '9') || 
           (ch >= 'a' && ch <= 'z') || 
           (ch >= 'A' && ch <= 'Z')){
            return true;
        }
        return false;
    }

    // Check if the string is a palindrome
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while(start <= end) {
            // Skip non-alphanumeric characters
            if(!isAlphaNum(s[start])){
                start++;
                continue;
            }

            if(!isAlphaNum(s[end])){
                end--;
                continue;
            }

            // Compare characters ignoring case
            if(isLowerCase(s[start]) == isLowerCase(s[end])){
                start++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    string testCases[] = {
        "A man, a plan, a canal: Panama",
        "race a car",
        " "
    };

    for(const auto &s : testCases) {
        cout << "Input: \"" << s << "\"\n";
        cout << "Output: " << (solution.isPalindrome(s) ? "true" : "false") << "\n\n";
    }

    return 0;
}
