Hier finden Sie einen Solver, der Ihnen
* den ggT zweier Zahlen mit dem euklidischen Algorithmus berechnet (mit Lösungsweg)
* diophantische Gleichungen löst (auch mit Lösungsweg)

Sie finden hier sowohl sämtliche Quelldateien als auch das fertige Programm zum Nur-Ausführen.

Um das Programm nur herunterzuladen und auszuführen, finden Sie alles nötige im "for-user" - Ordner.




## Beispiel für diophantische Gleichung

Gegeben ist die Aufgabe
__48a + 36b = 228__

Zuerst überprüfen wir die Lösbarkeit.
Dazu bestimmen wir den größten gemeinsamen Teiler der Koeffizienten:

48     =     36 * 1   +   12

36     =     12 * 3   +   0

Der ggT der beiden Zahlen ist:  12

 Wir reduzieren falls ggT>1 die Gleichung und erhalten:

48 / 12   =   4

36 / 12   =   3

228 / 12   =   19

4 * a   +   3 * b     =     19

Jetzt versuchen wir, die Gleichung zu lösen...
Betrachten wir die Gleichung dazu modulo des Koeffizienten von a:

3 * b     =     19          (mod  4 )

jetzt suchen wir das (multiplikative mod-)Inverse vom Koeffizienten von b:

3 * 3 * b     =     3 * 19          (mod  4 )

b     =     1          (mod  4 )

Wir führen einen neuen Parameter k element Z ein:
b     =          4 * k   +   1

Und jetzt sind wir auch fast schon fertig:

Wir ersetzen jetzt b anhand dieser Gleichung und erhalten dann für jeden ganzen Parameterwert k ein Wertepaar (a,b) von ganzen Zahlen als Lösung:

4 * a     +     3 * ( 4 * k   +   1)          =          19

4 * a     +     12 * k   +   3          =          19

4 * a     +     12 * k           =       19 - 3

4 * a     +     12 * k           =       16

a     +     3 * k           =       4

a        =         4   -   3 * k

TADAAAA!!!

 Wir haben schon die Lösung.
