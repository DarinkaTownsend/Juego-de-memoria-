
// bocina
int speakerPin = A3;

//flags
bool flag1 = true;
bool flag2 = true;
bool flag3 = true;
bool flag4 = true;
bool flag5 = true;
bool flag6 = true;
bool flag7 = true;

//pasa niveles
bool pas1 = false;
bool pas2 = false;
bool pas3 = false;
bool pas4 = false;
bool pas5 = false;
bool pas6 = false;
bool pas7 = false;

//JUEGO INICIADO
bool inicio=false;
bool ganando = false;
bool perdi=false;

// Definir los pines para LEDs
int Led0_13 = 2;
int Led1_12 = 3;
int Led2_11 = 4;
int Led3_10 = 5;
int Led4_9 = 6;
int Led5_8 = 7;
int Led6_7 = 8;

//Definir los botones
int Boton0_13 = 9;
int Boton1_12 = 10;
int Boton2_11 = 11;
int Boton3_10 = 12;
int Boton4_9 = A1;
int Boton5_8 = A5;
int Boton6_7 = A4;

int InicioJuego = A2;
bool final_juego = false;

// Inicializar el juego

int nivel1[] = {Led0_13, Led1_12};
int nivel2[] = {Led0_13, Led1_12, Led1_12};
int nivel3[] = {Led0_13, Led1_12, Led1_12, Led2_11};
int nivel4[] = {Led0_13, Led1_12, Led1_12, Led2_11, Led3_10};
int nivel5[] = {Led0_13, Led1_12, Led1_12, Led2_11, Led3_10, Led5_8};
int nivel6[] = {Led0_13, Led1_12, Led1_12, Led2_11, Led3_10, Led5_8, Led5_8};
int nivel7[] = {Led0_13, Led1_12, Led1_12, Led2_11, Led3_10, Led5_8, Led5_8, Led0_13};

void setup() {
  Serial.begin(9600);
  
  // BOCINA
  
  pinMode(speakerPin, OUTPUT);
  
  // Configurar pines de LEDs como salida
  pinMode(Led0_13, OUTPUT);
  pinMode(Led1_12, OUTPUT);
  pinMode(Led2_11, OUTPUT);
  pinMode(Led3_10, OUTPUT);
  pinMode(Led4_9, OUTPUT);
  pinMode(Led5_8, OUTPUT);
  pinMode(Led6_7, OUTPUT);
  
  // Configurar pines de botones como entrada
  pinMode(Boton0_13, INPUT);
  pinMode(Boton1_12, INPUT);
  pinMode(Boton2_11, INPUT);
  pinMode(Boton3_10, INPUT);
  pinMode(Boton4_9, INPUT);
  pinMode(Boton5_8, INPUT);
  pinMode(Boton6_7, INPUT);
  pinMode(InicioJuego, INPUT);
}

