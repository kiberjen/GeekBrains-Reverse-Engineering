#include <windows.h>

#pragma comment(lib,"user32.lib")

int main(int argc, char* argv[]) {

	int tmp = 2;
	char title[] = "Prog-3.1";

	goto metka;
		MessageBox(NULL, "Always Skipped", title, 0);
	metka:

	if (TRUE) { MessageBox(NULL, "Always TRUE", title, 0); }

	if (FALSE) { MessageBox(NULL, "Always FALSE", title, 0); }

	if (tmp < 5) { MessageBox(NULL, "tmp < 5", title, 0); }

	if (tmp > 5) {
		MessageBox(NULL, "tmp > 5", title, 0);
	} else {
		MessageBox(NULL, "tmp <= 5", title, 0);
	}

	if (tmp == 2) { MessageBox(NULL, "tmp == 2", title, 0); }

	switch (tmp)
	{
  		case 1:
  			MessageBox(NULL, "Case: 1", title, 0);
    			break;
  		case 2:
  			MessageBox(NULL, "Case: 2", title, 0);
    			break;
		default:
			MessageBox(NULL, "Case: default", title, 0);
			break;
	}
	return 0;
}
