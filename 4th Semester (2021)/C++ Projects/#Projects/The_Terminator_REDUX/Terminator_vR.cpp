#include <iostream>
#include <string>
#include<tchar.h>
#include <process.h>
#include <windows.h>
#include <tlhelp32.h>

using namespace std;

//  Forward declarations:
BOOL GetProcessList();
BOOL TerminateMyProcess(DWORD dwProcessId, UINT uExitCode);

int main( void )
{
	cout << "======================" << endl;
	cout << "\n - Terminator v5" << endl;
	cout << "----------------------" << endl;
	cout << "\n - Killing Tasks ..." << endl;
  GetProcessList( );
  return 0;
}

BOOL GetProcessList( )
{
  HANDLE hProcessSnap;
  HANDLE hProcess;
  PROCESSENTRY32 pe32;
  DWORD dwPriorityClass;

  // Take a snapshot of all processes in the system.
  hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
  if( hProcessSnap == INVALID_HANDLE_VALUE )
  {   
    return( FALSE );
  }

  // Set the size of the structure before using it.
  pe32.dwSize = sizeof( PROCESSENTRY32 );

  // Retrieve information about the first process,
  // and exit if unsuccessful
  if( !Process32First( hProcessSnap, &pe32 ) )
  {   
    CloseHandle( hProcessSnap );  // clean the snapshot object
    return( FALSE );
  }

  // Now walk the snapshot of processes 
  do
  {  
  
    string str(pe32.szExeFile);

    if(str == "chrome.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "adb.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "IDMan.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "TeamViewer_Service.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "TeamViewer.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "tv_w32.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "tv_x64.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "WinStore.App.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "sidebar.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "reader_sl.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "jqs.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "PhraseExpress.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "Connectify.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "vpn-unlimited.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "ConnectifyGopher.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "UninstallMonitor.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "vpn-unlimited-daemon.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "IUService.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "Osa.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "soffice.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "MEGAsync.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "AdobeARM.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "Jusched.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "AAM Update Notifier.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "DivXUpdate.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "Connectifyd.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "ConnectifyService.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "ConnectifyNetServices.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "DriverSwitcher.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "ConnectifySupportCenter.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "wmpnetwk.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "SkypeHost.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "GTAVLauncher.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "SearchFilterHost.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "SearchIndexer.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "SearchProtocolHost") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "taskhost.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "WmiPrvSE.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "PnkBstr.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "PnkBstrA.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "PnkBstrB.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "audiodg.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "taskeng.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "WmiPrvSE.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "firefox.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "chrome.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "opera.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "browser_assistant.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "GoogleUpdate.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "opera_crashreporter.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "MpCmdRun.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "Steam.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "steamwebhelper.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "dllhost.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "WUDFHost.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "CCleaner64.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "IEMonitor.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "WSHelper.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "unsecapp.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "PCRepairKit.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "winwfpmonitor.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "WmiPrvSE.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "fdm.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "boinc.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "charityengine.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "jusched.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "wuapihost.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "WmiPrvSE.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "ShellExperienceHost.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "WUDFHost.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "spoolsv.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "RuntimeBroker.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "FlashUtil32_29_0_0_171_Plugin.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "ONENOTEM.EXE") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "KMS-R@1n.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "KMS-R@1nHook.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "SppExtComObj.Exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "sedsvc.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "MicrosoftEdge.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "MicrosoftEdgeCP.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "MicrosoftEdgeSH.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "IDMIntegrator64.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "chrome.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "Integrator.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "OpenWith.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "RuntimeBroker.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "fireshot-chrome-plugin.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "wsl.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "kali.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "vcxsrv.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "CefSharp.BrowserSubprocess.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "MsMpEng.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "HelpPane.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "Monitor.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "ASC.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "ActionCenterDownloader.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "About.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "ASCDownload.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "ASCTray.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "ASCVER.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "AutoCare.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "AutoRamClean.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "ASCService.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "DriverBooster.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "SmartDefrag.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "Scheduler.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "MpCmdRun.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "MsMpEng.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "GameBar.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "ShareX.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "GameBar.exeGameBar.exeGameBar.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    
    if(str == "GameBarFT.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    }
	
    if(str == "WsAppService.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    if(str == "WinStore.App.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    if(str == "CefSharp.BrowserSubprocess.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    if(str == "msedge.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    }
    if(str == "nordvpn-service.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    if(str == "ASHelper.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    if(str == "EBCClient.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    if(str == "Agent.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    if(str == "GoogleCrashHandler64.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    if(str == "GoogleCrashHandler.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    if(str == "GoogleUpdate.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    if(str == "vmcompute.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    if(str == "KMS-R@1n.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    if(str == "KMS-R@1n.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    } 
    if(str == "MicrosoftEdgeUpdate.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    }
    if(str == "OfficeClickToRun.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    }
    if(str == "TextInputHost.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    }
    if(str == "RzSurroundVADStreamingService.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    }
    if(str == "TodoBackupService.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    }
    if(str == "spoolsv.exe") // put the name of your process you want to kill
    {
        TerminateMyProcess(pe32.th32ProcessID, 1);
    }
    
     
    
  } 
  while( Process32Next( hProcessSnap, &pe32 ) );
  
  cout << "----------------------" << endl;
  cout << "\n - Process Completed" << endl;
  cout << "\n - Listed Tasks Killed Successfully!" << endl;

  CloseHandle( hProcessSnap );
  return( TRUE );
}

BOOL TerminateMyProcess(DWORD dwProcessId, UINT uExitCode)
{
    DWORD dwDesiredAccess = PROCESS_TERMINATE;
    BOOL  bInheritHandle  = FALSE;
    HANDLE hProcess = OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId);
    if (hProcess == NULL)
        return FALSE;

    BOOL result = TerminateProcess(hProcess, uExitCode);

    CloseHandle(hProcess);

    return result;
}