void loop() {
  while(ganando){
    if(inicio){
      Serial.print("\n------------------- NIVEL 1----------------------------");
      nivel_Luz(nivel1, 2);
      digitalWrite(speakerPin, HIGH);
      delay(200);
      digitalWrite(speakerPin, LOW);
      nivel1_funcion_lectura();
        inicio=false;
    }else if (pas1){
      encender_todas_luces_carrera();
      Serial.print("\n------------------- NIVEL 2----------------------------");
      nivel_Luz(nivel2, 3);
      digitalWrite(speakerPin, HIGH);
      delay(200);
      digitalWrite(speakerPin, LOW);
      nivel2_funcion_lectura();
      pas1=false;
    }else if (pas2){
      encender_todas_luces_carrera();
      Serial.print("\n------------------- NIVEL 3----------------------------");
      nivel_Luz(nivel3, 4);
      digitalWrite(speakerPin, HIGH);
      delay(200);
      digitalWrite(speakerPin, LOW);
      nivel3_funcion_lectura();
      pas2=false;
    }else if (pas3){
      encender_todas_luces_carrera();
      Serial.print("\n------------------- NIVEL 4----------------------------");
      nivel_Luz(nivel4, 5);
      digitalWrite(speakerPin, HIGH);
      delay(200);
      digitalWrite(speakerPin, LOW);
      nivel4_funcion_lectura();
      pas3=false;
    }else if (pas4){
      encender_todas_luces_carrera();
      Serial.print("\n------------------- NIVEL 5----------------------------");
      nivel_Luz(nivel5, 6);
      digitalWrite(speakerPin, HIGH);
      delay(200);
      digitalWrite(speakerPin, LOW);
      nivel5_funcion_lectura();
      pas4=false;
    }else if (pas5){
      encender_todas_luces_carrera();
      Serial.print("\n------------------- NIVEL 6----------------------------");
      nivel_Luz(nivel6, 7);
      digitalWrite(speakerPin, HIGH);
      delay(200);
      digitalWrite(speakerPin, LOW);
      nivel6_funcion_lectura();
      pas5=false;
    }else if (pas6){
      encender_todas_luces_carrera();
      Serial.print("\n------------------- NIVEL 7----------------------------");
      nivel_Luz(nivel7, 8);
      digitalWrite(speakerPin, HIGH);
      delay(200);
      digitalWrite(speakerPin, LOW);
      nivel7_funcion_lectura();
      pas6=false;
    }else if (pas7){
      encender_luces_secuencia_doble();
      Musica_Ganadora();
      ganando=false;
      Serial.print("\n------------------- FIN ----------------------------");

    }}
  if(digitalRead(InicioJuego)==HIGH){
    Serial.print("Inicio de Juego");
    encender_todas_luces();
    Musica_Ganadora();
    inicio=true;
    ganando = true;
    flag1 = true;
    flag2 = true;
    flag3 = true;
    flag4 = true;
    flag5 = true;
    flag6 = true;
    flag7 = true;
    pas1 = false;
    pas2 = false;
    pas3 = false;
    pas4 = false;
    pas5 = false;
    pas6 = false;
    pas7 = false;
  
    }
    
}

void nivel1_funcion_lectura() {
  bool boton1_pres=false;
  while(flag1){
    if(digitalRead(Boton0_13)==HIGH && boton1_pres==false){
      Serial.print("\nBoton0_13 pulsado");
      digitalWrite(Led0_13, HIGH);
      delay(1000);
      digitalWrite(Led0_13, LOW);
      boton1_pres=true;      
    }else if((digitalRead(Boton1_12)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)&& boton1_pres==false){
        Serial.print("\nOtro boton presionado");
        encender_todas_luces();
        Musica_Perdedora();
        flag1=false;
        pas1=false;
        ganando=false;
    }else if(digitalRead(Boton1_12)==HIGH && boton1_pres==true){
        Serial.print("\nBoton1_12 pulsado");
        digitalWrite(Led1_12, HIGH);
        delay(1000);
        digitalWrite(Led1_12, LOW);
        flag1=false;
        pas1=true;
    }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)&& boton1_pres==true){
        Serial.print("\nOtro boton presionado 2");
        encender_todas_luces();
        Musica_Perdedora();
        flag1=false;
        pas1=false;
        ganando=false;
  }
  }
 }

void nivel2_funcion_lectura() {
  bool boton1_pres=false;
  bool boton2_pres=false;
  while(flag2){
    if(digitalRead(Boton0_13)==HIGH && boton1_pres==false && boton2_pres==false){
      Serial.print("\nBoton0_13 pulsado");
      digitalWrite(Led0_13, HIGH);
      delay(1000);
      digitalWrite(Led0_13, LOW);
      boton1_pres=true;      
    }else if((digitalRead(Boton1_12)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)&& boton1_pres==false && boton2_pres==false){
      encender_todas_luces();
        Musica_Perdedora();
        flag2=false;
        pas2=false;
        ganando=false;
    }else if(digitalRead(Boton1_12)==HIGH && boton1_pres==true && boton2_pres==false){
        Serial.print("\nBoton1_12 pulsado");
        digitalWrite(Led1_12, HIGH);
        delay(1000);
        digitalWrite(Led1_12, LOW);
        boton2_pres=true; 
    }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)&& boton1_pres==true && boton2_pres==false){
        encender_todas_luces();
        Musica_Perdedora();
        flag2=false;
        pas2=false;
        ganando=false;
  }else if(digitalRead(Boton1_12)==HIGH && boton1_pres==true && boton2_pres==true){
        Serial.print("\nBoton1_12 pulsado");
        digitalWrite(Led1_12, HIGH);
        delay(1000);
        digitalWrite(Led1_12, LOW);
        flag2=false;
        pas2=true;
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)&& boton1_pres==true && boton2_pres==false){
        encender_todas_luces();
        Musica_Perdedora();
        flag2=false;
        pas2=false;
        ganando=false;
      
  
  }
  }
 }



