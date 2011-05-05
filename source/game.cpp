#include "game.h"

Game::Game(int bg) {
	s_bg = bg;
	
	s_player = new Player;
	s_level1 = new Level(&map1, bg, 1);
	
	Enemy* enemy1 = new Enemy(1, 216, 176, 1, 0);
	Enemy* enemy2 = new Enemy(2, 128, 64, 0, 1);
	
	int nbEnemies = 2;
	Enemy* s_enemies[] = {
		enemy1,
		enemy2
	};
	
	s_player->setLevel(s_level1);
	
	int i;
	for(i = 0 ; i < nbEnemies ; i++) {
		s_enemies[i]->setLevel(s_level1);
	}
	
	s_level1->setEnemies(s_enemies, nbEnemies);
	
	s_level1->setGame(this);
}

Game::Game(int bg, Player* player, Level* level1) {
	s_bg = bg;

	s_player = player;
	s_level1 = level1;
	s_enemies = s_level1->enemies();
}

Game::~Game() {
}

void Game::displayHUD() {
	iprintf("\x1b[1;1HLifes: %i", s_player->lifesRemaining());
	iprintf("\x1b[3;1HPosition: %i/%i", (s_player->x() + s_level1->x())/8, s_level1->length()); // TODO: Maybe a minimap will coming here..
	iprintf("\x1b[5;1HLevel: %i", s_level1->id());
}

void Game::update() {
	while(1) {
		swiWaitForVBlank();
		
		scanKeys();
		
		s_frame++;
		
		displayHUD();
		
		s_player->move();
		s_player->draw();
		
		int i;
		for(i = 0 ; i < s_level1->nbEnemies() ; i++) {
			s_enemies[i]->move();
			s_enemies[i]->draw();
		}
		
		bgUpdate();
		oamUpdate(&oamMain);
	}
}
