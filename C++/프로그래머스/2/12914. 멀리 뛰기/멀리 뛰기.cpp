#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<unsigned long long> numbers;
    
    numbers.push_back(1);
    numbers.push_back(2);
    for(int i=2; i<n; i++)
    {
        numbers.push_back((numbers[i-2]%1234567) + (numbers[i-1]%1234567));
  //      cout<<numbers[i]<<endl;
 
    }

        answer = numbers[n-1] % 1234567;
    
    return answer;
}