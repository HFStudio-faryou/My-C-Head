#ifndef __MY_HEAD__ 
#define__MY_HEAD__
#include <stdarg.h>

//宏定义声明区 
int cmp_max(int a,int b);
int cmp_min(int a,int b);
int compare(int (*compare_type)(int,int),int num,...);
int max(int num,...);
int min(int num,...);
int add(int num,...);
int times(int num,...);
 
#endif

//函数编写区
int cmp_max(int a,int b){
	return a>b;
}

int cmp_min(int a,int b){
	return a<b;
}

int compare(int (*compare_type)(int,int),int num,...){
	va_list valist;
	va_start(valist,num);
	int i=0,ans=va_arg(valist,int),tmp;
	while(++i<num){
		tmp=va_arg(valist,int);
		if(compare_type(tmp,ans)) ans=tmp;
	}
	va_end(valist);
	return ans;
}

int max(int num,...){
	va_list valist;
	va_start(valist,num);
	int i=0,ans=va_arg(valist,int),tmp;
	while(++i<num){
		tmp=va_arg(valist,int);
		if(tmp>ans) ans=tmp;
	}
	va_end(valist);
	return ans;
}

int min(int num,...){
	va_list valist;
	va_start(valist,num);
	int i=0,ans=va_arg(valist,int),tmp;
	while(++i<num){
		tmp=va_arg(valist,int);
		if(tmp<ans) ans=tmp;
	}
	va_end(valist);
	return ans;
}

int add(int num,...){
	va_list valist;
	va_start(valist,num);
	int i=0,ans=va_arg(valist,int),tmp;
	while(++i<num) ans+=va_arg(valist,int);
	va_end(valist);
	return ans;
}

int times(int num,...){
	va_list valist;
	va_start(valist,num);
	int i=0,ans=va_arg(valist,int),tmp;
	while(++i<num) ans*=va_arg(valist,int);
	va_end(valist);
	return ans;
}
