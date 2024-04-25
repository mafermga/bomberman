#include <ftxui/component/animation.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <experimental/random>
#include <list>
#include <fstream>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    list<string> textos;
    fstream imagen;
    imagen.open("./assets/imagen.txt");

    string linea;
    while (getline(imagen, linea));

    {
        textos.push_back(linea);
    }
    imagen.close();

    int fotograma = 0;

    string reset;
    int posX = 0;
    int posY = 6;
    while (true)
    {
        fotograma++;

        int r = std::experimental::randint(0, 255);
        int g = std::experimental::randint(0, 255);
        int b = std::experimental::randint(0, 255);

        Element personaje = spinner(21, fotograma);

        // para color especifico
        Decorator colorFondo = bgcolor(Color::BlueLight);

        // para colores aleatorios
        // Decorator colorFondo = bgcolor (Color::RGB( r,g,b));
        Decorator colorTexto = color(Color::RGB(b, g, r));

        Element dibujo = border({hbox(personaje)}) | colorFondo | colorTexto;

        Dimensions Alto = Dimension::Full();

        Dimensions Ancho = Dimension::Full();

        Screen pantalla = Screen::Create(Ancho, Alto);

        Render(pantalla, dibujo);
        // para imprimir un parrafo
        // list<string> textos;
        // string texto = "Hola";
        // textos.push_back("Primera linea");
        // textos.push_back("Segunda linea");
        // textos.push_back("Tercera linea");

        int l = 0;
        for (auto &&texto : textos)
        {
            int i = 0;
            for (auto &&letra : texto)
            {
                pantalla.PixelAt(posX + i, posY + l).character = letra;
                i++;
            }
            l++;
        }

        posX++;
        pantalla.Print();

        reset = pantalla.ResetPosition();

        cout << reset;
        fotograma++;

        // para modificar el tiempo de como se mueve el monito
        this_thread::sleep_for(0.5s);
    }

    return 0;
}
