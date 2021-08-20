#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
using namespace std;
class Node
{
public:
    Node * right, * left;
    char symb;
    int weight;
    Node() { }
    Node(Node * right, Node * left)
    {
        this->right = right;
        this->left = left;
        weight = right->weight + left->weight;
    }
    void ShowTree(Node* root, int koef = 4)
    {
        if (root) {
            cout.width(koef);
            ShowTree(root->left, koef * 2);
            if (root->symb) cout << root->weight << "  (" << root->symb << ")" << endl;
            else cout << root->weight << endl;
            cout.width(koef);
            ShowTree(root->right, koef * 2);
        }
    }
};
class Compare
{
public:
    bool operator()(Node * left, Node * right)
    {
       return left->weight < right->weight; 
    }
};
int main() 
{
    string word = "AABBBCDDDDD";
    list<Node*> wlist;
    map<char, int> symb;
    map<char, int>::iterator it;
    for (int i = 0; i < word.length(); i++)
    {
        char c = word[i];
        symb[c]++;
    }
    for (it = symb.begin(); it != symb.end(); it++)
    {
        Node* curr = new Node;
        curr->symb = it->first;
        curr->weight = it->second;
        wlist.push_back(curr);
    }
    while(wlist.size() != 1) // когда мы не дойдем до самой первой вершины
    {
        wlist.sort(Compare());
        Node *sLeft, *sRight;
        sLeft = wlist.front();
        wlist.pop_front();
        sRight = wlist.front();
        wlist.pop_front();
        Node *tNode = new Node(sLeft, sRight);
        wlist.push_back(tNode);
    }
    Node *start = wlist.front();
    start->ShowTree(start);
    return 0;
}