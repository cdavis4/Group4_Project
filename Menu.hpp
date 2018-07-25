#ifndef MENU_HPP
#define MENU_HPP



class Menu 
{
	
	private:
		std::string userInput;
		int question;
		int maxAnt;
		int maxDoodle;
		
	
	public:
		Menu();
		void mainMenu();
		int inputVal();


};
#endif // MENU_HPP