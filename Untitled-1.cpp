//lab0
// Шифр Цезаря
#include <iostream>
#include <string>

using namespace std;

string shifr(string text, int key) {
    string shifrtext = "";

    for (char& c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            shifrtext += static_cast<char>((c - base + key) % 26 + base);
        } else {
            shifrtext += c;
        }
    }

    return shifrtext;
}

int main() {
    int key;
    string text;

    cout << "Key: ";
    cin >> key;
    cin.ignore();

    cout << "Text: ";
    getline(cin, text);

    string shifrtext = shifr(text, key);

    cout << "Code: " << shifrtext << endl;

    return 0;
}

//lab1
// 2 ------------------------------------------------------------

#include <iostream>

using namespace std;

int main() {
    const int n = 20;  
    char a[n];      

    cout << "Vvedite 20 simvolov:" << endl;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << "Stro4nie simvoly: ";
    for (int i = 0; i < n; ++i) {
        if (islower(a[i])) {
            cout << a[i] << " ";
        }
    }
    cout << endl;

    cout << "Propisniy simvoly: ";
    for (int i = 0; i < n; ++i) {
        if (isupper(a[i])) {
            cout << a[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

// 4 ---------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> chet;
    vector<int> nechet;

    cout << "Vvedite 20 4isel:\n";

    for (int i = 0; i < 20; ++i) {
        int n;
        cin >> n;

        if (n % 2 == 0) {
            chet.push_back(n);
        } else {
            nechet.push_back(n);
        }
    }

    cout << "4etnie:\n";
    for (int i : chet) {
        cout << i << " ";
    }

    cout << "\nNe4etnie:\n";
    for (int i : nechet) {
        cout << i << " ";
    }

    return 0;
}

// 6 ---------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int n = 20;
    vector<int> selae;
    vector<double> drobnay;

    for (int i = 0; i < n; i++) {
        double a;
        cout << "Vvedite 4isla " << i + 1 << ": ";
        cin >> a;

        if (a == static_cast<int>(a)) {
            selae.push_back(static_cast<int>(a));
        } else {
            drobnay.push_back(a);
        }
    }

    cout << "Selae\tDrobnay " << endl;
    for (size_t i = 0; i < max(selae.size(), drobnay.size()); i++) {
        if (i < selae.size()) {
            cout << selae[i];
        }
        cout << "\t\t";
        if (i < drobnay.size()) {
            cout << drobnay[i];
        }
        cout << endl;
    }

    return 0;
}

// 10 --------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

int main() {
    const int numRecords = 6;
    string fullNames[numRecords];

    for (int i = 0; i < numRecords; ++i) {
        cout << "FullName " << i + 1 << ": ";
        getline(cin, fullNames[i]);
    }

    cout << "FirstName\t\tMiddleName\tLastName\n";
    for (int i = 0; i < numRecords; ++i) {
        string fullName = fullNames[i];
        size_t pos1 = fullName.find(' '); 
        size_t pos2 = fullName.find(' ', pos1 + 1);

        if (pos1 != string::npos && pos2 != string::npos) {
            string firstName = fullName.substr(0, pos1);
            string lastName = fullName.substr(pos1 + 1, pos2 - pos1 - 1);
            string middleName = fullName.substr(pos2 + 1);

            cout << firstName << "\t\t" << lastName << "\t\t" << middleName << "\n";
        } else {
            cout << "ERROR: " << fullName << "\n";
        }
    }

    return 0;
}

// 12 ------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

int main() {
    const int n = 5;
    string city[n];
    int code[n];

    for (int i = 0; i < n; i++) {
        cout << "City " << i + 1 << ": ";
        getline(cin, city[i]);
        cout << "City code " << city[i] << ": ";
        cin >> code[i];
        cin.ignore();
    }

    
    cout << "Namder\tCode\tCity" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t\t" << code[i] << "\t\t" << city[i] << endl;
    }

    return 0;
}

//14 --------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

int main() {
    const int n = 6;
    string course[n];
    int grades[n];

    for (int i = 0; i < n; ++i) {
        cout << "Course: " << i + 1 << ": ";
        cin >> course[i];

        cout << "Grade " << course[i] << " (1 - the best, 2 - the better, 3 - good): ";
        cin >> grades[i];
    }

    for (int i = 0; i < n; ++i) {
        string g;

        switch (grades[i]) {
            case 1:
                g = "the best";
                break;
            case 2:
                g = "the better";
                break;
            case 3:
                g = "good";
                break;
            default:
                g = "ERROR";
                break;
        }

        cout << i + 1 << "\t\t" << course[i] << "\t\t" << g << "\n";
    }

    return 0;
}



















//lab2
//2 -------------------------------------------------
#include <iostream>
#include <cmath>

using namespace std;

double result(double x1, double x2, double x3, double x4) {
    return (0.53 * pow(x1, 5) + 3.4 * pow(x2, 4)) / (12 * pow(x3, 3) - 30 * pow(x4, 4));
}

int main() {
    double x[10][4];
    double y[10];

    for (int i = 0; i < 10; i++) {
        cout << "x1, x2, x3, x4 (" << i + 1 << "): ";
        cin >> x[i][0] >> x[i][1] >> x[i][2] >> x[i][3];
    }


    for (int i = 0; i < 10; i++) {
        y[i] = result(x[i][0], x[i][1], x[i][2], x[i][3]);
    }

    for (int i = 0; i < 10; i++) {
        cout << "y" << i + 1 << " = " << y[i] << endl;
    }

    return 0;
}

//4 -----------------------------------------------
#include <iostream>
#include <cmath>

using namespace std;

double result(double x1, double x2, double x3, double x4) {
    double pi = 180;
    return (tan(x1 - (90 / pi) * x2)) / (tan(x3 - (190 / pi) * x4));
}

int main() {
    double x[10][4];
    double y[10];
    

    for (int i = 0; i < 10; i++) {
        cout << "x1, x2, x3, x4 (" << i + 1 << "): ";
        cin >> x[i][0] >> x[i][1] >> x[i][2] >> x[i][3];
    }


    for (int i = 0; i < 10; i++) {
        y[i] = result(x[i][0], x[i][1], x[i][2], x[i][3]);
    }

    for (int i = 0; i < 10; i++) {
        cout << "y" << i + 1 << " = " << y[i] << endl;
    }

    return 0;
}

//6 -----------------------------------------------
#include <iostream>
#include <cmath>

using namespace std;

double result(double x1, double x2, double x3, double x4) {
    return log(x1 + x2) / log(5) + log(4 + x4) / log(x3);
}

int main() {
    double x[10][4];
    double y[10];

    for (int i = 0; i < 10; i++) {
        cout << "x1, x2, x3, x4 (" << i + 1 << "): ";
        cin >> x[i][0] >> x[i][1] >> x[i][2] >> x[i][3];
    }


    for (int i = 0; i < 10; i++) {
        y[i] = result(x[i][0], x[i][1], x[i][2], x[i][3]);
    }

    for (int i = 0; i < 10; i++) {
        cout << "y" << i + 1 << " = " << y[i] << endl;
    }

    return 0;
}

//8 -----------------------------------------------
#include <iostream>
#include <cmath>

using namespace std;

double result(double x1, double x2, double x3, double x4) {
    return (3.4 * pow(x2, 4)) / (12 * pow(x3, 3) - 30 * pow(x4, 4)) + (0.53 * pow(x1, 5));
}

int main() {
    double x[10][4];
    double y[10];

    for (int i = 0; i < 10; i++) {
        cout << "x1, x2, x3, x4 (" << i + 1 << "): ";
        cin >> x[i][0] >> x[i][1] >> x[i][2] >> x[i][3];
    }


    for (int i = 0; i < 10; i++) {
        y[i] = result(x[i][0], x[i][1], x[i][2], x[i][3]);
    }

    for (int i = 0; i < 10; i++) {
        cout << "y" << i + 1 << " = " << y[i] << endl;
    }

    return 0;
}

//14 ---------------------------------------
#include <iostream>
#include <cmath>

using namespace std;

double result(double x1, double x2, double x3, double x4) {
    return sqrt((0.3 * pow(x1, 5) + 0.4 * pow(x2, 4)) / (12 * pow(x3, 3) - 30 * pow(x4, 4)));
}

int main() {
    double x[10][4];
    double y[10];

    for (int i = 0; i < 10; i++) {
        cout << "x1, x2, x3, x4 (" << i + 1 << "): ";
        cin >> x[i][0] >> x[i][1] >> x[i][2] >> x[i][3];
    }


    for (int i = 0; i < 10; i++) {
        y[i] = result(x[i][0], x[i][1], x[i][2], x[i][3]);
    }

    for (int i = 0; i < 10; i++) {
        cout << "y" << i + 1 << " = " << y[i] << endl;
    }

    return 0;
}

//16 -----------------------------------------------
#include <iostream>
#include <cmath>

using namespace std;

double result(double x1, double x2, double x3, double x4) {
    return (tan(x1 * x2)) / (tan(sqrt(x3 - x4)));
}

int main() {
    double x[10][4];
    double y[10];

    for (int i = 0; i < 10; i++) {
        cout << "x1, x2, x3, x4 (" << i + 1 << "): ";
        cin >> x[i][0] >> x[i][1] >> x[i][2] >> x[i][3];
    }


    for (int i = 0; i < 10; i++) {
        y[i] = result(x[i][0], x[i][1], x[i][2], x[i][3]);
    }

    for (int i = 0; i < 10; i++) {
        cout << "y" << i + 1 << " = " << y[i] << endl;
    }

    return 0;
}

//18 --------------------------------------------------------
#include <iostream>
#include <cmath>

using namespace std;

double result(double x1, double x2, double x3, double x4) {
    return sin(log(x1 + x2) / log(5)) + log(x4) / log(x3);
}

int main() {
    double x[10][4];
    double y[10];

    for (int i = 0; i < 10; i++) {
        cout << "x1, x2, x3, x4 (" << i + 1 << "): ";
        cin >> x[i][0] >> x[i][1] >> x[i][2] >> x[i][3];
    }


    for (int i = 0; i < 10; i++) {
        y[i] = result(x[i][0], x[i][1], x[i][2], x[i][3]);
    }

    for (int i = 0; i < 10; i++) {
        cout << "y" << i + 1 << " = " << y[i] << endl;
    }

    return 0;
}

//lab3 -----------------------------------------------
#include <iostream>
#include <string>
#include <map>
#include <openssl/sha.h>

using namespace std;

// Простая структура для хранения хэша пароля
struct User {
    string passwordHash;
    // Здесь можно добавить дополнительные поля пользователя
};

// Функция для хэширования пароля с использованием SHA-256
string hashPassword(const string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);

    char hashHex[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hashHex + 2 * i, "%02x", hash[i]);
    }

    return hashHex;
}

