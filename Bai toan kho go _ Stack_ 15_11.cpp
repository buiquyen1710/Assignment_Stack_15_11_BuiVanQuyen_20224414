#include<iostream>
#include<string>
using namespace std;

#define INITIAL_CAPACITY 2
//Khai bao cau truc cho mot thanh go
struct go{
	string type;
	int size;
	int time; 
}; 
struct stackgo{
	int top;
	int capacity;
	go* array; 
}; 
stackgo* createstack(){
	stackgo* stack = new stackgo;
	stack->capacity = INITIAL_CAPACITY;
	stack->top = -1;
	stack->array = new go[stack->capacity];
	return stack; 
} 
// Ham kiem tra stack co rong khong
bool isemptystack(stackgo* stack){
	return stack->top == -1; 
} 
// Ham kiem tra stack co day khong
bool isfullstack(stackgo* stack){
	return stack->top == stack->capacity-1; 
} 
//Ham tang gap doi kich thuoc stack khi full
void doublestack(stackgo* stack){
	stack->capacity *=2;
	go* newarray = new go[stack->capacity];
	for(int i=0; i<=stack->top; i++){
		newarray[i]=stack->array[i]; 
	} 
	delete[] stack->array;
	stack->array = newarray; 
} 
//Ham them mot thanh go vao stack
void Push(stackgo* stack, go GO){
	if(isfullstack(stack)){
		doublestack(stack); 
	} 
	stack->array[++stack->top] = GO; 
}
 //Ham dem so luong thanh go hien co trong stack
 int count(stackgo* stack){
 	return stack->top+1; 
 } 
 //Ham huy stack 
 void deletestack(stackgo* stack){
 	if(stack){
 		delete[] stack->array;
		delete stack; 
	 } 
 } 


int main(){
	stackgo* goloai1 = createstack();
	stackgo* goloai2 = createstack();
	Push(goloai1,{"1", 5, 30});
	Push(goloai2,{"2", 7, 60});
	
	//Dem so luong thanh go trong kho
	 cout <<"So luong thanh go: "<< count(goloai1)+count(goloai2);
	 deletestack(goloai1);
	 deletestack(goloai2);
	 return 0; 
	 
} 













 
