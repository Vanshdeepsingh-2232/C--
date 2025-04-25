#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0;

        //finding the row to perform the search

        int i=0,j=matrix.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(matrix[mid][0]<=target && matrix[mid][matrix[0].size()-1] <=target) row=mid;
            else if(matrix[mid][0]<target) i=mid+1;
            else if(matrix[mid][0]>target) j=mid-1;

        }
        //now searching for target in that row
        int l=0,h=matrix[row].size();
        while (l<=h)
        {
            int mid=l+(h-l)/2;
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]<target) l=mid+1;
            else if(matrix[row][mid]>target) h=mid-1;
        }
        return false;
        
    }
};




int main(){
    Solution s1;
    //[[1,3,5,7],[10,11,16,20],[23,30,34,60]]
    vector<vector<int>> matrix={{1,3,5,7},
                                {10,11,16,20},
                                {23,30,34,60}
                                };
    int target=13;
    cout<<"Matrix size="<<matrix.size()<<endl;
    
    cout<<s1.searchMatrix(matrix,target);
  return 0;
}