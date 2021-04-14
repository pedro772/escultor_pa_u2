#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"

/**
 * @brief PutVoxel ativa o voxel na posição (x,y,z) - fazendo isOn = true - e atribui ao mesmo a cor definida em setColor
 * @param x é a coordenada em relação ao eixo x
 * @param y é a coordenada em relação ao eixo y
 * @param z é a coordenada em relação ao eixo z
 * @param r armazena a cor vermelha, variando entre 0 e 255.
 * @param g armazena a cor verde, variando entre 0 e 255.
 * @param b armazena a cor azul, variando entre 0 e 255.
 * @param a armazena a transparência do voxel, variando entre 0 e 1.
 */


class PutVoxel : public FiguraGeometrica{
    int x, y, z;
    float r, g, b, a;

public:
    /**
     * @brief Construtor de PutVoxel, seta os parâmetros
     * @param _x seta a posição x
     * @param _y seta a posição y
     * @param _z seta a posição z
     * @param _r seta a cor vermelha.
     * @param _g seta a cor verde.
     * @param _b seta a cor azul.
     * @param _a seta a transparência do voxel.
     */
    PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a);

    /**
     * @brief Função draw de PutVoxel, seta os parâmetros das cores e transparência do Voxel e ativa o voxel construído usando as funções Sculptor::SetColor e Sculptor::PutVoxel
     * @param t é o endereço do Sculptor construído
     */

    void draw(Sculptor &t);

    ~PutVoxel();
};

#endif // PUTVOXEL_H
