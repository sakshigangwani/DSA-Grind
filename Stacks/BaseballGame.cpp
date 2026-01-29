#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top();
                st.push(top1);
                st.push(top1 + top2);
            } else if (operations[i] == "C") {
                st.pop();
            } else if (operations[i] == "D") {
                st.push(2 * st.top());
            } else {
                st.push(stoi(operations[i]));
            }
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};

int main() {
    Solution sol;

    vector<string> operations = {"5", "2", "C", "D", "+"};

    int result = sol.calPoints(operations);
    cout << "Total points: " << result << endl;

    return 0;
}

//Time Complexity: O(n), where n is the number of operations.
//Space Complexity: O(n), in the worst case, all operations are valid and stored in the stack.