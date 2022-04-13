#include<iostream>
#include<string>

template<typename U, typename P>
struct T {
    T key;
    P data;
};

template<typename U, typename P>
class Map
{
private:
    int size;
    template<class R>
    class List
    {
    private:
        template<class K>
        class Node
        {
        public:
            T<U, P>* data;
            Node(Node* next = nullptr, T<U, P> * data = T<U, P>()) {
                this->data = data;
                this->next = next;
            }
        };
    public:
        Map() {
            
        }
        void insert() {

        }
    };
public:
    Map() {}
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
    friend std::ostream& operator<<(std::ostream& out, const Data& arg) {
        out << "[" << arg.id << " " << arg.name << " " << arg.direction << " " << arg.price << "]";
        return out;
    }
};

int main() {
    const int N = 6;
    Data mass[] = {
        Data(2345, "Иванов Сергей Степанович", "Разнорабочий", 28000),
        Data(2346, "Краснов Сергей Георгиевич", "Сантехник", 32000),
        Data(2347, "Бендер Остап Ибрагимович", "Директор", 62000),
        Data(2349, "Петров Сергей Степанович", "Электрик", 36000),
        Data(2356, "Кирпичев Владимир Викторович", "Начальник смены", 48000),
        Data(2378, "Абрамов Иван Петрович", "Электрик", 36000)
    };
    return 0;
}