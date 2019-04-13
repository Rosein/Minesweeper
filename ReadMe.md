# Minesweeper game

Uses SFML library.

Play like original minesweeper. 

First choose the level. Than play. Clicking on head restarts the game.

If you win a table with best scores at your level will be shown.

## Compilation

Under Linux:
From build folder run the terminal and type:

	cmake ..

	make

	./Minesweeper

The game will start!

You need to have installed SMFL library. Eventually you need to update in cmake the path to FindSFML.cmake on your computer.

## TDD

Game was created using TDD development process.

## Planned Updates

- [x] when clicked on empty field - all attacheched empty fields and surrounding fields with numbers should appear
- [x] when clicked on bomb - game is over and lost
- [x] when all fields apart of bombs are displayed - game is over and won
- [x] display amount of bombs left to find
- [x] add time counter
- [x] add best scores list
- [x] make head icon like in original Minesweeper
- [x] add level choosing



## Images:
<p align="center">
<br>At the beginning you need to choose the level:<br>
  <img src="https://user-images.githubusercontent.com/25400249/56082957-54ba3f80-5e1f-11e9-9e6a-8be9bfd0c6b5.png" width="300"/>
<br>When you start:<br>
  <img src="https://user-images.githubusercontent.com/25400249/55627796-5779bc80-57af-11e9-953e-cd79fb980c4d.png" width="500"/>
<br>When you lost:<br>
  <img src="https://user-images.githubusercontent.com/25400249/55627798-58125300-57af-11e9-8c76-24a516bfaa22.png" width="500"/>
<br>When you won:<br>
  <img src="https://user-images.githubusercontent.com/25400249/56082956-5421a900-5e1f-11e9-85d9-05e8724884fa.png" width="300"/>
<br>And after you clicked OK:<br>
  <img src="https://user-images.githubusercontent.com/25400249/55627799-58125300-57af-11e9-9d5f-544eb05d4769.png" width="500"/>

</p>