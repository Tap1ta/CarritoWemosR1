# Robot Móvil Autónomo con Control mediante Interfaz Web

Este proyecto presenta el diseño e implementación de un robot móvil autónomo controlado a través de una interfaz web utilizando un microcontrolador **Wemos D1 Mini**. El sistema permite la gestión independiente de dos motores DC para dirección y aceleración progresiva, junto con funcionalidades como un interruptor lógico y una eficiente reducción de voltaje de 9V a 3.7V.

## Características del Proyecto
- **Control remoto vía interfaz web responsiva**.
- **Reducción eficiente de voltaje** de 9V a 3.7V.
- **Gestión independiente** de dos motores DC.
- Simulación y pruebas funcionales exitosas en **Tinkercad**.

## Requisitos del Sistema
- **Hardware**:
  - Microcontrolador Wemos D1 Mini.
  - Motores DC (x2).
  - Reductor de voltaje.
  - Circuito con interruptor lógico.
- **Software**:
  - IDE de Arduino.
  - Navegador web para acceder a la interfaz de control.

## Instrucciones de Instalación

### 1. Configurar el Microcontrolador
1. Conecta el Wemos D1 Mini a tu computadora.
2. Abre el código del microcontrolador (`codigo_wemos.ino`) en el IDE de Arduino.
3. Cambia las credenciales de tu red Wi-Fi en las líneas correspondientes:
   ```cpp
   const char* ssid = "NOMBRE_DE_TU_WIFI";
   const char* password = "CONTRASEÑA_DE_TU_WIFI";
   ```
4. Sube el código al Wemos D1 Mini.

### 2. Configurar la Interfaz Web
1. Coloca el archivo `index.html` en tu servidor web local, o utilízalo directamente en combinación con el microcontrolador.
2. Asegúrate de que la dirección IP en el código HTML coincida con la dirección configurada en el microcontrolador:
   ```javascript
   const socket = new WebSocket("ws://192.168.1.100:81") // Modificar según tu red
   ```

### 3. Conectar el Hardware
1. Ensambla los motores y el reductor de voltaje al Wemos D1 Mini según el diagrama proporcionado en el proyecto.
2. Verifica que las conexiones sean correctas y asegúrate de que el sistema esté alimentado correctamente.

### 4. Configuración Final
1. Revisa las conexiones de los motores y asegúrate de que respondan correctamente a los comandos enviados desde la interfaz web.

## Uso del Sistema
1. Conecta tu dispositivo al mismo Wi-Fi que el Wemos D1 Mini.
2. Abre un navegador web e ingresa la dirección IP del Wemos D1 Mini.
3. Utiliza la interfaz web para controlar la dirección y velocidad del robot.

## Recomendaciones
Sigue la guia de desemblaje contenido en el informe para una correcta manipulación del carrito, luego optimiza el consumo de la bateria
ademas de ajustar la logica para obtener mejores resultados en la respuesta a las instrucciones enviadas desde el control hacia el carrito.


## Créditos
Desarrollado por: Jeremy Valera, Ever Quispe

Contacto: esqu3ma@gmail.com

## Licencia
Este proyecto está disponible bajo la licencia MIT.
