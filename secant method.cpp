#include<bits/stdc++.h>
#define E 0.001
using namespace std;

class secantMethod
{
    public:
        double f(double x)
        {
            return (x*x*x)-x-1;
        }

        void calculate(double x1,double x2)
        {
            if(f(x1)*f(x2)>0)
            {
                cout<<"root not available in this interval"<<endl;
                return ;
            }

            int cnt=0;
            double h = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
            while(abs(x1-x2)>=E)
            {
                double c = f(x1)*f(h);
                if(c==0)
                    break;
                x1=x2;
                x2=h;
                cnt++;
                h = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));

            }
            cout<<"The root is: "<<h<<endl;
            cout<<"The number of iteration is: "<<cnt<<endl;
        }

};


int main()
{
    double x1,x2;
    secantMethod sm;

    srand(time(NULL));
    x1 = ((rand()%(-20-20+1))-20); // range [-20,20]
    x2 = ((rand()%(0-20+1))+0); // range [0,20]

    cout<<"For x1 = "<<x1<<endl;
    cout<<"For x2 = "<<x2<<endl;
    sm.calculate(x1,x2);
    return 0;
}
