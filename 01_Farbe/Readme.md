## Abgabetermin: Montag, 20.09.2021, 11:30 Uhr**

## Übungsblatt 01, Aufgabe 01 (16 Punkte)**
(diese Aufgabe wird fortgesetzt)

Schreibe eine Klasse **Farbe**, die für die Objekte dieser Klasse die jeweiligen Rot-, Grün- und Blauanteile (RGB-Wert) und die Transparenz (Alpha-Wert) speichern kann. Alle vier Werte sind ganze Zahlen zwischen 0 und 255, wobei bei den RGB-Werten der Wert 0 keinen Farbanteil und 255 vollen Farbanteil bedeutet. Der Standardwert für die Transparenz soll 255 (voll deckende Farbe) sein und 0 als Transparenzwert soll eine völlig durchsichtige Farbe bedeuten.

**Beispiele** 
```
schwarz - 0 0 0
weiß - 255 255 255
rot - 255 0 0
grün 0 255 0
blau 0 0 255
gelb 255 255 0
```

```1. Entwerfe geeignete Datenelemente! Achte auf Speichereffizienz für die Datenelemente!``` 
```2. Entwerfe geeignete Konstruktoren und get-/set-Methoden.```
```3. An allen Stellen, an denen im Sourcecode die Datenelemente für die Farbanteile und die Transparenz gesetzt werden, soll verhindert werden, dass Werte kleiner als 0 oder größer als 255 eingetragen werden können.```
```4. Sehen Sie eine Methode vor, die ausgehend von den RGB- und dem Alpha-Wert der Farbe eine ganze Zahl rgba  mit 4 Bytes berechnet gemäß der Formel
    rgba  =  alpha*16777216 +  rot*65536 +  gruen*256 +  blau```    
```5. Sehen Sie eine Aus- und Eingabemethode für die Farbe vor.
    
Zudem soll es eine objektabhängige Methode "Farbe darker()" geben, die ausgehend von der aktuellen Farbe eine dunklere Farbe (als neues Objekt) zurückgeben soll. Multiplizieren Sie dazu die aktuellen RGB-Werte des Farbobjekts um den Faktor 0,7 (der Alpha-Wert soll jedoch gleich bleiben).  
In der Realisierung sollen Sie dazu in der Methode ein neues  Farbe-Objekt anlegen mit den dunkleren Farbanteilen und derselben Transparenz und dieses zurückgeben.```
```6. Sehen Sie eine Vergleichsmethode zweier Objekte der Klasse **Farbe** vor. Die Farben sollen dabei gleich sein, wenn alle drei Farbanteile und die Transparenz übereinstimmen.```

Legen Sie im Anwendungsprogramm alle Farben aus obigem Beispiel an sowie eine weitere Farbe **sienna**, die die RGB-Werte (160, 82, 45) haben soll mit der Defaulttransparenz. Rufen Sie auch die Vergleichsmethode mit auf.