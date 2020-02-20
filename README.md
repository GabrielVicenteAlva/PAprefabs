# PAprefabs
This will ease generating Project Arrythmia prefabs with C++.
## Use Guide:
- ```#include "prefab.h"```
- There's no prefab class, it's just one per program.
- Set prefab's properties, assign them values in the main function with ```prefab::property = value;```
  - ```String name```: Name of the prefab. Output file will have this name too.
  - ```int type```: You can find the types' names in the ```prefabTypes``` namespace.
  - ```float offset```: Same value as in the editor
  - Ignore the other varibles in the namespace
- Creating objects:
  - The Object class constructor is as follows:
  ```
    Object(
      float st, // Starting time
      int depth, // Rendering depth
      const shapes::Shape *shape, // See shape list in shape namespace
      int bin = 0,
      bool helper = false,
      bool autoKill = true,
      bool empty = false
    )
  ```
  - To create an object:
  ```Object *obj = new Object(0.,15,shapes::sq,0,false,true,false);```
  - Other properties:
    - ```Object *parent```: Assign object's parent
    - ```void setCenter(float x,float y)```: Give ```x``` and  ```y``` the values 0, 0.5 or -0.5
    - ```void parentOffset(bool posBool,bool scaBool,bool rotBool,float posOffset = 0.,float scaOffset = 0.,float rotOffset = 0.)```
  - Adding events: Use these four functions:
  ```
  void posEvent(
    float t, // Time
    float x,
    float y,
    string easeType = easeTypes::line, // See types in easeTypes namespace
    int r = 0, // Randomizing type
    float rx = 0., // Random X
    float ry = 0., // Random Y
    float rz = 0. // Random interval
  )
  void scaEvent(float t,float x,float y,string easeType = easeTypes::line,int r = 0,float rx = 0.,float ry = 0.,float rz = 0.);
  void rotEvent(float t,float x,string easeType = easeTypes::line,int r = 0,float rx = 0.,float rz = 0.);
  void colEvent(float t,int x,string easeType = easeTypes::line,int r = 0,float rx = 0.,float rz = 0.);
  ```
  - To call these functions:
  ```obj->pos(0.,0.,0.);```
- Now you can create lots of objects in interesting patterns using variables, loops, functions, etc. See examples.
- Call ```prefab::generate()``` before the end of ```main()``` and run.
