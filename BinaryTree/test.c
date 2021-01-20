#include"BinaryTree.h"
#include"Queue.h"

int main()
{
	BTNode* A = CreateNode('A');
	BTNode* B = CreateNode('B');
	BTNode* C = CreateNode('C');
	BTNode* D = CreateNode('D');
	BTNode* E = CreateNode('E');
	//BTNode* F = CreateNode('F');
	A->_left = B;
	A->_right = C;
	//C->_right = F;
	B->_left = D;
	B->_right = E;

	//PrevOrder(A);	//Ç°Ğò±éÀú
	//InOrder(A);	//ÖĞĞò±éÀú
	//PostOrder(A); //ºóĞò±éÀú
	//LevelOrder(A);	//²ãĞò±éÀú
	//printf("%d\n", TreeSize(A));
	//printf("%d\n", TreeLeafSize(A));
	//printf("%d\n", TreeComplete(A));
	printf("%d\n", TreeLevelKSize(A,2));
	printf("%c\n", TreeFind(A, 'C')->_data);

	system("pause");
	return 0;
}