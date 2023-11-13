//code is not correct for all cases
#include<iostream> 
#include<vector>
using namespace std;
double divide(int dividend,int divisor, int precision){

    int start = 0;
    int end = abs(dividend);
    double ans = 0.0;
    
    while(start<=end){
    int mid = start+(end-start)/2;
        if(abs(divisor) * mid == abs(dividend)){
            ans = mid;
            break;
        }
        if(abs(divisor) * mid < abs(dividend)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    //calculating decimal values
    double initial = 0.1;
    for(int i=0; i<precision; i++){
        for(double j = ans; j*divisor <= dividend; j=j+initial){
            ans = j;
        }
        initial = initial/10;
    }
    //returning ans
    if((dividend < 0 && divisor < 0) || (dividend >=0 && divisor>=0)){
        return ans;
    }
    else{
        return -ans;
    }
}
int main(){
    int dividend;
    cout << "Enter dividend ";
    cin >> dividend;

    int divisor;
    cout << "Enter divisor ";
    cin >> divisor;

    int precision;
    cout << "Number of floating values in precision ";
    cin >> precision;

    if(divisor==0){
        cout << "Division Not Possible";
    }
    
    cout << divide(dividend,divisor,precision);

}
