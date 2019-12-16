#include<stdio.h>
#include"math.h"
#include<stdlib.h>
#include<sys/time.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/param.h>
#include<unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <wait.h>
#include <string.h>
#include <pthread.h>
#include <limits.h>
#include <assert.h>

#define check_error(return_val,msg){\
			if(return_val!=0){\
				fprintf(stderr,"%s:%s\n",msg,strerror(return_val));   \
				exit(-1);\			
			}\
		}


