#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if(st.empty()) return false;

                if((s[i] == ')' && st.top() == '(') ||
                   (s[i] == ']' && st.top() == '[') ||
                   (s[i] == '}' && st.top() == '{')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;

    string test1 = "()[]{}";
    string test2 = "([)]";
    string test3 = "{[]}";

    cout << boolalpha; // print true/false instead of 1/0
    cout << "Test 1: " << sol.isValid(test1) << endl; // true
    cout << "Test 2: " << sol.isValid(test2) << endl; // false
    cout << "Test 3: " << sol.isValid(test3) << endl; // true

    return 0;
}