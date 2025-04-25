



//  _   _                  _                            _                                          __   __ 
// | | | |                | |                          | |                                        / _| / _|
// | |_| |  __ _  _ __  __| |    __      __ ___   _ __ | | __   _ __    __ _  _   _  ___    ___  | |_ | |_ 
// |  _  | / _` || '__|/ _` |    \ \ /\ / // _ \ | '__|| |/ /  | '_ \  / _` || | | |/ __|  / _ \ |  _||  _|
// | | | || (_| || |  | (_| |     \ V  V /| (_) || |   |   <   | |_) || (_| || |_| |\__ \ | (_) || |  | |  
// \_| |_/ \__,_||_|   \__,_|      \_/\_/  \___/ |_|   |_|\_\  | .__/  \__,_| \__, ||___/  \___/ |_|  |_|  
//                                                             | |             __/ |                     
//                                                             |_|             \___|

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;

string repeatCharacters(const int &times_repeat,string &s){
    string an;
    for(int i=0;i<times_repeat;i++){
        an.append(s);
    }
    return an;
}

string stringDecoder(string &s){
    stack<int> number_stack;
    stack<char> character_stack;
    string answer="";

    
    for(int i=0;i<s.length();i++){
        
        string str="";
        
        if(isdigit(s[i])){
            number_stack.push((int)s[i]-'0');
        }
        
        
        else if(s[i]==']'){
            char c;
            while(!character_stack.empty() && character_stack.top()!='['){
                
                if(character_stack.top()!=']' && character_stack.top()!='['){
                    c=character_stack.top();
                    str.insert(0,1,c);
                }
                if(!character_stack.empty()) character_stack.pop();
                //cout<<str;
            }

            int n=number_stack.top();
            if(!number_stack.empty()) number_stack.pop();

            string an=repeatCharacters(n,str);
            answer+=an;

        }
        else {
            character_stack.push(s[i]);
        }
    }
    
    return answer;
}



int main(){
    // 
    string as="3[a]2[bc]";
    cout<<stringDecoder(as);
  


    
  return 0;
}