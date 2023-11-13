#include<iostream>
#include<vector>
using namespace std;
int lastOccurrence(vector<int> nums, int target){
    int start = 0;
    int end = nums.size()-1;
    int mid = start + (end-start)/2;
    int ans = -1;

    while(start<=end){
        if(nums[mid]==target){
            ans = mid;
            start=mid+1;
        }
        else if(nums[mid]>target){
            end = mid-1;
        }
        else{
            start=mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}
int main(){
    vector<int> nums = {1,2,2,2,3,4,8};
    int result = lastOccurrence(nums,2);
    cout << result;
}

//Time Complexity - O(log n)
//Space Complexity - O(1)