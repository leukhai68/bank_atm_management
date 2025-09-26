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
#ifdef _WIN32
#endif
// ios::out có nghĩa là bạn muốn mở một tệp ở chế độ đầu ra (để ghi dữ liệu vào tệp)
// ios::in có nghĩa là bạn muốn mở một tệp ở chế độ nhập liệu (để trích xuất dữ liệu trong tệp)
// ios::app có nghĩa là bạn muốn mở một tệp ở chế độ thêm (để ghi dữ liệu vào tệp sau byte cuối cùng. Bạn sử dụng chế độ này nếu muốn giữ nguyên dữ liệu hiện có trong tệp và không muốn ghi đè lên như khi sử dụng chế độ tệp ios::out).
using namespace std;

class bank
{
private:
    long long pin;
    long long balance;
    string id, pass, name, fname, address, phone;
    int change = 1;

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
    if(change){
        cout << "\n\n\t\t\t";
        cout << "\n\n 1.Bank Management";
        cout << "\n 2.Exit";
        cout << "\n 3.Language: Vietnamese";
        cout << "\n\n Enter your choice : ";
    }else{
        cout << "\n\n\t\t\t";
        cout << "\n\n 1.Quản lý ngân hàng";
        cout << "\n 2.Thoát";
        cout << "\n 3.Language: English";
        cout << "\n\n Nhập lựa chọn của bạn : ";
    }
    long long choice;
    if (!(cin >> choice)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(change) cout << "\n Invalid... Try again!!!";
        else cout << "\n Không hợp lệ... Thử lại!!!";
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
        if(change){
            cout << "\n\n\t\t\tLogin Account Host";
            cout << "\n\n Email : ";
        }else{
            cout << "\n\n\t\t\tĐăng nhập tài khoản quản trị";
            cout << "\n\n Email : ";
        }
        cin >> email;
        if(change) cout << "\n\n Pin Code : ";
        else cout << "\n\n Mã Pin :";
        for(long long i = 1; i <= 1; i++){
            ch = getch();
            pin += ch;
            cout << "*";
        }
        if(change) cout << "\n\n Password : ";
        else cout << "\n\n Mật khẩu : ";
        for(long long i = 1; i <= 1; i++){
            ch = getch();
            pass += ch;
            cout << "*";
        }
        if(email == "1" && pin == "1" && pass == "1"){
            bank_quanli();
        }
        else{
            if(change) cout << "\n\n Your email, pin, pass is wrong. Try again!!!";
            else cout << "\n\n Email, pin, mật khẩu của bạn sai. Thử lại!!!";
            getch();
        }
        break;
    }
    case 2:
        exit(0);
    case 3:
        if(change) change = 0;
        else change = 1;
        goto p;
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
    if(change){
        cout << "\n\n\t\t\t Welcome to KhaiKevin Bank Management";
        cout << "\n\n 1. New User";      // tạo tài khoản
        cout << "\n 2. Already User";    // tài khoản cũ
        cout << "\n 3. Deposit Option";  // gửi tiền
        cout << "\n 4. Withdraw Option"; // rút tiền
        cout << "\n 5. Print Statement"; // in sao kê
        cout << "\n 6. Go Back";         // quay lại menu
        cout << "\n\n Enter your choice: ";
    }else{
        cout << "\n\n\t\t\t Chào mừng tới KhaiKevin Bank";
        cout << "\n\n 1. Tạo tài khoản";
        cout << "\n 2. Tài khoản đã có";
        cout << "\n 3. Gửi tiền";
        cout << "\n 4. Rút tiền";
        cout << "\n 5. In sao kê";
        cout << "\n 6. Quay lại";
        cout << "\n\n Nhập lựa chọn: ";
    }
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
        if(change) cout << "\n\n Invalid...Try again!!!";
        else cout << "\n\n Không hợp lệ... Thử lại!!!";
    }
}
void chuanhoa(string &s){
    stringstream ss(s);
    string token , res = "";
    while(ss >> token){
        token[0] = toupper(token[0]);
        for(int i = 1; i < token.size(); i++){
            token[i] = tolower(token[i]);
        }
        res += token + " ";
    }
    if(!res.empty()) res.pop_back(); // bỏ space cuối
    s = res;
}
void bank::new_user()
{
    p:
    system("cls");
    fstream file;
    if(change){
        cout << "\n\n\t\t\tAdd New User";
        cout << "\n\n User ID : ";
    }else{
        cout << "\n\n\t\t\tThêm người dùng mới";
        cout << "\n\n ID người dùng : ";
    }
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
                if(change) cout << "\n User Id Already Exist...";
                else cout << "\n Id người dùng đã tồn tại...";
                getch();
                goto p; // quay lại nhập lại từ đầu
            }
        }
    }
    if(change) cout << "\n\n\t\tName : ";
    else cout << "\n\n\t\tTên : ";
    cin >> ws;
    getline(cin, name);
    chuanhoa(name);
    if(change) cout << "\n\n Father Name : ";
    else cout << "\n\n Tên bố : ";
    cin >> ws;
    getline(cin, fname);
    chuanhoa(fname);
    if(change) cout << "\n\n\t\tAddress : ";
    else cout << "\n\n\t\tĐịa chỉ : ";
    cin >> ws;
    getline(cin, address);
    chuanhoa(address);
    if(change) cout << "\n\n Pin Code 6 numbers : ";
    else cout << "\n\n Mã Pin 6 số : ";
    cin >> pin;
    if (pin < 100000 || pin > 999999)
    {
        if(change) cout << "\n\n Pin Code must be 6 numbers...";
        else cout << "\n\n Mã Pin phải có 6 số...";
        getch();
        goto p;
    }
    if(change) cout << "\n\n\t\tPassword : ";
    else cout << "\n\n\t\tMật khẩu : ";
    cin >> pass;
    if(change) cout << "\n\n Phone Number. : ";
    else cout << "\n\n Số điện thoại : ";
    cin >> phone;
    if(change) cout << "\n\n\t\t Current Balance : ";
    else cout << "\n\n\t\t Số dư hiện tại : ";
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
        if(change) cout << "\n\n Cannot open bank.txt for writing!";
        else cout << "\n\n Không thể mở bank.txt để ghi!";
        getch();
        return;
    }
    file << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << fixed << setprecision(0) << balance << "\n";
    file.close();
    if(change) cout << "\n\n New User Account Created Successfully";
    else cout << "\n\n Tài khoản người dùng mới được tạo thành công";
    getch();
}

