# 🌡️ Sistema de Monitoreo de Temperatura y Humedad con Arduino

**Autor:** Jocelin Guadalupe Salvador Flores
**Carrera:** Ingeniería en Sistemas Computacionales  
---

## 📋 Descripción del Proyecto

Este proyecto utiliza un **Arduino UNO** para medir en tiempo real la temperatura y la humedad del ambiente mediante un sensor **DHT11**. Los valores obtenidos se muestran de forma clara en una pantalla **LCD con módulo I2C**.

Cuando la temperatura alcanza los **40 °C o más**, el sistema activa una alerta visual y sonora: el **LED azul** parpadea y el **buzzer** suena tres veces. La alarma no vuelve a activarse de forma repetitiva mientras la temperatura permanezca en ese rango o superior; se habilita nuevamente solo cuando la temperatura desciende y vuelve a alcanzar dicho límite.

## 🎯 Objetivo

Desarrollar un sistema embebido de monitoreo ambiental que permita visualizar métricas atmosféricas críticas y alertar automáticamente al detectar condiciones de temperatura elevada.

---

## 🛠️ Componentes Utilizados

* 🎛️ **Arduino UNO**
* 🌡️ **Sensor de temperatura y humedad DHT11**
* 🖥️ **Pantalla LCD de 16 × 2** con módulo I2C
* 💡 **LED azul**
* 🛡️ **Resistencia** para el LED (220 Ω o 330 Ω)
* 🔊 **Buzzer** (zumbador)
* 🔌 **Protoboard y cables jumper**
* 💻 **Cable USB** para alimentación y programación

---

## 🔌 Conexiones de Hardware

| Componente | Conexión al Arduino |
| :--- | :--- |
| **DHT11 (DATA)** | Pin `A0` |
| **LCD I2C (SDA)** | Pin `A4` |
| **LCD I2C (SCL)** | Pin `A5` |
| **LED azul (Ánodo / Pata larga)** | Pin `8` *(con resistencia)* |
| **LED azul (Cátodo / Pata corta)** | `GND` |
| **Buzzer (+)** | Pin `9` |
| **Buzzer (-)** | `GND` |
| **Alimentación de módulos** | `5V` y `GND` |

> **⚠️ Notas de Montaje:**  
> * El LED debe llevar obligatoriamente una resistencia en serie para evitar daños.  
> * Comprueba las polaridades (`+` y `-`) del buzzer; la longitud de sus patas puede variar según el modelo.  
> * Asegúrate de compartir adecuadamente la tierra (`GND`) entre todos los componentes y el Arduino.

---

## ⚙️ Configuración del Software

### Requisitos Previos
* [Arduino IDE](https://www.arduino.cc/en/software) instalado.
* Biblioteca **DHT sensor library** (de Adafruit).
* Biblioteca **LiquidCrystal_I2C**.
* Biblioteca **Wire** (incluida por defecto en el entorno de Arduino).

### Parámetros Principales del Código
* **Sensor DHT11:** Pin `A0`
* **LED azul:** Pin `8`
* **Buzzer:** Pin `9`
* **Dirección I2C del LCD:** `0x27` *(Nota: algunos módulos utilizan direcciones alternas como `0x3F`)*.
* **Umbral de alarma:** `40 °C`
* **Número de avisos:** `3`

---

## 🚀 Guía de Puesta en Marcha y Prueba

1. **Montaje:** Conecta los componentes físicos siguiendo la tabla de conexiones detallada arriba.
2. **Entorno:** Abre tu **Arduino IDE** y carga el código del proyecto (`.ino`).
3. **Placa y Puerto:** Selecciona la placa correcta (*Arduino UNO*) y el puerto COM correspondiente en el menú de herramientas.
4. **Carga:** Sube el programa a la placa.
5. **Visualización:** Comprueba que la pantalla LCD encienda y despliegue las métricas de temperatura y humedad.
6. **Prueba Rápida:** Para verificar la alarma sin necesidad de calentar todo el entorno a 40 °C, puedes cambiar temporalmente la condición en el código (`t >= 40`) por un valor menor. *No olvides restablecerlo a 40 después de validar*.

---

## 🔍 Solución de Problemas Frecuentes

* **La pantalla no muestra datos:** Revisa las líneas `SDA`, `SCL`, la alimentación de `5V`/`GND` y valida la dirección I2C del módulo.
* **Aparece "Error lectura":** Comprueba el cable de datos (`DATA`) del DHT11, su alimentación y asegúrate de haber seleccionado el tipo de sensor correcto en el código.
* **El LED no enciende:** Verifica su polaridad, la presencia de la resistencia y que esté conectado al pin `8`.
* **El buzzer no suena:** Confirma su polaridad y verifica si requiere una señal de frecuencia (por ejemplo, `tone(9, 1000)` si es un buzzer pasivo).
* **La alarma se repite infinitamente:** Comprueba la lógica del programa para asegurarte de que el indicador de estado se restablezca únicamente cuando la temperatura baje del umbral establecido.

---

## ✨ Resultado Esperado

El sistema opera de forma autónoma consultando y actualizando las métricas ambientales en la pantalla LCD. Al cruzar el umbral crítico de **40 °C**, despliega tres pulsos de alerta visuales y sonoros mediante el LED azul y el buzzer, bloqueando nuevas activaciones repetitivas hasta que las condiciones ambientales desciendan de forma segura.
