#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int size = arr1.size();
    int size2 = arr1[0].size();
    int size3 = arr2[0].size();
    int sum = 0;
    vector<int> temp;
    
  //  cout<<size<<endl;
    
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size3; j++)
        {
            for(int cnt=0; cnt<size2; cnt++)
            { 
                sum += arr1[i][cnt]*arr2[cnt][j];
               // cout<<i<<"아이"<<j<<"제이"<<cnt<<"cnt"<<endl;
            }
            temp.push_back(sum);
          //  cout<<sum<<endl;
              sum = 0;
        }
        answer.push_back(temp);
        temp.clear();

    }
    return answer;
}