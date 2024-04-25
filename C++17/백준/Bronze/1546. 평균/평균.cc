#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int num = 0;
    double max = 0;
    double score = 0.0;
    double cheat = 0.0;
    double sum = 0.0;
    double avg = 0.0;

    cin >> num;

    double scores[num];
    
    for(int i=0; i<num; i++){
        cin >> score;
        scores[i] = score;
    }

    max = scores[0];

    for(int i=0; i<num; i++){
        if(scores[i] > max){
            max = scores[i];
        }
    }

    for(int i=0; i<num; i++){
        cheat = (scores[i] / max) * 100 ;   
        sum += cheat;     
    }

    avg = double(sum) / double(num);
    cout.setf(ios::fixed);
    cout.precision(4);
    cout << avg;
    

    return 0;
}