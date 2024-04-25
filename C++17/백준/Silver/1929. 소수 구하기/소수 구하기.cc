#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int num){

    if( (num == 0) || (num == 1) ){
        return false;
    }
    
    for(int i=2; i<=sqrt(num); i++){
            if( (num%i) == 0 ){
                return false;
            }
    }
    
    return true;
}

int main(){

    int m = 0;
    int n = 0;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;

    for(int i=m; i<=n; i++){
        if(isPrime(i)){
            cout << i << "\n";
        }
    }

    return 0;
}