void nivel3_funcion_lectura() {
  bool boton1_pres=false;
  bool boton2_pres=false;
  bool boton3_pres=false;
  while(flag3){
    if(digitalRead(Boton0_13)==HIGH && boton1_pres==false 
       && boton2_pres==false && boton3_pres==false){
      Serial.print("\nBoton0_13 pulsado");
      digitalWrite(Led0_13, HIGH);
      delay(1000);
      digitalWrite(Led0_13, LOW);
      boton1_pres=true;      
    }else if((digitalRead(Boton1_12)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)&& boton1_pres==false 
             && boton2_pres==false && boton3_pres==false){
      encender_todas_luces();
        Musica_Perdedora();
        flag3=false;
        pas3=false;
        ganando=false;
    }else if(digitalRead(Boton1_12)==HIGH && boton1_pres==true 
             && boton2_pres==false && boton3_pres==false){
        Serial.print("\nBoton1_12 pulsado");
        digitalWrite(Led1_12, HIGH);
        delay(1000);
        digitalWrite(Led1_12, LOW);
        boton2_pres=true;
    }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
             && boton1_pres==true && boton2_pres==false
             && boton3_pres==false){
        encender_todas_luces();
        Musica_Perdedora();
        flag3=false;
        pas3=false;
        ganando=false;
  }else if(digitalRead(Boton1_12)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==false){
      Serial.print("\nBoton1_12 pulsado");
      digitalWrite(Led1_12, HIGH);
        delay(1000);
        digitalWrite(Led1_12, LOW);
        boton3_pres=true;
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==false){
        encender_todas_luces();
        Musica_Perdedora();
        flag3=false;
        pas3=false;
        ganando=false;

  }else if(digitalRead(Boton2_11)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==true){
        Serial.print("\nBoton2_11 pulsado");
        digitalWrite(Led2_11, HIGH);
        delay(1000);
        digitalWrite(Led2_11, LOW);
        flag3=false;
        pas3=true;
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton1_12) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==true){
        encender_todas_luces();
        Musica_Perdedora();
        flag3=false;
        pas3=false;
        ganando=false;
  }
  }
 }




void nivel_Luz(int* nivel, int length) {
  
  for (int i = 0; i < length; i++) {
    digitalWrite(nivel[i], HIGH);
    delay(500);
    digitalWrite(nivel[i], LOW);
    delay(500);
  }
}

