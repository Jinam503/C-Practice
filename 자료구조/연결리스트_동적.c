// 함수를 활용해 node 동적으로 생성하기
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
	  //heard, node1, node2 노드 생성
	  //각 노드->next를 저장
	  //head 노드를 출력
   
}
Node *createNode( element data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
    //노드 크기 동적 할당
    //노드의 데이터 저장
    //노드->next 참조를 NULL저장
	  return newNode;
}
void printAll( Node* ptr ){
    while( ptr ){
				if (ptr->next != NULL){//next 노드가 있으면 ->출력
          //노드의 데이터 출력 
        	//다음노드의 주소로 저장
					printf("%d->", ptr->data);
					ptr = ptr->next;
				}
			  else {
					printf("%d", ptr->data);
					//노드의 데이터 출
					return;//프린트 종료
				}
    }
}