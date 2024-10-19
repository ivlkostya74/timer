#include "stopwatch.h"

Stopwatch::Stopwatch()
    : previousLapTime(0),
    running(false)
{
}

void Stopwatch::start()
{
    if (!running) {
        timer.start();
        running = true;
    }
}

void Stopwatch::stop()
{
    if (running) {
        previousLapTime += timer.elapsed() / 1000.0;
        running = false;
    }
}

void Stopwatch::reset()
{
    previousLapTime = 0;
    lapTimes.clear();
    running = false;
}

int Stopwatch::lap()
{
    qreal currentLapTime = elapsedTime();
    lapTimes.append(currentLapTime - previousLapTime);
    previousLapTime = currentLapTime;
    return lapTimes.size();
}

qreal Stopwatch::lastLapTime() const
{
    if (!lapTimes.isEmpty()) {
        return lapTimes.last();
    }
    return 0;
}

bool Stopwatch::isRunning() const
{
    return running;
}

qreal Stopwatch::elapsedTime() const
{
    if (running) {
        return previousLapTime + timer.elapsed() / 1000.0;
    } else {
        return previousLapTime;
    }
}
