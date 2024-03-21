#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<string> makeSet(string str) 
{
    vector<string> str_set;

    for (int i = 0; i < str.length() - 1; ) {
        string temp = str.substr(i, 2);
        if (temp[0] >= 'a' && temp[0] <= 'z') {
            if (temp[1] >= 'a' && temp[1] <= 'z') {
                str_set.push_back(temp);
                i++;
            }
            else i += 2;
        }
        else {
            if (temp[1] >= 'a' && temp[1] <= 'z') i++;
            else i += 2;
        }
    }
    return str_set;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v1;
    vector<string> v2;
//    set<string> u;
    unordered_map<string, int> count;
    string temp = "";
  //  int cnt = 0;
    int uni = 0; //합집합 수
    int intersec = 0; //교집합 수
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    v1 = makeSet(str1);
    v2 = makeSet(str2);
    
    

 /*풀었던거   for(int i=0; i<str1.size(); i++)
    {
        if(str1[i] >= 'a' && str1[i] <= 'z')
        {
                temp += str1[i];
        }
        if((temp.size() == 2))
        {
            v1.push_back(temp);
            temp.erase(temp.begin());        
        }
        if(isalpha(str1[i])!=2)
        {
            continue;
        }
    }
    
    temp.clear();
    
    for(int i=0; i<str2.size(); i++)
    {
        if(str2[i] >= 'a' && str2[i] <= 'z')
        {
                temp += str2[i];
        }
        if((temp.size() == 2))
        {
            v2.push_back(temp);
            temp.erase(temp.begin());        
        }
        if(isalpha(str2[i])!=2)
        {
            continue;
        }
    } 풀었던거*/
    
/*    for(int i=0; i<v2.size(); i++)
    {
        for(int j=0; j<v2[i].size(); j++)
            cout<<v2[i][j];
        cout<<"/"<<endl;
    }
    */
/*    temp.clear();
    cnt = 0;
    
    for(int i=0; i<str2.size(); i++)
    {
        if(str2[i] >= 'a' && str2[i] <= 'z')
        {
                temp += str2[i];
      //      cout<<"진입1"<<temp<<endl;
                cnt++;
        }
        if((cnt == 2) || (i == str2.size()-1))
        {
  //          cout<<"진입2"<<temp<<endl;
            v2.push_back(temp);
            u.insert(temp);
            temp.clear();
            cnt = 0;           
        }
        if(isalpha(str2[i])!=2)
        {
            continue;
        }
    }*/
    
 /*   for(int i=0; i<v1.size(); i++)
    {
        for(int j=0; j<v1[i].size(); j++)
            cout<<v1[i][j];
        cout<<"/"<<endl;
    }
    cout<<"v1v2"<<endl;
    
    for(int i=0; i<v2.size(); i++)
    {
        for(int j=0; j<v2[i].size(); j++)
            cout<<v2[i][j];
        cout<<"/"<<endl;
    }*/
    
 /*   cout<<u.size()<<endl;
    total = v1.size() + v2.size();
    same = total - u.size(); //교집합 사이즈
    answer = (int)((same/u.size())*65536);*/
    
    for(int i=0; i<v1.size(); i++)
    {
        count[v1[i]]++; //첫번째 문자열 집합의 원소를 모두 count 맵에 key로 추가한다. value는 횟수로 카운팅
    }
    for(int i=0; i<v2.size(); i++)
    {//두번째 문자열 집합의 원소들이 count 맵에 있는지 확인한다.
        if(count.find(v2[i]) != count.end())
        {//찾았다면(끝까지 가기 전에 멈췄다면)
            if(count[v2[i]]==0) 
                continue;
            count[v2[i]]--; //count 맵에서 value값을 하나 마이너스하고
            intersec++; //교집합 개수를 추가한다
            
            /*
            첫번째 문자열 집합이 aa, aa 이고(맵에는 aa-2로 매핑)
            두번째 문자열 집합이 aa,aa,aa,an 이라면
            두번째 문자열의 세번재 aa를 검사할 땐 맵에서 aa-0인 상태이므로, 세번째 aa는 교집합 대상이 아닌 것이다.
            */
        }
    }
    
    uni = v1.size() + v2.size() - intersec;
    
    if(uni == 0)
        answer = 65536;
    else
        answer = (int)((float)intersec/uni*65536);


    
    return answer;
}