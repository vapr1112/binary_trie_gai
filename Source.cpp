#include "Binary_tree.h"

int main() {
    setlocale(LC_ALL, "Rus");

    Binary_tree gai;

    int number, number_2;

    string offence;

    for (int i = 0; i < 6; i++)
    {
        cout << "\n������� ��������������\n";

        getline(cin, offence);

        cout << "\n������� �����\n";

        cin >> number;

        gai.insert(number, offence);

        cin.ignore();
    }

    //gai.insert(number, offence);

    cout << "\n���� ������ ���\n";

    gai.print(gai.get_root());

    cout << "\n������� �����\n";

    cin >> number;

    gai.print(gai.search(gai.get_root(), number), 1);

    cout << "\n������� ������ � ����� ��������� �������, ���������� � ������� ������ �������\n";

    cin >> number >> number_2;

    for (size_t i = number; i <= number_2; i++)
    {
        gai.print(gai.search(gai.get_root(), i), 1);
        cout << "\n";
    }

    return 0;
}