#pragma once
/*******************************************************************************
 * ���ݽṹ��ѧ����������
 * ����˫��ѭ������ʵ���˽�ջ����ջ����
 * ��Ȩ����������������ʹ�á����ƻ򴫲������룬���뱣��ԭ��������
 * ���ߣ��ɶ�����ѧ��Ϣ��ѧ�뼼��ѧԺ-�������ϵ-�˷�  2015.09
*******************************************************************************/
#ifndef GSTACK_H
#define GSTACK_H

// ����ڵ�
template <class T>
struct GStackNode
{
	T				mData;			// ������
	GStackNode<T>* mpNext;			// ������ָ��

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
	GStackNode<T>* mpTop;		// ջ��ָ��

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

	T pop()
	{
		if (isEmpty()) return T();

		GStackNode<T>* pNode = mpTop;
		mpTop = pNode->mpNext;
		T data = pNode->mData;
		delete pNode;
		return data;
	}

	void push(const T& data)
	{
		GStackNode<T>* pNode = new GStackNode<T>(data);
		pNode->mpNext = mpTop;
		mpTop = pNode;
	}

	T top()
	{
		if (isEmpty()) return T();

		return mpTop->mData;
	}
};

#endif
