#include <iostream>
#include <fstream> // thư viện dùng để đọc ghi file
#include <conio.h> // để dùng getch()
#include <string>
#include <stdio.h>
#include <windows.h>
#include <limits>
#include <sstream>
#include <ctime>
#include <iomanip>
// ios::out có nghĩa là bạn muốn mở một tệp ở chế độ đầu ra (để ghi dữ liệu vào tệp)
// ios::in có nghĩa là bạn muốn mở một tệp ở chế độ nhập liệu (để trích xuất dữ liệu trong tệp)
// ios::app có nghĩa là bạn muốn mở một tệp ở chế độ thêm (để ghi dữ liệu vào tệp sau byte cuối cùng. Bạn sử dụng chế độ này nếu muốn giữ nguyên dữ liệu hiện có trong tệp và không muốn ghi đè lên như khi sử dụng chế độ tệp ios::out).
using namespace std;

class bank
{
private:
    long long pin;
    double balance;
    string id, pass, name, fname, address, phone;

public:
    void menu();
    void bank_quanli();
    void new_user();
    void alrady_user();
    void deposit_option();
    void withdraw_option();
    void print_statement();
};
void bank::menu()
{
p:
    system("cls"); // clear screen -> tác dụng xoá sạch màn hình console
    cout << "\n\n\t\t\t";
    cout << "\n\n 1.Bank Management";
    cout << "\n 2.Exit";
    cout << "\n\n Enter your choice : ";
    long long choice;
    if (!(cin >> choice))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n Invalid... Try again!!!";
        getch();
        goto p;
    }
    switch (choice)
    {
    case 1:
    {
        system("cls");
        string email, pin, pass;
        char ch;
        cout << "\n\n\t\t\tLogin Account Host";
        cout << "\n\n Email : ";
        cin >> email;
        cout << "\n\n Pin Code : ";
        for (long long i = 1; i <= 1; i++)
        {
            ch = getch();
            pin += ch;
            cout << "*";
        }
        cout << "\n\n Password : ";
        for (long long i = 1; i <= 1; i++)
        {
            ch = getch();
            pass += ch;
            cout << "*";
        }
        if (email == "1" && pin == "1" && pass == "1")
        {
            bank_quanli();
        }
        else
        {
            cout << "\n\n Your email, pin, pass is wrong. Try again!!!";
            getch();
        }
        break;
    }
    case 2:
        exit(0);
    default:
        cout << "\n\n Invalid...Try again!!!";
        getch();
        break;
    }
    getch(); // thao tác nhập
    goto p;  // quay lại điểm đánh dấu
}
void bank::bank_quanli()
{
p:
    system("cls");
    long long choice;
    cout << "\n\n\t\t\t Welcome to KhaiKevin Bank Management";
    cout << "\n\n 1. New User";      // tạo tài khoản
    cout << "\n 2. Already User";    // tài khoản cũ
    cout << "\n 3. Deposit Option";  // gửi tiền
    cout << "\n 4. Withdraw Option"; // rút tiền
    cout << "\n 5. Print Statement"; // in sao kê
    cout << "\n 6. Go Back";         // quay lại menu
    cout << "\n\n Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
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
        print_statement();
        break;
    case 6:
        menu();
    default:
        cout << "\n\n Invalid...Try again!!!";
    }
}

