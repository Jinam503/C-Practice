
#include <stdio.h>
typedef struct{
    struct ChristmasTree *left, *right;
    int data;
} ChristmasTree;

void Print(int line);ChristmasTree* CreateTree(int line);ChristmasTree* MakeNode(int data);
int line, count;
int main() {
    
	scanf("%d", &line);
	ChristmasTree* root = CreateTree(line);
	printf("%d", root->data);
	Print(line);
	

	return 0;
}
ChristmasTree* MakeNode(int data){
    ChristmasTree* nN = (ChristmasTree*)malloc(sizeof(ChristmasTree));
	nN->data = data;
	nN->left = NULL;
	nN->right = NULL;
    return nN;
}
ChristmasTree* CreateTree(int line){
  ChristmasTree* root = (ChristmasTree*)malloc(sizeof(ChristmasTree));
	root->data = 1;
  int count = 1;
	ChristmasTree* list[15] = {0};
	list[line-1] = root;
	for(int i = 1; i < line; i++){
		for(int j = 0; j < i; j ++){
			if( j == 0){
				ChristmasTree* lN = MakeNode(++count);
				ChristmasTree* rN = MakeNode(++count);
				list[line-1]->left = lN;
				list[line-1]->right = rN;
				list[line-1] = lN;
				list[i-1] = rN;
			}
			else{
				ChristmasTree* rN = MakeNode(++count);
				list[i - (j+1)]->left = list[i-j];
				list[i - (j+1)]->right = rN;
				list[i - (j+1)] = rN;
			}
		}
	}
	
	return root;
}
//ChristmasTree* Find(ChristmasTree* root,int keyNum){
	
//}
void Print(int line){

    printf("\nChristmas Tree!\n");
		if(line == 1){
			printf("  ☆\n  1\n  |");
				return;
		}
    for(int k = 0; k < (line - 1) * 2 ; k++) printf(" ");
    printf("☆\n");
    int cnt = 1;
    for(int i = 1; i <= line; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1) for(int k = 0; k < (line - i) * 2; k++) printf(" ");
            cnt < 10 ? printf("%d   ", cnt++) : printf("%d  ", cnt++);
        }
        printf("\n");
        for(int j = 0; j < (line - i) * 2 - 1; j++) printf(" ");
        if(i != line) {
            for(int j = 1; j <= i; j++) printf("/ \\ ");
            printf("\n");
        }
    }
    for(int i = 0; i < 1; i++){
        for(int k = 0; k < (line - 1) * 2 - 2; k++) printf(" ");
        printf("|   |\n");
    }
    for(int k = 0; k < (line - 1) * 2 - 2; k++) printf(" ");
    printf("_____\n");
}

