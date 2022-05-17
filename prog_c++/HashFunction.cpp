#include<iostream>
#include<string>
#include<cstring>

template<class T>
class List
{
private:
    template<class U>
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
    // структура для хранения ключа(-ей)
    struct Key {
        int id;
        std::string name;
        int code;

        Key() : id(0), name("") { }

        Key(int id, std::string name) {
            this->id = id;
            this->name = name;
            code = this->id;
            const char * str = name.c_str();
            for (int index = 0; index < strlen(str); index++) {
                int cc = static_cast<unsigned char>(str[index]);
                code += cc;
            }
        }
        
    };

    // структура для хранения остальных данных
    struct Value {
        std::string direction;
        int price;

        Value() : direction(""), price(0) { }

        Value(std::string direction, int price) {
            this->direction = direction;
            this->price = price;
        }
    };
    Key *key;
    Value *value;
public:
    Data() {
        key = new Key();
        value = new Value();
    }
    Data(int id, std::string name, std::string direction, int price) {
        key = new Key(id, name);
        value = new Value(direction, price);
    }
    friend int operator%(const Data& arg, int val) {
        
        /*if (val == 0) {
            throw std::runtime_error("zero division error");
        }*/
        return arg.key->code % val;
    }
    friend std::ostream& operator<<(std::ostream& out, const Data& arg) {
        out << "[" << arg.key->id << " " << arg.key->name << " " << arg.value->direction << " " << arg.value->price << "]";
        return out;
    }
};


// класс хеш-функции
template<class T>
class Hash
{
private:
    // размерность массива (условно хеш-таблицы) 
    int K;
    // массив указателей на объекты класса списка
    List<T>* blocks; 
    // методы получения точного размера хеша
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
    // нахождение индекса в хеш-таблице с помощью метода деления
    // можно использовать другие методы (например, универсальное хеширование, которое не зависит от ключевых полей в исходных данных,
    // а просто рандомно выбирает ячейку в массиве)

    int hashFunction(T key) {
        return key % K;
    }
public:
    // передаем в конструктор размерность хеш-таблицы, инициализируем массив с указателями на объекты списка 
    Hash(int size) {
        this->K = getPrime(size);
        blocks = new List<T>[K];
    }
    // 1. находим индекс куда вставлять данные в хеш-таблицы
    // 2. после того, как нашли индекс массива хеш-таблицы, создаем (если в этой ячейке head == null) список и вставляем данные
    // (если список по этому индексу хеш-таблицы уже создан, то вставляем данные в конец списка)

    // теория: предполагается, что в хеш-таблице в каждой её ячейке существует только один набор данных (например, Вася Пупкин)
    // если оказывается так, что после нахождения индекса куда нужно вставлять уже содержатся данные (например, Вася Пупкин --> Иван Иванов),
    // то такой случай называют "коллизией"
    // избежать коллизии практически невозможно, если только изменить размерность самой хеш-таблицы

    void insert(T data) {
        int index = hashFunction(data);
        blocks[index].pushBack(data);
    }
    // вывод хеш-таблицы
    void show() {
        for (int index = 0; index < K; index++) {
            std::cout << "ячейка[" << index << "]" << blocks[index] << std::endl;
        }
    }
};

int main() {
    setlocale(0, "");
    // здесь можно попробовать поизменять размерность хеш-таблицы
    const int N = 4;
    Data mass[] = {
        Data(2345, "Иванов Сергей Степанович", "Разнорабочий", 28000),
        Data(2346, "Краснов Сергей Георгиевич", "Сантехник", 32000),
        Data(2347, "Бендер Остап Ибрагимович", "Директор", 62000),
        Data(2349, "Петров Сергей Степанович", "Электрик", 36000),
        Data(2356, "Кирпичев Владимир Викторович", "Начальник смены", 48000),
        Data(2378, "Абрамов Иван Петрович", "Электрик", 36000)
    };
    Hash<Data> table(N);
    for (int index = 0; index < sizeof(mass) / sizeof(Data); index++) {
        table.insert(mass[index]);
    }
    table.show();
    return 0;
}