#include "Game.h"
#include "iostream"


//private functions
void Game::initVariables() {
	this->window = nullptr;
}

void Game::initWindow() {
	this->videoMode.height = 1080;
	this->videoMode.width = 1920;
	this->window = new sf::RenderWindow(this->videoMode, "Stratego", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initBoard()
{
    const float startingX = 100.f, startingY = 30.f;
    const float scale = 0.7f;

    float posX = startingX, posY = startingY;
    float width = 100.f * scale;

    for (int i = 0; i < this->mainBoardSize; i++) {
        for (int j = 0; j < this->mainBoardSize; j++){

            this->board[j][i].changePixelPosition(posX, posY);
            this->board[j][i].setPixelX(posX);
            this->board[j][i].setPixelY(posY);
            this->board[j][i].initShape(scale);
            this->board[j][i].setUnitPtr(nullptr);
            

            posX = posX + width;
        }
        posY = posY + width;
        posX = startingX;
    }
}

void Game::initSideBoards()
{
    const float startingX = 1200.f, startingY = 30.f;
    const float scale = 0.7f;

    float posX = startingX, posY = startingY;
    float width = 100.f * scale;

    for (int i = 0; i < this->sideBoardWidth; i++) {
        for (int j = 0; j < this->sideBoardHeight; j++) {

            this->sideBoardBlue[j][i].changePixelPosition(posX, posY);
            this->sideBoardBlue[j][i].initShape(scale);
            //this->board[j][i]->occupier = NULL;

            posX = posX + width;
        }
        posY = posY + width;
        posX = startingX;
    }

    initUnits();//place all units on the side boards
}

//manual assignment of all units to the side board
void Game::initUnits(){
    this->blue_marshall.setRank(MARSHAL); //WORKING HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE


    this->blue_spy.setRank(SPY);
    this->blue_spy.setAllegiance(BLUE);
    this->blue_spy.initSprite("Textures/1_blue.png");
    this->sideBoardBlue[0][0].setUnitPtr(&blue_spy); //place on blue side board
    this->sideBoardBlue[0][0].getUnitPtr()->unitSprite.setPosition(this->board[0][0].getShape().getPosition().y, this->board[0][0].getShape().getPosition().x); //WEIRD PIXEL COORDINATE DISCREPANCY


}



//Constructors / Destructors
Game::Game(){
    this->initVariables();
    this->initWindow();
    this->initBoard();
    this->initSideBoards();
    this->initUnits();
}

Game::~Game() {
	delete this->window;
}

//Accessors
const bool Game::running() const {
	return this->window->isOpen();
}

//Functions
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
    //std::cout << "Mouse position: x=" << sf::Mouse::getPosition(*this->window).x << " y=" << sf::Mouse::getPosition(*this->window).y << std::endl;
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    //Relative to the view
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::onClick() {
    //Check if clicking on main board
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        for (int i = 0; i < mainBoardSize; i++) {
            for (int j = 0; j < mainBoardSize; j++) {
                if (this->board[j][i].isClicked(&this->mousePosView)) {
                    //selected
                    this->board[j][i].changeColour(sf::Color::Red);
                }
            }
        }
    }

    //Check if clicking on side board
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        for (int i = 0; i < sideBoardWidth; i++) {
            for (int j = 0; j < sideBoardHeight; j++) {
                if (this->sideBoardBlue[j][i].isClicked(&this->mousePosView)) {
                    //selected
                    this->sideBoardBlue[j][i].changeColour(sf::Color::Red);
                }
            }
        }
    }
}

/*
void Game::renderUnit(int y, int x)
{
    if (this->board[y][x].getUnitPtr() != nullptr) {
        this->window->draw(this->board[y][x].getUnitPtr()->unitSprite);
    }
}*/



void Game::renderBoard()
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++){ 
            //Draw space{
            this->window->draw(this->board[i][j].getShape());
            //Draw unit on space if there is one
            if (this->board[i][j].getUnitPtr() != nullptr) {
                this->window->draw(this->board[i][j].getUnitPtr()->unitSprite);
            }
        }
    }
}

void Game::renderSideBoards()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            //Draw space
            this->window->draw(this->sideBoardBlue[i][j].getShape());
            //Draw unit on space
            if (this->board[i][j].getUnitPtr() != nullptr) {
                this->window->draw(this->sideBoardBlue[i][j].getUnitPtr()->unitSprite);
            }
        }
    }

}



void Game::update()
{
    this->pollEvents();
    this->updateMousePosition();
    this->onClick();
}

void Game::render()
{
    
    /*clear old frame
      render objects
      display frame in window*/
    
    this->window->clear(sf::Color());

    //Draw game objects
    this->renderBoard();
    this->renderSideBoards();

    this->window->display();
}




/*
void battle(Unit attacker, Unit defender) {
    int attackerRank = attacker.getRank();
    int defenderRank = defender.getRank();

    //draw
    if (attackerRank == defenderRank) {
        attacker.die();
        defender.die();
    }
    //spy kills marshal
    else if (attackerRank == SPY && defenderRank == MARSHAL) {
        attacker.setLocation(defender.getLocation());
        defender.die();
    }
    //bomb is defused
    else if (attackerRank == MINER && defenderRank == BOMB) {
        attacker.setLocation(defender.getLocation());
        defender.die();
    }
    //bomb is triggered
    else if (defenderRank == BOMB) {
        attacker.die();
    }
    //flag is captured
    else if (defenderRank == FLAG) {
        //WIN THE GAME
    }
    //normal attacker win
    else if (attackerRank > defenderRank) {
        attacker.setLocation(defender.getLocation());
        defender.die();
    }
    //normal defender win
    else {
        attacker.die();
    }
}
*/