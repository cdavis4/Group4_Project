class Board
{
	private:
	Critter ***boardArray;
	
	public:
	Board(int row, int column);
	friend class Critter;
	friend class Ant;
	friend class Doodlebug;
};