void nivel4_funcion_lectura() {
    bool boton1_pres=false;
    bool boton2_pres=false;
    bool boton3_pres=false;
    bool boton4_pres = false;
    while(flag4){
        if(digitalRead(Boton0_13)==HIGH && boton1_pres==false 
        && boton2_pres==false && boton3_pres==false
        && boton4_pres==false){
        Serial.print("\nBoton0_13 pulsado");
        digitalWrite(Led0_13, HIGH);
        delay(1000);
        digitalWrite(Led0_13, LOW);
        boton1_pres=true;      
    }else if((digitalRead(Boton1_12)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)&& boton1_pres==false 
             && boton2_pres==false && boton3_pres==false
             && boton4_pres==false){
      encender_todas_luces();
        Musica_Perdedora();
        flag4=false;
        pas4=false;
        ganando=false;
    }else if(digitalRead(Boton1_12)==HIGH && boton1_pres==true 
             && boton2_pres==false && boton3_pres==false
             && boton4_pres==false){
        Serial.print("\nBoton1_12 pulsado");
        digitalWrite(Led1_12, HIGH);
        delay(1000);
        digitalWrite(Led1_12, LOW);
        boton2_pres=true;
    }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
             && boton1_pres==true && boton2_pres==false
             && boton3_pres==false && boton4_pres==false){
        encender_todas_luces();
        Musica_Perdedora();
        flag4=false;
        pas4=false;
        ganando=false;
  }else if(digitalRead(Boton1_12)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==false
             && boton4_pres==false){
        Serial.print("\nBoton1_12 pulsado");
        digitalWrite(Led1_12, HIGH);
        delay(1000);
        digitalWrite(Led1_12, LOW);
        boton3_pres=true;
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==false && boton4_pres==false){
        encender_todas_luces();
        Musica_Perdedora();
        flag4=false;
        pas4=false;
        ganando=false;
  }else if(digitalRead(Boton2_11)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==true
             && boton4_pres==false){
        Serial.print("\nBoton2_11 pulsado");
        digitalWrite(Led2_11, HIGH);
        delay(1000);
        digitalWrite(Led2_11, LOW);
        boton4_pres=true;
  
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton1_12) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==true && boton4_pres==false){
        encender_todas_luces();
        Musica_Perdedora();
        flag4=false;
        pas4=false;
        ganando=false;
  }else if(digitalRead(Boton3_10)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==true
             && boton4_pres==true){
        Serial.print("\nBoton3_10 pulsado");
        digitalWrite(Led3_10, HIGH);
        delay(1000);
        digitalWrite(Led3_10, LOW);
        flag4=false;
        pas4=true;
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton1_12) == HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==true && boton4_pres==true){
        encender_todas_luces();
        Musica_Perdedora();
        flag4=false;
        pas4=false;
        ganando=false;
  }
  }
}



void nivel5_funcion_lectura() {
    bool boton1_pres=false;
    bool boton2_pres=false;
    bool boton3_pres=false;
    bool boton4_pres = false;
    bool boton5_pres = false;
    while(flag5){
        if(digitalRead(Boton0_13)==HIGH && boton1_pres==false 
        && boton2_pres==false && boton3_pres==false
        && boton4_pres==false && boton5_pres  == false){
        Serial.print("\nBoton0_13 pulsado");
        digitalWrite(Led0_13, HIGH);
        delay(1000);
        digitalWrite(Led0_13, LOW);
        boton1_pres=true;      
    }else if((digitalRead(Boton1_12)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)&& boton1_pres==false 
             && boton2_pres==false && boton3_pres==false
             && boton4_pres==false && boton5_pres  == false){
      encender_todas_luces();
        Musica_Perdedora();
        flag5=false;
        pas5=false;
        ganando=false;
    }else if(digitalRead(Boton1_12)==HIGH && boton1_pres==true 
             && boton2_pres==false && boton3_pres==false
             && boton4_pres==false && boton5_pres  == false){
        Serial.print("\nBoton1_12 pulsado");
        digitalWrite(Led1_12, HIGH);
        delay(1000);
        digitalWrite(Led1_12, LOW);
        boton2_pres=true;
    }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
             && boton1_pres==true && boton2_pres==false
             && boton3_pres==false && boton4_pres==false
             && boton5_pres  == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag5=false;
        pas5=false;
        ganando=false;
  }else if(digitalRead(Boton1_12)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==false
             && boton4_pres==false && boton5_pres  == false){
        Serial.print("\nBoton1_12 pulsado");
        digitalWrite(Led1_12, HIGH);
        delay(1000);
        digitalWrite(Led1_12, LOW);
        boton3_pres=true;
        Serial.print("Entra corr");
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==false && boton4_pres==false
           && boton5_pres  == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag5=false;
        pas5=false;
        ganando=false;
  }else if(digitalRead(Boton2_11)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==true
             && boton4_pres==false && boton5_pres  == false){
        Serial.print("\nBoton2_11 pulsado");
        digitalWrite(Led2_11, HIGH);
        delay(1000);
        digitalWrite(Led2_11, LOW);
        boton4_pres=true;
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton1_12) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==true && boton4_pres==false
           && boton5_pres  == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag5=false;
        pas5=false;
        ganando=false;
  }else if(digitalRead(Boton3_10)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==true
             && boton4_pres==true && boton5_pres  == false){
        Serial.print("\nBoton3_10 pulsado");
        digitalWrite(Led3_10, HIGH);
        delay(1000);
        digitalWrite(Led3_10, LOW);
        boton5_pres=true;
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton1_12) == HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==true && boton4_pres==true && boton5_pres  == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag5=false;
        pas5=false;
        ganando=false;
  }else if(digitalRead(Boton5_8)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==true
             && boton4_pres==true && boton5_pres  == true){
        Serial.print("\nBoton5_8 pulsado");
        digitalWrite(Led5_8, HIGH);
        delay(1000);
        digitalWrite(Led5_8, LOW);
        flag5=false;
        pas5=true;
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton1_12) == HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton3_10)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==true && boton4_pres==true && boton5_pres  == true){
        encender_todas_luces();
        Musica_Perdedora();
        flag5=false;
        pas5=false;
        ganando=false;
  }
  }
}

