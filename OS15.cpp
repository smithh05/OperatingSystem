#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <ftw.h>
#include <sys/stat.h>
#include <cassert>

//The Command Class defines the interface for executing a command
class Command
{
	public:
		virtual void execute() = 0;
};

//The Reciever Class does the actual work. All of the commands' functionality are contained in here
class Reciever
{
	public:
		Reciever()
		{
			
		}
		//Displays the current OS version
		void version()
		{
			std::cout << "SmithOS Version 1.5" << std::endl;
		}
		//Displays the current date and time the command is invoked
		void date()
		{
			time_t date = time(0);
			struct tm* currentTime = localtime(&date);
				if((currentTime->tm_mon + 1) == 1)
				{
					std::cout << "January ";
				}
				else if((currentTime->tm_mon + 1) == 2)
				{
					std::cout << "Feburary ";
				}
				else if((currentTime->tm_mon + 1) == 3)
				{
					std::cout << "March ";
				}
				else if((currentTime->tm_mon + 1) == 4)
				{
					std::cout << "April ";
				}
				else if((currentTime->tm_mon + 1) == 5)
				{
					std::cout << "May ";
				}
				else if((currentTime->tm_mon + 1) == 6)
				{
					std::cout << "June ";
				}
				else if((currentTime->tm_mon + 1) == 7)
				{
					std::cout << "July ";
				}
				else if((currentTime->tm_mon + 1) == 8)
				{
					std::cout << "August ";
				}
				else if((currentTime->tm_mon + 1) == 9)
				{
					std::cout << "September ";
				}
				else if((currentTime->tm_mon + 1) == 10)
				{
					std::cout << "October ";
				}
				else if((currentTime->tm_mon + 1) == 11)
				{
					std::cout << "November ";
				}
				else if((currentTime->tm_mon + 1) == 12)
				{
					std::cout << "December ";
				}
				std::cout << currentTime->tm_mday << ", " << (currentTime->tm_year + 1900) << ' ' << currentTime->tm_hour << ':'<< currentTime->tm_min << std::endl;
		}
		//dir actually displays the files in the current directory based on the file tree walk
		static int dir(const char *path, const struct stat *st, int flags)
		{
			std::cout << path << std::endl;
			return 0;
		}
		//directory executes the file tree walk function, which calls dir
		void directory()
		{
			ftw(".", dir, 1);
		}
		//exitSystem handles the procedures to shut the OS down
		void exitSystem()
		{
			std::string input;
			bool flag = 1;
			while (flag == 1)
			{	//Confirm if the user actually wants to shut down
				std::cout << "Are you sure you want to shut down? Type 'yes' if so or 'no' if not: " << std::endl;
				std::cin >> input;
				if(input == "yes")
				{
					std::system("clear");
					std::cout << "Exiting the OS. Have a nice day!" << std::endl;
					flag = 0;
					exit(0);
				}
				else if (input == "no")
				{
					std::system("clear");
					std::cout << "Returning back to system..." << std::endl;
					flag = 0;
				}
				else
				{
					std::system("clear");
					std::cout << "Invalid choice. Please try again." << std::endl;
				}
			}
		}
		//Displays help information of each available command. Each command has its own help file.
		void help()
		{
			bool help = 1;
			do
			{
				
				std::string line;
				std::ifstream file("helpmain.txt");
				if(file.is_open())
				{
					while(getline(file, line))
					{
						std::cout << line << std::endl;
					}
				}
				file.close();
				std::string choice;
				std::cin >> choice;
				if(choice == "version")
				{
					std::system("clear");
					std::ifstream file("version.txt");
					if(file.is_open())
					{
						while(getline(file, line))
						{
							std::cout << line << std::endl;
						}
					}
					file.close();
					help = 0;
				}
				else if(choice == "date")
				{
					std::system("clear");
					std::ifstream file("date.txt");
					if(file.is_open())
					{
						while(getline(file, line))
						{
							std::cout << line << std::endl;
						}
					}
					file.close();
					help = 0;
				}
				else if(choice == "directory")
				{
					std::system("clear");
					std::ifstream file("directory.txt");
					if(file.is_open())
					{
						while(getline(file, line))
						{
							std::cout << line << std::endl;
						}
					}
					file.close();
					help = 0;
				}
				else if(choice == "exit")
				{
					std::system("clear");
					std::ifstream file("exit.txt");
					if(file.is_open())
					{
						while(getline(file, line))
						{
							std::cout << line << std::endl;
						}
					}
					file.close();
					help = 0;
				}
				else if(choice == "help")
				{
					std::system("clear");
					std::ifstream file("help.txt");
					if(file.is_open())
					{
						while(getline(file, line))
						{
							std::cout << line << std::endl;
						}
					}
					file.close();
					help = 0;
				}
				else
				{
					std::system("clear");
					std::cout << "Invalid choice! Try again!" << std::endl;
				}
			} while(help == 1);
			
			//return 0;
		}
};

