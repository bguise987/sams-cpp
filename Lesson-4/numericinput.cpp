#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int Dividend = 1;
	cout << "Dividend: ";
	cin >> Dividend;

	int Divisor = 1;
	cout << "Divisor: ";
	cin >> Divisor;

	int Result = (Dividend/Divisor);
	cout << Result << endl;

	// Note: You must type something before the Enter key
	char StopCharacter;
	cout << endl << "Press a key and \"Enter\": ";
	cin >> StopCharacter;

	return 0;
}

