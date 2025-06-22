#pragma once
#include "Contract.h"
#include <iostream>

using namespace std;

Contract::Contract(string s, double p, double mu, double lev, double prin) {
    symbol = s;
    price = p;
    minUnit = mu;
    leverage = lev;
    principal = prin;
}

double Contract::getMinPositionValue() {
    return price * minUnit;
}

double Contract::getMaxPositionValue() {
    return principal * leverage;
}

bool Contract::canOpenPosition() {
    return getMaxPositionValue() >= getMinPositionValue();
}

void Contract::showResult() {
    cout << "幣種: " << symbol << endl;
    cout << "幣價: " << price << " USD" << endl;
    cout << "最小合約單位: " << minUnit << endl;
    cout << "本金: " << principal << " USDT" << endl;
    cout << "槓桿: " << leverage << " 倍" << endl;

    cout << "最小倉位價值: " << getMinPositionValue() << " USDT" << endl;
    cout << "最大可開倉位價值: " << getMaxPositionValue() << " USDT" << endl;

    if (canOpenPosition()) {
        cout << "可以開倉！" << endl;
    }
    else {
        cout << "本金或槓桿不足，無法開倉！" << endl;
        double need = getMinPositionValue() / leverage - principal;
        cout << "還需要額外 " << need << " USDT 本金才能開倉。" << endl;
    }

    cout << "--------------------" << endl;
}
