#ifndef VISAEEXTPROGRAMADD_H
#define VISAEEXTPROGRAMADD_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>

class VisAEExtProgramAdd : public QDialog
{
    Q_OBJECT
public:
    explicit VisAEExtProgramAdd(QWidget *parent = 0);

    QString     m_strPath;
    QString     m_strName;
    QString     m_strEXT;
    QString     m_strCapr;

signals:
public slots:
    void    selectApp();
    void    accptPressed();
private:
    QLineEdit   *m_edtPath;
    QLineEdit   *m_edtCapt;
    QPushButton *m_btnOk;
    QPushButton *m_btnCancel;
    QPushButton *m_btnCheckFile;

    void initView();
    void initSignSlots();

    // QWidget interface
protected:
    void showEvent(QShowEvent *);
};

#endif // VISAEEXTPROGRAMADD_H
