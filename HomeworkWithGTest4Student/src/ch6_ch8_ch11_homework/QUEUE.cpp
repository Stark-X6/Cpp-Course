#include "ch6_ch8_ch11_homework/QUEUE.h"

QUEUE::QUEUE(int m)
    : max(m), size(0)
{
    elems = new int[m];
}

QUEUE::QUEUE(const QUEUE& q)
{
    max = q.max;
    size = q.size;
    elems = new int[max];
    for (int i = 0; i < size; ++i) {
        elems[i] = q.elems[i];
    }
}

QUEUE::QUEUE(QUEUE&& q) noexcept
    : elems(q.elems), max(q.max), size(q.size)
{
    q.elems = nullptr;
    q.max = 0;
    q.size = 0;
}

QUEUE::operator int() const noexcept
{
    return size;
}

int QUEUE::capacity() const noexcept
{
    return max;
}

QUEUE& QUEUE::operator<<(int e)
{
    if (size >= max) {
        throw std::string("QUEUE is full!");
    }
    elems[size++] = e;
    return *this;
}

QUEUE& QUEUE::operator>>(int& e)
{
    if (size <= 0) {
        throw std::string("QUEUE is empty!");
    }
    e = elems[0];
    for (int i = 1; i < size; ++i) {
        elems[i - 1] = elems[i];
    }
    --size;
    return *this;
}

QUEUE& QUEUE::operator=(const QUEUE& q)
{
    if (this != &q) {
        delete[] elems;
        max = q.max;
        size = q.size;
        elems = new int[max];
        for (int i = 0; i < size; ++i) {
            elems[i] = q.elems[i];
        }
    }
    return *this;
}

QUEUE& QUEUE::operator=(QUEUE&& q) noexcept
{
    if (this != &q) {
        delete[] elems;
        elems = q.elems;
        max = q.max;
        size = q.size;
        q.elems = nullptr;
        q.max = 0;
        q.size = 0;
    }
    return *this;
}

std::string QUEUE::toString()
{
    if (size == 0) {
        return "";
    }
    std::string result;
    for (int i = 0; i < size; ++i) {
        result += std::to_string(elems[i]);
        if (i < size - 1) {
            result += " ";
        }
    }
    return result;
}

QUEUE::~QUEUE()
{
    if (elems != nullptr)
    {
        delete[] elems;
        elems = nullptr;
    }
    max = 0;
    size = 0;
}