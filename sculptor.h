#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <iostream>
#include <string>

/**
 * @brief Struct Voxel:
     * Voxels são equivalente aos já conhecidos pixels, porém em 3 dimensões.
     * Os Voxels armazenam informações como cor e transparência, que são necessárias para construir a escultura.
     * @param r armazena a cor vermelha, variando entre 0 e 255.
     * @param g armazena a cor verde, variando entre 0 e 255.
     * @param b armazena a cor azul, variando entre 0 e 255.
     * @param a armazena a transparência do voxel, variando entre 0 e 1.
     * @param isOn define se o Voxel está ativo ou não, assume valores booleanos (0 para desativado e 1 para ativado).
 */

struct Voxel{
    float r;
    float g;
    float b;
    float a;
    bool isOn;
};

/**
 * @brief Classe Sculptor
 * Monta uma estrutura e fornece os métodos para manipulação dos Voxels.
 */

class Sculptor{
protected:
    /**
     * @brief v é uma matriz 3D alocada dinamicamente responsável pelo armazenamento dos Voxels.
     */
    Voxel ***v;

    /**
    * @brief nx armazena a dimensão em x.
    */
    int nx;

    /**
    * @brief ny armazena a dimensão em y.
    */
    int ny;

    /**
    * @brief nz armazena a dimensão em z.
    */
    int nz;

    /**
     * @brief r armazena a intensidade atual da cor vermelha, varia entre [0 - 255]
    */
    float r;

    /**
     * @brief g armazena a intensidade atual da cor verde, varia entre [0 - 255]
    */
    float g;

    /**
     * @brief b armazena a intensidade atual da cor azul, varia entre [0 - 255]
    */
    float b;

    /**
     * @brief r armazena a intensidade atual da transparência, varia entre [0 - 1]
    */
    float a;

public:
    /**
     * @brief Sculptor: Construtor da classe Sculptor
     * @param _nx: Dimensão x da escultura 3D
     * @param _ny: Dimensão y da escultura 3D
     * @param _nz: Dimensão z da escultura 3D
     */
    Sculptor(int _nx, int _ny, int _nz);

    /**
      * @brief ~Sculptor: Destrutor da classe Sculptor
    */
    ~Sculptor();

    /**
     * @brief setColor define a cor atual do desenho.
     * @param r armazena a cor vermelha, variando entre 0 e 255.
     * @param g armazena a cor verde, variando entre 0 e 255.
     * @param b armazena a cor azul, variando entre 0 e 255.
     * @param a armazena a transparência do voxel, variando entre 0 e 1.
     */
    void setColor(float r, float g, float b, float alpha);

    /**
     * @brief putVoxel ativa o voxel na posição (x,y,z) - fazendo isOn = true - e atribui ao mesmo a cor definida em setColor
     * @param x é a coordenada em relação ao eixo x
     * @param y é a coordenada em relação ao eixo y
     * @param z é a coordenada em relação ao eixo z
     */
    void putVoxel(int x, int y, int z);

    /**
     * @brief cutVoxel desativa o voxel na posição (x,y,z), fazendo isOn = false
     * @param x é a coordenada em relacao ao eixo x
     * @param y é a coordenada em relacao ao eixo y
     * @param z é a coordenada em relacao ao eixo z
     */
    void cutVoxel(int x, int y, int z);

    /**
     * @brief putBox ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor definida em setColor
     * @param x0 é a coordenada do ponto inicial no eixo x
     * @param x1 é a coordenada do ponto final no eixo x
     * @param y0 é a coordenada do ponto inicial no eixo y
     * @param y1 é a coordenada do ponto final no eixo y
     * @param z0 é a coordenada do ponto inicial no eixo z
     * @param z1 é a coordenada do ponto final no eixo z
     */
    void putBox(int x0, int x1,int y0, int y1,int z0, int z1);

    /**
     * @brief cutBox desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor definida em setColor
     * @param x0 é a coordenada do ponto inicial no eixo x
     * @param x1 é a coordenada do ponto final no eixo x
     * @param y0 é a coordenada do ponto inicial no eixo y
     * @param y1 é a coordenada do ponto final no eixo y
     * @param z0 é a coordenada do ponto inicial no eixo z
     * @param z1 é a coordenada do ponto final no eixo z
     */
    void cutBox(int x0, int x1,int y0, int y1,int z0, int z1);

    /**
     * @brief putSphere ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor definida em setColor
     * @param xcenter é a coordenada x do centro da esfera
     * @param ycenter é a coordenada y do centro da esfera
     * @param zcenter é a coordenada z do centro da esfera
     * @param radius é o raio da esfera
     */
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);

    /**
     * @brief cutSphere desativa todos os voxels que satisfazem a equação da esfera
     * @param xcenter é a coordenada x do centro da esfera
     * @param ycenter é a coordenada y do centro da esfera
     * @param zcenter é a coordenada z do centro da esfera
     * @param radius é o raio da esfera
     */
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

    /**
     * @brief putEllipsoid ativa todos os voxels que satisfazem a equação do elipsoide e atribui aos mesmos a cor definida em setColor
     * @param xcenter é a coordenada x do centro do elipsoide
     * @param ycenter é a coordenada y do centro do elipsoide
     * @param zcenter é a coordenada z do centro do elipsoide
     * @param rx é o raio na direção x
     * @param ry é o raio na direção y
     * @param rz é o raio na direção z
     */
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    /**
     * @brief cutEllipsoid desativa todos os voxels que satisfazem a equação do elipsoide
     * @param xcenter é a coordenada x do centro do elipsoide
     * @param ycenter é a coordenada y do centro do elipsoide
     * @param zcenter é a coordenada z do centro do elipsoide
     * @param rx é o raio na direção x
     * @param ry é o raio na direção y
     * @param rz é o raio na direção z
     */
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    /**
     * @brief writeOFF grava a escultura no formato OFF no arquivo filename
     * @param filename armazena caminho do arquivo .off
     */
    void writeOFF(char* filename);
};

#endif // SCULPTOR_H
