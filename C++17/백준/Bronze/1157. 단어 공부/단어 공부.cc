#include <iostream>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

bool cmp(const pair<char, int>&a, const pair<char, int>&b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main(){
    string input;
    getline(cin, input);
    char c;
    
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    
    map<char, int> m;
    
    for(int i=0; i<input.size(); i++)
    {
        m[input[i]]++;
    }
    
    vector<pair<char, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    if(v[0].second == v[1].second)
        cout<<"?"<<endl;
    else
        cout<<v[0].first<<endl;
    /*for(auto vv:v)
    {
            cout<<vv.first<<endl;
            break;            
    }*/
    
    
    return 0;
}