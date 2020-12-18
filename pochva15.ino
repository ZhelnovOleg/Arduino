
hint rainPin = A0;
int greenLED = 6;
int redLED = 7;
// пороговое значение указывается тут:
int thresholdValue = 800;

int water; // присваиваем имя для значений с аналогового входа A5


void setup(){
  pinMode(rainPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  
  
  pinMode(12, OUTPUT); // пин 12 со светодиодом будет выходом (англ. «output»)
  pinMode(A5, INPUT);  // к входу A0 подключим датчик (англ. «intput»)
  Serial.begin(9600);  // подключаем монитор порта

}


void loop()
{
  
   int water = analogRead(A5); // переменная "water" находится в интервале от 0 до 1023
   if (water > 200) {{ digitalWrite(12, HIGH); } // включаем светодиод
       Serial.println(" - Вода в канистре есть"); 
       delay (1500);}
    // " – Полив не нужен" 
   
     else {{ digitalWrite(redLED, LOW); } { digitalWrite(12, LOW);}   // выключаем светодиод
  // считываем входные данные с аналогового контакта 0:
   Serial.println(water); // выводим значение датчика на монитор
   Serial.println(" Воды в канистре нет");
   delay (1500);
   }
    
    int sensorValue = analogRead(rainPin);
    if (sensorValue < thresholdValue)
   { Serial.print(sensorValue);
    Serial.println(" - Doesn't need watering");  
    // " – Полив не нужен"
   
    
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    delay (1000);
}


   else {
    Serial.println(" - Time to water your plant");
    // " – Пора поливать!"
  
    digitalWrite(redLED, HIGH);
    delay (3000);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    delay(1000);           // задержка в одну секунду

  }
   
  

   
}




 
