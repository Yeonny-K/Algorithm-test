#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    
    string input1;
    string input2;
    int target = 0;
    int num = 0;
    long long sum = 0;
    vector<int> nums; 
    
    int ten_arr[3] = {1, 10, 100};
    
    getline(cin, input1);
    getline(cin, input2);
    
    target = stoi(input1);
    
    for(int i=2; i>=0; i--){
        string temp = "";
        temp += input2[i];
        num = stoi(temp) * target;
        cout<<num<<endl;
        nums.push_back(num);
    }
    
    for(int i=0; i<3; i++){
        sum += nums[i] * ten_arr[i];
    }
    
    cout<<sum<<endl;
    
    return 0;
}