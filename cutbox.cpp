#include "cutbox.h"

CutBox::CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1){
    x0 = _x0; x1 = _x1;
    y0 = _y0; y1 = _y1;
    z0 = _z0; z1 = _z1;
}

CutBox::~CutBox(){

}

void CutBox::draw(Sculptor &t){
    for(int z=z0; z<=z1; z++){
        for(int x=x0; x<=x1; x++){
            for(int y=y0; y<=y1; y++){
                t.cutVoxel(x,y,z);
            }
        }
    }
}
