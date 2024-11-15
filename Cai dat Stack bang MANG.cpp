#include <iostream>
using namespace std;

#define MAXSIZE 10
struct ArrayStack{
	int top;
	int capacity;
	int* array; 
};

//Ham khoi tao ngan xep 
ArrayStack* createarraystack(){
	ArrayStack* stack = new ArrayStack;
	stack->capacity = MAXSIZE;
	stack->top = -1;
	stack->array = new int[stack->capacity];
	return stack; 
} 
//Kiem tra ngan xep co rong khong
bool isempty(const ArrayStack* stack){
	return(stack->top == -1); 
} 
//Kiem tra ngan xep co day khong 
bool isfull(const ArrayStack* stack){
	return(stack->top == stack->capacity -1); 
} 
//Them phan tu vao ngan xep
void push(ArrayStack* stack, int data){
	if(isfull(stack)){
		cout << "Stack da day!"<<endl; 
	} else{
		stack->array[stack->top] =data; 
	} 
} 
//Lay phan tu ra khoi ngan xep
int pop(ArrayStack* stack){
	if(isempty(stack)){
		cout << "Stack rong"<<endl; 
		return INT_MIN; 
	} else{
		return stack->array[stack->top--]; 
	} 
} 
//Giai phong bo nho cua ngan xep
void deletestack(ArrayStack* stack){
	if(stack){
		delete[] stack->array;
		delete stack; 
	} 
} 


 
