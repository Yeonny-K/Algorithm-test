#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    
    string input;
    string temp;
    vector<int> tm;
    int time = 0;
    int minute = 0;
    bool flag = false;
    
    getline(cin, input);
    
    stringstream sstream(input);
    while(getline(sstream, temp, ' '))
    {
        tm.push_back(stoi(temp));
    }
    
    time = tm[0];
    minute = tm[1];
    
    if(time == 0){
        time = 24;
        flag = true;        
    }
    
    if(minute<45){
        time = time-1;
        minute = minute + 60;
        minute = minute - 45;
        cout<<time<<" "<<minute<<endl;
    } else{
        if(flag){
            cout<<"0"<<" "<<minute - 45<<endl;       
        } else{
           cout<<time<<" "<<minute - 45<<endl;         
        }

    }
    
    return 0;
}