#include"window.h"
#include <math.h>
#include <string>


Window::Window(float tam_1,float tam_2,std::string tittle){
    tamx=tam_1;
    tamy=tam_2;
    sf::RenderWindow window(sf::VideoMode(tamx,tamy),tittle);
}

void Window::Abierto(bool state){

}

void Window::Dibujar(){

}
