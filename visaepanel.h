#ifndef VISAEPANEL_H
#define VISAEPANEL_H

#include "../../Base/component.h"

const int VisAEPanelRole = Qt::UserRole;


class VisAEPanel : public Component
{
    Q_OBJECT

    Q_PROPERTY(QString title READ title WRITE setTitle)


public:
    explicit VisAEPanel(QObject *parent = 0);

    QString title() const { return m_title; }

    virtual QWidget *panel() { return 0; }

signals:
    
public slots:
    void setTitle(QString arg) { m_title = arg;  }

private:
    QString m_title;

};

#endif // VISAEPANEL_H
