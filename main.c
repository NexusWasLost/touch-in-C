#include <stdio.h>
#include <windows.h>

int wmain(int argc, wchar_t** argv){

    if(argc < 2){
        printf("Insufficient amount of arguments passed !\n");
        return 1;
    }

    HANDLE hfile = CreateFileW(
        argv[1],
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_NEW,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if(hfile == INVALID_HANDLE_VALUE){
        DWORD error = GetLastError();
        if(error == ERROR_FILE_EXISTS) printf("File already exsist !");
        else printf("Error: %lu\n", error);
    }

    CloseHandle(hfile);

    return 0;
}
