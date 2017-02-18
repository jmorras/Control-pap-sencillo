// Programa para probar el movimiento de un motor paso a paso mediante la cncshield
// Conectamos los cuatro cables del motor paso a paso a los pines marcados con X
// El pololu necesita tres señales de control: Enable, Dirección y Paso
// En la placa cncshield, Enable es común para todos los pololus.
// El pololu del motor X se controla con las señales Dir_Pin_X (pata 5) y Step_Pin_X (pata 2)
// Esta información se puede sacar del esquema
// La señal Enable está activa con nivel bajo (LOW) y con HIGH se desactiva el motor
//
// Este programa genera una serie de pulsos en la salida Step_Pin_X (Hay que ponerlo a 1, esperar un tiempo, ponerlo a 0)
// Cuando ha mandado un número de pulsos, cambia la dirección


int EnPin = 8;     // cncshield conecta la señal de enable de los 4 pololus al pin 8
int Dir_Pin_X = 5; // cncshield conecta la señal de dirección del motor X al pin 5
int Step_Pin_X = 2;  // cncshield conecta la señal de paso del motor X al pin 2

bool Dir_estado = LOW;   // Esta variable sirve para cambiar de dirección
int contador = 0;

int Tempsensor = 9; // ping para poner el sensor de temperatura


void setup() {
  pinMode(EnPin, OUTPUT);        // Define el pin como salida
  pinMode(Dir_Pin_X, OUTPUT);    // Define el pin como salida
  pinMode(Step_Pin_X, OUTPUT);     // Define el pin como salida
  
  digitalWrite(EnPin, LOW);      // El pololu se activa con nivel bajo
  digitalWrite(Dir_Pin_X, Dir_estado);   // Saca por la pata de dircción el estado inicial
  
  //configurar pin de sensor temperatura
  
}

void loop() {                    // Para mandar un paso tenemos que mandar un 1 y luego un 0
  digitalWrite(Step_Pin_X, HIGH);  // Activa el pin de Paso
  delay(10);                     // Espera un poco
  digitalWrite(Step_Pin_X, LOW);   // Desactiva el pin de Paso
  delay(10);                     // Espera un poco
  contador = contador + 1;
  if (contador == 140) {
    Dir_estado = !Dir_estado;    // Invierte la direccion
    contador=0;                  // Reinicia el contador para hacer otros pasos en dirección contraria
    digitalWrite(Dir_Pin_X, Dir_estado);    // Saca por el pin de dirección el estado de la dirección
    if LeeTemp() >50 then
      end;  // no recuerdo si hay que poner end ó exit().
    
  }
  
  int LeeTemp()
  {// codigo para leer el sensor de temperatura
    
  }
}
