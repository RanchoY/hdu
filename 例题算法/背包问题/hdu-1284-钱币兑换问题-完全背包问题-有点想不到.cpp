//完全背包问题 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 50000
using namespace std;

int dp[MAX]={0};

int main()
{
	int n;
	dp[0] = 1;
	for(int i=1; i<=3; i++)
	{
		for(int j=i; j<=MAX; j++)
		{
			dp[j] += dp[j-i];
		}
	}
	while(~scanf("%d", &n))
	{
		printf("%d\n",dp[n]);
	}
	return 0;
}
/**
2934
12553

718831
13137761
*/ 