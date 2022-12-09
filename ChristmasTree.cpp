
#include <stdlib.h>
#include <string>
#include <Windows.h>
#include <iostream>

using namespace std;
typedef struct ChristmasTree {
	struct ChristmasTree* left, * right;
	int data;
	int light = 0;
	char letter[1000] = {};
};

void Print(int line, ChristmasTree* root);
ChristmasTree* CreateTree(int line);
ChristmasTree* MakeNode(int data);
ChristmasTree* Find(ChristmasTree* root, int data);
int line, count;
int main() {
	int room;
	char input;
	scanf_s("%d", &line);
	ChristmasTree* root = CreateTree(line);
	while (1) {
		system("cls");
		Print(line, root);
		printf("러브레터를 적고싶은 곳이나 수정하고 싶은 곳의 숫자를 적어주세요!\n");
		scanf_s("%d", &room);
		ChristmasTree* cN = Find(root, room);
		if (cN->light == 1) {
			cout << "내용이 있습니다! 수정하고 싶으면 \"e\", 삭제하고 싶으면 \"d\"키를 눌러주세요!\n\n";
			cin >> input;
			if (input == 'e') {
				system("cls");
				cout << "변경하고 싶은 내용을 입력해주세요.\n"
					<< cN->letter
					<< "\n\n"
					<< "               ↓↓  \n";
				cin >> cN->letter;
			}
			else if (input == 'd') {
				system("cls");
				cout << "삭제되었습니다.";
				cN->light = 0;
				Sleep(1000);
				continue;
			}
		}
		else {
			system("cls");
			printf("   - 러브레터 작성 - (한 문장으로 적어주세요!)\n\n");
			cin >> cN->letter;
			printf("%d", cN->data);
			if (cN->light == 1) cN->light = 0;
			else cN->light = 1;
			Sleep(100);
		}

	}



	return 0;
}
ChristmasTree* MakeNode(int d) {
	ChristmasTree* nN = (ChristmasTree*)malloc(sizeof(ChristmasTree));
	nN->data = d;
	nN->left = NULL;
	nN->right = NULL;
	return nN;
}
ChristmasTree* CreateTree(int line) {
	ChristmasTree* root = (ChristmasTree*)malloc(sizeof(ChristmasTree));
	root->data = 1;
	int count = 1;
	ChristmasTree* list[15] = { 0 };
	list[line - 1] = root;
	for (int i = 1; i < line; i++) {
		for (int j = 0; j < i; j++) {
			if (j == 0) {
				ChristmasTree* lN = MakeNode(++count);
				ChristmasTree* rN = MakeNode(++count);
				list[line - 1]->left = lN;
				list[line - 1]->right = rN;
				list[line - 1] = lN;
				list[i - 1] = rN;
			}
			else {
				ChristmasTree* rN = MakeNode(++count);
				list[i - (j + 1)]->left = list[i - j];
				list[i - (j + 1)]->right = rN;
				list[i - (j + 1)] = rN;
			}
		}
	}

	return root;
}
ChristmasTree* Find(ChristmasTree* root, int keyNum) {
	int count = 1;
	int right = 0;
	int keyInLine = 0;
	for (int i = 1; i <= line; i++) {
		for (int j = 0; j < i; j++, count++) {
			if (keyNum == count) {
				keyInLine = i;
				right = j;
			}
		}
	}

	ChristmasTree* rN = root;
	for (int i = 0; i < right; i++) {
		rN = rN->right;
	}
	for (int i = 0; i < (keyInLine - right - 1); i++) {
		rN = rN->left;
	}
	return rN;
}
void Print(int line, ChristmasTree* root) {

	printf("\nChristmas Tree!\n");
	if (line == 1) {
		printf("  ☆\n  1\n  |");
		return;
	}
	for (int k = 0; k < (line - 1) * 2; k++) printf(" ");
	printf("☆\n\n");
	int cnt = 1;
	int cnt2 = 1;
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) for (int k = 0; k < (line - i) * 2; k++) printf(" ");
			ChristmasTree* rN = Find(root, cnt2++);
			rN->light == 1 ? printf("●   ") : printf("○   ");
		}
		printf("\n");
		for (int j = 1; j <= i; j++) {
			if (j == 1) for (int k = 0; k < (line - i) * 2; k++) printf(" ");
			cnt < 10 ? printf("%d   ", cnt++) : printf("%d  ", cnt++);
		}
		printf("\n");
		for (int j = 0; j < (line - i) * 2 - 1; j++) printf(" ");
		if (i != line) {
			for (int j = 1; j <= i; j++) printf("/ \\ ");
			printf("\n");
		}
	}
	for (int i = 0; i < 1; i++) {
		for (int k = 0; k < (line - 1) * 2 - 2; k++) printf(" ");
		printf("|   |\n");
	}
	for (int k = 0; k < (line - 1) * 2 - 2; k++) printf(" ");
	printf("_____\n\n");
}

