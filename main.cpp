#include <iostream>
using namespace std;

const int size = 5;

double num1, num2;
char operation;
char back;

struct HistoryEntry {
    double num1;
    double num2;
    char operation;
    double result;
};

HistoryEntry history[size];
int historyCount = 0;

void addToHistory(double num1, double num2, char operation, double result) {
    if (historyCount < size) {
        HistoryEntry entry = {num1, num2, operation, result};
        history[historyCount] = entry;
        historyCount++;
    } else {
        for (int i = 0; i < size - 1; i++) {
            history[i] = history[i + 1];
        }
        HistoryEntry entry = {num1, num2, operation, result};
        history[size - 1] = entry;
    }
}

void displayHistory() {
    cout << "History:" << endl;
    for (int i = 0; i < historyCount; i++) {
        HistoryEntry* entryPtr = &history[i];
        cout << history[i].num1 << " " << history[i].operation << " " << history[i].num2
             << " = " << history[i].result << " (" << entryPtr << ")" << endl;
    }
}

void addition(double num1, double num2) {
    double result = num1 + num2;
    cout << num1 << " + " << num2 << " = " << result << endl;
    addToHistory(num1, num2, '+', result);
}

void subtraction(double num1, double num2) {
    double result = num1 - num2;
    cout << num1 << " - " << num2 << " = " << result << endl;
    addToHistory(num1, num2, '-', result);
}

void multiplication(double num1, double num2) {
    double result = num1 * num2;
    cout << num1 << " * " << num2 << " = " << result << endl;
    addToHistory(num1, num2, '*', result);
}

void division(double num1, double num2) {
    if (num2 == 0) {
        cout << "Undefined." << endl;
        addToHistory(num1, num2, '/', 0);
    } else {
        double result = num1 / num2;
        cout << num1 << " / " << num2 << " = " << result << endl;
        addToHistory(num1, num2, '/', result);
    }
}

int main() {
    do {
        system("cls");
        cout << "Calculator." << endl;
        cout << "The following operators are available: + - * / " << endl;
        cout << "Input your equation: ";
        cin >> num1 >> operation >> num2;

        switch (operation) {
            case '+':
                addition(num1, num2);
                break;
            case '-':
                subtraction(num1, num2);
                break;
            case '*':
                multiplication(num1, num2);
                break;
            case '/':
                division(num1, num2);
                break;
            default:
                cout << "Invalid operator." << endl;
                system("pause");
                main();
        }

        do {
            cout << "Input new equation? [Y/N]: ";
            cin >> back;

            if (back != 'y' && back != 'Y' && back != 'n' && back != 'N') {
                cout << "Invalid input. Try again." << endl;
            }
        } while (back != 'y' && back != 'Y' && back != 'n' && back != 'N');

    } while (back == 'y' || back == 'Y');

    displayHistory();

    cout << endl << endl;

    return 0;
}
