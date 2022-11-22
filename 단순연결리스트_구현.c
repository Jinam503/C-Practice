#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct Node{
	element data;
	struct Node* next;
}Node;
//1. 연결리스트 구조체 정의
Node* insertFirst(Node* head, element data){
	Node* nN = (Node*)malloc(sizeof(Node*));
	nN->data = data;
	nN->next = head;
	head = nN;
	return head;
	//2. 첫위치 삽입 코드 작성
}
Node* insert(Node* head, Node* pre, element data){
	Node* nN = (Node*)malloc(sizeof(Node*));
	nN->data = data;
	nN->next = pre->next;
	pre->next = nN;
	return head;
	//3. 중간위치(pre 다음 위치 )삽입
}
Node* deleteFirst(Node* head){
	//4. 첫위치 삭제 코드 작성
	Node* rN = head;
	head = rN->next;
	free(rN);
	rN = NULL;
	return head;
}
Node* delete(Node* head, Node* pre){
	//5.프리가 가리키는 다음 노드를 삭제
	Node* rN = pre->next;
	pre->next = rN->next;
	free(rN);
	rN = NULL;
	return head;
}
void printList(Node* head){
	Node* t = head;
	while(t!=NULL){
		printf("%d->", t->data);
		t = t->next;
	}
	//6.head가 널이 아니면 노드데이터 출력
	printf("NULL\n");
		
}
int main(){
	Node* head = NULL;
	Node* temp = NULL;
	printf("[첫 위치 삽입]\n");
	for(int i = 0;i<5;i++){
		head = insertFirst(head,i);//7. 첫위치에 i 삽입
		printList(head);
		if (i==2) temp = head; //데이터가 2인 노드 주소 저장

	}
	printf("[중간위치 삽입]\n");
	insert(head, temp,100);
	//8. temp 다음 위치에 100 저장
	printList(head);
	printf("[중간위치 삭제]\n");
	delete(head, temp);
	//9. temp 다음위치 노드 삭제
	printList(head);
	printf("[첫 위치 삭제]\n");
	for(int i=0;i<5;i++){
		head= deleteFirst(head);
		//10. 첫위치 노드 삭제
		printList(head);
	}
	return 0;
}



