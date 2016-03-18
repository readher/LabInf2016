//Proszę ściągnąć do swojego katalogu następujące pliki, składające się na program w C:
   //funkcje.c
   //funkcje.h
  // glowny.c
//Wywołanie w programie glowny.c funkcji form0 powoduje wczytanie formuły logicznej (zdania) i wyprodukowanie jej drzewa wywodu. Podawane formuły powinny być zgodne z gramatyką z komentarza na początku programu glowny.c . Np. zamiast formuły
   //(p∧q ⇒ r)  ≡  (p ⇒ (q ⇒ r))
//należy wstukać
   //(p&q > r) = (p > (q > r))
//W tym samym komentarzu jest podany sposób kompilacji programu z funkcjami.
//Program w obecnej postaci niczego sensownego nie drukuje: drzewo wywodu powstaje w pamięci komputera, ale nic się już potem z nim nie dzieje i program kończy działanie.
//Napisać funkcję wylicz, obliczającą wartość logiczną formuły (czy jest prawdziwa, czy fałszywa).
