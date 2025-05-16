#pragma once;
#include <blackjack_variables.h>
#include <fstream>

double read_wallet() {
    ifstream file("wallet.txt");
    double wallet_money;

    cout << "Loading wallet";

    for (int i = 0; i < 3; ++i) {
        cout << ".";
        cout.flush(); // forces output to appear immediately
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << endl;
    if (file.is_open()) {
        file >> wallet_money;
        file.close();
        if (wallet_money <= 0) {
            cout << "Your wallet money was set to 20$ as you had 0 or less.\n";
            wallet_money = 20;
            this_thread::sleep_for(chrono::seconds(2));
        }
        cout << "Wallet money loaded\n";
    }
    else {
        cout << "Unable to load money, setting default value...\n";
        wallet_money = 20;
        this_thread::sleep_for(chrono::seconds(2));
    }
    return wallet_money;
}

void save_wallet(double money) {
    ofstream file("wallet.txt");

    if (file.is_open()) {
        file << money;
        file.close();
        cout << endl;
        cout << "Wallet money saved.\n";
    }
    else {
        cout << "Unable to save money.\n";
        this_thread::sleep_for(chrono::seconds(2));
    }
}