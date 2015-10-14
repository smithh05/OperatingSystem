#ifndef PCB_H
#define PCB_H

#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
//#include <sstream>
//#include <boost/bind.hpp>

struct PCB
{
	std::string processName;
	int processClass;
	int processPriority;
	std::string processState1;
	std::string processState2;
	int processMemory;
	int timeRemaining;
	int timeOfArrival;
	int percentageOfCPU;
} typedef PCB;

/*struct Node
{
	Node* next;
	Node* prev;
	PCB* pcb;
};
struct QueueStruct
{
	int nodeCount;
	Node* head;
	Node* rear;
};*/

class PCBClass
{
	public:

		//QueueStruct* ReadyQueue;
		//QueueStruct* BlockedQueue;

		std::deque<PCB*> ReadyQueue;
        std::deque<PCB*> BlockedQueue;

		PCB* AllocatePCB()
		{
			PCB* newPCB = new PCB; //Allocate memory for new PCB
			return newPCB;
		}

		void FreePCB(PCB* pointer)
		{
			delete pointer;
		}

		PCB* SetupPCB(std::string processName, int processPriority, int processClass, int processMemory, int timeRemaining, int timeOfArrival, int percentageOfCPU)
		{
			if(processPriority < -127 || processPriority > 128)
			{
				std::cout << "Priority must be from -127 to 128!" << std::endl;
				return NULL;
			}
			if(processClass < 0 || processClass > 1)
			{
				std::cout << "Process class must either be 0 or 1!" << std::endl;
				return NULL;
			}
			if(FindPCB(processName) != NULL)
			{
				std::cout << "Cannot have two processes with the same name!" << std::endl;
				//return NULL;
			}

			PCB* newPCB = AllocatePCB();
			newPCB->processName = processName;
			newPCB->processPriority = processPriority;
			newPCB->processClass = processClass;
			newPCB->processState1 = "ready";
			newPCB->processState2 = "not suspended";
			newPCB->processMemory = processMemory;
			newPCB->timeRemaining = timeRemaining;
			newPCB->timeOfArrival = timeOfArrival;
			newPCB->percentageOfCPU = percentageOfCPU;
			return newPCB;
		}

		PCB* FindPCB(std::string processName)
		{
		    /*auto it = std::find_if(std::begin(ReadyQueue), std::end(ReadyQueue), [=] (PCB const pcb) {return (pcb.processName == processName);});
		    bool found = (it != std::end(ReadyQueue));
		    if(found == true)
            {
                std::cout << "Found in ready queue!" << std::endl;
                return 1;
            }
            auto it2 = std::find_if(std::begin(BlockedQueue), std::end(BlockedQueue), [=] (PCB const pcb) {return (pcb.processName == processName);});
		    bool found2 = (it != std::end(BlockedQueue));
		    if(found == true)
            {
                std::cout << "Found in blocked queue!" << std::endl;
                return 1;
            }*/
            std::deque<PCB*>::iterator itr;
            for(itr = ReadyQueue.begin(); itr != ReadyQueue.end(); ++itr)
            {
                if((*itr)->processName == processName)
                {
                    std::cout << "Found in ready" << std::endl;
                    return (*itr);
                }
                //return NULL;
            }
            for(itr = BlockedQueue.begin(); itr != BlockedQueue.end(); ++itr)
            {
                if((*itr)->processName == processName)
                {
                    std::cout << "Found in blocked" << std::endl;
                    return (*itr);
                }
                //return NULL;
            }
            return NULL;
		}

		void PrintQueue()
		{
			for(const PCB* pcb : ReadyQueue)
            {
                std::cout << pcb->processName << "R ";
            }
            std::cout << std::endl;
            for(const PCB* pcb : BlockedQueue)
            {
                std::cout << pcb->processName << "B ";
            }
            std::cout << std::endl;
		}

		void InsertPCB(PCB* inputPCB)
		{
			if(inputPCB->processState1 == "ready")
			{
				ReadyQueue.push_back(inputPCB);
			}
			if(inputPCB->processState1 == "blocked")
			{
				BlockedQueue.push_back(inputPCB);
			}
		}

