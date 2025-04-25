#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;



class MinStack {
public:
    stack<int> stack1,stack2;
    MinStack() {}


    void push(int val) {
        if(stack2.empty()){
            stack2.push(val);
        }
        else if(val<stack2.top()){
            stack2.push(val);
        }
        else if(val>=stack2.top()){
            stack2.push(stack2.top());
        }

        stack1.push(val);

    }
    
    void pop() {
        stack1.pop();
        stack2.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return stack2.top();
    }


};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main(){
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout<<minStack->getMin(); // return -3
    minStack->pop();
    minStack->top();    // return 0
    cout<<minStack->getMin();
  return 0;
}