# PAprefabs
This should ease generating prefabs with C++.
## Use Guide:
- ```#include "prefab.h"```
- There's no prefab class, it's just one per program.
- Set prefab's properties, assign them values in the main function with ```prefab::property = value;```
  - ```String name```: Name of the prefab. Output file will have this name too.
  -```int type```: You can find the types' names in the ```prefabTypes``` namespace.
  -```float offset```: Same value as in the editor
  - Ignore the other varibles in the namespace
- Creating objects:
  - The Object class constructor is as following:
  
  - To create an object:
  ```Object *obj = new Object(0.,15,shapes::sq,0,false,true,false);```
  - Some other properties:
  
  - Adding events: Use these four functions:
  
  - To call these functions:
  ```obj->pos(0.,0.,0.);```
- Now you can create lots of objects in interesting patterns using variables, loops, functions, etc.
- Call ```prefab::generate()``` before the end of ```main()``` and run.
