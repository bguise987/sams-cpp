#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	const int Dividend = 6;
	const int Divisor = 2;

	int Result = (Dividend/Divisor);

	Result = Result + 3; // Result is now its old valud + 3 = 6

	cout << Result << endl;

	// Note: You must type something before the Enter key
	char StopCharacter;
	cout << endl << "Press any key and \"Enter\": ";
	cin >> StopCharacter;

	return 0;
}
