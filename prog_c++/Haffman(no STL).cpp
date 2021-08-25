#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>

using namespace std;

class Data
{
private:
    char *symb;
    int *weight;
    int size;
public:
    Data() : symb(NULL), weight(NULL), size(0) { }
    Data(int size)
    {
        symb = new char[size];
        weight = new int[size];
        this->size = size;
    }
    int& operator[](const char index)
    {
        for (int i = 0; i < size; i++)
        {
            if (symb[i] == index) {
                return weight[i];
            }
        }
    }
};

class Haffman
{
public:
    class Node
    {
    public:
        Node* right, * left, * next;
        char symb;
        int weight;
        Node(Node* next)
        {
            symb = 0;
            weight = 0;
            right = left = NULL;
            this->next = next;
        }
        Node(Node* right, Node* left)
        {
            this->right = right;
            this->left = left;
            weight = right->weight + left->weight;
            next = NULL;
            symb = NULL;
        }
        Node()
        {
            right = left = next = NULL;
            symb = NULL;
            weight = 0;
        }
    };
    Haffman()
    {
        head = NULL;
    }
    void Coding(string word)
    {
        map<char, int> symb;
        map<char, int>::iterator it;
        Data obj1(word.length());
        for (unsigned int i = 0; i < word.length(); i++)
        {
            char c = word[i];
            symb[c]++;
        }
        for (it = symb.begin(); it != symb.end(); it++)
        {
            Node* curr = new Node;
            curr->symb = it->first;
            curr->weight = it->second;
            PushBack(curr);
        }
        while (Built()) // когда мы не дойдем до самой первой вершины
        {
            Sort();
            Node * sLeft;
            Node * sRight;
            sLeft = PopFront();
            sRight = PopFront();
            Node* tNode = new Node(sRight, sLeft);
            PushBack(tNode);
        }
    }
    void Sort()
    {
        Node* prev = head;
        Node* current = head->next;
        Node* temp = new Node;
        while (prev->next)
        {
            while (current)
            {
                if (prev->weight > current->weight) {
                    Replace(temp, current, prev);
                    temp->weight = prev->weight;
                    temp->symb = prev->symb;
                    prev->weight = current->weight;
                    prev->symb = current->symb;
                    current->weight = temp->weight;
                    current->symb = temp->symb;
                }
                else if (prev->weight == current->weight) {
                    Replace(temp, current, prev);
                    temp->weight = current->weight;
                    temp->symb = current->symb;
                    current->weight = prev->weight;
                    current->symb = prev->symb;
                    prev->weight = temp->weight;
                    prev->symb = temp->symb;
                }
                current = current->next;
            }
            prev = prev->next;
            current = prev->next;
        }
    }
    void Replace(Node * temp, Node * current, Node * prev)
    {
        if (prev->left || current->left) {
            temp->left = prev->left;
            prev->left = current->left;
            current->left = temp->left;
        }
        if (prev->right || current->right) {
            temp->right = prev->right;
            prev->right = current->right;
            current->right = temp->right;
        }
    }
    void PushFront()
    {
        head = new Node(head);
    }
    Node* PopFront()
    {
        Node* current = head;
        head = head->next;
        current->next = NULL;
        return current;
    }
    void PushBack(Node* p)
    {
        if (head == NULL) head = p;
        else {
            Node* curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = p;
        }
    }
    bool Built()
    {
        return head->next != NULL;
    }
    void ShowTree()
    {
        ShowTree(head, 4);
    }
    void ShowTree(Node* curr, int koef)
    {
        cout.width(koef);
        if (curr != NULL) {
            ShowTree(curr->left, koef);
            if (curr->symb) cout << "Символ: " << curr->symb << " . Вес: " << curr->weight << endl;
            else cout << "Символ: отсутствует . Вес: " << curr->weight << endl;
            cout.width(koef);
            ShowTree(curr->right, koef);
        }
    }
private:
    Node* head;
};
int main()
{
    setlocale(0, "");
    string word = "АААААБББВГГГГГГГГДДЕЕЕЕЕ";
    Haffman* list1 = new Haffman();
    list1->Coding(word);
    list1->ShowTree();
    return 0;
}