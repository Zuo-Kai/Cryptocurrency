#pragma once
#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>

class Contract {
private:
    std::string symbol;
    double price;
    double minUnit;
    double leverage;
    double principal;

public:
    Contract(std::string s, double p, double mu, double lev, double prin);

    double getMinPositionValue();
    double getMaxPositionValue();
    bool canOpenPosition();
    void showResult();
};

#endif
