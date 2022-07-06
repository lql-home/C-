#include "ad.h"
#include <iostream>
#include "math.h"
using namespace std;

// 重载运算符 “/”
const adouble operator / (const double v, const adouble& a)
{
    adouble tmp;
    tmp.value = v/a.value;
    tmp.ad_value = (-v*a.ad_value)/(a.value*a.value);
    return tmp;
}

// 重载运算符 “×”
const adouble operator * (const double v, const adouble& a)
{
    adouble tmp;
    tmp.value = v*a.value;
    tmp.ad_value = v*a.ad_value;
    return tmp;
}

const adouble adouble::operator * (const adouble& a) const
{
    adouble tmp;
    tmp.value = value * a.value;
    tmp.ad_value = ad_value*a.value + value*a.ad_value;
    return tmp; 
}

// 重载友元函数 sin(x)
const adouble sin(const adouble& a)
{
    adouble tmp;
    double tmp2;
    tmp.value = sin(a.value);
    tmp2 = cos(a.value);
    tmp.ad_value = tmp2*a.ad_value;
    return tmp;
}

//重载运算符 “+”
const adouble adouble::operator + (const adouble& a) const
{
    adouble tmp;
    tmp.value = value + a.value;
    tmp.ad_value = ad_value + a.ad_value;
    return tmp;
}

//重载运算符 “=“
void adouble::operator = (const adouble& a)
{
    value = a.value;
    ad_value = a.ad_value;
}

int main(){
    adouble x(2.5,1.0);
    adouble y;
    y = 5/x + 2*x + x*x + sin(x);
    cout << "y = " << y.value << endl;
    cout << "dy/dx = " << y.ad_value << endl;
    return 0;
}