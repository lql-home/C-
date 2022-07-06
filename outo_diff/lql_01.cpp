#include <iostream>
#include <math.h>

using namespace std;

int main1(){
    double x = 2.5;
    double y;
    y = 5/x + 2*x + x*x + sin(x);
    cout << "y = " << y << endl;
    return 0;
}