//SeeVersion, SeeDate, SeeDirectory, ExitSystem, and SeeHelp are concrete command classes.
//They implement the execute method by invoking commands on the Reciever class.
class SeeVersion : public Command
{
	Reciever* seeVersion;
	
	public:
		SeeVersion(Reciever* seeVersion)
		{
			this->seeVersion = seeVersion;
		}
		
		void execute()
		{
			seeVersion->version();
			//return 0;
		}
};

class SeeDate : public Command
{
	Reciever* seeDate;
	
	public:
		SeeDate(Reciever* seeDate)
		{
			this->seeDate = seeDate;
		}
		
		void execute()
		{
			seeDate->date();
			//return 0;
		}
};

class SeeDirectory : public Command
{
	Reciever* seeDirectory;
	
	public:
		SeeDirectory(Reciever* seeDirectory)
		{
			this->seeDirectory = seeDirectory;
		}
		
		void execute()
		{
			seeDirectory->directory();
			//return 0;
		}
};

class ExitSystem : public Command
{
	Reciever* exitOS;
	
	public:
		ExitSystem(Reciever* exitOS)
		{
			this->exitOS = exitOS;
		}
		
		void execute()
		{
			exitOS->exitSystem();
			//return 0;
		}
};

class SeeHelp : public Command
{
	Reciever* seeHelp;
	
	public:
		SeeHelp(Reciever* seeHelp)
		{
			this->seeHelp = seeHelp;
		}
		
		void execute()
		{
			seeHelp->help();
			//return 0;
		}
};

//The Invoker Class basically initiates the command. It passes the information to the Reciever and keeps a history of past commands.
class Invoker
{
	public:
		Invoker()
		{
			
		}
		void invoke(Command* command)
		{
			commandList.push_back(command);
			command->execute();
			//return 0;
		}
	private:
		std::vector<Command*> commandList;
};

//displayMenu just displays the main menu of the operating system
void displayMenu()
{
	Reciever* reciever = new Reciever();
	bool run = 1;
	std::cout << "Welcome to the OS! To get started, select an option from the following menu: " << std::endl;
	do
	{
		std::cout << "Enter 'version' to show the current OS version" << std::endl;
		std::cout << "Enter 'date' to show the current date" << std::endl;
		std::cout << "Enter 'directory' to display a list of files on the OS" << std::endl;
		std::cout << "Enter 'exit' to exit the OS" << std::endl;
		std::cout << "Enter 'help' to get help on these commands" << std::endl;
		std::cout << "Enter 'test' to test the functionality of the system" << std::endl;
		std::string option;
		std::cin >> option;
		//Check option input. Each option passes the command to the invoker to initiate execution.
		if(option == "version")
		{
			std::system("clear");
			SeeVersion* version = new SeeVersion(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(version);
		}
		else if(option == "date")
		{
			std::system("clear");
			SeeDate* date = new SeeDate(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(date);
		}
		else if(option == "directory")
		{
			std::system("clear");
			SeeDirectory* directory = new SeeDirectory(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(directory);
		}
		else if(option == "exit")
		{
			std::system("clear");
			ExitSystem* exit = new ExitSystem(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(exit);
		}
		else if(option == "help")
		{
			std::system("clear");
			SeeHelp* help = new SeeHelp(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(help);
		}
		else
		{
			std::system("clear");
			std::cout << "Invalid option. Please try again!" << std::endl;
		}
		
	} while (run == 1);	
}

int main()
{	
	displayMenu();
	return 0;
}
