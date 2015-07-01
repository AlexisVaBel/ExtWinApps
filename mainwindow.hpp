#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QAction>
#include <QMainWindow>
#include "extLoader/cmn/winprocess.h"
#include "extLoader/visaeextprogramadd.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

signals:

public slots:
    void    selectApp();
    void    setAppName();
    void    startApp();
private:
    VisAEExtProgramAdd  *m_extSelector;
    WinProcess          *m_extProcess;

    QAction *m_actSetApp;
    QAction *m_actStartApp;

    QLabel  *m_lblMain;

    QString m_strApp;

    void    prepareVis();
    void    prepareWnd();
    void    prepareAct();
    void    prepareCon();
};

#endif // MAINWINDOW_H
