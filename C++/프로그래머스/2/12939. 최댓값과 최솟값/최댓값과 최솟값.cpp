#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmpstr = "";
    vector <int> nums;
    int tmpint = 0;
    
    //cout<<s.size()<<endl;
    
    for(int i=0; i<s.size(); i++)
    {
       // cout<<i<<endl;
        if(s[i]==' ')
        {
            //공백일 경우
            tmpint = stoi(tmpstr);
            nums.push_back(tmpint);
            tmpstr = ""; //tempstr 초기화
          //  cout<<"공백"<<endl;
            
        }
        tmpstr+=s[i];
    }
    
    tmpint = stoi(tmpstr);
    nums.push_back(tmpint); // 마지막 숫자 넣어주기
    

    
    sort(nums.begin(), nums.end());
    
   /*  for(int i=0; i<nums.size(); i++)
    {
        cout<<nums[i]<<endl;
    }*/
    
    answer+=to_string(nums[0]);
    answer+=' ';
    answer+=to_string(nums[nums.size()-1]);
    
    return answer;
}