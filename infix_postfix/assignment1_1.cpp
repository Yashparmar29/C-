#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(') st.push(c);
        else if (c == ')') {
            if (st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

int precedence(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void solve() {
    string s = "(A+B)*(C-D";
    if (!isBalanced(s)) {
        cout << "Invalid Expression" << endl;
        return;
    }
    stack<char> st;
    string res;
    for (char c : s) {
        if (isalnum(c)) res += c;
        else if (c == '(') st.push('(');
        else if (c == ')') {
            while (st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && precedence(c) <= precedence(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    cout << "Postfix: " << res << endl;
}

int main() {
    solve();
    return 0;
}