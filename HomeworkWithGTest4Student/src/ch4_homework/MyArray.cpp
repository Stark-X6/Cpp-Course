#include "ch4_homework/MyArray.h"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

MyArray::MyArray(int size) : size(size), p(new int[size]()) {} //默认参数只能在函数声明或定义中出现一次，一般放在声明中（头文件）
MyArray::MyArray(const MyArray &old) : size(old.size), p(new int[old.size]) {
    std::copy(old.p, old.p + old.size, p);
}
MyArray & MyArray::operator=(const MyArray &rhs) {
    if (this != &rhs) {
        if (this->p) delete[] p;
        *(const_cast<int**>(&p)) = new int[rhs.size];
        size = rhs.size;
        std::copy(rhs.p, rhs.p + rhs.size, p);
    }
    return *this;
}
MyArray::MyArray(MyArray &&old) noexcept : size(old.size), p(old.p) {
    *(const_cast<int**>(&old.p)) = nullptr;
    old.size = 0;
}
MyArray & MyArray::operator=(MyArray &&rhs) noexcept {
    if (this != &rhs) {
        if (this->p) delete[] p;
        *(const_cast<int**>(&p)) = rhs.p;
        size = rhs.size;
        *(const_cast<int**>(&rhs.p)) = nullptr;
        rhs.size = 0;
    }
    return *this;
}
MyArray::~MyArray() {
    if (p) {
        delete[] p;
        *(const_cast<int**>(&p)) = nullptr;
        size = 0;
    }
}
int MyArray::length() {
    return size;
}
int &MyArray::get(int index) {
    return p[index];
}

bool MyArray::isEmpty() const {
    return size == 0 || p == nullptr;
}
bool MyArray::equals(const MyArray &other) const {
    if (this->isEmpty() || other.isEmpty()) return false;
    if (this->size != other.size) return false;
    for (int i = 0; i < size; ++i) {
        if (this->p[i] != other.p[i]) return false;
    }
    return true;
}
std::string MyArray::toString() {
    if (this->isEmpty()) return "";
    std::ostringstream oss;
    for (int i = 0; i < size; ++i) {
        oss << p[i];
        if (i != size - 1) oss << " ";
    }
    return oss.str();
}
const int* const MyArray::getP() {
    return p;
}