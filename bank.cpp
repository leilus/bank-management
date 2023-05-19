// bank.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include<fstream>
using namespace std;



void isRegisteredUser(){
    ofstream file("dane.txt");
    if (file.is_open()) {
        string username, password;
        cout << "Wprowadź swoje dane\nNazwa użytkownika: ";
        cin >> username;
        cout << "Hasło: ";
        cin >> password;
        file << username << password;
        file.close();
    }

    }
    void isRegisteredAdmin () {
        int attemptCount = 0;
        int limit = 3;
        int codeNumber;
        string username;
        string password;
        cout << "Wprowadź kod rejestracji";
        cin >> codeNumber;

        while (attemptCount < limit) {
            if (codeNumber == 123) {
                cout << "Wprowadź swoje dane\nNazwa użytkownika: ";
                cin >> username;
                cout << "Hasło: ";
                cin >> password;
                attemptCount = 3;
            }
            else if(codeNumber != 123){
                attemptCount++;
                cout << "Wprowadź kod ponownie";
                cin >> codeNumber;
            }
        }
        
    }

    bool isLoggedUser () {
        ifstream file("dane.txt");
        if (file.is_open()) {
            
            string username, password;
            cout << "Podaj login";
            cin >> username;
            cout << "Podaj hasło";
            cin >> password;

            string storedUsername, storedPassword;

            while (file >> storedUsername >> storedPassword) {
                if (username == storedUsername && password == storedPassword) {
                    file.close();
                    return true;
                }
                else {
                    cout << "Logowanie nie powiodło się";
                }
            }
         
        }
       
    }


int main()
{
    int type;
    int account;
    cout << "Witaj na naszym profilu bankowym (1 - Rejestracja, 2 - Logowanie, 3 - Wypłacanie pieniędzy, 4 - Wpłacanie pieniędzy)";
    cin >> account;

    switch (account) {
    case 1:
        cout << "<1>Rejestracja użytkownika\n<2>Rejestracja administratora";
        cin >> type;
        if (type == 1) {
            isRegisteredUser();
        }
        else if (type == 2) {
            isRegisteredAdmin();
        }
        else {
            cout << "Proszę wprowadzić prawidłowy wybór";
            cin >> type;
        }
        break;
    case 2:
        isLoggedUser();
        break;

    }
}
