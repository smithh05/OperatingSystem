#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <ftw.h>
#include <sys/stat.h>
#include <cassert>
#include "PCB.h"

PCBClass* pcb = new PCBClass;

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
			std::cout << "SmithOS Version 3.0" << std::endl;
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
				/*else if(choice == "createpcb")
				{
					std::system("clear");
					std::ifstream file("createpcb.txt");
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
				else if(choice == "deletepcb")
				{
					std::system("clear");
					std::ifstream file("deletepcb.txt");
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
				else if(choice == "block")
				{
					std::system("clear");
					std::ifstream file("block.txt");
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
				else if(choice == "unblock")
				{
					std::system("clear");
					std::ifstream file("unblock.txt");
					if(file.is_open())
					{
						while(getline(file, line))
						{
							std::cout << line << std::endl;
						}
					}
					file.close();
					help = 0;
				}*/
				else if(choice == "suspend")
				{
					std::system("clear");
					std::ifstream file("suspend.txt");
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
				else if(choice == "resume")
				{
					std::system("clear");
					std::ifstream file("resume.txt");
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
				else if(choice == "showpcb")
				{
					std::system("clear");
					std::ifstream file("showpcb.txt");
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
				else if(choice == "showall")
				{
					std::system("clear");
					std::ifstream file("showall.txt");
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
				else if(choice == "showready")
				{
					std::system("clear");
					std::ifstream file("showready.txt");
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
				else if(choice == "showblocked")
				{
					std::system("clear");
					std::ifstream file("showblocked.txt");
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
				else if(choice == "setpriority")
				{
					std::system("clear");
					std::ifstream file("setpriority.txt");
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
		
		/*void CreatePCBR(PCBClass* pcb)
		{
			//PCBClass* pcb = new PCBClass;
			pcb->CreatePCB();
		}
		
		void DeletePCBR(PCBClass* pcb)
		{
			pcb->DeletePCB();
		}
		
		void BlockR(PCBClass* pcb)
		{
			pcb->Block();
		}
		
		void UnBlockR(PCBClass* pcb)
		{
			pcb->Unblock();
		}*/
		
		void SuspendR(PCBClass* pcb)
		{
			pcb->Suspend();
		}
		
		void ResumeR(PCBClass* pcb)
		{
			pcb->Resume();
		}
		
		void SetPriorityR(PCBClass* pcb)
		{
			pcb->SetPriority();
		}
		
		void ShowPCBR(PCBClass* pcb)
		{
			pcb->ShowPCB();
		}
		
		void ShowAllR(PCBClass* pcb)
		{
			//PCBClass* pcb = new PCBClass;
			pcb->ShowAll();
		}
		
		void ShowReadyR(PCBClass* pcb)
		{
			pcb->ShowReady();
		}
		
		void ShowBlockedR(PCBClass* pcb)
		{
			pcb->ShowBlocked();
		}
		
		
		static bool Compare(const PCB* left, const PCB* right)
		{
			return left->timeRemaining < right->timeRemaining;
		}
	
		void SJF(PCBClass* pcb)
		{
			std::vector<PCB*> PCBList; //Used to hold PCBs for sorting
			std::string line;
			std::ifstream file("test.txt");
				if(file.is_open())
				{
					while(getline(file, line))
					{
						//std::cout << line << std::endl;
						std::istringstream buf(line);
						std::istream_iterator<std::string> beg(buf), end;
						//The following lines split the file lines into different variables for processing into PCBs
						std::vector<std::string> tokens(beg, end);
						std::string processName = tokens[0];
						std::string procClass = tokens[1];
						char processClass1 = procClass[0];
						int processClass;
						if(processClass1 == 'A')
						{
							processClass = 0;
						}
						else if(processClass1 == 'S')
						{
							processClass = 1;
						}
						int processPriority = std::stoi(tokens[2]);
						int processMemory = std::stoi(tokens[3]);
						int timeRemaining = std::stoi(tokens[4]);
						int timeOfArrival = std::stoi(tokens[5]);
						int percentageOfCPU = std::stoi(tokens[6]);
						
						PCB* newPCB = pcb->SetupPCB(processName, processPriority, processClass, processMemory, timeRemaining, timeOfArrival, percentageOfCPU);
						PCBList.push_back(newPCB);
						std::sort(PCBList.begin(), PCBList.end(), Compare); //Sort PCBs in PCBList by time remaining
					}
					//Used to insert PCBs to the ready queue in correct order
					for(const PCB* newPCB : PCBList)
					{
						pcb->InsertPCB(PCBList[0]);
						PCBList.erase(std::remove(PCBList.begin(), PCBList.end(), PCBList[0]), PCBList.end());
					}
					std::deque<PCB*>::iterator itr;
					int totalTime = 0; //Total time to completion
					int sum = 0; //Sum of times
					int processCount = 0; //Process counter
					std::vector<int> sumOfTimes; //Cascading sum of times
					//keeps track of # of processes, the total time to completion and the sum of times
					for(itr = pcb->ReadyQueue.begin(); itr != pcb->ReadyQueue.end(); ++itr)
					{
						processCount++;
						totalTime = totalTime + (*itr)->timeRemaining;
						sum = sum + (*itr)->timeRemaining;
						sumOfTimes.push_back(sum);
						//std::cout << sum << std::endl;
					}
					int sum2 = 0; //These are used to calculate turnaround time
					for(int n : sumOfTimes)
					{
						sum2 = sum2 + n;
					}
					
					std::cout << "CURRENT READY QUEUE" << std::endl;
					pcb->ShowReady(); //Show the current ready queue
					std::ofstream outputFile;
					outputFile.open (("SJF.txt"), std::ofstream::out | std::ofstream::app);
					//Dispatch the processes to "running" in the correct order
					for(itr = pcb->ReadyQueue.begin(); itr != pcb->ReadyQueue.end(); ++itr)
					{
						
						outputFile << (*itr)->processName << " entered system!" << std::endl;
						(*itr)->processState1 = "running";
						outputFile << (*itr)->processName << " changed state to " << (*itr)->processState1 << "!" << std::endl;
						outputFile << "SJF Completed: " << (*itr)->processName << std::endl;
						pcb->ReadyQueue.pop_front();
					}
					outputFile.close();
					pcb->ShowReady();
					std::cout << "Total time to completion: " << totalTime << std::endl;
					int turnaroundTime = sum2 / processCount;
					std::cout << "Average turnaround time: " << turnaroundTime << std::endl;
				}
				file.close();
		}
		
		void FIFO(PCBClass* pcb)
		{
			std::vector<PCB*> PCBList; //Used to hold PCBs
			std::string line;
			std::ifstream file("test.txt");
				if(file.is_open())
				{
					while(getline(file, line))
					{
						//std::cout << line << std::endl;
						std::istringstream buf(line);
						std::istream_iterator<std::string> beg(buf), end;
						//The following lines split the file lines into different variables for processing into PCBs
						std::vector<std::string> tokens(beg, end);
						std::string processName = tokens[0];
						std::string procClass = tokens[1];
						char processClass1 = procClass[0];
						int processClass;
						if(processClass1 == 'A')
						{
							processClass = 0;
						}
						else if(processClass1 == 'S')
						{
							processClass = 1;
						}
						int processPriority = std::stoi(tokens[2]);
						int processMemory = std::stoi(tokens[3]);
						int timeRemaining = std::stoi(tokens[4]);
						int timeOfArrival = std::stoi(tokens[5]);
						int percentageOfCPU = std::stoi(tokens[6]);
						
						PCB* newPCB = pcb->SetupPCB(processName, processPriority, processClass, processMemory, timeRemaining, timeOfArrival, percentageOfCPU);
						PCBList.push_back(newPCB);
					}
					//Used to insert PCBs to the ready queue in correct order
					for(const PCB* newPCB : PCBList)
					{
						pcb->InsertPCB(PCBList[0]);
						PCBList.erase(std::remove(PCBList.begin(), PCBList.end(), PCBList[0]), PCBList.end());
					}
					std::deque<PCB*>::iterator itr;
					int totalTime = 0; //Total time to completion
					int sum = 0; //Sum of times
					int processCount = 0; //Process counter
					std::vector<int> sumOfTimes; //Cascading sum of times
					//keeps track of # of processes, the total time to completion and the sum of times
					for(itr = pcb->ReadyQueue.begin(); itr != pcb->ReadyQueue.end(); ++itr)
					{
						processCount++;
						totalTime = totalTime + (*itr)->timeRemaining;
						sum = sum + (*itr)->timeRemaining;
						sumOfTimes.push_back(sum);
						//std::cout << sum << std::endl;
					}
					int sum2 = 0; //These are used to calculate turnaround time
					for(int n : sumOfTimes)
					{
						sum2 = sum2 + n;
					}
					
					std::cout << "CURRENT READY QUEUE" << std::endl;
					pcb->ShowReady(); //Show the current ready queue
					std::ofstream outputFile;
					outputFile.open (("FIFO.txt"), std::ofstream::out | std::ofstream::app);
					//Dispatch the processes to "running" in the correct order
					for(itr = pcb->ReadyQueue.begin(); itr != pcb->ReadyQueue.end(); ++itr)
					{
						outputFile << (*itr)->processName << " entered system!" << std::endl;
						(*itr)->processState1 = "running";
						outputFile << (*itr)->processName << " changed state to " << (*itr)->processState1 << "!" << std::endl;
						outputFile << "FIFO Completed: " << (*itr)->processName << std::endl;
						pcb->ReadyQueue.pop_front();
					}
					outputFile.close();
					pcb->ShowReady();
					std::cout << "Total time to completion: " << totalTime << std::endl;
					int turnaroundTime = sum2 / processCount;
					std::cout << "Average turnaround time: " << turnaroundTime << std::endl;
				}
				file.close();
		}
		
		void STCF(PCBClass* pcb)
		{
			std::vector<PCB*> PCBList; //Used to hold PCBs for sorting
			std::string line;
			std::ifstream file("test.txt");
				if(file.is_open())
				{
					while(getline(file, line))
					{
						//std::cout << line << std::endl;
						std::istringstream buf(line);
						std::istream_iterator<std::string> beg(buf), end;
						//The following lines split the file lines into different variables for processing into PCBs
						std::vector<std::string> tokens(beg, end);
						std::string processName = tokens[0];
						std::string procClass = tokens[1];
						char processClass1 = procClass[0];
						int processClass;
						if(processClass1 == 'A')
						{
							processClass = 0;
						}
						else if(processClass1 == 'S')
						{
							processClass = 1;
						}
						int processPriority = std::stoi(tokens[2]);
						int processMemory = std::stoi(tokens[3]);
						int timeRemaining = std::stoi(tokens[4]);
						int timeOfArrival = std::stoi(tokens[5]);
						int percentageOfCPU = std::stoi(tokens[6]);
						
						PCB* newPCB = pcb->SetupPCB(processName, processPriority, processClass, processMemory, timeRemaining, timeOfArrival, percentageOfCPU);
						PCBList.push_back(newPCB);
						//std::sort(PCBList.begin(), PCBList.end(), Compare); //Sort PCBs in PCBList by time remaining
					}
					//Used to insert PCBs to the ready queue in correct order
					for(const PCB* newPCB : PCBList)
					{
						pcb->InsertPCB(PCBList[0]);
						PCBList.erase(std::remove(PCBList.begin(), PCBList.end(), PCBList[0]), PCBList.end());
					}
					std::deque<PCB*>::iterator itr;
					int totalTime = 0; //Total time to completion
					int sum = 0; //Sum of times
					int processCount = 0; //Process counter
					std::vector<int> sumOfTimes; //Cascading sum of times
					//keeps track of # of processes, the total time to completion and the sum of times
					for(itr = pcb->ReadyQueue.begin(); itr != pcb->ReadyQueue.end(); ++itr)
					{
						processCount++;
						totalTime = totalTime + (*itr)->timeRemaining;
						sum = sum + (*itr)->timeRemaining;
						sumOfTimes.push_back(sum);
						//std::cout << sum << std::endl;
					}
					int sum2 = 0; //These are used to calculate turnaround time
					for(int n : sumOfTimes)
					{
						sum2 = sum2 + n;
					}
					
					std::cout << "CURRENT READY QUEUE" << std::endl;
					pcb->ShowReady(); //Show the current ready queue
					std::ofstream outputFile;
					outputFile.open (("STCF.txt"), std::ofstream::out | std::ofstream::app);
					//Dispatch the processes to "running" in the correct order
					for(unsigned int i = 0; i < pcb->ReadyQueue.size(); ++i)
					{
						
						outputFile << pcb->ReadyQueue[i]->processName << " entered system!" << std::endl;
						pcb->ReadyQueue[i]->processState1 = "running";
						outputFile << pcb->ReadyQueue[i]->processName << " changed state to " << pcb->ReadyQueue[i]->processState1 << "!" << std::endl;
						
							if(pcb->ReadyQueue[i]->timeRemaining > pcb->ReadyQueue[i+1]->timeRemaining && pcb->ReadyQueue[i]->timeRemaining != 0 && pcb->ReadyQueue[i+1]->timeRemaining != 0)
							{
								outputFile << pcb->ReadyQueue[i+1]->processName << " preempted!" << std::endl;
								pcb->ReadyQueue[i+1]->processState1 = "running";
								outputFile << pcb->ReadyQueue[i+1]->processName << " changed state to " << pcb->ReadyQueue[i+1]->processState1 << "!" << std::endl;
								pcb->ReadyQueue[i]->processState1 = "ready";
								outputFile << pcb->ReadyQueue[i]->processName << " changed state to " << pcb->ReadyQueue[i]->processState1 << "!" << std::endl;
								pcb->ReadyQueue[i]->timeRemaining -= pcb->ReadyQueue[i+1]->timeOfArrival;
								outputFile << "STCF Completed: " << pcb->ReadyQueue[i+1]->processName << std::endl;
								pcb->ReadyQueue[i+1]->timeRemaining = 0;
								i++;
							}
						
						if(pcb->ReadyQueue[i-1]->timeRemaining != 0)
						{
							pcb->ReadyQueue[i-1]->processState1 = "running";
							outputFile << pcb->ReadyQueue[i-1]->processName << " changed state to " << pcb->ReadyQueue[i-1]->processState1 << "!" << std::endl;
							outputFile << "STCF Completed: " << pcb->ReadyQueue[i-1]->processName << std::endl;
						}
						//pcb->ReadyQueue.pop_front();
					}
					std::cout << std::endl;
					pcb->ShowReady();
					outputFile.close();
					pcb->ReadyQueue.clear();
					std::cout << "Total time to completion: " << totalTime << std::endl;
					int turnaroundTime = sum2 / processCount;
					std::cout << "Average turnaround time: " << turnaroundTime << std::endl;
				}
				file.close();
		}
		
		void RR(PCBClass* pcb)
		{
			std::vector<PCB*> PCBList; //Used to hold PCBs for sorting
			std::string line;
			std::ifstream file("test.txt");
				if(file.is_open())
				{
					while(getline(file, line))
					{
						//std::cout << line << std::endl;
						std::istringstream buf(line);
						std::istream_iterator<std::string> beg(buf), end;
						//The following lines split the file lines into different variables for processing into PCBs
						std::vector<std::string> tokens(beg, end);
						std::string processName = tokens[0];
						std::string procClass = tokens[1];
						char processClass1 = procClass[0];
						int processClass;
						if(processClass1 == 'A')
						{
							processClass = 0;
						}
						else if(processClass1 == 'S')
						{
							processClass = 1;
						}
						int processPriority = std::stoi(tokens[2]);
						int processMemory = std::stoi(tokens[3]);
						int timeRemaining = std::stoi(tokens[4]);
						int timeOfArrival = std::stoi(tokens[5]);
						int percentageOfCPU = std::stoi(tokens[6]);
						
						PCB* newPCB = pcb->SetupPCB(processName, processPriority, processClass, processMemory, timeRemaining, timeOfArrival, percentageOfCPU);
						PCBList.push_back(newPCB);
						//std::sort(PCBList.begin(), PCBList.end(), Compare); //Sort PCBs in PCBList by time remaining
					}
					//Used to insert PCBs to the ready queue in correct order
					for(const PCB* newPCB : PCBList)
					{
						pcb->InsertPCB(PCBList[0]);
						PCBList.erase(std::remove(PCBList.begin(), PCBList.end(), PCBList[0]), PCBList.end());
					}
					std::deque<PCB*>::iterator itr;
					int totalTime = 0; //Total time to completion
					int sum = 0; //Sum of times
					int processCount = 0; //Process counter
					std::vector<int> sumOfTimes; //Cascading sum of times
					//keeps track of # of processes, the total time to completion and the sum of times
					for(itr = pcb->ReadyQueue.begin(); itr != pcb->ReadyQueue.end(); ++itr)
					{
						processCount++;
						totalTime = totalTime + (*itr)->timeRemaining;
						sum = sum + (*itr)->timeRemaining;
						sumOfTimes.push_back(sum);
						//std::cout << sum << std::endl;
					}
					int sum2 = 0; //These are used to calculate turnaround time
					for(int n : sumOfTimes)
					{
						sum2 = sum2 + n;
					}
					
					std::cout << "CURRENT READY QUEUE" << std::endl;
					pcb->ShowReady(); //Show the current ready queue
					std::ofstream outputFile;
					outputFile.open (("RR.txt"), std::ofstream::out | std::ofstream::app);
					int timeQuantum = 0;
					std::cout << "Please enter the time quantum: " << std::endl;
					std::cin >> timeQuantum;
					//Dispatch the processes to "running" in the correct order
					for(int i = 0; i < timeQuantum; ++i)
					{
						for(unsigned int j = 0; j < pcb->ReadyQueue.size(); ++j)
						{
							if(pcb->ReadyQueue[j]->timeRemaining > 0)
							{
								pcb->ReadyQueue[j]->timeRemaining -= timeQuantum;
								pcb->ReadyQueue[j]->processState1 = "running";
								outputFile << pcb->ReadyQueue[j]->processName << " changed state to " << pcb->ReadyQueue[j]->processState1 << "!" << std::endl;
							}
							else if(pcb->ReadyQueue[j]->timeRemaining <= 0)
							{
								PCB* finishedProcess;
								outputFile << "RR Completed: " << pcb->ReadyQueue[j]->processName << std::endl;
								finishedProcess = pcb->FindPCB(pcb->ReadyQueue[j]->processName);
								pcb->RemovePCB(finishedProcess);
							}
						}
					}
					std::cout << std::endl;
					pcb->ShowReady();
					outputFile.close();
					pcb->ReadyQueue.clear();
					std::cout << "Total time to completion: " << totalTime << std::endl;
					int turnaroundTime = sum2 / processCount;
					std::cout << "Average turnaround time: " << turnaroundTime << std::endl;
				}
				file.close();
		}
		
		void FPPS(PCBClass* pcb)
		{
			std::vector<PCB*> PCBList; //Used to hold PCBs for sorting
			std::string line;
			std::ifstream file("test.txt");
				if(file.is_open())
				{
					while(getline(file, line))
					{
						//std::cout << line << std::endl;
						std::istringstream buf(line);
						std::istream_iterator<std::string> beg(buf), end;
						//The following lines split the file lines into different variables for processing into PCBs
						std::vector<std::string> tokens(beg, end);
						std::string processName = tokens[0];
						std::string procClass = tokens[1];
						char processClass1 = procClass[0];
						int processClass;
						if(processClass1 == 'A')
						{
							processClass = 0;
						}
						else if(processClass1 == 'S')
						{
							processClass = 1;
						}
						int processPriority = std::stoi(tokens[2]);
						int processMemory = std::stoi(tokens[3]);
						int timeRemaining = std::stoi(tokens[4]);
						int timeOfArrival = std::stoi(tokens[5]);
						int percentageOfCPU = std::stoi(tokens[6]);
						
						PCB* newPCB = pcb->SetupPCB(processName, processPriority, processClass, processMemory, timeRemaining, timeOfArrival, percentageOfCPU);
						PCBList.push_back(newPCB);
						//std::sort(PCBList.begin(), PCBList.end(), Compare); //Sort PCBs in PCBList by time remaining
					}
					//Used to insert PCBs to the ready queue in correct order
					for(const PCB* newPCB : PCBList)
					{
						pcb->InsertPCB(PCBList[0]);
						PCBList.erase(std::remove(PCBList.begin(), PCBList.end(), PCBList[0]), PCBList.end());
					}
					std::deque<PCB*>::iterator itr;
					int totalTime = 0; //Total time to completion
					int sum = 0; //Sum of times
					int processCount = 0; //Process counter
					std::vector<int> sumOfTimes; //Cascading sum of times
					//keeps track of # of processes, the total time to completion and the sum of times
					for(itr = pcb->ReadyQueue.begin(); itr != pcb->ReadyQueue.end(); ++itr)
					{
						processCount++;
						totalTime = totalTime + (*itr)->timeRemaining;
						sum = sum + (*itr)->timeRemaining;
						sumOfTimes.push_back(sum);
						//std::cout << sum << std::endl;
					}
					int sum2 = 0; //These are used to calculate turnaround time
					for(int n : sumOfTimes)
					{
						sum2 = sum2 + n;
					}
					
					std::cout << "CURRENT READY QUEUE" << std::endl;
					pcb->ShowReady(); //Show the current ready queue
					std::ofstream outputFile;
					outputFile.open (("FPPS.txt"), std::ofstream::out | std::ofstream::app);
					//Dispatch the processes to "running" in the correct order
					for(unsigned int i = 0; i < pcb->ReadyQueue.size(); ++i)
					{
						
						outputFile << pcb->ReadyQueue[i]->processName << " entered system!" << std::endl;
						pcb->ReadyQueue[i]->processState1 = "running";
						outputFile << pcb->ReadyQueue[i]->processName << " changed state to " << pcb->ReadyQueue[i]->processState1 << "!" << std::endl;
						
							if(pcb->ReadyQueue[i]->processPriority > pcb->ReadyQueue[i+1]->processPriority)
							{
								outputFile << pcb->ReadyQueue[i+1]->processName << " preempted!" << std::endl;
								pcb->ReadyQueue[i+1]->processState1 = "running";
								outputFile << pcb->ReadyQueue[i+1]->processName << " changed state to " << pcb->ReadyQueue[i+1]->processState1 << "!" << std::endl;
								pcb->ReadyQueue[i]->processState1 = "ready";
								outputFile << pcb->ReadyQueue[i]->processName << " changed state to " << pcb->ReadyQueue[i]->processState1 << "!" << std::endl;
								pcb->ReadyQueue[i]->timeRemaining -= pcb->ReadyQueue[i+1]->timeOfArrival;
								outputFile << "FPPS Completed: " << pcb->ReadyQueue[i+1]->processName << std::endl;
								pcb->ReadyQueue[i+1]->timeRemaining = 0;
								i++;
							}
						
						if(pcb->ReadyQueue[i-1]->timeRemaining != 0)
						{
							pcb->ReadyQueue[i-1]->processState1 = "running";
							outputFile << pcb->ReadyQueue[i-1]->processName << " changed state to " << pcb->ReadyQueue[i-1]->processState1 << "!" << std::endl;
							outputFile << "STCF Completedo: " << pcb->ReadyQueue[i-1]->processName << std::endl;
						}
						//pcb->ReadyQueue.pop_front();
					}
					std::cout << std::endl;
					pcb->ShowReady();
					outputFile.close();
					pcb->ReadyQueue.clear();
					std::cout << "Total time to completion: " << totalTime << std::endl;
					int turnaroundTime = sum2 / processCount;
					std::cout << "Average turnaround time: " << turnaroundTime << std::endl;
				}
				file.close();
		}
		
		void MLFQ(PCBClass* pcb)
		{
			std::vector<PCB*> PCBList; //Used to hold PCBs for sorting
			std::string line;
			std::ifstream file("test.txt");
				if(file.is_open())
				{
					while(getline(file, line))
					{
						//std::cout << line << std::endl;
						std::istringstream buf(line);
						std::istream_iterator<std::string> beg(buf), end;
						//The following lines split the file lines into different variables for processing into PCBs
						std::vector<std::string> tokens(beg, end);
						std::string processName = tokens[0];
						std::string procClass = tokens[1];
						char processClass1 = procClass[0];
						int processClass;
						if(processClass1 == 'A')
						{
							processClass = 0;
						}
						else if(processClass1 == 'S')
						{
							processClass = 1;
						}
						int processPriority = std::stoi(tokens[2]);
						int processMemory = std::stoi(tokens[3]);
						int timeRemaining = std::stoi(tokens[4]);
						int timeOfArrival = std::stoi(tokens[5]);
						int percentageOfCPU = std::stoi(tokens[6]);
						
						PCB* newPCB = pcb->SetupPCB(processName, processPriority, processClass, processMemory, timeRemaining, timeOfArrival, percentageOfCPU);
						PCBList.push_back(newPCB);
						//std::sort(PCBList.begin(), PCBList.end(), Compare); //Sort PCBs in PCBList by time remaining
					}
					//Used to insert PCBs to the ready queue in correct order
					for(const PCB* newPCB : PCBList)
					{
						pcb->InsertPCB(PCBList[0]);
						PCBList.erase(std::remove(PCBList.begin(), PCBList.end(), PCBList[0]), PCBList.end());
					}
					std::deque<PCB*>::iterator itr;
					int totalTime = 0; //Total time to completion
					int sum = 0; //Sum of times
					int processCount = 0; //Process counter
					std::vector<int> sumOfTimes; //Cascading sum of times
					//keeps track of # of processes, the total time to completion and the sum of times
					for(itr = pcb->ReadyQueue.begin(); itr != pcb->ReadyQueue.end(); ++itr)
					{
						processCount++;
						totalTime = totalTime + (*itr)->timeRemaining;
						sum = sum + (*itr)->timeRemaining;
						sumOfTimes.push_back(sum);
						//std::cout << sum << std::endl;
					}
					int sum2 = 0; //These are used to calculate turnaround time
					for(int n : sumOfTimes)
					{
						sum2 = sum2 + n;
					}
					
					std::cout << "CURRENT READY QUEUE" << std::endl;
					pcb->ShowReady(); //Show the current ready queue
					std::ofstream outputFile;
					outputFile.open (("RR.txt"), std::ofstream::out | std::ofstream::app);
					int timeQuantum = 0;
					std::cout << "Please enter the time quantum: " << std::endl;
					std::cin >> timeQuantum;
					//Dispatch the processes to "running" in the correct order
					for(int i = 0; i < timeQuantum; ++i)
					{
						for(unsigned int j = 0; j < pcb->ReadyQueue.size(); ++j)
						{
							if(pcb->ReadyQueue[j]->timeRemaining > 0)
							{
								pcb->ReadyQueue[j]->timeRemaining -= timeQuantum;
								pcb->ReadyQueue[j]->processState1 = "running";
								outputFile << pcb->ReadyQueue[j]->processName << " changed state to " << pcb->ReadyQueue[j]->processState1 << "!" << std::endl;
							}
							else if(pcb->ReadyQueue[j]->timeRemaining <= 0)
							{
								PCB* finishedProcess;
								outputFile << "RR Completed: " << pcb->ReadyQueue[j]->processName << std::endl;
								finishedProcess = pcb->FindPCB(pcb->ReadyQueue[j]->processName);
								pcb->RemovePCB(finishedProcess);
							}
						}
					}
					std::cout << std::endl;
					pcb->ShowReady();
					outputFile.close();
					pcb->ReadyQueue.clear();
					std::cout << "Total time to completion: " << totalTime << std::endl;
					int turnaroundTime = sum2 / processCount;
					std::cout << "Average turnaround time: " << turnaroundTime << std::endl;
				}
				file.close();
		}
};

//These are all concrete command classes.
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

/*class CreatePCB : public Command
{
	Reciever* createPCB;
	public:
		CreatePCB(Reciever* createPCB)
		{
			this->createPCB = createPCB;
		}
		
		void execute()
		{
			createPCB->CreatePCBR(pcb);
		}
};

class DeletePCB : public Command
{
	Reciever* deletePCB;
	public:
		DeletePCB(Reciever* deletePCB)
		{
			this->deletePCB = deletePCB;
		}
		
		void execute()
		{
			deletePCB->DeletePCBR(pcb);
		}
};

class Block : public Command
{
	Reciever* block;
	public:
		Block(Reciever* block)
		{
			this->block = block;
		}
		
		void execute()
		{
			block->BlockR(pcb);
		}
};

class UnBlock : public Command
{
	Reciever* unblock;
	public:
		UnBlock(Reciever* unblock)
		{
			this->unblock = unblock;
		}
		
		void execute()
		{
			unblock->UnBlockR(pcb);
		}
};*/

class Suspend : public Command
{
	Reciever* suspend;
	public:
		Suspend(Reciever* suspend)
		{
			this->suspend = suspend;
		}
		
		void execute()
		{
			suspend->SuspendR(pcb);
		}
};

class Resume : public Command
{
	Reciever* resume;
	public:
		Resume(Reciever* resume)
		{
			this->resume = resume;
		}
		
		void execute()
		{
			resume->ResumeR(pcb);
		}
};

class SetPriority : public Command
{
	Reciever* setpriority;
	public:
		SetPriority(Reciever* setpriority)
		{
			this->setpriority = setpriority;
		}
		
		void execute()
		{
			setpriority->SetPriorityR(pcb);
		}
};

class ShowPCB : public Command
{
	Reciever* showpcb;
	public:
		ShowPCB(Reciever* showpcb)
		{
			this->showpcb = showpcb;
		}
		
		void execute()
		{
			showpcb->ShowPCBR(pcb);
		}
};

class ShowAll : public Command
{
	Reciever* showAll;
	public:
		ShowAll(Reciever* showAll)
		{
			this->showAll = showAll;
		}
		
		void execute()
		{
			showAll->ShowAllR(pcb);
		}
};

class ShowReady : public Command
{
	Reciever* showready;
	public:
		ShowReady(Reciever* showready)
		{
			this->showready = showready;
		}
		
		void execute()
		{
			showready->ShowReadyR(pcb);
		}
};

class ShowBlocked : public Command
{
	Reciever* showblocked;
	public:
		ShowBlocked(Reciever* showblocked)
		{
			this->showblocked = showblocked;
		}
		
		void execute()
		{
			showblocked->ShowBlockedR(pcb);
		}
};

class SJF : public Command
{
	Reciever* sjf;
	public:
		SJF(Reciever* sjf)
		{
			this->sjf = sjf;
		}
		
		void execute()
		{
			sjf->SJF(pcb);
		}
};

class FIFO : public Command
{
	Reciever* fifo;
	public:
		FIFO(Reciever* fifo)
		{
			this->fifo = fifo;
		}
		
		void execute()
		{
			fifo->FIFO(pcb);
		}
};

class STCF : public Command
{
	Reciever* stcf;
	public:
		STCF(Reciever* stcf)
		{
			this->stcf = stcf;
		}
		
		void execute()
		{
			stcf->STCF(pcb);
		}
};

class RR : public Command
{
	Reciever* rr;
	public:
		RR(Reciever* rr)
		{
			this->rr = rr;
		}
		
		void execute()
		{
			rr->RR(pcb);
		}
};

class FPPS : public Command
{
	Reciever* fpps;
	public:
		FPPS(Reciever* fpps)
		{
			this->fpps = fpps;
		}
		
		void execute()
		{
			fpps->FPPS(pcb);
		}
};

class MLFQ : public Command
{
	Reciever* mlfq;
	public:
		MLFQ(Reciever* mlfq)
		{
			this->mlfq = mlfq;
		}
		
		void execute()
		{
			mlfq->MLFQ(pcb);
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
	std::cout << "Welcome to SmithOS! To get started, select an option from the following menu: " << std::endl;
	do
	{
		std::cout << "Enter 'version' to show the current OS version" << std::endl;
		std::cout << "Enter 'date' to show the current date" << std::endl;
		std::cout << "Enter 'directory' to display a list of files on the OS" << std::endl;
		
		/*std::cout << "Enter 'createpcb' to create a PCB" << std::endl;
		std::cout << "Enter 'deletepcb' to delete a PCB" << std::endl;
		std::cout << "Enter 'block' to block a PCB" << std::endl;
		std::cout << "Enter 'unblock' to unblock a PCB" << std::endl;*/
		std::cout << "Enter 'suspend' to suspend a PCB" << std::endl;
		std::cout << "Enter 'resume' to resume a PCB" << std::endl;
		std::cout << "Enter 'setpriority' to change a PCB's priority" << std::endl;
		std::cout << "Enter 'showpcb' to display a PCB by name" << std::endl;
		std::cout << "Enter 'showall' to display a list of all PCBs" << std::endl;
		std::cout << "Enter 'showready' to display a list of all PCBs in the ready queue" << std::endl;
		std::cout << "Enter 'showblocked' to display a list of all PCBs in the blocked queue" << std::endl;
		
		std::cout << "Enter 'exit' to exit the OS" << std::endl;
		std::cout << "Enter 'help' to get help on these commands" << std::endl;
		//std::cout << "Enter 'test' to test the functionality of the system" << std::endl;
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
		/*else if(option == "createpcb")
		{
			std::system("clear");
			CreatePCB* createpcb = new CreatePCB(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(createpcb);
		}
		else if(option == "deletepcb")
		{
			std::system("clear");
			DeletePCB* deletepcb = new DeletePCB(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(deletepcb);
		}
		else if(option == "block")
		{
			std::system("clear");
			Block* block = new Block(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(block);
		}
		else if(option == "unblock")
		{
			std::system("clear");
			UnBlock* unblock = new UnBlock(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(unblock);
		}*/
		else if(option == "suspend")
		{
			std::system("clear");
			Suspend* suspend = new Suspend(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(suspend);
		}
		else if(option == "resume")
		{
			std::system("clear");
			Resume* resume = new Resume(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(resume);
		}
		else if(option == "setpriority")
		{
			std::system("clear");
			SetPriority* setpriority = new SetPriority(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(setpriority);
		}
		else if(option == "showpcb")
		{
			std::system("clear");
			ShowPCB* showpcb = new ShowPCB(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(showpcb);
		}
		else if(option == "showall")
		{
			std::system("clear");
			ShowAll* showall = new ShowAll(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(showall);
		}
		else if(option == "showready")
		{
			std::system("clear");
			ShowReady* showready = new ShowReady(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(showready);
		}
		else if(option == "showblocked")
		{
			std::system("clear");
			ShowBlocked* showblocked = new ShowBlocked(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(showblocked);
		}
		else if(option == "sjf")
		{
			std::system("clear");
			SJF* sjf = new SJF(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(sjf);
		}
		else if(option == "fifo")
		{
			std::system("clear");
			FIFO* fifo = new FIFO(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(fifo);
		}
		else if(option == "stcf")
		{
			std::system("clear");
			STCF* stcf = new STCF(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(stcf);
		}
		else if(option == "rr")
		{
			std::system("clear");
			RR* rr = new RR(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(rr);
		}
		else if(option == "fpps")
		{
			std::system("clear");
			FPPS* fpps = new FPPS(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(fpps);
		}
		else if(option == "mlfq")
		{
			std::system("clear");
			MLFQ* mlfq = new MLFQ(reciever);
			Invoker* invoker = new Invoker();
			invoker->invoke(mlfq);
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
