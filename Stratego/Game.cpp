#include "Game.h"
#include "iostream"


//private functions
void Game::initVariables() {
	this->window = nullptr;
    this->unitIsSelected = false;
    this->selectedSpace = nullptr;
    this->setupTime = true;
    for (int i = 0; i < 8; i++)
    {
        this->blockades[i].setAllegiance(NEUTRAL);
        this->blockades[i].setRank(BLOCKADE);
        this->blockades[i].initSprite("Textures/boat.png");
    }
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

    this->spawnBlockades(); //place the water in the middle
}

void Game::initSideBoards()
{
    const float startingX = 1000.f, startingY = 30.f;
    const float scale = 0.7f;

    float posX = startingX, posY = startingY;
    float width = 100.f * scale;

    for (int i = 0; i < this->sideBoardHeight; i++) {
        for (int j = 0; j < this->sideBoardWidth; j++) {

            this->sideBoardBlue[j][i].changePixelPosition(posX, posY);
            this->sideBoardBlue[j][i].setPixelX(posX);
            this->sideBoardBlue[j][i].setPixelY(posY);
            this->sideBoardBlue[j][i].initShape(scale);
            this->sideBoardBlue[j][i].setUnitPtr(nullptr);

            posX = posX + width;
        }
        posY = posY + width;
        posX = startingX;
    }

    initUnits();//place all units on the side boards
}

