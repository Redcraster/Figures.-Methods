#include <iostream>
#include <string>

// Базовый класс для всех фигур
class Figure {
protected:
    std::string name;
    int sides_count;

public:
    Figure(const std::string& name, int sides_count)
        : name(name), sides_count(sides_count) {}

    virtual void print_info() const {
        std::cout << name << ":\n";
        std::cout << "Количество сторон: " << sides_count << "\n";
    }

    virtual bool check() const {
        return sides_count == 0;  // Фигура по умолчанию всегда правильная
    }

    virtual ~Figure() = default; // Виртуальный деструктор
};

// Класс для треугольников
class Triangle : public Figure {
protected:
    int a, b, c; // Стороны
    int A, B, C; // Углы

public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : Figure("Треугольник", 3), a(a), b(b), c(c), A(A), B(B), C(C) {}

    void print_info() const override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
    }

    bool check() const override {
        if (Figure::check()) return false;
        return (A + B + C == 180);  // Проверка суммы углов
    }
};

// Класс для прямоугольного треугольника
class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    }

    bool check() const override {
        return Triangle::check() && (C == 90);
    }
};

// Класс для равнобедренного треугольника
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A) {
        name = "Равнобедренный треугольник";
    }

    bool check() const override {
        return Triangle::check() && (a == c) && (A == C);
    }
};

// Класс для равностороннего треугольника
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a)
        : Triangle(a, a, a, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }

    bool check() const override {
        return Triangle::check() && (a == b && b == c) && (A == 60 && B == 60 && C == 60);
    }
};

// Класс для четырёхугольников
class Quadrangle : public Figure {
protected:
    int a, b, c, d; // Стороны
    int A, B, C, D; // Углы

public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
        : Figure("Четырёхугольник", 4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    void print_info() const override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }

    bool check() const override {
        if (Figure::check()) return false;
        return (A + B + C + D == 360);  // Проверка суммы углов
    }
};

// Класс для прямоугольника
class Rectangle : public Quadrangle {
public:
    Rectangle(int a, int b)
        : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }

    bool check() const override {
        return Quadrangle::check() && (a == c) && (b == d) && (A == 90 && B == 90 && C == 90 && D == 90);
    }
};

// Класс для квадрата
class Square : public Quadrangle {
public:
    Square(int a)
        : Quadrangle(a, a, a, a, 90, 90, 90, 90) {
        name = "Квадрат";
    }

    bool check() const override {
        return Quadrangle::check() && (a == b && b == c && c == d) && (A == 90 && B == 90 && C == 90 && D == 90);
    }
};

// Класс для параллелограмма
class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrangle(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    }

    bool check() const override {
        return Quadrangle::check() && (a == c && b == d) && (A == C && B == D);
    }
};

// Класс для ромба
class Rhombus : public Quadrangle {
public:
    Rhombus(int a, int A, int B)
        : Quadrangle(a, a, a, a, A, B, A, B) {
        name = "Ромб";
    }

    bool check() const override {
        return Quadrangle::check() && (a == b && b == c && c == d) && (A == C && B == D);
    }
};

// Функция для вывода информации о фигуре
void print_info(const Figure* figure) {
    figure->print_info();
    std::cout << (figure->check() ? "Правильная" : "Неправильная") << "\n" << std::endl;
}

int main() {
    Figure figure("Фигура", 0);
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(10, 20, 30, 50, 90);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);
    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    print_info(&figure);
    print_info(&triangle);
    print_info(&right_triangle);
    print_info(&isosceles_triangle);
    print_info(&equilateral_triangle);
    print_info(&quadrangle);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);

    return 0;
}