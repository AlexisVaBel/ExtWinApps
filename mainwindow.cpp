#include "mainwindow.hpp"
#include <QToolBar>

#include <QDebug>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    prepareWnd();
    prepareVis();
    prepareAct();
    prepareCon();
}

void MainWindow::selectApp(){
    m_extSelector->show();
}

void MainWindow::setAppName(){
    m_strApp=m_extSelector->m_strCapr;
    qDebug()<<m_strApp;
    qDebug()<<m_extSelector->m_strPath;
    qDebug()<<m_extSelector->m_strName;
    qDebug()<<m_extSelector->m_strEXT;
}

void MainWindow::startApp(){
    QString strWork=m_strApp;
    qDebug()<<m_strApp;
    HWND handleWnd=0;
    HWND parentWnd=0;

// calling external application
    if(!strWork.isEmpty()){
        m_extProcess->setNeedCaption(strWork);
        handleWnd=(HWND) m_extProcess->getProcessIdent();
    }
    if(handleWnd!=0){
        parentWnd=GetWindow(handleWnd,GW_OWNER);
        ShowWindow(parentWnd,SW_SHOWDEFAULT);
        SetForegroundWindow(parentWnd);
    }else{
        strWork=m_extSelector->m_strPath+m_extSelector->m_strName+m_extSelector->m_strEXT;
        WinExec(strWork.toLocal8Bit(),SW_SHOW);
        m_extProcess->setNeedCaption(m_strApp);
        handleWnd=(HWND) m_extProcess->getProcessIdent();
        handleWnd=GetWindow(handleWnd,GW_OWNER);
        parentWnd=((HWND)(m_lblMain->winId()));
        if(parentWnd!=0)SetParent(handleWnd,parentWnd);
    }
//! calling external application
}

void MainWindow::prepareVis(){
    m_lblMain=new QLabel();
    setCentralWidget(m_lblMain);
}

void MainWindow::prepareWnd(){
    m_extProcess    =new WinProcess();
    m_extSelector   =new VisAEExtProgramAdd();
}

void MainWindow::prepareAct(){
    m_actSetApp     = new QAction(this);
    m_actStartApp   = new QAction(this);

    QToolBar    *toolBar=new QToolBar();
    toolBar->addAction(m_actSetApp);
    toolBar->addAction(m_actStartApp);
    addToolBar(toolBar);

    m_actSetApp->setText("set_app");
    m_actStartApp->setText("start_app");
}

void MainWindow::prepareCon(){
    connect(m_actSetApp,SIGNAL(triggered(bool)),SLOT(selectApp()));
    connect(m_actStartApp,SIGNAL(triggered(bool)),SLOT(startApp()));
    connect(m_extSelector,SIGNAL(accepted()),SLOT(setAppName()));
}

