#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

//나이, 이름 
//나이 오름차순 정렬
bool cmp(pair<int, string> A, pair<int, string> B){
    
    if(A.first == B.first){
        return false;
    }
    return A.first < B.first;
    
}

int main(){
    
    int n;
    string input;
    int age;
    string name;
    vector<string> temps;
    vector<pair<int, string>> vp;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> age >> name;
       /* stringstream sstream(input);
        while(!getline(sstream, temp, ' ')){
            temps.push_back(temp);
        }*/
        vp.push_back(make_pair(age, name));
    }
    
    stable_sort(vp.begin(), vp.end(), cmp);

    for(auto v : vp){
        cout<<v.first<<" "<<v.second<<'\n';
    }

    
    
    return 0;
}