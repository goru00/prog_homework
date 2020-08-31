#include <iostream>
#include <string>
using namespace std;
template <class T>
class Node {
private:
    T data;
    Node* left;
    Node* right;
public:
    Node(T& data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    T getData() { return data; }
    void setData(T& data) { this->data = data; }
    Node* getLeft() { return left; }
    void setLeft(Node* node) { this->left = node; }
    Node* getRight() { return right; }
    void setRight(Node* node) { this->right = node; }
};
template <class T>
class tree {
private:
    Node<T>* root;
public:
    tree() : root(NULL) { }
    void deleteroot(Node<T>*);
    Node<T>* joinTree(Node<T>*, Node<T>*);
    bool deletenode(T&);
    Node<T>* deletenode(bool&, T&);
    bool update(T, T);
    Node<T>* get_root() { return root; }
    Node<T>* insert(T);
    void show() { show(root); }
    void show(Node<T>*);
    Node<T>* find(T);
    bool empty();
};
template <class T>
void tree<T>::deleteroot(Node<T>* n)
{
    if (n)
    {
        deletenode(n->getLeft());
        deletenode(n->getRight());
        delete n;
    }
}
template<class T>
Node<T>* tree<T>::joinTree(Node<T>* ndLeft, Node<T>* ndRight) {
    if (ndLeft == NULL) return ndRight;
    if (ndRight == NULL) return ndLeft;
    Node<T>* nd = ndLeft->getRight();
    if (nd == NULL) {
        ndLeft->setRight(ndRight);
        return ndLeft;
    }
    ndLeft->setRight(joinTree(nd->getLeft(), nd->getRight()));
    nd->setLeft(ndLeft);
    nd->setRight(ndRight);
    return nd;
}
template<class T>
bool tree<T>::deletenode(T& data)
{
    bool flag = false;
    deletenode(flag, data);
    return flag;
}
template<class T>
Node<T>* tree<T>::deletenode(bool &flag, T& data)
{
    if (root == NULL) return NULL;
    Node<T>* parent = root;
    if (data == root->getData()) {

        root = joinTree(root->getLeft(), root->getRight());
        return parent;
    }
    Node<T>* current = root;
    while (current) {
        if (data < current->getData()) {
            parent = current;
            current = current->getLeft();
        }
        else if (data > current->getData()) {
            parent = current;
            current = current->getRight();
        }
        else {
            if (parent->getLeft() == current)
                parent->setLeft(joinTree(current->getLeft(), current->getRight()));
            else
                parent->setRight(joinTree(current->getLeft(), current->getRight()));
            flag = true;
            return current;
        }
    }
    return NULL;
}
template<class T>
bool tree<T>::update(T item1, T item2)
{
    if (deletenode(item1))
    {
        insert(item2);
        return true;
    }
    return false;
}
template <class T>
Node<T>* tree<T>::insert(T data) {
    if (root == NULL) {
        root = new Node<T>(data);
        return root;
    }
    Node<T>* temp = root;
    while (true) {
        if (data < temp->getData()) {
            if (temp->getLeft() == NULL) {
                temp->setLeft(new Node<T>(data));
                return temp->getLeft();
            }
            temp = temp->getLeft();
        }
        else if (data > temp->getData()) {
            if (temp->getRight() == NULL) {
                temp->setRight(new Node<T>(data));
                return temp->getRight();
            }
            temp = temp->getRight();
        }
        else {
            return NULL;
        }
    }
}
template<typename T>
void tree<T>::show(Node<T>* n) {
    if (n) {
        show(n->getLeft());
        cout << n->getData() << endl;
        show(n->getRight());
    }
}
template<typename T>
Node<T>* tree<T>::find(T data) {
    Node<T>* temp = root;
    while (temp != NULL) {
        if (data < temp->getData()) {
            temp = temp->getLeft();
        }
        else if (data > temp->getData()) {
            temp = temp->getRight();
        }
        else {
            break;
        }
    }
    return temp;
}
template<typename T>
bool tree<T>::empty()
{
    return root == NULL;
}
class storage {
private:
    string num_contract;
    string org;
    string street;
    int price;
public:
    storage() : num_contract(""), org(""), street(""), price(0) { }
    storage(string num_contract, string org, string street, int price)
    {
        this->num_contract = num_contract;
        this->org = org;
        this->street = street;
        this->price = price;
    }
    storage(storage& temp) {
        num_contract = temp.num_contract;
        org = temp.org;
        street = temp.street;
        price = temp.price;
    }
    storage* get_Data();
    void set_Data(storage&);
    bool operator <(storage temp) { return (price < temp.price) || ((price == temp.price) && (num_contract < temp.num_contract)); }
    bool operator >(storage temp) { return (price > temp.price) || ((price == temp.price) && (num_contract > temp.num_contract)); }
    bool operator ==(storage temp) { return (price == temp.price) && (num_contract == temp.num_contract); }
    friend bool operator<(const storage&, const storage&);
    friend bool operator>(const storage&, const storage&);
    friend bool operator==(const storage&, const storage&);
    storage& operator =(const storage&);
    friend ostream& operator<< (ostream&, const storage&);
};
storage* storage::get_Data()
{
    storage* temp = new storage();
    temp->num_contract = num_contract;
    temp->org = org;
    temp->street = street;
    temp->price = price;
    return temp;
}
void storage::set_Data(storage& temp) {
    num_contract = temp.num_contract;
    org = temp.org;
    street = temp.street;
    price = temp.price;
}
bool operator<(const storage& arg1, const storage& arg2) {
    return (arg1.price < arg2.price) || ((arg1.price == arg2.price) && (arg1.num_contract < arg2.num_contract));
}
bool operator>(const storage& arg1, const storage& arg2) {
    return (arg2.price < arg1.price) || ((arg2.price == arg1.price) && (arg2.num_contract < arg1.num_contract));
}
bool operator==(const storage& arg1, const storage& arg2) {
    return (arg1.price == arg2.price) && (arg1.num_contract == arg2.num_contract);
}
storage& storage::operator=(const storage& temp)
{
    if (this == &temp) {
        return *this;
    }
    num_contract = temp.num_contract;
    org = temp.org;
    street = temp.street;
    price = temp.price;
    return *this;
}
ostream& operator<<(ostream& out, const storage& arg1)
{
    out.width(10); out << left << arg1.num_contract;
    out.width(24); out << left << arg1.org;
    out.width(44); out << left << arg1.street;
    out.width(12); out << arg1.price << endl;
    return out;
}
int main() {
    setlocale(LC_ALL, "Russian");
    const int n = 6;
    storage tab[] = {
        {"2018-01", "ООО «Топаз»", "г.Котельники, 2-ой проезд, д.23", 200000},
        {"2018-03", "ООО «Вариант»", "г.Дзержинский, Матросова -14", 3000000},
        {"2019-05", "ОАО «Вымпел»", "г.Москва, Таганская -23", 3500000},
        {"2019-07", "ООО «Рога и копыта» ", "г.Одесса, ул.Малая Арнаутская, д.12", 350000},
        {"2020-01", "ОАО «Спартак»", "г.Москва, Кривоколенный пер. -14 стр.3", 1200000},
        {"2020-02", "ООО «Гламур»", "г.Москва, ул. Марксистская, д.25, оф.37", 3000000}
    };
    tree<storage>* trees = new tree<storage>();
    Node<storage>* nd;
    for (int i = 0; i < n; i++) {
        nd = trees->insert(tab[i]);
        if (nd == NULL)
            cout << "NULL" << '\t';
        else cout << tab[i] << '\n';
    }
    cout << endl;
    cout << (trees->empty() ? "Дерево пустое" : "Дерево не пустое") << endl;
    trees->show();
    storage find_element = { "2020-02", "", "", 3000000 };
    if ((nd = trees->find(find_element)) == NULL) cout << "Данная строка не найдена" << endl;
    else {
        cout << nd->getData() << endl;
    }
    find_element = { "2020-02", "ООО «Гламур»", "г. Москва, ул. Марксистская, д.25, оф. 37", 3000000 };
    cout << "Выполним удаление" << endl;
    if ((nd = trees->find(find_element)) == NULL) cout << "Данная строка не найдена" << endl;
    else {
        trees->deletenode(find_element);
        cout << endl;
        trees->show();
        cout << endl;
    }
    storage n_data("2019-05", "ОАО «Самфир»", "г.Москва, Таганская -23", 3500000);
    if (trees->update(tab[2], n_data))
    {
        trees->show();
    }
    else cout << "Такого объекта не существует!" << endl;
    return 0;
}