		void RemovePCB(PCB* inputPCB)
		{
			inputPCB = FindPCB(inputPCB->processName);
            std::cout << "F" << std::endl;
            //ReadyQueue.erase(std::remove_if(ReadyQueue.begin(), ReadyQueue.end(), [inputPCB](PCB* pcb) {return pcb->processName == inputPCB->processName;}), ReadyQueue.end());
            ReadyQueue.erase(std::remove(ReadyQueue.begin(), ReadyQueue.end(), inputPCB), ReadyQueue.end());
            //BlockedQueue.erase(std::remove_if(BlockedQueue.begin(), BlockedQueue.end(), [inputPCB](PCB* pcb) {return pcb->processName == inputPCB->processName;}), BlockedQueue.end());
            BlockedQueue.erase(std::remove(BlockedQueue.begin(), BlockedQueue.end(), inputPCB), BlockedQueue.end());
			return;

		}

		/*void CreatePCB()
		{
			std::string processName = "";
			int processPriority;
			bool processClass;

			bool checkName = true;
			do
            {
                std::cout << "Please enter the name of the process you want to create: " << std::endl;
                std::cin >> processName;
                if(FindPCB(processName) != NULL)
                {
                    std::cout << "Cannot have two processes with the same name!" << std::endl;
                }
                else
                {
                    checkName = false;
                }
            }while(checkName == true);

            bool checkPriority = true;
            do
			{
                std::cout << "Please enter the priority (between -127 and 128) of the process you want to create: " << std::endl;
                std::cin >> processPriority;
                if(processPriority < -127 || processPriority > 128)
                {
                    std::cout << "Priority must be from -127 to 128!" << std::endl;
                }
                else
			    {
                    checkPriority = false;
                }
			}while(checkPriority == true);

			bool checkClass = true;
			do
            {
                std::cout << "Please enter the class of the process you want to create (0 for Application and 1 for System): " << std::endl;
                std::cin >> processClass;
                if(processClass < 0 || processClass > 1)
                {
                    std::cout << "Process class must either be 0 or 1!" << std::endl;
                }
                else
                {
                    checkClass = false;
                }
            }while(checkClass == true);

			PCB* newPCB = SetupPCB(processName, processPriority, processClass);
			InsertPCB(newPCB);
		}

		void DeletePCB()
		{
			std::string processName = "";
			std::cout << "Please enter the name of the process you wish to delete: " << std::endl;
			std::cin >> processName;
			PCB* deletedPCB = FindPCB(processName);
			if(deletedPCB == NULL)
            {
                std::cout << "The specified process does not exist!" << std::endl;
                return;
            }
			RemovePCB(deletedPCB);
			FreePCB(deletedPCB);
		}

		void Block()
		{
			std::string processName = "";
			std::cout << "Please enter the name of the process you wish to block: " << std::endl;
			std::cin >> processName;
			PCB* blockedPCB = FindPCB(processName);
			if(blockedPCB == NULL)
            {
                std::cout << "The specified process does not exist!" << std::endl;
                return;
            }
			blockedPCB->processState1 = "blocked";
			RemovePCB(blockedPCB);
			InsertPCB(blockedPCB);
		}

		void Unblock()
		{
		    std::string processName = "";
			std::cout << "Please enter the name of the process you wish to unblock: " << std::endl;
			std::cin >> processName;
			PCB* unblockedPCB = FindPCB(processName);
			if(unblockedPCB == NULL)
            {
                std::cout << "The specified process does not exist!" << std::endl;
                return;
            }
			unblockedPCB->processState1 = "ready";
			RemovePCB(unblockedPCB);
			InsertPCB(unblockedPCB);
		}*/

		void Suspend()
		{
		    std::string processName = "";
			std::cout << "Please enter the name of the process you wish to suspend: " << std::endl;
			std::cin >> processName;
			PCB* suspendedPCB = FindPCB(processName);
			if(suspendedPCB == NULL)
            {
                std::cout << "The specified process does not exist!" << std::endl;
                return;
            }
			suspendedPCB->processState2 = "suspended";
		}

		void Resume()
		{
		    std::string processName = "";
			std::cout << "Please enter the name of the process you wish to resume: " << std::endl;
			std::cin >> processName;
			PCB* resumedPCB = FindPCB(processName);
			if(resumedPCB == NULL)
            {
                std::cout << "The specified process does not exist!" << std::endl;
                return;
            }
			resumedPCB->processState2 = "not suspended";
		}

