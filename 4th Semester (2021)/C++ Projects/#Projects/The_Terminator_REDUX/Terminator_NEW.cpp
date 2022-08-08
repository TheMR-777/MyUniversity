#include <iostream>
#include <tchar.h>
#include <process.h>
#include <windows.h>
#include <tlhelp32.h>
#include <string>
#include <array>
using namespace std;

BOOL TerminateMyProcess(DWORD dwProcessId, UINT uExitCode)
{
    DWORD dwDesiredAccess = PROCESS_TERMINATE;
    BOOL  bInheritHandle = FALSE;
    HANDLE hProcess = OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId);
    if (hProcess == NULL)
        return FALSE;

    BOOL result = TerminateProcess(hProcess, uExitCode);

    CloseHandle(hProcess);

    return result;
}

BOOL GetProcessList(const vector<string>& target)
{
    HANDLE hProcessSnap;
    HANDLE hProcess;
    PROCESSENTRY32 pe32;
    DWORD dwPriorityClass;

    // Take a snapshot of all processes in the system.
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE)
    {
        return FALSE;
    }

    // Set the size of the structure before using it.
    pe32.dwSize = sizeof(PROCESSENTRY32);

    // Retrieve information about the first process,
    // and exit if unsuccessful
    if (!Process32First(hProcessSnap, &pe32))
    {
        CloseHandle(hProcessSnap);  // clean the snapshot object
        return(FALSE);
    }

    // Now walk the snapshot of processes 
    do
    {
        string str(pe32.szExeFile);

        if (str == target[0]) // put the name of your process you want to kill
        {
            TerminateMyProcess(pe32.th32ProcessID, 1);
        }
    }
    while (Process32Next(hProcessSnap, &pe32));

    cout << "----------------------" << endl;
    cout << "\n - Process Completed" << endl;
    cout << "\n - Listed Tasks Killed Successfully!" << endl;

    CloseHandle(hProcessSnap);
    return(TRUE);
}

int main()
{
    cout << "======================" << endl;
    cout << "\n - Terminator v5" << endl;
    cout << "----------------------" << endl;
    cout << "\n - Killing Tasks ..." << endl;

    vector<string> V
    {
        "qbittorrent.exe"
    };

    GetProcessList(V);
    return 0;
}