void bank::new_user()
{
p:
    system("cls");
    fstream file;
    cout << "\n\n\t\t\tAdd New User";
    cout << "\n\n User ID : ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // dọn Enter 1 lần
    ifstream fin("bank.txt");
    if (fin)
    {
        string t_id;
        while (fin >> t_id)
        {                                                        // đọc token đầu (ID)
            fin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ phần còn lại của dòng
            if (t_id == id)
            {
                cout << "\n User Id Already Exist...";
                getch();
                goto p; // quay lại nhập lại từ đầu
            }
        }
    }
    cout << "\n\n\t\tName : ";
    cin >> ws;
    getline(cin, name);
    cout << "\n\n Father Name : ";
    cin >> ws;
    getline(cin, fname);
    cout << "\n\n\t\tAddress : ";
    cin >> ws;
    getline(cin, address);
    cout << "\n\n Pin Code 6 numbers : ";
    cin >> pin;
    if (pin < 100000 || pin > 999999)
    {
        cout << "\n\n Pin Code must be 6 numbers...";
        getch();
        goto p;
    }
    cout << "\n\n\t\tPassword : ";
    cin >> pass;
    cout << "\n\n Phone No. : ";
    cin >> phone;
    cout << "\n\n\t\t Current Balance : ";
    cin >> balance;
    // thay space = '_'
    for (size_t i = 0; i < name.size(); ++i)
        if (name[i] == ' ')
            name[i] = '_';
    for (size_t i = 0; i < fname.size(); ++i)
        if (fname[i] == ' ')
            fname[i] = '_';
    for (size_t i = 0; i < address.size(); ++i)
        if (address[i] == ' ')
            address[i] = '_';
    // ghi dữ liệu mới
    file.open("bank.txt", ios::app | ios::out);
    if (!file)
    {
        cout << "\n\n Cannot open bank.txt for writing!";
        getch();
        return;
    }
    file << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << fixed << setprecision(0) << balance << "\n";
    file.close();
    cout << "\n\n New User Account Created Successfully";
    getch();
}

void bank::alrady_user()
{
    system("cls");
    fstream file;
    string t_id;
    long long found = 0;
    cout << "\n\n\t\t\tAlready User Account";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error...";
    }
    else
    {
        cout << "\n\n User ID: ";
        cin >> t_id;
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string id;
            ss >> id; // đọc token đầu tiên = User ID
            if (id == t_id)
            {
                string name, fname, address, pin, pass, phone;
                float balance;
                // đọc các trường còn lại
                ss >> name >> fname >> address >> pin >> pass >> phone >> balance;
                system("cls");
                cout << "\n\n Already User Account";
                cout << "\n\n User ID : " << id << "   Ten : " << name << "   Pin Code : " << pin << "   Password : " << pass;
                found = 1;
                break;
            }
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n User ID Not Found...";
        }
    }
}

