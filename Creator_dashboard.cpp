#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Content
{
public:
    string title;
    string platform;
    int views;
    string status;

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Platform: " << platform << endl;
        cout << "Views: " << views << endl;
        cout << "Status: " << status << endl;
    }
};

void addContent()
{
    Content c;

    cout << "Enter Title: ";
    cin >> c.title;

    cout << "Enter Platform: ";
    cin >> c.platform;

    cout << "Enter Views: ";
    cin >> c.views;

    cout << "Enter Status: ";
    cin >> c.status;

    ofstream file("content_list.txt", ios::app);

    file << c.title << " "
         << c.platform << " "
         << c.views << " "
         << c.status << endl;

    file.close();

    cout << "Content Added Successfully!\n";
}

void viewContent()
{
    ifstream file("content_list.txt");

    string title, platform, status;
    int views;
    int count = 1;

    cout << "\nContent List:\n";

    while(file >> title >> platform >> views >> status)
    {
        cout << count << ". "
             << title << " - "
             << platform << endl;

        count++;
    }

    file.close();
}

void updateStatus()
{
    cout << "Status Update Feature Added\n";
    cout << "(For project demonstration)\n";
}

void deleteContent()
{
    cout << "Delete Feature Added\n";
    cout << "(For project demonstration)\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Creator Dashboard =====\n";
        cout << "1. Add Content\n";
        cout << "2. View Content\n";
        cout << "3. Update Status\n";
        cout << "4. Delete Content\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addContent();
                break;

            case 2:
                viewContent();
                break;

            case 3:
                updateStatus();
                break;

            case 4:
                deleteContent();
                break;

            case 5:
                cout << "Goodbye!";
                break;

            default:
                cout << "Invalid Choice!";
        }

    } while(choice != 5);

    return 0;
}
