#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
typedef struct {
	char word[100];
	char meaning[200];
}element;
typedef struct TreeNode{
	element key;
	struct TreeNode *left, *right;
}TreeNode;
int compare(element e1, element e2){
	return strcmp(e1.word,e2.word); //e1<e2:-1,==:0,>1
}
//이진탐색트리 출력함수
void display(TreeNode* p){
	if(p != NULL){
		printf("(");
		display(p->left);
		printf("%s:%s", p->key.word, p->key.meaning);
		display(p->right);
		printf(")");
	}
} 
//이진탐색트리 탐색함수
TreeNode* search(TreeNode* root, element key){
	TreeNode *p = root;
	while(p != NULL){
		if(compare(key, p->key) == 0) return p;
		else if(compare(key, p->key) < 0) p= p->left;
		else if(compare(key, p->key) > 0) p= p->right;
	}
	return p;
} 
TreeNode* newNode(element item){
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));//노드 동적할당
	temp->key =  item;//;
	temp->left = temp->right = NULL;//;
	return temp;
}
TreeNode* insertNode(TreeNode* node, element key){
	//탐색이 실패한 위치에 새로운 노드를 삽입 후 반환
	if ( node == NULL ) return newNode(key);
	//그렇지 않으면 순환적으로 트리를 내려간다.
	if (compare(key, node->key) < 0){ 
		node->left = insertNode(node->left,key);//
	}
	else if (compare(key, node->key) > 0) {
		node->right = insertNode(node->right, key);//
	}
	//변경된 루트 포인터 반환
	return node;
}
TreeNode *minNode(TreeNode* node){
	TreeNode* current = node;
	while(current->left != NULL){
		current = current->left;
	}
	return current;
}
TreeNode* deleteNode(TreeNode* root, element key){
	//printf("delete 주소=%p, key =%d\n",root,key);
	if (root == NULL) return root;
	//1.만약 키가 루트보다 작으면 ->왼쪽서브트리
	if (compare(key, root->key) < 0) {
		root->left =  deleteNode(root->left, key);//
	}
	//2.만약 키가 루트보다 크면 -> 오른쪽 서브트리
	else if(compare(key, root->key) > 0){
		root->right =deleteNode(root->right, key);
	} 
	//3. 키가 루트와 같으면 노드 삭제
	else{
		//3-1.삭제노드가 단말이거나 하나의 서브트리를 가지는 경우
		if (root->left == NULL){
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL){
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		//3-2.삭제노드가 두개의 서브트리를 가지고 있는 경우
		TreeNode* temp = minNode(root->right);
		//중위순회시 후계노드 복사
		root->key = temp->key; //22
		//중위순회시 후계 노드 삭제
	//	printf("delete [26]주소=%p, key =%d\n",root->right,temp->key);
		root->right = deleteNode(root->right,temp->key); //26주소 ,22
	}
	return root;
}
int main(){
	char command;
	element e;
	TreeNode* root = NULL;
	TreeNode* tmp;
	do{
		printf("\n ****i: 입력, d: 삭제,s: 탐색,p: 출력,q:종료****:");
		command = getchar();
		getchar();
		switch(command){
			case 'i':
				printf("단어:");
				//단어 한줄 e.word에 입력받음
				gets(e.word); // fgets(배열 이름, 크기, stdin); 
				printf("의미:");
			//의미 한줄 e.meaning에 입력받음
				gets(e.meaning);
				root =  insertNode(root, e);//구조체변수 e입력하는 함수 실행
				break; 
			case 'd':
				printf("단어:"); 
				gets(e.word);
				root = deleteNode(root, e);// 삭제 함수 실행
				break; 
			case 's':
				printf("단어:");
				gets(e.word);
				tmp = search(root, e);//탐색함수 실행
				if(tmp !=NULL){
					printf("의미: %s\n",e.meaning);
					 
				}
				break;
			case 'p':
				display(root);
				printf("\n");
				break;
		} 
	}while(command != 'q' );

	return 0; 
}

