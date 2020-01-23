//HK Arial
//Drone Hunter search program

#include <iostream>
//Helps generate a random number
#include <cstdlib>
//Time function that random is using
#include <ctime>

using namespace std;

int main()
{
	//Seed random number generator
	srand(static_cast<unsigned int>(time(0)));

	int searchGridLowNumber = 1;
	int searchGridHighNumber = 64;
	
	//Random number between 1 and 64 to hold the actual target location
	int actualTargetLocation = rand() % 64 + 1;
	
	//Random number between 1 and 64
	//int secretNumber = rand() % 64 + 1;
	int tries = 0;
	int attemptToLocateTarget = 0;

	cout << "\tWelcome to AI Drone Hunter 3000\n\n";

	//Checks to see if the guess is <, >, or = the actualTargetLocation
	do
	{
		//This is where the AI makes a target location guess
		cout << "\nThe real target location is at " << actualTargetLocation << endl;
		cout << "\nThe AI guesses the target is at location  " << attemptToLocateTarget << endl;
		attemptToLocateTarget = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		++tries;

		if (attemptToLocateTarget > actualTargetLocation)
		{
			cout << "The AI target prediction was too high.\n\n";
			searchGridHighNumber = attemptToLocateTarget - 1;
		}
		else if (attemptToLocateTarget < actualTargetLocation)
		{
			cout << "The AI target prediction was too low.\n\n";
			searchGridLowNumber = attemptToLocateTarget + 1;
		}
		else
		{
			cout << "\nThat's it! The AI got it in " << tries << " guesses!\n";
		}
	} while (attemptToLocateTarget != actualTargetLocation);

	return 0;
}