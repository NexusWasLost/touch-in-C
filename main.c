#include <stdio.h>
#include <windows.h>

void displayErrMsg(const wchar_t* argv, DWORD error){
    switch(error){
        case ERROR_FILE_EXISTS:
            wprintf(L"File %ls already exsist !\n", argv);
            break;

        case ERROR_PATH_NOT_FOUND:
            wprintf(L"Cannot create %ls in specified path because it does not exists !\n", argv);
            break;

        case ERROR_DIRECTORY:
            wprintf(L"Cannot create %ls because directory name is invalid or you put something at the end that is not supposed to be there !\n", argv);
            break;

        default:
            printf("Error: %lu\n", error);
            break;
    }
}

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
            displayErrMsg(argv[count], error);
            continue; //exit early! Beecause it failed, there is no handle to close !
        }

        CloseHandle(hfile);
    }

    return 0;
}
