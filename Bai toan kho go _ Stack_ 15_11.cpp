#include<iostream>
#include<string>
using namespace std;

#define INITIAL_CAPACITY 2

// Khai b�o c?u tr�c cho m?t thanh g?
struct go {
    string type;
    int size;
    int time; 
};

struct stackgo {
    int top;
    int capacity;
    go* array; 
};

stackgo* createstack() {
    stackgo* stack = new stackgo;
    stack->capacity = INITIAL_CAPACITY;
    stack->top = -1;
    stack->array = new go[stack->capacity];
    return stack; 
}

// H�m ki?m tra stack c� r?ng kh�ng
bool isemptystack(stackgo* stack) {
    return stack->top == -1; 
}

// H�m ki?m tra stack c� �?y kh�ng
bool isfullstack(stackgo* stack) {
    return stack->top == stack->capacity - 1; 
}

// H�m t�ng g?p ��i k�ch th�?c stack khi �?y
void doublestack(stackgo* stack) {
    stack->capacity *= 2;
    go* newarray = new go[stack->capacity];
    for (int i = 0; i <= stack->top; i++) {
        newarray[i] = stack->array[i]; 
    } 
    delete[] stack->array;
    stack->array = newarray; 
}

// H�m th�m m?t thanh g? v�o stack
void Push(stackgo* stack, go GO) {
    if (isfullstack(stack)) {
        doublestack(stack); 
    } 
    stack->array[++stack->top] = GO; 
}

// H�m �?m s? l�?ng thanh g? hi?n c� trong stack c� tu?i c? th?
int countByAge(stackgo* stack, int age) {
    int count = 0;
    for (int i = 0; i <= stack->top; i++) {
        if (stack->array[i].time == age) {
            count++;
        }
    }
    return count;
}

// H�m h?y stack 
void deletestack(stackgo* stack) {
    if (stack) {
        delete[] stack->array;
        delete stack; 
    } 
}

int main() {
    stackgo* goloai1 = createstack();
    stackgo* goloai2 = createstack();
    
    // Th�m c�c thanh g? v�o c�c kho
    Push(goloai1, {"Lo?i 1", 5, 30});
    Push(goloai1, {"Lo?i 1", 10, 30});
    Push(goloai1, {"Lo?i 1", 8, 25});
    Push(goloai2, {"Lo?i 2", 7, 60});
    Push(goloai2, {"Lo?i 2", 5, 30});

   
    int age;
    cout << "Nh?p tu?i g? c?n �?m: ";
    cin >> age;

   
    int count_goloai1 = countByAge(goloai1, age);
    int count_goloai2 = countByAge(goloai2, age);
    
    cout << "S? l�?ng thanh g? c� tu?i " << age << " trong goloai1: " << count_goloai1 << endl;
    cout << "S? l�?ng thanh g? c� tu?i " << age << " trong goloai2: " << count_goloai2 << endl;
    
    // H?y stack sau khi d�ng
    deletestack(goloai1);
    deletestack(goloai2);
    
    return 0;
}

