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
//        cout << "������� �����: ";
//        cin >> login;
//        if (cin.peek() != '\n')//peek - ������ �������� � �������� � ������
//        {
//            cin.clear();
//            while (cin.get() != '\n');
//        }
//        cout << "������� ������: ";
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
//            if (isgraph(ch))// ���������� ��������� ��������, ���� �� �������� ch �������� ����� ���������� ��������, �� �� ��������
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
//            cout << "������������ ����� ��� ������!" << endl;
//            password.clear();
//            login.clear();
//            count++;
//        }
//
//        if (count == 3)
//        {
//            cout << "������� ����� �������! ��������� � ����������" << endl << endl;
//            exit(1);
//        }
//
//    } while (1);
//}