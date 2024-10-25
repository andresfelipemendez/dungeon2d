#pragma once
struct GameState {
    int playerPosition;
    int score;
    bool shouldExit;
};

#define EXPORT extern "C" __declspec(dllexport)
