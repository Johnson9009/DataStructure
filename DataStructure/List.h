#ifndef __LIST_H__
#define __LIST_H__ 
#include <cstddef>

template <class T>
class Node
{
public:
	Node() :_value(), next(NULL)
	{};
	Node(const T *value) : _value(value), next(NULL)
	{};
	T GetValue(void)
	{
		return _value;
	}
	void SetVaule(const T * value)
	{
		_value = value;
	}
	Node * next;
private:
	T _value;
};
#endif

