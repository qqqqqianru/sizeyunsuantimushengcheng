#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"jieti.h"
#pragma warning(disable:4996)
int gongyueshu(int m, int n)
{
	if (n == 0)n = 1;
	if (m == 0)m = 1;
	int t;
	int x = m;//将最初的m和n的值分别用x和y保存起来，后面计算最小公倍数时需要用到
	int y = n;
	if (m < n) {
		t = m;//t为中间变量，来实现m与n的值的相互交换，保证被除数大于除数
		m = n;
		n = t;
	}
	int r = m % n;
	while (r) {//用n来除以m，直到m被n整除，循环终止，此时r的值为0，在c++中只有0才为假，任何非0的值都判断为真
		m = n;//辗转相除法的核心就是用较大的数m去除较小的数n，如果刚好能整除，则m与n的最大公约数为n，如果不能整除，则将n的值赋给m，余数r赋给n，再进行下一次的相除，以此循环，直到整除为止
		n = r;
		r = m % n;

	}
	return n;
}
int gongbeishu(int m, int n)
{
	int t;
	int x = m;//将最初的m和n的值分别用x和y保存起来，后面计算最小公倍数时需要用到
	int y = n;
	if (m < n) {
		t = m;//t为中间变量，来实现m与n的值的相互交换，保证被除数大于除数
		m = n;
		n = t;
	}
	int r = m % n;
	while (r) {//用n来除以m，直到m被n整除，循环终止，此时r的值为0，在c++中只有0才为假，任何非0的值都判断为真
		m = n;//辗转相除法的核心就是用较大的数m去除较小的数n，如果刚好能整除，则m与n的最大公约数为n，如果不能整除，则将n的值赋给m，余数r赋给n，再进行下一次的相除，以此循环，直到整除为止
		n = r;
		r = m % n;

	}
	return x * y / n;
}

