#include <iostream>
#include <stdio.h>
#include "gstack.h"

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
};

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

// 计算两个操作数运算的结果
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

int eval(const char* express, double& v)
{
	int ip;
	char c, op;
	double d, d1, d2;
	GStack<double> opnd;
	GStack<char> optr;

	v = 0;
	ip = 0;
	optr.push(6);
	c = express[ip];

	while (optr.top() != 6 || c != '\0')
	{
		if (isdigit(c))
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
				cout << "无法识别的运算符: " << express[ip] << endl;
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
			case 'x':	cout << "运算符关系错误!" << endl;
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
	//char express[] = "5.3+(6-8/9)*4";
	char express[256] = "";
	printf("Please input express\n");
	cin>> express;
	if (eval(express, v) == 0)
	{
		cout << express << " = " << v << endl;
	}
	return EXIT_SUCCESS;
}

/*int main()
{
	int i;
	GStack<int> stack;
	for (i=0; i<5; i++)
	{
		stack.push(i);
	}

	while (!stack.isEmpty())
	{
		cout << stack.pop() << " ";
	}

	cout << endl;
	return 0;
}*/