***Card games Version Alpha 1.0.0***
This project aims to bring you Red Dead Redemption 2 style card games 


Usage

	-This program uses number based menu for user input.
    -Remember to size up the cmd window to so everything fits!
    -You should put the exe into a floder because it creates a wallet file.
    -Play some card games and enjoy!

Features

    - RDR2 styled Blackjack
    - Texas hold'em poker (WIP)

Changelog

	- Alpha 1.0.0 Very basic verision of blackjack with very basic ai

<pre>Card-Games/ 
            ├── CMakeLists.txt - CMake file.
            ├── menu.cpp - Main logic of the program.
            ├── readme.md - Program's documentation.
            ├── TODO.txt - Todo list.
            core/
                  ai/
                     blackjack/
                              ├── ai_blackjack.h - File that is going to contain more complex ai logic.
                     texas_hold'em/
                  ASCII_cards/ -Every one of these folders will include every card in ASCII format. (there is just too many of those to list here)
                              clubs/
                              diamonds/
                              hearts/
                              spades/
                  games/
                        blackjack/
                                 ├── blackjack.h - This file contains main blackjack logic.
                                 ├── blackjack_functions.h - This file contains functions used for blackjack game.
                                 ├── blackjack_variables.h - This file contains variables for the blackjack.h file.
                                 ├── imports_blackjack.h - This file includes all of local files that should be included in blackjack.h file.
                                 ├── ui_blackjack.h - This file contains ui for the blackjack game.
                        blackjack_multiplayer/
                        texas_hold'em/
                        texas_hold'em multiplayer/
                  names/
                        ├── names.h - This file will contain names for characters.
                  objects/
                        ├── cards.h - This file contains enums and structs relating to cards.
                        ├── characters.h - This file contains structs relating to characters.
                  tutorials/
                           blackjack/
                                    ├── blackjack_tutorials.h - This file contains information on rule of blackjack etc.
                           texas_holdem/
                  utilities/
                           ├── utilities.h - This file contains utility functions for the program such as clear screen.

</pre>

Future Ideas

1. Adding linux support

2. Game Mechanics

   Blackjack and Other Games: Include detailed instructions on how to play Blackjack and other games. In the input capture interface,
   implement color indicators where green signifies an available action and red indicates an unavailable action.

3. Difficulty Levels

   Easy vs Hard AI: Implement two difficulty levels for the AI:

        Easy: The AI makes random decisions.

        Hard: The AI uses tactical strategies, including character traits for multiple players, to make more calculated decisions.

4. Wallet System

   Wallet Implementation: Create a system where players start with a specific amount of in-game currency (e.g., $20). Players can earn or lose money by playing games.

        The wallet balance should be saved in a file to persist across sessions.

        If the wallet balance falls below $20, it should automatically replenish to a preset amount.

        Track and display the highest wallet balance the player has achieved.

5. Stakes-Based Games

   Stakes Variations: Implement different stake games, each with varying levels of risk and rewards.
   The UI should adapt to reflect the theme and atmosphere of each game, such as a more refined, upscale environment like Saint Denis in the game.

6. Make versions of these games that could be played in multiplayer.

7. I might add a Polish translation in the future. 