char *calculate(char * timu,int kuohao,int chengfang,int chengchu,int jiajian)//递归计算 四个int变量指示括号、乘方、乘除、加减数量
{
	int len = strlen(timu);
	if (kuohao)
	{
		int lpos = 0,rpos = 0;
		for (int i = 0;i <= len;i++)//有括号时获取括号位置
		{
			if (timu[i] == '(')
			{
				lpos = i;
			}
			if (timu[i] == ')')
			{
				rpos = i;
				break;
			}
		}
		char ret[100];					//要返回的数组
		char newtimu[100];				//要参与递归的数组
		memset(newtimu, '\0', sizeof(newtimu));
		memset(ret, '\0', sizeof(ret));
		for (int i = 0;i < lpos;i++)
		{
			ret[i] = timu[i];
		}
		for (int i = lpos+1;i < rpos;i++)
		{
			newtimu[i-lpos-1] = timu[i];
		}
		kuohao--;
		int kuohao2=0, chengfang2=0, chengchu2=0, jiajian2=0;//统计括号内的运算符
		for (int i = lpos+1;i < rpos ;i++)//获得运算符个数
		{
			if (timu[i] == '+' || timu[i] == '-')
			{
				jiajian2++;
			}
			else if (timu[i] == '*' || timu[i] == '/')
			{
				chengchu2++;
			}
			else if (timu[i] == '^')
			{
				chengfang2++;
			}
			else if (timu[i] == '(')
			{
				kuohao2++;
			}
		}
		strcat(ret, calculate(newtimu, kuohao2, chengfang2, chengchu2, jiajian2));//进行递归
		int retlen = strlen(ret);
		for (int i = 0;i < len - rpos - 1;i++)
		{
			ret[retlen + i] = timu[rpos + i + 1];
		}
		kuohao2 = 0, chengfang2 = 0, chengchu2 = 0, jiajian2 = 0;//统计括号内的运算符
		int t = strlen(ret);
		for (int i = 0;i < t;i++)//获得运算符个数
		{
			if (ret[i] == '+' || ret[i] == '-')
			{
				jiajian2++;
			}
			else if (ret[i] == '*' || ret[i] == '/')
			{
				chengchu2++;
			}
			else if (ret[i] == '^')
			{
				chengfang2++;
			}
			else if (ret[i] == '(')
			{
				kuohao2++;
			}
		}
		return calculate(ret,kuohao2,chengfang2,chengchu2,jiajian2);
	}
	else if (chengfang)
	{
		int cpos = 0;
		char leftnum[10];
		int leftlen = 0;
		memset(leftnum, '\0', sizeof(leftnum));
		int leftstart=-1;//左边数字的起始位置
		for (int i = 0;i <= len;i++)//有乘方时获取乘方位置,并获取乘方符号左边数
		{
			if (timu[i] == '^')
			{
				cpos = i;
				break;
			}
			else if ('0' <= timu[i] && timu[i] <= '9')
			{
				if (leftstart == -1)leftstart = i;
				leftnum[leftlen++] = timu[i];
			}
			else if (timu[i] == '+' || timu[i] == '-' || timu[i] == '*' || timu[i] == '/')
			{
				leftlen = 0;
				leftstart = -1;
				memset(leftnum, '\0', sizeof(leftnum));
			}

		}
		char rightnum[10];
		int rightlen = 0;int rightop = -1;
		memset(rightnum, '\0', sizeof(rightnum));
		for (int i = cpos + 1;i < len;i++)//获取乘方符号右边的数字
		{
			if ('0' <= timu[i] && timu[i] <= '9')
			{
				rightnum[rightlen++] = timu[i];
			}
			else if (timu[i] == '+' || timu[i] == '-' || timu[i] == '*' || timu[i] == '/'||timu[i]=='^')
			{
				rightop = i;
				break;
			}
		}
		
		//进行计算
		int l = atoi(leftnum);int r = atoi(rightnum);int temp = l;
		for (int i = 1;i < r;i++)
			l = l * temp;
		
		char res[100];
		char newtimu[100];
		memset(newtimu, '\0', sizeof(newtimu));
		memset(res, '\0', sizeof(res));

		itoa(l,res,10);
		if ((!(jiajian)) && (!(chengchu)))return res;
		for (int i = 0;i < leftstart;i++)
		{
			newtimu[i] = timu[i];
		}
		strcat(newtimu, res);
		if (rightop != -1)
		{
			int newtimulen = strlen(newtimu);
			for (int i = 0;i < len - rightop;i++)
			{
				newtimu[newtimulen + i] = timu[rightop + i];		//计算完成确定新题目
			}
		}
		//乘方数量减一进行递归
		chengfang--;
		return calculate(newtimu, kuohao, chengfang, chengchu, jiajian);
	}
	else if (chengchu)
	{
	int cpos = 0;
	int op = -1;//op代表乘或除
	char leftnum[10];
	int leftlen = 0;
	memset(leftnum, '\0', sizeof(leftnum));
	int leftstart = -1;//左边数字的起始位置
	for (int i = 0;i <= len;i++)//有乘除时获取乘除位置,并获取符号左边数
	{
		if (timu[i] == '*')
		{
			cpos = i;
			op = 1;
			break;
		}
		else if (timu[i] == '/')
		{
			cpos = i;
			op = 2;
			break;
		}
		else if ('0' <= timu[i] && timu[i] <= '9')
		{
			if (leftstart == -1)leftstart = i;
			leftnum[leftlen++] = timu[i];
		}
		else if (timu[i] == '+' || timu[i] == '-'||timu[i]=='#' )
		{
			leftlen = 0;
			leftstart = -1;
			memset(leftnum, '\0', sizeof(leftnum));
		}
	}
	char rightnum[10];
	int rightlen = 0;int rightop = -1;
	memset(rightnum, '\0', sizeof(rightnum));
	int fu = 0;
	for (int i = cpos + 1;i < len;i++)//获取符号右边的数字
	{
		if ('0' <= timu[i] && timu[i] <= '9')
		{
			rightnum[rightlen++] = timu[i];
		}
		else if (timu[i] == '+' || timu[i] == '-' || timu[i] == '*' || timu[i] == '/' || timu[i] == '^')
		{
			if (i == cpos + 1)
			{
				fu = 1;
			}
			else
			{
				rightop = i;
				break;
			}
		}
	}

	//进行计算
	char res[100];
	memset(res, '\0', sizeof(res));
	char newtimu[100];
	memset(newtimu, '\0', sizeof(newtimu));
	int l = atoi(leftnum);
	int r = atoi(rightnum);
	int result = 0;
	if (leftstart == 0)//左边运算数在开头，不需考虑分数
	{
		if (op == 1)
		{
			result = l * r;
			itoa(result, res, 10);
			for (int i = 0;i < leftstart;i++)
			{
				newtimu[i] = timu[i];
			}
			if (fu == 1)
			{
				char t[2] = { "-" };
				strcat(newtimu, t);
			}
			strcat(newtimu, res);
			if (rightop != -1)
			{
				int newtimulen = strlen(newtimu);
				for (int i = 0;i < len - rightop;i++)
				{
					newtimu[newtimulen + i] = timu[rightop + i];		//计算完成确定新题目
				}
			}
			return calculate(newtimu, kuohao, chengfang, chengchu - 1, jiajian);
		}
		else
		{
			if (l%r == 0)//能除尽 直接计算
			{
				result = l / r;
				itoa(result, res, 10);
				for (int i = 0;i < leftstart;i++)
				{
					newtimu[i] = timu[i];
				}
				if (fu == 1)
				{
					char t[2] = { "-" };
					strcat(newtimu, t);
				}
				strcat(newtimu, res);
				if (rightop != -1)
				{
					int newtimulen = strlen(newtimu);
					for (int i = 0;i < len - rightop;i++)
					{
						newtimu[newtimulen + i] = timu[rightop + i];		//计算完成确定新题目
					}
				}
				return calculate(newtimu, kuohao, chengfang, chengchu - 1, jiajian);

			}
			else//不能除尽，化为分数
			{
				timu[cpos] = '#';//以#号代表不能除尽的分数
				char newtimu[100];
				memset(newtimu, '\0', sizeof(newtimu));
				strcpy(newtimu, timu);
				return calculate(newtimu, kuohao, chengfang, chengchu-1, jiajian);
			}
		}
	}
	else//需要考虑运算符左边是否为分数，由于顺序运算，不需考虑右边是否为分数
	{
		if (timu[leftstart - 1] == '#')
		{
			char leftfenzi[10];int fenzistart = -1,fenzilen = 0;//获得分子的值和起始位置
			memset(leftfenzi, '\0', sizeof(leftfenzi));
			for (int i = 0;i < leftstart - 1;i++)
			{
				if ('0' <= timu[i] && timu[i] <= '9')
				{
					if (fenzistart == -1)fenzistart = i;
					leftfenzi[fenzilen++] = timu[i];
				}
				else if (timu[i] == '+' || timu[i] == '-')
				{
					fenzilen = 0;
					fenzistart = -1;
					memset(leftfenzi, '\0', sizeof(leftfenzi));
				}
			}
			int fenzi = atoi(leftfenzi);

			if (op == 1)//乘
			{
				fenzi = fenzi * r;
				itoa(fenzi, res, 10);
				for (int i = 0;i < fenzistart; i++)
				{
					newtimu[i] = timu[i];
				}
				if (fu == 1)
				{
					char t[2] = { "-" };
					strcat(newtimu, t);
				}
				strcat(newtimu, res);
				strcat(newtimu, "#");
				itoa(l, res, 10);
				strcat(newtimu, res);
				int newtimulen = strlen(newtimu);
				if (rightop != -1)
				{
					for (int i = rightop;i < len;i++)
					{
						newtimu[newtimulen++] = timu[i];
					}
				}
				return calculate(newtimu, kuohao, chengfang, chengchu - 1, jiajian);
			}
			else//除
			{
				l = l * r;
				itoa(fenzi, res, 10);
				for (int i = 0;i < fenzistart; i++)
				{
					newtimu[i] = timu[i];
				}
				if (fu == 1)
				{
					char t[2] = { "-" };
					strcat(newtimu, t);
				}
				strcat(newtimu, res);
				strcat(newtimu, "#");
				itoa(l, res, 10);
				strcat(newtimu, res);
				int newtimulen = strlen(newtimu);
				if (rightop != -1)
				{
					for (int i = rightop;i < len;i++)
					{
						newtimu[newtimulen++] = timu[i];
					}
				}
				return calculate(newtimu, kuohao, chengfang, chengchu - 1, jiajian);
			}

		}
		else
		{
			if (op == 1)
			{
				result = l * r;
				itoa(result, res, 10);
				for (int i = 0;i < leftstart;i++)
				{
					newtimu[i] = timu[i];
				}
				if (fu == 1)
				{
					char t[2] = { "-" };
					strcat(newtimu, t);
				}
				strcat(newtimu, res);
				if (rightop != -1)
				{
					int newtimulen = strlen(newtimu);
					for (int i = 0;i < len - rightop;i++)
					{
						newtimu[newtimulen + i] = timu[rightop + i];		//计算完成确定新题目
					}
				}
				return calculate(newtimu, kuohao, chengfang, chengchu-1, jiajian);
			}
			else
			{
				if (l%r == 0)//能除尽 直接计算
				{
					result = l / r;
					itoa(result, res, 10);
					for (int i = 0;i < leftstart;i++)
					{
						newtimu[i] = timu[i];
					}
					if (fu == 1)
					{
						char t[2] = { "-" };
						strcat(newtimu, t);
					}
					strcat(newtimu, res);
					if (rightop != -1)
					{
						int newtimulen = strlen(newtimu);
						for (int i = 0;i < len - rightop;i++)
						{
							newtimu[newtimulen + i] = timu[rightop + i];		//计算完成确定新题目
						}
					}
				}
				else//不能除尽，化为分数
				{
					timu[cpos] = '#';//以#号代表不能除尽的分数
					char newtimu[100];
					memset(newtimu, '\0', sizeof(newtimu));
					strcpy(newtimu, timu);
					chengchu--;
					return calculate(newtimu, kuohao, chengfang, chengchu, jiajian);
				}
			}
		}
	}

	}
	else if (jiajian)
	{
		int fu=0;//首数字是否为负
		int jpos = 0;//加减运算符位置
		int op = 0;//加或减
		int zm = 1;//指示正在读的数为分子还是分母
		int fz1 = 0, fz2 = 1, fm1 = 1, fm2 = 1;
		char num1[20], num2[20];
		int endpos = 0;
		int len1=0, len2=0,len3=0,len4=0;
		memset(num1, '\0', sizeof(num1));
		memset(num2, '\0', sizeof(num2));
		for (int i = 0;i < len;i++)//该循环读取第一个操作数
		{
			if (timu[i] == '-'||timu[i]=='+')
			{
				if (i == 0)
				{
					fu = 1;
					if (jiajian == 1)
					{
						char newtimu[100];
						memset(newtimu, '\0', sizeof(newtimu));
						for (int i = 0;i < len;i++)
						{
							newtimu[i] = timu[i];

						}
						return calculate(newtimu, kuohao, chengfang, chengchu, jiajian - 1);
					}
				}
				else 
				{
					if (timu[i] == '+')op = 1;
					if (timu[i] == '-')op = 2;
					jpos = i;
					break;
				}
			}
			else if (timu[i] >= '0'&&timu[i] <= '9')
			{
				if (zm == 1)
				{
					num1[len1++] = timu[i];
				}
				else
				{
					num2[len2++] = timu[i];
				}
			}
			else if (timu[i] == '#')
			{
				zm = 2;
			}
		}

		fz1 = atoi(num1);
		if (num2[0] == '\0')
		{
			len2 = 1;
		}
		else
		{
			fm1 = atoi(num2);
		}
		zm = 1;
		memset(num1, '\0', sizeof(num1));
		memset(num2, '\0', sizeof(num2));
		for (int i = jpos + 1;i < len;i++)//该循环读取第二个操作数
		{
			if (timu[i] >= '0'&&timu[i] <= '9')
			{
				if (zm == 1)
				{
					num1[len3++] = timu[i];
				}
				else
				{
					num2[len4++] = timu[i];
				}
			}
			else if (timu[i] == '#')
			{
				zm = 2;
			}
			else if (timu[i] == '-'||timu[i] == '+')
			{

				endpos = i;
				break;
			}
		}
		fz2 = atoi(num1);
		if (num2[0] == '\0')
		{
			;
		}
		else
		{
			fm2 = atoi(num2);
		}
		int newfm = gongbeishu(fm1, fm2);
		fz1 = fz1 * (newfm / fm1);
		fz2 = fz2 * (newfm / fm2);
		int newfz;
		if (fu == 1)
			fz1 = -fz1;
		if (op == 2)
			fz2 = -fz2;
		newfz= fz1 + fz2;
		if (newfz < 0)
		{
			fu = 1;
			newfz = -newfz;
		}
		int gys = gongyueshu(newfz, newfm);
		if (gys != 1)
		{
			newfz = newfz / gys;
			newfm = newfm / gys;
		}
		char newtimu[100];
		memset(newtimu, '\0', sizeof(newtimu));
		memset(num1, '\0', sizeof(num1));
		if (fu == 1)
		{
			newtimu[0] = '-';
		}
		itoa(newfz, num1, 10);
		strcat(newtimu, num1);
		int t = strlen(newtimu);
		if (newfm != 1)
		{
			
			newtimu[t] = '#';
			memset(num1, '\0', sizeof(num1));
			itoa(newfm, num1, 10);
			strcat(newtimu, num1);
		}
		t = strlen(newtimu);
		if (endpos != 0)
		{
			for (int i = 0;i < len-endpos;i++)
			{
				newtimu[t +  i] = timu[endpos+i];
			}
		}
		t = strlen(newtimu);
		int newjiajian=0;
		for (int i = 0;i < t;i++)
		{
			if (newtimu[i] == '+' || newtimu[i] == '-')
				newjiajian++;
		}
		return calculate(newtimu, kuohao, chengfang, chengchu, newjiajian);
		
	}
	else
	{
	int fen = 0;
	int fu = 0;
	if (timu[0] == '-')
	{
		fu = 1;
	}

		for (int i = 1;i < len;i++)
		{
			if (timu[i] == '#')
			{
				fen = i;break;
			}
		}
		if (fen !=0)
		{
			char fenzi[20], fenmu[20];
			memset(fenzi, '\0', sizeof(fenzi));
			memset(fenmu, '\0', sizeof(fenmu));
			char newtimu[100];
			memset(newtimu, '\0', sizeof(newtimu));
			if (fu)
			{
				for (int i = 1;i < fen;i++)
					fenzi[i-1] = timu[i];
			}
			else
			{
				for (int i = 0;i < fen;i++)
					fenzi[i] = timu[i];
			}
			for (int i = fen + 1;i < len;i++)
			{
				fenmu[i - fen - 1] = timu[i];
			}
			int zi = atoi(fenzi), mu = atoi(fenmu);
			int gys = gongyueshu(zi, mu);
			zi = zi / gys;
			mu = mu / gys;
			memset(fenzi, '\0', sizeof(fenzi));
			memset(fenmu, '\0', sizeof(fenmu));
			itoa(zi, fenzi, 10);
			itoa(mu, fenmu, 10);
			char chu[2];
			chu[0] = '/';chu[1] = '\0';

			if (fu)
			{
				newtimu[0] = '-';
			}
			strcat(newtimu, fenzi);
			strcat(newtimu, chu);
			strcat(newtimu, fenmu);
			return newtimu;
		}
		else return timu;
	}
}

char * jieti(int mode,char *timu)
{
	char newtimu[100];
	memset(newtimu, '\0', sizeof(newtimu));
	int len = strlen(timu);
	int kuohao = 0, chengfang = 0, chengchu = 0,jiajian=0;
	if (mode == 2)//如果以**表示乘方则转化为^
	{
		for (int i = 0;i < len;i++)
		{
			if (timu[i] == '*'&&timu[i + 1] == '*')
			{
				timu[i] = '^';
				timu[i + 1] = ' ';
			}
		}
	}
	for (int i = 0;i < len ;i++)//获得运算符个数
	{
		if (timu[i] == '+'||timu[i]=='-')
		{
			jiajian++;
		}
		else if(timu[i] == '*' || timu[i] == '/')
		{
			chengchu++;
		}
		else if (timu[i] == '^')
		{
			chengfang++;
		}
		else if (timu[i] == '(')
		{
			kuohao++;
		}
		newtimu[i] = timu[i];
	}
	return calculate(newtimu,kuohao,chengfang,chengchu,jiajian);//递归计算

}
