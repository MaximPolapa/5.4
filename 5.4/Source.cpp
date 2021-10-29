#include <iostream>
#include <cmath>

using namespace std;

double S0(const int k, const int N)
{
	double s = 0;
	for (int i = k; i <= N; i++)
		s += (cos(i))/(1.+sin(i)* sin(i));
	return s;
}

double S1(const int k, const int N, const int i)
{
	if (i > N)
		return 0;
	else
		return (cos(i)) / (1. + sin(i) * sin(i)) + S1(k, N, i + 1);
}

double S2(const int k, const int N, const int i)
{
	if (i < k)
		return 0;
	else
		return (cos(i)) / (1. + sin(i) * sin(i)) + S2(k, 15, i - 1);
}

double S3(const int k, const int N, const int i, double t)
{
	t = t + (cos(i)) / (1. + sin(i) * sin(i));
	if (i >= N)
		return t;
	else
		return S3(k, N, i + 1, t);
}

double S4(const int k, const int N, const int i, double t)
{
	t = t + (cos(i)) / (1. + sin(i) * sin(i));
	if (i <= k)
		return t;
	else
		return S4(k, N, i-1, t);
}

int main()
{
	int k, N;
	cout << "k = "; cin >> k;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << S0(k, N) << endl;
	cout << "(rec up ++) S1 = " << S1(k, N, k) << endl;
	cout << "(rec up --) S2 = " << S2(k, N, N) << endl;
	cout << "(rec down ++) S3 = " << S3(k, N, k, 0) << endl;
	cout << "(rec down --) S4 = " << S4(k, N, N, 0) << endl;
	return 0;
}
