#include <stdio.h>
#define max 1000000
typedef long long ll;
int N, M;
ll tree[max + 1];
ll data[max + 1];
void update(int idx, ll value)
{
	while (idx <= N)
	{
		tree[idx] += value;
		idx += (idx & -idx);
	}
}
ll sum(int idx)
{
	ll ret = 0;
	while (idx > 0)
	{
		ret += tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}
int main()
{
	int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		ll x;
		scanf("%lld", &x);
		data[i + 1] = x;
		update(i + 1, x);
	}
	for (i = 0; i < M; i++)
	{
		int b, c;
		ll v;
		scanf("%d %d", &b, &c);
		printf("%lld\n", sum(c) - sum(b - 1));
	}
	return 0;
}