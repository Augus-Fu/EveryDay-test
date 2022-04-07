/*******************************************************************************
 * 数据结构教学程序：链队列
 * 利用双向循环链表实现了进栈、出栈操作
 * 版权声明：您可以随意使用、复制或传播本代码，但请保留原作者姓名
 * 作者：成都理工大学信息科学与技术学院-软件工程系-邓飞  2015.09
*******************************************************************************/
#ifndef GSTACK_H
#define GSTACK_H

#include <stdexcept>

// 链表节点
template <class T>
struct GStackNode
{
	T				mData;			// 数据域
	GStackNode<T>* mpNext;			// 向后的链指针

	GStackNode(const T& data = T(), GStackNode<T>* pNext = NULL)
	{
		mData = data;
		mpNext = pNext;
	}
};

template <class T>
class GStack
{
protected:
	GStackNode<T>* mpTop;		// 栈顶指针

public:
	GStack()
	{
		mpTop = NULL;
	}

	~GStack()
	{
		while (mpTop != NULL)
		{
			pop();
		}
	}

	bool isEmpty() const
	{
		return mpTop == NULL;
	}

	// 请完成pop函数, 实现栈顶数据的弹出, 返回栈顶数据
	T pop()
	{
		if (isEmpty()) return T();

		GStackNode<T>* pNode = mpTop;
		mpTop = pNode->mpNext;
		T data = pNode->mData;
		delete pNode;
		return data;
	}

	// 请完成push函数, 实现数据入栈
	void push(const T& data)
	{
		GStackNode<T>* pNode=new GStackNode<T>(data);
		pNode->mpNext = mpTop;
		mpTop = pNode;
	}

	T& top()
	{
		if (isEmpty()) throw std::overflow_error("Stack is Empty!");
		return mpTop->mData;
	}
	const T& top() const
	{
		if (isEmpty()) throw std::overflow_error("Stack is Empty!");

		return mpTop->mData;
	}
};

#endif