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

Führen Sie die Fixpunktiteration zur Berechnung der Mandelbrot-Menge $\mathbb{M}$ aus. 
**Berechnung der Mandelbrotmenge:**
Dazu betrachten wir die *komplexe* Fixpunktiteration:

$z_{k+1} = z_k^2+ c$ $\quad \quad$  $c ∈ \mathbb{C}$ , $k ∈ \mathbb{N}$ mit Startwert $z_0 = 0$

Ein $c ∈ \mathbb{C}$ ist Teil der Mandelbrot-Menge $\mathbb{M}$, wenn die Beträge der $z_k$ beschränkt sind, d.h. nicht über jede beliebige Grenze wachsen. Siehe dazu ein [kurzes Video](https://youtu.be/ovJcsL7vyrk?t=410).

Läuft die Iteration also gegen Unendlich, so ist $c$ nicht Teil der Mandelbrot-Menge $\mathbb{M}$ und wird farbig eingezeichnet. Bleibt die Iteration endlich, nach beliebig vielen Iterationen so ist $c ∈ \mathbb{M}$.
Dabei kann die Iteration entweder **gegen einen Fixpunkt konvergieren** *(Fall 1)*, **periodisches Verhalten** zeigen *(Fall 2)* oder **chaotisch** verlaufen - **aber endlich** bleiben *(Fall 3)*. In jedem der drei Fälle wird der Punkt auf im Koordinatensystem schwarz markiert.

Farbig codiert wird dann die Anzahl der nötigen Iterationen $k$, welche nötig sind, damit $z_k$ größer als ein selbst festgelegter Schwellenwert $M$. Zum Beispiel die Anzahl Iterationen die nötig sind, sodass $z_k > 1000$. Die $1000$ repräsentiert dann "Unendlich".


**Anleitung:**

1. Wählen Sie Intervalle <img src="https://latex.codecogs.com/svg.image?[p_{min},p_{max}]" title="[p_{min},p_{max}]" /> und <img src="https://latex.codecogs.com/svg.image?$[q_{min},q_{max}]$" title="$[q_{min},q_{max}]$" /> für die Real- und Imaginärteile des Funktionswerts $c$ in der Fixpunktiteration, d.h. Grenzen für Abzissen- und Ordinatenachse des zu zeichnenden Mandelbrot-Bildes.

2. Wählen Sie die Bild-Auflösung zur Berechnung, d.h. $r_x$ und $r_y$, um das Ergebnis in einer Matrix der Dimension $r_x$ x $r_y$ zu erstellen. Als Ergebnis der Iteration ergibt sich eine Zahl (eine fiktive Farbnummer). Es stehen 17 verschiedene Zahlen zur Verfügung, von 0 bis 16.

<img src="https://render.githubusercontent.com/render/math?math=%5CHuge%20%5CDelta%20p%20%3A%3D%20(p_%7Bmax%7D-p_%7Bmin%7D)%20%2F%20(r_x-1)">

3. Berechnen Sie die Schrittweiten $$Δ p := (p_{max}-p_{min}) / (r_x-1)$$     $$Δ q := (q_{max}-q_{min}) / (r_y-1)$$ und wählen Sie eine maximale Iterationszahl $K ∈ \mathbb{N}$ sowie eine Abbruchschranke $M>0$ für das maximale Betragsquadrat einer Iterierten.
4. Für alle $n_p=0,...,r_{x-1}$ und $n_q=0,...,r_{y-1}$ führe man die Schritte (iv)-(vi) durch.
5.	Setzen Sie den Iterationszähler $k=0$, setzen Sie $$p:=p_{min}+n_p * Δ p$$ $$q:=q_{min}+n_q * Δ q$$ und 			wählen Sie den Parameter $c=p+iq$ sowie den Startwert $z_0=0$. 
6. Berechnen Sie die nächste Iterierte $z_k+1$ gemäß Iterationsgleichung und inkrementieren Sie $k$.
7. Hat $k$ die maximale Iterationszahl $K$ erreicht, so wähle man das Ergebnis $0$ und gehe zu (vii).
Ansonsten berechne man den Betrag von $z_k$.
Ist $|z_k| \leq M$ und $k < K$, so gehe man zu (v).
Ist $|z_k| > M$, so wähle man das Ergebnis $(k$ mod $16) + 1$ und gehe zu (vii).

8. Das Ergebnis für jeden *Pixel* $(n_p, n_q)$ soll in einer Matrix abgespeichert werden. 

