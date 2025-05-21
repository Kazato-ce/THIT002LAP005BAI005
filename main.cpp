
#include <iostream>
#include "DaThuc.h"

int main() {
    DaThuc A, B;

    std::cout << "=== Nhập đa thức A ===\n";
    std::cin >> A;

    std::cout << "=== Nhập đa thức B ===\n";
    std::cin >> B;

    std::cout << "\nĐa thức A: " << A << "\n";
    std::cout << "Đa thức B: " << B << "\n";

    DaThuc tong = A + B;
    DaThuc hieu = A - B;
    DaThuc tich = A * B;

    std::cout << "\nTổng A + B: " << tong << "\n";
    std::cout << "Hiệu A - B: " << hieu << "\n";
    std::cout << "Tích A * B: " << tich << "\n";

    double x;
    std::cout << "\nNhập x để tính A(x): ";
    std::cin >> x;
    std::cout << "A(" << x << ") = " << A.tinhGiaTri(x) << "\n";

    return 0;
}
