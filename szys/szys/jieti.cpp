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
	int x = m;//�������m��n��ֵ�ֱ���x��y�������������������С������ʱ��Ҫ�õ�
	int y = n;
	if (m < n) {
		t = m;//tΪ�м��������ʵ��m��n��ֵ���໥��������֤���������ڳ���
		m = n;
		n = t;
	}
	int r = m % n;
	while (r) {//��n������m��ֱ��m��n������ѭ����ֹ����ʱr��ֵΪ0����c++��ֻ��0��Ϊ�٣��κη�0��ֵ���ж�Ϊ��
		m = n;//շת������ĺ��ľ����ýϴ����mȥ����С����n������պ�����������m��n�����Լ��Ϊn�����������������n��ֵ����m������r����n���ٽ�����һ�ε�������Դ�ѭ����ֱ������Ϊֹ
		n = r;
		r = m % n;

	}
	return n;
}
int gongbeishu(int m, int n)
{
	int t;
	int x = m;//�������m��n��ֵ�ֱ���x��y�������������������С������ʱ��Ҫ�õ�
	int y = n;
	if (m < n) {
		t = m;//tΪ�м��������ʵ��m��n��ֵ���໥��������֤���������ڳ���
		m = n;
		n = t;
	}
	int r = m % n;
	while (r) {//��n������m��ֱ��m��n������ѭ����ֹ����ʱr��ֵΪ0����c++��ֻ��0��Ϊ�٣��κη�0��ֵ���ж�Ϊ��
		m = n;//շת������ĺ��ľ����ýϴ����mȥ����С����n������պ�����������m��n�����Լ��Ϊn�����������������n��ֵ����m������r����n���ٽ�����һ�ε�������Դ�ѭ����ֱ������Ϊֹ
		n = r;
		r = m % n;

	}
	return x * y / n;
}

char *calculate(char * timu,int kuohao,int chengfang,int chengchu,int jiajian)//�ݹ���� �ĸ�int����ָʾ���š��˷����˳����Ӽ�����
{
	int len = strlen(timu);
	if (kuohao)
	{
		int lpos = 0,rpos = 0;
		for (int i = 0;i <= len;i++)//������ʱ��ȡ����λ��
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
		char ret[100];					//Ҫ���ص�����
		char newtimu[100];				//Ҫ����ݹ������
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
		int kuohao2=0, chengfang2=0, chengchu2=0, jiajian2=0;//ͳ�������ڵ������
		for (int i = lpos+1;i < rpos ;i++)//������������
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
		strcat(ret, calculate(newtimu, kuohao2, chengfang2, chengchu2, jiajian2));//���еݹ�
		int retlen = strlen(ret);
		for (int i = 0;i < len - rpos - 1;i++)
		{
			ret[retlen + i] = timu[rpos + i + 1];
		}
		kuohao2 = 0, chengfang2 = 0, chengchu2 = 0, jiajian2 = 0;//ͳ�������ڵ������
		int t = strlen(ret);
		for (int i = 0;i < t;i++)//������������
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
		int leftstart=-1;//������ֵ���ʼλ��
		for (int i = 0;i <= len;i++)//�г˷�ʱ��ȡ�˷�λ��,����ȡ�˷����������
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
		for (int i = cpos + 1;i < len;i++)//��ȡ�˷������ұߵ�����
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
		
		//���м���
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
				newtimu[newtimulen + i] = timu[rightop + i];		//�������ȷ������Ŀ
			}
		}
		//�˷�������һ���еݹ�
		chengfang--;
		return calculate(newtimu, kuohao, chengfang, chengchu, jiajian);
	}
	else if (chengchu)
	{
	int cpos = 0;
	int op = -1;//op����˻��
	char leftnum[10];
	int leftlen = 0;
	memset(leftnum, '\0', sizeof(leftnum));
	int leftstart = -1;//������ֵ���ʼλ��
	for (int i = 0;i <= len;i++)//�г˳�ʱ��ȡ�˳�λ��,����ȡ���������
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
	for (int i = cpos + 1;i < len;i++)//��ȡ�����ұߵ�����
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

	//���м���
	char res[100];
	memset(res, '\0', sizeof(res));
	char newtimu[100];
	memset(newtimu, '\0', sizeof(newtimu));
	int l = atoi(leftnum);
	int r = atoi(rightnum);
	int result = 0;
	if (leftstart == 0)//����������ڿ�ͷ�����迼�Ƿ���
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
					newtimu[newtimulen + i] = timu[rightop + i];		//�������ȷ������Ŀ
				}
			}
			return calculate(newtimu, kuohao, chengfang, chengchu - 1, jiajian);
		}
		else
		{
			if (l%r == 0)//�ܳ��� ֱ�Ӽ���
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
						newtimu[newtimulen + i] = timu[rightop + i];		//�������ȷ������Ŀ
					}
				}
				return calculate(newtimu, kuohao, chengfang, chengchu - 1, jiajian);

			}
			else//���ܳ�������Ϊ����
			{
				timu[cpos] = '#';//��#�Ŵ����ܳ����ķ���
				char newtimu[100];
				memset(newtimu, '\0', sizeof(newtimu));
				strcpy(newtimu, timu);
				return calculate(newtimu, kuohao, chengfang, chengchu-1, jiajian);
			}
		}
	}
	else//��Ҫ�������������Ƿ�Ϊ����������˳�����㣬���迼���ұ��Ƿ�Ϊ����
	{
		if (timu[leftstart - 1] == '#')
		{
			char leftfenzi[10];int fenzistart = -1,fenzilen = 0;//��÷��ӵ�ֵ����ʼλ��
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

			if (op == 1)//��
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
			else//��
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
						newtimu[newtimulen + i] = timu[rightop + i];		//�������ȷ������Ŀ
					}
				}
				return calculate(newtimu, kuohao, chengfang, chengchu-1, jiajian);
			}
			else
			{
				if (l%r == 0)//�ܳ��� ֱ�Ӽ���
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
							newtimu[newtimulen + i] = timu[rightop + i];		//�������ȷ������Ŀ
						}
					}
				}
				else//���ܳ�������Ϊ����
				{
					timu[cpos] = '#';//��#�Ŵ����ܳ����ķ���
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
		int fu=0;//�������Ƿ�Ϊ��
		int jpos = 0;//�Ӽ������λ��
		int op = 0;//�ӻ��
		int zm = 1;//ָʾ���ڶ�����Ϊ���ӻ��Ƿ�ĸ
		int fz1 = 0, fz2 = 1, fm1 = 1, fm2 = 1;
		char num1[20], num2[20];
		int endpos = 0;
		int len1=0, len2=0,len3=0,len4=0;
		memset(num1, '\0', sizeof(num1));
		memset(num2, '\0', sizeof(num2));
		for (int i = 0;i < len;i++)//��ѭ����ȡ��һ��������
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
		for (int i = jpos + 1;i < len;i++)//��ѭ����ȡ�ڶ���������
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
	if (mode == 2)//�����**��ʾ�˷���ת��Ϊ^
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
	for (int i = 0;i < len ;i++)//������������
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
	return calculate(newtimu,kuohao,chengfang,chengchu,jiajian);//�ݹ����

}
