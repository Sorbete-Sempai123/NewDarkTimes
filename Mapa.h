#ifndef MAPA_H
#define MAPA_H
#include "Headers.h"
#include "Area.h"
#include <SFML/Graphics.hpp>
#include "ValoresGlobales.h"
class Mapa
{
	float tam; //Tamaño del mapa
    int area_num;//cantidad de Areas normalmente cuadrado
    int area_numx;
    int area_numy;
    int area_numbloq;//cantidad de bloques por area
    int area_numbloqx;
    int area_numbloqy;
    int area_tamx;
    int area_tamy;
    Area *arr_areas;
    sf::Texture *texturas;
public:
    Mapa(){}
    Mapa(float,int,int,sf::Texture&);
    //tamano del mapa , numero de areas , numero de bloques por area
    Mapa(float,int,int,sf::Texture*,int[][pred_bloq_numx*pred_bloq_numy]);
    //
    Mapa(float,int,int,int,int);
    //tamano del mapa , numero de areas en X y Y , numnero de bloques por area X y Y
    Mapa(float,int,int[]);
    ~Mapa();
	int getarea_num(){return area_num;}
    int getarea_num_bloq(){return area_numbloq;}
    void Random(sf::RenderWindow&);
    void Dibujar_mapa(sf::RenderWindow&);
    void Dibujar(sf::RenderWindow&,int);
    void Dibujar_Area(sf::RenderWindow&,int);
    int getnumbloq(){
        return area_numbloq*area_num;
    }

    Area* getArea(int i){return &arr_areas[i];}
};
#endif 


