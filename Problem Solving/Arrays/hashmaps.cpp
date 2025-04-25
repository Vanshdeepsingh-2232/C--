#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;



int main(){
    map<int, int> myMap;

    // Adding elements with initial value 0
    myMap[1] = 0;
    myMap[2] = 0;
    myMap[3] = 0;

    // Accessing elements
    cout << "Initial values in the map:" << std::endl;
    for (const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
