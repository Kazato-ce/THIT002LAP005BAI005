
#ifndef DONTHUC_H
#define DONTHUC_H

#include <iostream>

class DonThuc {
private:
    double heSo;
    int bac;

public:
    DonThuc(double hs = 0, int b = 0);

    void setHeSo(double hs);
    void setBac(int b);
    double getHeSo() const;
    int getBac() const;

    DonThuc operator+(const DonThuc& d) const;
    DonThuc operator*(const DonThuc& d) const;
    bool operator==(const DonThuc& d) const;

    friend std::istream& operator>>(std::istream& in, DonThuc& d);
    friend std::ostream& operator<<(std::ostream& out, const DonThuc& d);
};

#endif
