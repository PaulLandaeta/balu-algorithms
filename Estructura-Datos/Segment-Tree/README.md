# Segment Tree
### Que es un Segment Tree?
    Arbol de Segmentos(ST) es basicamente un arbol binario usado para hacer operaciones como suma, minimo, maximo dentro de intervalos o segmentos.
    Cada nodo en el ST representa un intervalo de L a R por lo tanto el primer nodo del arbol representara al array completo, de lo cual tendremos 3 propiedades basicas. 
     La Raiz de arbol representa todo el array A=[0,n]
     Cada hoja del arbol representa un elemento array A=[i] donde 0<i<n
     Una hoja interna del arbol representa A=[L,R]
    Tenemos que tener claro que una vez creado el Arbol esta estructura no puede ser mnodificado pero tu si puedes podificar los valores de una hoja.
### Implementacion
    Dado que un ST es un Arbol binario, para la representacion de dicho arbol podemos hacer el uso de un arbol. 
    Un ST puede ser construido de manera recursiva usando Bottom-up approach. 
    Las hojas representan un solo elemento del array, en cada paso el uso de los dos hijos daran el valor del padre, lo que quiere decir que el padre es la union de sus dos hijos.
    Por lo cual, la raiz del arbol representara el array completo.
    Operaciones Basicas. 
    Construccion.O(NlogN)
    Actulizacion. O(log(N+K))
    Consulta. O(log(N+K))
    Donde K = Number of retrieved intervals or segments


## Referencias
### WebSites
https://www.commonlounge.com/discussion/e825e3afdcbe4a979b0cc3b34285aa24
https://codeforces.com/blog/entry/18051
http://se7so.blogspot.com/2012/12/segment-trees-and-lazy-propagation.html
http://www.algorithmist.com/index.php/Segmented_Trees
http://letuskode.blogspot.com/2013/01/segtrees.html
http://theoryofprogramming.com/2015/01/27/segment-trees/
https://codeextractor.wordpress.com/2016/07/11/playing-with-ranges-segment-tree/
https://kartikkukreja.wordpress.com/2014/11/09/a-simple-approach-to-segment-trees/
https://codeforces.com/blog/entry/15890
### Videos
https://www.youtube.com/watch?v=Oq2E2yGadnU