void nivel6_funcion_lectura() {
    bool boton1_pres=false;
    bool boton2_pres=false;
    bool boton3_pres=false;
    bool boton4_pres = false;
    bool boton5_pres = false;
    bool boton6_pres = false;
    while(flag6){
        if(digitalRead(Boton0_13)==HIGH && boton1_pres==false 
        && boton2_pres==false && boton3_pres==false
        && boton4_pres==false && boton5_pres  == false && boton6_pres == false){
        Serial.print("\nBoton0_13 pulsado");
        digitalWrite(Led0_13, HIGH);
        delay(1000);
        digitalWrite(Led0_13, LOW);
        boton1_pres=true;      
    }else if((digitalRead(Boton1_12)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)&& boton1_pres==false 
             && boton2_pres==false && boton3_pres==false
             && boton4_pres==false && boton5_pres  == false
             && boton6_pres == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag6=false;
        pas6=false;
        ganando=false;
    }else if(digitalRead(Boton1_12)==HIGH && boton1_pres==true 
             && boton2_pres==false && boton3_pres==false
             && boton4_pres==false && boton5_pres  == false
             && boton6_pres == false){
        Serial.print("\nBoton1_12 pulsado");
        digitalWrite(Led1_12, HIGH);
        delay(1000);
        digitalWrite(Led1_12, LOW);
        boton2_pres=true;
    }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
             && boton1_pres==true && boton2_pres==false
             && boton3_pres==false && boton4_pres==false
             && boton5_pres  == false && boton6_pres == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag6=false;
        pas6=false;
        ganando=false;
  }else if(digitalRead(Boton1_12)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==false
             && boton4_pres==false && boton5_pres  == false
             && boton6_pres == false){
        Serial.print("\nBoton1_12 pulsado");
        digitalWrite(Led1_12, HIGH);
        delay(1000);
        digitalWrite(Led1_12, LOW);
        boton3_pres=true;
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==false && boton4_pres==false
           && boton5_pres  == false && boton6_pres == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag6=false;
        pas6=false;
        ganando=false;
  }else if(digitalRead(Boton2_11)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==true
             && boton4_pres==false && boton5_pres  == false && boton6_pres == false){
        Serial.print("\nBoton2_11 pulsado");
        digitalWrite(Led2_11, HIGH);
        delay(1000);
        digitalWrite(Led2_11, LOW);
        boton4_pres=true;

  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton1_12) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==true && boton4_pres==false
           && boton5_pres  == false && boton6_pres == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag6=false;
        pas6=false;
        ganando=false;
  }else if(digitalRead(Boton3_10)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==true
             && boton4_pres==true && boton5_pres  == false
             && boton6_pres == false){
        Serial.print("\nBoton3_10 pulsado");
        digitalWrite(Led3_10, HIGH);
        delay(1000);
        digitalWrite(Led3_10, LOW);
        boton5_pres=true;
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton1_12) == HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==true && boton4_pres==true && boton5_pres  == false
           && boton6_pres == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag6=false;
        pas6=false;
        ganando=false;
  }else if(digitalRead(Boton5_8)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==true
             && boton4_pres==true && boton5_pres  == true
             && boton6_pres == false){
        Serial.print("\nBoton5_8 pulsado");
        digitalWrite(Led5_8, HIGH);
        delay(1000);
        digitalWrite(Led5_8, LOW);
        boton6_pres=true;
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton1_12) == HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton3_10)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==true && boton4_pres==true && boton5_pres  == true
           && boton6_pres == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag6=false;
        pas6=false;
        ganando=false;
  }else if(digitalRead(Boton5_8)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==true
             && boton4_pres==true && boton5_pres  == true
             && boton6_pres == true){
        Serial.print("\nBoton5_8 pulsado");
        digitalWrite(Led5_8, HIGH);
        delay(1000);
        digitalWrite(Led5_8, LOW);
        flag6=false;
        pas6=true;
        
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton1_12) == HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton3_10)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==true && boton4_pres==true && boton5_pres  == true
           && boton6_pres == true){
        encender_todas_luces();
        Musica_Perdedora();
        flag6=false;
        pas6=false;
        ganando=false;
  }
  }
}


