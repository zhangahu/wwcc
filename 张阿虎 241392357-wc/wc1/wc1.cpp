// wc1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

int _tmain(int argc, _TCHAR* argv[])
{
	//d:\\Program.cs
	char s[1024];
	char str[1024];
	int zline=0;
	int wline=0;
	int kline=0;
	int k=1,c=0;
	printf("�������ļ���ַ:\n");
	gets(s);
	FILE *fp=fopen(s,"r");
	while(!feof(fp))
	{
		fgets(str,1024,fp);
		if(str !="")
		{
			if(k==0 && c!=zline)
			{
				wline++;
			}
			zline++;
		}
		for(int i=0;i<1023;i++)
		{
			if(str[i]=='/' && str[i+1]=='/')
			{
				wline++;
			}
			else if(str[i]=='/' && str[i+1]=='*')
			{
				c=zline;
				k=0;
				wline++;
			}
			else if(str[i]=='*' && str[i+1]=='/')
			{
				k=1;
				wline++;
			}
			if(str[i]=='{' && str[i+1]=='\n')
			{
				kline++;
				break;
			}
			else if(str[i]=='}' && str[i+1]=='\n')
			{
				kline++;
				break;
			}
			else if(str[i]==' ' && str[i+1]=='\n')
			{
				kline++;
				break;
			}
		}
	}
	printf("������%d\n",zline);
	printf("������%d\n",kline);
	printf("ע������%d\n",wline);
	printf("��������%d\n",zline-kline-wline);
	return 0;
}