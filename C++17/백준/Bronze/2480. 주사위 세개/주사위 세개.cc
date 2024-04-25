#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n = 0;
    int max = 0;
    int result = 0;
    vector<int> nums;

    for(int i=0; i<3; i++){
        cin >> n;
        nums.push_back(n);
    }

    sort(nums.begin(), nums.end(), greater<int>());

    if( (nums[0]==nums[1]) && (nums[1]==nums[2]) && (nums[0] == nums[2]) ){
        result = 10000 + (nums[0] * 1000);
    } else if ( (nums[0]!=nums[1]) && (nums[1]!=nums[2]) && (nums[0] != nums[2]) ){
        result = (nums[0] * 100);
    } else {
        if(nums[0] == nums[1]){
            result = 1000 + (nums[0]*100);
        }else{
            result = 1000 + (nums[1]*100);
        }
    }


    cout << result;


    return 0;
}