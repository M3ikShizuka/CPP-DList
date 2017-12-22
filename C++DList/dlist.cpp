#include "dlist.hpp"

DList::DList(const int& _value)
{
	this->pFirst = new CNode(_value);
}

CNode::CNode(const int& _value) :
	value(_value), 
	pNext(nullptr), 
	pPrev(nullptr) 
{
}

// Push
void DList::PushFirst(const int& value)
{
	printf("=== ListPushFirst value: %i ===\n", value);
	
	if (!this)
	{
		return;
	}

	// Инициализация нового узла в листе.
	CNode *pNodeNew = new CNode(value);

	// Если лиси пуси
	if (this->pFirst)
	{
		// Задаём связи для нового списка
		pNodeNew->pNext = this->pFirst;
		this->pFirst->pPrev = pNodeNew;
		// Переопределяем начало списка	
	}
	this->pFirst = pNodeNew;
}

void DList::PushLast(const int& value)
{
	printf("=== ListPushLast value: %i ===\n", value);

	if (!this)
	{
		return;
	}

	// Инициализация нового узла в листе.
	CNode *pNodeNew = new CNode(value);

	// Если лиси пуси
	if (!this->pFirst)
	{
		this->pFirst = pNodeNew;
		return;
	}

	// Находим последнй элемент в списке
	CNode *pNode = this->pFirst;
	while (pNode->pNext)
	{
		pNode = pNode->pNext;
	}

	// Задаём связи для нового элемента
	pNodeNew->pPrev = pNode;
	// Задаём связи для предпоследнего элемента
	pNode->pNext = pNodeNew;
}

void DList::PushByIndex(const int& n, const int& value)
{
	printf("=== ListPushByIndex n: %i value: %i ===\n", n, value);
	
	if (!this)
	{
		return;
	}

	// Инициализация нового узла в листе.
	CNode *pNodeNew = new CNode(value);
	
	int iIndex = 0;
	bool bFound = 0;

	CNode *pNode = this->pFirst;
	// Если лист не пустой
	if (pNode)
	{
		while (pNode->pNext)
		{
			if (iIndex == n)
			{
				bFound = 1;
				break;
			}

			pNode = pNode->pNext;
			iIndex++;
		}

		if (bFound)
		{
			// Задаём связи для нового элемента
			pNodeNew->pNext = pNode->pNext;
			pNodeNew->pPrev = pNode;

			if (pNode->pNext)
				pNode->pNext->pPrev = pNodeNew;

			pNode->pNext = pNodeNew;
		}
		else
		{
			// Задаём связи для нового элемента
			pNodeNew->pNext = nullptr;
			pNodeNew->pPrev = pNode;

			pNode->pNext = pNodeNew;
		}
	}
	else
	{
		// Если лист пуст
		this->pFirst = pNodeNew;
	}
}

// Get first Element
CNode *DList::GetFirstElement()
{
	if (!this)
	{
		return nullptr;
	}

	return this->pFirst;
}

// Get value
const int& DList::GetFirstValue()
{
	if (!this || !this->pFirst)
	{
		return -1;
	}

	return this->pFirst->value;
}

const int& DList::GetLastValue()
{
	// Если лист не инициализирован или пуст
	if (!this || !this->pFirst)
	{
		return -1;
	}

	CNode *pNode = this->pFirst;
	while (pNode->pNext)
	{
		pNode = pNode->pNext;
	}

	return pNode->value;
}

const int& DList::GetValueByIndex(const int& n)
{
	// Если лист не инициализирован или пуст
	if (!this || !this->pFirst)
	{
		return -1;
	}

	CNode *pNode = this->pFirst;

	int iIndex = 0;
	bool bFound = 0;
	while (pNode)
	{
		if (iIndex == n)
		{
			bFound = 1;
			break;
		}

		if (!pNode->pNext)
			break;

		pNode = pNode->pNext;
		iIndex++;
	}

	if (bFound)
	{
		return pNode->value;
	}

	return -1;
}

// Pop
const int DList::PopFirst()
{
	printf("=== ListPopFirst ===\n");
	
	if (!this || !this->pFirst)
	{
		return -1;
	}
	
	CNode *pNodeFirst = this->pFirst;
	// Сохраняем значение value
	int value = pNodeFirst->value;
	// Переопределяем начало листа
	this->pFirst = pNodeFirst->pNext;
	// Затераем связи, если лист не пуст.
	if (this->pFirst)
		this->pFirst->pPrev = nullptr;
	
	delete pNodeFirst;
	pNodeFirst = nullptr;
	return value;
}

const int DList::PopLast()
{
	printf("=== ListPopLast ===\n");
	
	// Если лист не инициализирован или пуст
	if (!this || !this->pFirst)
	{
		return -1;
	}

	CNode *pNode = this->pFirst;
	while (pNode->pNext)
	{
		pNode = pNode->pNext;
	}
	
	int value = pNode->value;
	if (pNode->pPrev)
		pNode->pPrev->pNext = nullptr;
	else
		this->pFirst = nullptr;
	
	delete pNode;
	pNode = nullptr;
	return value;
}

const int DList::PopByIndex(const int& n)
{
	printf("=== ListPopByIndex n: %i ===\n", n);

	// Если лист не инициализирован или пуст
	if (!this || !this->pFirst)
	{
		return -1;
	}

	CNode *pNode = this->pFirst;

	int iIndex = 0;
	bool bFound = 0;
	while (pNode)
	{
		if (iIndex == n)
		{
			bFound = 1;
			break;
		}

		if (!pNode->pNext)
			break;

		pNode = pNode->pNext;
		iIndex++;
	}

	if (bFound)
	{
		if (pNode->pNext)
		{
			pNode->pNext->pPrev = pNode->pPrev;
		}

		if (pNode->pPrev)
		{
			pNode->pPrev->pNext = pNode->pNext;
		}
		else
		{
			this->pFirst = pNode->pNext;
		}

		int value = pNode->value;
		delete pNode;
		pNode = nullptr;
		return value;
	}
	else
	{
		return -2; // if List size < n
	}
}

// Print
void ListPrint(DList *pDList)
{
	// Если лист не инициализирован или пуст
	if (!pDList)
	{
		return;
	}

	CNode *pNode = pDList->GetFirstElement();
	int iIndex = 0;
	while (pNode)
	{
		printf("List \tid: %i\tvalue: %i\n", iIndex, pNode->value);
		pNode = pNode->pNext;
		iIndex++;
	}
}