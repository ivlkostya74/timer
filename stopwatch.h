#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QElapsedTimer>
#include <QVector>

class Stopwatch
{
public:
    Stopwatch();

    void start();
    void stop();
    void reset();
    int lap();              // Метод для записи круга
    qreal lastLapTime() const; // Возвращает время последнего круга
    bool isRunning() const;
    qreal elapsedTime() const; // Возвращает текущее время

private:
    QElapsedTimer timer;
    QVector<qreal> lapTimes; // Список времен кругов
    qreal previousLapTime;   // Время предыдущего круга
    bool running;            // Флаг состояния секундомера
};

#endif // STOPWATCH_H
