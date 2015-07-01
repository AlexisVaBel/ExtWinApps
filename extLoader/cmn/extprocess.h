#ifndef EXTPROCESS_H
#define EXTPROCESS_H

#include <QObject>

class ExtProcess : public QObject
{
    Q_OBJECT
public:
    explicit   ExtProcess(QObject *parent = 0);
    void       setNeedCaption(QString str)  {m_strProcess=str;}
    QString    getNeedCaption()             {return m_strProcess;}
    bool       isProcessWrk()               {return m_bProcessWrk;}
    virtual    void *     getProcessIdent()=0;

    bool       m_bProcessWrk;
    QString    m_strProcess;
};

#endif // EXTPROCESS_H



