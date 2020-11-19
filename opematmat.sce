function [res]=matmat3b(A,B)

    m=size(A,1);
    n=size(B,2);
    p=size(B,1);

    res=zeros(m,n);

    for i=1:m
        for j=1:n
            for k=1:p

                res(i,j)= A(i,k)*B(k,j)+res(i,j);
            end
        end
    end

endfunction

function [res]=matmat2b(A,B)

    m=size(A,1);
    n=size(B,2);

    res=zeros(m,n);

    for i=1:m
        for j=1:n

             res(i,j)= A(i,:)*B(:,j)+res(i,j);
        end
    end

endfunction

function [res]=matmat1b(A,B)

    m=size(A,1);

    res=zeros(m,n);

    for i=1:m
         res(i,:)= A(i,:)*B(:,:)+res(i,:);
    end

endfunction
