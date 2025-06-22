#include "MainApp.h"
#include <iostream>
#include <vector>
#include "Contract.h"

using namespace std;

void runApp() {
    int n;
    cout << "你想輸入幾筆合約資料？: ";
    cin >> n;

    vector<Contract> contracts;

    for (int i = 0; i < n; i++) {
        string symbol;
        double price, minUnit, leverage, principal;

        cout << "\n第 " << i + 1 << " 筆合約資料：" << endl;

        cout << "請輸入幣種 (例如 BTC): ";
        cin >> symbol;

        cout << "請輸入該幣價格 (USD): ";
        cin >> price;

        cout << "請輸入最小合約單位 (例如 0.001): ";
        cin >> minUnit;

        cout << "請輸入槓桿倍數: ";
        cin >> leverage;

        cout << "請輸入本金 (USDT): ";
        cin >> principal;

        contracts.push_back(Contract(symbol, price, minUnit, leverage, principal));
    }

    cout << "\n==== 合約結果 ====" << endl;
    for (auto& c : contracts) {
        c.showResult();
    }
}
