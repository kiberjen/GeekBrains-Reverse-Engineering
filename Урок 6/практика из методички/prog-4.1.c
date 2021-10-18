#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma comment(lib, "Advapi32.lib")

void usage(char *);
bool check_key(char *);
int sum(int, int);
bool check_numbers(char *, char *);
bool license(void);
bool trial(void);
bool check_trial(void);
bool isRegistered(void);

int main(int argc, char* argv[]) {

	if (argc == 1 || argc > 3) {
		usage(argv[0]);
		return 0;
	}
	
	if (argc == 2) {
		if (!check_key(argv[1])) {
			printf("\nLicense key is incorrect.\n");
			return 0;
		}
		
		if (license()) {
			printf("\nThe program has been activated!\n");
		} else {
			printf("\nUnknown error! (license)\n");
		}
		return 0;
	}
	
	if (isRegistered()) {
		if (!check_trial()) {
			printf("\nThe number of starts has expired.\n");
			return 0;
		}
	} else {
		if (!trial()) {
			printf("\nUnknown error! (trial)\n");
			return 0;
		}
	}	
	
	if (!check_numbers(argv[1], argv[2])) {
		usage(argv[0]);
		return 0; 
	}
	
	printf("\nResult: %d\n", sum(atoi(argv[1]), atoi(argv[2])));
}

void usage(char *program_name) {
	printf("\nUsage:\n");
	printf("\n\t%s <number> <number>\n", program_name);
	printf("\nActivation:\n");
	printf("\n\t%s <license key>\n", program_name);
}

bool isRegistered(void) {
	HKEY hkey;
	LPCTSTR PATH = TEXT("Software\\GeekBrains\\Prog4");
	LPCTSTR NAME = TEXT("Counter");
	
	LONG nError = RegOpenKeyEx(HKEY_CURRENT_USER, PATH, 0, KEY_READ, &hkey);
	if (nError != ERROR_SUCCESS) {
		return false;
    }
	
	nError = RegGetValue(hkey, NULL, NAME, RRF_RT_REG_SZ, 0, NULL, NULL);
	if (nError != ERROR_SUCCESS) {
		RegCloseKey(hkey);
		return false;
    }

	RegCloseKey(hkey);
	
	return true;
}

bool check_key(char* key) {

	if (strlen(key) != 19) {
		return false;
	}
	
	if (key[4] != '-' || key[9] != '-' || key[14] != '-') {
		return false;
	}
	
	for (int block_offset = 0; block_offset < 20; block_offset += 5) {
		if ((key[block_offset] + key[block_offset+1] + key[block_offset+2] + key[block_offset+3] - 192) != 10) {
			return false;
		}
	}

	return true;
}

int sum(int a, int b) {
	return a + b;
}

bool check_numbers(char *num1, char *num2) {	
	for (int i = 0; i < strlen(num1); i++) {
		if (num1[i] < 48 || num1[i] > 57) {
			return false;
		}
	}
	
	for (int i = 0; i < strlen(num2); i++) {
		if (num2[i] < 48 || num2[i] > 57) {
			return false;
		}
	}
	
	return true; 
}
bool license(void) {
	
	HKEY hkey;
	LPCTSTR PATH = TEXT("Software\\GeekBrains\\Prog4");
	LPCTSTR NAME = TEXT("Counter");
	
	char value[] = "10000";
	
	LONG nError = RegCreateKeyEx(HKEY_CURRENT_USER, PATH, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hkey, NULL);
	if (nError != ERROR_SUCCESS) {
		return false;
    }
	
	nError = RegSetValueExA(hkey, NAME, 0, REG_SZ, value, sizeof(value));
	if (nError != ERROR_SUCCESS) {
		RegCloseKey(hkey);
		return false;
    }
	
	RegCloseKey(hkey);
	
	return true;
}

bool trial(void) {
	
	HKEY hkey;
	LPCTSTR PATH = TEXT("Software\\GeekBrains\\Prog4");
	LPCTSTR NAME = TEXT("Counter");
	
	char value[] = "9";
	
	LONG nError = RegCreateKeyEx(HKEY_CURRENT_USER, PATH, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hkey, NULL);
	if (nError != ERROR_SUCCESS) {
		return false;
    }
	
	nError = RegSetValueExA(hkey, NAME, 0, REG_SZ, value, sizeof(value));
	if (nError != ERROR_SUCCESS) {
		return false;
    }
		
	printf("\nTrial Period: %d of 10\n", atoi(value));
	
	RegCloseKey(hkey);
	
	return true;
}

bool check_trial(void) {
	
	HKEY hkey;
	LPCTSTR PATH = TEXT("Software\\GeekBrains\\Prog4");
	LPCTSTR NAME = TEXT("Counter");
	
	char value[64];
    DWORD value_size = 64;
	
	LONG nError = RegOpenKeyEx(HKEY_CURRENT_USER, PATH, 0, KEY_READ, &hkey);
	if (nError != ERROR_SUCCESS) {
		return false;
    }
	
	nError = RegGetValue(hkey, NULL, NAME, RRF_RT_REG_SZ, 0, value, &value_size);
	if (nError != ERROR_SUCCESS) {
		RegCloseKey(hkey);
		return false;
    }
	
	int tmp = atoi(value);
	
	if (tmp == 0) {
		RegCloseKey(hkey);
		return false;
	}
	
	itoa(--tmp, value, 10);
	
	nError = RegOpenKeyEx(HKEY_CURRENT_USER, PATH, 0, KEY_WRITE, &hkey);
	if (nError != ERROR_SUCCESS) {
		RegCloseKey(hkey);
		return false;
    }
		
	nError = RegSetValueExA(hkey, NAME, 0, REG_SZ, value, sizeof(value));
	if (nError != ERROR_SUCCESS) {
		RegCloseKey(hkey);
		return false;
    }
	
	RegCloseKey(hkey);
	
	if (tmp < 10) { 
		printf("\nTrial Period: %d of 10\n", atoi(value));
	}
	
	return true;
}