#include	<cstdio>
#include	<cstdlib>
#include	<cstring>
#include	<vector>
#include	<string>
#include	<algorithm>
#include	<iostream>
#define pb push_back
using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long LL;
const double EPS = 1E-8;

struct Class {
	void Method(void);
};

struct Double { double d; Double(double dd) { d = dd; } };

int testcase;

bool
operator==(const Double &_a, const Double &_b)
{
	double a = _a.d, b = _b.d;
	double r1 = a * (1 - EPS), r2 = a * (1 + EPS);
	if ( r1 > r2 ) swap(r1, r2);
	return r1 <= b && b <= r2;
}

template<typename T> ostream &
operator<<(ostream &out, vector<T> v)
{
	cout << "{ ";
	for ( int i = 0; i < v.size(); i++ ) {
		if ( i ) cout << ", ";
		cout << v[i];
	}
	cout << " }";
	return cout;
}

ostream &
operator<<(ostream &out, string &s)
{
	cout << '"';
	for ( int i = 0; i < int(s.size()); i++ ) 
		cout << s[i];
	cout << '"';
	return cout;
}

ostream &
operator<<(ostream &out, Double d)
{
	out << d.d;
	return out;
}

template<typename T> void
TestEqual(T a, T b)
{
	if ( a == b ) {
		cout << "OK" << endl;
		exit(0);
	} else {
		cout << "Failed" << endl;
		cout << "Expected: " << a << endl;
		cout << "Received: " << b << endl;
		exit(1);
	}
}

