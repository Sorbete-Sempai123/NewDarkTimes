#include "Headers.h"
#include "Entidad.h"
#include "Mapa.h"
#include "State.h"
#include "ValoresGlobales.h"
#include "Zombie.h"
#include "Colisiones.h"


#define Nentity 100

int mapa_arr[pred_areas_numx*pred_areas_numy][pred_bloq_numx*pred_bloq_numy]={
        {1,1,1,1,1,0,0,0,1,0,1,1,1,0,0,0},
        {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    };
//g++ main.cpp -o test -lsfml-graphics -lsfml-window -lsfml-system Mapa.cpp window.cpp Entidad.cpp Area.cpp Colisiones.cpp Bloque.cpp

// El Main esta muy frondoso, MAS ABSTRACCION!
int main(){
    // create the window
    sf::RenderWindow window(sf::VideoMode(pred_window_tamx,pred_window_tamy), "My window");
    window.setMouseCursorGrabbed(0);
    srand(time(NULL));
    Zombie *mobs=new Zombie[Nentity];
    for(int i = 0; i < Nentity; i++)
    {
        mobs[i].setPosx_y(1366/2,768/2);
    }
    
    Colisiones col;
    col.setEntidades(mobs,Nentity);
    
    int x=0;
    window.setFramerateLimit(60);
    //Texturas
    sf::Texture *texturas;
    texturas=new sf::Texture[1];
    texturas[0].loadFromFile("Texturas/terreno1.jpg");
    // run the program as long as the window is open
    Mapa render(800,pred_areas_numx,pred_bloq_numx,*texturas,mapa_arr);
    while (window.isOpen())
    {
        for(int i=0;i<Nentity;i++){
            for(int j=0;j<Nentity;j++){
                if(i==j)continue;
                col.Entidad_Entidad(i,j);
            }
        }
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        //
        //DIBUJO DEL MAPA
        //render.Dibujar(window,1);
        //render.Dibujar(window,2);
        render.Dibujar_mapa(window);
        //render.Dibujar_Area(window,0);

        //
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            sf::CircleShape ward(100);
            ward.setFillColor(sf::Color(50,200,100));
            sf::Vector2i mposition= sf::Mouse::getPosition();
            ward.setPosition(sf::Vector2f(mposition.x,mposition.y));
            window.draw(ward);
            std::cout<<"mousepressed"<<mposition.x<<mposition.y<<"|";
        }
        //
        x=(x+1)%300;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))x=0;
        std::cout<<x<<"||";
        for(int i = 0; i < Nentity; i++)
        {
            mobs[i].MoveAutomatico();
            mobs[i].Dibujar(window);
        }

        for(int i=0;i<Nentity;i++){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                mobs[i].setObj(sf::Mouse::getPosition().x+5,sf::Mouse::getPosition().y+5);   
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                    mobs[i].setObj(100*i%(16*100),100*i/(16*100)*100);
            }
            mobs[i].MoveAutomatico();
            mobs[i].Dibujar(window);
        }
        // draw everything here...
        // window.draw(...);
        std::cout<<std::endl;
        // end the current frame
        window.display();
    }

    return 0;
}