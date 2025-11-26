#include <iostream>
#include <list>
#include <string>
#include <iomanip>
#include <algorithm> // for_each
using namespace std;

struct RGB {
    int r;
    int g;
    int b;
};

class point {
public:
    double x;
    double y;
    RGB color;
    string name;

    point(double x_, double y_, RGB c_, const string &n_)
        : x(x_), y(y_), color(c_), name(n_) {}
};

double luminance(const point &p) {
    return 0.3 * p.color.r + 0.59 * p.color.g + 0.11 * p.color.b;
}

void print_point(const point &p) {
    cout << fixed << setprecision(2);
    cout << "name=" << setw(8) << p.name
              << "  (x,y)=(" << p.x << ", " << p.y << ")"
              << "  RGB=(" << p.color.r << ", "
                           << p.color.g << ", "
                           << p.color.b << ")"
              << "  L=" << luminance(p)
              << '\n';
}

int main() {
    list<point> points = {
        point(  1.0,  2.0, {255,   0,   0}, "P1"),
        point( -2.0,  3.0, {  0, 255,   0}, "Alpha"),
        point( -1.0, -1.0, {  0,   0, 255}, "Beta"),
        point(  3.0, -4.0, {128, 128, 128}, "LongNm"), 
        point(  0.5,  0.5, { 30,  20,  10}, "pnt5"),
        point( -3.0,  1.0, { 60,  60,  60}, "Dark1"),
        point(  2.0, -5.0, { 10,  10,  10}, "Dark2"),
        point(  4.0,  1.0, {200, 200, 200}, "P8"),
        point( -4.0,  2.0, {100,  50,  50}, "P9"),
        point( -2.5, -3.5, { 50, 100, 150}, "P10"),
        point(  1.5, -2.5, { 20,  20,  80}, "P11"),
        point(  0.2,  3.5, {220,  10,  10}, "P12"),
        point(  5.0,  5.0, {255, 100, 100}, "Red"),
        point( -5.0,  5.0, {  0, 255,   0}, "Green"),
        point( -5.0, -5.0, {  0,   0, 255}, "Blue"),
        point(  5.0, -5.0, {250, 250, 250}, "Bright"),
        point( -1.0,  4.0, { 40,  40,  40}, "Dark3"),
        point(  2.0,  0.0, { 90,  90,  90}, "Sky"),
        point(  0.0, -3.0, { 30,  70,  30}, "Stone"),
        point(  1.2,  1.8, { 15,  15,  15}, "Grass"),
        point( -2.2,  2.8, { 70,  70,  90}, "Cloud"),
        point( -1.5, -2.2, {  5,   5,   5}, "Ocean"),
        point(  3.3, -1.1, {240, 240,   0}, "Sun")
    };

    points.remove_if([](const point &p) {
        return p.name.size() > 5;
    });

    cout << "Po usunieciu nazw > 5 znakow:\n";
    for (const auto &p : points) {
        print_point(p);
    }
    cout << "----------------------------------------\n";

    int q1 = 0, q2 = 0, q3 = 0, q4 = 0;

    for_each(points.begin(), points.end(),
                  [&](const point &p) {
        if (p.x > 0 && p.y > 0)      ++q1;
        else if (p.x < 0 && p.y > 0) ++q2;
        else if (p.x < 0 && p.y < 0) ++q3;
        else if (p.x > 0 && p.y < 0) ++q4;
    });

    cout << "Liczba punktow w cwiartkach:\n";
    cout << "I   : " << q1 << '\n';
    cout << "II  : " << q2 << '\n';
    cout << "III : " << q3 << '\n';
    cout << "IV  : " << q4 << '\n';
    cout << "----------------------------------------\n";

    points.sort([](const point &a, const point &b) {
        return luminance(a) < luminance(b);
    });

    cout << "Punkty po posortowaniu wg luminancji:\n";
    for (const auto &p : points) {
        print_point(p);
    }
    cout << "----------------------------------------\n";

    auto is_dark = [](const point &p) {
        return luminance(p) < 64.0;
    };

    list<point> dark_points;

    for (auto it = points.begin(); it != points.end(); ) {
        if (is_dark(*it)) {
            auto current = it;
            ++it;
            dark_points.splice(dark_points.end(), points, current);
        } else {
            ++it;
        }
    }

    cout << "Ciemne punkty (L < 64):\n";
    for (const auto &p : dark_points) {
        print_point(p);
    }
    cout << "Liczba ciemnych punktow: " << dark_points.size() << "\n";
    cout << "----------------------------------------\n";

    cout << "Lista pozostalych punktow (nieciemnych):\n";
    for (const auto &p : points) {
        print_point(p);
    }

    return 0;
}
