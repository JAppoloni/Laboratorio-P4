#include "../include/DtFechaHora.hpp"

DtFechaHora::DtFechaHora(int D, int M, int A, int H, int Min) {
    if ((D > 31) || (D < 1) || (M > 12) || (M < 1) || (A < 1900)) {
        throw std::invalid_argument("Fecha invalida.");
    }
    dia = D;
    mes = M;
    anio = A;
    hora = H;
    minuto = Min;
}

int DtFechaHora::getDia() {
    return dia;
}

int DtFechaHora::getMes() {
    return mes;
}

int DtFechaHora::getAnio() {
    return anio;
}

int DtFechaHora::getHora() {
    return hora;
}

int DtFechaHora::getMinuto() {
    return minuto;
}

bool DtFechaHora::operator==(const DtFechaHora& F) {
    return ((F.dia == dia) && (F.mes == mes) && (F.anio == anio) &&
            (F.hora == hora) && (F.minuto == minuto));
}

bool DtFechaHora::operator<(const DtFechaHora& F) {
    return (this->anio < F.anio) ||
           ((this->anio == F.anio) && (this->mes < F.mes)) ||
           ((this->anio == F.anio) && (this->mes == F.mes) &&
            (this->dia < F.dia)) ||
           ((this->anio == F.anio) && (this->mes == F.mes) &&
            (this->dia == F.dia) && (this->hora < F.hora)) ||
           ((this->anio == F.anio) && (this->mes == F.mes) &&
            (this->dia == F.dia) && (this->hora == F.hora) &&
            (this->minuto < F.minuto));
}

DtFechaHora DtFechaHora::operator+(const TiposSuscripcion tipo) {
    int a = this->anio;
    int m = this->mes;
    int d = this->dia;
    int hh = this->hora;
    int mm = this->minuto;

    switch (tipo) {
        case un_mes:
            if (m == 12) {
                m = 1;
                a++;
            } else {
                m++;
            }
            break;
        case tres_meses:
            if (m >= 10) {
                m = m + 3 - 12;
                a++;
            } else {
                m = m + 3;
            }
            break;
        case un_anio:
            a++;
            break;
        case vitalicio:
            break;
    }

    return DtFechaHora(d, m, a, hh, mm);
}

float DtFechaHora::operator-(const DtFechaHora& f) {
    // calcula la diferencia (en minutos) entre dos fechas
    // precondicion: fecha1 > fecha2
    int a1 = this->anio;
    int m1 = this->mes;
    int d1 = this->dia;
    int hh1 = this->hora;
    int mm1 = this->minuto;

    int a2 = f.anio;
    int m2 = f.mes;
    int d2 = f.dia;
    int hh2 = f.hora;
    int mm2 = f.minuto;

    float res = 0;
    if (mm1 < mm2) {
        if (hh1 > 0) {
            hh1--;
            mm1 += 60;
        } else {
            if (d1 > 0) {
                d1--;
                hh1 = 23;
                mm1 += 60;
            } else {
                if (m1 > 0) {
                    m1--;
                    d1 = 30;
                    hh1 = 23;
                    mm1 += 60;
                } else {
                    a1--;
                    m1 = 11;
                    d1 = 30;
                    hh1 = 23;
                    mm1 += 60;
                }
            }
        }
    }
    res += mm1 - mm2;

    if (hh1 < hh2) {
        if (d1 > 0) {
            d1--;
            hh1 += 24;
        } else {
            if (m1 > 0) {
                m1--;
                d1 = 30;
                hh1 += 24;
            } else {
                a1--;
                m1 = 11;
                d1 = 30;
                hh1 += 24;
            }
        }
    }
    res += (hh1 - hh2) * 60;

    if (d1 < d2) {
        if (m1 > 0) {
            m1--;
            d1 += 31;
        } else {
            a1--;
            m1 = 11;
            d1 += 31;
        }
    }
    res += (d1 - d2) * 24 * 60;

    if (m1 < m2) {
        a1--;
        m1 += 12;
    }
    res += (m1 - m2) * 31 * 24 * 60;
    res += (a1 - a2) * 365 * 31 * 24 * 60;
    return res / 60;
}

std::ostream& operator<<(std::ostream& os, DtFechaHora& fecha) {
    // Para printear "07" en lugar de 7.
    std::string hr = ((fecha.getHora() < 10) ? "0" : "") +
                     std::to_string(fecha.getHora()) + ':' +
                     ((fecha.getMinuto() < 10) ? "0" : "") +
                     std::to_string(fecha.getMinuto());

    os << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio()
       << " " + hr;

    return os;
}