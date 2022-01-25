#pragma once
#include <QElapsedTimer>

class GameTimer
{
private:
    QElapsedTimer timer;
    int lastRecordedTime = 0;

public:
    GameTimer();
    ~GameTimer();
    void startRecording();
    int getTimeElapsed();
};
