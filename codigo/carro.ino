/************ PINOS DOS SENSORES DE LINHA ************/
#define SF_E A4   // Sensor Frontal Esquerdo
#define SF_D A5   // Sensor Frontal Direito
#define SL_E A2   // Sensor Lateral Esquerdo
#define SL_D A3   // Sensor Lateral Direito

/************ PINOS DOS MOTORES (PONTE H HW-095) ************/
#define ENA 5
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENB 6

/************ SENSOR ULTRASSONICO ************/
#define TRIG 4
#define ECHO 3

/************ CONFIGURAÇÕES ************/
int LIMIAR = 250;

int velMaxima = 200;  
int velNormal = 170;  
int velCurva  = 150;  
int velParado = 0;

void setup() {
  Serial.begin(9600);

  pinMode(SF_E, INPUT);
  pinMode(SF_D, INPUT);
  pinMode(SL_E, INPUT);
  pinMode(SL_D, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  parar();
  delay(500);
}

void motorEsquerdo(int velocidade) {
  if (velocidade > 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else if (velocidade < 0) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
  analogWrite(ENA, abs(velocidade));
}

void motorDireito(int velocidade) {
  if (velocidade > 0) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (velocidade < 0) {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
  analogWrite(ENB, abs(velocidade));
}

void frente() {
  motorEsquerdo(velNormal);
  motorDireito(velNormal);
}

void frenteLento() {
  motorEsquerdo(velCurva);
  motorDireito(velCurva);
}

void parar() {
  motorEsquerdo(0);
  motorDireito(0);
}

void curvaDireita() {
  motorEsquerdo(velNormal);
  motorDireito(velCurva);
}

void curvaEsquerda() {
  motorEsquerdo(velCurva);
  motorDireito(velNormal);
}

void curvaAcentuadaDireita() {
  motorEsquerdo(-100);
  motorDireito(velNormal);
}

void curvaAcentuadaEsquerda() {
  motorEsquerdo(velNormal);
  motorDireito(-100);
}

float distanciaCM() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(3);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duracao = pulseIn(ECHO, HIGH, 25000);
  if (duracao == 0) return 999;

  float distancia = (duracao * 0.0343) / 2.0;
  return distancia;
}

void loop() {

  int fe = analogRead(SF_E);
  int fd = analogRead(SF_D);
  int le = analogRead(SL_E);
  int ld = analogRead(SL_D);

  float dist = distanciaCM();

  bool preto_FE = fe > LIMIAR;
  bool preto_FD = fd > LIMIAR;
  bool preto_LE = le > LIMIAR;
  bool preto_LD = ld > LIMIAR;

  if (dist < 15) {
    parar();
    delay(200);
    curvaEsquerda();
    delay(300);
    return;
  }

  if (preto_FE && preto_FD && !preto_LE && !preto_LD) {
    frente();
  }
  else if (preto_FE && !preto_FD) {
    curvaEsquerda();
  }
  else if (!preto_FE && preto_FD) {
    curvaDireita();
  }
  else if (preto_LE) {
    curvaAcentuadaEsquerda();
  }
  else if (preto_LD) {
    curvaAcentuadaDireita();
  }
  else {
    frenteLento();
  }

  delay(20);
}
