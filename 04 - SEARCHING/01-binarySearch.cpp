#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int> nums, int target){
    int start = 0;
    int end = nums.size()-1;
    int mid = start + (end-start)/2;

    while(start<=end){
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            end = mid-1;
        }
        else{
            start=mid+1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}
int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8};
    int target = -1;
    int result = binarySearch(nums,target);

    if(result>=0){
        cout << "Element found at index " << result;
    }
    else{
        cout << "Element not found";
    }
}

//Time Complexity - O(log n)
//Space Complexity - O(1)