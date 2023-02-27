#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PASSWORD_LENGTH 63

int main(void)
{
	char password[PASSWORD_LENGTH + 1];
	int i, ascii_value;
	srand(time(NULL));

	for (i = 0; i < PASSWORD_LENGTH; i++) {
		ascii_value = rand() % (126 - 33 + 1) + 33;
		password[i] = (char) ascii_value;
	}

	password[PASSWORD_LENGTH] = '\0';
	printf("%s", password);

	return 0;
}
