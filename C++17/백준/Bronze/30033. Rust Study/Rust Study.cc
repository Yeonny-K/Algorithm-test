#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){


    int cnt = 0;
    string planDay;
    string plan;
    string study;
    string temp;
    vector<int> planPage;
    vector<int> studyPage;

    getline(cin, planDay);
    getline(cin, plan);
    getline(cin, study);

    stringstream sstream(plan);
    while(getline(sstream, temp, ' ')){
        planPage.push_back((stoi(temp)));
    }

    temp = "";

    stringstream sstream2(study);
    while(getline(sstream2, temp, ' ')){
        studyPage.push_back((stoi(temp)));
    }

    for(int i=0; i<stoi(planDay); i++){
        if(planPage[i] <= studyPage[i]){
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}