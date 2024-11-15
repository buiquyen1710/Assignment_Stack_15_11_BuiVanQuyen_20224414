#include<iostream>
#include<string>
using namespace std;

#define INITIAL_CAPACITY 2

// Khai báo c?u trúc cho m?t thanh g?
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

// Hàm ki?m tra stack có r?ng không
bool isemptystack(stackgo* stack) {
    return stack->top == -1; 
}

// Hàm ki?m tra stack có ð?y không
bool isfullstack(stackgo* stack) {
    return stack->top == stack->capacity - 1; 
}

// Hàm tãng g?p ðôi kích thý?c stack khi ð?y
void doublestack(stackgo* stack) {
    stack->capacity *= 2;
    go* newarray = new go[stack->capacity];
    for (int i = 0; i <= stack->top; i++) {
        newarray[i] = stack->array[i]; 
    } 
    delete[] stack->array;
    stack->array = newarray; 
}

// Hàm thêm m?t thanh g? vào stack
void Push(stackgo* stack, go GO) {
    if (isfullstack(stack)) {
        doublestack(stack); 
    } 
    stack->array[++stack->top] = GO; 
}

// Hàm ð?m s? lý?ng thanh g? hi?n có trong stack có tu?i c? th?
int countByAge(stackgo* stack, int age) {
    int count = 0;
    for (int i = 0; i <= stack->top; i++) {
        if (stack->array[i].time == age) {
            count++;
        }
    }
    return count;
}

// Hàm h?y stack 
void deletestack(stackgo* stack) {
    if (stack) {
        delete[] stack->array;
        delete stack; 
    } 
}

int main() {
    stackgo* goloai1 = createstack();
    stackgo* goloai2 = createstack();
    
    // Thêm các thanh g? vào các kho
    Push(goloai1, {"Lo?i 1", 5, 30});
    Push(goloai1, {"Lo?i 1", 10, 30});
    Push(goloai1, {"Lo?i 1", 8, 25});
    Push(goloai2, {"Lo?i 2", 7, 60});
    Push(goloai2, {"Lo?i 2", 5, 30});

   
    int age;
    cout << "Nh?p tu?i g? c?n ð?m: ";
    cin >> age;

   
    int count_goloai1 = countByAge(goloai1, age);
    int count_goloai2 = countByAge(goloai2, age);
    
    cout << "S? lý?ng thanh g? có tu?i " << age << " trong goloai1: " << count_goloai1 << endl;
    cout << "S? lý?ng thanh g? có tu?i " << age << " trong goloai2: " << count_goloai2 << endl;
    
    // H?y stack sau khi dùng
    deletestack(goloai1);
    deletestack(goloai2);
    
    return 0;
}

