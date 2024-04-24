#include <iostream>

using namespace std;

int main(){

    int width = 0;
    int height = 0;

    cin >> width >> height;

    cout << fixed;
    cout.precision(1);

    cout << width * height * 0.5;

    return 0;
}