#include<iostream>
using namespace std;
struct dis
{
	int d,b,a,c;
};
int main()
{
	dis x;
	cout <<"enter the values of a,b,c";
	cin >>x.a>>x.b>>x.c;
	x.d =((x.b*x.b)-(4*x.a*x.c));
	cout <<"discriminant is equal to "<<x.d;
	return 0;	
}
