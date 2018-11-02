// 注意圆的半径为1，当圆心到某点距离小于1.0001就判定在圆中 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define MAX 305
using namespace std;

struct node {
	double x,y;
} p[MAX], center;

double dist(node a, node b)
{
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y); 
}
// 得到圆心 
void get_center(node a, node b)
{
	node mid;
	double k,angle,a_mid,len;
	k = (-1)*(a.x-b.x)/(a.y-b.y);
	angle = atan(k);// 角度数
	
	mid.x = (a.x + b.x) / 2;
	mid.y = (a.y + b.y) / 2;
	a_mid = dist(a, mid);
	len = sqrt(1.0 - a_mid);
	
	center.x = mid.x + len*cos(angle);
	center.y = mid.y + len*sin(angle);
}

int main()
{
	int cnt,n,res,temp;
	scanf("%d", &cnt);
	while(cnt--)
	{
		//初始化
		res = 1;
		 
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		
		for(int i=0; i<n-1; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				if(dist(p[i], p[j]) <= 4.0)
				{
					temp = 0;
					get_center(p[i], p[j]);
					
					for(int k=0; k<n; k++)
					{
						if(dist(center, p[k]) <= 1.0001)
						{
							temp ++;
						}
						res = max(res, temp);
					}
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}

/*
4
3
6.47634 7.69628
5.16828 4.79915
6.69533 6.20378
6
7.15296 4.08328
6.50827 2.69466
5.91219 3.86661
5.29853 4.16097
6.10838 3.46039
6.34060 2.41599
8
7.90650 4.01746
4.10998 4.18354
4.67289 4.01887
6.33885 4.28388
4.98106 3.82728
5.12379 5.16473
7.84664 4.67693
4.02776 3.87990
20
6.65128 5.47490
6.42743 6.26189
6.35864 4.61611
6.59020 4.54228
4.43967 5.70059
4.38226 5.70536
5.50755 6.18163
7.41971 6.13668
6.71936 3.04496
5.61832 4.23857
5.99424 4.29328
5.60961 4.32998
6.82242 5.79683
5.44693 3.82724
6.70906 3.65736
7.89087 5.68000
6.23300 4.59530
5.92401 4.92329
6.24168 3.81389
6.22671 3.62210

2
5
5
11
*/ 