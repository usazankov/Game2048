#ifndef BAR_H
#define BAR_H
#include <QObject>

class Bar: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int numeric READ numeric WRITE setnumeric NOTIFY numericChanged)
    Q_PROPERTY(int identificator READ identificator WRITE setidentificator NOTIFY identificatorChanged)
    Q_PROPERTY(int ix READ ix WRITE setix NOTIFY ixChanged)
    Q_PROPERTY(int iy READ iy WRITE setiy NOTIFY iyChanged)
public:
    explicit Bar(QObject *parent = 0);
    explicit Bar(const Bar& b);
    int numeric() const;
    int ix() const;
    int iy() const;
    virtual ~Bar(){}
    int identificator() const;
    Bar& operator =(const Bar& b)
    {
        //проверка на самоприсваивание
        if (this == &b) {
            return *this;
        }
        m_identificator = b.m_identificator;
        m_numeric = b.m_numeric;
        m_ix = b.m_ix;
        m_iy = b.m_iy;
        return *this;
    }
    friend bool operator==(const Bar& left, const Bar& right)
    {
        return left.m_identificator == right.m_identificator;
    }
public slots:
    void setnumeric(int numeric);
    void setix(int ix);
    void setiy(int iy);
    void setidentificator(int identificator);

signals:
    void numericChanged(int numeric);
    void ixChanged(int ix);
    void iyChanged(int iy);
    void identificatorChanged(int identificator);

private:
    //Идентификатор бара
    int m_identificator;
    //Число бара
    int m_numeric;
    //Индекс по x
    int m_ix;
    //Индекс по y
    int m_iy;
};

#endif // BAR_H
