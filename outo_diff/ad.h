#ifndef _ad_h_
#define _ad_h_

class adouble
{
public:
    double value;
    double ad_value;
public:
    //addition
    const adouble operator + (const double v) const;
    const adouble operator + (const adouble& a) const;
    friend const adouble operator + (const double v, const adouble& a);
    //substraction
    const adouble operator - (const double v) const;
    const adouble operator - (const adouble& a) const;
    friend const adouble operator - (const double v, const adouble& a);
    //multiplication
    const adouble operator * (const double v) const;
    const adouble operator * (const adouble& a) const;
    friend const adouble operator * (const double v, const adouble& a);
    //division
    const adouble operator / (const double v) const;
    const adouble operator / (const adouble& a) const;
    friend const adouble operator / (const double v, const adouble& a);
    //functions
    friend const adouble sin(const adouble& a);
    //assignment
    void operator = (const adouble& a);
    //constructor
    adouble(const double v, const double adv):value(v),ad_value(adv){};
    adouble(){};
};
#endif