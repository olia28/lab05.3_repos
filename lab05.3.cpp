#include <iostream>
#include <cmath>
using namespace std;
double y(const double x);
int main()
{
	double fp, fk, z;
	int n;
	cout << "gp = "; cin >> fp;
	cout << "gk = "; cin >> fk;
	cout << "n = "; cin >> n;
	double df = (fk - fp) / n;
	double f = fp;
	while (f <= fk)
	{
		z = y(f/2)+y(f+1)*y(f + 1)+y(2*f);
		cout << f << " " << z << endl;
		f += df;
	}
	return 0;
}
double y(const double x)
{
	if (abs(x) >= 1)
		return (exp(x)/(1+ exp(x) + sin(x)));
	else
	{
		double S = 0;
		int j = 0;
		double a = 1;
		S = a;
		do
		{
			j++;
			double R = pow(x, 2) / (2 * j - 4 * pow(j, 2));
			a *= R;
			S += a;
		} while (j < 8);
		return S;
	}
}
