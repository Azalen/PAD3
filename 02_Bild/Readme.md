## Abgabetermin: Montag, 27.09.2021, 11:30 Uhr

## Übungsblatt 02, Aufgabe 01 (20 Punkte)
(diese Aufgabe wird fortgesetzt)

*Die folgenden Teilaufgaben beziehen sich auf die Klasse **Farbe** vom letzten Übungsblatt.*

1.	Definieren Sie eine weitere Operatorüberladung für den Test auf Ungleichheit durch Benutzung von  `operator==()`.
2.	Definieren Sie eine Operatorüberladung `<` für den ***lexikografischen*** Vergleich zweier Farben. Zuerst sollen die Rotanteile verglichen werden. Sind sie gleich, sollen anschließend die Grünanteile verglichen werden. Sind diese auch gleich, werden die Blauanteile verglichen und ggf. auch noch die Alphaanteile. Benutzen Sie dabei zwingend den `friend`-Mechanismus d.h. die Operatorüberladung soll keine objektabhängige Methode sein und ohne Aufrufe von etwaigen Get-Methoden auskommen!
3.	Definieren Sie die Operatoren `<=`, `>` und `>=` ohne die Realisierung von Fallunterscheidungen wie in (2).
4.	Falls nicht bereits geschehen definieren Sie die Operatoren `<<` und `>>` zur Aus- und Eingabe durch Verwendung der Methoden`Farbe::ausgabe()` und `Farbe::eingabe()`.
**Hinweis**: Für den reibungslosen Ablauf ist es u.U. hilfreich den Methoden weitere Parameter zu übergeben.
5.	Realisieren Sie die vorhandene Methode `Farbe::darker()` zur Berechnung einer neuen, dunkleren Farbe als die aktuelle Farbe via Operatorüberladung (Operator ist freigestellt). Dabei soll sich nun aber das aktuelle Farbobjekt ändern, also dessen Farbe dunkler werden. 

Testen Sie alle Ihre Operatorüberladungen im Anwedungsprogramm!

**Frage:**
Erläutern Sie Vor- und Nachteile von objektabhängiger und objektunabhängiger (d.h. globaler) Operatorüberladung. Ist es möglich Operatorüberladungen als `static` zu definieren? 

***Lektüre:*** http://www.wilkening-online.de/programmieren/c++-operator-ueberladung.html#Kapitel_2_3


## Noch nicht final
## Übungsblatt 02, Aufgabe 02 (30 Punkte)
(diese Aufgabe wird fortgesetzt)


[<img src="https://i.imgur.com/mvfIzEt.png">](https://youtu.be/ovJcsL7vyrk?t=410)

**Anleitung:**

<img src="https://i.imgur.com/zZ465eE.png">
