//leitura da temperatura
int PinAnalogLM35 = 0;
float valAnalog = 0;
float temp = 0;

//controle de aparelhos e lampadas
int cozinha = 8;
int area_serv = 9;
int hall = 10;
int ar = 11;
int tv = 12;
int val = 0;

void leMemoria(int pino, int endereco) {
  if (EEPROM.read(endereco) == '1') {
    digitalWrite(pino, HIGH);
  }  
  else {
    digitalWrite(pino, LOW);
  }
}

void escreveMemoria(int endereco, char valor) {
  EEPROM.write(endereco, valor);
}

void setup(){
  Serial.begin(9600);
  pinMode(cozinha, OUTPUT);
  pinMode(area_serv, OUTPUT);
  pinMode(hall, OUTPUT);
  pinMode(ar, OUTPUT);
  pinMode(tv, OUTPUT);

  leMemoria(cozinha, 0);
  leMemoria(area_serv, 1);
  leMemoria(hall, 2);
  leMemoria(ar, 3);
  leMemoria(tv, 4);
}

void loop(){
  //digitalWrite(area_serv, HIGH);
  if (Serial.available() > 0){
    //Serial.print(Serial.read());
    //verifica a temperatura
    int comando = Serial.read();
    if (comando == 15) {
      valAnalog = analogRead(PinAnalogLM35);
      temp = (valAnalog * 500) / 1023;
      Serial.println(temp);
    }

    //acende luz area servico
    if (comando == 10){
      if(digitalRead(area_serv) == HIGH){
        Serial.println("A luz ja se encontra acesa. Gostaria de apagar?");  
      }
      else {
        digitalWrite(area_serv, HIGH);
        Serial.println("Luz acesa com sucesso!");
        escreveMemoria(1, '1');  
      }  
    }
    //apaga luz area servico
    if (comando == 16){
      if(digitalRead(area_serv) == LOW){
        Serial.println("A luz ja se encontra apagada. Gostaria de acender?");
      } 
      else{
        digitalWrite(area_serv, LOW);
        Serial.println("Luz apagada com sucesso!");
        escreveMemoria(1, '0');  
      }
    } 

    //verifica luz area servico
    if (comando == 22){
      if(digitalRead(area_serv) == LOW){
        Serial.println("A luz se encontra apagada. Gostaria de acender?");
      } 
      else{
        Serial.println("A luz se encontra acesa. Gostaria de apagar?");
      }
    } 

    //acende luz cozinha
    if (comando == 11){
      if(digitalRead(cozinha) == HIGH){
        Serial.println("A luz ja se encontra acesa. Gostaria de apagar?");
      } 
      else{
        digitalWrite(cozinha, HIGH);
        Serial.println("Luz acesa com sucesso!");
        escreveMemoria(0, '1');
      }
    }
    //apaga luz cozinha
    if (comando == 17){
      if(digitalRead(cozinha) == LOW){
        Serial.println("A luz ja se encontra apagada. Gostaria de acender?");
      } 
      else{
        digitalWrite(cozinha, LOW);
        escreveMemoria(0, '0');
        Serial.println("Luz apagada com sucesso!");
      }
    } 
    //verifica luz cozinha
    if (comando == 23){
      if(digitalRead(cozinha) == LOW){
        Serial.println("A luz se encontra apagada. Gostaria de acender?");
      } 
      else{
        Serial.println("A luz se encontra acesa. Gostaria de apagar?");
      }
    } 
    //acende luz hall
    if (comando == 12){
      if(digitalRead(hall) == HIGH){
        Serial.println("A luz ja se encontra acesa. Gostaria de apagar?");
      } 
      else{
        digitalWrite(hall, HIGH);
        escreveMemoria(2, '1');
        Serial.println("Luz acesa com sucesso!");
      }
    }
    //apaga luz hall
    if (comando == 18){
      if(digitalRead(hall) == LOW){
        Serial.println("A luz ja se encontra apagada. Gostaria de acender?");
      } 
      else{
        digitalWrite(hall, LOW);
        escreveMemoria(2, '0');
        Serial.println("Luz apagada com sucesso!");
      }
    } 

    //verifica luz hall
    if (comando == 24){
      if(digitalRead(hall) == LOW){
        Serial.println("A luz se encontra apagada. Gostaria de acender?");
      } 
      else{
        Serial.println("A luz se encontra acesa. Gostaria de apagar?");
      }
    }    

    //liga o ar
    if (comando == 13){
      if(digitalRead(ar) == HIGH){
        Serial.println("O Ar condicionado se encontra ligado. Gostaria de Desligar?");
      } 
      else{
        digitalWrite(ar, HIGH);
        escreveMemoria(3, '1');
        Serial.println("Ar condicionado ligado com sucesso!");
      }
    }
    //desliga o ar
    if (comando == 19){
      if(digitalRead(ar) == LOW){
        Serial.println("O Ar condicionado se encontra desligado. Gostaria de ligar?");
      } 
      else{
        digitalWrite(ar, LOW);
        escreveMemoria(3, '0');
        Serial.println("Ar condicionado desligado com sucesso!");
      }
    } 

    //verifica ar
    if (comando == 25){
      if(digitalRead(ar) == LOW){
        Serial.println("O Ar condicionado se encontra desligado. Gostaria de ligar?");
      } 
      else{
        Serial.println("O Ar condicionado se encontra ligado. Gostaria de Desligar?");
      }
    } 

    //liga a TV
    if (comando == 14){
      if(digitalRead(tv) == HIGH){
        Serial.println("A TV se encontra ligada. Gostaria de Desligar?");
      } 
      else{
        digitalWrite(tv, HIGH);
        escreveMemoria(4, '1');
        Serial.println("TV ligada com sucesso!");
      }
    }
    //desliga a TV
    if (comando == 20){
      if(digitalRead(tv) == LOW){
        Serial.println("A TV se encontra desligada. Gostaria de ligar?");
      } 
      else{
        digitalWrite(tv, LOW);
        escreveMemoria(4, '0');
        Serial.println("TV ligada desligada com sucesso!");
      }
    } 

    //verifica a TV
    if (comando == 26){
      if(digitalRead(tv) == LOW){
        Serial.println("A TV se encontra desligada. Gostaria de ligar?");
      } 
      else{
        Serial.println("A TV se encontra ligada. Gostaria de Desligar?");
      }
    } 
  }
}

