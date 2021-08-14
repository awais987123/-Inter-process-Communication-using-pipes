#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#define buffsize 25
#define read_pipe 0
#defife write_pipe 1 
int main()
{
char w_msg[buffsize]="Hello World!";
char r_msg[buffsize];
int fd[2];
pid_t pid;
//Create a pipe
if(pipe(fd)==-1)
{
fprintf(stderr,"Pipe is not created ");
0
return 1;
}
pid=fork();
if(pid<0)
{
fprintf(stderr, "Fork failed");
return 1;
}
if(pid>0)
{
//parent process 
close(fd[write_pipe]);
read(fd[read_pipe],r_msg,buffsize);
printf("read =%s",r_msg);
close(fd[read_pipe]);
}
else
{
//child process
close(fd[read_pipe]);
write(fd[write_pipe],w_msg,strlen(w_msg)+1);
close(fd[write_pipe]);
}return 0;
}
