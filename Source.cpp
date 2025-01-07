#include "Binary_tree.h"

int main() {
    setlocale(LC_ALL, "Rus");

    Binary_tree gai;

    int number, number_2;

    string offence;

    for (int i = 0; i < 6; i++)
    {
        cout << "\nвведите правонарушение\n";

        getline(cin, offence);

        cout << "\nвведите номер\n";

        cin >> number;

        gai.insert(number, offence);

        cin.ignore();
    }

    //gai.insert(number, offence);

    cout << "\nбаза данных гаи\n";

    gai.print(gai.get_root());

    cout << "\nвведите номер\n";

    cin >> number;

    gai.print(gai.search(gai.get_root(), number), 1);

    cout << "\nвведите начало и конец диапозона номеров, информацию о которых хотите вывести\n";

    cin >> number >> number_2;

    for (size_t i = number; i <= number_2; i++)
    {
        gai.print(gai.search(gai.get_root(), i), 1);
        cout << "\n";
    }

    return 0;
}