void nivel7_funcion_lectura() {
    bool boton1_pres=false;
    bool boton2_pres=false;
    bool boton3_pres=false;
    bool boton4_pres = false;
    bool boton5_pres = false;
    bool boton6_pres = false;
    bool boton7_pres = false;
    while(flag7){
        if(digitalRead(Boton0_13)==HIGH && boton1_pres==false 
        && boton2_pres==false && boton3_pres==false
        && boton4_pres==false && boton5_pres  == false && boton6_pres == false
        && boton7_pres == false){
        Serial.print("\nBoton0_13 pulsado");
        digitalWrite(Led0_13, HIGH);
        delay(1000);
        digitalWrite(Led0_13, LOW);
        boton1_pres=true;      
    }else if((digitalRead(Boton1_12)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)&& boton1_pres==false 
             && boton2_pres==false && boton3_pres==false
             && boton4_pres==false && boton5_pres  == false
             && boton6_pres == false && boton7_pres == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag7=false;
        pas7=false;
        ganando=false;
    }else if(digitalRead(Boton1_12)==HIGH && boton1_pres==true 
             && boton2_pres==false && boton3_pres==false
             && boton4_pres==false && boton5_pres  == false
             && boton6_pres == false && boton7_pres == false){
        Serial.print("\nBoton1_12 pulsado");
        digitalWrite(Led1_12, HIGH);
        delay(1000);
        digitalWrite(Led1_12, LOW);
        boton2_pres=true;
    }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
             && boton1_pres==true && boton2_pres==false
             && boton3_pres==false && boton4_pres==false
             && boton5_pres  == false && boton6_pres == false
             && boton7_pres == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag7=false;
        pas7=false;
        ganando=false;
  }else if(digitalRead(Boton1_12)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==false
             && boton4_pres==false && boton5_pres  == false
             && boton6_pres == false && boton7_pres == false){
        Serial.print("\nBoton1_12 pulsado");
        digitalWrite(Led1_12, HIGH);
        delay(1000);
        digitalWrite(Led1_12, LOW);
        boton3_pres=true;
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==false && boton4_pres==false
           && boton5_pres  == false && boton6_pres == false
           && boton7_pres == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag7=false;
        pas7=false;
        ganando=false;
  }else if(digitalRead(Boton2_11)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==true
             && boton4_pres==false && boton5_pres  == false && boton6_pres == false
             && boton7_pres == false){
        Serial.print("\nBoton2_11 pulsado");
        digitalWrite(Led2_11, HIGH);
        delay(1000);
        digitalWrite(Led2_11, LOW);
        boton4_pres=true;
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton1_12) == HIGH | 
             digitalRead(Boton3_10) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==true && boton4_pres==false
           && boton5_pres  == false && boton6_pres == false
           && boton7_pres == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag7=false;
        pas7=false;
        ganando=false;
  }else if(digitalRead(Boton3_10)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==true
             && boton4_pres==true && boton5_pres  == false
             && boton6_pres == false && boton7_pres == false){
        Serial.print("\nBoton3_10 pulsado");
        digitalWrite(Led3_10, HIGH);
        delay(1000);
        digitalWrite(Led3_10, LOW);
        boton5_pres=true;
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton1_12) == HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==true && boton4_pres==true && boton5_pres  == false
           && boton6_pres == false && boton7_pres == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag7=false;
        pas7=false;
        ganando=false;
  }else if(digitalRead(Boton5_8)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==true
             && boton4_pres==true && boton5_pres  == true
             && boton6_pres == false && boton7_pres == false){
        Serial.print("\nBoton5_8 pulsado");
        digitalWrite(Led5_8, HIGH);
        delay(1000);
        digitalWrite(Led5_8, LOW);
        boton6_pres=true;
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton1_12) == HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton3_10)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==true && boton4_pres==true && boton5_pres  == true
           && boton6_pres == false && boton7_pres == false){
        encender_todas_luces();
        Musica_Perdedora();
        flag7=false;
        pas7=false;
        ganando=false;
  }else if(digitalRead(Boton5_8)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==true
             && boton4_pres==true && boton5_pres  == true
             && boton6_pres == true && boton7_pres == false){
        Serial.print("\nBoton5_8 pulsado");
        digitalWrite(Led5_8, HIGH);
        delay(1000);
        digitalWrite(Led5_8, LOW);
        boton7_pres=true;
        
  }else if((digitalRead(Boton0_13)==HIGH | 
             digitalRead(Boton1_12) == HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton3_10)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==true && boton4_pres==true && boton5_pres  == true
           && boton6_pres == true && boton7_pres==false){
        encender_todas_luces();
        Musica_Perdedora();
        flag6=false;
        pas6=false;
        ganando=false;
  }else if(digitalRead(Boton0_13)==HIGH && boton1_pres==true 
             && boton2_pres==true && boton3_pres==true
             && boton4_pres==true && boton5_pres  == true
             && boton6_pres == true && boton7_pres==true){
        Serial.print("\nBoton0_13 pulsado");
        digitalWrite(Led0_13, HIGH);
        delay(1000);
        digitalWrite(Led0_13, LOW);
        flag7=false;
        pas7=true;
  }else if((digitalRead(Boton5_8)==HIGH | 
             digitalRead(Boton1_12) == HIGH | 
             digitalRead(Boton2_11) == HIGH | 
             digitalRead(Boton4_9) == HIGH | 
             digitalRead(Boton3_10)==HIGH | 
             digitalRead(Boton6_7) == HIGH)
           && boton1_pres==true && boton2_pres==true
           && boton3_pres==true && boton4_pres==true && boton5_pres  == true
           && boton6_pres == true && boton7_pres == true){
        encender_todas_luces();
        Musica_Perdedora();
        flag7=false;
        pas7=false;
        ganando=false;
  }
  }
}





       
void Musica_Perdedora() {
  Serial.print("Perdiste!");
  // Definir las frecuencias de las notas (puedes ajustarlas según tus preferencias)
  int notas[] = {262,260,260,330};
  //int notas[] = {262, 294, 330, 349, 392, 440, 494, 523};
  
  // Definir las duraciones de las notas (en milisegundos)
  int duraciones[] = {200, 200, 200, 200, 200, 200, 200, 200};
  
  // Reproducir la melodía
  for (int i = 0; i < sizeof(notas) / sizeof(notas[0]); i++) {
    tone(speakerPin, notas[i], duraciones[i]);
    delay(300);  // Pausa corta entre notas
  }
  

}

