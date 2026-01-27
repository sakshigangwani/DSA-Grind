#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};

int main() {
    Solution sol;

    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    sol.reverseString(s);

    for (char c : s) {
        cout << c << " ";
    }

    cout << endl;
    return 0;
}
