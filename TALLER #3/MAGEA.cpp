

Taller3 explicacion · HTML
<!DOCTYPE html>
<html lang="es">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Taller 3 — Explicación paso a paso</title>
<link rel="preconnect" href="https://fonts.googleapis.com">
<link href="https://fonts.googleapis.com/css2?family=Space+Grotesk:wght@500;600;700&family=Source+Serif+4:ital,opsz,wght@0,8..60,400;0,8..60,600;1,8..60,400&family=IBM+Plex+Mono:wght@400;500;600&display=swap" rel="stylesheet">
<style>
  :root{
    --bg:#0F1417;
    --surface:#161D22;
    --surface-2:#1C242A;
    --border:#2A333A;
    --text:#EAF0F2;
    --text-dim:#93A3AB;
    --amber:#E8A33D;
    --teal:#5FC0AF;
    --rose:#E27A63;
  }
  *{box-sizing:border-box;}
  html{scroll-behavior:smooth;}
  body{
    margin:0;
    background:var(--bg);
    color:var(--text);
    font-family:"Source Serif 4", Georgia, serif;
    line-height:1.65;
    font-size:17px;
  }
  h1,h2,h3,.mono-label{
    font-family:"Space Grotesk", sans-serif;
  }
  code, pre, .ptr, .kbd{
    font-family:"IBM Plex Mono", monospace;
  }
 
  .wrap{max-width:760px; margin:0 auto; padding:0 24px 120px;}
  header.hero{
    max-width:100%;
    padding:72px 24px 56px;
    border-bottom:1px solid var(--border);
    background:
      radial-gradient(560px 220px at 12% -10%, rgba(95,192,175,0.14), transparent 65%),
      radial-gradient(480px 220px at 88% 0%, rgba(232,163,61,0.10), transparent 60%);
  }
  .hero-inner{max-width:760px; margin:0 auto;}
  .eyebrow{
    font-family:"IBM Plex Mono", monospace;
    font-size:13px;
    color:var(--teal);
    letter-spacing:.02em;
  }
  h1.title{
    font-size:clamp(30px,4.2vw,42px);
    font-weight:700;
    line-height:1.12;
    margin:14px 0 16px;
    letter-spacing:-0.01em;
  }
  .hero p{
    color:var(--text-dim);
    font-size:18px;
    max-width:58ch;
    margin:0;
  }
 
  nav.pills{
    display:flex; gap:10px; flex-wrap:wrap;
    margin-top:28px;
  }
  nav.pills a{
    font-family:"IBM Plex Mono", monospace;
    font-size:13px;
    color:var(--text);
    text-decoration:none;
    padding:7px 14px;
    border:1px solid var(--border);
    border-radius:999px;
    background:var(--surface);
    transition:border-color .15s ease, color .15s ease;
  }
  nav.pills a:hover{border-color:var(--teal); color:var(--teal);}
 
  section.exercise{padding-top:64px;}
  .ex-head{
    display:flex; align-items:baseline; gap:12px;
    margin-bottom:6px;
  }
  .ex-num{
    font-family:"IBM Plex Mono", monospace;
    color:var(--amber);
    font-size:15px;
  }
  h2.ex-title{
    font-size:28px;
    margin:0;
    font-weight:600;
  }
  .file-tag{
    font-family:"IBM Plex Mono", monospace;
    font-size:12.5px;
    color:var(--text-dim);
    margin:6px 0 0;
  }
 
  .brief{
    margin:28px 0 40px;
    padding:22px 24px;
    background:var(--surface);
    border:1px solid var(--border);
    border-left:3px solid var(--teal);
    border-radius:4px;
  }
  .brief h3{
    margin:0 0 10px;
    font-size:14px;
    color:var(--teal);
    text-transform:none;
    font-weight:600;
  }
  .brief p{margin:0 0 10px; color:var(--text-dim); font-size:15.5px;}
  .brief p:last-child{margin-bottom:0;}
  .brief ol.full-statement{
    margin:0 0 4px;
    padding-left:22px;
    color:var(--text-dim);
    font-size:15.5px;
  }
  .brief ol.full-statement li{margin-bottom:6px;}
  .brief ol.full-statement li:last-child{margin-bottom:0;}
  .brief .sub-label{
    font-family:"IBM Plex Mono", monospace;
    font-size:12px;
    color:var(--teal);
    letter-spacing:.03em;
    margin:16px 0 8px;
  }
  .restriction{
    margin-top:14px;
    padding-top:14px;
    border-top:1px dashed var(--border);
    font-size:14.5px;
    color:var(--rose);
  }
  .restriction .ptr{color:var(--rose); opacity:.9;}
 
  .step{margin:44px 0;}
  .step-head{
    display:flex; align-items:baseline; gap:10px;
    margin-bottom:10px;
  }
  .step-n{
    font-family:"IBM Plex Mono", monospace;
    font-size:13px;
    color:var(--text-dim);
    border:1px solid var(--border);
    border-radius:50%;
    width:26px; height:26px;
    display:flex; align-items:center; justify-content:center;
    flex-shrink:0;
  }
  h3.step-title{
    font-size:19px;
    margin:0;
    font-weight:600;
    font-family:"Space Grotesk", sans-serif;
  }
  .step p{margin:0 0 14px;}
  .callback{
    font-size:15px;
    color:var(--amber);
    background:rgba(232,163,61,0.08);
    border-left:2px solid var(--amber);
    padding:10px 14px;
    margin:14px 0;
    border-radius:2px;
  }
  .callback strong{font-family:"IBM Plex Mono", monospace; font-weight:600; font-size:13px; text-transform:uppercase; letter-spacing:.04em; display:block; margin-bottom:4px; opacity:.85;}
 
  blockquote.enunciado{
    margin:0 0 16px;
    padding:14px 18px;
    background:rgba(95,192,175,0.06);
    border-left:2px solid var(--teal);
    border-radius:2px;
    font-style:italic;
    font-size:15.5px;
    color:#C9D6D1;
  }
  blockquote.enunciado .src{
    display:block;
    margin-top:8px;
    font-family:"IBM Plex Mono", monospace;
    font-style:normal;
    font-size:12px;
    color:var(--teal);
    letter-spacing:.02em;
  }
 
  pre{
    background:var(--surface-2);
    border:1px solid var(--border);
    border-radius:6px;
    padding:16px 18px;
    overflow-x:auto;
    font-size:13.5px;
    line-height:1.6;
    margin:0;
  }
  code{font-size:inherit;}
  .cm{color:#6C7A82;}
  .kw{color:var(--teal);}
  .tp{color:var(--amber);}
  .st{color:#B7D0C4;}
  .fn{color:#9FC7E8;}
 
  .ptr-inline{
    color:var(--rose);
    background:rgba(226,122,99,0.10);
    padding:1px 5px;
    border-radius:3px;
    font-size:.92em;
  }
 
  .note{
    font-size:15px;
    color:#9FC7E8;
    background:rgba(159,199,232,0.07);
    border-left:2px solid #9FC7E8;
    padding:10px 14px;
    margin:14px 0;
    border-radius:2px;
  }
  .note strong{font-family:"IBM Plex Mono", monospace; font-weight:600; font-size:13px; text-transform:uppercase; letter-spacing:.04em; display:block; margin-bottom:4px; opacity:.85;}
 
  .glossary{
    margin-top:72px;
    padding:28px 24px;
    background:var(--surface);
    border:1px solid var(--border);
    border-radius:4px;
  }
  .glossary h2{
    font-size:20px;
    margin:0 0 18px;
    font-family:"Space Grotesk", sans-serif;
  }
  .glossary dl{margin:0;}
  .glossary .row{
    display:grid;
    grid-template-columns:180px 1fr;
    gap:18px;
    padding:12px 0;
    border-top:1px solid var(--border);
    align-items:baseline;
  }
  .glossary .row:first-of-type{border-top:none;}
  .glossary dt{
    font-family:"IBM Plex Mono", monospace;
    color:var(--teal);
    font-size:14px;
  }
  .glossary dd{margin:0; color:var(--text-dim); font-size:15px;}
 
  footer{
    max-width:760px; margin:64px auto 0; padding:0 24px;
    color:var(--text-dim); font-size:14px;
    font-family:"IBM Plex Mono", monospace;
  }
 
  @media (max-width:640px){
    .glossary .row{grid-template-columns:1fr; gap:4px;}
  }
</style>
</head>
<body>
 
<header class="hero">
  <div class="hero-inner">
    <div class="eyebrow">Programación Avanzada · Taller 3</div>
    <h1 class="title">Registro de ventas y sistema académico, explicados puntero por puntero</h1>
    <p>Los dos ejercicios comparten una misma idea de fondo: recorrer un arreglo de structs sin usar <code class="ptr-inline">[i]</code>, solo con <code class="ptr-inline">(ptr+i)</code> y <code class="ptr-inline">-&gt;</code>. Este documento va sobre el código realmente entregado (LAB_3-_01.cpp y LAB_3-_02.cpp), sección por sección, conectando cada bloque con el punto del enunciado que resuelve.</p>
    <nav class="pills">
      <a href="#ej1">Ejercicio 1 — Ventas</a>
      <a href="#ej2">Ejercicio 2 — Académico</a>
      <a href="#glosario">Glosario de punteros</a>
    </nav>
  </div>
</header>
 
<div class="wrap">
 
  <!-- ============ EJERCICIO 1 ============ -->
  <section class="exercise" id="ej1">
    <div class="ex-head">
      <span class="ex-num">01</span>
      <h2 class="ex-title">Registro de ventas con búsqueda y estadísticas</h2>
    </div>
    <p class="file-tag">Archivo: LAB_3-_01.cpp — Integrantes: María Fernanda Castañeda, Santiago Gaitán · Grupo 12</p>
 
    <div class="brief">
      <h3>Enunciado completo</h3>
      <p>Una empresa quiere registrar las ventas de sus empleados. Cada venta contiene: idEmpleado (entero), producto (cadena de caracteres), cantidad (entero), valorUnitario (float). Se debe almacenar la información de 10 ventas en un arreglo de estructuras. Esta información se solicita por consola.</p>
      <p>Con base en ese arreglo:</p>
      <ol class="full-statement">
        <li>Usando únicamente apuntadores y aritmética de apuntadores, mostrar todas las ventas en pantalla. (idEmpleado, producto, cantidad, valorUnitario)</li>
        <li>Calcular e imprimir el total vendido por cada empleado, recorriendo el arreglo con un apuntador.</li>
        <li>Determinar e imprimir el empleado que más vendió (en dinero).</li>
        <li>Permitir al usuario ingresar un idEmpleado y, usando un recorrido con apuntador, mostrar todas sus ventas.</li>
        <li>Armar un menú para mostrar cada uno de los cálculos.</li>
      </ol>
      <div class="restriction">Restricción dura: "No usar índices de arreglo (ventas[i]). Todo el recorrido y acceso debe hacerse con (ptr+i) y -&gt; ó *(ptri+i)."</div>
      <div class="restriction" style="color:var(--text-dim); border-top:none; margin-top:6px; padding-top:0;">Rúbrica: Crear estructura 10% · Llenar con apuntadores 20% · Mostrar ventas 20% · Empleado que más vendió 20% · Consultar por empleado 20% · Menú 10%.</div>
    </div>
 
    <!-- Paso 1 -->
    <div class="step">
      <div class="step-head">
        <span class="step-n">1</span>
        <h3 class="step-title">La estructura <code class="ptr-inline">Venta</code></h3>
      </div>
      <blockquote class="enunciado">
        "Cada venta contiene: idEmpleado (entero), producto (cadena de caracteres), cantidad (entero), valorUnitario (float). Se debe almacenar la información de 10 ventas en un arreglo de estructuras."
        <span class="src">— Planteamiento, Ejercicio 1</span>
      </blockquote>
      <pre><code><span class="cm">#include</span> &lt;iostream&gt;
<span class="cm">#include</span> &lt;string&gt;
<span class="kw">using namespace</span> std;
 
<span class="kw">struct</span> Venta {
    <span class="tp">int</span> idEmpleado;
    <span class="tp">string</span> producto;
    <span class="tp">int</span> cantidad;
    <span class="tp">float</span> valorUnitario;
};</code></pre>
      <p>Acá se resolvió "cadena de caracteres" con <code class="ptr-inline">string</code> en vez de <code class="ptr-inline">char[]</code>. Es una decisión válida: la restricción del taller prohíbe indexar el <em>arreglo de ventas</em> con <code class="ptr-inline">[i]</code>, no prohíbe qué tipo de dato uses adentro de cada campo. <code class="ptr-inline">(ptr+i)-&gt;producto</code> funciona exactamente igual sea <code class="ptr-inline">string</code> o <code class="ptr-inline">char[50]</code>, porque el puntero se mueve sobre el <em>struct completo</em>, no sobre el campo.</p>
    </div>
 
    <!-- Paso 2 -->
    <div class="step">
      <div class="step-head">
        <span class="step-n">2</span>
        <h3 class="step-title">Un solo puntero, declarado una sola vez</h3>
      </div>
      <blockquote class="enunciado">
        "Se debe almacenar la información de 10 ventas en un arreglo de estructuras. Esta información se solicita por consola." · Restricción: "Todo el recorrido y acceso debe hacerse con (ptr+i) y -&gt; ó *(ptri+i)."
        <span class="src">— Planteamiento y Restricciones, Ejercicio 1</span>
      </blockquote>
      <pre><code><span class="kw">const</span> <span class="tp">int</span> NUM_VENTAS = <span class="st">10</span>;
Venta ventas[NUM_VENTAS];
Venta* ptr = ventas;
 
cout &lt;&lt; <span class="st">"--- INGRESO DE VENTAS ---"</span> &lt;&lt; endl;
<span class="kw">for</span> (<span class="tp">int</span> i = <span class="st">0</span>; i &lt; NUM_VENTAS; ++i) {
    cout &lt;&lt; <span class="st">"\nVenta #"</span> &lt;&lt; (i + <span class="st">1</span>) &lt;&lt; <span class="st">":"</span> &lt;&lt; endl;
    cout &lt;&lt; <span class="st">"ID de Empleado: "</span>;
    cin &gt;&gt; (ptr + i)-&gt;idEmpleado;
 
    cout &lt;&lt; <span class="st">"Producto: "</span>;
    cin.ignore();
    getline(cin, (ptr + i)-&gt;producto);
 
    cout &lt;&lt; <span class="st">"Cantidad: "</span>;
    cin &gt;&gt; (ptr + i)-&gt;cantidad;
 
    cout &lt;&lt; <span class="st">"Valor Unitario: "</span>;
    cin &gt;&gt; (ptr + i)-&gt;valorUnitario;
}</code></pre>
      <p><code class="ptr-inline">Venta* ptr = ventas;</code> se declara una única vez, arriba de todo <code class="ptr-inline">main()</code>. Como <code class="ptr-inline">ptr</code> nunca se reasigna a otra dirección, ese mismo puntero sigue siendo válido más abajo, dentro de cada <code class="ptr-inline">case</code> del menú — no hace falta volver a apuntarlo ni pasarlo como parámetro a ninguna parte, porque todo vive en el mismo <code class="ptr-inline">main</code>.</p>
      <div class="note"><strong>Un detalle para revisar</strong><code class="ptr-inline">cin.ignore()</code> sin argumentos solo descarta <em>un</em> carácter del buffer (el <code class="ptr-inline">\n</code> que dejó el <code class="ptr-inline">cin &gt;&gt; idEmpleado</code> anterior). Funciona aquí porque justo hay un solo carácter pendiente, pero es menos robusto que la versión que se usó en el Ejercicio 2: <code class="ptr-inline">cin.ignore(numeric_limits&lt;streamsize&gt;::max(), '\n')</code>, que limpia toda la línea sobrante sin importar cuántos caracteres queden. Vale la pena unificar el criterio entre los dos archivos.</div>
    </div>
 
    <!-- Paso 3 -->
    <div class="step">
      <div class="step-head">
        <span class="step-n">3</span>
        <h3 class="step-title">El menú y por qué cada <code class="ptr-inline">case</code> lleva llaves</h3>
      </div>
      <blockquote class="enunciado">
        "Armar un menú para mostrar cada uno de los cálculos."
        <span class="src">— Punto 5, Ejercicio 1 · vale 10%</span>
      </blockquote>
      <pre><code><span class="tp">int</span> opcion;
<span class="kw">do</span> {
    cout &lt;&lt; <span class="st">"\n========= MENU ========="</span> &lt;&lt; endl;
    cout &lt;&lt; <span class="st">"1. Mostrar todas las ventas"</span> &lt;&lt; endl;
    cout &lt;&lt; <span class="st">"2. Total vendido por cada empleado"</span> &lt;&lt; endl;
    cout &lt;&lt; <span class="st">"3. Empleado que mas vendio"</span> &lt;&lt; endl;
    cout &lt;&lt; <span class="st">"4. Buscar ventas por ID de empleado"</span> &lt;&lt; endl;
    cout &lt;&lt; <span class="st">"5. Salir"</span> &lt;&lt; endl;
    cin &gt;&gt; opcion;
 
    <span class="kw">switch</span> (opcion) {
        <span class="kw">case</span> <span class="st">1</span>: { <span class="cm">/* ... */</span> <span class="kw">break</span>; }
        <span class="kw">case</span> <span class="st">2</span>: { <span class="cm">/* ... */</span> <span class="kw">break</span>; }
        <span class="kw">case</span> <span class="st">3</span>: { <span class="cm">/* ... */</span> <span class="kw">break</span>; }
        <span class="kw">case</span> <span class="st">4</span>: { <span class="cm">/* ... */</span> <span class="kw">break</span>; }
        <span class="kw">case</span> <span class="st">5</span>:
            cout &lt;&lt; <span class="st">"Saliendo del programa..."</span> &lt;&lt; endl;
            <span class="kw">break</span>;
        <span class="kw">default</span>:
            cout &lt;&lt; <span class="st">"Opcion no valida. Intente de nuevo."</span> &lt;&lt; endl;
    }
} <span class="kw">while</span> (opcion != <span class="st">5</span>);</code></pre>
      <p>Cada <code class="ptr-inline">case</code> abre con <code class="ptr-inline">{ }</code> propias. No es decoración: dentro de los casos 2 y 3 se declaran arreglos nuevos (<code class="ptr-inline">ids</code>, <code class="ptr-inline">totales</code>). Sin esas llaves, C++ no deja saltar de un <code class="ptr-inline">case</code> a otro por encima de una variable recién declarada — es el error clásico "jump bypasses variable initialization". Las llaves crean un bloque con vida propia para cada opción del menú.</p>
    </div>
 
    <!-- Paso 4 -->
    <div class="step">
      <div class="step-head">
        <span class="step-n">4</span>
        <h3 class="step-title">Caso 1 — Mostrar todas las ventas</h3>
      </div>
      <blockquote class="enunciado">
        "Usando únicamente apuntadores y aritmética de apuntadores, mostrar todas las ventas en pantalla. (idEmpleado, producto, cantidad, valorUnitario)"
        <span class="src">— Punto 1, Ejercicio 1 · vale 20%</span>
      </blockquote>
      <pre><code><span class="kw">case</span> <span class="st">1</span>: {
    cout &lt;&lt; <span class="st">"--- TODAS LAS VENTAS ---"</span> &lt;&lt; endl;
    <span class="kw">for</span> (<span class="tp">int</span> i = <span class="st">0</span>; i &lt; NUM_VENTAS; ++i) {
        cout &lt;&lt; <span class="st">"Venta "</span> &lt;&lt; (i + <span class="st">1</span>)
             &lt;&lt; <span class="st">" | ID: "</span> &lt;&lt; (ptr + i)-&gt;idEmpleado
             &lt;&lt; <span class="st">" | Producto: "</span> &lt;&lt; (ptr + i)-&gt;producto
             &lt;&lt; <span class="st">" | Cantidad: "</span> &lt;&lt; (ptr + i)-&gt;cantidad
             &lt;&lt; <span class="st">" | V. Unitario: $"</span> &lt;&lt; (ptr + i)-&gt;valorUnitario &lt;&lt; endl;
    }
    <span class="kw">break</span>;
}</code></pre>
      <p>El recorrido más directo del taller: un solo <code class="ptr-inline">for</code>, un solo puntero, los cuatro campos pedidos por el enunciado en el mismo orden en que los enumera.</p>
    </div>
 
    <!-- Paso 5 -->
    <div class="step">
      <div class="step-head">
        <span class="step-n">5</span>
        <h3 class="step-title">Caso 2 — Total vendido por empleado</h3>
      </div>
      <blockquote class="enunciado">
        "Calcular e imprimir el total vendido por cada empleado, recorriendo el arreglo con un apuntador."
        <span class="src">— Punto 2, Ejercicio 1 · vale 20%</span>
      </blockquote>
      <pre><code><span class="kw">case</span> <span class="st">2</span>: {
    <span class="tp">int</span> ids[NUM_VENTAS];
    <span class="tp">float</span> totales[NUM_VENTAS] = {<span class="st">0</span>};
    <span class="tp">int</span>* ptrIds = ids;
    <span class="tp">float</span>* ptrTotales = totales;
    <span class="tp">int</span> empleadosUnicos = <span class="st">0</span>;
 
    <span class="kw">for</span> (<span class="tp">int</span> i = <span class="st">0</span>; i &lt; NUM_VENTAS; ++i) {
        <span class="tp">int</span> idActual = (ptr + i)-&gt;idEmpleado;
        <span class="tp">float</span> montoVenta = ((ptr + i)-&gt;cantidad) * ((ptr + i)-&gt;valorUnitario);
        <span class="tp">bool</span> registrado = <span class="kw">false</span>;
 
        <span class="kw">for</span> (<span class="tp">int</span> j = <span class="st">0</span>; j &lt; empleadosUnicos; ++j) {
            <span class="kw">if</span> (*(ptrIds + j) == idActual) {
                *(ptrTotales + j) += montoVenta;
                registrado = <span class="kw">true</span>;
                <span class="kw">break</span>;
            }
        }
        <span class="kw">if</span> (!registrado) {
            *(ptrIds + empleadosUnicos) = idActual;
            *(ptrTotales + empleadosUnicos) = montoVenta;
            empleadosUnicos++;
        }
    }
 
    <span class="kw">for</span> (<span class="tp">int</span> j = <span class="st">0</span>; j &lt; empleadosUnicos; ++j) {
        cout &lt;&lt; <span class="st">"Empleado ID: "</span> &lt;&lt; *(ptrIds + j)
             &lt;&lt; <span class="st">" | Total Vendido: $"</span> &lt;&lt; *(ptrTotales + j) &lt;&lt; endl;
    }
    <span class="kw">break</span>;
}</code></pre>
      <p>Este es el bloque más elaborado del ejercicio, porque el enunciado no dice explícitamente qué hacer cuando un mismo empleado aparece en varias de las 10 ventas. La solución acá es un patrón de "acumulador con arreglos paralelos":</p>
      <p><code class="ptr-inline">ids[]</code> y <code class="ptr-inline">totales[]</code> son dos arreglos auxiliares del mismo tamaño, cada uno con su propio puntero (<code class="ptr-inline">ptrIds</code>, <code class="ptr-inline">ptrTotales</code>). <code class="ptr-inline">empleadosUnicos</code> funciona como un contador que también hace de "tamaño real" de esos dos arreglos — arrancan vacíos y van creciendo.</p>
      <p>Por cada venta: se calcula su monto (<code class="ptr-inline">cantidad * valorUnitario</code>), se busca ese <code class="ptr-inline">idEmpleado</code> entre los ya vistos (<code class="ptr-inline">*(ptrIds+j) == idActual</code>); si aparece, se le suma el monto a su posición correspondiente en <code class="ptr-inline">totales</code>; si no aparece, se agrega como una entrada nueva al final y crece <code class="ptr-inline">empleadosUnicos</code>. Es exactamente lo que pide el punto 2: un solo recorrido del arreglo original, con punteros, sin repetir empleados en la salida.</p>
      <div class="note"><strong>Ojo con el nombre de la variable</strong> <code class="ptr-inline">ids</code> y <code class="ptr-inline">totales</code> se declaran como arreglos normales, pero nunca se acceden con <code class="ptr-inline">ids[j]</code> — siempre es <code class="ptr-inline">*(ptrIds + j)</code>. Así que aunque parezcan "arreglos con índice", el acceso real sigue respetando la restricción del taller.</div>
    </div>
 
    <!-- Paso 6 -->
    <div class="step">
      <div class="step-head">
        <span class="step-n">6</span>
        <h3 class="step-title">Caso 3 — Empleado que más vendió</h3>
      </div>
      <blockquote class="enunciado">
        "Determinar e imprimir el empleado que más vendió (en dinero)."
        <span class="src">— Punto 3, Ejercicio 1 · vale 20%</span>
      </blockquote>
      <pre><code><span class="kw">case</span> <span class="st">3</span>: {
    <span class="cm">// (se repite el mismo bloque del caso 2: ids[], totales[], ptrIds, ptrTotales)</span>
    ...
 
    <span class="tp">float</span> maxVendido = -<span class="st">1.0</span>;
    <span class="tp">int</span> idMax = -<span class="st">1</span>;
 
    <span class="kw">for</span> (<span class="tp">int</span> j = <span class="st">0</span>; j &lt; empleadosUnicos; ++j) {
        <span class="kw">if</span> (*(ptrTotales + j) &gt; maxVendido) {
            maxVendido = *(ptrTotales + j);
            idMax = *(ptrIds + j);
        }
    }
 
    <span class="kw">if</span> (idMax != -<span class="st">1</span>) {
        cout &lt;&lt; <span class="st">"--- MEJOR EMPLEADO ---"</span> &lt;&lt; endl;
        cout &lt;&lt; <span class="st">"El empleado que mas vendio es el ID: "</span> &lt;&lt; idMax
             &lt;&lt; <span class="st">" con un total de $"</span> &lt;&lt; maxVendido &lt;&lt; endl;
    }
    <span class="kw">break</span>;
}</code></pre>
      <p>La parte nueva es corta: recorrer <code class="ptr-inline">totales[]</code> (vía <code class="ptr-inline">ptrTotales</code>) buscando el valor más alto, guardando en paralelo el <code class="ptr-inline">idMax</code> correspondiente desde <code class="ptr-inline">ptrIds</code>. <code class="ptr-inline">maxVendido</code> arranca en <code class="ptr-inline">-1.0</code> para que la primera comparación siempre gane y quede un candidato inicial.</p>
      <div class="callback"><strong>Volviendo al enunciado</strong>El bloque de "construir ids/totales" del inicio de este caso es idéntico, carácter por carácter, al del caso 2. El enunciado no lo prohíbe, pero es candidato natural a convertirse en una función <code class="ptr-inline">calcularTotales(ventas, ids, totales)</code> compartida entre los dos casos — no cambia la nota, pero evita mantener la misma lógica en dos lugares.</div>
    </div>
 
    <!-- Paso 7 -->
    <div class="step">
      <div class="step-head">
        <span class="step-n">7</span>
        <h3 class="step-title">Caso 4 — Consultar ventas de un empleado</h3>
      </div>
      <blockquote class="enunciado">
        "Permitir al usuario ingresar un idEmpleado y, usando un recorrido con apuntador, mostrar todas sus ventas."
        <span class="src">— Punto 4, Ejercicio 1 · vale 20%</span>
      </blockquote>
      <pre><code><span class="kw">case</span> <span class="st">4</span>: {
    <span class="tp">int</span> idBuscado;
    cout &lt;&lt; <span class="st">"Ingrese el ID del empleado a buscar: "</span>;
    cin &gt;&gt; idBuscado;
 
    cout &lt;&lt; <span class="st">"--- VENTAS DEL EMPLEADO "</span> &lt;&lt; idBuscado &lt;&lt; <span class="st">" ---"</span> &lt;&lt; endl;
    <span class="tp">bool</span> tieneVentas = <span class="kw">false</span>;
 
    <span class="kw">for</span> (<span class="tp">int</span> i = <span class="st">0</span>; i &lt; NUM_VENTAS; ++i) {
        <span class="kw">if</span> ((ptr + i)-&gt;idEmpleado == idBuscado) {
            cout &lt;&lt; <span class="st">"Producto: "</span> &lt;&lt; (ptr + i)-&gt;producto
                 &lt;&lt; <span class="st">" | Cantidad: "</span> &lt;&lt; (ptr + i)-&gt;cantidad
                 &lt;&lt; <span class="st">" | V. Unitario: $"</span> &lt;&lt; (ptr + i)-&gt;valorUnitario
                 &lt;&lt; <span class="st">" | Subtotal: $"</span> &lt;&lt; ((ptr + i)-&gt;cantidad * (ptr + i)-&gt;valorUnitario) &lt;&lt; endl;
            tieneVentas = <span class="kw">true</span>;
        }
    }
    <span class="kw">if</span> (!tieneVentas) {
        cout &lt;&lt; <span class="st">"No se encontraron ventas registradas para este empleado."</span> &lt;&lt; endl;
    }
    <span class="kw">break</span>;
}</code></pre>
      <p>El recorrido más simple de los cuatro casos: no necesita arreglos auxiliares porque el objetivo es listar <em>todas</em> las apariciones del id, no resumirlas. El extra que no pide el enunciado pero suma: el <code class="ptr-inline">Subtotal</code> por venta, calculado al vuelo con <code class="ptr-inline">(ptr+i)-&gt;cantidad * (ptr+i)-&gt;valorUnitario</code> — mismo cálculo que ya se usó en el caso 2, sin necesidad de guardarlo en el struct.</p>
    </div>
  </section>
 
  <!-- ============ EJERCICIO 2 ============ -->
  <section class="exercise" id="ej2">
    <div class="ex-head">
      <span class="ex-num">02</span>
      <h2 class="ex-title">Sistema académico</h2>
    </div>
    <p class="file-tag">Archivo: LAB_3-_02.cpp — Integrantes: María Fernanda Castañeda, Santiago Gaitán · Grupo 12</p>
 
    <div class="brief">
      <h3>Enunciado completo</h3>
      <p>Una universidad desea manejar un registro de estudiantes. Cada estudiante tiene:</p>
      <div class="sub-label">Materias</div>
      <ol class="full-statement">
        <li>Materia (Arreglo de caracteres)</li>
        <li>Nota (float)</li>
      </ol>
      <div class="sub-label">Estudiante</div>
      <ol class="full-statement">
        <li>id (entero)</li>
        <li>nombre (cadena de caracteres)</li>
        <li>materias[3] (arreglo de 3 Materias con las calificaciones de sus materias)</li>
      </ol>
      <p style="margin-top:16px;">Se pide:</p>
      <ol class="full-statement">
        <li>Ingresar la información de 5 estudiantes en un arreglo de estructuras.</li>
        <li>Usando apuntadores a estructuras y apuntadores dentro de cada arreglo de Materias, calcular: el promedio individual de cada estudiante y el promedio general del curso.</li>
        <li>Determinar cuál estudiante tiene el mayor promedio.</li>
        <li>Mostrar, usando solo aritmética de apuntadores, las notas del estudiante con el mayor promedio.</li>
      </ol>
      <p style="margin-top:10px;">No tienen que armar un menú: una vez finalicen de solicitar la información de los estudiantes, mostrar un título indicando el proceso o cálculo y mostrar la información respectiva.</p>
      <div class="restriction">Restricción dura: "No usar índices de arreglo (Estudiantes y Notas[i]). Todo el recorrido y acceso debe hacerse con (ptr+i) y -&gt; ó *(ptri+i)."</div>
      <div class="restriction" style="color:var(--text-dim); border-top:none; margin-top:6px; padding-top:0;">Rúbrica: Crear estructura 12% · Llenar con apuntadores 22% · Promedio individual 22% · Promedio general 22% · Estudiante de mayor promedio 22%. Sin menú.</div>
    </div>
 
    <!-- Paso 1 -->
    <div class="step">
      <div class="step-head">
        <span class="step-n">1</span>
        <h3 class="step-title">Dos structs anidados</h3>
      </div>
      <blockquote class="enunciado">
        "Cada estudiante tiene: Materias — Materia (Arreglo de caracteres), Nota (float). Estudiante — id (entero), nombre (cadena de caracteres), materias[3] (arreglo de 3 Materias con las calificaciones de sus materias)."
        <span class="src">— Planteamiento, Ejercicio 2</span>
      </blockquote>
      <pre><code><span class="kw">struct</span> Materia {
    <span class="tp">char</span> nombreMateria[<span class="st">50</span>];
    <span class="tp">float</span> nota;
};
 
<span class="kw">struct</span> Estudiante {
    <span class="tp">int</span> id;
    <span class="tp">char</span> nombre[<span class="st">50</span>];
    Materia materias[<span class="st">3</span>];
};</code></pre>
      <p>Traslado casi literal del enunciado: <code class="ptr-inline">Materia</code> guarda su nombre y su nota, <code class="ptr-inline">Estudiante</code> guarda sus datos y un arreglo fijo de 3 <code class="ptr-inline">Materia</code>. Acá sí se usó <code class="ptr-inline">char[50]</code> en vez de <code class="ptr-inline">string</code> — cualquiera de las dos opciones es válida, como se vio en el Ejercicio 1.</p>
    </div>
 
    <!-- Paso 2 -->
    <div class="step">
      <div class="step-head">
        <span class="step-n">2</span>
        <h3 class="step-title">Llenar: puntero de afuera, puntero de adentro</h3>
      </div>
      <blockquote class="enunciado">
        "Ingresar la información de 5 estudiantes en un arreglo de estructuras." · Restricción: "No usar índices de arreglo (Estudiantes y Notas[i]). Todo el recorrido y acceso debe hacerse con (ptr+i) y -&gt; ó *(ptri+i)."
        <span class="src">— Punto 1 y Restricciones, Ejercicio 2 · vale 22%</span>
      </blockquote>
      <pre><code>Estudiante estudiantes[NUM_ESTUDIANTES];
Estudiante* ptrEst = estudiantes;
 
<span class="kw">for</span> (<span class="tp">int</span> i = <span class="st">0</span>; i &lt; NUM_ESTUDIANTES; ++i) {
    cout &lt;&lt; <span class="st">"ID: "</span>;
    cin &gt;&gt; (ptrEst + i)-&gt;id;
 
    cout &lt;&lt; <span class="st">"Nombre: "</span>;
    cin.ignore(numeric_limits&lt;streamsize&gt;::max(), <span class="st">'\n'</span>);
    cin.getline((ptrEst + i)-&gt;nombre, <span class="st">50</span>);
 
    Materia* ptrMat = (ptrEst + i)-&gt;materias;
 
    <span class="kw">for</span> (<span class="tp">int</span> j = <span class="st">0</span>; j &lt; NUM_MATERIAS; ++j) {
        cout &lt;&lt; <span class="st">"  Nombre de la Materia "</span> &lt;&lt; (j + <span class="st">1</span>) &lt;&lt; <span class="st">": "</span>;
        cin.getline((ptrMat + j)-&gt;nombreMateria, <span class="st">50</span>);
 
        cout &lt;&lt; <span class="st">"  Nota de "</span> &lt;&lt; (ptrMat + j)-&gt;nombreMateria &lt;&lt; <span class="st">": "</span>;
        cin &gt;&gt; (ptrMat + j)-&gt;nota;
        cin.ignore(numeric_limits&lt;streamsize&gt;::max(), <span class="st">'\n'</span>);
    }
}</code></pre>
      <p>Dos niveles de recorrido, dos punteros. <code class="ptr-inline">ptrEst</code> se mueve entre los 5 estudiantes; dentro de cada vuelta, <code class="ptr-inline">ptrMat = (ptrEst+i)-&gt;materias</code> apunta al primer elemento del arreglo de materias <em>de ese estudiante en particular</em>. Es justo lo que pide el enunciado: "apuntadores a estructuras <em>y</em> apuntadores dentro de cada arreglo de Materias".</p>
      <div class="note"><strong>Mejor manejo del buffer que en el Ejercicio 1</strong><code class="ptr-inline">cin.ignore(numeric_limits&lt;streamsize&gt;::max(), '\n')</code> descarta <em>toda</em> la línea sobrante, sin importar cuántos caracteres queden — no depende de que solo haya un <code class="ptr-inline">\n</code> pendiente. Es la versión robusta del <code class="ptr-inline">cin.ignore()</code> simple que se usó en LAB_3-_01.cpp.</div>
    </div>
 
    <!-- Paso 3 -->
    <div class="step">
      <div class="step-head">
        <span class="step-n">3</span>
        <h3 class="step-title">Un solo recorrido para promedio individual + acumulado general + el mejor</h3>
      </div>
      <blockquote class="enunciado">
        "Usando apuntadores a estructuras y apuntadores dentro de cada arreglo de Materias, calcular: El promedio individual de cada estudiante. El promedio general del curso." · "Determinar cuál estudiante tiene el mayor promedio."
        <span class="src">— Puntos 2 y 3, Ejercicio 2 · 22% + 22%</span>
      </blockquote>
      <pre><code><span class="tp">float</span> sumaGeneralCurso = <span class="st">0.0</span>;
<span class="tp">float</span> maxPromedio = -<span class="st">1.0</span>;
Estudiante* ptrMejorEst = <span class="kw">nullptr</span>;
 
<span class="kw">for</span> (<span class="tp">int</span> i = <span class="st">0</span>; i &lt; NUM_ESTUDIANTES; ++i) {
    <span class="tp">float</span> sumaNotas = <span class="st">0.0</span>;
    Materia* ptrMat = (ptrEst + i)-&gt;materias;
 
    <span class="kw">for</span> (<span class="tp">int</span> j = <span class="st">0</span>; j &lt; NUM_MATERIAS; ++j) {
        sumaNotas += (ptrMat + j)-&gt;nota;
    }
 
    <span class="tp">float</span> promedioEstudiante = sumaNotas / NUM_MATERIAS;
    sumaGeneralCurso += promedioEstudiante;
 
    cout &lt;&lt; <span class="st">"   - "</span> &lt;&lt; (ptrEst + i)-&gt;nombre &lt;&lt; <span class="st">" (ID: "</span> &lt;&lt; (ptrEst + i)-&gt;id
         &lt;&lt; <span class="st">") | Promedio: "</span> &lt;&lt; promedioEstudiante &lt;&lt; endl;
 
    <span class="kw">if</span> (promedioEstudiante &gt; maxPromedio) {
        maxPromedio = promedioEstudiante;
        ptrMejorEst = (ptrEst + i);
    }
}</code></pre>
      <p>Este bloque hace tres cosas en una sola pasada por los 5 estudiantes, en vez de recorrerlos tres veces por separado:</p>
      <p><strong style="font-family:'IBM Plex Mono',monospace; font-size:14px; font-weight:600; color:var(--teal);">1.</strong> Calcula <code class="ptr-inline">promedioEstudiante</code> recorriendo sus 3 materias con <code class="ptr-inline">ptrMat</code> — resuelve el punto 2, primera parte.</p>
      <p><strong style="font-family:'IBM Plex Mono',monospace; font-size:14px; font-weight:600; color:var(--teal);">2.</strong> Va sumando cada promedio individual en <code class="ptr-inline">sumaGeneralCurso</code>, dejando lista la base para el promedio general — punto 2, segunda parte.</p>
      <p><strong style="font-family:'IBM Plex Mono',monospace; font-size:14px; font-weight:600; color:var(--teal);">3.</strong> Compara contra <code class="ptr-inline">maxPromedio</code> y, si el estudiante actual es mejor, guarda <code class="ptr-inline">ptrMejorEst = (ptrEst + i)</code> — resuelve el punto 3, sin necesitar una segunda vuelta al arreglo.</p>
      <div class="callback"><strong>Volviendo al enunciado</strong><code class="ptr-inline">ptrMejorEst</code> es un <code class="ptr-inline">Estudiante*</code>, no un id ni una posición entera. Arranca en <code class="ptr-inline">nullptr</code> y termina apuntando directo al struct ganador, listo para usarse en el paso 5 sin volver a buscarlo.</div>
    </div>
 
    <!-- Paso 4 -->
    <div class="step">
      <div class="step-head">
        <span class="step-n">4</span>
        <h3 class="step-title">Promedio general del curso</h3>
      </div>
      <blockquote class="enunciado">
        "El promedio general del curso."
        <span class="src">— Punto 2 (segunda parte), Ejercicio 2 · vale 22%</span>
      </blockquote>
      <pre><code><span class="tp">float</span> promedioGeneral = sumaGeneralCurso / NUM_ESTUDIANTES;
cout &lt;&lt; <span class="st">"\n2. PROMEDIO GENERAL DEL CURSO:"</span> &lt;&lt; endl;
cout &lt;&lt; <span class="st">"   - El promedio de todos los "</span> &lt;&lt; NUM_ESTUDIANTES
     &lt;&lt; <span class="st">" estudiantes es: "</span> &lt;&lt; promedioGeneral &lt;&lt; endl;</code></pre>
      <p>Ya no hace falta ningún puntero acá: <code class="ptr-inline">sumaGeneralCurso</code> se armó en el paso anterior sumando los 5 promedios individuales, así que el promedio general es una sola división. Es promedio-de-promedios (cada estudiante pesa igual), no el promedio de las 15 notas sueltas.</p>
    </div>
 
    <!-- Paso 5 -->
    <div class="step">
      <div class="step-head">
        <span class="step-n">5</span>
        <h3 class="step-title">Notas del mejor estudiante, solo con aritmética de punteros</h3>
      </div>
      <blockquote class="enunciado">
        "Mostrar, usando solo aritmética de apuntadores, las notas del estudiante con el mayor promedio." Y sobre el formato de salida: "No tienen que armar un menú, una vez finalicen de solicitar la información de los estudiantes, mostrar un título indicando el proceso o cálculo y mostrar la información respectiva."
        <span class="src">— Punto 4 y nota final, Ejercicio 2 · vale 22%</span>
      </blockquote>
      <pre><code><span class="kw">if</span> (ptrMejorEst != <span class="kw">nullptr</span>) {
    cout &lt;&lt; <span class="st">"   - Nombre: "</span> &lt;&lt; ptrMejorEst-&gt;nombre &lt;&lt; endl;
    cout &lt;&lt; <span class="st">"   - Promedio: "</span> &lt;&lt; maxPromedio &lt;&lt; endl;
    cout &lt;&lt; <span class="st">"   - Notas desglosadas:"</span> &lt;&lt; endl;
 
    <span class="cm">// Apuntador para recorrer las materias del MEJOR estudiante</span>
    Materia* ptrMatMejor = ptrMejorEst-&gt;materias;
    <span class="kw">for</span> (<span class="tp">int</span> j = <span class="st">0</span>; j &lt; NUM_MATERIAS; ++j) {
        cout &lt;&lt; <span class="st">"       * "</span> &lt;&lt; (ptrMatMejor + j)-&gt;nombreMateria
             &lt;&lt; <span class="st">": "</span> &lt;&lt; (ptrMatMejor + j)-&gt;nota &lt;&lt; endl;
    }
}</code></pre>
      <p>Como <code class="ptr-inline">ptrMejorEst</code> ya venía apuntando al ganador desde el paso 3, acá no se vuelve a recorrer el arreglo de 5 estudiantes — solo se entra a sus 3 materias con un tercer puntero, <code class="ptr-inline">ptrMatMejor</code>, mismo patrón que <code class="ptr-inline">ptrMat</code> en el llenado. El <code class="ptr-inline">if (ptrMejorEst != nullptr)</code> es la comprobación de seguridad de que sí se encontró un ganador antes de desreferenciarlo.</p>
    </div>
  </section>
 
  <div class="glossary" id="glosario">
    <h2>Glosario rápido de punteros</h2>
    <dl>
      <div class="row">
        <dt>Venta* ptr = ventas;</dt>
        <dd>El nombre de un arreglo ya "decae" a la dirección de su primer elemento — no hace falta <code class="ptr-inline">&amp;ventas[0]</code>. Al declararse una sola vez arriba, sigue siendo válido dentro de cualquier <code class="ptr-inline">case</code> del menú.</dd>
      </div>
      <div class="row">
        <dt>ptr + i</dt>
        <dd>Aritmética de punteros: avanza <em>i</em> elementos completos, no <em>i</em> bytes. El compilador ya sabe el tamaño del struct.</dd>
      </div>
      <div class="row">
        <dt>(ptr + i)-&gt;campo</dt>
        <dd>Abreviación de <code class="ptr-inline">(*(ptr + i)).campo</code>: desreferenciar y acceder al campo en un solo paso.</dd>
      </div>
      <div class="row">
        <dt>*(ptrIds + j)</dt>
        <dd>Cuando el puntero no es a un struct sino a un tipo simple (<code class="ptr-inline">int</code>, <code class="ptr-inline">float</code>), no hay flecha — se desreferencia directo con <code class="ptr-inline">*</code>.</dd>
      </div>
      <div class="row">
        <dt>Estudiante* ptrMejorEst</dt>
        <dd>Un puntero que "recuerda" cuál fue el mejor elemento visto hasta el momento. Se reasigna dentro del mismo bucle que calcula los promedios, evitando un segundo recorrido.</dd>
      </div>
    </dl>
  </div>
 
</div>
 
<footer>Taller 3 — Programación Avanzada</footer>
 
</body>
</html>
 






