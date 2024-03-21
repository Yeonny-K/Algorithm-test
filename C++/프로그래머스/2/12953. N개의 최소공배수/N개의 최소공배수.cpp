#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b)
{
    if(b == 0)
        return a;
    else
        return GCD(b, a%b);
}

int solution(vector<int> arr) {
    int answer = 1;
    int gcd = 0;
    int lcm = 0;
    sort(arr.begin(), arr.end());
    
    //최소공배수 = 두 수의 곱 / 최대공약수
    
    for(int i=1; i<arr.size(); i++)
    {
        gcd = GCD(arr[i], arr[i-1]);
        lcm = (arr[i]*arr[i-1]) / gcd;
        arr[i] = lcm;
    }
    
    return lcm;
}