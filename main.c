#include <stdio.h>
#include <windows.h>

int wmain(int argc, wchar_t** argv){

    if(argc < 2){
        printf("Insufficient amount of arguments passed !\n");
        return 1;
    }

    for(int count = 1; count < argc; ++count){
        HANDLE hfile = CreateFileW(
            argv[count],
            GENERIC_WRITE,
            0,
            NULL,
            CREATE_NEW,
            FILE_ATTRIBUTE_NORMAL,
            NULL
        );

        if(hfile == INVALID_HANDLE_VALUE){
            DWORD error = GetLastError();
            if(error == ERROR_FILE_EXISTS) wprintf(L"File %ls already exsist !\n", argv[count]);
            else printf("Error: %lu\n", error);
            continue; //exit early! Beecause it failed, there is no handle to close !
        }

        CloseHandle(hfile);
    }

    return 0;
}
