1. Create a new project in visual studio
2. Goto project properties-> VC++ Directories->Include Directories 
3. Add you opencv include path EX: C:\opencv\opencv\build\include
4. Goto project properties->Configuration Properties VC++ Directories->Include Directories 
   & add your opencv lib path EX:C:\opencv\opencv\build\x64\vc15\lib
5. Goto Linker-> Input -> Additional dependencies and add opencv_world440d.lib that found in opencv lib path

