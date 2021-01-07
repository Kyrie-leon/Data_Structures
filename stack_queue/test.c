#include "stack.h"
#include "Queue.h"

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

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	while (!(QueueEmpty(&q)))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestroy(&q);
}

int main()
{
	//TestStack();
	TestQueue();
	system("pause");
	return 0;
}