#include <LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd(0x27, 16, 4); // размер экрана, адрес шины

const int BUTTON_R = 2; // Вправо
const int BUTTON_L = 3; // Влево
const int BUTTON_U = 4; // Вверх
const int BUTTON_D = 5; // Вниз

const int SPEAKER = 7;
const float d5 = 587.32;
const float f5 = 523.25;

const char PLAYER = 0; // пользовательский символ префикс
byte player_image[8] = {
  0b00100,
  0b01110,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010,
  0b01010
};

const char HP = 1;
byte hp_image[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b11011,
  0b11111,
  0b11111,
  0b01110,
  0b00100
};

 const char MONSTER1 = 2;
 byte monster1_image[8] = {
  0b10001,
  0b01110,
  0b10101,
  0b01110,
  0b10001,
  0b01110,
  0b00000,
  0b00000
};

const byte SPACE = ' ';
const byte WALL = '#';

// Размер игровой карты
const byte MAP_W = 20;
const byte MAP_H = 4;

// Игровая карта
char game_map[MAP_H][MAP_W];

// Функция генерации карты
void generate_map() {
  for (int y = 0; y < MAP_H; y++) {
    for (int x = 0; x < MAP_W; x++) {
      int n = random(0,8);
      if ( n == 0 ) {
        game_map[y][x] = HP;
      } else if (n == 1) {
        game_map[y][x] = MONSTER1;
      } else if (n == 2) {
        game_map[y][x] = WALL;
      } else {
      game_map[y][x] = SPACE;
    }
  }
  }
  game_map[0][3] = WALL;
  game_map[1][3] = WALL;
  game_map[2][1] = MONSTER1;
  game_map[3][6] = WALL;
  game_map[2][5] = HP;
}

//вывести карту на экран
void show_map() {
  for (int y = 0; y < MAP_H; y++) {
    for (int x = 0; x < MAP_W; x++) {
      lcd.setCursor(x,y); //устанавливает положение, в котором на его экран будет выведен последующий текст.
      lcd.print(game_map[y][x] ); // выводим где указатель символа массива
    }
  }
}

int player_x = 0;
int player_y = 0;

void play_tone (int port, float f, long t) { 
  const long P = 1000000 / f; // период
  const long D = P / 2; // длительность сигналов
  const int COUNT = t / P; // кол-во проигрывания сигналов
  for (int c = 0; c < COUNT; c++) {
    digitalWrite(port, HIGH); //позволяет установить состояние вывода как цифровой выход
    delayMicroseconds(D);
    digitalWrite(port, LOW);
    delayMicroseconds(D);
  }
}

void setup() { // тут располагаются команды подпрограммы которые выполняются один раз при запуске проги
  lcd.init(); //инициализируем лсд
  lcd.backlight(); //подсветка
  pinMode(BUTTON_R, INPUT_PULLUP); // инвертируется сигнал включает внутренний резистр
  pinMode(BUTTON_L, INPUT_PULLUP); //операций считывания или записи, режим работы выход
  pinMode(BUTTON_U, INPUT_PULLUP);
  pinMode(BUTTON_D, INPUT_PULLUP);
  lcd.createChar(MONSTER1, monster1_image); // создаем символ
  lcd.createChar(PLAYER, player_image);
  lcd.createChar(HP, hp_image);
  pinMode(SPEAKER, OUTPUT);
  randomSeed( analogRead(A0) ); // инициализирует генератор псевдослучайных чисел //встроенный аналого-цифровой преобразователь 
  generate_map();// выводим массив на экран
}

void game_over() {
  lcd.setCursor(2,2);
  lcd.print("G A M E O V E R");
  long t = 75000;
  for (float f = 1000; f >= 50; f/= 1.4){
    play_tone(SPEAKER, f, t);
    t *= 1.2;
  }
  player_x = 0;
  player_y = 0;
  generate_map();
}

void loop() { //команды, которые   будут выполняться все время, пока включена плата Arduino. 
  show_map();
  if (digitalRead(BUTTON_R)== LOW) {
    player_x++;
    if (game_map[player_y][player_x] == WALL) {
      player_x--;
    }
  }
  
  if (digitalRead(BUTTON_L)== LOW) {
    player_x--;
    if (game_map[player_y][player_x] == WALL) {
      player_x++;
    }
  }
  
  if (digitalRead(BUTTON_U)== LOW) {
    player_y--;
    if (game_map[player_y][player_x] == WALL) {
      player_y++;
    }
  }
  
  if (digitalRead(BUTTON_D)== LOW) {
    player_y++;
    if (game_map[player_y][player_x] == WALL) {
      player_y--;
    }
  }

  if (game_map[player_y][player_x]== MONSTER1) {
    game_over();
  }
  
  if (game_map[player_y][player_x] == HP) {
    game_map[player_y][player_x] = SPACE;
    play_tone(SPEAKER, d5, 125000);
    play_tone(SPEAKER, f5, 622500);
  }
  lcd.setCursor(player_x, player_y);
  lcd.print(PLAYER);
  delay(100);
}

const int port1 = 2

void svet () {
  for (int a = 0; a < 5; a++);
    digitalWrite(port1, HIGH);
    delayMicroseconds(D);
    digitalWrite(port1, LOW);
    delayMicroseconds(D);

}