#include<bits/stdc++.h>

using namespace std;

struct Value
{
    int x,y;
};

class LagrangeMethod
{
    public:

    double calculate(map<int,int> a, int x_out, int n)
    {
        map<int, int>::iterator itr_i;
        map<int, int>::iterator itr_j;
        double result = 0;
        int i,j;

        for (itr_i=a.begin(),i=0; itr_i!=a.end(); itr_i++,i++)
        {
            double Y = itr_i->second;
            for (itr_j=a.begin(),j=0; itr_j!=a.end(); itr_j++,j++)
            {
                if (j!=i)
                    Y *= (x_out - itr_j->first)/double(itr_i->first - itr_j->first);
            }

            result += Y;
        }

        return result;
    }

};


int main()
{
    LagrangeMethod lm;

    map<int,int> a;
    a.insert(pair<int, int>(0, 2));
    a.insert(pair<int, int>(1, 3));
    a.insert(pair<int, int>(2, 12));
    a.insert(pair<int, int>(5, 147));

    double ans = lm.calculate(a,3,4);
    cout<<"ans for f(3) is : "<<ans<<endl;

    return 0;
}
