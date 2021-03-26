#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "sculptor.h"

int main() {
    Sculptor *policeCar;
    int dimensionX=120, dimensionY=120, dimensionZ=120;

    policeCar = new Sculptor(dimensionX,dimensionY,dimensionZ);

    // estrutura principal
    policeCar->setColor(190,190,190,1);
    policeCar->putBox(0,80,10,34,0,30);
    policeCar->cutBox(10,20,10,17,0,30);
    policeCar->cutBox(60,70,10,17,0,30);
    policeCar->cutBox(0,15,23,34,0,30);
    policeCar->cutBox(65,80,23,34,0,30);
    policeCar->cutBox(0,4,10,14,0,30);
    policeCar->cutBox(76,80,10,14,0,30);

    // parachoques
    policeCar->setColor(0,0,0,0.5);
    policeCar->putBox(0,4,10,14,0,30);
    policeCar->putBox(76,80,10,14,0,30);

    // eixo frontal
    policeCar->setColor(0,0,0,0.5);
    policeCar->putSphere(15,10,2,5);
    policeCar->cutBox(10,20,5,15,5,10);
    policeCar->putSphere(15,10,28,5);
    policeCar->cutBox(10,20,5,15,20,25);
    policeCar->cutBox(10,20,5,15,31,35);
    policeCar->putBox(14,16,9,11,4,26);
    policeCar->putBox(14,16,11,17,13,15);

    // eixo traseiro
    policeCar->setColor(0,0,0,0.5);
    policeCar->putSphere(65,10,2,5);
    policeCar->cutBox(60,70,5,15,5,10);
    policeCar->putSphere(65,10,28,5);
    policeCar->cutBox(60,70,5,15,20,25);
    policeCar->cutBox(60,70,5,15,31,35);
    policeCar->putBox(64,66,9,11,4,26);
    policeCar->putBox(64,66,11,17,13,15);

    // farois frontais
    policeCar->cutBox(0,1,17,19,2,8);
    policeCar->setColor(255,255,255,1);
    policeCar->putBox(0,1,17,19,2,8);
    policeCar->setColor(255,255,0,1);
    policeCar->putVoxel(0,18,0);
    policeCar->putVoxel(0,18,1);
    policeCar->putVoxel(0,17,1);
    policeCar->putVoxel(0,19,1);
    policeCar->cutBox(0,1,17,19,22,28);
    policeCar->setColor(255,255,255,1);
    policeCar->putBox(0,1,17,19,22,28);
    policeCar->setColor(255,255,0,1);
    policeCar->putVoxel(0,18,30);
    policeCar->putVoxel(0,18,29);
    policeCar->putVoxel(0,17,29);
    policeCar->putVoxel(0,19,29);

    // farois traseiros
    policeCar->cutBox(79,80,17,19,2,8);
    policeCar->setColor(255,0,0,1);
    policeCar->putBox(79,80,17,19,2,8);
    policeCar->setColor(255,255,0,1);
    policeCar->putVoxel(80,18,0);
    policeCar->putVoxel(80,18,1);
    policeCar->putVoxel(80,17,1);
    policeCar->putVoxel(80,19,1);
    policeCar->cutBox(79,80,17,19,22,28);
    policeCar->setColor(255,0,0,1);
    policeCar->putBox(79,80,17,19,22,28);
    policeCar->setColor(255,255,0,1);
    policeCar->putVoxel(80,18,30);
    policeCar->putVoxel(80,18,29);
    policeCar->putVoxel(80,17,29);
    policeCar->putVoxel(80,19,29);
    policeCar->setColor(255,255,255,1);
    policeCar->putBox(80,80,18,18,23,27);
    policeCar->putBox(80,80,18,18,3,7);

    // giroflex
    policeCar->setColor(255,0,0,0.1);
    policeCar->putEllipsoid(25,36,15,3,2,10);

    // portas
    policeCar->setColor(80,80,80,1);
    policeCar->putBox(63,63,19,33,0,0);
    policeCar->putBox(63,63,19,33,30,30);
    policeCar->putBox(58,63,19,19,0,0);
    policeCar->putBox(58,63,19,19,30,30);
    policeCar->putBox(58,58,11,19,30,30);
    policeCar->putBox(58,58,11,19,0,0);
    policeCar->putBox(17,17,19,33,0,0);
    policeCar->putBox(17,17,19,33,30,30);
    policeCar->putBox(17,22,19,19,0,0);
    policeCar->putBox(17,22,19,19,30,30);
    policeCar->putBox(22,22,11,19,30,30);
    policeCar->putBox(22,22,11,19,0,0);
    policeCar->putBox(17,63,33,33,0,0);
    policeCar->putBox(17,63,33,33,30,30);
    policeCar->putBox(22,58,11,11,0,0);
    policeCar->putBox(22,58,11,11,30,30);
    policeCar->putBox(40,40,11,33,0,0);
    policeCar->putBox(40,40,11,33,30,30);
    policeCar->setColor(150,150,150,1);
    policeCar->putBox(41,41,12,32,30,30);
    policeCar->putBox(41,41,12,32,0,0);
    policeCar->putBox(39,39,12,32,30,30);
    policeCar->putBox(39,39,12,32,0,0);
    policeCar->setColor(0,0,0,1);
    policeCar->putBox(35,37,22,22,0,0);
    policeCar->putBox(35,37,22,22,30,30);
    policeCar->putBox(59,61,22,22,0,0);
    policeCar->putBox(59,61,22,22,30,30);

    policeCar -> writeOFF("C:/Users/pedro/Documents/UFRN/programacao_avancada/escultor_pa_u2/police_car.off");
    return 0;
}
