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
		cout << "命令行参数格式错误！" << endl;
		cout << "请输入两个参数，第一个为出题数量（1000以内），第二个为乘方表示形式（1表示^，2表示**）" << endl;
		return 0;
	}
	int a1len = strlen(argv[1]);
	for (int i = 0;i < a1len;i++)
	{
		if (!('0' <= argv[1][i]&&  argv[1][i] <= '9'))
		{
			cout << "参数1错误，请输入数字" << endl;
			return 0;
		}
	}
	int a1num = atoi(argv[1]);
	if (!(0 < a1num <= 1000))
	{
		cout << "参数1错误，出题数量应为1-1000之内的整数" << endl;
		return 0;
	}
	if (strlen(argv[2]) != 1)
	{
		cout<<"参数2长度错误，请输入1或2"<<endl;
		return 0;
	}
	if (!(argv[2][0] == '1' || argv[2][0] == '2'))
	{
		cout<<"参数2数值错误，请输入1或2"<<endl;
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
		cout<<"请输入你的答案"<<endl;
		cin >> answer;
		getchar();
		
		if (strcmp(correct, answer))
		{
			x+=1;
			cout<<"答案错误"<<endl;
			cout << "正确答案为" <<correct<< endl;
		}
		else
		{
			v += 1;
			cout << "答案正确" << endl;
		}
	}
	cout<<"答题完成"<<endl;
	cout<<"正确数："<<v<<"错误数："<<x<<endl;
	double lv = v / (v + x);
	cout << "正确率：" << lv << endl;
	system("pause");
	return 0;
}