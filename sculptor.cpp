#include "sculptor.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using std::cout;
using std::endl;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx; ny = _ny; nz = _nz;

    if (nx <= 0 || ny <= 0 || nz <= 0)
        nx = ny = nz = 0;

    v = new Voxel**[nz];
    v[0] = new Voxel*[nz*nx];

    for (int z = 1; z < nz; z++){
        v[z] = v[z-1] + nx;
    }

    v[0][0] = new Voxel[nz*nx*ny];
    int n = 0;

    for (int z = 0; z < nz; z++){
        for(int x = 0; x < nx; x++){
            v[z][x] = v[0][0] + n*ny;
            n++;
        }
    }
}

Sculptor::~Sculptor(){
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

void Sculptor::setColor(float _r, float _g, float _b, float alpha){
    r = _r;
    g = _g;
    b = _b;
    a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z) {
    if(x<nx && x >= 0 && y < ny && y >= 0 && z < nz && z>= 0) {
        v[x][y][z].isOn = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z){
    if(x < nx && x >= 0 && y < ny && y >= 0 && z < nz && z >= 0)
        v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int z=z0; z<=z1; z++){
        for(int y=y0; y<=y1; y++){
            for(int x=x0; x<=x1; x++){
                putVoxel(x,y,z);
            }
        }
    }

}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){  
    for(int z=z0; z<=z1; z++){
        for(int x=x0; x<=x1; x++){
            for(int y=y0; y<=y1; y++){
                cutVoxel(x,y,z);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){  
    double distance;

    for(int z=0; z<=nz; z++){
        for(int y=0; y<=ny; y++){
            for(int x=0; x<=nz; x++){
                distance = pow(x - xcenter, 2) + pow(y - ycenter, 2) + pow(z - zcenter, 2);

                if(distance <= pow(radius,2) )
                    putVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    double distance;

    for(int z=0; z<=nz; z++){
        for(int y=0; y<=ny; y++){
            for(int x=0; x<=nx; x++){
                distance = pow(x - xcenter, 2) + pow(y - ycenter, 2) + pow(z - zcenter, 2);

                if(distance <= pow(radius,2))
                    cutVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float distanceX, distanceY, distanceZ;
    int x1 = xcenter-rx, x2 = xcenter+rx;
    int y1 = ycenter-ry, y2 = ycenter+ry;
    int z1 = zcenter-rz, z2 = zcenter+rz;

    for(int i=x1; i<x2; i++){
        distanceX=((static_cast<float>(i)-xcenter)/rx)*((static_cast<float>(i)-xcenter)/rx);
        for(int j=y1; j<y2; j++){
            distanceY=((static_cast<float>(j)-ycenter)/ry)*((static_cast<float>(j)-ycenter)/ry);
            for (int k=z1; k<z2; k++) {
                 distanceZ=((static_cast<float>(k)-zcenter)/rz)*((static_cast<float>(k)-zcenter)/rz);
                if(distanceX+distanceY+ distanceZ<=1){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float distanceX, distanceY, distanceZ;
    int x1 = xcenter-rx, x2 = xcenter+rx;
    int y1 = ycenter-ry, y2 = ycenter+ry;
    int z1 = zcenter-rz, z2 = zcenter+rz;

    for(int i=x1; i<x2; i++){
        distanceX=((static_cast<float>(i)-xcenter)/rx)*((static_cast<float>(i)-xcenter)/rx);
        for(int j=y1; j<y2; j++){
            distanceY=((static_cast<float>(j)-ycenter)/ry)*((static_cast<float>(j)-ycenter)/ry);
            for (int k=z1; k<z2; k++) {
                distanceZ=((static_cast<float>(k)-zcenter)/rz)*((static_cast<float>(k)-zcenter)/rz);
                if(distanceX+distanceY+distanceZ<=1){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}


void Sculptor::writeOFF(char* filename){
    int Nf, Nv, Nvox=0, nfc=0, face;
    char ***check;
    check=new char**[nx];

    if(check == nullptr){
        cout<<"check não armazenado"<<endl;
        exit(0);
    }

    check[0]= new char*[nx*ny];

    if(check[0] == nullptr){
        cout<<"check[0] não armazenado"<<endl;
        exit(0);
    }

    check[0][0]= new char[nx*ny*nz];

    if(check[0][0]==nullptr){
        cout<<"check[0][0] não armazenado"<<endl;
        exit(0);
    }

    for (int i=0;i<nx;i++){
        if(i<(nx-1))
            check[i+1]=check[i]+ny;

        for (int j=0;j<ny;j++){
            if(j==ny-1&&i!=(nx-1))
                check[i+1][0]=check[i][j]+nz;
            else
                check[i][j+1]=check[i][j]+nz;

            for(int k=0;k<nz;k++){
                check[i][j][k]='0';
            }
        }
    }

    for(int i=1;i<(nx-1);i++){
        for (int j=1;j<(ny-1);j++) {
            for(int k=1; k<(nz-1);k++){
                if(v[i-1][j][k].isOn && v[i+1][j][k].isOn && v[i][j-1][k].isOn &&
                        v[i][j+1][k].isOn && v[i][j][k-1].isOn && v[i][j][k+1].isOn){
                    check[i][j][k]='1';
                }
            }
        }
    }

    for(int i=1;i<(nx-1);i++){
        for (int j=1;j<(ny-1);j++) {
            for(int k=1; k<(nz-1);k++){
                if(check[i][j][k]=='1'){
                    v[i][j][k].isOn=false;
                }
            }
        }
    }

    delete [] check[0][0];
    delete [] check[0];
    delete [] check;

    std::ofstream file;
    file.open(filename);

    if(file.is_open()){
        cout<<"Arquivo off aberto"<<endl;
    } else {
        cout << "arquivo off nao foi aberto"<<endl;
        exit(1);
    }

    file<<"OFF \n";

    for (int i=0;i<nx;i++) {
        for (int j=0;j<ny;j++) {
            for (int k=0;k<nz;k++) {
                if(v[i][j][k].isOn){
                    Nvox++;
                }
            }
        }
    }

    Nf=6*Nvox;
    Nv=8*Nvox;
    file<<Nv<<" "<<Nf<<" 0 \n";

    double lowX,highX,lowY,highY,lowZ,highZ;

    for(int k=0;k<nz; k++){
        lowZ=-0.5+k;
        highZ=0.5+k;
        for(int j=0;j<ny;j++){
            lowY=-0.5+j;
            highY=0.5+j;
            for(int i=0;i<nx;i++){
                lowX=-0.5+i;
                highX=0.5+i;

                if(v[i][j][k].isOn){
                    file<<lowX<<" "<<highY<<" "<<lowZ<<endl
                       <<lowX<<" "<<lowY<<" "<<lowZ<<endl
                      <<highX<<" "<<lowY<<" "<<lowZ<<endl
                     <<highX<<" "<<highY<<" "<<lowZ<<endl
                    <<lowX<<" "<<highY<<" "<<highZ<<endl
                    <<lowX<<" "<<lowY<<" "<<highZ<<endl
                    <<highX<<" "<<lowY<<" "<<highZ<<endl
                    <<highX<<" "<<highY<<" "<<highZ<<endl;
                }
            }
        }

    }

    for(int k=0;k<nz; k++){
        for(int j=0;j<ny;j++){
            for(int i=0;i<nx;i++){

                if(v[i][j][k].isOn){
                    face=nfc*8;

                    file<<"4 "<<0+face<<" "<<3+face<<" "<<2+face<<" "<<1+face<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                       <<"4 "<<4+face<<" "<<5+face<<" "<<6+face<<" "<<7+face<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                      <<"4 "<<0+face<<" "<<1+face<<" "<<5+face<<" "<<4+face<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                     <<"4 "<<0+face<<" "<<4+face<<" "<<7+face<<" "<<3+face<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                    <<"4 "<<3+face<<" "<<7+face<<" "<<6+face<<" "<<2+face<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                    <<"4 "<<1+face<<" "<<2+face<<" "<<6+face<<" "<<5+face<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;

                    nfc++;
                }
            }
        }
    }

    file.close();
}
