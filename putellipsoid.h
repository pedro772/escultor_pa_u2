#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"

/**
 * @brief PutEllipsoid ativa todos os voxels que satisfazem a equação do elipsoide e atribui aos mesmos a cor definida em setColor
 * @param xcenter é a coordenada x do centro do elipsoide
 * @param ycenter é a coordenada y do centro do elipsoide
 * @param zcenter é a coordenada z do centro do elipsoide
 * @param rx é o raio na direção x
 * @param ry é o raio na direção y
 * @param rz é o raio na direção z
 * @param r armazena a cor vermelha, variando entre 0 e 255.
 * @param g armazena a cor verde, variando entre 0 e 255.
 * @param b armazena a cor azul, variando entre 0 e 255.
 * @param a armazena a transparência do voxel, variando entre 0 e 1.
 */


class PutEllipsoid : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;
    float r, g, b, a;

public:
    /**
     * @brief construtor de PutEllipsoid, seta os parâmetros
     * @param _xcenter seta a coordenada x do centro do elipsoide
     * @param _ycenter seta a coordenada y do centro do elipsoide
     * @param _zcenter seta a coordenada z do centro do elipsoide
     * @param _rx seta o raio na direção x
     * @param _ry seta o raio na direção y
     * @param _rz seta o raio na direção z
     * @param _r seta a cor vermelha.
     * @param _g seta a cor verde.
     * @param _b seta a cor azul.
     * @param _a seta a transparência do voxel.
     */
    PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a);

    /**
     * @brief Função draw de PutEllipsoid, seta os parâmetros das cores e transparência do elipsoide e ativa os voxels dentro do elipsoide construído usando as funções Sculptor::SetColor e Sculptor::PutVoxel
     * @param t é o endereço do Sculptor construído
     */

    void draw(Sculptor &t);

    ~PutEllipsoid();
};

#endif // PUTELLIPSOID_H
