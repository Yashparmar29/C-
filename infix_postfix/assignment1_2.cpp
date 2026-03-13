#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string exp = "12 3 4 * + 6 -";
    stringstream ss(exp);
    string token;
    stack<int> st;

    while (ss >> token) {
        if (isdigit(token[0])) {
            st.push(stoi(token));
        } else {
            int v2 = st.top(); st.pop();
            int v1 = st.top(); st.pop();
            if (token == "+") st.push(v1 + v2);
            else if (token == "-") st.push(v1 - v2);
            else if (token == "*") st.push(v1 * v2);
            else if (token == "/") st.push(v1 / v2);
        }
    }
    cout << "Final Result: " << st.top() << endl;
    return 0;
}