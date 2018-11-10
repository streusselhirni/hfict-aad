# Aufgabge 1

1 Münzkombinationen
In dieser Aufgabe soll ein Algorithmus implementiert werden, welcher für einen bestimmten Geldbetrag die minimale
Anzahl Münzen berechnet.

Der Algorithmus erhält als Input den Betrag sowie ein Array mit den verfügbaren Münzen:

Beispiel:
```
Beispiel:
Betrag: 23 CHF
Münzen: 0.05, 0.10, 0.20, 0.50, 1, 2, 5
Resultat: 5, 5, 5, 5, 2, 1 (minimale Anzahl Münzen)
```

# Aufgabe 2
In dieser Aufgabe soll eine Methode implementiert werden, welche mit Hilfe von Rekursion prüft, ob eine Zeichenkette
ein Palindrome ist.

# Aufgabe 3
In dieser Aufgabe soll eine Methode implementiert werden, welche von 2 Zeichenketten den längsten Substring findet,
welcher in beiden Zeichenketten vorkommt.

## Anmerkung zu Aufgabe 3
Es gibt unterschiedliche Lösungen für dieses Problem. Die optimalste Lösung ist es, einen Suffix-Baum zu
implementieren. Mit Hilfe eines Suffix-Baums kann das Problem mit einer Laufzeit von `O(n)`` gelöst werden.

Die (sehr komplexe) Lösung mit Hilfe eines Suffixbaumes ist im Unterordner "SuffixTree" implementiert.
Interessierte Leser, die ungefähr 4 - 8 Stunden Zeit haben, können sich unter folgenden Links schlau lesen
(Es wird empfohlen, die Seiten der Reihe nach von oben nach unten zu lesen):

  * https://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-1/
  * https://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-2/
  * https://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-3/
  * https://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-4/
  * https://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-5/
  * https://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-6/
  * https://www.geeksforgeeks.org/generalized-suffix-tree-1/
  * https://www.geeksforgeeks.org/suffix-tree-application-5-longest-common-substring-2/

Die von mir selbst entwickelte Lösung (also die Lösung, auf die ich ohne weitere Hilfe selbst kam) basiert darauf,
eine Matrix aufzubauen, welche auf der X-Achse die Buchstaben
des Strings `input1` und auf der Y-Achse die Buchstaben des Strings `input2` auflistet. Die Zeile und Spalte 0 werden
nicht benötigt und sind nur enthalten, um den Code einfacher zu gestalten. Ein Beispiel für eine solche Matrix ist in
der Datei `Aufgabe3/Vergleichsmatrix.xslx` zu sehen.

Für jede Position `[i][j]` in der Matrix werden die Buchstaben `input1.at(i - 1)` und `input2.at(j - 1)` verglichen.
Falls Sie gleich sind, wird die Stelle `[i][j]` der Matrix auf den Wert `[i - 1][j - 1] + 1` gesetzt.

Außerdem wird mit zwei Variablen gemerkt, ob der aktuelle Substring (Werte in der Matrix größer als 1) größer ist,
als was wir zuvor gemerkt hatten. Ist dies der Fall, speichern wir uns die aktuelle Länge und die Startposition
(Wert von `i` abzüglich Länge des Substrings `[i][j]`) um am Ende den Substring auszugeben.

Diese Lösung hat für zwei Strings `S1[0...m]` und `S2[0...n]` eine Laufzeit von `O(m*n)``.