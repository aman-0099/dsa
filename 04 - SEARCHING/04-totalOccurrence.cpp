#include<iostream>
#include<vector>
using namespace std;
int totalOccurrence(vector<int> nums, int target){
    int start = 0;
    int end = nums.size()-1;
    int mid = start + (end-start)/2;
    int first = -1;
    int last = -1;

    //first occurrence
    while(start<=end){
        if(nums[mid]==target){
            first = mid;
            end = mid-1;
        }
        else if(nums[mid]>target){
            end = mid-1;
        }
        else{
            start=mid+1;
        }
        mid = start + (end-start)/2;
    }

    //last occurrence
    start = 0;
    end = nums.size()-1;
    mid = start + (end-start)/2;
    while(start<=end){
        if(nums[mid]==target){
            last = mid;
            start = mid+1;
        }
        else if(nums[mid]>target){
            end = mid-1;
        }
        else{
            start=mid+1;
        }
        mid = start + (end-start)/2;
    }

    int total = first==-1? -1 : last-first+1;
    return total;
}
int main(){
    vector<int> nums = {1,2,2,2,3,4,4,4,4,4,4,4,4,4,8};
    int result = totalOccurrence(nums,4);
    cout << result;
}

//Time Complexity - O(log n)
//Space Complexity - O(1)