#include<bits/stdc++.h>
#define E 0.0001
using namespace std;

class Bisection
{
    public:

    double f(double x)
    {
        return (x*x*x)-x-1;
    }

    double findRoot(double a, double b)
    {
        if(f(a)*f(b)>=0)
        {
            cout<<"Your bad! this seems to be wrong a & b :D"<<endl;
            return 0;
        }

        double c =a;

        while ((b-a) >= E)
        {

            c = (a+b)*0.5;

            if (f(c) == 0.0)
                break;

            else if (f(c)*f(a) < 0)
                b = c;
            else
                a = c;
        }
        cout << "The value of root is : " << c<<endl;
    }

};

int main()
{
 double a,b,Iteration;
 Bisection bisection;
 srand(time(NULL));
 a = ((rand()%(-10-20+1))-10); // range [-10,20]
 b = (rand()%(0-10+1))+0;  //range [0,10]

 Iteration = log(abs(b-a)/E)/log(2);

 cout<<"value of a is : "<<a<<endl;
 cout<<"value of b is : "<<b<<endl;
 cout<<"Number of Iteration is : "<<Iteration<<endl;

 bisection.findRoot(a,b);
 return 0;
}
