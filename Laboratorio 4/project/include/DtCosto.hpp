#ifndef DTCOSTO_HPP
#define DTCOSTO_HPP

class DtCosto {
   private:
    double mensual;
    double trimestral;
    double anual;
    double vitalicio;

   public:
    DtCosto(double mensual, double trimestral, double anual, double vitalicio);
    DtCosto() = default;

    ~DtCosto() = default;
    double getMensual();
    double getTrimestral();
    double getAnual();
    double getVitalicio();
};

#endif