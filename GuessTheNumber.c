#include <stdio.h>
#include <string.h>

void displayTitle() { //functions need to be declared before the main because if not, c might complain that it did not know the function.
    printf("==================\n");
    printf("|Guess The Number|\n");
    printf("==================\n");
}

void gameMode(){
  char gamemode [8];
  printf("How hard do you want the game to be?\n");
  printf("Easy (1-10), Medium (1-50), Hard (1-100), God Mode (1-1000), Custom\n");
  printf("-");
  scanf("%7s", gamemode);

  if (_stricmp(gamemode, "Easy") == 0){
    printf("You picked Easy!");
  } 
  else if (_stricmp(gamemode, "Medium") == 0){
    printf("You picked Medium!");
  }else if (_stricmp(gamemode, "Hard") == 0){
    printf("You picked Hard!");
  }else if (_stricmp(gamemode, "God Mode") == 0){
    printf("You picked God Mode!");
  }else{
    printf("Seems like you didnt put in any of the choices, lets run it back");
    gameMode();
  }
  
  
}

int main() {
  displayTitle();

  char start;

  printf("Are you ready to start guessing? (Y/N):");
  scanf(" %c", &start);

  if (start == 'Y' || start == 'y'){
      printf("\nLet's Get Started!\n");
      gameMode();
    }
  else{
      printf("OK! See you later!");
    }
    
  return 0;
}

