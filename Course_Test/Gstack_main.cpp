#include <iostream>
#include <stdio.h>
#include "Gstack.h"

using namespace std;

#include <iostream>
#include <string.h>
#include "gstack.h"

using namespace std;

// + - * / ( ) \0
static char OPTR_PRI[7][7] =
{
	/* + */	'>', '>', '<', '<', '<', '>', '>',
	/* - */	'>', '>', '<', '<', '<', '>', '>',
	/* * */	'>', '>', '>', '>', '<', '>', '>',
	/* / */	'>', '>', '>', '>', '<', '>', '>',
	/* ( */	'<', '<', '<', '<', '<', '=', 'x',
	/* ) */	'>', '>', '>', '>', 'x', '>', '>',
	/* 0 */	'<', '<', '<', '<', '<', 'x', '='
};//�ж����ȼ�

//����->���֣�������char���������������⣩
char getOptrCode(char c)
{
	switch (c)
	{
	case '+':	return 0;
	case '-':	return 1;
	case '*':	return 2;
	case '/':	return 3;
	case '(':	return 4;
	case ')':	return 5;
	case '\0':	return 6;
	default:	return -1;
	}
}

// ������������������Ľ��
double calc(char op, double d1, double d2)
{
	switch (op)
	{
	case 0:		return d1 + d2;
	case 1:		return d1 - d2;
	case 2:		return d1 * d2;
	case 3:		return d1 / d2;
	default:	return 0;
	}
}
//�õ�������ջ���´ο�ʼ��λ��
int getOpnd(const char* express, int ip, double& d)
{
	int i, j;
	char c;
	bool isFirst = true;
	char str[256] = { 0 };

	for (i = ip, j = 0; express[i] != '\0'; i++)
	{
		c = express[i];
		if (isdigit(c)) str[j++] = c;
		else if (c == '.')
		{
			if (isFirst)
			{
				str[j++] = c;
				isFirst = false;
			}
			else break;
		}
		else break;
	}
	str[j] = '\0';
	d = atof(str);
	return ip + j;
}

// ����ɱ��ʽ��ֵ����, ��������ɹ�����0, ���ҽ����ʽ��ֵ����v��
int eval(const char* express, double& v/*���*/)
{
	int ip;//���ʽexpress��ʼλ��
	char c, op;
	double d, d1, d2;
	GStack<double> opnd;//����ջ
	GStack<char> optr;//����ջ

	v = 0;
	ip = 0;
	optr.push(1);//�����жϷ����Ƿ�ȫ����ջ
	c = express[ip];

	while (optr.top() != 1 || c != '\0')
	{
		if (isdigit(c))//isdigit()�ж��Ƿ�������
		{
			ip = getOpnd(express, ip, d);
			opnd.push(d);
			c = express[ip];
		}
		else
		{
			op = getOptrCode(c);
			if (op < 0)
			{
				cout << "�޷�ʶ��������: " << express[ip] << endl;
				return -1;
			}

			switch (OPTR_PRI[optr.top()][op])
			{
			case '<':	optr.push(op);
				c = express[++ip];
				break;
			case '=':	optr.pop();
				c = express[++ip];
				break;
			case '>':	op = optr.pop();
				d2 = opnd.pop();
				d1 = opnd.pop();
				d = calc(op, d1, d2);
				opnd.push(d);
				break;
			case 'x':	cout << "�������ϵ����!" << endl;
				return -2;
			}
		}
	}

	v = opnd.top();
	return 0;
}

int main(int argc, char* argv[])
{
	double v;
	char express[] = "2*1*3";
	//char express[256] = "";
	//printf("Please input express\n");
	//scanf("%s", express);
	if (eval(express, v) == 0)
	{
		cout << express << " = " << v << endl;
	}
	return EXIT_SUCCESS;
}