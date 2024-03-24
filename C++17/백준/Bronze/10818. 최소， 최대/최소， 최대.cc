#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main(){
    
    string t;
    string s;
    string temp;
    vector<int> nums;
    
    
    getline(cin, t);
    getline(cin, s);
    
    stringstream sstream(s);
    while(getline(sstream, temp, ' ')){
        nums.push_back(stoi(temp));
    }
    
    sort(nums.begin(), nums.end());
    
    cout<<nums[0]<<" "<<nums[nums.size()-1]<<endl;
    
    return 0;
}