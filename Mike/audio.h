#ifndef AUDIO_H
#define AUDIO_H

#include "SDL/SDL_mixer.h"

// game audio
extern Mix_Music *music;// = NULL;

  // Sound Effects
extern Mix_Chunk *roll;// = NULL;
extern Mix_Chunk *gamePause;// = NULL;
extern Mix_Chunk *purchase;// = NULL;
extern Mix_Chunk *trade;// = NULL;
extern Mix_Chunk *penalty;// = NULL;


inline void gameMusic(){
  
  if (Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    std::cout << "ERROR OPENING AUDIO LIBRARY" << std::endl;

  // load music 
  music = Mix_LoadMUS( "data/monopoly.wav" );
  roll = Mix_LoadWAV( "data/roll.wav" );
  // Play the music
  Mix_PlayMusic(music, -1);

  
}

inline void closeMusic(){
  Mix_FreeChunk( roll );
  Mix_FreeChunk( gamePause );
  Mix_FreeChunk( purchase );
  Mix_FreeChunk( trade );
  
  Mix_FreeMusic( music );

  Mix_CloseAudio();
}


#endif
