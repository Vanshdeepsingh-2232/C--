#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValidparenthesis(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '[' || c == '{' || c == '(') {
            st.push(c);
        } else {
            if (st.empty() || (c == ']' && st.top() != '[') || (c == '}' && st.top() != '{') || (c == ')' && st.top() != '(')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main(){
    string s="({({({}})})";
    cout<<isValidparenthesis(s);
    return 0;
}