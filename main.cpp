#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Registration Function
void registration()
{
    string username, password;

    cout << "\n--- Registration ---\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Check if username already exists
    ifstream file("users.txt");
    string savedUsername, savedPassword;

    while (file >> savedUsername >> savedPassword)
    {
        if (savedUsername == username)
        {
            cout << "Username already exists!\n";
            file.close();
            return;
        }
    }

    file.close();

    // Save new user
    ofstream outFile("users.txt", ios::app);
    outFile << username << " " << password << endl;
    outFile.close();

    cout << "Registration successful!\n";
}

// Login Function
void login()
{
    string username, password;
    string savedUsername, savedPassword;

    cout << "\n--- Login ---\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> savedUsername >> savedPassword)
    {
        if (savedUsername == username && savedPassword == password)
        {
            cout << "Login successful! Welcome, " << username << "!\n";
            file.close();
            return;
        }
    }

    file.close();

    cout << "Invalid username or password!\n";
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n===== Login & Registration System =====\n";
        cout << "1. Registration\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            registration();
        }
        else if (choice == 2)
        {
            login();
        }
        else if (choice == 3)
        {
            cout << "Thank you!\n";
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}