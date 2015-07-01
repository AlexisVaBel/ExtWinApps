#include "visaeextprogramadd.h"

#include <QFileDialog>
#include <QGridLayout>
#include <QLabel>

#include <QDebug>
VisAEExtProgramAdd::VisAEExtProgramAdd(QWidget *parent) :
    QDialog(parent){
    initView();
    initSignSlots();
    m_strPath="D://promauto-src/Work_shd/WesClient";
}

void VisAEExtProgramAdd::selectApp(){    
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open Exe"), m_strPath, tr(" (*)"));
    m_edtPath->setText(fileName);
    m_strCapr=m_edtCapt->text();
    m_strPath=m_edtPath->text();
    m_strEXT =m_strPath.right(m_strPath.length()-m_strPath.lastIndexOf('.'));
    m_strName=m_strPath.right(m_strPath.length()-m_strPath.lastIndexOf('/')-1);
    m_strName=m_strName.left(m_strName.lastIndexOf('.'));
    m_strPath=m_strPath.left(m_strPath.lastIndexOf('/')+1);
    if(m_edtCapt->text().isEmpty())m_edtCapt->setText(m_strName);
}

void VisAEExtProgramAdd::accptPressed(){
    if(m_edtCapt->text().isEmpty())m_strCapr=m_strName;
    else
        m_strCapr=m_edtCapt->text();    
    emit accept();
}

void VisAEExtProgramAdd::initView(){
    QLabel *lblPath = new QLabel(QString::fromLocal8Bit("Укажите файл"));
    QLabel *lblCap  = new QLabel(QString::fromLocal8Bit("Укажите заголовк окна"));
    m_edtPath       = new QLineEdit();
    m_edtCapt       = new QLineEdit();
    m_btnOk         = new QPushButton(QString::fromLocal8Bit("ОK"));
    m_btnCancel     = new QPushButton(QString::fromLocal8Bit("Отмена"));
    m_btnCheckFile  = new QPushButton("...");

//    // группировка
    QGridLayout *ltEdt = new QGridLayout();
    ltEdt->setSpacing(3);
    ltEdt->addWidget(lblPath        , 0,0);
    ltEdt->addWidget(m_edtPath      , 1,0,1,3);
    ltEdt->addWidget(m_btnCheckFile , 1,4,1,1);
    ltEdt->addWidget(lblCap         , 2,0);
    ltEdt->addWidget(m_edtCapt      , 3,0,1,2);

//    // группировка кнопок
    QHBoxLayout *ltBtn = new QHBoxLayout();
    ltBtn->setMargin(5);
    ltBtn->setSpacing(5);
    ltBtn->addStretch();
    ltBtn->addWidget(m_btnOk);
    ltBtn->addWidget(m_btnCancel);

//    // общая группировка
    QVBoxLayout *ltMain = new QVBoxLayout();
    ltMain->setMargin(5);
    ltMain->setSpacing(5);
    ltMain->addLayout(ltEdt);
    ltMain->addLayout(ltBtn);

    setLayout(ltMain);
    setWindowTitle(QString::fromLocal8Bit("Редактор внешних приложений"));
    setModal(true);
    setFixedSize(300, 140);
}

void VisAEExtProgramAdd::initSignSlots(){
    connect(m_btnOk         ,SIGNAL(clicked()),this,SLOT(accptPressed()));
    connect(m_btnCancel     ,SIGNAL(clicked()),this,SLOT(reject()));
    connect(m_btnCheckFile  ,SIGNAL(clicked()),this,SLOT(selectApp()));
}

void VisAEExtProgramAdd::showEvent(QShowEvent *){    
//    m_strName.clear();
//    m_strEXT.clear();
//    m_strCapr.clear();
}
