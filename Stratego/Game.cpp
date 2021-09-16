#include "Game.h"


//private functions
void Game::initVariables() {
	this->window = nullptr;
}
void Game::initWindow() {
	this->videoMode.height = 1080;
	this->videoMode.width = 1920;
	this->window = new sf::RenderWindow(this->videoMode, "Stratego", sf::Style::Titlebar | sf::Style::Close);
}
//Constructors / Destructors
Game::Game() {
	this->initVariables();
	this->initWindow();
}

Game::~Game() {
	delete this->window;
}

//Accessors
const bool Game::running() const {
	return this->window->isOpen();
}

void Game::pollEvents()
{
    //Event polling
    while (this->window->pollEvent(this->ev)) {
        switch (ev.type)
        {
            //close window with X on window
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            //close window with esc
            if (ev.key.code == sf::Keyboard::Escape) {
                this->window->close();
            }
            break;
            //case mouse
        default:
            break;
        }
    }
}

//Functions
void Game::update()
{
    this->pollEvents();
}

void Game::render()
{
    /*clear old frame
      render objects
      display frame in window*/
    
    this->window->clear(sf::Color(255, 0, 0, 255));

    //Draw game

    this->window->display();
}






