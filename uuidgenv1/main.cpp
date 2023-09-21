#define _WIN32_WINNT 0x0500
#include <iostream>
#include <windows.h>
#include <Rpc.h>

int main(int argc, char** argv) {
	UUID uuid = {};

	RPC_STATUS err = UuidCreateSequential(&uuid);

	if (err != RPC_S_OK) {
		std::wcerr << L"Failed to Create UUID";
		return err;
	}

	RPC_WSTR stringUuid = NULL;

	err = UuidToString(&uuid, &stringUuid);

	if (err != RPC_S_OK) {
		std::wcerr << L"Failed to Convert UUID To String";
		return err;
	}

	std::wcout << (wchar_t*)stringUuid;
	return err;
}