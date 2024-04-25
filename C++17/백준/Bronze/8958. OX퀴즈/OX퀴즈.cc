#include <iostream>
#include <vector>

using namespace std;

int sumFunction(int n){

    int sum = 0;
    
    for(int i=0; i<=n; i++){
        sum += i;
    }

    return sum;
}


int main(){

    int num = 0;
    int cnt = 0;
    int sum = 0;
    bool flag = true;
    string temp;
    vector<string> quiz;
    vector<int> score;

    cin >> num;

    for(int i=0; i<num; i++){
        cin >> temp;
        quiz.push_back(temp);
    }

    for(int i=0; i<quiz.size(); i++){
        for(int j=0; j<quiz[i].length(); j++){
            if(quiz[i][j] == 'O'){
                cnt++;
            } else if(quiz[i][j] == 'X'){
                sum += sumFunction(cnt);
                cnt = 0;
            }
        }
        if(cnt > 0){
            sum += sumFunction(cnt);
        }
        score.push_back(sum);
        sum = 0;
        cnt = 0;
    }

    for(int i=0; i<score.size(); i++){
        cout << score[i] << endl;
    }


    return 0;
}