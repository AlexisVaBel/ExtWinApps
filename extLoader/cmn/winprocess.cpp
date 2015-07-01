#include "winprocess.h"
#include <qdebug.h>
#include <Winuser.h>

BOOL CALLBACK HandleWindow(HWND hWnd, LPARAM lParam){
    QString     strCaption,strNeedCaption;
    WCHAR       title[TITLE_LNG];
    WinProcess *winProcs=reinterpret_cast<WinProcess*>(lParam);
    GetWindowText(hWnd,title,sizeof(title));
    for(int i=0;i<TITLE_LNG;i++){
        strCaption.append(title[i]);
    };
    if(winProcs!=0){
        strNeedCaption=winProcs->getNeedCaption();
        strCaption=strCaption.trimmed();
        //qDebug()<<"Need caption"<<strNeedCaption<<strCaption.length()<<strNeedCaption.length();
        if((strCaption.contains(strNeedCaption,Qt::CaseInsensitive))){
            winProcs->setHWND(hWnd);
//            qDebug()<<"Found Wind"<<strCaption;
            return false;
        }
    }
//    qDebug()<<"Wind title"<<strCaption;
    return true;
}

WinProcess::WinProcess(QObject *obj){
}

void *WinProcess::getProcessIdent(){
    if(m_strProcess.isEmpty())return 0;
    getOpenedWins();
    return m_handleWnd;
}

void WinProcess::getOpenedWins(){
    m_handleWnd=0;
    EnumWindows(&HandleWindow,reinterpret_cast<LPARAM> (this));
}
