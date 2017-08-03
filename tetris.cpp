// tetris.cpp
// Matthew Edge

#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

/* Constant Variables
 */
const int WIDTH = 320;
const int HEIGHT = 480;
const int M = 20;
const int N = 10;

int field[M][N] = {0};

struct Point {
  int x, y;
};

int figures[7][4] = {
  1,3,5,7, // I
  2,4,5,7, // Z
  3,5,4,6, // S
  3,5,4,7, // T
  2,3,5,7, // L
  3,5,7,6, // J
  2,3,4,5, // O
};

void Move(Point a[], Point b[], int dx);
void Rotate(Point a[]);
void Tick(Point a[], Point b[], int &colorNum);
bool check(Point a[]);
void clearRow();
void moveEveryDown(int row);
bool stopGame();
void resetGame();

int main() {
  /* Seed srand
   */
  srand(time(NULL));

  /* Declare Variables
   */
  int i, j, n, dx = 0, colorNum = 1;
  bool rotate = false;
  float time, timer = 0, delay = 0.3;
  Point a[4] = {0}, b[4];
  Texture t1, t2, t3;

  Font font;
  if (!font.loadFromFile("fonts/Pacifico.ttf")) std::cout << "Couldn't load font file!" << std::endl;

  /* Set up Text for losing
   */
  Text end_message;
  Text restart_message;
  end_message.setFont(font);
  restart_message.setFont(font);
  end_message.setString("GAME OVER!");
  restart_message.setString("Press r to restart");
  end_message.setCharacterSize(30);
  restart_message.setCharacterSize(20);
  end_message.setColor(Color::White);
  end_message.setStyle(Text::Bold);


  /* Declare window
   */ 
  RenderWindow window(VideoMode(WIDTH, HEIGHT), "Tetris!");

  /* Store pixels from tiles.png in Texture object.
   */
  t1.loadFromFile("images/tiles.png");
  t2.loadFromFile("images/background.png");
  t3.loadFromFile("images/frame.png");  

  /* Create a Drawable representation of the Texture t as Sprite s
   */
  Sprite s(t1), background(t2), frame(t3);

  /* Define a rectangle, located at (0, 0) with a size of 18x18.
   */
  s.setTextureRect(IntRect(0,0,18,18));

  Clock clock;

  /* Keep Program Running as long as window is open
   */ 
  while (window.isOpen()) {
    /* User clock to allow delay for y speed
     */
    time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;

    /* Handle Keyboard events
     */
    Event e;
    while (window.pollEvent(e)) {
      if (e.type == Event::Closed) 
        window.close();

      if (e.type == Event::KeyPressed) {
        if (e.key.code == Keyboard::Escape) window.close();
        else if (e.key.code == Keyboard::Up) rotate = true;
        else if (e.key.code == Keyboard::Left) dx = -1;
        else if (e.key.code == Keyboard::Right) dx = 1;
        else if (e.key.code == Keyboard::Down) delay = 0.05;
        else if (e.key.code == Keyboard::R) resetGame();
      }
    }

    /* Move figures Left or Right */
    Move(a, b, dx);

    /* Rotate */
    if (rotate) {
      Rotate(a);
      if (!check(a)) {
        for (i = 0; i < 4; i++) {
          a[i] = b[i];
        }
      }
    }

    /* Tick
     */
    if (timer > delay && !stopGame()) {
      Tick(a, b, colorNum);     
      timer = 0; 
    }

    /* Set variables back to default values
     */
    dx = 0;
    rotate = false;
    delay = 0.3;

    /* Draw Sprites and text
     */
    window.clear(Color::White);
    window.draw(background);
    for (i = 0; i < M; i++) {
      for (j = 0; j < N; j++) {
        if (field[i][j] == 0) continue;
        s.setTextureRect(IntRect(field[i][j] * 18,0,18,18));
        s.setPosition(j*18, i*18);
        s.move(70,31);
        window.draw(s);
      }
    }

    for (i = 0; i < 4; i++) {
      s.setTextureRect(IntRect(colorNum * 18,0,18,18));
      s.setPosition(a[i].x * 18, a[i].y * 18);
      s.move(70,31);
      window.draw(s);
    }

    if (stopGame()) {
      end_message.setPosition(50,400); 
      restart_message.setPosition(80,440); 
      window.draw(end_message);
      window.draw(restart_message);
    }

    window.draw(frame);
    window.display();
  } 
  return 0; 
}

// Move Function
void Move(Point a[], Point b[], int dx) {
  int i;
  for (i = 0; i < 4; i++) {
    b[i] = a[i];
    a[i].x += dx;
  }
  if (!check(a)) {
    for (i = 0; i < 4; i++) {
      a[i] = b[i];
    }
  }
}

// Rotate Function
void Rotate(Point a[]) {
  int i, x, y;
  Point p = a[1]; // Center of rotaion
  for (i = 0; i < 4; i++) {
    x = a[i].y - p.y;
    y = a[i].x - p.x;
    a[i].x = p.x - x;
    a[i].y = p.y + y;
  }
}

// Tick Function
void Tick(Point a[], Point b[], int &colorNum) {
  int i, n;
  for (i = 0; i < 4; i++) {
    b[i] = a[i];
    a[i].y += 1;
  }
  if (!check(a)) {
    for (i = 0; i < 4; i++) {
      field[(b[i].y)][(b[i].x)] = colorNum;
    }
    clearRow();
    colorNum = 1 + rand() % 7;
    n = rand() % 7;
    for (i = 0; i < 4; i++) {
      a[i].x = figures[n][i] % 2;
      a[i].y = figures[n][i] / 2;
    }
  }
}

// Check Function
bool check(Point a[]) {
  int i;
  for (i = 0; i < 4; i++) {
    if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return false;
    else if (field[a[i].y][a[i].x]) return false;
  }
  return true;
}

// Clear A Row out if full
void clearRow(){
  int i, j;
  bool is_not_full = true;
  for(i = M - 1; i > -1; i--) {
   for(j = N - 1; j > -1; j--) {
     if(field[i][j] == 0) {
       is_not_full = false; 
     }
   }
   if(is_not_full){
     for(j = 0; j < N; j++) {
       field[i][j] = 0;
     }
     moveEveryDown(i);
     i += 1;
   }
   is_not_full= true;
 }
}

// Move everything above the cleared row down one
void moveEveryDown(int row) {
  int i, j;
  for(i = row - 1; i > -1; i--) {
    for(j = N - 1; j > -1; j--) {
      field[i+1][j] = field[i][j];
      field[i][j] = 0; 
    }
  }
}

// Check if user lost
bool stopGame() {
  int j;
  for (j = 0; j < N; j++) {
    if(field[1][j] != 0) {
      return true;
    }
  }
  return false;
}

// Start from begging
void resetGame() {
  int i, j;
  for(i = 0; i < M; i++) {
    for(j = 0; j < N; j++) {
      field[i][j] = 0;
    }
  }
}
