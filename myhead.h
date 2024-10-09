#ifndef __MY_HEAD__ 
#define __MY_HEAD__
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
int compare(int (*compare_type)(int,int),int num,...){//多变量比较大小，取最值，参数分别为：比较函数：使用cmp_max、cmp_min或自己根据需求编写；变量总数量；所有变量
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
int max(int num,...){//多变量取最大值，参数分别为：变量数量、所有变量名
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
int min(int num,...){//多变量取最小值，参数分别为：变量数量、所有变量名
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
int add(int num,...){//连加，参数分别为：变量数量、所有变量名
	va_list valist;
	va_start(valist,num);
	int i=0,ans=va_arg(valist,int),tmp;
	while(++i<num) ans+=va_arg(valist,int);
	va_end(valist);
	return ans;
}
int times(int num,...){//连乘，参数分別为：变量数量，所有变量名
	va_list valist;
	va_start(valist,num);
	int i=0,ans=va_arg(valist,int),tmp;
	while(++i<num) ans*=va_arg(valist,int);
	va_end(valist);
	return ans;
}
