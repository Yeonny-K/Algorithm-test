#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    
    int input = 0;
    int target = 0;
    int Idx = 0;
    vector<int> nums;
    vector<int> nums_sorted;
    
    for(int i=0; i<9; i++)
    {
        cin >> input;
        nums.push_back(input);
    }
    
    nums_sorted = nums;
    sort(nums_sorted.begin(), nums_sorted.end(), greater<int>());
    target = nums_sorted[0];
    Idx = find(nums.begin(), nums.end(), target) - nums.begin() +1;
    cout<<target<<endl;
    cout<<Idx<< endl;
    
    return 0;
}