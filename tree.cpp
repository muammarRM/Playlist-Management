#include <iostream>
using namespace std;

// Struktur data untuk node tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi untuk melakukan transversal preorder
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Fungsi untuk melakukan transversal inorder
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Fungsi untuk melakukan transversal postorder
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Fungsi untuk menambahkan node baru pada tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Fungsi untuk mencari node dengan nilai terkecil pada tree
Node* findMinNode(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Fungsi untuk menghapus node pada tree
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;
    else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        // Jika node memiliki satu anak atau tidak memiliki anak
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Jika node memiliki dua anak, maka gantikan dengan nilai terkecil dari subtree kanan
        Node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Fungsi untuk menampilkan tree dalam bentuk grafik
void printTree(Node* root, string indent, bool last) {
    if (root == NULL) return;
    cout << indent;
    if (last) {
        cout << "└─";
        indent += "  ";
    }
    else {
        cout << "├─";
        indent += "│ ";
    }
    cout << root->data << endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
    }

// Fungsi main
int main() {
Node* root = NULL;
int choice, data;
do {
    cout << "\n==============================\n";
    cout << "Menu:\n";
    cout << "1. Tambah Bilangan\n";
    cout << "2. Hapus Bilangan\n";
    cout << "3. Tampilkan Bilangan\n";
    cout << "4. Keluar\n";
    cout << "Pilih: ";
    cin >> choice;
    cout << endl;

    switch (choice) {
        case 1:
            cout << "Masukkan bilangan: ";
            cin >> data;
            root = insertNode(root, data);
            cout << "Bilangan " << data << " berhasil ditambahkan." << endl;
            break;
        case 2:
            cout << "Masukkan bilangan yang akan dihapus: ";
            cin >> data;
            root = deleteNode(root, data);
            cout << "Bilangan " << data << " berhasil dihapus." << endl;
            break;
        case 3:
            cout << "Transversal Preorder: ";
            preorder(root);
            cout << endl;
            cout << "Transversal Inorder: ";
            inorder(root);
            cout << endl;
            cout << "Transversal Postorder: ";
            postorder(root);
            cout << endl;
            cout << "Tree: \n";
            printTree(root, "", true);
            break;
        case 4:
            cout << "Terima kasih!\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
    }
} while (choice != 4);

return 0;
}
