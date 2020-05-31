#ifndef ZBIORNIK_HH
#define ZBIORNIK_HH

class Zbiornik
{
protected:
    double m_x_min;
    double m_x_max;
    double m_y_min;
    double m_y_max;
    double m_z_min;
    double m_z_max;

public:
    Zbiornik() = delete;

    Zbiornik(double x_min, double x_max, double y_min, double y_max, double z_min, double z_max)
        : m_x_min(x_min), m_x_max(x_max), m_y_min(y_min), m_y_max(y_max), m_z_min(z_min), m_z_max(z_max) {}

    double PrzekazXMin() const{
        return m_x_min;
    }

    double PrzekazXMax() const{
        return m_x_max;
    }

    double PrzekazYMin() const{
        return m_y_min;
    }

    double PrzekazYMax() const{
        return m_y_max;
    }

    double PrzekazZMin() const{
        return m_z_min;
    }

    double PrzekazZMax() const
    {
        return m_z_max;
    }
};

#endif // ZBIORNIK_HH