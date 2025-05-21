
#include "DaThuc.h"
#include <iostream>
#include <cmath>

DaThuc::DaThuc() {}

void DaThuc::rutGon() {
    std::vector<DonThuc> kq;

    for (const auto& d : ds) {
        bool timThay = false;
        for (auto& k : kq) {
            if (k.getBac() == d.getBac()) {
                k.setHeSo(k.getHeSo() + d.getHeSo());
                timThay = true;
                break;
            }
        }
        if (!timThay)
            kq.push_back(d);
    }

    ds = kq;
}

std::istream& operator>>(std::istream& in, DaThuc& dt) {
    int n;
    std::cout << "Nhập số đơn thức: ";
    in >> n;
    dt.ds.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Đơn thức " << i + 1 << ":
";
        in >> dt.ds[i];
    }
    dt.rutGon();
    return in;
}

std::ostream& operator<<(std::ostream& out, const DaThuc& dt) {
    bool first = true;
    for (const auto& d : dt.ds) {
        if (d.getHeSo() == 0) continue;
        if (!first && d.getHeSo() > 0) out << " + ";
        if (!first && d.getHeSo() < 0) out << " - ";
        if (first && d.getHeSo() < 0) out << "-";

        if (!first)
            out << std::abs(d.getHeSo());
        else
            out << d;

        if (d.getBac() > 0)
            out << (first ? "" : "") << "x" << (d.getBac() > 1 ? "^" + std::to_string(d.getBac()) : "");

        first = false;
    }

    if (first) out << "0";
    return out;
}

DaThuc DaThuc::operator+(const DaThuc& other) const {
    DaThuc kq = *this;
    kq.ds.insert(kq.ds.end(), other.ds.begin(), other.ds.end());
    kq.rutGon();
    return kq;
}

DaThuc DaThuc::operator-(const DaThuc& other) const {
    DaThuc kq = *this;
    for (const auto& d : other.ds) {
        kq.ds.push_back(DonThuc(-d.getHeSo(), d.getBac()));
    }
    kq.rutGon();
    return kq;
}

DaThuc DaThuc::operator*(const DaThuc& other) const {
    DaThuc kq;
    for (const auto& a : ds)
        for (const auto& b : other.ds)
            kq.ds.push_back(a * b);
    kq.rutGon();
    return kq;
}

double DaThuc::tinhGiaTri(double x) const {
    double tong = 0;
    for (const auto& d : ds) {
        tong += d.getHeSo() * std::pow(x, d.getBac());
    }
    return tong;
}
