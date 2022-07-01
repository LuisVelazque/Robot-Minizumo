int s1;
int s2;
int D1;
int D2;
int arr;
int i;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  //sensores
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(8,INPUT);


}

void loop() {
  
  D1 = digitalRead(A2);
  D2 = digitalRead(A3);
  s1 = digitalRead(A0);
  s2 = digitalRead(A1);
  arr = digitalRead(8);

 while (arr == LOW) arr = digitalRead(8);
 while (arr == HIGH)
  {
 if((D1==LOW)&&(D2==LOW))
 {
  //EST1();
    izq();
  delay(50);
  adelante();
  delay(400);
  der();
  delay(50);
  busder();
  delay(50);
        for ( i = 0; i < 180000; i++)
      {
        s1 = digitalRead(A0);
        s2 = digitalRead(A1);
        mov();
        arr = digitalRead(8);
        if (arr == LOW)break;
      }
  }else{
    if((D1==HIGH)&&(D2==LOW))
    {
     //EST2();
     atras();
     delay(200);
     der();
     delay(200);
     atras();
     delay(400);
     busizq();
     delay(100);
     for ( i = 0; i < 180000; i++)
      {
        s1 = digitalRead(A0);
        s2 = digitalRead(A1);
        mov();
        arr = digitalRead(8);
        if (arr == LOW)break;
      }
    }else{
     if((D1==LOW)&&(D2==HIGH))
     {
      der();
      delay(50);
      adelante();
      delay(300);
      izq();
      delay(120);
      adelante();
      delay(300);
      izq();
      delay(500);
      //EST3();
      for ( i = 0; i < 180000; i++)
      {
        s1 = digitalRead(A0);
        s2 = digitalRead(A1);
        mov();
        arr = digitalRead(8);
        if (arr == LOW)break;
      }
     }else{
      if((D1==HIGH)&&(D2==HIGH))
      {
          adelante();
          delay(300);
          bus();
          delay(50);
        //EST4();
     for ( i = 0; i < 180000; i++)
      {
        s1 = digitalRead(A0);
        s2 = digitalRead(A1);
        mov();
        arr = digitalRead(8);
        if (arr == LOW)break;
      }
      }
     }
    }
  }
    arr = digitalRead(8);
    if (arr == LOW)break;
  }
  paro();

}


void adelante() {

  //Derecho ,Adelante
    analogWrite(3,190);
    analogWrite(11,0);
    //Izquiedo ,Adelante
    analogWrite(9,190);
    analogWrite(10,0);
}

void atras() {

   //Derecho ,Atras
    analogWrite(3,0);
    analogWrite(11,190);
    //Izquiedo ,Atras
    analogWrite(9,0);
    analogWrite(10,190);
}
void der() {

   //Derecho ,Adelante
    analogWrite(3,190);
    analogWrite(11,0);
    //Izquiedo ,Atras
    analogWrite(9,0);
    analogWrite(10,190);
}
void izq() {

  //Derecho ,Atras
    analogWrite(3,0);
    analogWrite(11,190);
    //Izquiedo ,Adelante
    analogWrite(9,190);
    analogWrite(10,0);
}
void paro() {
  //Derecho ,Atras
  analogWrite(3, 0);
  analogWrite(11, 0);
  //Izquiedo ,Adelante
  analogWrite(9, 0);
  analogWrite(10, 0);
}
void busizq() {

  //Derecho ,Atras
    analogWrite(3,0);
    analogWrite(11,120);
    //Izquiedo ,Adelante
    analogWrite(9,120);
    analogWrite(10,0);
}
void busder(){
     //Derecho ,Adelante
    analogWrite(3,120);
    analogWrite(11,0);
    //Izquiedo ,Atras
    analogWrite(9,0);
    analogWrite(10,120);
}
void mov(){  

  

    if ((s1 == HIGH) && (s2 == HIGH)) {
    adelante();
  } else {
    if ((s1 == HIGH) && (s2 == LOW)) {
      der();
    } else{
      if ((s1 == LOW) && (s2 == HIGH)) {
        izq();
      } else {
        if ((s1 == LOW) && (s2 == LOW)) {
          busizq();
        }
      }
    }
  }
}
void EST1(){
  //Seguimiento
  izq();
  delay(50);
  adelante();
  delay(400);
  der();
  delay(50);
  busder();
  delay(50);

}
void EST2(){
  //DEFENSA
atras();
delay(200);
der();
delay(200);
atras();
delay(400);
busizq();
delay(100);
}
void EST3(){
  //ATAQUE
  der();
  delay(50);
  adelante();
  delay(300);
  izq();
  delay(120);
  adelante();
  delay(300);
  izq();
  delay(500);

  
  
}
void EST4(){
  adelante();
  delay(300);
  busder();
  delay(50);
}
