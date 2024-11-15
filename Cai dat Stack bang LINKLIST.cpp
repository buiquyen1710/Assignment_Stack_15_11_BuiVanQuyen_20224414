#include<iostream>
#include<climits> //De dung cho INT_MIN
using namespace std;

struct Listnode{
	int data;
	Listnode* next;
};
struct Stack{
	Listnode* top;
};

//Tao mot stack moi
Stack* createstack(){
	Stack* stack = new Stack;
	stack -> top = NULL; //khoi tao top la NULL
	return stack;
}

//Ham them phan tu vao Stack
void Push(Stack* stack, int data){
	Listnode* temp = new listnode;
	if(!temp){
		cout <<"khong the cap phat bo nho";
		return;
	}
	temp -> data = data;
	temp -> next = stack->top;
	stack->top = temp;
}

//Ham kiem tra stack rong
bool isemptystack(Stack* stack){
	return stack->top= NULL;
}

//Ham lay phan tu khoi stack va xoa no
int Pop(Stack *stack){
	if(isemptystack(stack)){
		cout <<"Stack dang rong";
		return INT_MIN;
	}
	Listnode* temp = stack->top;
	stack->top= stack->top->next;
	int data = temp->data;
	delete temp;
	return data;
}

//Ham de lay phan tu tren cung ma khong xoa no
int Top(Stack* stack){
	if(isemptystack(stack)){
		cout << "stack dang rong";
		return INT_MIN;
	}
	return stack->top->data;
}

//Ham xoa toan bo stack
void deletestack(Stack* stack){
	ListNode* temp;
	while(stack->top){
		temp = stack->top;
		stack->top=stack->top->next;
		delete temp;
	}
	delete stack;
}









 
