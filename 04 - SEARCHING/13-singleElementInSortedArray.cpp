//https://leetcode.com/problems/single-element-in-a-sorted-array
#include<iostream>
#include<vector>
using namespace std;
int searchSingleElement(vector<int> nums){
        int start=0;
        int end=nums.size()-1;

        while(start<=end){
            int mid = start+(end-start)/2;
            if(start==end){
                return start;
            }
            else if(mid&1){
                if(nums[mid]==nums[mid-1]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            else{
                if(nums[mid]==nums[mid+1]){
                    start = mid+2;
                }
                else{
                    end=mid;
                }
            }
        }
        return -1;
}
int main(){
    vector<int> nums = {1,1,4,2,2,5,5,8,8,5,9,9,2};
    int ans = searchSingleElement(nums);
    
    if(ans>=0){
    cout << "Single element is " << nums[ans] << " at index " << ans;
    }
    else{
        cout << "No single element is found in array";
    }
}
