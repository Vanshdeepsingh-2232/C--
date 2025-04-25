#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    string reversePrefix(string word, char &ch) {
         string answer=word;
         int index=0;
      bool found=false;
        for (int i = 0; i < word.size(); i++)
        {
            if(word[i]==ch){
                found=true;
                index=i;
                break;
            }
        }
        
        if(found){
            for(int i=0,j=index ; i<j ; i++,j--){
                swap(answer[i],answer[j]);
            }
            return answer;
            
        }
        return word;
    }
};

int main(){
    Solution s1;
    string word="abcdefd";
    char ch='z';
    cout<<s1.reversePrefix(word,ch);

  return 0;
}