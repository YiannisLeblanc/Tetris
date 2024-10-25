#ifndef SQUARE_H
#define SQUARE_H

class Square {
private:
	int x;
	int y;
public:
	int getX() const;
	int getY() const;
	void set(int x, int y);
	void setX(int x);
	void setY(int y);
	void move(int deltaX, int deltaY);
	void moveX(int deltaX);
	void moveY(int deltaY);
	Square(int x, int y);
	Square();
	Square& operator=(const Square& square);
	Square operator+(const Square square) const;
	Square operator-(const Square square) const;
	Square& operator+=(const Square square);
	Square& operator-=(const Square square);

};

#endif