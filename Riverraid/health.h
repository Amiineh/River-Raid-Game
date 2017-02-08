#ifndef HEALTH_H
#define HEALTH_H
#include<QObject>
#include<QGraphicsTextItem>

class Health : public QGraphicsTextItem
{
public:
    Health(QGraphicsItem* parent = 0);
    int getAmount() const;
    void setAmount(int value);
    void fill();
public slots:
    void decrease();
private:
    int amount;
};

#endif // HEALTH_H
