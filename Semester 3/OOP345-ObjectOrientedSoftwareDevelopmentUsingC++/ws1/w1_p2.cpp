
#include <iostream>
#include <iomanip>
#include <fstream>
#include "event.h"
#include "event.h"


// Cheching if header guards exist and follow convention.
#ifndef SENECA_EVENT_H
#error "The header guard for 'Event.h' doesn't follow the convention!"
#endif

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

/* input file format: a comma separated set of fields; some fields have a single parameter
T175,SComputer Starting,P,

codes
	T - time (parameter: a number representing the time--measured in seconds--when the following codes apply)
	S - start event (parameter: a string representing the description for the event that starts)
	E - end the event
	P - print to screen
	A - archive
*/

// TODO: write the prototype for the main function
//         to accept command line arguments

int main(int arg_count, char* arguments[]) {
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	// TODO: print the command line here, in the format
	//   1: first argument
	//   2: second argument
	//   3: third argument
	//   ...
	for (int i = 0; i < arg_count; i++)
	{
		std::cout << "  ";
		std::cout << i + 1 << ": " << arguments[i] << "\n";
	}
	std::cout << "--------------------------\n\n";


	// the archive can store maximum 10 events
	seneca::Event archive[10];
	// the index of the next available position in the archive
	size_t idxArchive = 0;

	seneca::Event currentEvent;

	const size_t secInDay = 60u * 60u * 24u;// day has 86400 seconds

	for (auto day = 1; day < arg_count; ++day)
	{
		// each parameter for an application contains the events from one day
		// process each one
		std::cout << "--------------------\n";
		std::cout << "    Day " << day << '\n';
		std::cout << "--------------------\n";
		std::ifstream in(arguments[day]);
		if (in.is_open() == false)
		{
			std::cout << "Cannot open file [" << arguments[day] << "]. Ignoring it!\n";
			continue; // go to the next iteration of the loop
		}
		char opcode = '\0';
		size_t time = secInDay + 1;
		in >> opcode >> time;

		// starting at midnight, until the end of the day
		for (seneca::g_sysClock = 0u; seneca::g_sysClock < secInDay; ++seneca::g_sysClock)
		{
			// what should happen this second
			while (time == seneca::g_sysClock)
			{
				// skip the delimiter
				in.ignore();
				// read the next opcode
				in >> opcode;

				// end of the file
				if (in.fail())
					break;

				// handle the operation code
				switch (opcode)
				{
				case 'T': // a new time code, this is the exit from the while loop (back to for loop)
					in >> time;
					break;
				case 'S': // start a new event, the old event is automatically finished
					char buffer[1024];
					in.get(buffer, 1024, ',');
					currentEvent.set(buffer);
					break;
				case 'E': // end the current event
					currentEvent.set(nullptr);
					break;
				case 'P': // print to scren the information about the current event
					currentEvent.display();
					break;
				case 'A': // add a copy of the current event to the archive
					seneca::Event copy(currentEvent);
					archive[idxArchive++] = copy;
					break;
				}
			}
		}
	}

	// print the archive
	std::cout << "--------------------\n";
	std::cout << "    Archive\n";
	std::cout << "--------------------\n";
	for (auto i = 0u; i < idxArchive; ++i)
		archive[i].display();
	std::cout << "--------------------\n";

	return cout;
}