#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
    node *firstchild;
};

typedef node* Tree;

Tree newTree(int k) {
    Tree p = new node();
    p->data = k;
    p->next = nullptr;
    p->firstchild = nullptr;
    return p;
}

Tree addSibling(Tree firstchild, int data) {
    if (firstchild == nullptr)
        return nullptr;

    while (firstchild->next)
        firstchild = firstchild->next;

    return (firstchild->next = newTree(data));
}

Tree addChild(Tree root, int u, int v) {
    if (root == nullptr) {
        root = newTree(u);
        root->firstchild = newTree(v);
        return root;
    }

    if (root->firstchild)
        return addSibling(root->firstchild, v);
    else
        return (root->firstchild = newTree(v));
}

Tree createTree(Tree root, int u, int v) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data == u) {
        return addChild(root, u, v);
    }
    else {
        if (root->firstchild)
            createTree(root->firstchild, u , v);
        createTree(root->next, u, v);
    }
}

int tree_height(Tree root) {
    if (root == nullptr) {
        return 0;
    } else {
        int max_ = 0, height;
        while (root) {
            height = tree_height(root->firstchild);
            if (height >= max_)
                max_ = height;
            root = root->next;
        }
        return max_ + 1;
    }
}

void printPreorder(Tree root) {
    if (root == nullptr) return;
    while (root) {
        cout << root->data << " ";
        printPreorder(root->firstchild);
        root = root->next;
    }
}

void printPostorder(Tree root) {
    if (root == nullptr) return;
    while (root) {
        printPostorder(root->firstchild);
        cout << root->data << " ";
        root = root->next;
    }
}

bool checkBinarytree(Tree root) {
    int numberchild = 0;
    bool check = true;
    while (root) {
        if (root->firstchild)
            check = checkBinarytree(root->firstchild);
        numberchild++;
        root = root->next;
    }
    if (numberchild > 2)
        return false;
    else if (numberchild <= 2 && check == true)
        return true;
}

void printinorder(Tree root) {
    if (root == nullptr) return;
    else {
        printinorder(root->firstchild);
        cout << root->data << " ";
        if (root->firstchild != nullptr)
            printinorder(root->firstchild->next);
    }
}

int main()
{
    Tree root = nullptr;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if (i == 0) {
            root = addChild(root, u, v);
            continue;
        }
        createTree(root, u, v);
    }
    cout << tree_height(root)-1 << endl;
    printPreorder(root);
    cout << endl;
    printPostorder(root);
    cout << endl;
    if (checkBinarytree(root) == false)
        cout << "NOT BINARY TREE" << endl;
    else
        printinorder(root);


    return 0;
}
