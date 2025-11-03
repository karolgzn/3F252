#pragma once
#include <cmath>
#include <vector>
#include "Dibujo.hpp"
#include "GestorDibujos.hpp"

class Autos {
public:
    GestorDibujos gestor;
    Dibujo carretera;
    std::vector<Dibujo> edificios;
    Dibujo auto1;
    Dibujo auto2;
    Dibujo meta;
    int frame = 0;

    Autos(int ancho_pantalla, int alto_pantalla)
        : carretera(0, alto_pantalla / 2 - 2, GenerarCarretera(ancho_pantalla, 5), ftxui::Color::GrayDark),
          auto1(2, alto_pantalla / 2 - 3, GenerarAuto(U'#'), ftxui::Color::Red),
          auto2(10, alto_pantalla / 2 + 1, GenerarAuto(U'@'), ftxui::Color::Blue),
          meta(ancho_pantalla - 10, alto_pantalla / 2 - 6, GenerarMeta(), ftxui::Color::Green) {

        // Crear algunos edificios al azar
        int edificio_ancho = 10;
        for (int i = 0; i < ancho_pantalla; i += edificio_ancho + 2) {
            edificios.push_back(Dibujo(i, 1, GenerarEdificio(edificio_ancho, 6), ftxui::Color::Yellow));
            edificios.push_back(Dibujo(i, alto_pantalla - 8, GenerarEdificio(edificio_ancho, 6), ftxui::Color::Yellow));
        }

        gestor.Agregar(carretera);
        gestor.Agregar(auto1);
        gestor.Agregar(auto2);
        gestor.Agregar(meta);
        for (auto& e : edificios) gestor.Agregar(e);
    }

    static std::vector<std::u32string> GenerarCarretera(int ancho, int alto) {
        std::vector<std::u32string> figura;
        for (int i = 0; i < alto; ++i) {
            std::u32string fila(ancho, U' ');
            if (i == 0 || i == alto - 1) {
                for (int j = 0; j < ancho; ++j)
                    fila[j] = U'=';
            } else if (i == alto / 2) {
                for (int j = 0; j < ancho; j += 6)
                    fila[j] = U'-';
            }
            figura.push_back(fila);
        }
        return figura;
    }

    static std::vector<std::u32string> GenerarAuto(char32_t c) {
        return {
            U" __",
            U"|__\\_",
            std::u32string{U' ', c, U' ', c, U' '}
        };
    }

    static std::vector<std::u32string> GenerarEdificio(int ancho, int alto) {
        std::vector<std::u32string> figura;
        for (int i = 0; i < alto; ++i) {
            std::u32string fila(ancho, U' ');
            for (int j = 0; j < ancho; ++j) {
                if (i == 0 || i == alto - 1 || j == 0 || j == ancho - 1)
                    fila[j] = U'#';
                else if (i % 2 == 0 && j % 2 == 0)
                    fila[j] = U'o';
            }
            figura.push_back(fila);
        }
        return figura;
    }

    static std::vector<std::u32string> GenerarMeta() {
        return {
            U"##########",
            U"#   M E  #",
            U"#   T A  #",
            U"##########",
            U"    ||    ",
            U"    ||    "
        };
    }

    void MoverAutos(int ancho_pantalla) {
        frame++;

        // Mover auto1 y auto2 horizontalmente
        auto1.x = (2 + frame) % (ancho_pantalla - 6);
        auto2.x = (10 + frame * 2) % (ancho_pantalla - 6);
    }

    void Dibujar(ftxui::Screen& screen, int ancho_pantalla) {
        gestor.dibujos.clear();

        // Redibujar carretera, meta y edificios
        gestor.Agregar(carretera);
        for (auto& e : edificios) gestor.Agregar(e);
        gestor.Agregar(meta);

        // Mover autos y volverlos a agregar
        MoverAutos(ancho_pantalla);
        gestor.Agregar(auto1);
        gestor.Agregar(auto2);

        gestor.DibujarTodos(screen);
    }
};