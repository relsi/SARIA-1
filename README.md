# S.A.R.I.A

###Sistema de Automação Residencial com Inteligência Artificial

**S.A.R.I.A**  é  um  sistema  para  automação residencial  livre  que iniciou como uma experiência para construir uma interface web para controlar dispositivos e sensores através de um arduino.

O sistema está sendo reescrito com foco em IoT, fazendo as vezes de uma interface local para que o usuário possa acessar os dispositivos de sua residência.

Desenvolvido utilizando Python, com o framework de desenvolvimento web Web2py, torna possível ao usuário acessar e controlar a sua residência através da rede local utilizando um smartphone ou um navegador.



####Funcionalidades
- **Reconhecimento de voz** 
	- Julius: Engine Offline (não implementado)
	- Amazon Alexa: Engine Online (não implementado)

- **Reconhecimento de Texto** 
	- Rivescript

- **Sintetizador de Voz**
	- eSpeak: TTS offline
	- Amazon Ivona: TTS online (não implementado)

- **Integração Telegram**
	- Bot (não implementado)

- **Controle de Dispositivos** 
	- Arduino: pySerial
	- ESP8266: REST (não implementado)

####Dependências
- requests
- pyvona
- rivescript
- pyserial
- meSpeak.js
