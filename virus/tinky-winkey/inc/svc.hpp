#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <winsvc.h>

#define SVCNAME "tinky"
#define SVCPATH "\\tinky.exe"

using namespace std;

SC_HANDLE g_SCM;

bool initSvcManager()
{
    g_SCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (g_SCM == NULL) {
        cout << "OpenSCManager failed: " << GetLastError() << endl;
        return false;
    }
    return true;
};

int getIndexOf(vector<string> &v, string &s)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] == s)
        {
            return i;
        }
    }
    throw "Not found";
}

void error_usage()
{
    cout << "Usage: svc < install | start | stop | uninstall >" << endl;
    exit(1);
}