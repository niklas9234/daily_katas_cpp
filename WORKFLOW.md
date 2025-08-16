# Workflow – Projektstruktur & Vorgehen für C++ Advent of Code

Dieses Dokument beschreibt die generelle Vorgehensweise beim Anlegen neuer Aufgaben (Tage) im Projekt, sowie Sonderfälle und Best Practices.

---

## Allgemeiner Ablauf für einen neuen Tag

1. **Ordner anlegen**
    - Unter `lib/<jahr>/day_XX/` die Unterordner `include/` und `src/` erstellen.
    - Im `include/` Verzeichnis: öffentlichen Header ablegen.
    - Im `src/` Verzeichnis: Implementierungsdateien ablegen.

2. **Namespace wählen**
    - Einheitlich `aoc<jahr>::day_XX` verwenden.
    - Konsistenz ist wichtig, sonst entstehen Linker-Fehler.

3. **Header-Datei (`.h/.hpp`)**
    - Enthält die öffentliche Schnittstelle: Funktionen (`part1`, `part2`), Klassen-Schnittstellen, Structs, Konstanten.
    - Nur Deklarationen, keine Implementierungen.
    - Enthält `#pragma once` oder klassische Include-Guards.
    - Nur das Nötigste als `public API` exportieren.

4. **Quell-Datei (`.cpp`)**
    - Enthält die Implementierung der im Header deklarierten Funktionen/Klassen.
    - Private Hilfsfunktionen hier definieren, nicht im Header.
    - Der gleiche Namespace wie im Header muss verwendet werden.

5. **Runner (`main.cpp`)**
    - Liegt unter `apps/`.
    - Importiert die Header der jeweiligen Tage.
    - Steuert, welche Tages-Lösung mit welchem Input ausgeführt wird.
    - Enthält die einzige `main`-Funktion des Projekts.

6. **CMake**
    - Neue `.cpp` Dateien zum Build hinzufügen.
    - Den Include-Pfad (`include/`) der neuen Tages-Library eintragen.
    - Sauber neu konfigurieren, wenn neue Quellen hinzugefügt wurden.

---

## Best Practices

- **Eine Aufgabe = eine Library-Einheit**  
  Jeder Tag bildet eine abgeschlossene Einheit mit eigenem Header und Quellen.

- **Öffentlich vs. intern trennen**
    - Alles, was nur für interne Implementierung nötig ist → in `.cpp` oder in einem `detail/`-Header.
    - Alles, was von außen (Runner, Tests) genutzt wird → in den öffentlichen Header.

- **Konsistente Benennung**
    - `day_01.h`, `day_01.cpp`
    - Namespace: `aoc2024::day_01`
    - Eingabedatei: `data/2024/day_01.txt`

- **Nur eine `main`-Funktion**  
  Alle Aufgaben werden über denselben Runner gestartet, niemals mehrere `main.cpp` im Projekt haben.

- **Daten getrennt halten**  
  Eingabedateien gehören nach `data/<jahr>/day_XX.txt`, nicht in den Code.

- **Tests**  
  Für jeden Tag optionale Unit-Tests unter `tests/` schreiben.  
  Getrennt vom produktiven Runner.

---

## Sonderfälle & Ausnahmen

### Mehrere Klassen / Aufteilung in Dateien
- Eine Klasse = eigener Header + eigener `.cpp`.
- Alle Dateien nutzen denselben Namespace (`aoc2024::day_XX`).
- Gemeinsame Helfer können in ein `detail/`-Unterverzeichnis oder direkt in `.cpp` ausgelagert werden.

### Templates
- Templates **müssen** vollständig im Header definiert sein.
- Alternativ kann eine separate `.tpp`/`.ipp` Datei erstellt und vom Header inkludiert werden.

### Konstanten
- `constexpr` oder `inline` Konstanten können direkt im Header stehen.
- Sonst Deklaration im Header, Definition in einer `.cpp`.

### Gemeinsame Utilities
- Funktionen, die von mehreren Tagen verwendet werden (z. B. Input-Parser, Timer), kommen in ein zentrales `lib/<jahr>/aoc/` Verzeichnis.
- Struktur wie bei den Tagen: `include/aoc<jahr>/utils/...` und `src/...`.
- Vermeidet Duplikate und erleichtert Wartung.

### Tests
- Tests haben eine eigene Binary (z. B. mit Catch2 oder GoogleTest).
- Build-System so konfigurieren, dass die Bibliotheken der Tage in den Tests verlinkt werden können.
- Tests nie in das produktive `main.cpp` mischen.

---
