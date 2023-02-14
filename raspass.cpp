#include <iostream>
#include <string>
#include <random>

using namespace std;

int main() {
    bool done = false;
    const string charset = "0123456789abcdefghijklmnopqrstuvwxyz!@#$%^&*()ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int max_index = charset.size() - 1;
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution<int> dist(0, max_index);
    string password;
    int length;
    char response;
    while (!done) {
        cout << "How many characters do you want in your password? "; cin >> length;
        password = "";
        for (int i = 0; i < length; i++) {
            password += charset[dist(rng)];
        }
        cout << password << endl;
        cout << "Is this password good? (y/n) ";
        cin >> response;
        if (response == 'y') {
            done = true;
        }
    }
}