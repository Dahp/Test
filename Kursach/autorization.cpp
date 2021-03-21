//#include "autorization.h"
//
//
//void autorization::Autorization()
//{
//    string login, password, rlogin, rpassword;
//
//        Binf ID("ID.bin");
//        ID.read(rlogin);
//        ID.read(rpassword);
//
//    char ch;
//    int count = 0;
//
//    do
//    {
//        cout << "Введите логин: ";
//        cin >> login;
//        if (cin.peek() != '\n')//peek - читает фрагмент и помещает в массив
//        {
//            cin.clear();
//            while (cin.get() != '\n');
//        }
//        cout << "Введите пароль: ";
//
//        do
//        {
//            ch = _getch();
//
//            if (ch == 13) break;
//            if (ch == '\b' && !password.empty())
//            {
//                cout << '\b';
//                cout << ' ';
//                cout << '\b';
//
//                password.pop_back();
//                continue;
//            }
//            if (isgraph(ch))// возвращает ненулевое значение, если ее аргумент ch является любым печатаемым символом, но не пробелом
//            {
//                cout << '*';
//                password.push_back(ch);
//            }
//        } while (1);
//
//        if (login == rlogin && password == rpassword)
//        {
//            break;
//        }
//        else
//        {
//            system("CLS");
//            cout << "Неправильный логин или пароль!" << endl;
//            password.clear();
//            login.clear();
//            count++;
//        }
//
//        if (count == 3)
//        {
//            cout << "Слишком много попыток! Перезайди в приложение" << endl << endl;
//            exit(1);
//        }
//
//    } while (1);
//}