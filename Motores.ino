int tiempo;
void setup() {
  pinMode(3,OUTPUT);
  pinMode(11,OUTPUT);
  
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);

}
void loop(){
  if(Serial.available())
  {
    char dato = Serial.read();
    if(dato=='a')
    {
      adelante();
      tiempo=0;
    }
    else if(dato=='r')
    {
      atras();
      tiempo=0;
    }
    else if(dato=='d')
    {
      izq();
      tiempo=0;
    }
    else if(dato=='i')
    {
      der();
      tiempo=0;
    }
  }

  if(tiempo<200)//100 ciclos de 1ms
  {
    tiempo=tiempo+1;
  }
  else //ya transcurrieron 100 ms (100 ciclos)
  {
    paro();
  }
  delay(1);
  
}

void adelante() {
  //Derecho ,Adelante
  analogWrite(3,180);
  analogWrite(11,0);
  //Izquiedo ,Adelante
  analogWrite(9,0);
  analogWrite(10,200);
}
void atras() {
  //Derecho ,Atras
  analogWrite(3,0);
  analogWrite(11,200);
  //Izquiedo ,Atras
  analogWrite(9,140);
  analogWrite(10,0);
}
void izq() {
  //Derecho ,Adelante
  analogWrite(3,120);
  analogWrite(11,0);
  //Izquiedo ,Atras
  analogWrite(9,150);
  analogWrite(10,0);
}
void der() {
  //Derecho ,Atras
  analogWrite(3,0);
  analogWrite(11,120);
  //Izquiedo ,Adelante
  analogWrite(9,0);
  analogWrite(10,150);
}
void paro() {
  //Derecho ,Atras
  analogWrite(3,0);
  analogWrite(11,0);
  //Izquiedo ,Adelante
  analogWrite(9,0);
  analogWrite(10,0);
}
