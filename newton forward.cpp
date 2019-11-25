#include<bits/stdc++.h>

using namespace std;

class NewtonForward
{
    public:

    float find_u(float u, int n)
    {
        float temp = u;
        for (int i = 1; i < n; i++)
            temp = temp * (u - i);
        return temp;
    }

    int fact(int n)
    {
        int f = 1;
        for (int i = 2; i <= n; i++)
            f *= i;
        return f;
    }

    void calculate()
    {
       // int n = 4;
       // float x[] = { 1, 3, 5, 7 };
       int n = 5;
       float x[] = {0.10 , 0.15, 0.20, 0.25,0.30 };
        float y[n][n];
        /*y[0][0] = 24;
        y[1][0] = 120;
        y[2][0] = 336;
        y[3][0] = 720;*/
        y[0][0] = 0.1003;
        y[1][0] = 0.1511;
        y[2][0] = 0.2027;
        y[3][0] = 0.2553;
        y[4][0] = 0.3093;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
                y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }

        for (int i = 0; i < n; i++)
        {
            cout << setw(4) << x[i]
             << "\t";
        for (int j = 0; j < n - i; j++)
            cout << setw(4) << y[i][j]
                 << "\t";
        cout << endl;
        }

        //float value = 0.12;
        float value = 0.26;

        float sum = y[0][0];

        float u = (value - x[0]) / (x[1] - x[0]);

        for (int i = 1; i < n; i++) {
            sum = sum + (find_u(u, i) * y[0][i]) /
                                     fact(i);
        }

        cout << "\nValue of " << value << " is "
             << sum << endl;
        }
};


int main()
{
    NewtonForward nf;

    nf.calculate();

    return 0;
}
