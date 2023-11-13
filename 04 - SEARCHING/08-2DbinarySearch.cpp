//https://leetcode.com/problems/search-a-2d-matrix
#include<iostream>
#include<vector>
using namespace std;
vector<int> binarySearch(vector<vector<int> > nums, int target){
    int start = 0;
    int m = nums.size(); //no.of rows
    int n = nums[0].size(); //no.of cols
    int end = m*n-1;
    vector<int> ans;

    while(start<=end){
        int mid = start + (end-start)/2;
        int rowIndex = mid/n;
        int colIndex = mid%n;
        int element = nums[rowIndex][colIndex];

        if(element == target){
            ans.push_back(rowIndex);
            ans.push_back(colIndex);
            break;
        }
        else if(element > target){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}
int main(){
    vector<vector<int> > nums = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int target = 7;
    vector<int> result =  binarySearch(nums,target);

    if(result.size()<1){
        cout << "Element Not Found";
    }
    else{
        cout << target << " found at index " << result[0] << " " << result[1];
    }
}


//Time Complexity - O(log m*n)
//Space Complexity - O(1)