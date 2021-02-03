#ifndef PRECIPICIO_H_INCLUDED
#define PRECIPICIO_H_INCLUDED

class Precipicio: public Casillero
{
public:
    Precipicio();
    string tipo_casillero();
    int calcular_costo(Personaje* nuevo);
};

#endif // PRECIPICIO_H_INCLUDED
