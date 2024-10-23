% parent(child, parent)



        % sunil
        %     \
        % sachin  sunita
        %     \   /
        %     gauri
        %   /      \
        % ravi    rashmi


parent(ravi, gauri).
parent(rashmi, gauri).
parent(gauri, sachin).
parent(gauri, sunita).
parent(sachin, sunil).

% male(person)
male(ravi).
male(sachin).
male(sunil).

% female(person)
female(gauri).
female(sunita).
female(rashmi).




% sibling(X, Y) - X and Y are siblings if they have the same parent.
sibling(X, Y) :- parent(X, P), parent(Y, P), X \= Y.

% grandparent(G, C) - G is the grandparent of C if G is a parent of Cs parent.
grandparent(G, C) :- parent(P, C), parent(G, P).

% ancestor(A, D) - A is an ancestor of D if A is a parent or a parent of an ancestor.
ancestor(A, D) :- parent(A, D).
ancestor(A, D) :- parent(A, P), ancestor(P, D).