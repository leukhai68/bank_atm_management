#include <iostream>
#include <fstream> // thư viện dùng để đọc ghi file
#include <conio.h> // để dùng getch()
#include <string>
#include <stdio.h>
#include <windows.h>
using namespace std;

class bank{
private:
    int pin;
    float balance;
    string id, pass, name, fname, address, phone;

public:
    void menu();
    void bank_quanli();
    void new_user();
    void alrady_user();
    void deposit_option();
};
void bank::menu(){
    p:
    system("cls"); // clear screen -> tác dụng xoá sạch màn hình console
    cout << "\n\n\t\t\t";
    cout << "\n\n 1.Bank Management";
    cout << "\n 2.Exit";
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
        if(email == "khaikevin" && pin == "123456" && pass == "123456"){
            bank_quanli();
        }
        else{
            cout << "\n\n Your email, pin, pass is wrong !!!";
        }
        break;
    }
    case 2:
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
    cout << "\n\n 1. New User";  // tạo tài khoản
    cout << "\n 2. Already User";  // tài khoản cũ
    cout << "\n 3. Deposit Option";  // gửi tiền
    cout << "\n 4. Withdraw Option"; // rút tiền
    cout << "\n 5. Transfer Option"; // chuyển tiền
    cout << "\n 6. Payment Option"; // thanh toán
    cout << "\n 7. Search User Record";  // tìm kiếm tài khoản
    cout << "\n 8. Edit User Record"; // chỉnh sửa tài khoản
    cout << "\n 9. Delete User Record"; // xoá tài khoản
    cout << "\n 10. Show All Records"; // hiển thị tất cả tài khoản
    cout << "\n 11. Transfer Option"; // chuyển tiền
    cout << "\n 12. Go Back"; // quay lại menu 
    cout << "\n\n Enter your choice: ";
    cin >> choice;
    switch(choice){
    case 1:
        new_user();
        break;
    case 2:
        alrady_user();
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

void bank::new_user(){
    p:
    system("cls");
    fstream file;
    int p;
    float b;
    string n,f,pa,a,ph,i;
    cout << "\n\n\t\t\tAdd New User";
    cout << "\n\n User ID : ";
    cin >> id;
    cout << "\n\n\t\tName : ";
    cin.ignore();
    getline(cin, name);
    cout << "\n\n Father Name : ";
    getline(cin, fname);
    cout << "\n\n\t\tAddress : ";
    cin.ignore();
    getline(cin,address);
    cout << "\n\n Pin Code 6 numbers : ";
    cin >> pin;
    cout << "\n\n\t\tPassword : ";
    cin >> pass;
    cout << "\n\n Phone No. : ";
    cin >> phone;
    cout << "\n\n\t\t Current Balance : ";
    cin >> balance;
    file.open("bank.txt", ios::in);
    if(!file){   // kiểm tra file đã mở chưa
    // trường hợp file chưa tồn tại thì tạo file mới và ghi dữ liệu vào
        file.open("bank.txt", ios::app | ios::out);
        file << id << '|' << name << '|' << fname << '|' << address << '|'<< pin << '|' << pass << '|' << phone << '|' << balance << "\n";
        file.close();
    }else{
        // trường hợp file đã có thì kiếm tra id đã có chưa
        getline(file, i, '|');
        getline(file, n, '|');
        getline(file, f, '|');
        getline(file, a, '|');
        file >> p;
        file.ignore(); // bỏ ký tự phân cách
        getline(file, pa, '|');
        getline(file, ph, '|');
        file >> b;

        while(!file.eof()){
            if(i == id){
                cout << "\n\n User Id Already Exist...";
                getch();
                goto p;
            }
            getline(file, i, '|');
            getline(file, n, '|');
            getline(file, f, '|');
            getline(file, a, '|');
            file >> p;
            file.ignore(); // bỏ ký tự phân cách
            getline(file, pa, '|');
            getline(file, ph, '|');
            file >> b;
        }
        file.close();
        // nếu không bị trùng id thì ghi dữ liệu vào file
        file.open("bank.txt", ios::app | ios::out);
        file << id << '|' << name << '|' << fname << '|' << address << '|'<< pin << '|' << pass << '|' << phone << '|' << balance << "\n";
        file.close();
    }
    cout << "\n\n New User Account Created Successfully";
}
void bank::alrady_user(){
    system("cls");
    fstream file;
    string t_id;
    int found = 0;
    cout << "\n\n\t\t\tAlready User Account";
    file.open("bank.txt", ios::in);
    if(!file){
        cout << "\n\n File Opening Error...";
    }else{
        cout << "\n\n User ID: ";
        cin >> t_id;
        string id, name, fname, address, pin, pass, phone, balance;
        while(getline(file, id, '|')){
            getline(file, name, '|');
            getline(file, fname, '|');
            getline(file, address, '|');
            getline(file, pin, '|');
            getline(file, pass, '|');
            getline(file, phone, '|');
            getline(file, balance, '\n'); // đọc đến hết dòng
            if(t_id == id){
                system("cls");
                cout << "\n\n Already User Account";
                cout << "\n\n User ID : " << id << "   Pin Code : " << pin << "   Password : " << pass;
                found = 1;
                break;
            }
        }
        file.close();
        if(found == 0){
            cout << "\n\n User ID Not Found...";
        }
    }
}

void bank::deposit_option(){
    
}
int main()
{
    bank obj;
    obj.menu();
    return 0;
}
