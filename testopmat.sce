n=10;

A=rand(n,n);
B=rand(n,n);

tic;
res=matmat3b(A,B);
toc

tic;
res=matmat2b(A,B);
toc

tic;
res=matmat1b(A,B);
toc