//manual assignment of all units to the side board
void Game::initUnits(){
    /*
    10: 1 Marshall
    9: 1 General
    8: 2 Colonels
    7: 3 Majors
    6: 4 Captains
    5: 4 Lieutenants
    4: 4 Sergeants
    3: 5 Miners
    2: 8 Scouts
    1: 1 Spy
    */
    this->blue_marshall.setRank(MARSHAL); //WORKING HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
    this->blue_marshall.setAllegiance(BLUE);
    this->blue_marshall.initSprite("Textures/10_blue.png");
    this->sideBoardBlue[0][0].setUnitPtr(&blue_marshall); //place on blue side board
    this->sideBoardBlue[0][0].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[0][0].getShape().getPosition().x, this->sideBoardBlue[0][0].getShape().getPosition().y);

    this->blue_general.setRank(GENERAL);
    this->blue_general.setAllegiance(BLUE);
    this->blue_general.initSprite("Textures/9_blue.png");
    this->sideBoardBlue[1][0].setUnitPtr(&blue_general);
    this->sideBoardBlue[1][0].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[1][0].getShape().getPosition().x, this->sideBoardBlue[1][0].getShape().getPosition().y);

    this->blue_colonel_1.setRank(COLONEL);
    this->blue_colonel_1.setAllegiance(BLUE);
    this->blue_colonel_1.initSprite("Textures/8_blue.png");
    this->sideBoardBlue[2][0].setUnitPtr(&blue_colonel_1);
    this->sideBoardBlue[2][0].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[2][0].getShape().getPosition().x, this->sideBoardBlue[2][0].getShape().getPosition().y);

    this->blue_colonel_2.setRank(COLONEL);
    this->blue_colonel_2.setAllegiance(BLUE);
    this->blue_colonel_2.initSprite("Textures/8_blue.png");
    this->sideBoardBlue[3][0].setUnitPtr(&blue_colonel_2);
    this->sideBoardBlue[3][0].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[3][0].getShape().getPosition().x, this->sideBoardBlue[3][0].getShape().getPosition().y);

    this->blue_major_1.setRank(MAJOR);
    this->blue_major_1.setAllegiance(BLUE);
    this->blue_major_1.initSprite("Textures/7_blue.png");
    this->sideBoardBlue[0][1].setUnitPtr(&blue_major_1);
    this->sideBoardBlue[0][1].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[0][1].getShape().getPosition().x, this->sideBoardBlue[0][1].getShape().getPosition().y);

    this->blue_major_2.setRank(MAJOR);
    this->blue_major_2.setAllegiance(BLUE);
    this->blue_major_2.initSprite("Textures/7_blue.png");
    this->sideBoardBlue[1][1].setUnitPtr(&blue_major_2);
    this->sideBoardBlue[1][1].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[1][1].getShape().getPosition().x, this->sideBoardBlue[1][1].getShape().getPosition().y);

    this->blue_major_3.setRank(MAJOR);
    this->blue_major_3.setAllegiance(BLUE);
    this->blue_major_3.initSprite("Textures/7_blue.png");
    this->sideBoardBlue[2][1].setUnitPtr(&blue_major_3);
    this->sideBoardBlue[2][1].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[2][1].getShape().getPosition().x, this->sideBoardBlue[2][1].getShape().getPosition().y);

    this->blue_captain_1.setRank(CAPTAIN);
    this->blue_captain_1.setAllegiance(BLUE);
    this->blue_captain_1.initSprite("Textures/6_blue.png");
    this->sideBoardBlue[3][1].setUnitPtr(&blue_captain_1);
    this->sideBoardBlue[3][1].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[3][1].getShape().getPosition().x, this->sideBoardBlue[3][1].getShape().getPosition().y);

    this->blue_captain_2.setRank(CAPTAIN);
    this->blue_captain_2.setAllegiance(BLUE);
    this->blue_captain_2.initSprite("Textures/6_blue.png");
    this->sideBoardBlue[0][2].setUnitPtr(&blue_captain_2);
    this->sideBoardBlue[0][2].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[0][2].getShape().getPosition().x, this->sideBoardBlue[0][2].getShape().getPosition().y);

    this->blue_captain_3.setRank(CAPTAIN);
    this->blue_captain_3.setAllegiance(BLUE);
    this->blue_captain_3.initSprite("Textures/6_blue.png");
    this->sideBoardBlue[1][2].setUnitPtr(&blue_captain_3);
    this->sideBoardBlue[1][2].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[1][2].getShape().getPosition().x, this->sideBoardBlue[1][2].getShape().getPosition().y);

    this->blue_captain_4.setRank(CAPTAIN);
    this->blue_captain_4.setAllegiance(BLUE);
    this->blue_captain_4.initSprite("Textures/6_blue.png");
    this->sideBoardBlue[2][2].setUnitPtr(&blue_captain_4);
    this->sideBoardBlue[2][2].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[2][2].getShape().getPosition().x, this->sideBoardBlue[2][2].getShape().getPosition().y);

    this->blue_lieutenant_1.setRank(LIEUTENANT);
    this->blue_lieutenant_1.setAllegiance(BLUE);
    this->blue_lieutenant_1.initSprite("Textures/5_blue.png");
    this->sideBoardBlue[3][2].setUnitPtr(&blue_lieutenant_1);
    this->sideBoardBlue[3][2].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[3][2].getShape().getPosition().x, this->sideBoardBlue[3][2].getShape().getPosition().y);

    this->blue_lieutenant_2.setRank(LIEUTENANT);
    this->blue_lieutenant_2.setAllegiance(BLUE);
    this->blue_lieutenant_2.initSprite("Textures/5_blue.png");
    this->sideBoardBlue[0][3].setUnitPtr(&blue_lieutenant_2);
    this->sideBoardBlue[0][3].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[0][3].getShape().getPosition().x, this->sideBoardBlue[0][3].getShape().getPosition().y);

    this->blue_lieutenant_3.setRank(LIEUTENANT);
    this->blue_lieutenant_3.setAllegiance(BLUE);
    this->blue_lieutenant_3.initSprite("Textures/5_blue.png");
    this->sideBoardBlue[1][3].setUnitPtr(&blue_lieutenant_3);
    this->sideBoardBlue[1][3].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[1][3].getShape().getPosition().x, this->sideBoardBlue[1][3].getShape().getPosition().y);

    this->blue_lieutenant_4.setRank(LIEUTENANT);
    this->blue_lieutenant_4.setAllegiance(BLUE);
    this->blue_lieutenant_4.initSprite("Textures/5_blue.png");
    this->sideBoardBlue[2][3].setUnitPtr(&blue_lieutenant_4);
    this->sideBoardBlue[2][3].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[2][3].getShape().getPosition().x, this->sideBoardBlue[2][3].getShape().getPosition().y);

    this->blue_sergeant_1.setRank(SERGEANT);
    this->blue_sergeant_1.setAllegiance(BLUE);
    this->blue_sergeant_1.initSprite("Textures/4_blue.png");
    this->sideBoardBlue[3][3].setUnitPtr(&blue_sergeant_1);
    this->sideBoardBlue[3][3].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[3][3].getShape().getPosition().x, this->sideBoardBlue[3][3].getShape().getPosition().y);

    this->blue_sergeant_2.setRank(SERGEANT);
    this->blue_sergeant_2.setAllegiance(BLUE);
    this->blue_sergeant_2.initSprite("Textures/4_blue.png");
    this->sideBoardBlue[0][4].setUnitPtr(&blue_sergeant_2);
    this->sideBoardBlue[0][4].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[0][4].getShape().getPosition().x, this->sideBoardBlue[0][4].getShape().getPosition().y);

    this->blue_sergeant_3.setRank(SERGEANT);
    this->blue_sergeant_3.setAllegiance(BLUE);
    this->blue_sergeant_3.initSprite("Textures/4_blue.png");
    this->sideBoardBlue[1][4].setUnitPtr(&blue_sergeant_3);
    this->sideBoardBlue[1][4].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[1][4].getShape().getPosition().x, this->sideBoardBlue[1][4].getShape().getPosition().y);

    this->blue_sergeant_4.setRank(SERGEANT);
    this->blue_sergeant_4.setAllegiance(BLUE);
    this->blue_sergeant_4.initSprite("Textures/4_blue.png");
    this->sideBoardBlue[2][4].setUnitPtr(&blue_sergeant_4);
    this->sideBoardBlue[2][4].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[2][4].getShape().getPosition().x, this->sideBoardBlue[2][4].getShape().getPosition().y);

    this->blue_miner_1.setRank(MINER);
    this->blue_miner_1.setAllegiance(BLUE);
    this->blue_miner_1.initSprite("Textures/3_blue.png");
    this->sideBoardBlue[3][4].setUnitPtr(&blue_miner_1);
    this->sideBoardBlue[3][4].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[3][4].getShape().getPosition().x, this->sideBoardBlue[3][4].getShape().getPosition().y);
    
    this->blue_miner_2.setRank(MINER);
    this->blue_miner_2.setAllegiance(BLUE);
    this->blue_miner_2.initSprite("Textures/3_blue.png");
    this->sideBoardBlue[0][5].setUnitPtr(&blue_miner_2);
    this->sideBoardBlue[0][5].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[0][5].getShape().getPosition().x, this->sideBoardBlue[0][5].getShape().getPosition().y);

    this->blue_miner_3.setRank(MINER);
    this->blue_miner_3.setAllegiance(BLUE);
    this->blue_miner_3.initSprite("Textures/3_blue.png");
    this->sideBoardBlue[1][5].setUnitPtr(&blue_miner_3);
    this->sideBoardBlue[1][5].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[1][5].getShape().getPosition().x, this->sideBoardBlue[1][5].getShape().getPosition().y);

    this->blue_miner_4.setRank(MINER);
    this->blue_miner_4.setAllegiance(BLUE);
    this->blue_miner_4.initSprite("Textures/3_blue.png");
    this->sideBoardBlue[2][5].setUnitPtr(&blue_miner_4);
    this->sideBoardBlue[2][5].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[2][5].getShape().getPosition().x, this->sideBoardBlue[2][5].getShape().getPosition().y);

    this->blue_miner_5.setRank(MINER);
    this->blue_miner_5.setAllegiance(BLUE);
    this->blue_miner_5.initSprite("Textures/3_blue.png");
    this->sideBoardBlue[3][5].setUnitPtr(&blue_miner_5);
    this->sideBoardBlue[3][5].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[3][5].getShape().getPosition().x, this->sideBoardBlue[3][5].getShape().getPosition().y);

    this->blue_scout_1.setRank(SCOUT);
    this->blue_scout_1.setAllegiance(BLUE);
    this->blue_scout_1.initSprite("Textures/2_blue.png");
    this->sideBoardBlue[0][6].setUnitPtr(&blue_scout_1);
    this->sideBoardBlue[0][6].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[0][6].getShape().getPosition().x, this->sideBoardBlue[0][6].getShape().getPosition().y);

    this->blue_scout_2.setRank(SCOUT);
    this->blue_scout_2.setAllegiance(BLUE);
    this->blue_scout_2.initSprite("Textures/2_blue.png");
    this->sideBoardBlue[1][6].setUnitPtr(&blue_scout_2);
    this->sideBoardBlue[1][6].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[1][6].getShape().getPosition().x, this->sideBoardBlue[1][6].getShape().getPosition().y);

    this->blue_scout_3.setRank(SCOUT);
    this->blue_scout_3.setAllegiance(BLUE);
    this->blue_scout_3.initSprite("Textures/2_blue.png");
    this->sideBoardBlue[2][6].setUnitPtr(&blue_scout_3);
    this->sideBoardBlue[2][6].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[2][6].getShape().getPosition().x, this->sideBoardBlue[2][6].getShape().getPosition().y);

    this->blue_scout_4.setRank(SCOUT);
    this->blue_scout_4.setAllegiance(BLUE);
    this->blue_scout_4.initSprite("Textures/2_blue.png");
    this->sideBoardBlue[3][6].setUnitPtr(&blue_scout_4);
    this->sideBoardBlue[3][6].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[3][6].getShape().getPosition().x, this->sideBoardBlue[3][6].getShape().getPosition().y);

    this->blue_scout_5.setRank(SCOUT);
    this->blue_scout_5.setAllegiance(BLUE);
    this->blue_scout_5.initSprite("Textures/2_blue.png");
    this->sideBoardBlue[0][7].setUnitPtr(&blue_scout_5);
    this->sideBoardBlue[0][7].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[0][7].getShape().getPosition().x, this->sideBoardBlue[0][7].getShape().getPosition().y);

    this->blue_scout_6.setRank(SCOUT);
    this->blue_scout_6.setAllegiance(BLUE);
    this->blue_scout_6.initSprite("Textures/2_blue.png");
    this->sideBoardBlue[1][7].setUnitPtr(&blue_scout_6);
    this->sideBoardBlue[1][7].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[1][7].getShape().getPosition().x, this->sideBoardBlue[1][7].getShape().getPosition().y);

    this->blue_scout_7.setRank(SCOUT);
    this->blue_scout_7.setAllegiance(BLUE);
    this->blue_scout_7.initSprite("Textures/2_blue.png");
    this->sideBoardBlue[2][7].setUnitPtr(&blue_scout_7);
    this->sideBoardBlue[2][7].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[2][7].getShape().getPosition().x, this->sideBoardBlue[2][7].getShape().getPosition().y);

    this->blue_scout_8.setRank(SCOUT);
    this->blue_scout_8.setAllegiance(BLUE);
    this->blue_scout_8.initSprite("Textures/2_blue.png");
    this->sideBoardBlue[3][7].setUnitPtr(&blue_scout_8);
    this->sideBoardBlue[3][7].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[3][7].getShape().getPosition().x, this->sideBoardBlue[3][7].getShape().getPosition().y);

    this->blue_spy.setRank(SPY);
    this->blue_spy.setAllegiance(BLUE);
    this->blue_spy.initSprite("Textures/1_blue.png");
    this->sideBoardBlue[0][8].setUnitPtr(&blue_spy);
    this->sideBoardBlue[0][8].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[0][8].getShape().getPosition().x, this->sideBoardBlue[0][8].getShape().getPosition().y);

    this->blue_bomb_1.setRank(BOMB);
    this->blue_bomb_1.setAllegiance(BLUE);
    this->blue_bomb_1.initSprite("Textures/bomb_blue.png");
    this->sideBoardBlue[1][8].setUnitPtr(&blue_bomb_1);
    this->sideBoardBlue[1][8].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[1][8].getShape().getPosition().x, this->sideBoardBlue[1][8].getShape().getPosition().y);

    this->blue_bomb_2.setRank(BOMB);
    this->blue_bomb_2.setAllegiance(BLUE);
    this->blue_bomb_2.initSprite("Textures/bomb_blue.png");
    this->sideBoardBlue[2][8].setUnitPtr(&blue_bomb_2);
    this->sideBoardBlue[2][8].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[2][8].getShape().getPosition().x, this->sideBoardBlue[2][8].getShape().getPosition().y);

    this->blue_bomb_3.setRank(BOMB);
    this->blue_bomb_3.setAllegiance(BLUE);
    this->blue_bomb_3.initSprite("Textures/bomb_blue.png");
    this->sideBoardBlue[3][8].setUnitPtr(&blue_bomb_3);
    this->sideBoardBlue[3][8].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[3][8].getShape().getPosition().x, this->sideBoardBlue[3][8].getShape().getPosition().y);

    this->blue_bomb_4.setRank(BOMB);
    this->blue_bomb_4.setAllegiance(BLUE);
    this->blue_bomb_4.initSprite("Textures/bomb_blue.png");
    this->sideBoardBlue[0][9].setUnitPtr(&blue_bomb_4);
    this->sideBoardBlue[0][9].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[0][9].getShape().getPosition().x, this->sideBoardBlue[0][9].getShape().getPosition().y);

    this->blue_bomb_5.setRank(BOMB);
    this->blue_bomb_5.setAllegiance(BLUE);
    this->blue_bomb_5.initSprite("Textures/bomb_blue.png");
    this->sideBoardBlue[1][9].setUnitPtr(&blue_bomb_5);
    this->sideBoardBlue[1][9].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[1][9].getShape().getPosition().x, this->sideBoardBlue[1][9].getShape().getPosition().y);

    this->blue_bomb_6.setRank(BOMB);
    this->blue_bomb_6.setAllegiance(BLUE);
    this->blue_bomb_6.initSprite("Textures/bomb_blue.png");
    this->sideBoardBlue[2][9].setUnitPtr(&blue_bomb_6);
    this->sideBoardBlue[2][9].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[2][9].getShape().getPosition().x, this->sideBoardBlue[2][9].getShape().getPosition().y);

    this->blue_flag.setRank(FLAG);
    this->blue_flag.setAllegiance(BLUE);
    this->blue_flag.initSprite("Textures/flag_blue.png");
    this->sideBoardBlue[3][9].setUnitPtr(&blue_flag);
    this->sideBoardBlue[3][9].getUnitPtr()->unitSprite.setPosition(this->sideBoardBlue[3][9].getShape().getPosition().x, this->sideBoardBlue[3][9].getShape().getPosition().y);
}

