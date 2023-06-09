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

    bool is_empty() { //проверка на пустоту списка, выводит 1 при пустом и 0 при обратном
        return front == nullptr;
    }

    //1. Добавления элемента в конец
    void push_back(int value) { //добавляем значения в конец
        Node* newNode = new Node();
        if (is_empty()) { //если он пустой, то присваивается одно значение к первому и ко второму
            front = newNode;
            return;
        }
        Node* curr = front;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    //2. Добавления элемента в начало
    void push_before(int value) { //добавляем значение в начало
        Node* newNode = new Node();
        if (is_empty()) { //если он пустой, то присваивается одно значение к первому и ко второму
            front = newNode;
            return;
        }
        newNode->next = front; //сама написала не поняла че
        front = newNode;
    }

    //3. Добавление в заданную позицию
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

    //4. Удаление элемента по значению
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

    //удаление первого элемента
    void remove_first() {
        if (is_empty())
            return; //если пустое - выход
        Node* curr = front; //указатель на первый
        front = curr->next; //значение первого места уходит к следующему узлу
        delete curr; //удаляем тот первый узел
    }
    //удаление последнего
  
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

    //6. поиск элемента по значению
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
    //7. поиск элемента по позиции
    int find_pos(int index) {
        Node* curr = front; //указатель на первый узел списка
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->value;
    }

    //8. Печать списка
    void print() { //вывод списка на экран
        if (is_empty()) return; //если там пусто
        Node* curr = front; //указатель на первый узел списка
        while (curr) { //пока p не пустой - выводим значение р и едем дальше
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    int peek() { // получение значения первого элемента очереди
        if (front == NULL) { // если очередь пуста
            return -1; // вернуть некорректное значение
        }
        return front->value;
    }

    int intop() { // получение значения первого элемента очереди
        if (front != NULL) { // если очередь пуста
            return front->value; // вернуть некорректное значение
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
    //Функция для вывода о пустом стеке
    int empty() {
        cout << "Stack is empty!" << endl;
        return -1;
    }

    bool is_empty() { //проверка на пустоту списка, выводит 1 при пустом и 0 при обратном
        return front == nullptr;
    }

    // Функция для добавления элемента в стек
    void push(int value) {
        list.push_back(value);
    }
    // Функция для удаления элемента из стека
    int pop() {
        if (is_empty()) {
            empty();
            return 0;
        }
        int val = list.searchByPosition(1);
        list.removeByPosition(1);
        return val;
    }
    

    int intop() { // получение значения первого элемента очереди
        return list.find_pos(1);
    }
};


class Func {
public:

    // Функция для проверки, является ли символ оператором
    bool mathematical_oper(char symbol) {
        return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
    }
    // Функция для вывода ошибки
    int error() {
        cout << "Error! Invalid expression!" << endl;
        return -1;
    }
    // Функция для ранжирования символов
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

    int peek() { // получение значения первого элемента очереди
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

// Функция преобразования из инфикстной в постфиксную
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
                stack.pop(); // Удаляем открывающую скобку из стека
            }
            else { // Если текущий символ - оператор
                while (!stack.is_empty() && function.priority(symbol) <= function.priority(stack.intop())) {
                    queue.push(stack.intop());
                    stack.pop();
                }
                stack.push(symbol);
            }
        }
        
        while (!stack.is_empty()) { // Удаляем операторы из стека
            queue.push(stack.intop());
            stack.pop();
        }
        string postfix;
        while (!queue.is_empty()) { // Формируем и возвращаем выходную строку
            postfix.push_back(queue.peek());
            queue.pop();
        }
        return postfix;
    }
};

// Функция для вычисления значения выражения обратной польской нотации
class SolutionPostfix {
public:
    Stack stack;
    Func function;
    int result(string expr) {
        int size = expr.length();
        int res;
        for (int i = 0; i < size; i++) { //цикл прохождения по строке
            char symbol = expr[i];
            if (symbol == ' ') {
                continue;
            }
            else if (isdigit(symbol)) { //проверка символа на i позиции в строке на является ли оно числом
                int value = symbol - '0';
                stack.push(value);
            }
            else if (function.mathematical_oper(symbol)) { //математическая операция
                int num2 = stack.pop(); //извлекаем верхнее число из стека
                int num1 = stack.pop(); //извлекаем следубщее число из стека
                if (symbol == '+') { //дальше он сравнивает символ с текущим и проводит соответстующую операцию
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
                        cout << "Division by zero is not allowed!" << endl; //если делим на 0 - выдается ошибка
                        return -1;
                    }
                    res = num1 / num2;
                    stack.push(res);
                }
            }
            else {
                function.error(); //если ввод некорректный - выводится ошибка
                return -1;
            }
        }
        if (stack.is_empty()) { //если ввода нет, то ошибка
            function.error();
            return -1;
        }
        int result = stack.pop(); //берём верхний элемент стека и присваиваем заначение результату 
        if (!stack.is_empty()) { //если в стеке еще что-то есть, то ошибка
            function.error();
            return -1;
        }
        return result; //если нет ошибок, то вернется результат, если они были - "-1"
    }
};

int main() {
    string str;
    SolutionPostfix solution;
    FrominfixToPostfix FromItoP;
    cout << "Enter the expression: ";
    getline(cin, str);
    if (str.length() < 3) { //при длине выражения меньше 3 элементов выдастся ошибка, так как недостаточно элементов
        cout << "Expression is not correct!!" << endl;
    }
    else {
        //string res = FromItoP.express(str);
        int res1 = solution.result(str);
        if (res1 != -1) { //тк Solution интовая, то при ошибке выводится соо об ошибке и возвращается -1, которое можно не выовдить
            cout << "Expressiion result: " << res1 << endl;
        }
    }
}