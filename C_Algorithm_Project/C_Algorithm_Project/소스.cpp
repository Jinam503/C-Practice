
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <iostream>

using namespace std;
typedef struct ChristmasTree {
	struct ChristmasTree* left, * right;//��, ������ ���
	int data;//��ȣ
	int light = 0;//������ �ִ��� ������
	char letter[1000];//����
};
bool isFinish;
int line, count;
void Print(int line, ChristmasTree* root);//Ʈ�� ���
ChristmasTree* CreateTree(int line);//����ü Ʈ�� ����
ChristmasTree* MakeNode(int data);//��� �ϳ� �����
ChristmasTree* Find(ChristmasTree* root, int data);//���ϴ� ���ڰ� ����ִ� ����� ��ġ ���ϱ�
void finish();//���� �Է��� ������ �б��������� �ٲ� ��

int main() {
	
	int room;
	char input;
	scanf_s("%d", &line);
	ChristmasTree* root = CreateTree(line);
	while (1) {
		
		if (!isFinish) {
			system("cls");
			Print(line, root);
			printf("������ ������� ���̳� �����ϰ� ���� ���� ���ڸ� �����ּ���! ( �����ۼ��� �������� 0���� �����ּ���. )\n\n");
			scanf_s("%d", &room);
			if (room == 0) {
				finish();
				continue;
			}
			ChristmasTree* cN = Find(root, room);
			if (cN->light == 1) {
				cout << "\n������ �ֽ��ϴ�! �����ϰ� ������ \"e\", �����ϰ� ������ \"d\"Ű�� �����ּ���!\n\n";
				cin >> input;
				if (input == 'e') {
					system("cls");
					cout << "�����ϰ� ���� ������ �Է����ּ���.\n\n";
					cout << cN->letter;
					cout << "\n\n"
						<< "               ���  \n\n";
					cin.getline(cN->letter, 1000, '~');
				} 
				else if (input == 'd') {
					system("cls");
					cout << "�����Ǿ����ϴ�.";
					cN->light = 0;
					Sleep(1000);
					continue;
				}

			}
			else {
				system("cls");
				cout <<"   - ���� �ۼ� - ( '~'�� ���� ������ �Է��� �޽��ϴ�. )\n\n";
				cin.getline(cN->letter, 100, '~');
				if (cN->light == 1) cN->light = 0;
				else cN->light = 1;
				Sleep(100);
			}
		}
		else {
			
			system("cls");
			Print(line, root);
			cout << "������ ���� ���� ���� ���ڸ� �����ּ���! ( �����Ϸ��� 0���� �����ּ���. )\n\n";
			cin >> room;
			if (room == 0) break;
			ChristmasTree* cN = Find(root, room);
			if (cN->light != 1) {
				cout << "�װ��� ������ ����� �̤�";
				Sleep(1000);
				continue;
			}
			system("cls");
			cout << cN->letter<< "\n\n\n" << "�����÷��� �ƹ�Ű�� �����ּ���.\n";
			char d[1000];
			cin >>d;
		}
		

	}



	return 0;
}
void finish() {
	system("cls");
	cout << "ũ�������� Ʈ�� �����Է��� �Ϸ�Ǿ����ϴ�.";
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
		cout<<"  ��\n  1\n  |";
		return;
	}
	for (int k = 0; k < (line - 1) * 2; k++) cout<<" ";
	cout<<"��\n\n";
	int cnt = 1;
	int cnt2 = 1;
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) for (int k = 0; k < (line - i) * 2; k++) cout<<" ";
			ChristmasTree* rN = Find(root, cnt2++);
			rN->light == 1 ? cout<<"��  " : cout<<"��  ";
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

