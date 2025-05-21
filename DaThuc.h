
#ifndef DATHUC_H
#define DATHUC_H

#include <vector>
#include "DonThuc.h"

class DaThuc {
private:
    std::vector<DonThuc> ds;
    void rutGon();

public:
    DaThuc();

    friend std::istream& operator>>(std::istream& in, DaThuc& dt);
    friend std::ostream& operator<<(std::ostream& out, const DaThuc& dt);

    DaThuc operator+(const DaThuc& other) const;
    DaThuc operator-(const DaThuc& other) const;
    DaThuc operator*(const DaThuc& other) const;

    double tinhGiaTri(double x) const;
};

#endif
