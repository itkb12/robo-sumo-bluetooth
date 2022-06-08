int mt11 = 43;
int mt12 = 42;
int mt21 = 45;
int mt22 = 44;

int ENA1 = 2;
int ENA2 = 3;
int veloc = 200;
char command;

void setup() {
  // put your setup code here, to run once:
  pinMode(mt11,OUTPUT);
  pinMode(mt12,OUTPUT);
  pinMode(mt21,OUTPUT);
  pinMode(mt22,OUTPUT);

  pinMode(ENA1,OUTPUT);
  pinMode(ENA2,OUTPUT);

  digitalWrite(mt11,LOW);
  digitalWrite(mt12,LOW);
  digitalWrite(mt21,LOW);
  digitalWrite(mt22,LOW);
  
  Serial.begin(38400);
  Serial.println("Conectado!");
  
  analogWrite(ENA1,veloc);
  analogWrite(ENA2,veloc);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    command = Serial.read();
    if(command == 'f'){
      forward();
      Serial.println("FRENTE");
    }else if(command == 'b'){
      backwards();
      Serial.println("TRAS");
    }else if(command == 'r'){
      right();
      Serial.println("DIREITA");
    }else if(command == 'l'){
      left();
      Serial.println("ESQUERDA");
    }else if(command == 's'){
      pare();
      Serial.println("PARE");
    }
  }
}

void forward(){
  digitalWrite(mt11,HIGH);
  digitalWrite(mt12,LOW);
  digitalWrite(mt21,HIGH);
  digitalWrite(mt22,LOW);
}

void backwards(){
  digitalWrite(mt11,LOW);
  digitalWrite(mt12,HIGH);
  digitalWrite(mt21,LOW);
  digitalWrite(mt22,HIGH);
}

void right(){
  digitalWrite(mt11,HIGH);
  digitalWrite(mt12,LOW);
  digitalWrite(mt21,LOW);
  digitalWrite(mt22,HIGH);
}

void left(){
  digitalWrite(mt11,LOW);
  digitalWrite(mt12,HIGH);
  digitalWrite(mt21,HIGH);
  digitalWrite(mt22,LOW);
}

void pare(){
  digitalWrite(mt11,LOW);
  digitalWrite(mt12,LOW);
  digitalWrite(mt21,LOW);
  digitalWrite(mt22,LOW);
}
