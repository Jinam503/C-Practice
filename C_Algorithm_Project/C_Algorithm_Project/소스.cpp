
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <iostream>

using namespace std;
typedef struct ChristmasTree {
	struct ChristmasTree* left, * right;//왼, 오른쪽 노드
	int data;//번호
	int light = 0;//편지가 있는지 없는지
	char letter[1000];//편지
};
bool isFinish;
int line, count;
void Print(int line, ChristmasTree* root);//트리 출력
ChristmasTree* CreateTree(int line);//구조체 트리 구성
ChristmasTree* MakeNode(int data);//노드 하나 만들기
ChristmasTree* Find(ChristmasTree* root, int data);//원하는 숫자가 들어있는 노드의 위치 구하기
void finish();//편지 입력을 끝내고 읽기전용으로 바꿀 떄

int main() {
	
	int room;
	char input;
	scanf_s("%d", &line);
	ChristmasTree* root = CreateTree(line);
	while (1) {
		
		if (!isFinish) {
			system("cls");
			Print(line, root);
			printf("편지를 적고싶은 곳이나 수정하고 싶은 곳의 숫자를 적어주세요! ( 편지작성을 끝내려면 0번을 적어주세요. )\n\n");
			scanf_s("%d", &room);
			if (room == 0) {
				finish();
				continue;
			}
			ChristmasTree* cN = Find(root, room);
			if (cN->light == 1) {
				cout << "\n내용이 있습니다! 수정하고 싶으면 \"e\", 삭제하고 싶으면 \"d\"키를 눌러주세요!\n\n";
				cin >> input;
				if (input == 'e') {
					system("cls");
					cout << "변경하고 싶은 내용을 입력해주세요.\n\n";
					cout << cN->letter;
					cout << "\n\n"
						<< "               ↓↓  \n\n";
					cin.getline(cN->letter, 1000, '~');
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
				cout <<"   - 편지 작성 - ( '~'를 적을 때까지 입력을 받습니다. )\n\n";
				cin.getline(cN->letter, 100, '~');
				if (cN->light == 1) cN->light = 0;
				else cN->light = 1;
				Sleep(100);
			}
		}
		else {
			
			system("cls");
			Print(line, root);
			cout << "편지를 보고 싶은 곳의 숫자를 적어주세요! ( 종료하려면 0번을 눌러주세요. )\n\n";
			cin >> room;
			if (room == 0) break;
			ChristmasTree* cN = Find(root, room);
			if (cN->light != 1) {
				cout << "그곳엔 편지가 없어요 ㅜㅜ";
				Sleep(1000);
				continue;
			}
			system("cls");
			cout << cN->letter<< "\n\n\n" << "나가시려면 아무키나 눌러주세요.\n";
			char d[1000];
			cin >>d;
		}
		

	}



	return 0;
}
void finish() {
	system("cls");
	cout << "크리스마스 트리 편지입력이 완료되었습니다.";
	isFinish = true;
	Sleep(1000);

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

	cout<<"\nChristmas Tree!\n";
	if (line == 1) {
		cout<<"  ☆\n  1\n  |";
		return;
	}
	for (int k = 0; k < (line - 1) * 2; k++) cout<<" ";
	cout<<"☆\n\n";
	int cnt = 1;
	int cnt2 = 1;
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) for (int k = 0; k < (line - i) * 2; k++) cout<<" ";
			ChristmasTree* rN = Find(root, cnt2++);
			rN->light == 1 ? cout<<"●  " : cout<<"○  ";
		}
		cout<<"\n";
		for (int j = 1; j <= i; j++) {
			if (j == 1) for (int k = 0; k < (line - i) * 2; k++) cout<<" ";
			cnt < 10 ? cout << cnt++ << "   " : cout << cnt++<< "  ";
		}
		cout << "\n";
		for (int j = 0; j < (line - i) * 2 - 1; j++) cout<<" ";
		if (i != line) {
			for (int j = 1; j <= i; j++) cout<<"/ \\ ";
			cout << "\n";
		}
	}
	for (int i = 0; i < 1; i++) {
		for (int k = 0; k < (line - 1) * 2 - 2; k++) cout << " ";
		cout <<"|   |\n";
	}
	for (int k = 0; k < (line - 1) * 2 - 2; k++) cout<<" ";
	cout << "_____\n\n";
}

