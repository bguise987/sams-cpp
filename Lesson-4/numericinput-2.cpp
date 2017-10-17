#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	float  Dividend = 1;
	cout << "Dividend: ";
	cin >> Dividend;

	float Divisor = 1;
	cout << "Divisor: ";
	cin >> Divisor;

	float Result = (Dividend/Divisor);
	cout << Result << endl;

	// Note: You must type something before the Enter key
	char StopCharacter;
	cout << endl << "Press a key and \"Enter\": ";
	cin >> StopCharacter;

	return 0;
}

