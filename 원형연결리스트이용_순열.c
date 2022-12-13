#include <stdio.h>
#include <stdlib.h>
typedef int element;
//0) Node구조체 작성
	int a,b;
typedef struct Node{
	element data;
	struct Node* next;
	
}Node;
void printList(Node* head){
	Node *p =  head->next;//1)처음위치부터 출력;
	int cnt = 0;
	if (head == NULL) return;
	do {
		if(p == NULL) break;
		printf("%d->",p->data);
		p = p->next;
		//2)데이터 출력
		//3)ptr을 다음 주소로 저장
		cnt++;
	}while(cnt < a);//4)조건

	printf("\n");
}
Node* insertFirst(Node* head, element data){
	Node* node = (Node*)malloc(sizeof(Node*));//Node 동적할당
	node->data = data;
	if (head == NULL){
		head=node;// head의 주소로 새로운노드의 주소 저장
		node->next=head;//새로운노드의 다음 주소로 head 저장
	}
	else{
		node->next = head->next;//새로운노드의 다음 주소로 head 저장	 
		head->next = node;//head의 다음노드 주소로 새로운노드의 주소 저장
		head=node;
	}
	return head;
}
Node* removeNode(Node* head){
	Node *node = head, *removedNode =head; 
	for(int i = 0; i<b-1;i++)node = node->next;
	removedNode = node->next;
	printf("%d", node->next->data);
	node->next = node->next->next;
	head = node;
	free(removedNode);
	return head;
}
int main() {
	Node *head=NULL;
	scanf("%d %d",&a,&b);
	for(int i = 1;i<= a;i++){
		head = insertFirst(head,i);//마지막 위치에 삽입하는 함수 호출	
	}
	printf("<");
	for(int i = 1;i<= a;i++){
		head = removeNode(head);//마지막 위치에 삽입하는 함수 호출	
		if(i<a)printf(", ");
		else printf(">");
	}
	return 0;
}



// 1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

// 원형연결리스트를 이용하여 N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 5,000)

// 출력
// 예제와 같이 요세푸스 순열을 출력한다.