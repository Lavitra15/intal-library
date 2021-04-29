#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"
char* intal_add(const char* intal1, const char* intal2)
{
	int len1= strlen(intal1);
	int len2= strlen(intal2);
	if(len1<len2)
	{
		const char *temp=intal1;
		intal1=intal2;
		intal2=temp;
		int temp_len=len1;
		len1=len2;
		len2=temp_len;
	}
	int carry=0, diff_len=len1-len2;
	int sum, i;
	char *result=(char*)malloc((len1+2)*sizeof(char));
	result[len1+1]='\0';
	for(i=0; i<len1+1; ++i)
		result[i]='0';
	for(i=len2-1; i>=0; --i)
	{
		sum=intal1[diff_len+i]+intal2[i]+carry-48;
		if(sum>57)
		{
			result[diff_len+i+1]=sum-10;
			carry=1;
		}
		else
		{
			result[diff_len+i+1]=sum;
			carry=0;
		}
	}
	for(i=diff_len-1; i>=0; --i)
	{
		sum=intal1[i]+carry;
		if(sum>57)
		{
			result[i+1]=sum-10;
			carry=1;
		}
		else
		{
			result[i+1]=sum;
			carry=0;
		}
	}
	result[0]=carry+48;
	if(result[0]=='0' && result[1]!='\0')
	{
		char *res=(char*)malloc((len1+1)*sizeof(char));
		res[len1]='\0';
		for(i=len1-1; i>=0; --i)
			res[i]=result[i+1];
		free(result);
		return res;
	}
	return result;
}
int intal_compare(const char* intal1, const char* intal2)
{
	int len1= strlen(intal1);
	int len2= strlen(intal2);
	if(len1>len2) return 1;
	if(len1<len2) return -1;
	int i=-1;
	while(++i<len1)
	{
		if(intal1[i]>intal2[i]) return 1;
		if(intal1[i]<intal2[i]) return -1;
	}
	return 0;
}
char* intal_diff(const char* intal1, const char* intal2)
{
	int len1= strlen(intal1);
	int len2= strlen(intal2);
	if(intal_compare(intal1, intal2)<0)
	{
		const char *temp=intal1;
		intal1=intal2;
		intal2=temp;
		int temp_len=len1;
		len1=len2;
		len2=temp_len;
	} //now len1 always greater than or equal to len2
	int diff_len = len1-len2;
	char *result = (char*)malloc((len1+1)*sizeof(char));
	result[len1]='\0';
	int diff, borrow=0;
	for(int i=len2-1; i>=0; --i)
	{
		diff=intal1[diff_len+i]-intal2[i]-borrow;
		if(diff<0)
		{
			result[diff_len+i]=diff+48+10;
			borrow=1;
		}
		else
		{
			result[diff_len+i]=diff+48;
			borrow=0;
		}
	}
	for(int i=diff_len-1; i>=0; --i)
	{
		diff=intal1[i]-borrow;
		if(diff<48)
		{
			result[i]=diff+10;
			borrow=1;
		}
		else
		{
			result[i]=diff;
			borrow=0;
		}
	}
	int i=0;
	if('0'==result[0])	
	{
		while('\0'!=result[i+1] && '0'==result[i])
			++i;
		char *res=(char*)malloc((len1+1-i)*sizeof(char));
		res[len1-i]='\0';
		for(int j=len1-1; j>=i; --j)
			res[j-i]=result[j];
		free(result);
		return res;
	}
	return result;
}
char* intal_multiply(const char* intal1, const char* intal2)
{
	if(0==intal_compare(intal1,"0") && 0==intal_compare(intal2,"0"))return "0";
	int len1= strlen(intal1);
	int len2= strlen(intal2);
	if(len1<len2)
	{
		const char *temp=intal1;
		intal1=intal2;
		intal2=temp;
		int temp_len=len1;
		len1=len2;
		len2=temp_len;
	}
	int num1, num2, mul, carry=0, i, j, k;
	char *result = (char*)malloc((len1+len2+1)*sizeof(char));
	result[len1+len2]='\0';
	for(i=0; i<len1+len2; ++i)
		result[i]='0';
	for(i=1; i<=len2; ++i)
	{
		num2=intal2[len2-i]-48;
		carry=0;
		for(j=1; j<=len1; ++j)
		{
			num1=intal1[len1-j]-48;
			mul=num1*num2+carry;
			carry=mul/10;
			result[len1+len2-i-j+1]+=mul%10;
			k=i+j;
			while((k-1<=len1+len2) && result[len1+len2-k+1]>57)
			{
				result[len1+len2-k+1]-=10;
				result[len1+len2-k]+=1;
				++k;
			}
		}
		result[len1+len2-i-j+1]+=carry;
	}
	i=0;
	while('\0'!=result[i+1] && '0'==result[i])
		++i;
	char *res=(char*)malloc((len1+len2+1-i)*sizeof(char));
	res[len1+len2-i]='\0';
	for(j=len1+len2-1; j>=i; --j)
		res[j-i]=result[j];
	free(result);
	return res;
}
static char* mod_cal(const char* intal1, const char* intal2)
{
	int comp=intal_compare(intal1,intal2);
	if(comp==0)
	{
		char* res=(char*)malloc(sizeof(char)*2);
		res[0]='0';
		res[0]='\0';
		return res;
	}
	int len1=strlen(intal1);
	if(comp==-1)
	{
		char* res=(char*)malloc(sizeof(char)*(len1+1));
		strcpy(res,intal1);
		return res;
	}
	else
	{
		int len2=strlen(intal2);
		int d=len1-len2;
		int i=0;
		while(i<len2)
		{
			if(intal1[i]>intal2[i])
				i=len2;
			else if(intal1[i]<intal2[i])
			{
				--d;
				i=len2;
			}
			++i;
		}
		int lenc=len2+d;
		char* copy2=(char*)malloc(sizeof(char)*(lenc+1));
		strcpy(copy2,intal2);
		for(i=len2;i<lenc;++i)
			copy2[i]='0';
		copy2[lenc]='\0';
		char* diff=intal_diff(intal1,copy2);
		free(copy2);
		char* res=intal_mod(diff,intal2);
		free(diff);
		return res;
	}
}
char* intal_mod(const char* intal1, const char* intal2)
{
	if(intal2[0]=='2' && intal2[1]=='\0')
	{
		char* res=(char*)malloc(sizeof(char)*2);
		int len1=strlen(intal1);
		res[0]=((intal1[len1-1]-'0')%2)+'0';
		res[1]='\0';
		return res;
	}
	int comp=intal_compare(intal1,intal2);
	if(comp==0)
	{
		char* res=(char*)malloc(sizeof(char)*2);
		res[0]='0';
		res[1]='\0';
		return res;
	}
	else if(comp==-1)
	{
		int len=strlen(intal1);
		char* res=(char*)malloc(sizeof(char)*(len+1));
		strcpy(res,intal1);
		return res;
	}
	return mod_cal(intal1,intal2);
}
char* intal_pow(const char* intal1, unsigned int n)
{
	if(intal1[0]=='0')
	{
		char *intal=(char*)malloc(2*sizeof(char));
		intal="0";
		return intal;
	}
	else if(n==0)
	{
		char *intal=(char*)malloc(2*sizeof(char));
		intal="1";
		return intal;
	}
	if(n==1)
	{
		char *temp=(char*)malloc((strlen(intal1)+1)*sizeof(char));
		strcpy(temp,intal1);
		return temp;
	}
	if(n%2) 
	{
		char *temp=intal_pow(intal1,(n-1)/2);
		return intal_multiply(intal1,intal_multiply(temp,temp));
	}
	else
	{
		char *temp=intal_pow(intal1,n/2);
		return intal_multiply(temp,temp);
	}
}
char* intal_gcd(const char* intal1, const char* intal2)
{
	if(intal1[0]=='0' && intal2[0]=='0') return "0";
	if(intal1[0]=='0')
	{
		char *temp=(char*)malloc((strlen(intal2)+1)*sizeof(char));
		strcpy(temp,intal2);
		return temp;
	}
	if(intal2[0]=='0')
	{
		char *temp=(char*)malloc((strlen(intal1)+1)*sizeof(char));
		strcpy(temp,intal1);
		return temp;
	}
	if(intal_compare(intal1, intal2)<0)
	{
		const char *temp=intal1;
		intal1=intal2;
		intal2=temp;
	}
	char *i1=(char*)malloc((1+strlen(intal1))*sizeof(char));
    char *i2=(char*)malloc((1+strlen(intal2))*sizeof(char));
    strcpy(i1,intal1);
    strcpy(i2,intal2);
    while(1==intal_compare(intal_mod(i1,i2),"0"))
    {
        char *temp=intal_mod(i1,i2);
		strcpy(i1,i2);
        strcpy(i2,temp);
        free(temp);
    }
    return i2;
}
char* intal_fibonacci(unsigned int n)
{
	char* a=(char*)malloc(sizeof(char)*2);
	a[0]='0';
	a[1]='\0';
	if(n==0)
		return a;
	else if(n==1)
	{
		a[0]='1';
		return a;
	}
	char* b=(char*)malloc(sizeof(char)*2);
	b[0]='1';
	b[1]='\0';
	char* c;
	unsigned int i=2;
	while(i<=n)
	{
		c=intal_add(a,b);
		free(a);
		a=b;
		b=c;
		++i;
	}
	free(a);
	return c;
}
static char* int_to_intal(unsigned int n)
{
	char* a=(char*)malloc(sizeof(char)*5);
	int ind=4;
	a[ind--]='\0';
	while(n>0)
	{
		int d=n%10;
		a[ind]=d+'0';
		--ind;
		n/=10;
	}
	if(ind==-1)
		return a;
	++ind;
	int i=5-ind;
	char* r=(char*)malloc(sizeof(char)*i);
	r[--i]='\0';
	--i;
	while(i>=0)
	{
		r[i]=a[ind+i];
		--i;
	}
	free(a);
	return r;
}
char* intal_factorial(unsigned int n)
{
	char* fact;
	if(n==0 || n==1)
	{
		fact=(char*)malloc(sizeof(char)*2);
		fact[0]='1';
		fact[1]='\0';
	}
	else
	{
		int i=2;
		fact=(char*)malloc(sizeof(char)*2);
		fact[0]='1';
		fact[1]='\0';
		while(i<=n)
		{
			char* num=int_to_intal(i);
			char* prod=intal_multiply(fact,num);
			free(num);
			free(fact);
			fact=prod;
			++i;
		}
	}
	return fact;
}
char* intal_bincoeff(unsigned int n, unsigned int k)
{
	if(k>n/2)
		k=n-k;
	char** dp=(char**)malloc(sizeof(char*)*(k+1));

	for(int i=0;i<k+1;++i)
	{
		dp[i]=(char*)malloc(sizeof(char)*2);
		dp[i][0]='0';
		dp[i][1]='\0';
	}
	dp[0][0]='1';
	for(int i=1;i<=n;++i)
	{
		for(int j=(i<k)?i:k;j>0;--j)
		{
			char* res=intal_add(dp[j],dp[j-1]);
			free(dp[j]);
			dp[j]=res;
		}
	}
	char* r=dp[k];
	for(int i=0;i<k;++i)
        free(dp[i]);
    free(dp);
    return r;
}
int intal_max(char **arr, int n)
{
	char *max_intal=arr[0];
	int offset=0;
	for(int i=1; i<n; ++i)
		if(1==intal_compare(arr[i],max_intal))
		{
			max_intal=arr[i];
			offset=i;
		}
	return offset;
}
int intal_min(char **arr, int n)
{
	char *min_intal=arr[0];
	int offset=0;
	for(int i=1; i<n; ++i)
		if(-1==intal_compare(arr[i],min_intal))
		{
			min_intal=arr[i];
			offset=i;
		}
	return offset;
}
int intal_search(char **arr, int n, const char* key)
{
	int offset=0;
	while(offset<n)
	{
		if(0==intal_compare(arr[offset],key)) return offset;
		++offset;
	}
	return -1;
}
int intal_binsearch(char **arr, int n, const char* key)
{
	int start=0;
	int end=n;
	while(start<=end)
	{
		int mid=(end+start)/2; //since n<1000
		if(0==intal_compare(key,arr[mid]))
		{
			if(mid-1>=0 && 0!=intal_compare(key,arr[mid-1])) return mid;
			else if(0==mid) return 0;
			else
			{
				end=mid-1;
				while(start<=end)
				{
					int mid2=(end+start)/2;
					if(0==intal_compare(key,arr[mid2]))
					{
						if(mid2-1>=0 && 0!=intal_compare(key,arr[mid2-1])) return mid2;
						else if(0==mid2) return 0;
						end=mid2-1;
						mid=mid2;
					}
					else
					{
						for(int i=mid2+1, j=mid-1; i<=j; ++i, --j)
						{
							if(0==intal_compare(key,arr[i]))
								return i;
							if(0!=intal_compare(key,arr[j]))
								return j+1;
						}
					}
				}
			}
		}
		else if(-1==intal_compare(key,arr[mid]))
			end=mid-1;
		else start=mid+1;
	}
	return -1;
}
static void merge(char** arr, int l, int r, int m)
{
    int l1=m-l+1;
    int l2=r-m;
    char** a=(char**)malloc(sizeof(char*)*l1);
    char** b=(char**)malloc(sizeof(char*)*l2);
    for(int i=0;i<l1;++i)
        a[i]=arr[i+l];
    for(int i=0;i<l2;++i)
        b[i]=arr[i+m+1];
    int i=0;
    int j=0;
    int k=l;
    while(i<l1 && j<l2)
    {
        int cmp=intal_compare(a[i],b[j]);
        if(cmp!=1)
        {
            arr[k]=a[i];
            ++i;
        }
        else
        {
            arr[k]=b[j];
            ++j;
        }
        ++k;
    }
    while(i<l1)
    {
    	arr[k]=a[i];
    	++i;
    	++k;
    }
    while(j<l2)
    {
    	arr[k]=b[j];
    	++j;
    	++k;
    }
    free(a);
    free(b);
}
static void merge_sort(char *arr[], int l, int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, r, m);
    }
}
void intal_sort(char **arr, int n)
{
	merge_sort(arr,0,n-1);
}
char* coin_row_problem(char **arr, int n)
{
	char* prev=(char*)malloc(sizeof(char)*2);
		prev[0]='0';
		prev[1]='\0';
	if(n==0)
		return prev;
	char* cur=(char*)malloc(sizeof(char)*(strlen(arr[0])+1));
	strcpy(cur,arr[0]);
	for(int i=2;i<=n;++i)
	{
		char* sum=intal_add(prev,arr[i-1]);
		int comp=intal_compare(sum,cur);
		if(comp!=1)
		{
			free(sum);
			if(prev!=cur)
				free(prev);
			prev=cur;
		}
		else
		{
			if(prev!=cur)
				free(prev);
			prev=cur;
			cur=sum;
		}
	}
	if(prev!=cur)
		free(prev);
	return cur;
}