#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element; //int�� element�� ������
element	stack[MAX_STACK_SIZE]; //1���� �迭�� ���� ����
//���������� ���� ����
typedef struct{
	int data[100];
	int top;
}Stack;
Stack s;
int isEmpty(){
 	if(s.top == -1) return 1;
	else return 0;
}
int isFull(){
	if(MAX_STACK_SIZE -1 == s.top) return 1;
	else return 0;
}	 
void push(element item){
	s.top++;
	s.data[s.top] = item;
	
}
element pop(){ //��ȯ�� ����
	element temp = s.data[s.top];
	s.top--;
	return temp;
}
element peek(){//��ȯ��
element temp = s.data[s.top];
	return temp;
}
int main(){
	s.top = -1;
	push(1);
	push(2);
	push(3);
	printf("%d\n",pop());
	printf("%d\n",peek());
	printf("%d\n",pop());
	return 0;

}