		void SetPriority()
		{
		    std::string processName = "";
			std::cout << "Please enter the name of the process you wish to change priority: " << std::endl;
			std::cin >> processName;
			int processPriority;

			bool checkPriority = true;
            do
			{
                std::cout << "Please enter the priority (between -127 and 128): " << std::endl;
                std::cin >> processPriority;
                if(processPriority < -127 || processPriority > 128)
                {
                    std::cout << "Priority must be from -127 to 128!" << std::endl;
                }
                else
			    {
                    checkPriority = false;
                }
			}while(checkPriority == true);

			PCB* pcb = FindPCB(processName);
			pcb->processPriority = processPriority;
		}

		void ShowPCB()
		{
		    std::string processName = "";
			std::cout << "Please enter the name of the process you wish to view: " << std::endl;
			std::cin >> processName;
			PCB* pcb = FindPCB(processName);
			if(pcb == NULL)
            {
                std::cout << "The specified process does not exist!" << std::endl;
                return;
            }
			std::cout << "Process Name: " << pcb->processName << std::endl;
			std::cout << "Process Class: " << pcb->processClass << std::endl;
			std::cout << "Process Priority: " << pcb->processPriority << std::endl;
			std::cout << "Process State1: " << pcb->processState1 << std::endl;
			std::cout << "Process State2: " << pcb->processState2 << std::endl;
			std::cout << "Process Memory: " << pcb->processMemory << std::endl;
			std::cout << "Time Remaining: " << pcb->timeRemaining << std::endl;
			std::cout << "Time of Arrival: " << pcb->timeOfArrival << std::endl;
			std::cout << "Percentage of CPU: " << pcb->percentageOfCPU << std::endl;
		}

		void ShowAll()
		{
		    for(const PCB* pcb : ReadyQueue)
            {
                std::cout << "Process Name: " << pcb->processName;
                std::cout << " Process Class: " << pcb->processClass;
                std::cout << " Process Priority: " << pcb->processPriority;
                std::cout << " Process State1: " << pcb->processState1;
                std::cout << " Process State2: " << pcb->processState2;
                std::cout << " Process Memory: " << pcb->processMemory;
                std::cout << " Time Remaining: " << pcb->timeRemaining;
				std::cout << " Time of Arrival: " << pcb->timeOfArrival;
				std::cout << " Percentage of CPU: " << pcb->percentageOfCPU << std::endl;
                std::cout << "*****************************" << std::endl;
            }
            std::cout << std::endl;
            for(const PCB* pcb : BlockedQueue)
            {
                std::cout << "Process Name: " << pcb->processName;
                std::cout << " Process Class: " << pcb->processClass;
                std::cout << " Process Priority: " << pcb->processPriority;
                std::cout << " Process State1: " << pcb->processState1;
                std::cout << " Process State2: " << pcb->processState2;
                std::cout << " Process Memory: " << pcb->processMemory;
                std::cout << " Time Remaining: " << pcb->timeRemaining;
				std::cout << " Time of Arrival: " << pcb->timeOfArrival;
				std::cout << " Percentage of CPU: " << pcb->percentageOfCPU << std::endl;
                std::cout << "*****************************" << std::endl;
            }
            std::cout << std::endl;
		}

		void ShowReady()
		{
		    for(const PCB* pcb : ReadyQueue)
            {
                std::cout << "Process Name: " << pcb->processName;
                std::cout << " Process Class: " << pcb->processClass;
                std::cout << " Process Priority: " << pcb->processPriority;
                std::cout << " Process State1: " << pcb->processState1;
                std::cout << " Process State2: " << pcb->processState2;
                std::cout << " Process Memory: " << pcb->processMemory;
                std::cout << " Time Remaining: " << pcb->timeRemaining;
                std::cout << " Time of Arrival: " << pcb->timeOfArrival;
                std::cout << " Percentage of CPU: " << pcb->percentageOfCPU << std::endl;
                std::cout << "*****************************" << std::endl;
            }
		}

		void ShowBlocked()
		{
		    for(const PCB* pcb : BlockedQueue)
            {
                std::cout << "Process Name: " << pcb->processName;
                std::cout << " Process Class: " << pcb->processClass;
                std::cout << " Process Priority: " << pcb->processPriority;
                std::cout << " Process State1: " << pcb->processState1;
                std::cout << " Process State2: " << pcb->processState2;
                std::cout << " Process Memory: " << pcb->processMemory;
                std::cout << " Time Remaining: " << pcb->timeRemaining;
				std::cout << " Time of Arrival: " << pcb->timeOfArrival;
				std::cout << " Percentage of CPU: " << pcb->percentageOfCPU << std::endl;
                std::cout << "*****************************" << std::endl;
            }
		}




};

#endif
