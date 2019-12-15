#include "my.h"
void init_daemom(void){
	pid_t child1,child2;
	int i;
	child1=fork();
	if(child1>0){		//创建子进程，终止父进程
		exit(0);		//	这是子进程，后台继续执行
	}
	else if(child1<0){
		perror("创建子进程失败！");	//fork()失败，退出
		exit(1);
	}
	setsid();					//	在子进程中创建新绘画
	chdir("/tmp");				//改变工作目录到“/tmp”
	umask(0);					//重设文件创建掩码
	for(i=0;i<NOFILE;++i){	//关闭文件描述符
		close(i);
	}
	return ;
}

int main(){
	FILE *fp;
	time_t t;
	init_daemom();
	while(1){
		sleep(10);
		if((fp=fopen("6-8.log","a"))>=0){
			t=time(0);
			fprintf(fp,"守护进程还在运行，时间是：%s",asctime(localtime(&t)));
			fclose(fp);
		}
	}

}
