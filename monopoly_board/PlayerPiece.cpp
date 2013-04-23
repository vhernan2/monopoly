#include "PlayerPiece.h"

PlayerPiece::PlayerPiece() {
    x = 720;
    y = 780;
}   
                
void PlayerPiece::move(int location){
    
    if (location <= 10) y = 790;
    if ((location > 10) && (location <=20 )) x = 20;
    if ((location > 20) && (location <=30 )) y = 20;
    if (location > 30) x = 765;
    
    switch (location) {
    
        case 0:
                x = 745; 
                break;
        case 1:
        case 29:
                x = 656;
        break;
        case 2:
        case 28:
                x = 592;
                break;
        case 3:
        case 27:
                x = 522;
                break;
        case 4:
        case 26:
                x = 461;
                break;
        case 5:
        case 25:
                x = 397;
                break;
        case 6:
        case 24:
                x = 328;
        break;
        case 7:
        case 23:
                x = 266;
                break;
        case 8:
        case 22:
                x = 200;
                break;
        case 9:
        case 21:
                x = 138;
                break;
        case 10:
                x = 9;
                y = 791;
                break;
        case 11:
        case 39:
                y = 651;
                break;
        case 12:
        case 38:
                y = 586;
                break;
        case 13:
        case 37:
                y = 521;
                break;
        case 14:
        case 36:
                y = 458;
                break;
        case 15:
        case 35:
                y = 391;
                break;
        case 16:
        case 34:
                y = 326;
                break;
        case 17:
        case 33:
                y = 265;
                break;
        case 18:
        case 32:
                y = 198;
                break;
        case 19:
        case 31:
                y = 136;
                break;
        case 20:
                x = 30;
                y = 36;
                break;
        case 30:
                x = 45;
                y = 739;
                break;
        default:
                x = 400;
                y = 400;
                break;

    }

}

int PlayerPiece::getX(){
        return x;
}

int PlayerPiece::getY(){
        return y;
}

