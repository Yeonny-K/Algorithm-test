#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string input1;
    string input2;
    string temp = "";
    vector<int> nums;
    unsigned long long sum = 0;
    
    getline(cin, input1);
    getline(cin, input2);
 
        for(int i=0; i<input2.length(); i++)
        {
            temp += input2[i];
            nums.push_back(stoi(temp));
            temp = "";
        }
    
    
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
    }
    
    cout<<sum<<endl;
    
    return 0;
}