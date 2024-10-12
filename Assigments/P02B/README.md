## P02B - Class Design Assignment
### Ashley Flores
### Description:

This assignment involves designing a set of classes for a digital version of the game Knucklebones. It focuses on organizing the various components of the game, such as players, dice, and the game itself, and defining their relationships. The design process includes determining when to apply composition and inheritance, while considering the "IS-A" rule discussed in class.In this initial design phase, actions, data, and the organization of each class are outlined in bulleted lists, without the need for formal UML diagrams at this stage. The objective is to thoughtfully structure the game’s elements before moving on to implementation.

### Dice Class:
  -Data:
  - `sides` : Number of sides on a dice (6)
    
  - `current_value` : Value after rolling the dice.
    
  -Actions:
  -  `roll()` : Simulation of the dice being rolled
    
  - `get_value` : Gets and returns the value currently on the dice
    
  -Relationship: Dice will be used by the Player to roll during the game.
  
    
### Player Class:
  -Data:
  - `name` : Player's game name
    
  - `score` : Current score of the player
    
  - `dice_set` : Array of 2 Dice
    
  - `player_stats` : Possibly have player's stats as they play the game
    
  -Actions:
  - `roll_dice()` : Roll dice for the player and returns value
    
  - `get_score()` : Get/Retrieve the current score
    
  - `update_score()` : Update the player's score after each roll
    
  -Relationships: Each player has a set of dice and participates in the game.
  -A Player HAS-A Dice (composition)
    
  -A Player IS-A participant in the game (inheritance)
  
### Game Classes:
  -Data:
  - `vector <player> players` : a dynamic array that can resize depending on the number of people playing
    
  - `vector <int> score` : a dynamic array keeping track of the scores of the players
    
  - `rules` : gives the rules of the average game
    
  - `current_round` : indicates the current round/level being played
    
  -Actions:
  - `start_game()` : starts the game and players
    
  - `end_game()` : ends the game
    
  - `get_winner()` : determines the winner by seeing which player has the highest score
    
  -Relationships: The Game class controls the players and their actions.

### Knucklebones:
  -Data:
  - `board` : a 3X3 grid
    
  - `knucklebones_specific_rules` : gives rules specifically for knucklebones(2 players, dice rolling, placing dice, scoring rules, opponents dice removal, etc.)
    
  - `start_round()` : knucklebones round starts
    
  - `end_round()` : knucklebones current round ends
    
  - `get_winner` : determines the winner by seeing who has the highest score
    
  -Relationships: Inherits from Game, as Knucklebones is a game with specific rules and conditions.

## Necessary:
-coins
-first name
-last name
-score
-winner
-player stats
-user id

## Possible:
-messaging
-high score
-leader board

## Wishful:
-chat
-levels
-streak
-teams
-team stats
