#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    
    int n;
    int input;
    int num = 0;
    vector<int> nums;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> input;
        nums.push_back(input);
    }
    
    sort(nums.begin(), nums.end());
    
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<'\n';
    }
    
    return 0;
}