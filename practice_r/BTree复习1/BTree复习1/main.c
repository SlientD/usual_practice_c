#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"

int main(){
	char* x = "ABDH##I##EJ###CF##G##";
	//char* x = "ABD##EJ###CF##G##";
	//char* x = "A#B#c##";
	BTreeNode* bt;
	bt = BTreeCreat(x);
	int i;
	//Ç°Ðò±éÀú1
	printf("pre:");
	BTreePreOrder(bt);
	printf("\nin:");
	BTreeInOrder(bt);
	printf("\npost:");
	BTreePostOrder(bt);
	
	printf("\nlevel:");
	BTreeLevelOrder(bt);

	printf("\npreNR:");
	BTreePreOrderNR(bt);
	printf("\ninNR:");
	BTreeInOrderNR(bt);
	printf("\npostNR:");
	BTreePostOrderNR(bt);
	printf("\niscompete?");
	i = BTreeIsCompete(bt);
	printf("%d", i);

	printf("\ndestroy:");
	BTreeDestroy(bt);
	
	system("pause");
	return 0;
}