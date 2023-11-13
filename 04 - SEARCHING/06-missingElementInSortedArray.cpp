//leetcode premium question https://leetcode.com/problems/missing-element-in-sorted-array
#include<iostream>
#include<vector>
using namespace std;
int missingElement(vector<int> nums){
    int start = 0;
    int end = nums.size()-1;
    int mid= start + (end-start)/2;
    int ans = -1;

    while(start<=end){
        if((nums[mid]-mid) == 1){
            start = mid+1;
        }
        else{
            ans = mid+1;
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans ;
}
int main(){
    vector<int> nums = {1,2,3,5,6,7,8};
    cout << missingElement(nums);

}

//Time Complexity - O(log n)
//Space Complexity - O(1)