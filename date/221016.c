#include <stdio.h>
#include <string.h>
int main() {
	char s[1000001] ={0};
	char A[91] ={0};
	scanf("%s", s);
	for(int i= 0; s[i] != '\0';i++){
    A[s[i]]++;
	}
	for(int i= 65; i<91;i++){
		if(A[i] != 0) printf("%c : %d\n", i, A[i]);
	}
	return 0;
}