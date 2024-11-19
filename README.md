# scef

Fixes a weird encoding issue I've encountered when copying text.

Turns
```
Toto je ˇcesky psan´y text s diakritikou. 

M˚uˇze obsahovat i 'umlaut', ˇcili: ¨a, ¨o nebo ¨u.

Samotn´a diakritika z˚ustane nezmˇenˇena: 'ˇ', '´', '"', '˚'. 
```
Into
```
Toto je česky psaný text s diakritikou. 

Může obsahovat i 'umlaut', čili: ä, ö nebo ü.

Samotná diakritika zůstane nezměněna: 'ˇ', '´', '"', '˚'. 
```

---

To build run:
```
make
```

Example usage:
```
cat input.txt | ./scef > result.txt
```
