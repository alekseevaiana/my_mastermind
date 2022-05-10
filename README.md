# Welcome to My Mastermind
***

## Task
Mastermind is a game composed of 8 pieces of different colors.
A secret code is then composed of 4 distinct pieces.

The player has 10 attempts to find the secret code.
After each input, the game indicates to the player the number of well-placed pieces and the number of misplaced pieces.

Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.

If the player finds the code, he wins, and the game stops.
A misplaced piece is a piece that is present in the secret code butthat is not in a good position.

You must read the player's input from the standard input.

Your program will also receive the following parameters:
-c [CODE]: specifies the secret code. If no code is specified, a random code will be generated.
-t [ATTEMPTS]: specifies the number of attempts; by default, the playerhas 10 attempts.

## Description
The program is written in C language.
I did the following steps:
- get options from the command
- if no options are provided, the program generates default options (for secret code I generated a random number)
- iterated through a loop with attempts and read user's input
- compared secret code and user's input (character by character)
- if users guessed all digits, they won
- if not, the program provides info about well-placed pieces and misplaced pieces and switches to a new round
- program checks if user provided the right input, if input has the wrong characters, user gets a message and switches to a new round

## Installation
- run `make`

## Usage
With no options (secret code is random and default attempts number is 10)
- run `./my_mastermind`
With options:
`./my_mastermind -t 5 -c 7543` where -t: attempts, and -c: secret code

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar Silicon Valley</a></i></span>
<span><img alt='Qwasar Silicon Valley Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
