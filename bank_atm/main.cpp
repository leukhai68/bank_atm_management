#include <iostream>
#include <fstream>
#include <conio.h> // để dùng getch()
#include <string>
#include <stdio.h>
#include <windows.h>
using namespace std;

class bank{
public:
    void menu();
    void bank_quanli();
    void atm_quanli();
};
void bank::menu(){
    p:
    system("cls"); // clear screen -> tác dụng xoá sạch màn hình console
    cout << "\n\n\t\t\tControl Panel";
    cout << "\n\n 1.Bank Management";
    cout << "\n 2.ATM Management";
    cout << "\n 3.Exit";
    cout << "\n\n Enter your choice : ";
    int choice;
    cin >> choice;
    switch(choice){
    case 1:{
        system("cls");
        string email, pin, pass;
        char ch;
        cout << "\n\n\t\t\tLogin Account";
        cout << "\n\n Email : ";
        cin >> email;
        cout << "\n\n Pin Code : ";
        for(int i = 1; i <= 6; i++){
            ch = getch();
            pin += ch;
            cout << "*";
        }
        cout << "\n\n Password : ";
        for(int i = 1; i <= 6; i++){
            ch = getch();
            pass += ch;
            cout << "*";
        }
        if(email == "khaikevin2006@gmail.com" && pin == "123456" && pass == "123456"){
            bank_quanli();
        }
        else{
            cout << "\n\n Your email, pin, pass is wrong !!!";
        }
        break;
    }
    case 2:
        atm_quanli();
        break;
    case 3:
        exit(0);
    default:
        cout << "\n\n Invalid...Try again!!!";
    }
    getch(); // thao tác nhập
    goto p; // quay lại điểm đánh dấu
}
void bank::bank_quanli(){
    p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\tBank Management System";
    cout << "\n\n 1. New User";
    cout << "\n 2. Already User";
    cout << "\n 3. Deposit Option";
    cout << "\n 4. Withdraw Option";
    cout << "\n 5. Transfer Option";
    cout << "\n 6. Payment Option";
    cout << "\n 7. Search User Record";
    cout << "\n 8. Edit User Record";
    cout << "\n 9. Delete User Record";
    cout << "\n 10. Show All Records";
    cout << "\n 11. Transfer Option";
    cout << "\n 12. Go Back";
    cout << "\n\n Enter your choice: ";
    cin >> choice;
    switch(choice){
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        menu();
    default:
        cout << "\n\n Invalid...Try again!!!";
    }
}
void bank::atm_quanli(){
    p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\tATM Management System";
    cout << "\n\n 1. User Login and Check Balance";
    cout << "\n 2. Withdraw Amount";
    cout << "\n 3. Account Detailes";
    cout << "\n 4. Go back";
    cin >> choice;
    switch(choice){
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        menu();
    default:
        cout << "\n\n Invalid...Try again!!!";
    }
    getch();
    goto p;
}
int main()
{
    bank obj;
    obj.menu();
    return 0;
}
