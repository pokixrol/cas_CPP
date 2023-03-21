#include "cas.hpp"
#include <ctime>
#include <iomanip>


cas::cas() {
    systemCas();
}

cas::cas(int h, int m, int s) {
    if (setCas(h, m, s)) {
    } else {
        systemCas();
    }

}

cas::cas(const cas &orig) {
    setCas(orig.getHodiny(), orig.getMinuty(), orig.getSekundy());
}

cas::~cas() {

}

bool cas::kontrola(int h, int m, int s) const {
    return h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59;
}

void cas::systemCas() {
    time_t t;
    struct tm *pt;
    time(&t);
    pt = localtime(&t);
    this->hodiny = pt->tm_hour;
    this->minuty = pt->tm_min;
    this->sekundy = pt->tm_sec;
    return;
}

int cas::getHodiny() const {
    return this->hodiny;
}

int cas::getMinuty() const {
    return this->minuty;
}

int cas::getSekundy() const {
    return this->sekundy;
}

bool cas::setCas(int h, int m, int s) {
    if (kontrola(h, m, s)) {
        this->hodiny = h;
        this->minuty = m;
        this->sekundy = s;
        return true;
    } else {
        return false;
    }
}

int cas::sekundyOdPulnoci() const {
    int s = 0;
    s += this->hodiny * 3600;
    s += this->minuty * 60;
    s += this->sekundy;
    return s;
}

int cas::sekundyNaCas(int s) {
    int dny;
    dny = s / 86400;
    this->hodiny = (s - dny * 86400) / 3600;
    this->minuty = (s - dny * 86400 - this->hodiny * 3600) / 60;
    this->sekundy = s % 60;
    return dny;
}

bool cas::operator==(const cas &c) const {
    return this->sekundyOdPulnoci() == c.sekundyOdPulnoci();
}

cas &cas::operator=(const cas &c) {
    this->setCas(c.getHodiny(), c.getMinuty(), c.getSekundy());
    return *this;
}

cas &cas::operator+=(const cas &c) {
    int s = this->sekundyOdPulnoci() + c.sekundyOdPulnoci();
    this->sekundyNaCas(s);
    return *this;
}

cas cas::operator+(const cas &c) const {
    cas cas1(*this);
    cas1 += c;
    return cas1;
}

std::ostream &operator<<(ostream &os, const cas &c) {
    os << std::setfill('0');
    os << std::setw(2) << c.getHodiny() << ":" << std::setw(2) << c.getMinuty()
       << ":" << std::setw(2) << c.getSekundy();

    /* os << (c.getHodiny() < 10 ? "0" : "") << c.getHodiny() << ":" << (c.getMinuty() < 10 ? "0" : "") <<
        c.getMinuty() << ":" << (c.getSekundy() < 10 ? "0" : "") << c.getSekundy();*/

    return os;
}
