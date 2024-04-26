#include <iostream>

using namespace std;

int main(){

    long long total = 0;
    long long sum = 0;
    int nums = 0;
    int price = 0;
    int num = 0;
    
    cin >> total;
    cin >> nums;

    for(int i=0; i<nums; i++){
        cin >> price >> num;
        sum += price * num;
    }

    if(total == sum){
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}