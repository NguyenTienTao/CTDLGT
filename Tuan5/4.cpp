#include <bits/stdc++.h>

using namespace std;

class Node {
    int ID;
    string Name, Class;
    Node *left, *right, *father;

public:
    Node() {
    }

    Node(int id, string name, string class_) {
        this->ID = id;
        this->Name = name;
        this->Class = class_;
        left = nullptr;
        right = nullptr;
        father = nullptr;
    }

    friend class BST;
};

class BST{
    Node *root;

public:
    BST() {
        root = nullptr;
    }

    //Tra ve node cuoi cung hoac tra ve node cha cua node co ID la id
    Node* find(Node* node, int id) {
        if (!node) return nullptr;
        else {
            while(node != nullptr) {
                if (id == node->ID) break;
                if (id > node->ID) {
                    node = node->right;
                    continue;
                }
                if (id < node->ID) {
                    node = node->left;
                    continue;
                }
            }
            return node;
        }
    }

    void Insert(int ID, string Name, string Class) {
        Node *p = new Node(ID, Name, Class);
        if (root == nullptr) {
            root = p;
        } else {
            Node *tmp = root;
            Node *par = new Node();
            while (tmp) {
                par = tmp;
                if (tmp->ID < ID) {
                    tmp = tmp->right;
                } else if (tmp->ID > ID) {
                    tmp = tmp->left;
                } else break;
            }
            if (ID > par->ID) {
                par->right = p;
                p->father = par;
            }
            else if (ID < par->ID) {
                par->left = p;
                p->father = par;
            } else {
                cout << "Da co sinh vien mang ID nhu vay" << endl;
            }
        }
    }

    void Delete(int ID) {
        Node *tmp = find(root, ID);
        if (!tmp) {
            cout << "Khong co sinh vien mang ID nhu vay" << endl;
            return;
        }
        Node *parent = tmp->father;
        if (tmp->left == nullptr && tmp->right == nullptr) {
            if (parent->ID > ID) parent->left = nullptr;
            else parent->right = nullptr;
        } else if ((tmp->left != nullptr && tmp->right == nullptr)) {
            if (parent->ID > ID) {
                parent->left = tmp->left;
                tmp->left->father = parent;
            } else {
                parent->right = tmp->left;
                tmp->left->father = parent;
            }
        } else if ((tmp->left == nullptr && tmp->right != nullptr)) {
            if (parent->ID > ID) {
                parent->left = tmp->right;
                tmp->right->father = parent;
            }
            else {
                parent->right = tmp->right;
                tmp->right->father = parent;
            }
        } else {
            Node *p1 = tmp;
            p1 = p1->left;
            while (p1->right) {
                p1 = p1->right;
            }
            Node *par_of_p1 = p1->father;
            if (tmp == par_of_p1) {
                par_of_p1->left = p1->left;
            } else {
                par_of_p1->right = p1->left;
            }
            if (p1->left) p1->left->father = par_of_p1;
            p1->left = tmp->left;
            p1->right = tmp->right;
            p1->father = tmp->father;
        }
        delete tmp;
    }

    void Infor(int ID) {
        Node *tmp = find(root, ID);
        if (tmp)
            cout << tmp->Name << "," << tmp->Class << endl;
        else
            cout << "NA,NA" << endl;
    }

};

int main() {
    BST *tree = new BST();
    string s;

    tree->Insert(1, "Tuan", "K61CS");
    tree->Insert(2, "Vinh", "K43C");
    tree->Infor(3);
    tree->Infor(2);
    tree->Delete(2);
    tree->Infor(2);

    return 0;
}

