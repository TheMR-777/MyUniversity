#include <QCoreApplication>
#include <QDebug>

class Persona: public QObject
{
protected:
    std::string_view m_name = "N/A";
    Persona(std::string_view data) : m_name(data) {}
};

struct Captain: Persona
{
    Captain(const char* data) : Persona(data) {}
    Q_OBJECT
signals:
    void call_everyone(std::string_view) const;
};

struct Partner: Persona
{
    Partner(const char* data) : Persona(data) {}
    Q_OBJECT
public slots:
    void respond(std::string_view data) const
    {
        qDebug() << m_name.data() << "Responding, for" << data.data();
    }
};
