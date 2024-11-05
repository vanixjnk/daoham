#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void nhapDaThuc(vector<double>& heSo, vector<int>& soMu) {
    int k;
    cin >> k;
    heSo.resize(k);
    soMu.resize(k);
    for (int i = 0; i < k; i++) cin >> heSo[i];
    for (int i = 0; i < k; i++) cin >> soMu[i];
}
void xuatDaThuc(const vector<double>& heSo, const vector<int>& soMu) {
    bool dauTien = true;
    for (int i = 0; i < heSo.size(); i++) {
        double heso = heSo[i];
        int somu = soMu[i];
        if (heso == 0) continue;
        if (!dauTien) cout << " + ";
        if (heso != 1 || somu == 0) cout << heso;
        if (somu > 0) {
            cout << "x";
            if (somu > 1) cout << "^" << somu;
        }
        dauTien = false;
    }
    cout << endl;
}
double tinhGiaTriDaThuc(const vector<double>& heSo, const vector<int>& soMu, double x) {
    double ketQua = 0.0;
    for (int i = 0; i < heSo.size(); i++) {
        ketQua += heSo[i] * pow(x, soMu[i]);
    }
    return ketQua;
}
void daoHamDaThuc(const vector<double>& heSo, const vector<int>& soMu, vector<double>& heSoDaoHam, vector<int>& soMuDaoHam) {
    heSoDaoHam.clear();
    soMuDaoHam.clear();
    for (int i = 0; i < heSo.size(); i++) {
        if (soMu[i] > 0) {
            heSoDaoHam.push_back(heSo[i] * soMu[i]);
            soMuDaoHam.push_back(soMu[i] - 1);
        }
    }
}
int main() {
    vector<double> heSo;
    vector<int> soMu;
    nhapDaThuc(heSo, soMu);
    double x;
    cin >> x;
    xuatDaThuc(heSo, soMu);
    double ketQua = tinhGiaTriDaThuc(heSo, soMu, x);
    cout << ketQua << endl;
    vector<double> heSoDaoHam;
    vector<int> soMuDaoHam;
    daoHamDaThuc(heSo, soMu, heSoDaoHam, soMuDaoHam);
    xuatDaThuc(heSoDaoHam, soMuDaoHam);
    return 0;
}
