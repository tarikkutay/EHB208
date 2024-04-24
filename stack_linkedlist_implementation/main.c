#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 4

typedef struct node {
	int data;
	struct node* next;
}node;	//ba�l� liste d���m� tan�mlad�m

typedef struct {
	struct node *top;
	int cnt;
}stack;
//top nodu ve counter yap�s� tan�mlad�k
typedef enum{false,true}boolean;
//c nin i�inde standart true false 0 1 yok o y�zden numaraland�rd�k
void initStack(stack* stk) {
	stk->top = NULL;
	stk->cnt = 0;
}
boolean isEmpty(stack* stk) {
	return(stk->cnt == 0);
}

boolean isFull(stack *stk) {
	return(stk->cnt != STACK_SIZE);
}

void push(stack* stk, int c) {

	if (!isFull(stk)) {
		node *temp = (node*)malloc(sizeof(node));
		//yeni bir d���m olu�turuldu
		temp->data = c;
		//o d���m�n i�inde istedi�im de�erin datas� sakland�
		temp->next = stk->top;
		//o d���m�n next de�eri stackin top de�erini g�sterdi
		stk->top = temp;
		//o d���m� g�steren pointer top ile de�i�tirildi 
		stk->cnt++;
		//counter 1 artt�r�ld�
	}
	//stack dolu de�ilse bu i�lemler ger�ekle�ir
	else
		printf("\nStack Dolu\n");
}

int pop(stack* stk) {
	if (!isEmpty(stk)) {
		node *temp = stk->top;
		stk->top = stk->top->next;
		int x = temp->data;
		free(temp);
		stk->cnt--;
		return x;
	}
	else {
		printf("\nStack Bos\n\n");
		return INT_MIN;
	}
}

int main() {
	stack s;
	initStack(&s);

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);

	int x = pop(&s);
	printf("%d stacktan ��kar�lan de�erdir", x);
	return 0;
}