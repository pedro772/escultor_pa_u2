#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"

/**
 * @brief CutEllipsoid ativa todos os voxels que satisfazem à equação do elipsoide e atribui aos mesmos a cor definida em setColor
 * @param xcenter é a coordenada x do centro do elipsoide
 * @param ycenter é a coordenada y do centro do elipsoide
 * @param zcenter é a coordenada z do centro do elipsoide
 * @param rx é o raio na direção x
 * @param ry é o raio na direção y
 * @param rz é o raio na direção z
 */


class CutEllipsoid : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;

public:
    /**
     * @brief construtor de CutEllipsoid, seta os parâmetros
     * @param _xcenter seta a coordenada x do centro do elipsoide
     * @param _ycenter seta a coordenada y do centro do elipsoide
     * @param _zcenter seta a coordenada z do centro do elipsoide
     * @param _rx seta o raio na direção x
     * @param _ry seta o raio na direção y
     * @param _rz seta o raio na direção z
     */
    CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz);

    /**
     * @brief Função draw de CutEllipsoid, desativa os voxels dentro do elipsoide construído usando a função Sculptor::CutVoxel
     * @param t é o endereço do Sculptor construído
     */

    void draw(Sculptor &t);

    ~CutEllipsoid();
};

#endif // CUTELLIPSOID_H
