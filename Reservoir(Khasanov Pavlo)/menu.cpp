#include "includes.h"

void displayMenu(int button)
{
	const char* menu[]{ "Add reservoir", "Delete reservoir", "Display reservoirs", "Save reservoirs", "EXIT" };
	for (int i = 0; i < 5; i++) {
		if (button == i)
			cout << "*";

		int lengthStr = strlen(menu[i]);
		if (button == i)
			--lengthStr;

		cout.width(lengthStr + 1);
		cout << menu[i] << endl;
	}
}

bool moveMenu(int& button)
{
	char clickButton = _getch();
	if (clickButton == 'w') {
		button--;
		if (button < 0)
			button = 4;
	}
	else if (clickButton == 's') {
		button++;
		if (button > 4)
			button = 0;
	}
	else if (clickButton == 13) {
		return true;
	}

	return false;
}
