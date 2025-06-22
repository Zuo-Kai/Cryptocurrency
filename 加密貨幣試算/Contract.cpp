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
    cout << "����: " << symbol << endl;
    cout << "����: " << price << " USD" << endl;
    cout << "�̤p�X�����: " << minUnit << endl;
    cout << "����: " << principal << " USDT" << endl;
    cout << "�b��: " << leverage << " ��" << endl;

    cout << "�̤p�ܦ����: " << getMinPositionValue() << " USDT" << endl;
    cout << "�̤j�i�}�ܦ����: " << getMaxPositionValue() << " USDT" << endl;

    if (canOpenPosition()) {
        cout << "�i�H�}�ܡI" << endl;
    }
    else {
        cout << "�����κb�줣���A�L�k�}�ܡI" << endl;
        double need = getMinPositionValue() / leverage - principal;
        cout << "�ٻݭn�B�~ " << need << " USDT �����~��}�ܡC" << endl;
    }

    cout << "--------------------" << endl;
}
