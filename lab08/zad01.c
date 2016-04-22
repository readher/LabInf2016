//Jakie będą skutki rozwinięcia następującej makrodefinicji?
 	//#define INFO(kraj, waluta) W kraj OBOWIAZUJE waluta.
 	//INFO(Polsce, zloty)
  //INFO(Rosji, rubel)
 	//INFO(Slowacji, euro)
//Najpierw zgadnąć, a potem sprawdzić komendą
    //gcc -E -CC plik
  #define INFO(kraj, waluta) W kraj OBOWIAZUJE waluta.
  INFO(Polsce, zloty)
  INFO(Rosji, rubel)
  INFO(Slowacji, euro)

  // Program wypisze kolejno : W Polsce OBOWIAZUJE zloty. W Rosji OBOWIAZUJE rubel. W Slowacji OBOWIAZUJE euro.
