#ifndef WINPROCESS_H
#define WINPROCESS_H


#include <windows.h>
#include "extprocess.h"
#include <QString>
#include <QObject>
static const int TITLE_LNG=1024;

BOOL CALLBACK HandleWindow(HWND hWnd, LPARAM lParam);

class WinProcess:public ExtProcess{
Q_OBJECT
public:
    WinProcess(QObject *obj=0);
    void       setHWND(HWND hWnd){m_handleWnd=hWnd;}
        // ExtProcess interface
public:
    void *getProcessIdent();
private:
    void       getOpenedWins();
    HWND       m_handleWnd;
};

#endif // WINPROCESS_H

