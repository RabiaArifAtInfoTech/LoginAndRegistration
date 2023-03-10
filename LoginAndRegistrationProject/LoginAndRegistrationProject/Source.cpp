#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;


void mainmenu();


int choice;
bool cinFail;
int confirmation;
string username, password, password2;

void writetofile(string username) {
    ofstream writefile;
    string file = username + ".txt";
    writefile.open(file.c_str());
    writefile << password;
    writefile.close();
    //mainmenu();
}

void login() {
    cout << "You are being logged in!";
}


void registerpassword() {
    cout << "Please enter the password : ";
    cin >> password;
    cout << "Please renter your password for confirmation : ";
    cin >> password2;
    if (password == password2) {
        cin.clear();
        cin.ignore(10000, '\n');
        writetofile(username);
        exit(0);
    }
    else; {
        cout << "Sorry invalid" << endl;
        registerpassword();
    }
}


void registerme() {
    cout << "Please enter your username: " << endl;
    getline(cin, username);
    cout << "\nUsername -  \"" << username << "\"\nConfirm? \n\n[1] Yes\n[2] No" << endl;
    cin >> confirmation;
    if (confirmation == 1) {
        registerpassword();
    }

    else; {
        cout << "Sorry invalid input, Please try again" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        registerme();
    }
}


void exit() {
    exit(0);
}

void mainmenu() {
    cout << "Hello, Would you like to log in or register\n[1] Login\n[2] Register\n[3] Exit" << endl; 
    cin >> choice; 
    do {
        cinFail = cin.fail();
        cin.clear();
        cin.ignore(10000, '\n');

    } while (cinFail == true); 
    
    switch (choice) {
       case 1:
           login();
           exit();

        case 2:
            registerme();
            exit();

        case 3:
            exit();
    }
}

int main() {
    mainmenu();
    ///return 0;
}