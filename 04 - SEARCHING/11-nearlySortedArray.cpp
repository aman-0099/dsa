#include<iostream>
#include<vector>
using namespace std;
int searchtarget(vector<int> arr, int target){
    int start = 0;
    int end = arr.size() - 1;
/* In nearly sorted, we have to compare target with it's nearby element also, like (mid+1) and (mid-1) element
  as we compared with nearby element, we will increase or decrease by 2 */
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(mid < end && arr[mid+1] == target){
            return mid+1;
        }
        else if(mid > start && arr[mid-1] == target){
            return mid-1;
        }

        else if(arr[mid] > target){
            end = mid-2;
        }

        else{
            start = mid+2;
        }
    }
    return -1;
}

int main(){
    vector<int> nums{10,3,40,20,50,80,70};
    int target = 40;

    int index = searchtarget(nums,target);

    if(index < 0){
        cout << "Element Not Found";
    }
    else{
        cout <<  target <<  " Found At Index " << index;
    }

    return 0;
}

//Time Complexity - O(log n)
//Space Complexity - O(1)