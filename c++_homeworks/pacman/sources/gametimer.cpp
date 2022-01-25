
#include "../headers/gametimer.h"

GameTimer::GameTimer()
{
    timer.start();
}

void GameTimer::startRecording()
{
    lastRecordedTime = timer.elapsed();
}

int GameTimer::getTimeElapsed()
{

    int timeElapsed = timer.elapsed() - lastRecordedTime;
    return timeElapsed;
}