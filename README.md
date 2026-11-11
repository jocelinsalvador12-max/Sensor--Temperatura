Sistema de monitoreo de temperatura y humedad con Arduino

Descripción
Este proyecto utiliza un Arduino UNO para medir la temperatura y la
humedad del ambiente mediante un sensor DHT11. Los valores obtenidos se
muestran en una pantalla LCD con módulo I2C.

Cuando la temperatura alcanza los 40 °C o más, el sistema activa una
alerta visual y sonora: el LED azul parpadea y el buzzer suena tres
veces. La alarma no vuelve a activarse mientras la temperatura
permanezca en 40 °C o más. Se habilita nuevamente cuando la temperatura
baja de 40 °C y después vuelve a alcanzar ese límite.

Objetivo
Desarrollar un sistema sencillo de monitoreo ambiental que permita
visualizar la temperatura y la humedad, además de alertar cuando se
detecte una temperatura elevada.

Componentes
- Arduino UNO.
- Sensor de temperatura y humedad DHT11.
- Pantalla LCD de 16 × 2 con módulo I2C.
- LED azul.
- Resistencia para el LED (por ejemplo, 220 Ω o 330 Ω).
- Buzzer.
- Protoboard.
- Cables jumper.
- Cable USB para alimentar y programar el Arduino.

Conexiones
  Componente                                          Conexión al Arduino
  DHT11 (DATA)                                        A0
LCD I2C (SDA)                                       A4
LCD I2C (SCL)                                       A5
LED azul (ánodo/pata larga, mediante resistencia)   Pin 8
LED azul (cátodo/pata corta)                        GND
Buzzer (+)                                          Pin 9
Buzzer (−)                                          GND
Alimentación de los módulos                         5V y GND, según corresponda

Importante: el LED debe llevar una resistencia en serie. Comprueba
las marcas + y − del buzzer; la longitud de sus patas puede variar
según el modelo. Comparte GND entre los componentes y el Arduino.
Funcionamiento
1. El Arduino inicia la pantalla LCD y el sensor DHT11.
2. El sensor toma lecturas de temperatura y humedad.
3. La pantalla muestra ambos valores.
4. Si la temperatura es menor de 40 °C, la alarma permanece apagada.
5. Si la temperatura llega a 40 °C o más, el LED y el buzzer se activan
   tres veces.
6. La alarma queda bloqueada mientras la temperatura siga en 40 °C o
   más.
7. Cuando la lectura baja de 40 °C, el sistema queda listo para
   detectar un nuevo aumento y activar otra vez la alarma.
   
Requisitos de software
- Arduino IDE.
- Biblioteca DHT sensor library (Adafruit).
- Biblioteca LiquidCrystal_I2C.
- Biblioteca Wire (incluida con el entorno Arduino).
Instala las bibliotecas desde el Administrador de bibliotecas del
Arduino IDE si todavía no están disponibles.

Configuración
El programa utiliza estos valores:
- Sensor DHT11: pin A0.
- LED azul: pin 8.
- Buzzer: pin 9.
- Dirección I2C de la pantalla: 0x27.
- Umbral de alarma: 40 °C.
- Número de avisos: 3.
Si la pantalla no muestra información, verifica su dirección I2C;
algunos módulos utilizan una dirección distinta de 0x27.

Prueba del proyecto
1. Conecta los componentes de acuerdo con la tabla.
2. Abre el programa en Arduino IDE.
3. Selecciona la placa Arduino UNO y el puerto correspondiente.
4. Carga el programa.
5. Comprueba que la pantalla muestre temperatura y humedad.
6. Para probar la alarma sin esperar a que el ambiente alcance 40 °C,
   cambia temporalmente la condición t >= 40 por un umbral menor.
   Después de la prueba, restablece el valor a 40.
   
Notas y solución de problemas
- La pantalla no muestra datos: revisa SDA, SCL, alimentación y
  dirección I2C.
- Aparece "Error lectura": revisa la conexión DATA del DHT11, su
  alimentación y el tipo de sensor configurado.
- El LED no enciende: verifica su polaridad, la resistencia y que
  esté conectado al pin 8 y a GND.
- El buzzer no suena o suena bajo: revisa su polaridad y confirma
  si es activo o pasivo. El buzzer pasivo requiere una señal de
  frecuencia, por ejemplo tone(9, 1000). Cambiar la frecuencia
  modifica el tono, pero no garantiza mayor volumen.
- La alarma se repite: comprueba que el programa restablezca el
  indicador de alarma únicamente cuando la temperatura baje de 40 °C.
  
Resultado esperado
El sistema permite consultar la temperatura y la humedad en la pantalla
LCD. Al detectar una temperatura de 40 °C o superior, emite tres avisos
mediante el LED azul y el buzzer. Después espera a que la temperatura
descienda por debajo del límite antes de permitir una nueva alerta.
Autoría
Proyecto académico realizado con Arduino UNO y componentes electrónicos
básicos.
