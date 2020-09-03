# Allegro Audio

I want to add some audio to both a CPP project and to a C Project.
So before having to deal with the general project complexities, I thought it was prudent to try and just load and play these sounds without any other distractions or things that could go wrong.

## Pre-requisites

A CPP and C compiler, Allegro 5 development installed, and CMake. I also used this project as an oppertunity to start transitioning over to using CMake - I have been impressed. 

# Code Structure

I have tried as much as possible to keep the code as close to each other as possible. There are slight differences in the Mutex invocation between C and CPP (nothing I can do about that), but both code-bases, do the same operations. Namely

  - Create a Thread
    - Thread Locks a Mutex
    - Thread Initializes the Allegro Env
    - Thread Plays Wav File
    - Thread Unlocks Mutea
    - Indicates Thread is done
  - While Waiting for a Mutex
    - Counter displayed
  - Unlock Mutex
  - join Thread
  - exit

You will have to change the AUDIO_FILE reference, I have not yet got to grips with Cmake enough to allow  
