
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() 
{
	//character!!
	char wannaPlay = 'y';

	//the game lopp
	while (wannaPlay == 'y') 
	{

		//seeding ~~~~~~~
		srand(static_cast<unsigned int>(time(0)));

		//initialize random enemy location
		int enemyLocation = rand() % 64 + 1;
		cout << "Enemy is located in sector " << enemyLocation << "!!!\n\n";

		//human search!
		int humanGuess = 0;
		int humanSearches = 0;

		while (true) 
		{
			humanSearches++;
			cout << "\nPlease Select a sector you would like to Search: ";
			cin >> humanGuess;

			if (humanGuess == enemyLocation) 
			{
				cout << ">>ENEMY SPOTTED..<<\n\n";
				break;
			}
			else if (humanGuess > enemyLocation) 
			{
				cout << "No enemies found... I think we over shot it.\n";
			}
			else if (humanGuess < enemyLocation) 
			{
				cout << "Enemy seems to be close... Let's go a little farther.\n";
			}
		}

		//binary search
		int binaryLowSearch = 0;			
		int binaryHighSearhc = 64;	
		//chooses secters being searched
		int binaryGuess = 0;	
		//counts the searches
		int binarySearches = 0;	

		while (binaryGuess != enemyLocation) 
		{
			//increment!!
			binarySearches++;				
			binaryGuess = (binaryHighSearhc + binaryLowSearch) / 2;	

			if (binaryGuess == enemyLocation) break;
			else if (binaryGuess > enemyLocation) binaryHighSearhc = binaryGuess - 1;
			else if (binaryGuess < enemyLocation) binaryLowSearch = binaryGuess + 1;
		}

		//linear search
		int linearSearches = 0;	

		while (linearSearches != enemyLocation)
			linearSearches++;

		//random search
		int randomSearches = 0;	
		int randomGuess = 0;		

		while (randomGuess != enemyLocation) 
		{
			randomSearches++;
			randomGuess = rand() % 64 + 1;
		}

		cout << "All done!!\n\n";

		cout << "--------------\n\n";

		cout << "How many pings before the enemy was found!!:\n\n";

		cout << "Player:   " << humanSearches << "\n";
		cout << "Linear:   " << linearSearches << "\n";
		cout << "Random:   " << randomSearches << "\n";
		cout << "Binary:   " << binarySearches << "\n\n";

		cout << "You wanna try again?? (y/n): ";
		cin >> wannaPlay;
	}

	return 0;
}