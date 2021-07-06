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

unsigned int tot,fst[5000000],nxt[5000000];
typedef struct {unsigned int con,s[26];} stu; stu pol[2000000];
unsigned char buffer1[50000000],buffer2[5000000],print[400000],*s[5000000];
void digit(unsigned int x) {if (x>9) digit(x/10); print[tot++]=x%10^48; return;}
int read() {unsigned int ans=0; char c=getchar(); while ('0'<=c && c<='9') ans=(ans<<3)+(ans<<1)+(c^48),c=getchar(); return ans;}

int main()
{
	FILE *in,*out;
	register unsigned char* pos,c;
	unsigned int n,i,j,k=0,top=0,len=0;
	const unsigned char split[256]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
	const unsigned char ascii[256]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	const unsigned char alpha[256]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	in=fopen("article.txt","rb");
	n=fread(buffer1,1,50000000,in);
	for (buffer1[n]=j=0,i=n-1;i+1;)
	{
		while (i+1 && !ascii[buffer1[i]]) --i;
		while (i+1 && ascii[c=buffer1[i--]])
		{
			if (!pol[j].s[alpha[c]]) pol[j].s[alpha[c]]=++k;
			j=pol[j].s[alpha[c]];
		}
		++pol[j].con,j=0;
	}
	fclose(in);
	in=fopen("stopwords.txt","rb");
	k=fread(buffer2,1,5000000,in);
	for (buffer2[k]=j=0,i=k-1;i+1;)
	{
		while (i+1 && !ascii[buffer2[i]]) --i;
		while (i+1 && ascii[c=buffer2[i]])
		{
			if (!pol[j].s[alpha[c]])
			{
				while (ascii[buffer2[i]]) --i;
				j=0; break;
			}
			j=pol[j].s[alpha[c]],i--;
		}
		if (j) j=pol[j].con=0;
	}
	fclose(in);
	for (i=n-1,j=n=0;i+1;)
	{
		while (i+1 && split[buffer1[i]]) --i;
		for (k=0;i+1;)
		{
			while (i+1 && !ascii[c=buffer1[i]])
				if (split[c]) goto OUT;
				else --i;
			while (i+1 && ascii[c=buffer1[i--]])
				j=pol[j].s[alpha[c]];
			k+=pol[j].con,j=0;
		}
		OUT:
		if (k)
		{
			nxt[++n]=fst[k],fst[k]=n;
			s[n]=buffer1+i+1,++len;
			if (k>top) top=k;
		}
	}
	n=read();
	if (n>len) n=len;
	for (i=top,k=0,len=0;i && k<n;--i)
		for (j=fst[i];j && k<n;j=nxt[j])
		{
			++k,pos=s[j];
			digit(i),print[tot++]=32;
			while (*pos<=32 || *pos==127) ++pos;
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