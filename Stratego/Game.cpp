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
    const float startingX = 100.f, startingY = 30.f;
    float posX = startingX, posY = startingY;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++){
            this->board[j][i].setPosition(posX, posY);
            this->board[j][i].setSize(sf::Vector2f(100.f, 100.f));
            this->board[j][i].setFillColor(sf::Color::Blue);
            this->board[j][i].setOutlineColor(sf::Color::Green);
            this->board[j][i].setOutlineThickness(2.f);

            posX = posX + 100;
        }
        posY = posY + 100;
        posX = startingX;
    }
    
}

void Game::initTexture()
{
}

void Game::initSprite()
{
}

//Constructors / Destructors
Game::Game() {
	this->initVariables();
	this->initWindow();
    this->initBoardSpace();
    this->initTexture();
    this->initSprite();
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

void Game::renderBoard()
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            this->window->draw(this->board[j][i]);
        }
    }
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
    renderBoard();

    this->window->display();
}






