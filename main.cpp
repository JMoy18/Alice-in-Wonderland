#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string.h>

using namespace std;

int world_bunny = 1;
int world_alice = 1;
int round_num = 0;
int alice_position = 1;
int bunny_position = 2;
int gameplayer = 0;
int alice_dice = 0;
int bunny_dice = 0;
int game_end = 0;

int bunny_movement(int bunny_position) {
  srand(time(NULL));
  if (bunny_position < 16) {
    int added = 0;
    added += rand() % (1 - 4);
    bunny_position += added;
    return bunny_position;
  } else {
    cout << "The Bunny slips your grasp and enters the next world\n";
    world_bunny += 1;
    return bunny_position;
  }
}
int alice_movement(int alice_position) {
  if (alice_position < 16) {
    int added = 0;
    added += rand() % (1 - 4);
    alice_position += added;
    return alice_position;
  } else {
    cout << "You have made it to the next world... go get that rabbit!\n";
    world_alice += 1;
    return alice_position;
  }
}
/*char dice_roll() {
  char dice = 0;
  //cout << "Roll dice: ";
  cin >> dice;
  return dice;
}
void check_dice(int alice_position, int alice_dice, int bunny_dice,
                int bunny_position) {
  dice_roll();
  if (dice_roll() == '1') {
    alice_dice = alice_movement(alice_position);
    alice_position += alice_dice;
    bunny_dice = bunny_movement(bunny_position);
    bunny_position += bunny_dice;
    if (bunny_dice <= 16) {
      cout << " White Rabbit's position: " << bunny_dice << "\n\n";
    } else {
      cout << " White Rabbit's position: " << ((bunny_dice % 16) + 1) << "\n\n";
    }
    if (alice_dice <= 16) {
      cout << " \nAlice's position: " << alice_dice << "\n\n";
    } else {
      cout << " \nAlice's position: " << ((alice_dice % 16) + 1) << "\n\n";
    }
  } else {
    cout << "Enter a valid statement";
    check_dice(alice_position, alice_dice, bunny_dice, bunny_position);
  }
}*/
int trivia_game(int alice_position, int alice_dice) {
  double year = 0;
  string character;
  int inches = 0;
  int points = 0;
  cout << "You have entered the Lair of the Queen of Hearts. If you want to "
          "advance, correctly answer this trivia question";
  cout << endl;
  cout << "Question: In what year was the original Alice in Wonderland created?"
       << endl;
  cout << "Answer: ";
  cin >> year;
  if (year != 1956) {
    cout << "Incorrect. The answer was 1956" << endl;
  } else {
    cout << "You are correct. The animated film of Alice in Wonderland came "
            "out in 1956."
         << endl
         << endl;
    points++;
  }
  cout << "Question 2: ";
  cout << "Did Alice have a pet?" << endl;
  cout << "Answer: ";
  cin >> character;
  if (character != "yes") {
    cout << "Incorrect. Alice had a pet cat named Dinah." << endl;
  } else {
    cout << "You are correct. She had a pet cat named Dinah." << endl;
    points++;
  }
  cout << endl << endl;
  cout << "Question 3: ";
  cout << "How many inches tall was the caterpiller?" << endl;
  cout << "Answer: ";
  cin >> inches;
  if (inches != 3) {
    cout << endl << "Incorrect. The caterpiller was 3 inches tall.";
  } else {
    cout << "You are correct. The caterpiller was 3 inches tall.";
    points++;
  }
  if (points >= 2) {
    cout << "You can advance to the next round!" << endl << endl;
  } else {
    cout << "You have failed. You will loose a turn";
  }
}
int rock_paper(int alice_position, int alice_dice) {
  char choice_you, choice_comp;
  int num = 3;
  int points = 0;
  char options[] = {'A', 'K', 'Q'};
  unsigned seed = time(0);
  srand(seed);
  cout << "Welcome to the second game in the Queen's Lair. To pass, you must "
          "beat this game of ace, king, queen aka rock paper scissors."
       << endl
       << endl;
  cout << "A = ace, K = king, Q = queen" << endl;
  while (num != 0) {
    cout << "Would you like to choose ace, king or queen?" << endl
         << "Choice: ";
    cin >> choice_you;
    cout << endl;
    choice_comp = options[rand() % 3];
    cout << "The computer chose: " << choice_comp << endl;
    if (choice_you == choice_comp) {
      cout << "You tied. No one looses or wins" << endl;
      num++;
      cout << endl;
    }
    if (choice_you == 'A' && choice_comp == 'K') {
      cout << "You loose. King will beat Ace" << endl;
      num--;
      cout << endl;
    }
    if (choice_you == 'K' && choice_comp == 'A') {
      cout << "You get a point. King beats Ace" << endl;
      num--;
      points++;
      cout << endl;
    }
    if (choice_you == 'Q' && choice_comp == 'K') {
      cout << "You get a point. Queen beats King" << endl;
      num--;
      points++;
      cout << endl;
    }
    if (choice_you == 'K' && choice_comp == 'Q') {
      cout << "You loose this round. Queen beats King" << endl;
      num--;
      cout << endl;
    }
    if (choice_you == 'A' && choice_comp == 'Q') {
      cout << "You get a point. Ace beats Queen" << endl;
      num--;
      points++;
      cout << endl;
    }
    if (choice_you == 'Q' && choice_comp == 'A') {
      cout << "You loose this round. Ace beats Queen" << endl;
      num--;
      points++;
      cout << endl;
    }
  }
  if (points == 2) {
    cout << "You win ace, king, queen!";
    cout << endl;
  } else {
    cout << "You lost. You will loose a turn";
    cout << endl;
  }
}
int make_potion(int alice_position, int alice_dice) {
  string pick;
  int count = 0;
  cout << "Welcome to the Potion Making Lair. To advance to the next room, you "
          "need to take a potion to skrink to the size of an ant."
       << endl;
  cout << "If you win you can advance. If not, you will loose a turn. " << endl
       << endl;
  string cake[] = {"flour",  "sugar",   "milk", "eggs",
                   "butter", "vanilla", "salt"};
  string flower[] = {"air", "soil", "space", "sun", "worms"};
  cout << "Name 3 things you need to make a cake in lowecase letters. You have "
          "5 tries."
       << endl;
  int i = 0;
  int num = 0;
  while (count != 5) {
    if (count > 0) {
      cout << "Pick another: \n";
    }
    cin >> pick;
    for (i = 0; i < 7; i++) {
      if (pick == cake[i]) {
        count++;
        cout << "You have chosen a correct ingredient!\n\n";
      }
    }
    if (count == 3) {
      cout << "Congrats you have made it to the next level.\n\n";
      break;
    }
  }
}
int anagram(int alice_position, int alice_dice) {
  int c = 0;
  int sucess = 0;
  string x;
  string words[] = {"cat",   "alice",  "potion", "ace",
                    "small", "garden", "solider"};
  while (c != 3) {
    if (sucess ==3){
      break;
    }
    cout << "Type an Alice in Wonderland word (in lowercase) that contain the "
            "following letters: CTELNISMPAO    ";
    cin >> x;
    for (int i = 0; i < 7; i++) {
      if (words[i] == x) {
        cout << "Good job! lets find another\n";
        words[i] = "0";
        sucess += 1;
        c++;
      }
      if (sucess == 3) {
        cout << "YOU WIN!!";
        break;
      } else {
        c++;
        }
    }
  }
}
int riddle(int alice_position, int alice_dice) {
  string response = "";
  cout << "Welcome to the reign of the cheshire cat";
  cout << "\nto move forward, please the cat\nHello there, my curious friend! "
          "\nI have a riddle for you that I think you will find quite "
          "delightful.\nAre you ready?(Yes/No) ";

  cin >> response;
  while (response != "Yes" && response != "No") {
    cout << "invalid, please type Yes or No";
    cin >> response;
  }
  while (response == "No") {
    cout << "\nCome now, don't be shy! I promise, it's a good one.\nAre you "
            "ready? ";
    cin >> response;
    if (response == "Yes") {
      cout << "Wonderful! Here is the riddle\n";
    }
  }
  cout << "\nI light up the night, but I am not the sun,\nI can be full, or "
          "thin and on the run.\nI'm always changing, but always the "
          "same,\nWhat am I? ";
  cin >> response;
  for (int i = 0; i < response.length(); i++) {
    response[i] = tolower(response[i]);
  }
  int tries = 0;
  while (true) {
    if (response == "moon") {
      if (tries == 0) {
        cout
            << "\nAh, clever you! \nThe answer is the moon, of course. \nIt's "
               "always changing, but it never goes away. \nJust like me! Haha!";
        break;
      }

      cout << "\nYes! That's it! The moon! \nIt's a simple riddle, really, but "
              "I think it's quite lovely. \nYou'll get the next one, I'm sure! "
              "It took you "
           << tries;
      cout << " tries";
      break;
    }
    cout << "Hmm, that's not quite right, my dear. Guess again.\n";
    cin >> response;
    for (int i = 0; i < response.length(); i++) {
      response[i] = tolower(response[i]);
    }
    tries++;
  }
}
int main() {
  int bunny_position = 2;
  int currentPos = 0; // used to indicate the world we are in
  int alice_position = 1;
  int clock = 8;
  int exit = 15;
  int alice_dice, bunny_dice;
  // clear position after exit world
  int world = 0;
  char dice;
  while (world != 4) {
    cout << "World " << world_alice << " for Alice \n";
    cout << "Roll dice: ";
    cin >> dice;
    if (dice == '1' && game_end == 0) {
      alice_dice = alice_movement(alice_position);
      alice_position += alice_dice;
      bunny_dice = bunny_movement(bunny_position);
      bunny_position += bunny_dice;
      if (bunny_dice <= 16) {
        cout << " White Rabbit's position: " << bunny_dice << "\n\n";
      } else {
        cout << " White Rabbit's position: " << ((bunny_dice % 16) + 1)
             << "\n\n";
      }
    }
    if (alice_dice <= 16) {
      cout << " Alice's position: " << alice_dice << "\n\n";
    } else {
      cout << " Alice's position: " << ((alice_dice % 16) + 1) << "\n\n";
    }
    if (bunny_position == alice_position && round_num != 1 ||
        alice_position >= 16 && world_alice == 4) {
      cout << "you captured the rabbit you win!";
    }
    if (bunny_position >= 16 && world_bunny == 4) {
      cout << "Better luck next time, you lose :(";
    }
    if (world == 0) {
      if (round_num == 0) {
        cout << "Welcome to Alice's World a small game created by Uma, Jess, "
                "and Neinei! \n Intructions: \n \t1. Roll the dice by entering "
                "1. \n\t2. Refer to the open map to determine your location. "
                "If you land on square 8, you wll get to do a puzzle. \n\t3. "
                "If you decide to solve the puzzle and you complete it "
                "successfully, you advance 1 extra square otherwise your turn "
                "\n \n Your goal: Catch the White Rabbit as he tries to "
                "escape. If you do, you win!! \n\n";
        round_num += 1;
      }
      if (alice_position == 8) {
        anagram(alice_position, alice_dice);
      }
      if (alice_position >= 16) {
        world++;
      }
    }
    if (world == 1) {
      if (alice_position >= 8) {
        anagram(alice_position, alice_dice);
      }
      if (alice_position >= 16) {
        world++;
      }
      if (round_num == 1) {
        cout << "Welcome to the potion room. Roll the dice by entering 1. If "
                "you land on square 8, you wll get to do a puzzle. If you "
                "solve the puzzle, you can advance 1 extra square. If you do "
                "not choose to do the puzzle or if you loose, you will loose "
                "your turn."
             << endl;
        round_num += 1;
      }
    }
    if (world == 2) {
      if (round_num == 2) {
        cout << "Welcome to the Cheshire Cat's Realm. Roll the dice by "
                "entering 1. If you land on square 8, you wll get to do a "
                "puzzle. If you solve the puzzle, you can advance 1 extra "
                "square. If you do not choose to do the puzzle or if you "
                "loose, you will loose your turn."
             << endl;
      }
      if (alice_position == clock) {
        rock_paper(alice_position, alice_dice);
      }
      if (alice_position >= exit) {
        world++;
      }
    }
    if (world == 3) {
      if (alice_position >= 8) {
        cout << "Welcome to the Queen of Heart's World. Roll the dice by "
                "entering 1. If you land on square 8, you wll get to do a "
                "puzzle. If you solve the puzzle, you can advance 1 extra "
                "square. If you do not choose to do the puzzle or if you "
                "loose, you will loose your turn."
             << endl;
        riddle(alice_position, alice_dice);
      }
      if (alice_position >= exit) {
        cout << "Congrats. You have caught the White Rabbit just in time for "
                "the tea party!";
      } else {
        // need to add condition if white rabitt got to the exit first.
      }
    }
  }
}