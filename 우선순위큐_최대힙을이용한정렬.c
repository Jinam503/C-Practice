#include<stdio.h>
#include<stdlib.h>
//우선순위 큐
//우선순위큐의 추상자료형
//객체: n개의 element형의 우선순위를 가진 요소들의 모임
//연산 create() :=우선순위큐 생성
//init(q), is_empty(q),is_full(q),insert(q,x) ,delete(q),find(q)
//
//우선순위큐는 0개 이상의 요소 모임
//최소순위큐 
#define MAX_ELEMENT 200
#define element int
typedef struct{
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;
HeapType* create(){
	return (HeapType*)malloc(sizeof(HeapType));//
}
void init(HeapType* h){
	h->heap_size= 0;//
}
//현재 요소의 개수가 heap_size인 히프 h에 item 삽입 
void insert_max_heap(HeapType* h, element item){
    int i;
    i = ++(h->heap_size);//
    //트리를 거슬러 올라가면서 부모노드와 비교하는 과정
    while(i!=1 && item > h->heap[i/2]/**/){
       h->heap[i]  = h->heap[i/2];
       i /=2;//
    }
    h->heap[i]=item;//  //새로운 노드를 삽입
}
//삭제함수 
element delete_max_heap(HeapType* h){
    int parent, child;
    element item, temp;
    item = h->heap[1];//
	  temp = h->heap[h->heap_size--];//
    parent = 1;//
	  child = 2;//
    while(child <= h->heap_size){
		//현재 노드의 자식 노드 중 더 큰 자식 노드를 검색
		if (child < h->heap_size && h->heap[child] < h->heap[child+1]/*오른쪽노드*/ )
			child++;
		//검색된 자식노드가 말단노드이면 아래로 이동안함.	
		if (temp >= h->heap[child] ) break; 
		//한단계 아래로 이동
		h->heap[parent] = h->heap[child];//
		parent = child;//
		child *= 2;
	}
	h->heap[parent] = temp;//
	return item;
}
//우선순위 큐인 히프를 이용한 정렬
void heap_sort(element a[], int n){
	int i;
	HeapType* h;
	h=create(); //힙 생성
	h->heap_size = 0;
	for(i=0;i<n;i++){
		insert_max_heap(h,a[i]);
	}
	for(i=n-1;i>=0;i--){
		a[i]=delete_max_heap(h);//최대힙 삭제
	}
	free(h);
	
} 
#define SIZE 8
int main(){
	element list[SIZE]={23,56,11,9,56,99,27,34};
	heap_sort(list,SIZE);
	for(int i =0;i<SIZE;i++){
		printf("%d ",list[i]);
	}
	printf("\n");
	
	return 0;
} 


