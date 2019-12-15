#include "dylib.h"
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
int main()
{
	int n=100;
	int a[n];
	void *hd;
	char *error;
	void (*f1)();
	int (*f2)(),(*f3)();
	hd=dlopen("../dynamiclib/libdylib.so",RTLD_LAZY);
	if(!hd)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f1=dlsym(hd,"initarray");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f1(a,n);
	f1=dlsym(hd,"showarray");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f2=dlsym(hd,"max");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f3=dlsym(hd,"sum");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f1(a,n);
	printf("max= %d\n",f2(a,n));
	printf("sum= %d\n",f3(a,n));
	if(dlclose(hd)<0)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	return 0;
}
