#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    int cnt = 0;
    int max = 0;
    string day;
    string solvedInput;
    string temp;
    vector<int> solved;

    getline(cin, day);
    getline(cin, solvedInput);

    stringstream sstream(solvedInput);
    while(getline(sstream, temp, ' ')){
        solved.push_back(stoi(temp));
    }

    for(int i=0; i<solved.size(); i++){
        if(solved[i] != 0){
            cnt++;
        } else {
            if(cnt > max){
                max = cnt;
            }
            cnt = 0;
        }
        
    }

    if(cnt > max){
        max = cnt;
    }

    cout << max;

    return 0;
}