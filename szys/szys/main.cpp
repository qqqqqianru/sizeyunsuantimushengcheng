#include<iostream>
#include<stdio.h>
#include<fstream>
#include<ctime>
#include<stdlib.h>
#include"chuti.cpp"
#include"jieti.cpp"
#include"save.cpp"
using namespace std;
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		cout << "�����в�����ʽ����" << endl;
		cout << "������������������һ��Ϊ����������1000���ڣ����ڶ���Ϊ�˷���ʾ��ʽ��1��ʾ^��2��ʾ**��" << endl;
		return 0;
	}
	int a1len = strlen(argv[1]);
	for (int i = 0;i < a1len;i++)
	{
		if (!('0' <= argv[1][i]&&  argv[1][i] <= '9'))
		{
			cout << "����1��������������" << endl;
			return 0;
		}
	}
	int a1num = atoi(argv[1]);
	if (!(0 < a1num <= 1000))
	{
		cout << "����1���󣬳�������ӦΪ1-1000֮�ڵ�����" << endl;
		return 0;
	}
	if (strlen(argv[2]) != 1)
	{
		cout<<"����2���ȴ���������1��2"<<endl;
		return 0;
	}
	if (!(argv[2][0] == '1' || argv[2][0] == '2'))
	{
		cout<<"����2��ֵ����������1��2"<<endl;
		return 0;
	}
	int a2num = atoi(argv[2]);
	double v = 0, x = 0;

	/*char timu[100] = {"1*1/2^1"};
	char *correct = jieti(a2num, timu);
	cout << timu << endl;
	cout << correct << endl;*/


	for (int i = 1;i <= a1num;i++)
	{
		char *timu = (char *)malloc(sizeof(char) * 100);
		timu= chuti(a2num);
		//save(timu);
		char *correct= jieti(a2num, timu);
		char answer[100];
		cout<<"��������Ĵ�"<<endl;
		cin >> answer;
		getchar();
		
		if (strcmp(correct, answer))
		{
			x+=1;
			cout<<"�𰸴���"<<endl;
			cout << "��ȷ��Ϊ" <<correct<< endl;
		}
		else
		{
			v += 1;
			cout << "����ȷ" << endl;
		}
	}
	cout<<"�������"<<endl;
	cout<<"��ȷ����"<<v<<"��������"<<x<<endl;
	double lv = v / (v + x);
	cout << "��ȷ�ʣ�" << lv << endl;
	system("pause");
	return 0;
}