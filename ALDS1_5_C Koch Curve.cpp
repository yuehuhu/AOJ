#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#define pi 3.1415926

using namespace std;
struct point
{
	double x, y;
};
int n;
double th = pi * 60 / 180;

void koch(int n, point a, point b)
{
	if (n == 0) return;
	point s, t, u;
	s.x = (b.x + 2 * a.x) / 3;
	s.y = (b.y + 2 * a.y) / 3;
	t.x = (2 * b.x + a.x) / 3;
	t.y = (2 * b.y + a.y) / 3;
	u.x = (t.x - s.x)*cos(th) - (t.y - s.y)*sin(th)+s.x;
	u.y = (t.x - s.x)*sin(th) + (t.y - s.y)*cos(th)+s.y;
	//printf("n=%d, (%.2f %.2f) (%.2f %.2f) (%.2f %.2f) (%.2f %.2f) (%.2f %.2f)\n",n, a.x, a.y, s.x, s.y, u.x, u.y, t.x, t.y, b.x, b.y);
	koch(n - 1, a, s);
	printf("%.8f %.8f\n", s.x, s.y);
	koch(n - 1, s, u);
	printf("%.8f %.8f\n", u.x, u.y);
	koch(n - 1, u, t);
	printf("%.8f %.8f\n", t.x, t.y);
	koch(n - 1, t, b);
	
	

}

int main()
{
	cin >> n;
	point a,b;
	a.x = 0;
	a.y = 0;
	b.x = 100;
	b.y = 0;
	printf("%.8f ,%.8f\n", a.x, a.y);

	koch(n, a, b);
	printf("%.8f ,%.8f\n", b.x, b.y);
	return 0;
}