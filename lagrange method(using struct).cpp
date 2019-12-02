#include<bits/stdc++.h>

using namespace std;

struct Value
{
    int x,y;
};

class LagrangeMethod
{
    public:

    double calculate(Value a[], int x_out, int n)
    {
        double result = 0;

        for (int i=0; i<n; i++)
        {
            double Y = a[i].y;
            for (int j=0;j<n;j++)
            {
                if (j!=i)
                    Y *= (x_out - a[j].x)/double(a[i].x - a[j].x);
            }

            result += Y;
        }

        return result;
    }

};


int main()
{
    LagrangeMethod lm;

    Value a[] = {{0,2}, {1,3}, {2,12}, {5,147}};

    double ans = lm.calculate(a,3,4);
    cout<<"ans for f(3) is : "<<ans<<endl;

    return 0;
}
