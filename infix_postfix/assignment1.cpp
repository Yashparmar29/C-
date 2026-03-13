#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string toPostfix(string s) {
    stack<char> st;
    string res;
    for (char c : s) {
        if (isdigit(c)) res += c;
        else if (c == '(') st.push('(');
        else if (c == ')') {
            while (st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(s[res.length()]) <= prec(st.top())) { 
                if(prec(c) <= prec(st.top())) {
                    res += st.top();
                    st.pop();
                } else break;
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

int evaluate(string s) {
    stack<int> st;
    for (char c : s) {
        if (isdigit(c)) st.push(c - '0');
        else {
            int v2 = st.top(); st.pop();
            int v1 = st.top(); st.pop();
            if (c == '+') st.push(v1 + v2);
            else if (c == '-') st.push(v1 - v2);
            else if (c == '*') st.push(v1 * v2);
            else if (c == '/') st.push(v1 / v2);
        }
    }
    return st.top();
}

int main() {
    string exp = "(2+3)*(4+5)";
    string post = toPostfix(exp);
    cout << "Postfix: " << post << endl;
    cout << "Result: " << evaluate(post) << endl;
    return 0;
}