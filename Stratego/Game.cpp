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
void Game::initBoardSpace()
{
    this->boardSpace.setPosition(10.f, 10.f);
    this->boardSpace.setSize(sf::Vector2f(100.f, 100.f));
    this->boardSpace.setFillColor(sf::Color::Transparent);
    this->boardSpace.setOutlineColor(sf::Color::Green);
    this->boardSpace.setOutlineThickness(2.f);
}

//Constructors / Destructors
Game::Game() {
	this->initVariables();
	this->initWindow();
    this->initBoardSpace();
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

void Game::updateMousePosition()
{
    //Relative to the window
    std::cout << "Mouse position: x=" << sf::Mouse::getPosition(*this->window).x << " y=" << sf::Mouse::getPosition(*this->window).y << std::endl;
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

//Functions
void Game::update()
{
    this->pollEvents();
    this->updateMousePosition();
}

void Game::render()
{
    /*clear old frame
      render objects
      display frame in window*/
    
    this->window->clear(sf::Color());

    //Draw game objects
    this->window->draw(this->boardSpace);

    this->window->display();
}






