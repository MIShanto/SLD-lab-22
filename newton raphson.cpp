#include<bits/stdc++.h>
#define E 0.001
using namespace std;

class newtonRapson
{
    public:
        double f(double x)
        {
            return (x*x*x)-x-1;
        }

        double derived_f(double x)
        {
            return 3*x*x-1;
        }

        void calculate(double x)
        {
            double h = f(x)/derived_f(x);
            while(abs(h)>=E)
            {
                h = f(x)/derived_f(x);
                x-=h;
            }
            cout<<"The root is: "<<x<<endl;
        }

};


int main()
{
    double x;
    newtonRapson nR;

    srand(time(NULL));
    x = ((rand()%(-20-20+1))-20); // range [-20,20]
    cout<<"For x = "<<x<<endl;
    nR.calculate(x);
    return 0;
}
