#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"

/**
 * @brief CutVoxel desativa o voxel na posição (x,y,z), fazendo isOn = false
 * @param x é a coordenada em relação ao eixo x
 * @param y é a coordenada em relação ao eixo y
 * @param z é a coordenada em relação ao eixo z
 */


class CutVoxel : public FiguraGeometrica{
    int x, y, z;

public:
    /**
     * @brief Construtor de CutVoxel, seta os parâmetros
     * @param _x seta a posição x
     * @param _y seta a posição y
     * @param _z seta a posição z
     */
    CutVoxel(int _x, int _y, int _z);

    /**
     * @brief Função draw de CutVoxel, desativa os voxels construídos usando a função Sculptor::CutVoxel
     * @param t é o endereço do Sculptor construído
     */

    void draw(Sculptor &t);

    ~CutVoxel();
};
#endif // CUTVOXEL_H
