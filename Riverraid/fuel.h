#ifndef FUEL_H
#define FUEL_H

class Fuel: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Fuel();

public slots:
    void move();
private:
    int hitScore;
};

#endif // FUEL_H
