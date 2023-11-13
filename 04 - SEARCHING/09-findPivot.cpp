#include<iostream>
#include<vector>
using namespace std;
int findPivot(vector<int> nums){
    int start = 0;
    int end = nums.size()-1;
    int mid = start + (end-start)/2;

    while(start<=end){
        if(start==end){
            return start;
        }
        else if(mid < end && nums[mid]>nums[mid+1]){
            return mid;
        }
        else if(mid > start && nums[mid]<nums[mid-1]){
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
int main(){
    vector<int> nums = {9,10,2,4,6,8};
    int ans =  findPivot(nums);
    cout << "Pivot is " << nums[ans] << " at index " << ans;

}

//Time Complexity - O(log n)
//Space Complexity - O(1)