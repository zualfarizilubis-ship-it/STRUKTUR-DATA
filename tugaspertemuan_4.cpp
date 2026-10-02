#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* buatNode(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->left = nullptr;
    baru->right = nullptr;

    return baru;
}

Node* tambah(Node* root, int nilai) {
    if (root == nullptr) {
        return buatNode(nilai);
    }

    if (nilai < root->data) {
        root->left = tambah(root->left, nilai);
    } 
    else if (nilai > root->data) {
        root->right = tambah(root->right, nilai);
    }

    return root;
}

void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;
    int angka;

    cout << "Masukkan angka (0 untuk berhenti):" << endl;

    while (true) {
        cin >> angka;

        if (angka == 0) {
            break;
        }

        root = tambah(root, angka);
    }

    cout << endl;
    cout << "Pre-order  : ";
    preOrder(root);

    cout << endl;
    cout << "In-order   : ";
    inOrder(root);

    cout << endl;
    cout << "Post-order : ";
    postOrder(root);

    return 0;
}