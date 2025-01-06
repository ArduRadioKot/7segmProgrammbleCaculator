// Определяем выводы для сегментов
const int segmentA[2] = {2, 8};
const int segmentB[2] = {3, 9};
const int segmentC[2] = {4, 10};
const int segmentD[2] = {5, 11};
const int segmentE[2] = {6, 12};
const int segmentF[2] = {7, 13};
const int segmentG[2] = {8, 14};

const int numDigits = 2; // Количество индикаторов

void setup() {
  // Устанавливаем все сегменты как выходы
  for (int i = 0; i < numDigits; i++) {
    pinMode(segmentA[i], OUTPUT);
    pinMode(segmentB[i], OUTPUT);
    pinMode(segmentC[i], OUTPUT);
    pinMode(segmentD[i], OUTPUT);
    pinMode(segmentE[i], OUTPUT);
    pinMode(segmentF[i], OUTPUT);
    pinMode(segmentG[i], OUTPUT);
  }
}

void loop() {
  // Пример вывода числа 42
  displayNumber(42);
  delay(1000);
}

void displayNumber(int num) {
  int digits[numDigits];
  
  // Разделяем число на разряды
  for (int i = 0; i < numDigits; i++) {
    digits[i] = num % 10; // Получаем последний разряд
    num /= 10; // Убираем последний разряд
  }

  // Мультиплексирование
  for (int i = 0; i < numDigits; i++) {
    displayDigit(digits[i], i);
    delay(5); // Задержка для видимости
    clearDisplay(i);
  }
}

void displayDigit(int digit, int position) {
  // Сброс всех сегментов
  clearDisplay(position);

  // Включаем сегменты в зависимости от числа
  switch(digit) {
    case 0:
      digitalWrite(segmentA[position], HIGH);
      digitalWrite(segmentB[position], HIGH);
      digitalWrite(segmentC[position], HIGH);
      digitalWrite(segmentD[position], HIGH);
      digitalWrite(segmentE[position], HIGH);
      digitalWrite(segmentF[position], HIGH);
      break;
    case 1:
      digitalWrite(segmentB[position], HIGH);
      digitalWrite(segmentC[position], HIGH);
      break;
    case 2:
      digitalWrite(segmentA[position], HIGH);
      digitalWrite(segmentB[position], HIGH);
      digitalWrite(segmentD[position], HIGH);
      digitalWrite(segmentE[position], HIGH);
      digitalWrite(segmentG[position], HIGH);
      break;
    case 3:
      digitalWrite(segmentA[position], HIGH);
      digitalWrite(segmentB[position], HIGH);
      digitalWrite(segmentC[position], HIGH);
      digitalWrite(segmentD[position], HIGH);
      digitalWrite(segmentG[position], HIGH);
      break;
    case 4:
      digitalWrite(segmentB[position], HIGH);
      digitalWrite(segmentC[position], HIGH);
      digitalWrite(segmentF[position], HIGH);
      digitalWrite(segmentG[position], HIGH);
      break;
    case 5:
      digitalWrite(segmentA[position], HIGH);
      digitalWrite(segmentC[position], HIGH);
      digitalWrite(segmentD[position], HIGH);
      digitalWrite(segment F[position], HIGH);
      digitalWrite(segmentG[position], HIGH);
      break;
    case 6:
      digitalWrite(segmentA[position], HIGH);
      digitalWrite(segmentC[position], HIGH);
      digitalWrite(segmentD[position], HIGH);
      digitalWrite(segmentE[position], HIGH);
      digitalWrite(segmentF[position], HIGH);
      digitalWrite(segmentG[position], HIGH);
      break;
    case 7:
      digitalWrite(segmentA[position], HIGH);
      digitalWrite(segmentB[position], HIGH);
      digitalWrite(segmentC[position], HIGH);
      break;
    case 8:
      digitalWrite(segmentA[position], HIGH);
      digitalWrite(segmentB[position], HIGH);
      digitalWrite(segmentC[position], HIGH);
      digitalWrite(segmentD[position], HIGH);
      digitalWrite(segmentE[position], HIGH);
      digitalWrite(segmentF[position], HIGH);
      digitalWrite(segmentG[position], HIGH);
      break;
    case 9:
      digitalWrite(segmentA[position], HIGH);
      digitalWrite(segmentB[position], HIGH);
      digitalWrite(segmentC[position], HIGH);
      digitalWrite(segmentD[position], HIGH);
      digitalWrite(segmentF[position], HIGH);
      digitalWrite(segmentG[position], HIGH);
      break;
  }
}

void clearDisplay(int position) {
  // Сброс всех сегментов для данного индикатора
  digitalWrite(segmentA[position], LOW);
  digitalWrite(segmentB[position], LOW);
  digitalWrite(segmentC[position], LOW);
  digitalWrite(segmentD[position], LOW);
  digitalWrite(segmentE[position], LOW);
  digitalWrite(segmentF[position], LOW);
  digitalWrite(segmentG[position], LOW);
}