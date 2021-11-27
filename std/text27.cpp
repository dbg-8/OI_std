#include <math.h>
#include <float.h>
#include <complex>
#include <iostream>
/******************************************************************************\
对一个复数 x 开 n 次方
\******************************************************************************/
std::complex<double>  sqrtn(const std::complex<double>&x,double n)
{
    double r = hypot(x.real(),x.imag()); //模
    if(r > 0.0)
    {
        double a = atan2(x.imag(),x.real()); //辐角
        n = 1.0 / n;
        r = pow(r,n);
        a *= n;
        return std::complex<double>(r * cos(a),r * sin(a));
    }
    return std::complex<double>();
}
/******************************************************************************\
使用费拉里法求解一元四次方程 a*x^4 + b*x^3 + c*x^2 + d*x + e = 0
\******************************************************************************/
std::complex<double> Ferrari(std::complex<double> x[4]
,std::complex<double> a
,std::complex<double> b
,std::complex<double> c
,std::complex<double> d
,std::complex<double> e)
{
    a = 1.0 / a;
    b *= a;
    c *= a;
    d *= a;
    e *= a;
    std::complex<double> P = (c * c + 12.0 * e - 3.0 * b * d) / 9.0;
    std::complex<double> Q = (27.0 * d * d + 2.0 * c * c * c + 27.0 * b * b * e - 72.0 * c * e - 9.0 * b * c * d) / 54.0;
    std::complex<double> D = sqrtn(Q * Q - P * P * P,2.0);
    std::complex<double> u = Q + D;
    std::complex<double> v = Q - D;
    if(v.real() * v.real() + v.imag() * v.imag() > u.real() * u.real() + u.imag() * u.imag())
    {
        u = sqrtn(v,3.0);
    }
    else
    {
        u = sqrtn(u,3.0);
    }
    std::complex<double> y;
    if(u.real() * u.real() + u.imag() * u.imag() > 0.0)
    {
        v = P / u;
        std::complex<double> o1(-0.5,+0.86602540378443864676372317075294);
        std::complex<double> o2(-0.5,-0.86602540378443864676372317075294);
        std::complex<double>&yMax = x[0];
        double m2 = 0.0;
        double m2Max = 0.0;
        int iMax = -1;
        for(int i = 0;i < 3;++i)
        {
            y = u + v + c / 3.0;
            u *= o1;
            v *= o2;
            a = b * b + 4.0 * (y - c);
            m2 = a.real() * a.real() + a.imag() * a.imag();
            if(0 == i || m2Max < m2)
            {
                m2Max = m2;
                yMax = y;
                iMax = i;
            }
        }
        y = yMax;
    }
    else
    {//一元三次方程，三重根
        y = c / 3.0;
    }
    std::complex<double> m = sqrtn(b * b + 4.0 * (y - c),2.0);
    if(m.real() * m.real() + m.imag() * m.imag() >= DBL_MIN)
    {
        std::complex<double> n = (b * y - 2.0 * d) / m;
        a = sqrtn((b + m) * (b + m) - 8.0 * (y + n),2.0);
        x[0] = (-(b + m) + a) / 4.0;
        x[1] = (-(b + m) - a) / 4.0;
        a = sqrtn((b - m) * (b - m) - 8.0 * (y - n),2.0);
        x[2] = (-(b - m) + a) / 4.0;
        x[3] = (-(b - m) - a) / 4.0;
    }
    else
    {
        a = sqrtn(b * b - 8.0 * y,2.0);
        x[0] =
        x[1] = (-b + a) / 4.0;
        x[2] =
        x[3] = (-b - a) / 4.0;
    }
return x[4];
}

int main()
{
  std::complex<double> x[4];
  x[4] = Ferrari(x,1, 1, 5, 5, -12); //验证费拉里法
  std::cout<<"root1: "<<x[0]<<std::endl
                     <<"root2: "<<x[1]<<std::endl
                     <<"root3: "<<x[2]<<std::endl
                     <<"root4: "<<x[3]<<std::endl;
  return true;
}