void bank::alrady_user()
{
    system("cls");
    fstream file;
    string t_id;
    long long found = 0;
    if(change) cout << "\n\n\t\t\tAlready User Account";
    else cout << "\n\n\t\t\tTài khoản đã có";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        if(change) cout << "\n\n File Opening Error...";
        else cout << "\n\n Lỗi mở file...";
    }
    else
    {
        if(change) cout << "\n\n User ID : ";
        else cout << "\n\n ID người dùng : ";
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
                long long balance;
                // đọc các trường còn lại
                ss >> name >> fname >> address >> pin >> pass >> phone >> balance;
                system("cls");
                if(change) cout << "\n\n Already User Account";
                else cout << "\n\n Tài khoản đã có";
                if(change) cout << "\n\n User ID : " << id << "   Name : " << name << "   Pin Code : " << pin << "   Password : " << pass;
                else cout << "\n\n ID người dùng : " << id << "   Tên : " << name << "   Mã Pin : " << pin << "   Mật khẩu : " << pass;
                found = 1;
                break;
            }
        }
        file.close();
        if (found == 0)
        {
            if(change) cout << "\n\n User ID Not Found...";
            else cout << "\n\n Không tìm thấy ID người dùng...";
        }
    }
}

void bank::deposit_option()
{
    fstream file, file1;
    system("cls");
    if(change) cout << "\n\n\t\t\t Deposit Amount Option";
    else cout << "\n\n\t\t\t Gửi tiền";
    string t_id;
    long long tiengui;
    long long found = 0;
    file.open("bank.txt", ios::in);
    if (!file)
    {
        if(change) cout << "\n\n File Opening Error..";
        else cout << "\n\n Lỗi mở file...";
        return;
    }
    if(change) cout << "\n\n User ID: ";
    else cout << "\n\n ID người dùng: ";
    cin >> t_id;
    // Ghi mới file tạm, KHÔNG dùng ios::app
    file1.open("bank1.txt", ios::out | ios::trunc);
    // Lặp theo điều kiện đọc thành công, không dùng eof()
    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance)
    {
        if (t_id == id)
        {
            if(change) cout << "\n\n Amount For Deposit: ";
            else cout << "\n\n Số tiền gửi: ";
            while (!(cin >> tiengui))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if(change == 0) cout << "Nhap lai so tien: ";
                else cout << "Re-enter the amount: ";
            }
            balance += tiengui;
            found = 1;
            if(change) {
                cout << "\n\n\t\t\t Your Amount : " << fixed << setprecision(0) << tiengui << " Successfully Deposit";
                cout << "\n\n\t\t\t Your Current Balance : " << fixed << setprecision(0) << balance;
            }else{ 
                cout << "\n\n\t\t\t Số tiền của bạn : " << fixed << setprecision(0) << tiengui << " Gửi tiền thành công";
                cout << "\n\n\t\t\t Số dư hiện tại của bạn : " << fixed << setprecision(0) << balance;
            }
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
            log << stt + 1 << " " << id << " " << ngay1 << "/" << thang1 << "/" << nam << " " << tiengui << " " << "DEPOSIT" << "\n";
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
        if(change) cout << "\n\n User ID Not Found...";
        else cout << "\n\n Không tìm thấy ID người dùng...";
    }
}
void bank::withdraw_option()
{
    fstream file, file1;
    system("cls");
    if(change) cout << "\n\n\t\t\t Withdraw Amount Option";
    else cout << "\n\n\t\t\t Rút tiền";
    string t_id;
    long long tienrut;
    bool foundUser = false; // tách cờ: đã tìm thấy user
    bool updated = false;   // đã trừ tiền thành công
    file.open("bank.txt", ios::in);
    if (!file)
    {
        if(change) cout << "\n\n File Opening Error..";
        else cout << "\n\n Lỗi mở file...";
        return;
    }
    if(change) cout << "\n\n User ID: ";
    else cout << "\n\n ID người dùng: ";
    cin >> t_id;
    file1.open("bank1.txt", ios::out | ios::trunc);
    // Lưu ý: đọc bằng >> sẽ hỏng nếu name/fname/address có dấu cách
    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance)
    {
        if (t_id == id)
        {
            foundUser = true; // ĐÁNH DẤU NGAY KHI TÌM THẤY
            if(change) cout << "\n\n Amount For Withdraw: ";
            else cout << "\n\n Số tiền rút: ";
            while (!(cin >> tienrut) || tienrut <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if(change == 0) cout << "Nhap lai so tien (>0): ";
                else cout << "Re-enter the amount (>0): ";
            }
            if (tienrut > balance)
            {
                if(change) cout << "\n\n\t\t\t Your Current Balance is not enough...";
                else cout << "\n\n\t\t\t Số dư hiện tại của bạn không đủ...";
                // KHÔNG cập nhật balance, updated vẫn false
            }
            else
            {
                balance -= tienrut;
                updated = true;
                if(change){
                    cout << "\n\n\t\t\t Your Amount : " << fixed << setprecision(0) << tienrut << " Successfully Withdraw";
                    cout << "\n\n\t\t\t Your Current Balance : " << fixed << setprecision(0) << balance;
                }else{
                    cout << "\n\n\t\t\t Số tiền của bạn : " << fixed << setprecision(0) << tienrut << " Rút tiền thành công";
                    cout << "\n\n\t\t\t Số dư hiện tại của bạn : " << fixed << setprecision(0) << balance;
                }
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
                log << stt + 1 << " " << id << " " << ngay1 << "/" << thang1 << "/" << nam << " " << tienrut << " " << "WITHDRAW" << "\n";
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
        if(change) cout << "\n\n User ID Not Found...";
        return;
    }
    // Có user: thay file gốc bằng file tạm (kể cả không đủ tiền thì dữ liệu không đổi)
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");
}

#include <iomanip>

void bank::print_statement()
{
    system("cls");
    if(change){
        cout << "\n\n\t\t\t Print Statment Option";
        cout << "\n\n User Id: ";
    }else{
        cout << "\n\n\t\t\t In sao kê";
        cout << "\n\n Id người dùng: ";
    }
    string t_id;
    cin >> t_id;
    ifstream fin("saoke.txt");
    if (!fin)
    {
        if(change) cout << "\n\n Error in opening file...";
        else cout << "\n\n Lỗi khi mở file...";
        return;
    }
    
    // Tiêu đề
    if(change == 0){
        cout << "\n\n\t\tSao Ke Tai Khoan ID: " << t_id << "\n";
    }else{
        cout << "\n\n\t\tStatement for Account ID: " << t_id << "\n";
    }
    
    // Bảng đơn giản với ký tự ASCII
    cout << "+------+-------------+----------------------+----------+\n";
    
    // Tiêu đề cột
    if(change == 0){
        cout << "| " << left << setw(4) << "STT" << "| "
             << setw(11) << "TGIAN" << "| "
             << setw(20) << "So tien" << "| "
             << setw(8) << "Ghi Chu" << "     |\n";
    }else{
        cout << "| " << left << setw(4) << "No." << "| "
             << setw(11) << "Date" << "| "
             << setw(20) << "Amount" << "| "
             << setw(8) << "Note" << "     |\n";
    }
    
    cout << "+------+-------------+----------------------+----------+\n";
    
    auto localnote = [&](const string& code) -> string{
        if(change){
            if(code == "DEPOSIT") return "Deposit";
            if(code == "WITHDRAW") return "Withdraw";
            return code;
        }else{
            if(code == "DEPOSIT") return "Gui tien";
            if(code == "WITHDRAW") return "Rut tien";
            return code;
        }
    };
    
    string line;
    long long found = 0;
    int stt_rieng = 0;
    while (getline(fin, line))
    {
        if (line.empty())
            continue;
            
        stringstream ss(line);
        long long stt;
        string uid, date, note;
        long long amount;
        if (!(ss >> stt >> uid >> date >> amount >> note))
        {
            continue;
        }
        if (uid == t_id)
        {
            stt_rieng++;
            found = 1;
            
            // In dữ liệu với căn lề
            cout << "| " << left << setw(4) << stt_rieng << "| "
                 << setw(11) << date << "| "
                 << setw(20) << amount << "| "
                 << setw(8) << localnote(note) << "     |\n";
        }
    }
    
    // Đường kẻ cuối
    if (found) {
        cout << "+------+-------------+----------------------+----------+\n";
    } else {
        if(change == 0) 
            cout << "|               Khong co giao dich cho ID nay!               |\n";
        else 
            cout << "|               No transactions for this ID!               |\n";
        cout << "+----------------------------------------------------------+\n";
    }
    fin.close();
}
int main()
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // xuất UTF-8
    SetConsoleCP(CP_UTF8);       // đọc UTF-8 (nếu cần)
    #endif
    bank obj;
    obj.menu();
    return 0;
}
