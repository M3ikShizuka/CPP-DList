#pragma once
#include "head.hpp"

class CNode;
class DList;

class CNode
{
public:
	int value;
	CNode *pNext;
	CNode *pPrev; // previous
	
public:
	CNode(const int& _value);
};

class DList
{
private:
	CNode *pFirst;

public:
	DList(const int& _value);
	// Push
	void PushFirst(const int& value);
	void PushLast(const int& value);
	void PushByIndex(const int& n, const int& value);
	
	// Get first Element
	CNode *GetFirstElement();
	
	// Get value
	const int& GetFirstValue();
	const int& GetLastValue();
	const int& GetValueByIndex(const int& n);
		
	// Pop
	const int PopFirst();
	const int PopLast();
	const int PopByIndex(const int& n);
};

// Print
void ListPrint(DList *pDList);