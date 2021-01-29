int main()
{
	int a = 0;
	int n = 0;
	int i = 0;
	int sum = 0;
	int tmp = 0;
 
 
	scanf("%d%d", &a, &n);
	for(i=0; i<n; i++)
	{
		tmp = tmp*10+a;
		sum += tmp;
	}
	printf("%d\n", sum);
 
	return 0;
}