void Game::spawnBlockades()
{
    this->board[2][4].setUnitPtr(&blockades[0]);
    this->board[2][4].getUnitPtr()->unitSprite.setPosition(this->board[2][4].getShape().getPosition().x, this->board[2][4].getShape().getPosition().y);
    this->board[2][4].changeColour(sf::Color::Cyan);

    this->board[3][4].setUnitPtr(&blockades[1]);
    this->board[3][4].getUnitPtr()->unitSprite.setPosition(this->board[3][4].getShape().getPosition().x, this->board[3][4].getShape().getPosition().y);
    this->board[3][4].changeColour(sf::Color::Cyan);

    this->board[2][5].setUnitPtr(&blockades[2]);
    this->board[2][5].getUnitPtr()->unitSprite.setPosition(this->board[2][5].getShape().getPosition().x, this->board[2][5].getShape().getPosition().y);
    this->board[2][5].changeColour(sf::Color::Cyan);

    this->board[3][5].setUnitPtr(&blockades[3]);
    this->board[3][5].getUnitPtr()->unitSprite.setPosition(this->board[3][5].getShape().getPosition().x, this->board[3][5].getShape().getPosition().y);
    this->board[3][5].changeColour(sf::Color::Cyan);

    this->board[6][4].setUnitPtr(&blockades[4]);
    this->board[6][4].getUnitPtr()->unitSprite.setPosition(this->board[6][4].getShape().getPosition().x, this->board[6][4].getShape().getPosition().y);
    this->board[6][4].changeColour(sf::Color::Cyan);

    this->board[7][4].setUnitPtr(&blockades[5]);
    this->board[7][4].getUnitPtr()->unitSprite.setPosition(this->board[7][4].getShape().getPosition().x, this->board[7][4].getShape().getPosition().y);
    this->board[7][4].changeColour(sf::Color::Cyan);

    this->board[6][5].setUnitPtr(&blockades[6]);
    this->board[6][5].getUnitPtr()->unitSprite.setPosition(this->board[6][5].getShape().getPosition().x, this->board[6][5].getShape().getPosition().y);
    this->board[6][5].changeColour(sf::Color::Cyan);

    this->board[7][5].setUnitPtr(&blockades[7]);
    this->board[7][5].getUnitPtr()->unitSprite.setPosition(this->board[7][5].getShape().getPosition().x, this->board[7][5].getShape().getPosition().y);
    this->board[7][5].changeColour(sf::Color::Cyan);
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
    std::cout << "Mouse position: x=" << sf::Mouse::getPosition(*this->window).x << " y=" << sf::Mouse::getPosition(*this->window).y << std::endl;
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    //Relative to the view
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}


