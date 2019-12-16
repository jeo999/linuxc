#include"my.h"
int main(){
	pid_t child1, child2, child3;
	int r_num;
	int pipe_fd1[2], pipe_fd2[2];
	char buf_r1[4097];//32位机器才是4096字节大小
	char buf_r2[4097];
	memset(buf_r1, 0, sizeof(buf_r1));
	memset(buf_r2, 97, sizeof(buf_r2));
	if(pipe(pipe_fd1)<0 || pipe(pipe_fd2)<0){
		perror("创建管道失败!\n");
		return -1;
	}
	child1 = fork();
	if(child1<0){
		perror("创建子进程1失败！\n");
		return -1;
	}else if(child1==0){
		close(pipe_fd1[0]);
		if(write(pipe_fd1[1], buf_r2, 4097)!=-1){
			printf("子进程1写入！\n");
		}
		close(pipe_fd1[1]);
		exit(0);
	}else{
		child2 = fork();
		if(child2<0){
			perror("创建子进程2失败！\n");
			return -1;
		}else if(child2==0){
			close(pipe_fd1[1]);
			if(r_num=read(pipe_fd1[0], buf_r1, 4097)>0){
				printf("子进程2从管道读取的字符串是：%s, 大小是读：%ld,读取字符个数：%d\n", buf_r1, sizeof(buf_r1), r_num);
			}
			close(pipe_fd1[0]);
			
			close(pipe_fd2[0]);
			if(write(pipe_fd2[1], buf_r1, 4097)!=-1){
				printf("子进程2写入！\n");
			}
			close(pipe_fd2[1]);
			exit(0);
		}else{
			child3 = fork();
			if(child3<0){
				perror("创建子进程3失败！\n");
				return -1;
			}else if(child3==0){
				close(pipe_fd2[1]);
				if(r_num=read(pipe_fd2[0], buf_r1, 4097)>0){
					printf("子进程3从管道读取的字符串是：%s, 大小是读：%ld,读取字符个数：%d\n", buf_r1, sizeof(buf_r1), r_num);
				}
				close(pipe_fd2[0]);
				exit(0);
			}else{
				wait(NULL);
				wait(NULL);
				wait(NULL);
				return 0;
			}
		}
	}
}

