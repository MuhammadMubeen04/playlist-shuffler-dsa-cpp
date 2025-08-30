#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>
using namespace std;

class song 
{
    string songName;
    string creatorName;
    song* next;
    song* prev;
public:
    song(string sName, string cName) 
	{
        songName = sName;
        creatorName = cName;
        next = NULL;
        prev = NULL;
    }

    void addSongs(song*& head, string sName, string cName) 
	{
        song* n = new song(sName, cName);
        if (head == NULL) 
		{
            head = n;
        } 
		else 
		{
            song* temp = head;
            while (temp->next != NULL) 
			{
                temp = temp->next;
            }
            temp->next = n;
            n->prev = temp;
        }
    }

    void deleteSongs(song*& head, string sName, song*& lastDeleted) 
	{
        if (head == NULL) return;

        if (sName == head->songName) 
		{
            lastDeleted = head;
            head = head->next;
            if (head) head->prev = NULL;
        } else 
		{
            song* temp = head;
            while (temp->next != NULL && temp->next->songName != sName) 
			{
                temp = temp->next;
            }
            if (temp->next == NULL) 
			{
                cout << "Song not found!\n";
                return;
            }
            lastDeleted = temp->next;
            temp->next = temp->next->next;
            if (temp->next) 
			{
                temp->next->prev = temp;
            }
        }
        lastDeleted->next = NULL;
        lastDeleted->prev = NULL;
    }

    void undoDelete(song*& head, song*& lastDeleted) 
	{
        if (lastDeleted == NULL) 
		{
            cout << "No song to undo delete!\n";
            return;
        }

        if (head == NULL) 
		{
            head = lastDeleted;
        } 
		else 
		{
            song* temp = head;
            while (temp->next != NULL) 
			{
                temp = temp->next;
            }
            temp->next = lastDeleted;
            lastDeleted->prev = temp;
        }
        lastDeleted = NULL;
        cout << "Last deleted song restored!\n";
    }

    void shufflePlaylist(song*& head) 
	{
        srand(time(0));
        int count = 0;
        song* temp = head;
        while (temp != NULL) 
		{
            count++;
            temp = temp->next;
        }
        if (count < 2) 
		{
            cout << "Not enough songs to shuffle!\n";
            return;
        }

        song** songArray = new song * [count];
        temp = head;
        for (int i = 0; i < count; i++) 
		{
            songArray[i] = temp;
            temp = temp->next;
        }

        for (int i = count - 1; i > 0; i--) 
		{
            int j = rand() % (i + 1);
            swap(songArray[i], songArray[j]);
        }

        head = songArray[0];
        head->prev = NULL;
        temp = head;
        for (int i = 1; i < count; i++) 
		{
            temp->next = songArray[i];
            songArray[i]->prev = temp;
            temp = temp->next;
        }
        temp->next = NULL;

        delete[] songArray;
        cout << "Playlist shuffled!\n";
    }

    void display(song*& head) 
	{
        song* temp = head;
        cout << "Playlist:\n";
        while (temp != NULL) 
		{
            cout << temp->songName << " (" << temp->creatorName << ")\n";
            temp = temp->next;
        }
    }
};

void menu(song obj, song*& head, song*& lastDeleted) 
{
    int choice;
    while (true) 
	{
        system("cls");
        cout << "Music Playlist Shuffler:\n1. Add Songs\n2. Delete Songs\n3. Undo Last Deleted Song\n4. Shuffle Playlist\n";
        cout << "5. Display Playlist\n6. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) 
		{
        case 1: 
		{
            string sName, cName;
            cout << "Enter song name: ";
            getline(cin, sName);
            cout << "Enter creator name: ";
            getline(cin, cName);
            obj.addSongs(head, sName, cName);
            break;
        }
        case 2: 
		{
            string sName;
            cout << "Enter the song name to delete: ";
            getline(cin, sName);
            obj.deleteSongs(head, sName, lastDeleted);
            break;
        }
        case 3:
            obj.undoDelete(head, lastDeleted);
            break;
        case 4:
            obj.shufflePlaylist(head);
            break;
        case 5:
            obj.display(head);
            break;
        case 6:
            cout << "Exiting...\n";
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
        cout << "Press any key to continue...";
        getch();
    }
}

int main() 
{
    song* head = NULL;
    song* lastDeleted = NULL;
    song playlist("", "");
    playlist.addSongs(head,"Love Lost","Talha Anjum");
    playlist.addSongs(head,"HeartBroke Kid","Talha Anjum");
    playlist.addSongs(head,"Me & You","Talha Anjum");
    playlist.addSongs(head,"Departure Lane","Talha Anjum");
    playlist.addSongs(head,"4AM in Karachi","Talha Anjum");
    menu(playlist, head, lastDeleted);
    return 0;
}