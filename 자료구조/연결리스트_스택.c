#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct Node{
	element data;
	struct Node* next;
}Node;
typedef struct SList{
	struct Node* top;
}SList;
//1) 노드의 구조체 정의
//2) 스택리스트의 시작 구조체 정의

void init(SList* s){
	 s->top = NULL;//
}
int isEmpty(SList* s){
	return s->top == NULL ? 1:0;//
}
int isFull(SList* s){
	return 0;
}
void push(SList* s, element data){
  Node* node = (Node*)malloc(sizeof(Node));//동적할당;
	node->data = data; //;
	node->next = s->top; //;
	s->top = node;//
}
void pop(SList* s){
	Node* p = s->top;
	if (isEmpty(s)){
		printf("Stack is Empty\n");
	}
	else{
		s->top =  s->top->next;//
		free(p);
		 
	}
}
void printList(SList* s){
	Node* p = s->top;//;
	while(p!=NULL){
		printf("%d->",p->data);
		p = p->next;//
	}
	printf("NULL\n");
}
int main() {
	SList s = {0};
	init(&s);
	push(&s,1); printList(&s);
	push(&s,2); printList(&s);
	push(&s,3); printList(&s);
	pop(&s); printList(&s);
	pop(&s); printList(&s);
	pop(&s); printList(&s);
	return 0;
}