//move
void Game::moveUnit(BoardSpace* from, BoardSpace* to) {
    to->setUnitPtr(from->getUnitPtr());
    to->getUnitPtr()->unitSprite.setPosition(to->getShape().getPosition().x, to->getShape().getPosition().y);
    from->setUnitPtr(nullptr);
}

bool Game::validateMove(BoardSpace* from, BoardSpace* to)
{
    if (!this->unitIsSelected || to->getUnitPtr() != nullptr) {
        return false;
    }

    if (from->getX() != to->getX() && from->getY() != to->getY()) {
        return false;
    }

    if (from->getUnitPtr()->getRank() != 2) {
        if (to->getX() == from->getX() - 1 || to->getX() == from->getX() + 1 || to->getY() == from->getY() - 1 || to->getY() == from->getY() + 1) {
            return true;
        }
    }
    else {
        //PUT LOGIC FOR SCOUTS HERE
    }

    return false;
}



void Game::clickLogicDuringGame() {
    //Check if clicking on main board
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        for (int i = 0; i < mainBoardSize; i++) {
            for (int j = 0; j < mainBoardSize; j++) {
                if (this->board[i][j].isClicked(&this->mousePosView)) {
                    //if there is a unit that is not a bomb or flag and other unit not selected yet, store the space
                    if (!this->unitIsSelected && this->board[i][j].getUnitPtr() != nullptr && this->board[i][j].getUnitPtr()->getRank() != BOMB && this->board[i][j].getUnitPtr()->getRank() != FLAG && this->board[i][j].getUnitPtr()->getRank() != BLOCKADE) {
                        this->unitIsSelected = true;
                        this->board[i][j].changeColour(sf::Color::Red);
                        this->selectedSpace = &board[i][j];
                    }
                    else if (this->unitIsSelected) {
                        if (validateMove(this->selectedSpace, &board[i][j])) {
                            moveUnit(this->selectedSpace, &board[i][j]);
                            this->selectedSpace->changeColour(sf::Color::Green);
                            this->selectedSpace = nullptr;
                            this->unitIsSelected = false;
                        }
                    }
                }
            }
        }
    }
}

