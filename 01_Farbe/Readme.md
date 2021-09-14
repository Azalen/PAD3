## Abgabetermin: Montag, 20.09.2021, 11:30 Uhr

## Übungsblatt 01, Aufgabe 01 (16 Punkte)
(diese Aufgabe wird fortgesetzt)

Schreiben Sie eine Klasse **Farbe**, die für die Objekte dieser Klasse die jeweiligen Rot-, Grün- und Blauanteile (RGB-Wert) und die Transparenz (Alpha-Wert) speichern kann. Alle vier Werte sind ganze Zahlen zwischen 0 und 255, wobei bei den RGB-Werten der Wert 0 keinen Farbanteil und 255 vollen Farbanteil bedeutet. Der Standardwert für die Transparenz soll 255 (voll deckende Farbe) sein und 0 als Transparenzwert soll eine völlig durchsichtige Farbe bedeuten.

**Beispiele** 
```
schwarz     0   0   0
weiß      255 255 255
rot       255   0   0
grün        0 255   0
blau        0   0 255
gelb      255 255   0
```

1. Entwerfen Sue geeignete Datenelemente! Achten Sie auf Speichereffizienz für die Datenelemente!
2. Entwerfen Sie geeignete Konstruktoren und ggf. get- und set-Methoden.
3. An allen Stellen, an denen im Sourcecode die Datenelemente für die Farbanteile und die Transparenz gesetzt werden, soll verhindert werden, dass Werte kleiner als 0 oder größer als 255 eingetragen werden können.
4. Sehen Sie eine Methode vor, die ausgehend von den RGB- und dem Alpha-Wert der Farbe eine ganze Zahl rgba mit 4 Bytes berechnet gemäß der Formel
    `rgba  =  alpha*16777216 +  rot*65536 +  gruen*256 +  blau`
5. Sehen Sie eine Aus- und Eingabemethode für die Farbe vor. Zudem soll es eine objektabhängige Methode `Farbe darker()` geben, die ausgehend von der aktuellen Farbe eine dunklere Farbe (als neues Objekt) zurückgeben soll. Multiplizieren Sie dazu die aktuellen RGB-Werte des Farbobjekts um den Faktor 0,7 (der Alpha-Wert soll jedoch gleich bleiben). In der Realisierung sollen Sie dazu in der Methode ein neues  Farbe-Objekt anlegen mit den dunkleren Farbanteilen und derselben Transparenz und dieses zurückgeben.
6. Sehen Sie eine Vergleichsmethode zweier Objekte der Klasse Farbe vor. Die Farben sollen dabei gleich sein, wenn alle drei Farbanteile und die Transparenz übereinstimmen.

Legen Sie im Anwendungsprogramm alle Farben aus obigem Beispiel an sowie eine weitere Farbe *sienna*, die die RGB-Werte (160, 82, 45) haben soll mit Defaulttransparenz. Rufen Sie auch die Vergleichsmethode mit auf.

## Übungsblatt 01, Aufgabe 02 (24 Punkte)
(diese Aufgabe wird fortgesetzt)

Erweitern Sie Ihren Entwurf zur Klasse Farbe um folgende Bestandteile:

1.	Verwenden Sie objektunabhängige Datenelemente in Ihrer Klasse, insbesondere auch für Standardwerte (z.B. in Konstruktoren) und minimale/maximale Werte. Diese sollen konsequent in allen Sourcefiles aktuelle Zahlenwerte ersetzen. Zusätzlich soll der Defaultwert für die Transparenz zwar sinnvoll vorbesetzt, aber veränderbar sein.

	Definieren Sie objektunabhängige Datenelemente für die fünf Grundfarben Rot, Grün, Blau, Schwarz und Weiß. Beachten Sie dabei, dass kein "Teufelskreis" entsteht, wenn man in einer Klasse objektunabhängige Datenelemente derselben Klasse definiert.

	  Unterscheiden Sie genau, in welchem Sourcefile Sie die Deklaration eines solchen Objektes (Datentyp + Name, versehen mit `static`) machen und in welches Sourcefile das Objekt zu initialisieren ist (Datentyp + Scope + Name + Konstruktoraufruf).

	Definieren Sie ein veränderbares objektunabhängiges Datenelement für einen Grauton. Dieser soll vorbesetzt sein mit dem RGB-Wert (128, 128, 128).


2.	Definieren Sie eine objektunabhängige Hilfsmethode, die testet, ob ein Wert geeignet ist zur Initialisierung eines RGBA-Anteils oder nicht und die nur in der Klasse aufrufbar sein soll. Die Methode soll bei zulässigem Wert den mit angegebenen RGBA-Anteil verändern. Sollte der Test negativ ausfallen (unzulässiger Wert), soll als Voreinstellung ein Standardwert für den RGBA-Anteil gesetzt werden.


3.	Verwenden Sie überall an den Stellen, an denen RGBA-Anteile durch übergebene Werte gesetzt werden, die Hilfsmethode aus (2).

4.	 Definieren Sie die objektabhängige Methode "darker(..)" aus Aufgabe 01 als objektunabhängige Methode.

5.	Schreiben Sie ein (nicht zu langes) Anwendungsprogramm, das die neuen objektunabhängigen Datenelemente und Methoden testet.

6.	Schreiben Sie einen Typumwandlungskonstruktor, der aus einem ganzzahligen Wert `rgba` ein Objekt der Klasse Farbe erzeugt.

7.	Demonstrieren Sie die implizite und explizite Datentypumwandlung in ein Farbobjekt

**Fragen:**

Warum wird dieser Typumwandlungskonstruktor nicht aktiv, wenn man einen int-Wert mit cout ausgibt?

Wie kann man erzwingen, dass der int-Wert doch als Farbobjekt von cout ausgegeben wird?

Kann man in einer Funktion, die ein Farbobjekt als Funktionsergebnis zurückgeben soll (laut Funktionskopf) im if-Teil ein Farbobjekt mit return zurückgeben und im else-Teil einen int-Wert?