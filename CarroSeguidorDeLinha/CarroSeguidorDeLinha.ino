//Prof.William José - 2019
/*** DECLARAÇÃO DE VARIAVEIS ***/

#define MotorA_sentido1 2
#define MotorA_sentido2 4
#define MotorB_sentido1 8
#define MotorB_sentido2 9
#define MotorA_PWM 3  
#define MotorB_PWM 10  

/*** VARIÁVEIS PARA A VELOCIDADE DO ROBÔ ***/

#define veloc0 0
#define veloc1 30
#define veloc2 120 
#define veloc3 180
 
#define Sensor_direita 6
#define Sensor_esquerda 7
 
bool direita, esquerda;
 
void setup() {
  Serial.begin(9600);
  pinMode(MotorA_sentido1, OUTPUT);
  pinMode(MotorA_sentido2, OUTPUT);
  pinMode(MotorB_sentido1, OUTPUT);
  pinMode(MotorB_sentido2, OUTPUT);
  pinMode(MotorA_PWM, OUTPUT);
  pinMode(MotorB_PWM, OUTPUT);
  pinMode(Sensor_direita, INPUT);
  pinMode(Sensor_esquerda, INPUT);
}
 
void loop() {
   //Define o sentido de rotação dos motores
  digitalWrite(MotorA_sentido1, LOW);
  digitalWrite(MotorA_sentido2, HIGH);
  digitalWrite(MotorB_sentido1, HIGH);
  digitalWrite(MotorB_sentido2, LOW);
  
  //Leituras dos Sensores
  direita = digitalRead(Sensor_direita);
  esquerda = digitalRead(Sensor_esquerda);
  Serial.print(direita); // Acompanhamento dos resultados via Monitor Serial
  Serial.print(" || ");
  Serial.println(esquerda);
 
  //Rodando os motores 
 if(direita == false && esquerda == false){ // Nenhum sensor na linha preta
 analogWrite(MotorA_PWM, veloc2);
 analogWrite(MotorB_PWM, veloc2);
 } else if(direita == false && esquerda == true){ // Sensor esquerdo na linha preta
 delay(0);
 analogWrite(MotorA_PWM, veloc2);
 analogWrite(MotorB_PWM, veloc1);
 delay(0);
 }else if(direita == true && esquerda == false){ // Sensor direito na linha preta
 delay(0);
 analogWrite(MotorA_PWM, veloc1);
 analogWrite(MotorB_PWM, veloc2);
 delay(0);
 
 }else if(direita == true && esquerda == true){ // Ambos os sensores na trilha preta
 analogWrite(MotorA_PWM, veloc0);
 analogWrite(MotorB_PWM, veloc0);
 }
}
