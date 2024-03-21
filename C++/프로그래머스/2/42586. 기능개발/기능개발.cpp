#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    int temp = 0;
    int cnt = 1;
   // bool Flag = false;
    int max = 0;
    
    for(int i=0; i<progresses.size(); i++)
    {
        temp = ((99-progresses[i]) / speeds[i]) + 1;
        days.push_back(temp);
    }
    
    max = days[0];
    answer.push_back(1);
    
    for(int j=1; j<days.size(); j++)
    {
        if(max < days[j])
        {
            max = days[j];
            answer.push_back(1);
        }
        else
            answer.back()++;
    }
    
   /* for(int j=0; j<days.size()-1; j++)
    {
        if(Flag)
        {
            cnt = 1;
            Flag = false;
        }
        if(days[j] >= days[j+1])
            cnt++;
        else
        {
            answer.push_back(cnt);
            Flag = true;
        }
    }*/
    
    return answer;
}