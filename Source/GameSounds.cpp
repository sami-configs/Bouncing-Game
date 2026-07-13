#include "GameSounds.h"

GameSounds::GameSounds() : 
music_("Content/Music.mp3"),
bounceSoundBuffer_("Content/Bounce.mp3"),
bounceSound_(bounceSoundBuffer_)

{
    music_.setVolume(20);
    music_.setLooping(true);
    music_.play();

    bounceSound_.setVolume(90);
}

void GameSounds::PlayBounceSound()
{
    bounceSound_.play();
}