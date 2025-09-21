#include <iostream>
#include <fstream> // thư viện dùng để đọc ghi file
#include <conio.h> // để dùng getch()
#include <string>
#include <stdio.h>
#include <windows.h>
#include <limits>
#include <sstream>
#include <ctime>
//ios::out có nghĩa là bạn muốn mở một tệp ở chế độ đầu ra (để ghi dữ liệu vào tệp)
//ios::in có nghĩa là bạn muốn mở một tệp ở chế độ nhập liệu (để trích xuất dữ liệu trong tệp)
//ios::app có nghĩa là bạn muốn mở một tệp ở chế độ thêm (để ghi dữ liệu vào tệp sau byte cuối cùng. Bạn sử dụng chế độ này nếu muốn giữ nguyên dữ liệu hiện có trong tệp và không muốn ghi đè lên như khi sử dụng chế độ tệp ios::out).
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
    void withdraw_option();
    void insaoke();
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
        cout << "\n\n\t\t\tLogin Account Host";
        cout << "\n\n Email : ";
        cin >> email;
        cout << "\n\n Pin Code : ";
        for(int i = 1; i <= 1; i++){
            ch = getch();
            pin += ch;
            cout << "*";
        }
        cout << "\n\n Password : ";
        for(int i = 1; i <= 1; i++){
            ch = getch();
            pass += ch;
            cout << "*";
        }
        if(email == "1" && pin == "1" && pass == "1"){
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
    cout << "\n 5. In sao ke"; // in sao kê
    cout << "\n 6. Go Back"; // quay lại menu
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
        deposit_option();
        break;
    case 4:
        withdraw_option();
        break;
    case 5:
        insaoke();
        break;
    case 6:
        menu();
    default:
        cout << "\n\n Invalid...Try again!!!";
    }
}

void bank::new_user(){
    p:
    system("cls");
    fstream file;
    cout << "\n\n\t\t\tAdd New User";
    cout << "\n\n User ID : ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // dọn Enter 1 lần duy nhất
    cout << "\n\n\t\tName : ";
    getline(cin, name);
    cout << "\n\n Father Name : ";
    getline(cin, fname);
    cout << "\n\n\t\tAddress : ";
    getline(cin, address);  // KHÔNG ignore thêm ở đây
    cout << "\n\n Pin Code 6 numbers : ";
    cin >> pin;
    cout << "\n\n\t\tPassword : ";
    cin >> pass;
    cout << "\n\n Phone No. : ";
    cin >> phone;
    cout << "\n\n\t\t Current Balance : ";
    cin >> balance;
    // --- kiểm tra trùng id, chỉ đọc token đầu rồi bỏ phần còn lại của dòng ---
    file.open("bank.txt", ios::in);
    if(file){
        string i;
        while (file >> i){ // lấy đúng token đầu là ID
            file.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ phần còn lại (tên/địa chỉ...)
            if(i == id){
                cout << "\n\n User Id Already Exist...";
                file.close();
                getch();
                goto p;
            }
        }
        file.close();
    }else{
        // nếu mở ios::in thất bại, xóa failbit để còn mở lại ở dưới
        file.clear();
    }
    // --- ghi dữ liệu mới, giữ đúng format cách trắng như bạn muốn ---
    file.open("bank.txt", ios::app | ios::out);
    file << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
    file.close();
    cout << "\n\n New User Account Created Successfully";
    getch();
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
    } else {
        cout << "\n\n User ID: ";
        cin >> t_id;
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id;
            ss >> id; // đọc token đầu tiên = User ID
            if(id == t_id){
                string name, fname, address, pin, pass, phone;
                float balance;
                // đọc các trường còn lại
                ss >> name >> fname >> address >> pin >> pass >> phone >> balance;
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
    fstream file, file1;
    system("cls");
    cout << "\n\n\t\t\t Deposit Amount Option";
    string t_id;
    float tiengui;
    int found = 0;
    file.open("bank.txt", ios::in);
    if(!file){
        cout << "\n\n File Opening Error..";
        return;
    }
    cout << "\n\n User ID: ";
    cin >> t_id;
    // Ghi mới file tạm, KHÔNG dùng ios::app
    file1.open("bank1.txt", ios::out | ios::trunc);
    // Lặp theo điều kiện đọc thành công, không dùng eof()
    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance){
        if (t_id == id){
            cout << "\n\n Amount For Deposit: ";
            while(!(cin >> tiengui)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nhap lai so tien: ";
            }
            balance += tiengui;
            found = 1;
            cout << "\n\n\t\t\t Your Amount : " << tiengui << " Successfully Deposit";
            int stt = 0;
            // tính số thứ tự
            ifstream dem("saoke.txt");
            string tien;
            while(getline(dem, tien)) stt++;
            dem.close();
            // nhập ngày tháng năm
            string date;
            cin >> date;
            // ghi 1 dong log stt id date tien note
            ofstream log("saoke.txt", ios::app);
            log << stt + 1 << " " << id << " " << date << " " << tiengui << " " << "Gui Tien" << "\n";
            log.close();
        }
        // Ghi (đã cập nhật hoặc giữ nguyên) sang file tạm
        file1 << id << " " << name << " " << fname << " " << address << " "
              << pin << " " << pass << " " << phone << " " << balance << "\n";
    }
    file.close();
    file1.close();
    if(found){
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
    }else{
        remove("bank1.txt");
        cout << "\n\n User ID Not Found...";
    }
}
void bank::withdraw_option(){
    fstream file, file1;
    system("cls");
    cout << "\n\n\t\t\t Withdraw Amount Option";
    string t_id;
    float tienrut;
    bool foundUser = false;   // tách cờ: đã tìm thấy user
    bool updated   = false;   // đã trừ tiền thành công
    file.open("bank.txt", ios::in);
    if(!file){
        cout << "\n\n File Opening Error..";
        return;
    }
    cout << "\n\n User ID: ";
    cin >> t_id;
    file1.open("bank1.txt", ios::out | ios::trunc);
    // Lưu ý: đọc bằng >> sẽ hỏng nếu name/fname/address có dấu cách
    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance){
        if (t_id == id){
            foundUser = true; // ĐÁNH DẤU NGAY KHI TÌM THẤY
            cout << "\n\n Amount For Withdraw: ";
            while(!(cin >> tienrut) || tienrut <= 0){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nhap lai so tien (>0): ";
            }
            if(tienrut > balance){
                cout << "\n\n\t\t\t Your Current Balance is not enough...";
                // KHÔNG cập nhật balance, updated vẫn false
            } else {
                balance -= tienrut;
                updated = true;
                cout << "\n\n\t\t\t Your Amount : " << tienrut << " Successfully Withdraw";
            }
        }
        // Ghi (đã cập nhật hoặc giữ nguyên) sang file tạm
        file1 << id << " " << name << " " << fname << " " << address << " "
              << pin << " " << pass << " " << phone << " " << balance << "\n";
    }
    file.close();
    file1.close();
    if(!foundUser){
        remove("bank1.txt");
        cout << "\n\n User ID Not Found...";
        return;
    }
    // Có user: thay file gốc bằng file tạm (kể cả không đủ tiền thì dữ liệu không đổi)
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");
}

int main()
{
    bank obj;
    obj.menu();
    return 0;
}
