#include <string>

#ifndef DTEST_HPP
#define DTEST_HPP

class DtEstadistica {
   private:
    std::string name;
    double dato;

   public:
    DtEstadistica(std::string, double);
    ~DtEstadistica() = default;
    std::string getName();
    double getDato();
    bool operator<(const DtEstadistica&) const;
};

#endif