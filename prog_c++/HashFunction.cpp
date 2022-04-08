#include<iostream>
#include<string>

template<class T>
class List
{
private:
    template<class T>
    class Node
    {
    public:
        T data;
        Node* next;
        Node(T data = T(), Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
        Node(Node* n, Node* next = nullptr) {
            this->data = n->data;
            this->next = next;
        }
    };
    Node<T>* head;
    int size;
public:
    List() {
        head = nullptr;
        size = 0;
    }
    void pushBack(T data) {
        if (head == nullptr) {
            head = new Node<T>(data);
        }
        else {
            Node<T>* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = new Node<T>(data);
        }
        ++size;
    }
    bool isEmpty() { return head == nullptr; }
    friend std::ostream& operator<<(std::ostream& out, const List<T>& arg) {
        Node<T>* curr = arg.head;
        while (curr) {
            out << "-->" << curr->data;
            curr = curr->next;
        }
        return out;
    }
};

class Data {
private:
    int id;
    std::string name;
    std::string direction;
    int price;
public:
    Data() {
        this->id = 0;
        this->name = "";
        this->direction = "";
        this->price = 0;
    }
    Data(int id, std::string name, std::string direction, int price) {
        this->id = id;
        this->name = name;
        this->direction = direction;
        this->price = price;
    }
    friend int operator%(const Data& arg, int val) {
        if (val == 0) {
            throw std::runtime_error("zero division error");
        }
        return arg.id % val;
    }
    friend std::ostream& operator<<(std::ostream& out, const Data& arg) {
        out << "[" << arg.id << " " << arg.name << " " << arg.direction << " " << arg.price << "]";
        return out;
    }
};

template<class T>
class Hash
{
private:
    int K;
    List<T>* blocks;
    int checkPrime(int n) {
        if (n == 1 || n == 0) {
            return 0;
        }
        for (int i = 2; i < n / 2; i++) {
            if (n % i == 0) {
                return 0;
            }
        }
        return 1;
    }
    int getPrime(int n) {
        if (n % 2 == 0) {
            n++;
        }
        while (!checkPrime(n)) {
            n = n + 2;
        }
        return n;
    }
    int hashFunction(T key) {
        return key % K;
    }
public:
    Hash(int size) {
        this->K = getPrime(size);
        blocks = new List<T>[K];
    }
    void insert(T data) {
        int index = hashFunction(data);
        blocks[index].pushBack(data);
    }
    void show() {
        for (int index = 0; index < K; index++) {
            std::cout << "ячейка[" << index << "]" << blocks[index] << std::endl;
        }
    }
};

int main() {
    setlocale(0, "");
    const int N = 6;
    Data mass[] = {
        Data(2345, "Иванов Сергей Степанович", "Разнорабочий", 28000),
        Data(2346, "Краснов Сергей Георгиевич", "Сантехник", 32000),
        Data(2347, "Бендер Остап Ибрагимович", "Директор", 62000),
        Data(2349, "Петров Сергей Степанович", "Электрик", 36000),
        Data(2356, "Кирпичев Владимир Викторович", "Начальник смены", 48000),
        Data(2378, "Абрамов Иван Петрович", "Электрик", 36000)
    };
    Hash<Data> table(N);
    for (int index = 0; index < N; index++) {
        table.insert(mass[index]);
    }
    table.show();
    return 0;
}