void Musica_Ganadora() {
  // Definir las frecuencias de las notas (puedes ajustarlas según tus preferencias)
  int notas[] = {330,392,440,523};
  
  //int notas[] = {262, 294, 330, 349};
  
  // Definir las duraciones de las notas (en milisegundos)
  int duraciones[] = {200, 200, 200, 200, 200, 200, 200, 200};
  
  // Reproducir la melodía
  for (int i = 0; i < sizeof(notas) / sizeof(notas[0]); i++) {
    tone(speakerPin, notas[i], duraciones[i]);
    delay(300);  // Pausa corta entre notas
  }
  
}

void encender_todas_luces(){
    digitalWrite(Led0_13, HIGH);
    digitalWrite(Led1_12, HIGH);
    digitalWrite(Led2_11, HIGH);
    digitalWrite(Led3_10, HIGH);
    digitalWrite(Led4_9, HIGH);
    digitalWrite(Led5_8, HIGH);
    digitalWrite(Led6_7, HIGH);
   
    delay(500);
    digitalWrite(Led0_13, LOW);
    digitalWrite(Led1_12, LOW);
    digitalWrite(Led2_11, LOW);
    digitalWrite(Led3_10, LOW);
    digitalWrite(Led4_9, LOW);
    digitalWrite(Led5_8, LOW);
    digitalWrite(Led6_7, LOW);
  

}

