//https://leetcode.com/problems/find-peak-element
//https://leetcode.com/problems/peak-index-in-a-mountain-array
#include<iostream>
#include<vector>
using namespace std;
int findPeakElement(vector<int> nums) {
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end-start)/2;

        while(start<end){ //to avoid infinite loop we removed "="
            if(nums[mid]<nums[mid+1]){
                start=mid+1;
            }
            else{
                end=mid; //if we put mid-1 becuase if we are on peak, we will lose it
            }
            mid = start + (end-start)/2;
        }
        return start; //here both start and end are at peak so we can return either of them
    }
int main(){
    vector<int> nums = {2,4,8,15};
    int ans = findPeakElement(nums);
    cout << "Peak Element is " << nums[ans] << " at index " << ans;
}

//Time Complexity - O(log n)
//Space Complexity - O(1)