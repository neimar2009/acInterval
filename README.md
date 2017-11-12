
# Library to control cycle of runtime methods.

Description
------------
* Enables the execution of methods at predefined time intervals.
* Each instance created handles the execution of methods independently in time.
* Possibilita a execução de métodos em intervalos de tempo pré definidos.
* Cada instância criada manipula a execução de métodos independênte no tempo.


Help
------------

### acIntervalclass

  ```acIntervalclass example(timeInterval);

  timeInterval = Intervalo de tempo entre as execuções.    

### begin

  ```example.begin(timeInit);```    

  timeInit = Momento de início das execuções após o sistema ter inicial.

### dispatch

  Retorna verdade quando o intervalo de execução é alcançado.    
  Este é momento de executar um método ou grupo de métodos.

### stepHigh

  Retorna a indicação se é um processo par ou impar.    
  Isto serve para intercalar estados na aplicação.

### stepCount

  Retorna uma contagem de no máximo até a um valor pré especificado.

### stepCount

  ```stepCount(count);```    
  Configura um contador incrementado a cada processo. A contagem recomeça quando chega ao limite dado por ```count```.

### interval

  Retorna o intervalo de tempo entre processos.

### pause

  Pausa o processo, isto faz ```dispatch()``` retornar sempre ```false```

### restart

  Tira o processo do estado de pausa. A execução do processo será quando o intervalo se completar.

### reset

  ```example.reset();```    
  or    
  ```example.reset(timeInterval);```    

  Reinicia o processo a contar do momento da execução do ```reset()``` mantendo o mesmo intervalo pré definido.    
  timeInterval = Reinicia com um novo intervalo.

### priorProcess

  Retorna o momento da processo anterior.

### nextProcess

  Retorna o memento do próximo processo.



Help example
------------

```
  ...

  acIntervalClass processBlink1(500);  // Interval of 1/2 second.
  acIntervalClass processBlink2(1234); // Interval of 1234 milliseconds.

  ...
```
 
 
```
  void setup {

    processBlink1.begin(250);  // Initial time of 1/4 second.
    processBlink2.begin(1234); // Initial time of 1234 milliseconds.
    processBlink2.begin();     // Initial time now.

  ...
```


```
  void loop() {

    if(processBlink1.dispatch()){
      digitalWrite(pinBlink1, processBlink1.stepState());
    }

    if(processBlink2.dispatch()){
      digitalWrite(pinBlink2, processBlink2.stepHigh());
      if (processBlink2.stepHigh()) {
        processBlink2.reset(20);
      } else {
        processBlink2.reset(200);
      }
    }

    ...
```

  For lack of elaboration of a help file, please analyze the sample files.
  Adapt the same to the project need.


Help me
------------
  Due to the limited time available for development, I present this project in the
  way that you see it. Personally, I'm sorry, but so far I've been able to develop.
  
  My English is weak, to the extent possible, depending on available time, I will
  translate.
  
  Comments and suggestions will help in improving the project. Welcome.


Thanks
------------
  **I thank God.**
  
------------
