#ifndef COORDENADA_H_INCLUDED
#define COORDENADA_H_INCLUDED

using namespace std;

class Coordenada {
private:
    int primera;
    int segunda;
public:
    Coordenada(int _primera, int _segunda);
    Coordenada() = default;
    int obtener_primera();
    int obtener_segunda();
    void cambiar_primera(int nueva);
    void cambiar_segunda(int nueva);
};

#endif // COORDENADA_H_INCLUDED