#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"

/**
 * @brief CutBox desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1]
 * @param x0 é a coordenada do ponto inicial no eixo x
 * @param x1 é a coordenada do ponto final no eixo x
 * @param y0 é a coordenada do ponto inicial no eixo y
 * @param y1 é a coordenada do ponto final no eixo y
 * @param z0 é a coordenada do ponto inicial no eixo z
 * @param z1 é a coordenada do ponto final no eixo z
 */


class CutBox : public FiguraGeometrica{
    int x0, x1;
    int y0, y1;
    int z0, z1;

public:
    /**
     * @brief Construtor de CutBox, seta os parâmetros
     * @param _x0 seta a posição x0
     * @param _x1 seta a posição x1
     * @param _y0 seta a posição y0
     * @param _y1 seta a posição y1
     * @param _z0 seta a posição z0
     * @param _z1 seta a posição z1
     */
    CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1);

    /**
     * @brief Função draw de CutBox, desativa os voxels dentro da caixa construída usando a função Sculptor::CutVoxel
     * @param t é o endereço do Sculptor construído
     */

    void draw(Sculptor &t);

    ~CutBox();
};

#endif // CUTBOX_H
