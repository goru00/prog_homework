#include<iostream>
#include<string>

using namespace std;

class Haffman
{
public:
    class Node
    {
    public:
        Node* right, * left, * next;
        char symb;
        int weight;
        bool code;
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
        size = 0;
    }
    void Coding(string word)
    {
        for (unsigned int i = 0; i < word.length(); i++)
        {
            char c = word[i];
            if (FindSymb(c)) {
                continue;
            }
            else {
                Node* curr = new Node;
                curr->symb = c;
                curr->weight++;
                PushBack(curr);
                size++;
            }
        }
        while (Built()) // когда мы не дойдем до самой первой вершины
        {
            Sort();
            Node* sLeft;
            Node* sRight;
            sLeft = PopFront();
            sRight = PopFront();
            Node* tNode = new Node(sRight, sLeft);
            PushBack(tNode);
            size++;
        }
    }
    void BuildCodeTable()
    {
        BuildCodeTable(head, "0");
    }
    void BuildCodeTable(Node* curr, string code)
    {
        if (curr->left != NULL) {
            BuildCodeTable(curr->left, code + '0');
        }
        if (curr->right != NULL) {
            cout << 1;
            BuildCodeTable(curr->right, code + '1');
        }
        if (curr->symb) cout << code;
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
    void PopBack()
    {
        if (head == NULL) return;
        Node* curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        delete curr;
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
        BuildCodeTable();
    }
private:
    void Replace(Node* temp, Node* current, Node* prev)
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
    bool FindSymb(char s)
    {
        Node* curr = head;
        while (curr)
        {
            if (curr->symb == s)
            {
                curr->weight++;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
    Node* head;
    int size;
};
int main()
{
    setlocale(0, "");
    string word = "AABBBCDDDDD";
    Haffman* list1 = new Haffman();
    list1->Coding(word);
    list1->ShowTree();
    return 0;
}
