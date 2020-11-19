function jouet(N,e)

format( "e",e);

A=rand(N,N);

xex=rand(N,1);

B=A*xex;

x=A\B;

frelres = norm(x-xex)/norm(xex);

brelres = norm(B-A*x)/norm(B);

cata = cond(A);

disp("frelres=", cata)

disp("=", cata * frelres)

disp("=", cata * brelres)

endfunction
