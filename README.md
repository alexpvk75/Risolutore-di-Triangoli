# TRIANGOLO - DOCUMENTAZIONE TECNICA

Questo progetto è un programma che calcola le principali proprietà di un triangolo a partire dalle lunghezze dei suoi lati.

Il progetto implementa la determinazione di:
- perimetro (somme delle lunghezze dei lati)
- area
- angoli interni
- altezze relative ai lati
- classificazione del triangolo in base a lati e angoli

Il progetto è stato implementato nei linguaggi C e Python durante l’anno scolastico 2025/2026.

## DESCRIZIONE ALGORITMICA

Il programma è organizzato in queste fasi:

- acquisizione controllata dei tre lati del triangolo
- verifica della disuguaglianza triangolare
- calcolo di perimetro, area, angoli e altezze
- stampa e classificazione del triangolo
- gestione del ciclo iterativo e possibile terminazione del programma

Il programma è interamente sequenziale e non utilizza strutture dati dinamiche o parallelismo.

## INTERFACCIA CLU

La CLI è progettata per guidare l’utente nell’inserimento dei dati e nella visualizzazione dei risultati.

Le funzionalità principali includono:
- acquisizione controllata dei lati del triangolo
- validazione automatica dell’input
- gestione degli errori di inserimento
- visualizzazione strutturata dei risultati
- gestione di scelta di eseguire più computazioni

L’utente inserisce tre valori reali positivi corrispondenti ai lati AB, BC e AC
Se i valori non rispettano la disuguaglianza triangolare, il programma rigetta l’input e richiede una nuova inserzione.

## NUCLEO COMPUTAZIONALE

Il cuore del progetto è costituito dai calcoli geometrici basati su formule analitiche.

Area (formula di Erone):
    $$A = \sqrt{s*(s-a)*(s-b)*(s-c)}$$
dove s sta per il semiperimetro

Teorema del coseno:
$$\cos(\alpha) = \frac{b^2+c^2-a^2}{2bc}$$

Altezza relative ai lati:
$$h_a = \frac{2*A}{a}$$

Il triangolo viene classificato secondo due criteri indipendenti:

In base ai lati:
- equilatero: tutti i lati uguali
- isoscele: due lati uguali
- scaleno: tutti i lati diversi
In base agli angoli:
- rettangolo: presenza di un angolo di 90°
- ottusangolo: presenza di un angolo maggiore di 90°
- acutangolo: tutti gli angoli minori di 90°
- equiangolo: tutti gli angoli pari a 60°