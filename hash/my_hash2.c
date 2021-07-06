#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <stdio.h>

typedef struct {unsigned int con; unsigned char *s;} stu; stu pol[2000000];
unsigned char buffer1[50000000],buffer2[5000000],print[400000],*s[5000000];
unsigned int tot,fst[5000000],lst[5000000],nxt[5000000],src[524300],dst[5000000];
void digit(unsigned int x) {if (x>9) digit(x/10); print[tot++]=x%10^48; return;}
int read() {unsigned int ans=0; char c=getchar(); while ('0'<=c && c<='9') ans=(ans<<3)+(ans<<1)+(c^48),c=getchar(); return ans;}

inline int smp(unsigned char* a,unsigned char* b,const unsigned char ascii[])
{
	while ((*a|32)==(*b|32) && ascii[*a] && ascii[*b]) ++a,++b;
	return !ascii[*a] && !ascii[*b];
}

int main()
{
	FILE *in,*out;
	register unsigned char *pos,*fnd;
	unsigned int n,i,j,k,tmp=0,top=0,len=0;
	const unsigned char split[256]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
	const unsigned char ascii[256]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	in=fopen("article.txt","rb");
	n=fread(buffer1,1,50000000,in);
	for (buffer1[n]=i=0;buffer1[i];)
	{
		while (buffer1[i] && !ascii[buffer1[i]]) ++i;
		for (k=0,pos=buffer1+i;ascii[buffer1[i]];)
			k=k*13131+(buffer1[i++]|32);
		for (k&=524287,j=src[k];j;j=dst[j])
			if (smp(pol[j].s,pos,ascii))
				{++pol[j].con; pos=NULL; break;}
		if (!pos) continue;
		pol[++tmp].s=pos,++pol[tmp].con;
		dst[tmp]=src[k],src[k]=tmp;
	}
	fclose(in);
	in=fopen("stopwords.txt","rb");
	n=fread(buffer2,1,5000000,in);
	for (buffer2[n]=i=0;buffer2[i];)
	{
		while (buffer2[i] && !ascii[buffer2[i]]) ++i;
		for (k=0,pos=buffer2+i;ascii[buffer2[i]];)
			k=k*13131+(buffer2[i++]|32);
		for (k&=524287,j=src[k];j;j=dst[j])
			if (smp(pol[j].s,pos,ascii))
				{pol[j].con=0; break;}
	}
	fclose(in);
	for (i=n=0;buffer1[i];)
	{
		while (buffer1[i] && split[buffer1[i]]) ++i;
		while (buffer1[i] && (buffer1[i]<=32 || buffer1[i]==127)) ++i;
		fnd=&buffer1[i];
		for (tmp=0;buffer1[i];)
		{
			while (buffer1[i] && !ascii[buffer1[i]])
				if (split[buffer1[i]]) goto OUT;
				else ++i;
			for (k=0,pos=buffer1+i;ascii[buffer1[i]];)
				k=k*13131+(buffer1[i++]|32);
			for (k&=524287,j=src[k];j;j=dst[j])
				if (smp(pol[j].s,pos,ascii))
					{tmp+=pol[j].con; break;}
		}
		OUT:
		if (tmp)
		{
			nxt[lst[tmp]]=++n,lst[tmp]=n;
			s[n]=fnd,++len;
			if (tmp>top) top=tmp;
			if (!fst[tmp]) fst[tmp]=n;
		}
	}
	n=read();
	if (n>len) n=len;
	for (i=top,k=0,len=0;i && k<n;--i)
		for (j=fst[i];j && k<n;j=nxt[j])
		{
			++k,pos=s[j];
			digit(i),print[tot++]=32;
			while (!split[*pos]) print[tot++]=*pos++;
			print[tot++]=*pos++,print[tot++]='\n';
			if (k==5) len=tot;
		}
	out=fopen("results.txt","w");
	fwrite(print,1,tot,out),fclose(out);
	if (len) print[len]=0;
	puts((const char*)print);
	return 0;
}