// load_dll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

int main(int argc, char** argv)
{
	char* libreria;
	char* funcion;
	int size_dll, size_fun;

	if (argc != 3) {
		printf("Uso: load.dll.exe <test.dll> <test_funcion>");
		exit(0);
	}

	size_dll = strlen(argv[1]);
	size_fun = strlen(argv[2]);

	libreria = (char*)malloc(size_dll + 1);
	memcpy(libreria, argv[1], size_dll + 1);

	funcion = (char*)malloc(size_fun + 1);
	memcpy(funcion, argv[2], size_fun + 1);

	MessageBoxA(NULL, "Esperando para tomar el proceso...", "Attach Me", MB_OK | MB_ICONINFORMATION);
	printf("Attach Process [ENTER]\n");
	printf("Buscando BP...\n");

	HMODULE hDLL = LoadLibraryA(libreria);
	if (hDLL) {
		FARPROC fpFun = GetProcAddress(hDLL, funcion);
		(*fpFun)();
	} else {
		//printf("Libreria no encontrada :(");
		MessageBoxA(NULL, "Libreria no encontrada", "I'm sorry :(", MB_OK | MB_ICONEXCLAMATION);
		exit(0);
	}
	FreeLibrary(hDLL);
}