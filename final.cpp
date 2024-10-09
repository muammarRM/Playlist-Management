#include <iostream>
#include <string>
using namespace std;

struct Song
{
    string title;
    string artist;
    string album;
    int year;
};

struct Node
{
    Song data;
    Node *next;
};

Node *head = NULL;

void menu();
void addSong();
void deleteSong();
void displayPlaylist();

int main()
{
    menu();
    return 0;
}

void addSong()
{
    cout << "=====================" << endl;
    cout << "MENU TAMBAH PLAYLIST" << endl;
    cout << "=====================" << endl;
    cout << endl;
    Node *newNode = new Node;
    cout << "Judul: ";
    getline(cin, newNode->data.title);
    cout << "Penyanyi: ";
    getline(cin, newNode->data.artist);
    cout << "Album: ";
    getline(cin, newNode->data.album);
    cout << "Tahun: ";
    cin >> newNode->data.year;
    cin.ignore(); // clear input buffer
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << endl;
    cout << "Lagu ditambahkan!" << endl
         << endl;
    cout << "Tekan [Enter] untuk melanjutkan: ";
    cin.get();
}

void displayPlaylist()
{
    cout << "=====================" << endl;
    cout << "MENU DISPLAY PLAYLIST" << endl;
    cout << "=====================" << endl;
    cout << endl;
    if (head == NULL)
    {
        cout << "Playlist kosong." << endl;
    }
    else
    {
        Node *temp = head;
        cout << "+----------------------------------------------------------------------------------------------------+" << endl;
        cout << "| Title                     | Artist                    | Album                     | Year           |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------+" << endl;
        while (temp != NULL)
        {
            cout << "| ";
            cout.width(25);
            cout << left << temp->data.title << " | ";
            cout.width(25);
            cout << left << temp->data.artist << " | ";
            cout.width(25);
            cout << left << temp->data.album << " | ";
            cout.width(14);
            cout << left << temp->data.year << " |" << endl;
            temp = temp->next;
        }
        cout << "+----------------------------------------------------------------------------------------------------+" << endl;
    }
    cout << "Tekan [Enter] untuk melanjutkan: ";
    cin.get();
}

void deleteSong()
{
    cout << "=========================" << endl;
    cout << "MENU PENGHAPUSAN PLAYLIST" << endl;
    cout << "=========================" << endl;
    cout << endl;
    if (head == NULL)
    {
        cout << "Playlist kosong" << endl;
    }
    else
    {
        string title;
        cout << "Masukkan Judul Lagu yang ingin dihapus: ";
        getline(cin, title);

        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL && temp->data.title != title)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Lagu " << title << " tidak ditemukan." << endl;
        }
        else
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Berhasil dihapus!" << endl;
        }
    }
    cout << "Tekan [Enter] untuk melanjutkan: ";
    cin.get();
}

void menu()
{
    int choice;
    bool exit = false;

    do
    {
        system("cls");
        cout << "======== Playlist Management ========" << endl;
        cout << "1. Tambahkan Lagu" << endl;
        cout << "2. Tampilkan playlist" << endl;
        cout << "3. Hapus Lagu" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> choice;
        cin.ignore(); // clear input buffer
        cout << endl;

        switch (choice)
        {
        case 1:
            system("cls");
            addSong();
            break;
        case 2:
            system("cls");
            displayPlaylist();
            break;
        case 3:
            system("cls");
            deleteSong();
            break;
        case 4:
            cout << "Keluar dari program..." << endl;
            exit = true;
            break;
        default:
            cout << "Masukkan angka dari 1-4" << endl;
            cout << "Tekan [Enter] untuk melanjutkan: ";
            cin.get();
            continue;
        }
        cout << endl;
    } while (!exit);
}
