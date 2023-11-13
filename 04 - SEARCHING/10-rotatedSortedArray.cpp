//https://leetcode.com/problems/search-in-rotated-sorted-array
#include<iostream>
#include<vector>
using namespace std;
int findPivot(vector<int> nums){
    int start = 0;
    int end = nums.size()-1;
    int mid = start + (end-start)/2;

    while(start<=end){
        if(start == end){
            return start;
        }
        else if(mid<end && nums[mid]>nums[mid+1]){
            return mid;
        }
        else if(mid>start && nums[mid]<nums[mid-1]){
            return mid-1;
        }
        else if(nums[mid]<nums[start]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int binarySearch(vector<int> nums, int start, int end, int target){
    int mid = start +(end-start)/2;

     while(start<=end){
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
     }
     return -1;
}

int searchElement(vector<int> nums, int target){
    int start = 0;
    int end = nums.size()-1;
    int result = -1;
    int pivotIndex = findPivot(nums);

    if(target>=nums[start] && target <= nums[pivotIndex]){
        result = binarySearch(nums,start,pivotIndex,target);
    }
    else{
        result = binarySearch(nums,pivotIndex+1,end,target);
    }
    return result;
}

int main(){
    vector<int> nums = {9,10,2,4,6,8};
    int target = 8;

    int ans = searchElement(nums,target);
    cout << target << " found at index " << ans;

}

//Time Complexity - O(log n)
//Space Complexity - O(1)