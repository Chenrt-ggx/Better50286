#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

const int maxn=500;
const char* files[]=
{
	"my_trie1","my_trie2",
	"my_trie3",
	"my_trie1","my_trie2",
	"my_trie3",
	"my_trie1","my_trie2",
	"my_trie3",
};

char buffer[1<<12];
clock_t start,finish;
char fc1[1<<22],fc2[1<<22];
double result[sizeof(files)/sizeof(*files)];

inline void test(const char* name,double* pushup)
{
	sprintf(buffer,"%s.exe < input.txt > nil.txt",name);
	start=clock(); system(buffer); finish=clock();
	*pushup+=(((double)finish-(double)start)/1e3);
	FILE* in1=fopen("answer.txt","rb"); assert(in1);
	FILE* in2=fopen("results.txt","rb"); assert(in2);
	fread(fc1,1,1<<22,in1);
	fread(fc2,1,1<<22,in2);
	assert(!strcmp(fc1,fc2));
	fclose(in1),fclose(in2);
	return;
}

int main()
{
	for (int i=0;i<(int)(sizeof(files)/sizeof(*files));i++)
	{
		sprintf(buffer,"%s.c",files[i]);
		FILE* test=fopen(buffer,"r");
		assert(test); fclose(test);
		sprintf(buffer,"gcc %s.c -o %s -std=c99",files[i],files[i]);
		system(buffer);
		sprintf(buffer,"%s.exe",files[i]);
		test=fopen(buffer,"r");
		assert(test); fclose(test);
	}
	puts("all compiled");
	for (int i=0;i<maxn;i++)
	{
		for (int j=0;j<(int)(sizeof(files)/sizeof(*files));j++)
			test(files[j],result+j);
		printf("finished %d / %d\n",i,maxn);
	}
	for (int i=0;i<(int)(sizeof(files)/sizeof(*files));i++)
	{
		printf("total time of %s is %lf\n",files[i],result[i]);
		//sprintf(buffer,"rm %s.exe",files[i]);
		system(buffer);
	}
	system("rm results.txt");
	system("rm nil.txt");
	return 0;
}