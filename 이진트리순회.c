#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode{
	char data;
	struct TreeNode *left, *right;
} TreeNode;
TreeNode* search(TreeNode* root, char data){
	if(root != NULL){
		if(root->data == data) return root;
		else{
			TreeNode* node = search(root->left, data);
			if(node != NULL) return node;
			else return search(root->right, data);
		}
	}
	else return NULL;
}
TreeNode* makeNode(char data){
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void setNode(TreeNode* node, char a, char b, char c){
	node->data = a;
	if(b != '.') node->left = makeNode(b);
	if(c != '.') node->right = makeNode(c);
}
void preorder(TreeNode* root)
{
	if(root != NULL){
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(TreeNode* root)
{
	if(root != NULL){
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

void postorder(TreeNode* root)
{
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
}
int main(){
	int n;
	char a,b,c;
	scanf("%d", &n);
	getchar();
	TreeNode* root = makeNode(NULL);
	TreeNode* root2;
	for(int i = 0; i< n; i++){
		scanf("%c %c %c", &a, &b, &c);
		getchar();
		root2 = search(root, a);
		if(root2 != NULL) setNode(root2, a,b,c);
		else setNode(root,a,b,c);
	}
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	return 0;
}
// 문제
// 이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.



// 예를 들어 위와 같은 이진 트리가 입력되면,

// 전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
// 중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
// 후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)
// 가 된다.

// 입력
// 첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현한다.

// 출력
// 첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.