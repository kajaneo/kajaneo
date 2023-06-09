#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int value;
    Node* next;
};

//list
class List {
public:
    Node* front;
    int size;

    List() {
        front == NULL;
    }

    bool is_empty() { //�������� �� ������� ������, ������� 1 ��� ������ � 0 ��� ��������
        return front == nullptr;
    }

    //1. ���������� �������� � �����
    void push_back(int value) { //��������� �������� � �����
        Node* newNode = new Node();
        if (is_empty()) { //���� �� ������, �� ������������� ���� �������� � ������� � �� �������
            front = newNode;
            return;
        }
        Node* curr = front;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    //2. ���������� �������� � ������
    void push_before(int value) { //��������� �������� � ������
        Node* newNode = new Node();
        if (is_empty()) { //���� �� ������, �� ������������� ���� �������� � ������� � �� �������
            front = newNode;
            return;
        }
        newNode->next = front; //���� �������� �� ������ ��
        front = newNode;
    }

    //3. ���������� � �������� �������
    void add_num(int value, int index) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (index == 1) {
            newNode->next = front;
            front = newNode;
            return;
        }
        Node* curr = front;
        for (int i = 1; i < index - 1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    //4. �������� �������� �� ��������
    void delete_val(int value) {
        Node* temp = front;
        Node* prev = NULL;
        if (temp != NULL && temp->value == value) {
            front = temp->next;
            delete temp;
            return;
        }
        while (temp != NULL && temp->value != value) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) { return; }
        prev->next = temp->next;
        delete temp;
    }

    //�������� ������� ��������
    void remove_first() {
        if (is_empty())
            return; //���� ������ - �����
        Node* curr = front; //��������� �� ������
        front = curr->next; //�������� ������� ����� ������ � ���������� ����
        delete curr; //������� ��� ������ ����
    }
    //�������� ����������
  
    void removeByPosition(int position) {
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (position == 1) {
            if (front == nullptr) {
                cout << "List is empty!" << endl;
                return;
            }
            Node* temp = front;
            front = front->next;
            delete temp;
            return;
        }
        Node* curr = front;
        int currPosition = 1;
        while (curr != nullptr && currPosition < position - 1) {
            curr = curr->next;
            currPosition++;
        }
        if (curr == nullptr || curr->next == nullptr) {
            std::cout << "Invalid position!" << endl;
            return;
        }
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }

    //6. ����� �������� �� ��������
    int find_val(int value) {
        Node* curr = front;
        int index = 0;
        if (is_empty()) return -1;
        else {
            while (curr != nullptr) {
                if (curr->value == value) return index;
                curr = curr->next;
                index++;
            }
            return -1;
        }
    }
    //7. ����� �������� �� �������
    int find_pos(int index) {
        Node* curr = front; //��������� �� ������ ���� ������
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->value;
    }

    //8. ������ ������
    void print() { //����� ������ �� �����
        if (is_empty()) return; //���� ��� �����
        Node* curr = front; //��������� �� ������ ���� ������
        while (curr) { //���� p �� ������ - ������� �������� � � ���� ������
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    int peek() { // ��������� �������� ������� �������� �������
        if (front == NULL) { // ���� ������� �����
            return -1; // ������� ������������ ��������
        }
        return front->value;
    }

    int intop() { // ��������� �������� ������� �������� �������
        if (front != NULL) { // ���� ������� �����
            return front->value; // ������� ������������ ��������
        }
        return -1;
    }

    int searchByPosition(int position) {
        if (position <= 0) {
            return -1;
        }

        Node* current = front;
        int currentPosition = 1;
        while (current != nullptr && currentPosition < position) {
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr) {
            return -1;
        }

        return current->value;
    }
};

//stack
class Stack {
private:
    List list;
    
public:
    Node* front;
    //������� ��� ������ � ������ �����
    int empty() {
        cout << "Stack is empty!" << endl;
        return -1;
    }

    bool is_empty() { //�������� �� ������� ������, ������� 1 ��� ������ � 0 ��� ��������
        return front == nullptr;
    }

    // ������� ��� ���������� �������� � ����
    void push(int value) {
        list.push_back(value);
    }
    // ������� ��� �������� �������� �� �����
    int pop() {
        if (is_empty()) {
            empty();
            return 0;
        }
        int val = list.searchByPosition(1);
        list.removeByPosition(1);
        return val;
    }
    

    int intop() { // ��������� �������� ������� �������� �������
        return list.find_pos(1);
    }
};


class Func {
public:

    // ������� ��� ��������, �������� �� ������ ����������
    bool mathematical_oper(char symbol) {
        return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
    }
    // ������� ��� ������ ������
    int error() {
        cout << "Error! Invalid expression!" << endl;
        return -1;
    }
    // ������� ��� ������������ ��������
    int priority(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }
};

//queue
class Queue {
private:
    List list;
    Node* front;
public:
    
    void push(int value) {
        list.push_back(value);
    }

    int pop() {
        int val = list.find_pos(1);
        list.removeByPosition(1);
        return val;;
    }

    bool is_empty() {
        return front == nullptr;
    }

    int peek() { // ��������� �������� ������� �������� �������
        return list.find_pos(1);
    }

    void display() {
        Node* temp = new Node;
        if (front == NULL) {
            cout << "The queue is empty." << endl;
            return;
        }
        temp = front;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ������� �������������� �� ���������� � �����������
class  FrominfixToPostfix {
public:
    Stack stack;
    Queue queue;
    Func function;
    string express(string exp) {
        for (int i = 0; i < exp.length(); i++) {
            char symbol = exp[i];
            if (symbol == ' ') {
                continue;
            }
            if (isalnum(symbol)) {
                queue.push(symbol);
            }
            else if (symbol == '(') {
                stack.push(symbol);
            }
            else if (symbol == ')') {
                while (!stack.is_empty() && stack.intop() != '(') {
                    queue.push(stack.intop());
                    stack.pop();
                }
                stack.pop(); // ������� ����������� ������ �� �����
            }
            else { // ���� ������� ������ - ��������
                while (!stack.is_empty() && function.priority(symbol) <= function.priority(stack.intop())) {
                    queue.push(stack.intop());
                    stack.pop();
                }
                stack.push(symbol);
            }
        }
        
        while (!stack.is_empty()) { // ������� ��������� �� �����
            queue.push(stack.intop());
            stack.pop();
        }
        string postfix;
        while (!queue.is_empty()) { // ��������� � ���������� �������� ������
            postfix.push_back(queue.peek());
            queue.pop();
        }
        return postfix;
    }
};

// ������� ��� ���������� �������� ��������� �������� �������� �������
class SolutionPostfix {
public:
    Stack stack;
    Func function;
    int result(string expr) {
        int size = expr.length();
        int res;
        for (int i = 0; i < size; i++) { //���� ����������� �� ������
            char symbol = expr[i];
            if (symbol == ' ') {
                continue;
            }
            else if (isdigit(symbol)) { //�������� ������� �� i ������� � ������ �� �������� �� ��� ������
                int value = symbol - '0';
                stack.push(value);
            }
            else if (function.mathematical_oper(symbol)) { //�������������� ��������
                int num2 = stack.pop(); //��������� ������� ����� �� �����
                int num1 = stack.pop(); //��������� ��������� ����� �� �����
                if (symbol == '+') { //������ �� ���������� ������ � ������� � �������� �������������� ��������
                    res = num1 + num2;
                    stack.push(res);
                }
                else if (symbol == '-') {
                    res = num1 - num2;
                    stack.push(res);
                }
                else if (symbol == '*') {
                    res = num1 * num2;
                    stack.push(res);
                }
                else if (symbol == '/') {
                    if (num2 == 0) {
                        cout << "Division by zero is not allowed!" << endl; //���� ����� �� 0 - �������� ������
                        return -1;
                    }
                    res = num1 / num2;
                    stack.push(res);
                }
            }
            else {
                function.error(); //���� ���� ������������ - ��������� ������
                return -1;
            }
        }
        if (stack.is_empty()) { //���� ����� ���, �� ������
            function.error();
            return -1;
        }
        int result = stack.pop(); //���� ������� ������� ����� � ����������� ��������� ���������� 
        if (!stack.is_empty()) { //���� � ����� ��� ���-�� ����, �� ������
            function.error();
            return -1;
        }
        return result; //���� ��� ������, �� �������� ���������, ���� ��� ���� - "-1"
    }
};

int main() {
    string str;
    SolutionPostfix solution;
    FrominfixToPostfix FromItoP;
    cout << "Enter the expression: ";
    getline(cin, str);
    if (str.length() < 3) { //��� ����� ��������� ������ 3 ��������� �������� ������, ��� ��� ������������ ���������
        cout << "Expression is not correct!!" << endl;
    }
    else {
        //string res = FromItoP.express(str);
        int res1 = solution.result(str);
        if (res1 != -1) { //�� Solution �������, �� ��� ������ ��������� ��� �� ������ � ������������ -1, ������� ����� �� ��������
            cout << "Expressiion result: " << res1 << endl;
        }
    }
}