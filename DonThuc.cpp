
#include "DonThuc.h"

DonThuc::DonThuc(double hs, int b) : heSo(hs), bac(b) {}

void DonThuc::setHeSo(double hs) { heSo = hs; }
void DonThuc::setBac(int b) { bac = b; }
double DonThuc::getHeSo() const { return heSo; }
int DonThuc::getBac() const { return bac; }

DonThuc DonThuc::operator+(const DonThuc& d) const {
    if (bac != d.bac) return *this;
    return DonThuc(heSo + d.heSo, bac);
}

DonThuc DonThuc::operator*(const DonThuc& d) const {
    return DonThuc(heSo * d.heSo, bac + d.bac);
}

bool DonThuc::operator==(const DonThuc& d) const {
    return bac == d.bac && heSo == d.heSo;
}

std::istream& operator>>(std::istream& in, DonThuc& d) {
    std::cout << "Nhập hệ số: ";
    in >> d.heSo;
    std::cout << "Nhập bậc: ";
    in >> d.bac;
    return in;
}

std::ostream& operator<<(std::ostream& out, const DonThuc& d) {
    if (d.heSo == 0) return out;
    if (d.bac == 0) out << d.heSo;
    else if (d.bac == 1) out << d.heSo << "x";
    else out << d.heSo << "x^" << d.bac;
    return out;
}
