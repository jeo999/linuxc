#include "dylib.h"
#include <stdio.h>

int main()
{
	int n=100;
	int a[n];
	initarray(a,n);
	showarray(a,n);
	printf("max= %d\n",max(a,n));
	printf("sum= %d\n",sum(a,n));
	return 0;

}
