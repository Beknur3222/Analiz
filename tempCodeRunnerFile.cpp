#include <iostream>
#include <string>
#include <map>

using namespace std;

// Простая структура для хранения информации о пользователе
struct User {
    string password;
    // Здесь можно добавить дополнительные поля пользователя
};

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
                User user;
                user.password = password;
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

                // Проверяем правильность пароля
                if (users[username].password == password) {
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