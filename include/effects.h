#ifndef TETRIS_EFFECTS_H
#define TETRIS_EFFECTS_H

#include <SFML/Graphics.hpp>
#include  <SFML/Audio.hpp>

using namespace sf;

namespace tetris
{
    
    class Effect{
    public:
    Effect();
    void Score();

    private:
    sf::Texture brick_tex;
    sf::Sprite brick;
    sf::Music track;
    sf::SoundBuffer buffer;
    sf::SoundBuffer bufferTwo;
    sf::SoundBuffer bufferThree;
    sf::Text score;
	sf::Font font;


    };





}
#endif 