void bank::deposit_option()
{
    fstream file, file1;
    system("cls");
    cout << "\n\n\t\t\t Deposit Amount Option";
    string t_id;
    float tiengui;
    long long found = 0;
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error..";
        return;
    }
    cout << "\n\n User ID: ";
    cin >> t_id;
    // Ghi mới file tạm, KHÔNG dùng ios::app
    file1.open("bank1.txt", ios::out | ios::trunc);
    // Lặp theo điều kiện đọc thành công, không dùng eof()
    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance)
    {
        if (t_id == id)
        {
            cout << "\n\n Amount For Deposit: ";
            while (!(cin >> tiengui))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nhap lai so tien: ";
            }
            balance += tiengui;
            found = 1;
            cout << "\n\n\t\t\t Your Amount : " << fixed << setprecision(0) << tiengui << " Successfully Deposit";
            long long stt = 0;
            // tính số thứ tự
            ifstream dem("saoke.txt");
            string tien;
            while (getline(dem, tien))
                stt++;
            dem.close();
            // nhập ngày tháng năm
            time_t now = time(0);
            tm t = *localtime(&now);
            long long nam = 1900 + t.tm_year;
            long long thang = 1 + t.tm_mon;
            long long ngay = t.tm_mday;
            string ngay1, thang1;
            if (ngay < 10)
            {
                ngay1 = "0" + to_string(ngay);
            }
            else
            {
                ngay1 = to_string(ngay);
            }
            if (thang < 10)
            {
                thang1 = "0" + to_string(thang);
            }
            else
            {
                thang1 = to_string(thang);
            }
            // ghi 1 dong log stt id date tien note
            ofstream log("saoke.txt", ios::app);
            log << stt + 1 << " " << id << " " << ngay1 << "/" << thang1 << "/" << nam << " " << tiengui << " " << "Gui_Tien" << "\n";
            log.close();
        }
        // Ghi (đã cập nhật hoặc giữ nguyên) sang file tạm
        file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
    }
    file.close();
    file1.close();
    if (found)
    {
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
    }
    else
    {
        remove("bank1.txt");
        cout << "\n\n User ID Not Found...";
    }
}
void bank::withdraw_option()
{
    fstream file, file1;
    system("cls");
    cout << "\n\n\t\t\t Withdraw Amount Option";
    string t_id;
    float tienrut;
    bool foundUser = false; // tách cờ: đã tìm thấy user
    bool updated = false;   // đã trừ tiền thành công
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error..";
        return;
    }
    cout << "\n\n User ID: ";
    cin >> t_id;
    file1.open("bank1.txt", ios::out | ios::trunc);
    // Lưu ý: đọc bằng >> sẽ hỏng nếu name/fname/address có dấu cách
    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance)
    {
        if (t_id == id)
        {
            foundUser = true; // ĐÁNH DẤU NGAY KHI TÌM THẤY
            cout << "\n\n Amount For Withdraw: ";
            while (!(cin >> tienrut) || tienrut <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nhap lai so tien (>0): ";
            }
            if (tienrut > balance)
            {
                cout << "\n\n\t\t\t Your Current Balance is not enough...";
                // KHÔNG cập nhật balance, updated vẫn false
            }
            else
            {
                balance -= tienrut;
                updated = true;
                cout << "\n\n\t\t\t Your Amount : " << fixed << setprecision(0) << tienrut << " Successfully Withdraw";
                long long stt = 0;
                // tính số thứ tự
                ifstream dem("saoke.txt");
                string tien;
                while (getline(dem, tien))
                    stt++;
                dem.close();
                // nhập ngày tháng năm
                time_t now = time(0);
                tm t = *localtime(&now);
                long long nam = 1900 + t.tm_year;
                long long thang = 1 + t.tm_mon;
                long long ngay = t.tm_mday;
                string ngay1, thang1;
                if (ngay < 10)
                {
                    ngay1 = "0" + to_string(ngay);
                }
                else
                {
                    ngay1 = to_string(ngay);
                }
                if (thang < 10)
                {
                    thang1 = "0" + to_string(thang);
                }
                else
                {
                    thang1 = to_string(thang);
                }
                // ghi 1 dong log stt id date tien note
                ofstream log("saoke.txt", ios::app);
                log << stt + 1 << " " << id << " " << ngay1 << "/" << thang1 << "/" << nam << " " << tienrut << " " << "Rut_Tien" << "\n";
                log.close();
            }
        }
        // Ghi (đã cập nhật hoặc giữ nguyên) sang file tạm
        file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
    }
    file.close();
    file1.close();
    if (!foundUser)
    {
        remove("bank1.txt");
        cout << "\n\n User ID Not Found...";
        return;
    }
    // Có user: thay file gốc bằng file tạm (kể cả không đủ tiền thì dữ liệu không đổi)
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");
}

void bank::print_statement()
{
    system("cls");
    cout << "\n\n\t\t\t Print Statment Option";
    cout << "\n\n User Id: ";
    string t_id;
    cin >> t_id;
    ifstream fin("saoke.txt");
    if (!fin)
    {
        cout << "\n\n Error in opening file...";
        return;
    }
    cout << "\n\n\t\tSao Ke Tai Khoan ID: " << t_id << "\n";
    cout << "STT   NgayThangNam     SoTien         Note\n";
    cout << "-----------------------------------------------\n";
    string line;
    long long found = 0;
    while (getline(fin, line))
    {
        if (line.empty())
            continue;
        // parse từng dòng
        stringstream ss(line);
        long long stt;
        string uid, date, note;
        double amount;
        if (!(ss >> stt >> uid >> date >> amount >> note))
        {
            // Dòng sai định dạng -> in ra để bạn kiểm tra
            cout << "[LOI FORMAT] " << line << "\n";
            continue;
        }
        if (uid == t_id)
        {
            found = 1;
            // in có canh lề cơ bản
            cout << stt << "     " << date << "\t" << amount << "           " << note << "\n";
        }
    }
    if (!found)
    {
        cout << "\nKhong co giao dich nao cho User ID nay!\n";
    }
    fin.close();
}

int main()
{
    bank obj;
    obj.menu();
    return 0;
}
