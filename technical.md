# Technical Doc

- New Components
  - KeyTracker
    - Very Simple component used to keep track of the key item.
  - Key
    - Very Simple component for the key interactable. Which keeps track of the players position and deletes itself when the player is close.
  - Sound
    - A component for playing sounds based on what is being done.
      - Player Sound Component, plays a sound when the player jumps and activates their jetpack.
  
- Fully Functional Game
  - The game is playable with the player able to navigate the procedural environment and collect keys to beat the stage.
  - Stage 2 is hand made using a previous generation of the cellAuto library.
  - After stage 2 it loads back to stage 1 which will have a completely new layout.


- AI
  - As it stand ai in the main branch of this project is untouched I spent a decent bit of time attempting to implement a* pathfinding by my own means and through the use of a generic library which i will link at the end of this section.
  - I ran into several issues and problems and ultimately ended up sinking too much time into attempting to make it work.
  - The attempt at this work is present on the astar branch but ultimately i was not able to get it to work.
  
- Memory Management
  - Outside of using smart pointers for player and the keytracker there is no other heavy use of memory management throughout the project.
  - At the end of the scene all shared pointers are reset.

- Management of Game Resources
  - Sound is mostly handled by the sound components but the audio used by them is output using sfml audio

- Common Errors
