#include<iostream>
#include<string>

class List 
{
private:
    class Node
    {
    public:
        int key;
        std::string val;
        Node * next;
        Node(int key, std::string val) {
            this->key = key;
            this->val = val;
            this->next = nullptr;
        }
        Node(Node * n) {
            this->key = n->key;
            this->val = n->val;
            this->next = nullptr;
        }
    };
    Node * head;
    int size; 
public:
    List() {
        head = nullptr;
        size = 0;
    }
    void pushBack(Node * n) {
        if (head == nullptr) {
            head = new Node(n);
            return;
        } else {
            Node * curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = n;
        }
    }
    void pushBack(int key, std::string val) {
        if (head == nullptr) {
            head = new Node(key, val);
            return;
        } else {
            Node * curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = new Node(key, val);
        }
    }
    void show() {
        if (isEmpty()) return;
        Node * curr = head;
        while (curr) {
            std::cout << "Ключ: " << curr->key << " " << curr->val << std::endl;
            curr = curr->next;
        }
    }
    bool isEmpty() { return head == nullptr; }
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
        this->name = nullptr;
        this->direction = nullptr;
        this->price = 0;
    }
    Data(int id, std::string name, std::string direction, int price) {
        this->id = id;
        this->name = name;
        this->direction = direction;
        this->price = price;
    }
    friend std::ostream& operator<<(std::ostream& out, const Data& arg) {
        out << arg.id << " " << arg.name << " " << arg.direction << " " << arg.price << std::endl;
        return out;
    }
};

int main() {
    List * list = new List();
    list->pushBack(10, "gjerigjioerjogr");
    list->pushBack(12, "gerjgioerjiogjioergoer");
    list->show();
    return 0;
}