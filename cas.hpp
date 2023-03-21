#ifndef CAS_CAS_HPP
#define CAS_CAS_HPP

#include <iostream>

using std::ostream;

class cas {
public:
    cas();
    cas(int, int, int);
    cas(const cas &);
    virtual ~cas();

    int getHodiny() const;
    int getMinuty() const;
    int getSekundy() const;

    bool setCas(int, int, int);
    int sekundyOdPulnoci()const;
    int sekundyNaCas(int);

    bool operator==(const cas &) const;
    cas &operator=(const cas &);
    cas &operator+=(const cas &);
    cas operator+(const cas &) const;

private:
    int hodiny, minuty, sekundy;
    bool kontrola(int, int, int) const;
    void systemCas();
};

ostream &operator<<(ostream &, const cas &);

#endif //CAS_CAS_HPP
