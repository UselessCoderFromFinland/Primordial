#include "pch.h"
#include <Windows.h>
#include <fstream>


#include "Install.hpp"

BOOL __stdcall DllMain( HMODULE hModule, DWORD ulReason, LPVOID lpReserved )
{
	if ( ulReason != DLL_PROCESS_ATTACH )
		return 1;

	AllocConsole( );
	freopen_s( reinterpret_cast< FILE** >( stdin ), "CONIN$", "r", stdin );
	freopen_s( reinterpret_cast< FILE** >( stdout ), "CONOUT$", "w", stdout );
	SetConsoleTitleA( "=)" );

	CInstall* pInstall = new CInstall( );
	pInstall->Init( );

	return 1;
}