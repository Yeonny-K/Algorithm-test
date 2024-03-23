#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
    int cnt = 0;
    string input;
    string s = "";
    vector<string> temp;
    getline(cin, input);
    
    if(input[0]==' ')
    {
        input.erase(input.begin());
    }
    
    stringstream sstream(input);
    
    while(getline(sstream, s, ' '))
    {
        temp.push_back(s);
    }
    
    cnt = temp.size();
    cout<<cnt<<endl;
    return 0;
}