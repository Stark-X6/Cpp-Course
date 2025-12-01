#include "ch6_ch8_ch11_homework/DUALQUEUE.h"

DUALQUEUE::DUALQUEUE(int m)
    : QUEUE(m), q(m)
{}

DUALQUEUE::DUALQUEUE(const DUALQUEUE& s)
    : QUEUE(s), q(s.q)
{
}

DUALQUEUE::DUALQUEUE(DUALQUEUE&& s) noexcept
    : QUEUE(static_cast<QUEUE&&>(s))
    , q(static_cast<QUEUE&&>(s.q))
{
}

DUALQUEUE::operator int() const noexcept
{
    return IN_QUEUE_ELEMS + OUT_QUEUE_ELEMS;
}

int DUALQUEUE::capacity() const noexcept
{
    return IN_QUEUE_CAPACITY + OUT_QUEUE_CAPACITY;
}

DUALQUEUE& DUALQUEUE::operator<<(int e)
{
    if (DUALQUEUE_ELEMS >= DUALQUEUE_CAPACITY) {
        throw std::string("DUALQUEUE is full!");
    }
    try {
        QUEUE::operator<<(e);
    } catch (const std::string&) {
        // Move elements from in-queue to out-queue
        int temp;
        while (IN_QUEUE_ELEMS) {
            QUEUE::operator>>(temp);
            q << temp;
        }
        QUEUE::operator<<(e);
    }
    return *this;
}

DUALQUEUE& DUALQUEUE::operator>>(int& e)
{
    if (DUALQUEUE_ELEMS <= 0) {
        throw std::string("DUALQUEUE is empty!");
    }
    try {
        q >> e;
    } catch (const std::string&) {
        // Move elements from in-queue to out-queue
        int temp;
        while (IN_QUEUE_ELEMS) {
            QUEUE::operator>>(temp);
            q << temp;
        }
        q >> e;
    }
    return *this;
}

DUALQUEUE& DUALQUEUE::operator=(const DUALQUEUE& s)
{
    if (this != &s) {
        QUEUE::operator=(s);
        q = s.q;
    }
    return *this;
}

DUALQUEUE& DUALQUEUE::operator=(DUALQUEUE&& s) noexcept
{
    if (this != &s) {
        QUEUE::operator=(static_cast<QUEUE&&>(s));
        q = static_cast<QUEUE&&>(s.q);
    }
    return *this;
}

std::string DUALQUEUE::toString()
{
    std::string result;
    int temp;
    // Extract elements from out-queue
    QUEUE outQueue = q; // Make a copy to preserve original
    while (static_cast<int>(outQueue)) {
        outQueue >> temp;
        result += std::to_string(temp) + " ";
    }
    // Extract elements from in-queue
    QUEUE inQueue = *this; // Make a copy to preserve original
    while (static_cast<int>(inQueue)) {
        inQueue >> temp;
        result += std::to_string(temp) + " ";
    }
    if (!result.empty()) {
        result.pop_back(); // Remove trailing space
    }
    return result;
}

DUALQUEUE::~DUALQUEUE() noexcept
{

}