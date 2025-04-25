#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> valid;

    void generate(string &s,int open,int close){
      
      if(open==0 && close==0){
        valid.push_back(s);
        return;
      }

      if(open>0){
        s.push_back('(');
        generate(s,open-1,close);
        s.pop_back();
      }

      if(close>0){
        if(open<close){
          s.push_back(')');
          generate(s,open,close-1);
          s.pop_back();
        }
      }

    }

    vector<string> generateParenthesis(int n) {
      string s;
      generate(s,n,n);
      return valid;
    }
};

int main(){
    Solution s1;
    int input=2;
    vector<string> output = s1.generateParenthesis(input) ;
    for (int i = 0; i < output.size(); i++)
    {
      cout<<output[i]<<",";
    }
    

  return 0;
}

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["    ((())) ",
            //  "(()())",
            //  "(())()",
            //  "()(())",
            //  "()()()"]


// Example 2:

// Input: n = 1
// Output: ["()"]


