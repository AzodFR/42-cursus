#include "svc.hpp"

bool install()
{
    
    SC_HANDLE sv = OpenService(g_SCM, SVCNAME, SERVICE_ALL_ACCESS);
    if (sv != NULL) {
        cout << "Service already installed" << endl;
        CloseServiceHandle(sv);
        return false;
    }
    else {
        cout << "Installing..." << endl;
        char tinkyPath[MAX_PATH];

        if (!GetCurrentDirectory(MAX_PATH, tinkyPath))
        {
            cout << "GetCurrentDirectory failed: " << GetLastError() << endl;
            return false;
        }
        strcat_s(tinkyPath, SVCPATH);
        sv = CreateService(g_SCM, SVCNAME, SVCNAME, SERVICE_ALL_ACCESS, SERVICE_WIN32_OWN_PROCESS, SERVICE_AUTO_START, SERVICE_ERROR_IGNORE, tinkyPath, NULL, NULL, NULL, NULL, NULL);
        if (sv == NULL) {
            cout << "CreateService failed: " << GetLastError() << endl;
            return false;
        }
        else {
            cout << "Service installed" << endl;
            CloseServiceHandle(sv);
            return true;
        }
    }
    return true;
}

bool start()
{
    cout << "Starting..." << endl;
    return true;
}

bool stop()
{
    cout << "Stopping..." << endl;
    return true;
}

bool uninstall()
{
    SC_HANDLE sv = OpenService(g_SCM, SVCNAME, SERVICE_ALL_ACCESS);
    if (sv == NULL)
    {
        cout << "Service not installed" << endl;
        CloseServiceHandle(sv);
        return false;
    }
    else
    {
        cout << "Deleting..." << endl;
        if (DeleteService(sv) == 0)
        {
            cout << "DeleteService failed: " << GetLastError() << endl;
            CloseServiceHandle(sv);
            return false;
        }
        else
        {
            cout << "Service deleted" << endl;
            CloseServiceHandle(sv);
            return true;
        }
    }
}

int main(int ac, char **av)
{
    // Check for the correct number of arguments
    if (ac != 2) {
        error_usage();
    }

    // Declare pointers to functions
    bool (*func[])() = {install, start, stop, uninstall};
    
    
    // Check if args correspond to the function names
    vector<string> cmds = {"install", "start", "stop", "delete"};
    string cmd = av[1];
    bool no_error = true;
    if(!initSvcManager()) {
        return 1;
    }
    try {
        no_error = func[getIndexOf(cmds, cmd)]();
    }
    catch (...) {
        error_usage();
    }

    CloseServiceHandle(g_SCM);
    return no_error ? 0 : 1;
}