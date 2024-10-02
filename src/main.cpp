#define MODE 3

#include <iostream>

#include "utils.h"
#include "Core.h"

using Operation = double (*)(double, double);
double calculate(Operation op, double a, double b);

const int  startMode = 4;

int main(int argc, char *argv[]) {
#if MODE == 0
    std::cout <<"DEBUG MODE" << std::endl;
    std::cout << "Hello, World!" << std::endl;
#elif MODE == 1
    double x = 10.0, y = 5.0;
    Operation operation;

    // 选择操作
    int choice;
    std::cout << "Choose an operation:\n"
              << "1. Add\n"
              << "2. Subtract\n"
              << "3. Multiply\n"
              << "4. Divide\n"
              << "Enter your choice (1-4): ";
    std::cin >> choice;


    switch (choice) {
        case 1:
            operation = [](double a, double b) { return a + b; };
            break;
        case 2:
            operation = [](double a, double b) { return a - b; };
            break;
        case 3:
            operation = [](double a, double b) { return a * b; };
            break;
        case 4:
            operation = [](double a, double b) { return a / b; };
            break;
        default:
            std::cerr << "Invalid choice. Defaulting to addition." << std::endl;
            operation = [](double a, double b) { return a + b; };
            break;
    }

    // 执行运算并显示结果
    double result = calculate(operation, x, y);
    std::cout << "The result is: " << result << std::endl;
#else
    Core core=Core(startMode);
    core.start(argc, argv);
#endif
    return 0;
}


// 使用函数指针执行运算
double calculate(Operation op, double a, double b) {
    return op(a, b);
}