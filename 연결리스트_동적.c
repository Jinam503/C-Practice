// �Լ��� Ȱ���� node �������� �����ϱ�
#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct Node {
    element data;
    struct Node* next;
}Node;
Node *createNode( element data );
void printAll( Node *ptr );

int main(){
    Node *head, *node1,*node2, *node3 ;
	node1 = createNode(12);
	node2= createNode(99);
	node3 = createNode(37);
	
	node1->next = node2;
	node2->next =  node3;
	
	printAll(node1);
	  //heard, node1, node2 ��� ����
	  //�� ���->next�� ����
	  //head ��带 ���
   
}
Node *createNode( element data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
    //��� ũ�� ���� �Ҵ�
    //����� ������ ����
    //���->next ������ NULL����
	  return newNode;
}
void printAll( Node* ptr ){
    while( ptr ){
				if (ptr->next != NULL){//next ��尡 ������ ->���
          //����� ������ ��� 
        	//��������� �ּҷ� ����
					printf("%d->", ptr->data);
					ptr = ptr->next;
				}
			  else {
					printf("%d", ptr->data);
					//����� ������ ��
					return;//����Ʈ ����
				}
    }
}