#include <cstdio>
#include <queue>

void hanoi_tower(int n, int from, int tmp, int to)
{
	if (n==1)
		printf("%c %c\n", from, to);
	else
	{
		hanoi_tower(n-1, from, to, tmp);
		printf("%c %c\n", from, to);
		hanoi_tower(n -1, tmp, from, to);
	}
}

int main()
{
	int n, d=1;

	scanf("%d", &n);

	for(int i=0; i<n; i++)
		d*=2;

	printf("%d\n", d-1);

	hanoi_tower(n, '1', '2', '3');

}
