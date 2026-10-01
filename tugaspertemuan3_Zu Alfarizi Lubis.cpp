#include <iostream>
#include <string>
using namespace std;

int main() {
    string kata;
    char stack[100];
    int top = -1;

    cout << "Masukkan kata: ";
    cin >> kata;

    for (int i = 0; i < kata.length(); i++) {
        top++;
        stack[top] = kata[i];
    }

    cout << "Kata setelah dibalik: ";

    while (top >= 0) {
        cout << stack[top];
        top--;
    }

    cout << endl;

    return 0;
}