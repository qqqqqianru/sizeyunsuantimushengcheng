#include<iostream>
#include<stdlib.h>
#pragma warning (disable:4996)
void save(char *timu)
{
	char t[100];
	memset(t, '\0', sizeof(t));
	FILE *p;
	int len = strlen(timu);
	for (int i = 0;i < len;i++)
	{
		t[i] = timu[i];
	}
	if ((p = fopen("E:\\data.txt","wt")) != NULL);
	for (int i = 0;i < len;i++)
	{
		fprintf(p, "%c", t[i]);
	}
	fclose(p);
	return;
}