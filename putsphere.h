#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"

/**
 * @brief putSphere ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor definida em setColor
 * @param xcenter é a coordenada x do centro da esfera
 * @param ycenter é a coordenada y do centro da esfera
 * @param zcenter é a coordenada z do centro da esfera
 * @param radius é o raio da esfera
 * @param r armazena a cor vermelha, variando entre 0 e 255.
 * @param g armazena a cor verde, variando entre 0 e 255.
 * @param b armazena a cor azul, variando entre 0 e 255.
 * @param a armazena a transparência do voxel, variando entre 0 e 1.
 */


class PutSphere : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, radius;
    float r, g, b, a;

public:
    /**
     * @brief construtor de PutSphere, seta os parâmetros
     * @param _xcenter é a coordenada x do centro da esfera
     * @param _ycenter é a coordenada y do centro da esfera
     * @param _zcenter é a coordenada z do centro da esfera
     * @param _radius é o raio da esfera
     * @param _r seta a cor vermelha.
     * @param _g seta a cor verde.
     * @param _b seta a cor azul.
     * @param _a seta a transparência do voxel.
     */
    PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a);

    /**
     * @brief Função draw de PutSphere, seta os parâmetros das cores e transparência da caixa e ativa os voxels dentro da esfera construída usando as funções Sculptor::SetColor e Sculptor::PutVoxel
     * @param t é o endereço do Sculptor construído
     */

    void draw(Sculptor &t);

    ~PutSphere();
};

#endif // PUTSPHERE_H