void encender_todas_luces_carrera() {
    digitalWrite(Led0_13, HIGH);
    delay(100);
    digitalWrite(Led0_13, LOW);

    digitalWrite(Led1_12, HIGH);
    delay(100);
    digitalWrite(Led1_12, LOW);

    digitalWrite(Led2_11, HIGH);
    delay(100);
    digitalWrite(Led2_11, LOW);

    digitalWrite(Led3_10, HIGH);
    delay(100);
    digitalWrite(Led3_10, LOW);

    digitalWrite(Led4_9, HIGH);
    delay(100);
    digitalWrite(Led4_9, LOW);

    digitalWrite(Led5_8, HIGH);
    delay(100);
    digitalWrite(Led5_8, LOW);

    digitalWrite(Led6_7, HIGH);
    delay(100);
    digitalWrite(Led6_7, LOW);

    // Retardo después de encender todas las luces
    delay(500);
}

void encender_luces_secuencia_doble() {
    // Encendido y apagado de ida
    digitalWrite(Led0_13, HIGH);
    delay(100);
    digitalWrite(Led0_13, LOW);

    digitalWrite(Led1_12, HIGH);
    delay(100);
    digitalWrite(Led1_12, LOW);

    digitalWrite(Led2_11, HIGH);
    delay(100);
    digitalWrite(Led2_11, LOW);

    digitalWrite(Led3_10, HIGH);
    delay(100);
    digitalWrite(Led3_10, LOW);

    digitalWrite(Led4_9, HIGH);
    delay(100);
    digitalWrite(Led4_9, LOW);

    digitalWrite(Led5_8, HIGH);
    delay(100);
    digitalWrite(Led5_8, LOW);

    digitalWrite(Led6_7, HIGH);
    delay(100);
    digitalWrite(Led6_7, LOW);

    // Retardo antes de cambiar de dirección
    delay(500);

    // Encendido y apagado de vuelta
    digitalWrite(Led6_7, HIGH);
    delay(100);
    digitalWrite(Led6_7, LOW);

    digitalWrite(Led5_8, HIGH);
    delay(100);
    digitalWrite(Led5_8, LOW);

    digitalWrite(Led4_9, HIGH);
    delay(100);
    digitalWrite(Led4_9, LOW);

    digitalWrite(Led3_10, HIGH);
    delay(100);
    digitalWrite(Led3_10, LOW);

    digitalWrite(Led2_11, HIGH);
    delay(100);
    digitalWrite(Led2_11, LOW);

    digitalWrite(Led1_12, HIGH);
    delay(100);
    digitalWrite(Led1_12, LOW);

    digitalWrite(Led0_13, HIGH);
    delay(100);
    digitalWrite(Led0_13, LOW);

    // Retardo antes de regresar a la dirección original
    delay(500);
}


  
