#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    string artist;
    string album;
    int year;
};

struct Node {
    Song data;
    Node* next;
};

Node* head = NULL;

void addSong() {
    Node* newNode = new Node;
    cout << "Title: ";
    getline(cin, newNode->data.title);
    cout << "Artist: ";
    getline(cin, newNode->data.artist);
    cout << "Album: ";
    getline(cin, newNode->data.album);
    cout << "Year: ";
    cin >> newNode->data.year;
    cin.ignore(); // clear input buffer
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Added successfully!" << endl;
}

void displayPlaylist() {
    if (head == NULL) {
        cout << "Playlist is empty." << endl;
    } else {
        Node* temp = head;
        cout << "+-----------------------------------------------------------------+" << endl;
        cout << "| Title           | Artist          | Album           | Year      |" << endl;
        cout << "+-----------------------------------------------------------------+" << endl;
        while (temp != NULL) {
            cout << "| ";
            cout.width(15);
            cout << left << temp->data.title << " | ";
            cout.width(15);
            cout << left << temp->data.artist << " | ";
            cout.width(15);
            cout << left << temp->data.album << " | ";
            cout.width(9);
            cout << left << temp->data.year << " |" << endl;
            temp = temp->next;
        }
        cout << "+-----------------------------------------------------------------+" << endl;
    }
}

void deleteSong() {
    if (head == NULL) {
        cout << "Playlist is empty." << endl;
        return;
    }
    
    string title;
    cout << "Enter the title of the song to be deleted: ";
    getline(cin, title);
    
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL && temp->data.title != title) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Song not found." << endl;
    } else {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
        cout << "Deleted successfully!" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "======== Playlist Management ========" << endl;
        cout << "1. Add a song" << endl;
        cout << "2. Display playlist" << endl;
        cout << "3. Delete a song" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear input buffer
        cout << endl;
        
        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                displayPlaylist();
                break;
            case 3:
                deleteSong();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    } while (choice != 4);
    
    return 0;
}
