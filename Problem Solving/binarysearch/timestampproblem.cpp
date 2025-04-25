#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<map>
using namespace std;
// Example 1:

// Input

// ["TimeMap", "set", "get", "get", "set", "get", "get"]
// [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]

// Output

// [null, null, "bar", "bar", null, "bar2", "bar2"]

// Explanation

// TimeMap timeMap = new TimeMap();
// timeMap->set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1->
// timeMap->get("foo", 1);         // return "bar"
// timeMap->get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar"->
// timeMap->set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4->
// timeMap->get("foo", 4);         // return "bar2"
// timeMap->get("foo", 5);         // return "bar2"


class TimeMap {
    unordered_map<string,map<int,string>>timemap;
    int min_key=0;
    int time_prev=0;
    bool b=false;

public:

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
       timemap[key][timestamp]=value;
       time_prev=timestamp;
       if(!b){
        min_key=timestamp;
        b=true;
       }
    }


    string get(string key, int timestamp) {
      int start=min_key;
      int end=timestamp;
      if(timestamp<min_key) return "";

      if(""==timemap[key][timestamp] && timestamp>time_prev) return timemap[key][time_prev];

      if(""==timemap[key][timestamp] && timestamp<time_prev){
        int iter=0;
        while(start<=end){
            
            int mid = (start+end)/2;
            if(mid==timestamp) return timemap[key][timestamp];
            else if(mid > timestamp) end=mid-1;
            else if(mid < timestamp) start=mid+1;
            iter=mid;
        }
        return timemap[key][iter];
      }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */




int main(){
    TimeMap* obj=new TimeMap;
    // string key="foo";
    // string value="bar";
    // int timestamp=1;
obj->set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1->
obj->get("foo", 1);         // return "bar"
obj->get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar"->
obj->set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4->
obj->get("foo", 4);         // return "bar2"
obj->get("foo", 5);

  return 0;
}