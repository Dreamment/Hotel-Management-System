#include <iostream>
#include <conio.h>
#include "admin.h"

using namespace std;

int main() {
    while(true){
        system("cls");
        cout<<"\t\tHotel Management System by Dreamment\n"
              "\t\t1. Login\n"
              "\t\t2. Register\n"
              "\t\t0. Exit\n"
              "\t\tEnter your choice: ";
        char choice = getch();
        fflush(stdin);
        while(choice != '1' && choice != '2' && choice != '0') {
            cout << "\n\n\t\tInvalid choice. Please try again: ";
            choice = getch();
            fflush(stdin);
        }
        while(choice == '1'){
            system("cls");
            cout<<"\t\tHotel Management System by Dreamment\n"
                  "\t\t\tLogin Screen\n"
                  "\t\t1. Customer Login\n"
                  "\t\t2. Manager Login\n"
                  "\t\t3. Previous Menu\n"
                  "\t\t0. Exit\n"
                  "\t\tEnter your choice: ";
            char choice2 = getch();
            fflush(stdin);
            while(choice2 != '1' && choice2 != '2' && choice2 != '3' && choice2 != '0') {
                cout << "\n\n\t\tInvalid choice. Please try again: ";
                choice2 = getch();
                fflush(stdin);
            }
            while(choice2 == '1'){
                system("cls");
                cout<<"\t\tHotel Management System by Dreamment\n"
                      "\t\t\tCustomer Login\n"
                      "\t\tEnter your username: ";
                string username;
                cin >> username;
                fflush(stdin);
                cout << "\t\tEnter your password: ";
                string password;
                cin >> password;
                fflush(stdin);
                admin myAdmin;
                bool login_status = false;
                try{
                    login_status = myAdmin.customer_login(username, password);
                }
                catch (invalid_argument &e){
                    cerr<<"Error while logging in: "<<e.what();
                    choice2 = 0;
                    cout<<"Existing system. Press anything to continue.";
                    getch();
                    break;
                }
                while(login_status){
                    system("cls");
                    cout<<"\t\tHotel Management System by Dreamment\n"
                          "\t\t\t\tCustomer Screen"
                          "\n\n\t\t1. Room Reservation"
                          "\n\t\t2. Room Cancellation"
                          "\n\t\t3. Housekeeping Service"
                          "\n\t\t4. Main Menu"
                          "\n\t\t0. Exit"
                          "\n\t\tEnter Your Choice: ";
                    char choice3 = getch();
                    while(choice3 != 1 && choice3 != 2 && choice3 != 3 && choice3 != 4 && choice3 != 0){
                        cout<<"Invalid Option. Please Try Again: ";
                        choice3 = getch();
                    }
                    while(choice3 == '1'){
                        //TODO: Room Reservation
                    }
                    while(choice3 == '2'){
                        //TODO: Room Cancellation
                    }
                    while(choice3 == '3'){
                        //TODO: Cleaning Service
                    }
                    if(choice3 == '4'){
                        choice2 = '9';
                        break;
                    }
                    if(choice3 == '0'){
                        choice2 = 0;
                        break;
                    }
                }
                if(!login_status){
                    cout<<"\n\t\tYou entered wrong username or password."
                          "\n\t\tDo you want to try again?(y/n) ";
                    char choice3 = getch();
                    fflush(stdin);
                    while (choice3 != 'y' && choice3 != 'Y' && choice3 != 'n' && choice3 != 'N'){
                        cout<<"\n\t\tInvalid choice. Please try again: ";
                        choice3 = getch();
                        fflush(stdin);
                    }
                    if (choice3 == 'n' || choice3 == 'N'){
                        choice2 = 0;
                        break;
                    }
                }
            }
            while (choice2 == '2'){
                system("cls");
                cout<<"\t\tHotel Management System by Dreamment\n"
                      "\t\t\tManager Login"
                      "\n\n\t\tEnter username: ";
                string username;
                cin>>username;
                fflush(stdin);
                cout<<"\t\tEnter password: ";
                string password;
                cin>>password;
                fflush(stdin);
                bool login_status = false;
                admin myAdmin;
                try {
                    login_status = myAdmin.manager_login(username,password);
                }
                catch (invalid_argument &e){
                    cerr<<"Error while logging in: "<<e.what();
                    choice2 = 0;
                    cout<<"Existing system. Press anything to continue.";
                    getch();
                    break;
                }
                while (login_status){
                    system("cls");
                    cout<<"\t\tHotel Management System"
                          "\n\t\t\tManager Login"
                          "\n\n\t\t1. Edit Rooms"
                          "\n\t\t2. Add Room"
                          "\n\t\t3. Remove Room"
                          "\n\t\t4. Employee Screen"
                          "\n\t\t5. Get Stuff Shifts"
                          "\n\t\t6. Previous Menu"
                          "\n\t\t0. Exit"
                          "\n\t\tEnter your choice: ";
                    char choice3 = getch();
                    fflush(stdin);
                    while (choice3 != '1' && choice3 != '2' && choice3 != '3' && choice3 != '4' && choice3 != '5' &&
                        choice3 != '6' && choice3 != '0'){
                        cout<<"\n\t\tInvalid Choice. Please try again: ";
                        choice3 = getch();
                        fflush(stdin);
                    }
                    while (choice3 == '1'){
                        //TODO: Edit Rooms
                    }
                    while (choice3 == '2'){
                        //TODO: Add Room
                    }
                    while (choice3 == '3'){
                        //TODO: Remove Room
                    }
                    while (choice3 == '4'){
                        //TODO: Employee Screen
                    }
                    while (choice3 == '5'){
                        //TODO: Stuff shifts
                    }
                    if (choice3 == '6'){
                        choice2 = '9';
                        break;
                    }
                    if (choice3 == '0'){
                        choice2 = '0';
                        break;
                    }
                }
                if(!login_status){
                    cout<<"\n\t\tYou entered wrong username or password."
                          "\n\t\tDo you want to try again?(y/n) ";
                    char choice3 = getch();
                    fflush(stdin);
                    while (choice3 != 'y' && choice3 != 'Y' && choice3 != 'n' && choice3 != 'N'){
                        cout<<"\n\t\tInvalid choice. Please try again: ";
                        choice3 = getch();
                        fflush(stdin);
                    }
                    if (choice3 == 'n' || choice3 == 'N'){
                        choice2 = 0;
                        break;
                    }
                }
            }
            while (choice2 == '3'){
                choice = '9';
                break;
            }
            if (choice2 == '0'){
                choice = '0';
                break;
            }
        }
        while (choice == '2'){
            system("cls");
            cout<<"\t\tHotel Management System\n"
                  "\t\t\tRegister Screen"
                  "\n\n\t\t1. Register as Customer"
                  "\n\t\t2. Register as Manager"
                  "\n\t\t3. Previous Menu"
                  "\n\t\t0. Exit"
                  "\n\t\tEnter your choice: ";
            char choice2 = getch();
            fflush(stdin);
            while (choice2 != '1' && choice2 != '2' && choice2 != '3' && choice2 != '0'){
                cout<<"\n\t\tInvalid Choice. Please try again: ";
                choice2 = getch();
                fflush(stdin);
            }
            while (choice2 == '1'){
                system("cls");
                cout<<"\t\tHotel Management System\n"
                      "\t\tCustomer Register Screen"
                      "\n\n\t\tEnter your username: ";
                string username;
                cin>>username;
                fflush(stdin);
                cout<<"\t\tEnter your password: ";
                string password;
                cin>>password;
                fflush(stdin);
                cout<<"\t\tEnter your password again:";
                string password2;
                cin>>password2;
                fflush(stdin);
                cout<<"\t\tEnter your name: ";
                string name;
                cin>>name;
                fflush(stdin);
                cout<<"\t\tEnter your surname: ";
                string surname;
                cin>>surname;
                fflush(stdin);
                cout<<"\t\tEnter your email: ";
                string email;
                cin>>email;
                fflush(stdin);
                cout<<"\t\tEnter your phone number: ";
                string phone_number;
                cin>>phone_number;
                fflush(stdin);
                bool register_status = false;
                admin myAdmin;
                try {
                    register_status = myAdmin.customer_register(username,password,password2,email,phone_number,name,surname);
                }
                catch (invalid_argument &e){
                    cerr<<"Error while registering: "<<e.what();
                    choice2 = 0;
                    cout<<"Existing system. Press anything to continue.";
                    getch();
                    break;
                }
                if (register_status){
                    cout<<"\n\t\tYou have successfully registered. Press anything to continue.";
                    getch();
                    choice2 = 0;
                    break;
                }
                else {
                    cout<<"\n\t\tYou entered wrong information. Do you want to try again?(y/n) ";
                    char choice3 = getch();
                    fflush(stdin);
                    while (choice3 != 'y' && choice3 != 'Y' && choice3 != 'n' && choice3 != 'N'){
                        cout<<"\n\t\tInvalid choice. Please try again: ";
                        choice3 = getch();
                        fflush(stdin);
                    }
                    if (choice3 == 'n' || choice3 == 'N'){
                        choice2 = 0;
                        break;
                    }
                }
            }
            while (choice2 == '2'){
                system("cls");
                cout<<"\t\tHotel Management System\n"
                      "\t\tCustomer Register Screen"
                      "\n\n\t\tEnter your username: ";
                string username;
                cin>>username;
                fflush(stdin);
                cout<<"\t\tEnter your password: ";
                string password;
                cin>>password;
                fflush(stdin);
                cout<<"\t\tEnter your password again:";
                string password2;
                cin>>password2;
                fflush(stdin);
                cout<<"\t\tEnter your name: ";
                string name;
                cin>>name;
                fflush(stdin);
                cout<<"\t\tEnter your surname: ";
                string surname;
                cin>>surname;
                fflush(stdin);
                cout<<"\t\tEnter your email: ";
                string email;
                cin>>email;
                fflush(stdin);
                cout<<"\t\tEnter your phone number: ";
                string phone_number;
                cin>>phone_number;
                fflush(stdin);
                bool register_status = false;
                admin myAdmin;
                try {
                    register_status = myAdmin.manager_register(username,password,password2,email,phone_number,name,surname);
                }
                catch (invalid_argument &e){
                    cerr<<"Error while registering: "<<e.what();
                    choice2 = 0;
                    cout<<"Existing system. Press anything to continue.";
                    getch();
                    break;
                }
                if (register_status){
                    cout<<"\n\t\tYou have successfully registered. Press anything to continue.";
                    getch();
                    choice2 = 0;
                    break;
                }
                else {
                    cout<<"\n\t\tYou entered wrong information. Do you want to try again?(y/n) ";
                    char choice3 = getch();
                    fflush(stdin);
                    while (choice3 != 'y' && choice3 != 'Y' && choice3 != 'n' && choice3 != 'N'){
                        cout<<"\n\t\tInvalid choice. Please try again: ";
                        choice3 = getch();
                        fflush(stdin);
                    }
                    if (choice3 == 'n' || choice3 == 'N'){
                        choice2 = 0;
                        break;
                    }
                }
            }
            if (choice2 == '3'){
                choice = '9';
                break;
            }
            if (choice2 == '0'){
                choice = '0';
                break;
            }
        }
        if (choice == '0'){
            system("cls");
            cout << "\n\n\t\tThank you for using my program. Goodbye!"
                    "\n\t\t\tBy Dreamment";
            break;
        }
    }
    return 1;
}
