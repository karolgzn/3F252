#include <thread>
#include <chrono>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include "Autos.hpp"

int main() {
    const int ancho = 80;
    const int alto = 25;

    Autos escena(ancho, alto);

    const int total_frames = 400;  // Número total de frames de la animación

    for (int frame = 0; frame < total_frames; ++frame) {
        auto screen = ftxui::Screen::Create(
            ftxui::Dimension::Fixed(ancho),
            ftxui::Dimension::Fixed(alto)
        );

        escena.Dibujar(screen, ancho);

        screen.Print();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        printf("\033[H\033[J");
    }
    return 0;
}