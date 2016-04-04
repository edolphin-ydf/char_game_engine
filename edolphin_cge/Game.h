#ifndef _GAME_H_
#define _GAME_H_ 

class Game {
public:
	void init();
	void main();

private:
	void draw();


private:
	volatile bool finished;
};

#endif /* ifndef _GAME_H_ */
