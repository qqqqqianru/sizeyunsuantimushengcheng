#include<iostream>
#include<stdio.h>
#include<fstream>
#include<ctime>
#include<stdlib.h>
#include<time.h>
using namespace std;

char* chuti(int a)
{
	double nums[100];
	srand((unsigned)time(NULL));
	char str[100];

	char chuti[3000];
	memset(chuti, '\0', sizeof(chuti));
	int ii = 0;

	int   flag, q = 1;

	int pos1 = -1,        ///pos1,pos2为括号位置

		pos2 = -1;

	if (a == 1)
	{
		int dd, ee, ff, gg;

		str[0] = '+';
		str[1] = '-';
		str[2] = '*';
		str[3] = '/';

		flag = rand() % 5 + 2;

		int aa;
		aa = 0;
		int bb;
		bb = rand() % flag - 1;

		int cc = -1;






		for (int i = 0; i < flag; i++)

		{
			nums[i] = rand() % 20 + 1;
		}

		pos1 = -1;

		pos2 = -1;



		while (1)

		{

			pos1 = rand() % flag;

			pos2 = rand() % flag;

			if (abs(pos1 - pos2))//绝对值 

			{
				if (pos1 > pos2)
				{
					int t = pos1;
					pos1 = pos2;
					pos2 = t;
				}


				break;

			}

		}

		if (flag == 2)

		{

			pos1 = -1;

			pos2 = -1;

		}

		//ofile<<"(" << q << ")"<< "  ";

		//cout << "(" << q++ << ")"<< "  ";

		for (int i = 0; i < flag; i++)

		{

			int k = rand() % 4;

			if (i == pos1 && pos1 != pos2)

			{
				if (pos1 != 0 || pos2 != flag - 1)
				{
					cout << "(" << " ";

					chuti[ii] = '(';
					ii++;

					//ofile<<"("<<" ";
				}

			}

			cout << nums[i] << " ";
			if (nums[i] < 10)
			{
				chuti[ii] = nums[i] + 48;
				ii++;
			}
			else
			{
				gg = nums[i];
				chuti[ii] = nums[i] / 10 + 48;
				ii++;
				ff = gg % 10;
				chuti[ii] = ff + 48;
				ii++;
			}

			//ofile<<nums[i]<<" ";

			if (i == pos2 && pos1 != pos2)

			{
				if (pos1 != 0 || pos2 != flag - 1)
				{
					int dd = rand() % 3 + 2;
					cout << "^" << " " << dd << " ";
					chuti[ii] = '^';
					ii++;
					chuti[ii] = dd + 48;
					ii++;




					aa = 1;
					cout << ")" << " ";
					chuti[ii] = ')';
					ii++;
					//ofile<<")"<<" ";
				}

			}

			if (aa == 0)
			{
				if (i == bb)
				{
					ee = rand() % 3 + 2;
					cout << "^" << " " << ee << " ";
					chuti[ii] = '^';
					ii++;
					chuti[ii] = ee + 48;
					ii++;
				}


			}

			if (i != flag - 1)

			{

				cout << str[k] << " ";
				chuti[ii] = str[k];
				ii++;

				//ofile<<str[k]<<" ";

			}

		}

		cout << endl;
	}

	else
	{
		int dd, ee, ff, gg;

		str[0] = '+';
		str[1] = '-';
		str[2] = '*';
		str[3] = '/';

		flag = rand() % 3 + 2;

		int aa;
		aa = 0;
		int bb;
		bb = rand() % flag - 1;

		int cc = -1;






		for (int i = 0; i < flag; i++)

		{
			nums[i] = rand() % 20 + 1;
		}

		pos1 = -1;

		pos2 = -1;



		while (1)

		{

			pos1 = rand() % flag;

			pos2 = rand() % flag;

			if (abs(pos1 - pos2))//绝对值 

			{

				if (pos1 > pos2)
				{
					int t = pos1;
					pos1 = pos2;
					pos2 = t;
				}
				break;

			}

		}

		if (flag == 2)

		{

			pos1 = -1;

			pos2 = -1;

		}

		//ofile<<"(" << q << ")"<< "  ";

		//cout << "(" << q++ << ")"<< "  ";

		for (int i = 0; i < flag; i++)

		{

			int k = rand() % 4;

			if (i == pos1 && pos1 != pos2)

			{
				if (pos1 != 0 || pos2 != flag - 1)
				{
					cout << "(" << " ";
					chuti[ii] = '(';
					ii++;

					//ofile<<"("<<" ";
				}

			}

			cout << nums[i] << " ";
			if (nums[i] < 10)
			{
				chuti[ii] = nums[i] + 48;
				ii++;
			}
			else
			{
				gg = nums[i];
				chuti[ii] = nums[i] / 10 + 48;
				ii++;
				ff = gg % 10;
				chuti[ii] = ff + 48;
				ii++;
			}

			//ofile<<nums[i]<<" ";

			if (i == pos2 && pos1 != pos2)

			{
				if (pos1 != 0 || pos2 != flag - 1)
				{
					int dd = rand() % 3 + 2;
					cout << "**" << " " << dd << " ";
					chuti[ii] = '*';
					ii++;
					chuti[ii] = '*';
					ii++;
					chuti[ii] = dd + 48;
					ii++;




					aa = 1;
					cout << ")" << " ";
					chuti[ii] = ')';
					ii++;
					//ofile<<")"<<" ";
				}

			}

			if (aa == 0)
			{
				if (i == bb)
				{
					ee = rand() % 3 + 2;
					cout << "**" << " " << ee << " ";
					chuti[ii] = '*';
					ii++;
					chuti[ii] = '*';
					ii++;
					chuti[ii] = ee + 48;
					ii++;
				}


			}

			if (i != flag - 1)

			{

				cout << str[k] << " ";
				chuti[ii] = str[k];
				ii++;

				//ofile<<str[k]<<" ";

			}

		}

		cout << endl;
	}

	
	return chuti;


}
