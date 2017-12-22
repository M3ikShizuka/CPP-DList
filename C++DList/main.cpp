#include "main.hpp"
#include "dlist.hpp"

int main()
{
	system("color 0A");

	DList *pDList = new DList(2);

	//// PUSH
	printf("==============================\n\tPUSH\n==============================\n");
	printf("--- pDList init value: %i ---\n", pDList->GetFirstElement()->value);
	ListPrint(pDList);
	pDList->PushFirst(1);
	ListPrint(pDList);
	pDList->PushLast(4);
	ListPrint(pDList);
	pDList->PushByIndex(1, 3);
	ListPrint(pDList);

	// Get value
	printf("==============================\n\tGet value\n==============================\n");
	printf("First value: %i\n", pDList->GetFirstValue());
	int n = 1;
	printf("Value: %i \tby n: %i\n", pDList->GetValueByIndex(n), n);
	n = 2;
	printf("Value: %i \tby n: %i\n", pDList->GetValueByIndex(n), n);
	printf("Last value: %i\n", pDList->GetLastValue());

	//// POP
	printf("==============================\n\tPOP\n==============================\n");
	pDList->PopFirst();
	ListPrint(pDList);
	pDList->PopLast();
	ListPrint(pDList);
	pDList->PopByIndex(1);
	ListPrint(pDList);
	pDList->PopLast();
	ListPrint(pDList);

	delete pDList;

	system("pause");

	return 0;
}