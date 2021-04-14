#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"

/**
 * @brief PutBox ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor definida em setColor
 * @param x0 é a coordenada do ponto inicial no eixo x
 * @param x1 é a coordenada do ponto final no eixo x
 * @param y0 é a coordenada do ponto inicial no eixo y
 * @param y1 é a coordenada do ponto final no eixo y
 * @param z0 é a coordenada do ponto inicial no eixo z
 * @param z1 é a coordenada do ponto final no eixo z
 * @param r armazena a cor vermelha, variando entre 0 e 255.
 * @param g armazena a cor verde, variando entre 0 e 255.
 * @param b armazena a cor azul, variando entre 0 e 255.
 * @param a armazena a transparência do voxel, variando entre 0 e 1.
 */


class PutBox : public FiguraGeometrica{
    int x0, x1;
    int y0, y1;
    int z0, z1;
    float r, g, b, a;

public:
    /**
     * @brief Construtor de PutBox, seta os parâmetros
     * @param _x0 seta a posição x0
     * @param _x1 seta a posição x1
     * @param _y0 seta a posição y0
     * @param _y1 seta a posição y1
     * @param _z0 seta a posição z0
     * @param _z1 seta a posição z1
     * @param _r seta a cor vermelha.
     * @param _g seta a cor verde.
     * @param _b seta a cor azul.
     * @param _a seta a transparência do voxel.
     */
    PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a);

    /**
     * @brief Função draw de PutBox, seta os parâmetros das cores e transparência da caixa e ativa os voxels dentro da caixa construída usando as funções Sculptor::SetColor e Sculptor::PutVoxel
     * @param t é o endereço do Sculptor construído
     */

    void draw(Sculptor &t);

    ~PutBox();
};

#endif // PUTBOX_H
