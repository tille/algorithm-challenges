#include <bits/stdc++.h>

using namespace std;

int r, xi, yi, xf, yf;
double x3, y3, ratioC, dist;

void solve() {
    ratioC = (dist + r) / 2.0;

    double cs = abs(xf - xi) / dist;
    double sn = abs(yf - yi) / dist;

    double deltaX = cs * ratioC;
    double deltaY = sn * ratioC;

    if (xf > xi) {
        x3 = xf - deltaX;
    } else if (xf < xi) {
        x3 = xf + deltaX;
    } else {
        x3 = xf;
    }

    if (yf > yi) {
        y3 = yf - deltaY;
    } else if (yf < yi) {
        y3 = yf + deltaY;
    } else {
        y3 = yf;
    }
}

void print(double x, double y, double r) {
    printf("%.15f %.15f %.15f\n", x, y, r);
}

int main() {
    cin >> r >> xi >> yi >> xf >> yf;
    double p1 = xf - xi;
    double p2 = yf - yi;
    dist = sqrt(p1*p1+p2*p2);

    if (dist > r) {
        print(xi, yi, r);
    } else if (xi == xf && yi == yf) {
        x3 = xi + (r / 2.0);
        print(x3, yi, r / 2.0);
    } else {
        solve();
        print(x3, y3, ratioC);
    }

    return 0;
}