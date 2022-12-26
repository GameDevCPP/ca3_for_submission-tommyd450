# Game Design document

In the following document, if you used a particular game design pattern in a section, please describe it (a brief description will do) and how you used it. Code snippets may help with this.
In addition to this outline, I have an example of short design document from Richard McKenna titled: "Spiked Acid Game Design Document", which helped inform this document.

## Introduction
* This document will detail Caver a procedurally generated 2d cave exploration game.


## Technology
* Which platform(s)?
* Game engine/software library (obviously SFML plus framework plus your own additions and external libraries - describe them all in a general fashion).
* The frame work being used is centered around sfml and several libraries which work in tandem for creating tile maps using sfml shapes.
* A new library called the cell auto library was created for use in creating random cave levels using basic cellular automata rules.
* This library is also responsible for placement of collectibles and enemies as well as the player.

## Objective
* The player must collect 10 keys to escape the level through a red tile which is the exit.


## Gameplay
- Describe how your game works in general - see the "Spiked Acid Game Design Document"

## Levels
* The levels of caver are procedurally generated using a cellular automata library created for this project.
* The method used is cellular automata which is uses basic neighbour count rules to determine which cells are kept and deleted.
* These cells are output into a text file in accordance with the tile system library prresent in the projet.


## Controls
* Mouse and or keyboard (other controller)
  - how was it implemented
- Controls
- Left Arrow
  - Player movement to the left.
- Right Arrow
  - Player movement to the right.
- Up Arrow
  - Player Jump.
- Space
  - Activate the players jetpack in the air, Allows for upwards traversal through the cave.

  

## Artwork
* No textures are utilised in this project.


## Sound (sound effects)
* Using sfml and the entity component model sounds are implemented using an ecm family.
* For player effects and item collection


## Music
* Describe the music used and its source/origin
* Is there a menu track, and a track for main game (level).
* Is the music randomly chosen for each game.
