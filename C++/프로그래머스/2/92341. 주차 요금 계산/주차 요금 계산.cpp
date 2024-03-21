#include<bits/stdc++.h>

using namespace std;

struct Car
{
    string carNum;
    vector<string> inTime;
    vector<string> inMin;
    vector<string> outTime;
    vector<string> outMin;
    int times = 0;
    int fee = 0;
};

Car ArrCar[1001];

bool cmp(Car a, Car b)
{
    if(a.carNum < b.carNum)
        return true;
    return false;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int carCnt = 0;
    
    for(int i=0; i<records.size(); i++)
    {
        string temp = records[i].substr(6,4); //차번호 자르기
       // cout<<temp<<endl;
        bool flag = false; // 새로운 차번호라는 뜻
        for(int j=0; j<carCnt; j++)
        {
            if(ArrCar[j].carNum == temp) //이미 있는 차라면
            {
                flag = true; // 이미 있는 차라는 뜻
                if(find(records[i].begin(), records[i].end(), 'I')!=records[i].end()) // 입차 기록이면
                {
                    string temp2 = records[i].substr(0,2); //시간
                    ArrCar[j].inTime.push_back(temp2);
                    string temp3 = records[i].substr(3,2); //분
        //            cout<<temp3<<endl;
                    ArrCar[j].inMin.push_back(temp3);
                }
                else // 출차 기록이면
                {
                    string temp2 = records[i].substr(0,2); //시간
                    ArrCar[j].outTime.push_back(temp2);
                    string temp3 = records[i].substr(3,2); //분
           //         cout<<temp3<<endl;
                    ArrCar[j].outMin.push_back(temp3);
                }
                
                break;
            }
        
        }
        if(flag == false)
        {
            ArrCar[carCnt].carNum = temp;
            if(find(records[i].begin(), records[i].end(), 'I')!=records[i].end()) // 입차 기록이면
                {
                    string temp2 = records[i].substr(0,2); //시간
                    ArrCar[carCnt].inTime.push_back(temp2);
                    string temp3 = records[i].substr(3,2); //분
          //      cout<<temp3<<endl;
                    ArrCar[carCnt].inMin.push_back(temp3);
                }
                else // 출차 기록이면
                {
                    string temp2 = records[i].substr(0,2); //시간
                    ArrCar[carCnt].outTime.push_back(temp2);
                    string temp3 = records[i].substr(3,2); //분
           //         cout<<temp3<<endl;
                    ArrCar[carCnt].outMin.push_back(temp3);
                }
            carCnt++;
        }
    }
    
    sort(ArrCar, ArrCar+carCnt, cmp);

    for(int i=0; i<carCnt; i++)
    {
        if(ArrCar[i].inTime.size() == ArrCar[i].outTime.size()) //입/출차 짝이 맞는 경우
        {
            for(int j=0; j<ArrCar[i].inTime.size(); j++)
            {
                int t = stoi(ArrCar[i].outTime[j]) - stoi(ArrCar[i].inTime[j]);
                int m = stoi(ArrCar[i].outMin[j]) - stoi(ArrCar[i].inMin[j]);
                int ts = 60*t + m;
                ArrCar[i].times += ts;
            }
      //      cout<<"시간확인1  "<<ArrCar[i].carNum<<"/"<<ArrCar[i].times<<endl;
            if(ArrCar[i].times<=fees[0]) //기본요금에 해당하는 시간이라면
                ArrCar[i].fee = fees[1];
            else
            {
                if(((ArrCar[i].times-fees[0])%fees[2])!=0)
                    ArrCar[i].fee = fees[1] + (((ArrCar[i].times-fees[0])/fees[2])+1)*fees[3];
                else
                    ArrCar[i].fee = fees[1] + ((ArrCar[i].times-fees[0])/fees[2])*fees[3];
            }
        }
        else //입차한 기록만 있는 경우
        {
            ArrCar[i].outTime.push_back("23");
            ArrCar[i].outMin.push_back("59");
            for(int j=0; j<ArrCar[i].inTime.size(); j++)
            {
                int t = stoi(ArrCar[i].outTime[j]) - stoi(ArrCar[i].inTime[j]);
                int m = stoi(ArrCar[i].outMin[j]) - stoi(ArrCar[i].inMin[j]);
                int ts = 60*t + m;
                ArrCar[i].times += ts;
            }
    //        cout<<"시간확인2  "<<ArrCar[i].carNum<<"/"<<ArrCar[i].times<<endl;
            if(ArrCar[i].times<=fees[0]) //기본요금에 해당하는 시간이라면
                ArrCar[i].fee = fees[1];
            else
            {
                if(((ArrCar[i].times-fees[0])%fees[2])!=0)
                    ArrCar[i].fee = fees[1] + (((ArrCar[i].times-fees[0])/fees[2])+1)*fees[3];
                else
                    ArrCar[i].fee = fees[1] + ((ArrCar[i].times-fees[0])/fees[2])*fees[3];
            }
        }
        
   //     cout<<ArrCar[i].carNum<<"/"<<ArrCar[i].fee<<endl;
        answer.push_back(ArrCar[i].fee);
    }
    
   
    return answer;
}