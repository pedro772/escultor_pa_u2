#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"

/**
 * @brief CutSphere desativa todos os voxels que satisfazem à equação da esfera.
 * @param xcenter é a coordenada x do centro da esfera
 * @param ycenter é a coordenada y do centro da esfera
 * @param zcenter é a coordenada z do centro da esfera
 * @param radius é o raio da esfera
 */


class CutSphere : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, radius;
    float r, g, b, a;

public:
    /**
     * @brief construtor de CutSphere, seta os parâmetros.
     * @param _xcenter seta a coordenada x do centro da esfera
     * @param _ycenter seta a coordenada y do centro da esfera
     * @param _zcenter seta a coordenada z do centro da esfera
     * @param _radius é o raio da esfera
     */
    CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius);

    /**
     * @brief Função draw de CutSphere, desativa os voxels dentro da esfera construída usando a função Sculptor::CutVoxel
     * @param t é o endereço do Sculptor construído
     */

    void draw(Sculptor &t);

    ~CutSphere();
};

#endif // CUTSPHERE_H
