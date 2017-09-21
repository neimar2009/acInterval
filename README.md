
**Library to control cycle of runtime methods.**

Description
------------
* Enables the execution of methods at predefined time intervals.
* Each instance created handles the execution of methods independently in time.
* Possibilita a execução de métodos em intervalos de tempo pré definidos.
* Cada instância criada manipula a execução de métodos independênte no tempo.


Help file
------------
```
  ...

  acIntervalClass processBlink1;
  acIntervalClass processBlink2;

  ...
```
 
 
```
  void setup {

  	processBlink1.begin(5000); // Interval of 5 seconds.
  	processBlink2.begin(1234); // Interval of 1234 milliseconds.

  ...
```


```
  void loop() {

  	if(processBlink1.dispatch()) {  // Returns 'true' if the range is complete.

  		blink1();
  	}

  	if(processBlink2.dispatch()) {  // Returns 'true' if the range is complete.

  		blink2();
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
