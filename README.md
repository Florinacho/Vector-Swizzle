# Vector
Classes for vector 2, 3 or 4 with swizzle support. https://en.wikipedia.org/wiki/Swizzling_(computer_graphics)  
The swizzle functionality does not increase the RAM usage and keeps the CPU impact at a minimum but can increase the compilling time.  

Example: 
```
vec4 v4(1.0f, 2.0f, 3.0f, 4.0f);
vec2 v2 = v4.yw;
vec4 v4b = v4.wzyx;
```
