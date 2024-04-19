#include <ftxui/component/animation.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <experimental/random>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{

    int fotograma = 0;
    
    string reset;
    while (true)
    {
        fotograma++;

        int r = std::experimental::randint(0, 255);
        int g = std::experimental::randint(0, 255);
        int b = std::experimental::randint(0, 255); 

        Element personaje = spinner(21, fotograma);
        
        //para color especifico 
        Decorator colorFondo = bgcolor(Color::BlueLight);

        //para colores aleatorios
        //Decorator colorFondo = bgcolor (Color::RGB( r,g,b));
        Decorator colorTexto = color(Color::RGB(b,g,r));

        Element dibujo = border({hbox(personaje)  })| colorFondo | colorTexto; 

        Dimensions Alto = Dimension::Fixed(10);

        Dimensions Ancho = Dimension::Full();

        Screen pantalla = Screen::Create(Ancho, Alto);

        Render(pantalla, dibujo);

        pantalla.Print();

        reset = pantalla.ResetPosition();

        cout << reset;

        //para modificar el tiempo de como se mueve el monito
        this_thread::sleep_for(0.8s);
    }

    return 0;
}
