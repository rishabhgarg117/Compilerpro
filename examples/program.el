int i = 1;
while(i neq 101){
  int remainderTwo = i % 2;
  if(remainderTwo eq 0){
    write("even", 4);
    write(i,2);
  }
  if(remainderTwo neq 0){
    write("odd", 4);
  }
  i = i + 1;
}

exit(0);