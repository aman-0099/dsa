//https://leetcode.com/problems/sqrtx/
#include<iostream>
#include<vector>
using namespace std;
int mySqrt(int num){
    int start = 0;
    int end = num;
    int ans;

    while(start<=end){
        long mid = start + (end-start)/2;

        if(mid*mid == num){
            return mid;
        }
        else if(mid*mid> num){
            end = mid-1;
        }
        else{
            ans = mid;
            start = mid+1;
        }
    }
    return ans;
}
int main(){
    int num;
    cout << "Enter Number " ;
    cin >> num;

    double finalAns = mySqrt(num);

    int precision;
    double initial = 0.1;
    cout << "Enter Number of Floating Values in Precision ";
    cin >> precision;

    for(int i = 0; i<precision; i++){
        for(double j = finalAns; j*j <= num; j = j + initial){
            finalAns = j;
        }
        initial=initial/10;
    }

    cout << finalAns;
}


//Time Complexity - O(log n + precision * sqrt(num))
//Space Complexity - O(1)