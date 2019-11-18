#include<bits/stdc++.h>
#define E 0.001
using namespace std;
double c;
class FalsePosition
{
    public:

        double f(double x)
    {
        return (x*x*x)-x-1;
    }

    double calculate(double a,double b)
    {
        if(f(a) * f(b) >= 0)
        {
            cout<<"Incorrect a and b";
            return 0;
        }

        while (1)
        {
            double d=c;

            c = ((f(a)*b)-(f(b)*a))/(f(a)-f(b));

            if ( abs(d-c)< E ){
               printf("Root = %.2f\n",c);
                break;
            }
            else if (f(c)*f(a) < 0){
                   printf("Root = %.2f\n",c);
                    b = c;
            }
            else{
                   printf("Root = %.2f\n",c);
                    a = c;
            }
        }
         printf("The final root is = %.2f",c);
    }
};


int main()
{
    FalsePosition fp;
    double a,b,c;

    srand(time(NULL));
    a = ((rand()%(-10-20+1))-10); // range [-10,20]
    b = (rand()%(0-10+1))+0;  //range [0,10]

    cout<<"For a = "<<a<<endl;
    cout<<"For b = "<<b<<endl;
    fp.calculate(a,b);


    return 0;
}
