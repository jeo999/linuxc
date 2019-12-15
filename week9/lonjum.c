#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <setjmp.h>
static jmp_buf g_stack_env;

static void fun1(void);
static void fun2(void);


int main(void){
	if(0== setjmp(g_stack_env)){
		printf("Normal folw\n");
		fun1();
	}else{
		printf("Long jump flow\n");
	}
	return 0;
}

static void fun1(){
	printf("Enter func1\n");
	fun2();
}

static void fun2(){
	printf("Enter func2\n");
	longjmp(g_stack_env,1);
	printf("Leave func2\n");
}
