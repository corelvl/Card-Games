#pragma once
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <random>
#include <string>
using namespace std;



void cmdc(int color) { //Cmd color (Windows)
#ifdef _WIN32
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#elif __linux__
	//Implement linux colors here for cmd
	//Example:
	//Common Colors:
		//30 - Black
		//31 - Red
		//32 - Green
		//33 - Yellow
		//34 - Blue
		//35 - Magenta
		//36 - Cyan
		//37 - White
		//39 - Default(reset)
		//example std::cout << "\033[1;33mThis is bold yellow text\033[0m" << std::endl;
#endif
}

void cls() {
#ifdef _WIN32
	system("cls");
#elif __linux__
	system("clear");
#endif

}

void inputfail() {
		cin.clear(); //Gotta be called first
		cin.ignore(1000, '\n');
		

		cout << "Input has to be a number!\n";
		cout << "Getting back in 3 seconds....\n";
		this_thread::sleep_for(chrono::seconds(3));
}


