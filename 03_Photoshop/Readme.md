## Abgabetermin: Montag, 04.10.2021, 11:30 Uhr

## Übungsblatt 03, Aufgabe 01 (20 Punkte)

Schreiben Sie ein Klasse **Photoshop**, welche ein **Bild** im `.ppm`-Format einlesen kann oder alternativ eine neue leere Arbeitsfläche mit vom Nutzer eingegebenen Maßen realisiert. Eventuell müssen Sie dafür Ihren Klassenentwurf von **Bild** und **Farbe** leicht anpassen (Ein Umbennennen von **Farbe** in **Pixel** erleichtert eventuell das Codeverständnis).

Realisieren Sie folgende Funktionalität:
*   *Speichern unter* in den unkomprimierten Formaten `.ppm (P3)` und `.ppm (P6)` ([Hinweise zu den Formaten](http://davis.lbl.gov/Manuals/NETPBM/doc/ppm.html))
*   *Einfärben* des gesamten Bildes/Arbeitsfläche mit 10x10 Pixel-Quadraten zufälliger Farbe
*   *Drehen* des Bildes um 90° im Uhrzeigersinn
*   *Helligkeit verringern/erhöhen* um einen vom Nutzer abgefragten prozentualen Wert
*   Ein Menü, in dem der Nutzer die verschiedenen Operationen ausführen kann 

Verfassen Sie außerdem ein Klassendiagramm nach UML2-Standard!

## Übungsblatt 03, Aufgabe 02 (15 Punkte)

Erweitern Sie **Photoshop** um die Funktion ein farbiges Bild in ein Schwarz-Weiß (Greyscale) Bild zu transformieren. Speichern Sie das neue Bild möglichst effizient ab.

Um Farben zu Graustufen zu transformieren ist es nötig die gewichtete Helligkeit (Luma/Luminanz) der einzelnen Farben zu betrachten. Dabei werden die Farben nicht gleich gewichtet, da zwischen Rot, Grün & Blau für das menschliche Auge (und auf Grund der unterschiedlichen Wellenlängen des farbigen Lichts) Helligkeitsunterschiede herrschen.

Guter Ergebnisse sind bspw. mit der Formel `Y = 0.299 R + 0.587 G + 0.114 B` zu erziehlen.

Hinweis: http://davis.lbl.gov/Manuals/NETPBM/doc/pgm.html

## Übungsblatt 03, Aufgabe 03 (15 Punkte)

***Super Simple Zoom***

Erweitern Sie ihr Programm um eine 200% Zoomfunktion unter Verwendung der *zero order hold*-Methode:
*   Iteriere über alle Reihen des Bildes
    *   Wähle reihenweise zwei aufeinanderfolgende Pixel und füge einen Pixel zwischen diesen ein nach der Formel `px1 + px2 / 2`
*   Iteriere nun über alle Spalten des Bilden
    *   Wähle spaltenweise zwei aufeinanderfolgende Pixel und füge einen Pixel zwischen diesen ein nach obiger Formel