bool Game::validateSetupMove(BoardSpace* to) {//ONLY ON BOTTOM BOARD
    if (to->getUnitPtr() != nullptr) {
        return false;
    }
    /*
    for (int i = 0; i < this->mainBoardSize; i++)   
    {
        if (to->getY() <= 5)
        {
            return false;
        }
    }*/

    return true;
}

void Game::clickLogicDuringSetup() {
    //Check if clicking on main board
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        for (int i = 0; i < mainBoardSize; i++) {
            for (int j = 0; j < mainBoardSize; j++) {
                if (this->board[i][j].isClicked(&this->mousePosView)) {
                    
                    if (!this->unitIsSelected && this->board[i][j].getUnitPtr() != nullptr && this->board[i][j].getUnitPtr()->getRank() != BLOCKADE) {
                        this->unitIsSelected = true;
                        this->board[i][j].changeColour(sf::Color::Red);
                        this->selectedSpace = &board[i][j];
                    }
                    else if (this->unitIsSelected) {
                        if (validateSetupMove(&board[i][j])) {//new validate function
                            moveUnit(this->selectedSpace, &board[i][j]);
                            this->selectedSpace->changeColour(sf::Color::Green);
                            this->selectedSpace = nullptr;
                            this->unitIsSelected = false;
                        }
                    }
                }
            }
        }
    }

    //Check if clicking on side board
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        for (int i = 0; i < sideBoardHeight; i++) {
            for (int j = 0; j < sideBoardWidth; j++) {
                if (this->sideBoardBlue[j][i].isClicked(&this->mousePosView)) {
                    
                    if (!this->unitIsSelected && this->sideBoardBlue[j][i].getUnitPtr() != nullptr) {
                        this->unitIsSelected = true;
                        this->sideBoardBlue[j][i].changeColour(sf::Color::Red);
                        this->selectedSpace = &sideBoardBlue[j][i];
                    }
                    else if (this->unitIsSelected) {
                        if (validateSetupMove(&sideBoardBlue[j][i])) {
                            moveUnit(this->selectedSpace, &sideBoardBlue[j][i]);
                            this->selectedSpace->changeColour(sf::Color::Green);
                            this->selectedSpace = nullptr;
                            this->unitIsSelected = false;
                        }
                    }
                }
            }
        }
    }
}



void Game::renderBoard()
{
    for (int i = 0; i < mainBoardSize; i++) {
        for (int j = 0; j < mainBoardSize; j++){
            //Draw space{
            this->window->draw(this->board[j][i].getShape());
            //Draw unit on space if there is one
            if (this->board[j][i].getUnitPtr() != nullptr) {
                this->window->draw(this->board[j][i].getUnitPtr()->unitSprite);
            }
        }
    }
}

void Game::renderSideBoards()
{
    for (int i = 0; i < sideBoardHeight; i++) {
        for (int j = 0; j < sideBoardWidth; j++) {
            //Draw space
            this->window->draw(this->sideBoardBlue[j][i].getShape());
            //Draw unit on space
            if (this->sideBoardBlue[j][i].getUnitPtr() != nullptr) {
                this->window->draw(this->sideBoardBlue[j][i].getUnitPtr()->unitSprite);
            }
        }
    }
}



void Game::update()
{
    this->pollEvents();
    this->updateMousePosition();
    if (setupTime) {
        this->clickLogicDuringSetup();
    }
    else {
        this->clickLogicDuringGame();
    }
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