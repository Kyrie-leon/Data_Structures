#include "stack.h"

void TestStack()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPush(&ps, 5);
	while (!StackEmpty(&ps))
	{

		printf("%d, %d\n", StackTop(&ps),StackSize(&ps));
		StackPop(&ps);
	}

	
}

int main()
{
	TestStack();
	system("pause");
	return 0;
}