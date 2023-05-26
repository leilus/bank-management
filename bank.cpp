
#include <iostream>
#include<fstream>
#include <dos.h>
#include <conio.h>
using namespace std;

#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif
using namespace std;


void isRegisteredUser() {
    ofstream file("dane.txt", ios::app);
    if (file.is_open()) {
        string username, password;
        cout << "Wprowadz swoje dane\nNazwa uzytkownika: ";
        cin >> username;
        cout << "Haslo: ";
        cin >> password;
        file << username << " " << password << endl;
        file.close();
        cout << "Uzytkownik zarejestrowany!\nMozesz teraz sie zalogowac!\n";
    }
    else {
        cout << "Nie udalo sie zarejestrowac";
    }


}
void isRegisteredAdmin() {
    ofstream file("adminDane.txt", ios::app);
    ifstream plik("code.txt");

    if (file.is_open()) {
        if (plik.is_open()) {
            int attemptCount = 1;
            int limit = 3;
            string codeNumber, username, password, storedCode;
            cout << "Wprowadz kod rejestracji";
            cin >> codeNumber;

            while (plik >> storedCode) {
                while (attemptCount < limit) {
                    if (codeNumber == storedCode) {
                        cout << "Wprowadz swoje dane\nNazwa uzytkownika: ";
                        cin >> username;
                        cout << "Haslo: ";
                        cin >> password;

                        attemptCount = 3;
                        file << username << " " << password << endl;
                        cout << "Administrator zarejestrowany";
                        file.close();
                        plik.close();
                    }

                    else if (codeNumber != storedCode) {
                        attemptCount++;
                        cout << "Wprowadz kod ponownie";
                        cin >> codeNumber;
                    }
                }
            }

        }
    }
}

bool isLoggedUser(bool loggedIn = false) {
    int type;
    ifstream file("dane.txt");
    if (file.is_open()) {
        string username, password;
        cout << "Podaj login: ";
        cin >> username;
        cout << "Podaj haslo: ";
        cin >> password;

        string storedUsername, storedPassword;

        while (file >> storedUsername >> storedPassword) {
            if (username == storedUsername && password == storedPassword) {
                file.close();
                cout << "Zalogowano pomyslnie! Witaj " << storedUsername << "! ";
                return true;
                loggedIn = true;
            }
        }
        cout << "Nie udalo sie zalogowac";
        file.close();
        return false;
    }
}

bool isLoggedAdmin() {
    ifstream file("adminDane.txt");
    if (file.is_open()) {
        string username, password;
        cout << "Podaj login: ";
        cin >> username;
        cout << "Podaj haslo: ";
        cin >> password;

        string storedUsername, storedPassword;

        while (file >> storedUsername >> storedPassword) {
            if (username == storedUsername && password == storedPassword) {
                file.close();
                cout << "Udalo sie zalogowac ";
                return true;
            }

        }
        cout << "Nie udalo sie zalogowac ";
        return false;
    }
    else {
        cout << "Blad pliku";
    }
}


void isDeposit() {
    ofstream money("money.txt", ios::app);
    ifstream moneyRead("money.txt");
    
    int moneyAmmount;

    if (money.is_open()) {
        cout << "Witaj, prosze wprowadzic ilosc pieniedzy do wplacenia ";
        cin >> moneyAmmount;
        money << moneyAmmount << endl;
        money.close();
        
    }
  
    int value;
    int totalMoney = 0;
    if (moneyRead.is_open()) {
        int value;
        while (moneyRead >> value) {
            totalMoney += value;
        }
        moneyRead.close();
   }

    cout << totalMoney;

  
}
int main()
{

    int type;
    int account;
    bool session = false;
    while (!session) {
        cout << "Witaj na naszym profilu bankowym (1 - Rejestracja, 2 - Logowanie, 3 - Wyplacanie pieniedzy, 4 - Wplacanie pieniedzy)";
        cin >> account;

        switch (account) {
        case 1:
            cout << "(1)Rejestracja uzytkownika\n(2)Rejestracja administratora\n";
            cin >> type;
            if (type == 1) {
                isRegisteredUser();
            }
            else if (type == 2) {
                isRegisteredAdmin();
            }
            else {
                cout << "Prosze wprowadzic prawidlowy wybor";
                cin >> type;
            }
            break;
        case 2:
            cout << "(1)Logowanie uzytkownika\n(2)Logowanie administratora\n";
            cin >> type;
            if (type == 1) {
                isLoggedUser();
            }
            else if (type == 2) {
                isLoggedAdmin();
                session = true;
            }
            break;
        case 4:
            isDeposit();
            break;
        }
    }
}
