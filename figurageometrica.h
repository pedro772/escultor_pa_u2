#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"
#include <iostream>


/**
 * @brief A classe FiguraGeometrica é a superclasse de referência para todas as classes que trabalham com formas
 */

class FiguraGeometrica
{
public:
    FiguraGeometrica();

    /**
      * @brief função virtual draw, usada para chamar outras funções draw, dependendo da classe apontada
      * @param t é o endereço do Sculptor construído
      */
    virtual void draw(Sculptor &t) = 0;

    virtual ~FiguraGeometrica();
};

#endif // FIGURAGEOMETRICA_H