int main() {
    map<string, User> users; // Карта для хранения пользователей и их данных

    while (true) {
        cout << "Выберите действие:\n";
        cout << "1. Регистрация\n";
        cout << "2. Авторизация\n";
        cout << "3. Выход\n";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string username, password;
            cout << "Введите имя пользователя: ";
            cin >> username;

            // Проверяем, существует ли пользователь с таким именем
            if (users.find(username) != users.end()) {
                cout << "Пользователь с таким именем уже существует.\n";
            } else {
                cout << "Введите пароль: ";
                cin >> password;

                // Хэшируем пароль перед сохранением
                string passwordHash = hashPassword(password);

                User user;
                user.passwordHash = passwordHash;
                users[username] = user;
                cout << "Регистрация успешна!\n";
            }
        } else if (choice == 2) {
            string username, password;
            cout << "Введите имя пользователя: ";
            cin >> username;

            // Проверяем, существует ли пользователь с таким именем
            if (users.find(username) != users.end()) {
                cout << "Введите пароль: ";
                cin >> password;

                // Хэшируем введенный пароль и сравниваем с хранимым хэшем
                string passwordHash = hashPassword(password);

                if (users[username].passwordHash == passwordHash) {
                    cout << "Авторизация успешна. Добро пожаловать, " << username << "!\n";
                } else {
                    cout << "Ошибка авторизации. Неправильный пароль.\n";
                }
            } else {
                cout << "Ошибка авторизации. Пользователь с таким именем не существует.\n";
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Неправильный выбор. Пожалуйста, выберите 1, 2 или 3.\n";
        }
    }

    return 0;
}
