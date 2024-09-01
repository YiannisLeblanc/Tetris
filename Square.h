#pragma once
class Square {
private:
	int x;
	int y;
public:
	int getX();
	int getY();
	void set(int x, int y);
	void setX(int x);
	void setY(int y);
	void move(int deltaX, int deltaY);
	void moveX(int deltaX);
	void moveY(int deltaY);
};
