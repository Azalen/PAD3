
# Blatt 4 - Datenkompression

## Aufgabe 01: Shannon–Fano

Implementieren Sie den Shannon-Fano-Algorithmus zum encodieren von Zeichenketten in Binärcode. Schreiben Sie dazu die zwei Klassen `SFEncode` und `SFNode`. Erstere soll zur Gesamtkoordination des Encodierprozesses dienen, während Letztere einen Knotem im zugehörigen Binärbaum darstellt. `SFEncode` soll eine Zeichenkette parsen und die Anzahl der enthaltenen Buchstaben in einer Fequenztabelle verwalten. Daraus können dann relative Häufigkeiten der einzelnen Zeichen ermittelt werden. Mithilfe der Häufigkeiten kann schließlich die Trennposition für den Binärbaum errechnet werden. Die Blätter `SFNode`sollen nach Möglichkeit keine eigene Datenstruktur verwalten, sondern durch Indizes auf die Originalstruktur verweisen. Es genügt am Ende einen String mit dem korrekten Binärcode auszugeben.

Abweichende Implementierungen sind gern gesehen.

**Tips:**
* die *C++ STL* enthält passende Datenstrukturen doch eventuell ist es sinnvoll mehr als eine Einzelne zu verwenden
* [Lambda-Funktionen](https://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11) oder [Comparator-Klassen](https://www.geeksforgeeks.org/comparator-class-in-c-with-examples/) sind eventuell hilfreich
* STL `<set>` lässt sich nur nach *key* - nicht nach *value* - sortieren. Mögliche Lösungen hierfür [finden Sie hier](https://www.educative.io/edpresso/how-to-sort-a-map-by-value-in-cpp).

**Weitere Informationen:**
* https://www.geeksforgeeks.org/shannon-fano-algorithm-for-data-compression/
* https://www.youtube.com/watch?v=B3y0RsVCyrw

## Aufgabe 02: Huffman

