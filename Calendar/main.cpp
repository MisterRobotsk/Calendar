#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include "unistd.h"
//#include "windows.h"

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

time_t now = time(&now);
tm *ltm = localtime(&now);

int main()
{	
	int Choice_Data;
	
	std::cout << "██╗░░░██╗██╗███████╗░██╗░░░░░░░██╗  ██████╗░░█████╗░████████╗░█████╗░\n";
	std::cout << "██║░░░██║██║██╔════╝░██║░░██╗░░██║  ██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗\n";
	std::cout << "╚██╗░██╔╝██║█████╗░░░╚██╗████╗██╔╝  ██║░░██║███████║░░░██║░░░███████║\n";
	std::cout << "░╚████╔╝░██║██╔══╝░░░░████╔═████║░  ██║░░██║██╔══██║░░░██║░░░██╔══██║\n";
	std::cout << "░░╚██╔╝░░██║███████╗░░╚██╔╝░╚██╔╝░  ██████╔╝██║░░██║░░░██║░░░██║░░██║\n";
	std::cout << "░░░╚═╝░░░╚═╝╚══════╝░░░╚═╝░░░╚═╝░░  ╚═════╝░╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝\n";
	
	std::cout << "Enter number for choice module:\n\nClassic Time  DD//MM//YYYY[1]\nAmerican Time MM//DD//YYYY[2]\nClock[3]\n\nEixt...[4]\n\nInput: ";
	
	while(!(cin >> Choice_Data) || (cin.peek() != '\n'))
	{
		cin.clear();

		while(cin.get() != '\n');
			cerr << "Incorrect input\n";
	}

	if(Choice_Data == 1)
	{
		cout << ltm -> tm_mday << "/" << 1 + ltm -> tm_mon << "/" << 1900 + ltm -> tm_year << endl;
	}

	else if(Choice_Data == 2)
	{
		cout << 1 + ltm -> tm_mon << "/" << ltm -> tm_mday << "/" << 1900 + ltm -> tm_year << endl;	
	}

	else if(Choice_Data == 3)
	{
		while(true)
		{
			auto now = std::chrono::system_clock::now();
        	time_t time_now = std::chrono::system_clock::to_time_t(now);
        
        	cout << ctime(&time_now);
        		std::this_thread::sleep_for(std::chrono::seconds(1));
				system("clear");
		}	
	}

	else cout << "Exit...\n";
	
	return 0;
}
