#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int angka;
    string message;
    Node *left;
    Node *right;
};

void init(Node *root);
void playGame(Node *node);
int jumlahAngka(Node *node);
void hapusTree(Node *node);

int main()
{
    Node *root = new Node();
    init(root);

    playGame(root);
    cout << jumlahAngka(root);

    return 0;
}
void init(Node *root)
{
    string kartu1 = "1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31";
    string kartu2 = "2, 3, 6, 7, 10, 11, 14, 15, 18, 19, 22, 23, 26, 27, 30, 31";
    string kartu3 = "4, 5, 6, 7, 12, 13, 14, 15, 20, 21, 22, 23, 28, 29, 30, 31";
    string kartu4 = "8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, 30, 31";
    string kartu5 = "16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31";
    int angka1 = 1;
    int angka2 = 2;
    int angka3 = 4;
    int angka4 = 8;
    int angka5 = 16;

    root->message = "Apakah angka anda ada di kartu ini? " + kartu1;
    root->angka = angka1;

    root->left = new Node();
    root->left->message = "Apakah angka anda ada di kartu ini? " + kartu2;
    root->left->angka = angka2;

    // kiri 3
    root->left->left = new Node();
    root->left->left->message = "Apakah angka anda ada di kartu ini? " + kartu3;
    root->left->left->angka = angka3;

    root->left->left->left = new Node();
    root->left->left->left->message = "Apakah angka anda ada di kartu ini? " + kartu4;
    root->left->left->left->angka = angka4;

    root->left->left->left->left = new Node();
    root->left->left->left->left->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->left->left->left->left->angka = angka5;
    root->left->left->left->left->right = NULL;
    root->left->left->left->left->left = NULL;

    root->left->left->left->right = new Node();
    root->left->left->left->right->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->left->left->left->right->angka = angka5;
    root->left->left->left->right->right = NULL;
    root->left->left->left->right->left = NULL;

    root->left->left->right = new Node();
    root->left->left->right->message = "Apakah angka anda ada di kartu ini? " + kartu4;
    root->left->left->right->angka = angka4;

    root->left->left->right->left = new Node();
    root->left->left->right->left->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->left->left->right->left->angka = angka5;
    root->left->left->right->left->right = NULL;
    root->left->left->right->left->left = NULL;

    root->left->left->right->right = new Node();
    root->left->left->right->right->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->left->left->right->right->angka = angka5;
    root->left->left->right->right->right = NULL;
    root->left->left->right->right->left = NULL;

    root->left->right = new Node();
    root->left->right->message = "Apakah angka anda ada di kartu ini? " + kartu3;
    root->left->right->angka = angka3;

    root->left->right->left = new Node();
    root->left->right->left->message = "Apakah angka anda ada di kartu ini? " + kartu4;
    root->left->right->left->angka = angka4;

    root->left->right->left->left = new Node();
    root->left->right->left->left->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->left->right->left->left->angka = angka5;
    root->left->right->left->left->right = NULL;
    root->left->right->left->left->left = NULL;

    root->left->right->left->right = new Node();
    root->left->right->left->right->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->left->right->left->right->angka = angka5;
    root->left->right->left->right->right = NULL;
    root->left->right->left->right->left = NULL;

    root->left->right->right = new Node();
    root->left->right->right->message = "Apakah angka anda ada di kartu ini? " + kartu4;
    root->left->right->right->angka = angka4;

    root->left->right->right->left = new Node();
    root->left->right->right->left->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->left->right->right->left->angka = angka5;
    root->left->right->right->left->right = NULL;
    root->left->right->right->left->left = NULL;

    root->left->right->right->right = new Node();
    root->left->right->right->right->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->left->right->right->right->angka = angka5;
    root->left->right->right->right->right = NULL;
    root->left->right->right->right->left = NULL;
    // kanan 3
    root->right = new Node();
    root->right->message = "Apakah angka anda ada di kartu ini? " + kartu2;
    root->right->angka = angka2;

    root->right->left = new Node();
    root->right->left->message = "Apakah angka anda ada di kartu ini? " + kartu3;
    root->right->left->angka = angka3;

    root->right->left->left = new Node();
    root->right->left->left->message = "Apakah angka anda ada di kartu ini? " + kartu4;
    root->right->left->left->angka = angka4;

    root->right->left->left->left = new Node();
    root->right->left->left->left->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->right->left->left->left->angka = angka5;
    root->right->left->left->left->right = NULL;
    root->right->left->left->left->left = NULL;

    root->right->left->left->right = new Node();
    root->right->left->left->right->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->right->left->left->right->angka = angka5;
    root->right->left->left->right->right = NULL;
    root->right->left->left->right->left = NULL;

    root->right->left->right = new Node();
    root->right->left->right->message = "Apakah angka anda ada di kartu ini? " + kartu4;
    root->right->left->right->angka = angka4;

    root->right->left->right->left = new Node();
    root->right->left->right->left->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->right->left->right->left->angka = angka5;
    root->right->left->right->left->right = NULL;
    root->right->left->right->left->left = NULL;

    root->right->left->right->right = new Node();
    root->right->left->right->right->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->right->left->right->right->angka = angka5;
    root->right->left->right->right->right = NULL;
    root->right->left->right->right->left = NULL;

    root->right->right = new Node();
    root->right->right->message = "Apakah angka anda ada di kartu ini? " + kartu3;
    root->right->right->angka = angka3;

    root->right->right->left = new Node();
    root->right->right->left->message = "Apakah angka anda ada di kartu ini? " + kartu4;
    root->right->right->left->angka = angka4;

    root->right->right->left->left = new Node();
    root->right->right->left->left->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->right->right->left->left->angka = angka5;
    root->right->right->left->left->right = NULL;
    root->right->right->left->left->left = NULL;

    root->right->right->left->right = new Node();
    root->right->right->left->right->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->right->right->left->right->angka = angka5;
    root->right->right->left->right->right = NULL;
    root->right->right->left->right->left = NULL;

    root->right->right->right = new Node();
    root->right->right->right->message = "Apakah angka anda ada di kartu ini? " + kartu4;
    root->right->right->right->angka = angka4;

    root->right->right->right->left = new Node();
    root->right->right->right->left->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->right->right->right->left->angka = angka5;
    root->right->right->right->left->right = NULL;
    root->right->right->right->left->left = NULL;

    root->right->right->right->right = new Node();
    root->right->right->right->right->message = "Apakah angka anda ada di kartu ini? " + kartu5;
    root->right->right->right->right->angka = angka5;
    root->right->right->right->right->right = NULL;
    root->right->right->right->right->left = NULL;
}


// Fungsi untuk memainkan game
void playGame(Node *node)
{
    cout << node->message << " (y/t): ";
    string input;
    cin >> input;
    if (input == "y")
    {
        if (node->left != NULL)
        {
            playGame(node->left);
        }
    }
    else if (input == "t")
    {
        if (node->right != NULL)
        {
            hapusTree(node->left);
            Node *temp = node->right;
            *node = *temp;
            delete temp;
            playGame(node);
        }
    }
}

// Fungsi untuk menghitung jumlah angka pada tree
int jumlahAngka(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->angka + jumlahAngka(node->left) + jumlahAngka(node->right);
}

// Fungsi untuk menghapus tree
void hapusTree(Node *node)
{
    if (node != NULL)
    {
        hapusTree(node->left);
        hapusTree(node->right);
        delete node;
    }
}
