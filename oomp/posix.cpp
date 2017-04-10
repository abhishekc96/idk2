#include<iostream>
#include<stdlib.h>
#include<string>
#include<spawn.h>
#include<sys/wait.h>

using namespace std;

int main(void)
{
	pid_t pid1, pid2, pid3;

	char str1[] = "mkdir";
	char str2[] = "Modern";	
	char str3[] = "pwd";
	char str4[] = "ls";

	char* args1[] = {str1, str2, NULL};
	char* args2[] = {str3, NULL};
	char* args3[] = {str4, NULL};
	
	int status1, status2, status3;

	status1 = posix_spawn(&pid1, "/bin/mkdir", NULL, NULL, args1, NULL);
	cout<<"\nCreating 'Modern' directory"<<"\nPid: "<<pid1<<"\nPosix spawn status: "<<status1;
	status2 = posix_spawn(&pid2, "/bin/pwd", NULL, NULL, args2, NULL);
	cout<<"\nDisplaying the path of 'Modern' directory"<<"\nPid: "<<pid2<<"\nPosix spawn status: "<<status2;
	status3 = posix_spawn(&pid3, "/bin/ls", NULL, NULL, args3, NULL);
	cout<<"\nDisplaying list of processes"<<"\nPid: "<<pid3<<"\nPosix spawn status: "<<status3<<endl<<endl;
	return 0;
}
