function jouet(N,e)

format( "e",e);

A=rand(N,N);

xex=rand(N,1);

B=A*xex;

x=A\B;

frelres = norm(x-xex)/norm(xex);//erreur avant

brelres = norm(B-A*x)/norm(B);//erreur arrier

cot = cond(A);

disp("Erreur avant=", frelres)

disp("Erreur arriere=",brelres)

disp("Conditionnement=", cot)

disp("born", cot * brelres)

endfunction
