#include "MainApp.h"
#include <iostream>
#include <vector>
#include "Contract.h"

using namespace std;

void runApp() {
    int n;
    cout << "�A�Q��J�X���X����ơH: ";
    cin >> n;

    vector<Contract> contracts;

    for (int i = 0; i < n; i++) {
        string symbol;
        double price, minUnit, leverage, principal;

        cout << "\n�� " << i + 1 << " ���X����ơG" << endl;

        cout << "�п�J���� (�Ҧp BTC): ";
        cin >> symbol;

        cout << "�п�J�ӹ����� (USD): ";
        cin >> price;

        cout << "�п�J�̤p�X����� (�Ҧp 0.001): ";
        cin >> minUnit;

        cout << "�п�J�b�쭿��: ";
        cin >> leverage;

        cout << "�п�J���� (USDT): ";
        cin >> principal;

        contracts.push_back(Contract(symbol, price, minUnit, leverage, principal));
    }

    cout << "\n==== �X�����G ====" << endl;
    for (auto& c : contracts) {
        c.showResult();
    }
}
