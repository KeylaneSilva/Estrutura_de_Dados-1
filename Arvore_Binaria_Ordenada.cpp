#include <iostream>
using namespace  std ;

class  no
{
private:
	no * esq, * dir;
	int chave;

public:
	no ( int chave)
	{
		this -> chave = chave;
		esq = NULL ;
		dir = NULL ;
	}

	int  getChave ()
	{
		return chave;
	}
	
	// fun��es getters e setters

	no * getEsq ()
	{
		return esq;
	}

	no * getDir ()
	{
		return dir;
	}

	void  setEsq (no * no)
	{
		esq = no;
	}

	void  setDir (no * no)
	{
		dir = no;
	}
};

class  Arvore
{
private:
	no * raiz;

public:
	Arvore ()
	{
		raiz = NULL ;
	}

	void  inserir ( int chave)
	{
		if (raiz == NULL ) // verifica se a �rvore esta vazia
			raiz = novo  no (chave); // cria um novo n�
		else
			juntarAux (raiz, chave);
	}

	void  inserirAux (no * no, int chave)
	{
		// para menor, ent�o insere � esquerda
		if (chave <no-> getChave ())
		{
			// verifica se � esquerda � nulo
			if (no-> getEsq () == NULL )
			{
				no * novo_no = novo no (chave);
				no-> setEsq (novo_no); // seta o novo_no � esquerda
			}
			else
			{
				// sen�o, continua percorrendo recursivamente
				inserirAux (no-> getEsq (), chave);
			}
		}
		// para maior, ent�o insere � direita
		else  if (chave> no-> getChave ())
		{
			// verifica se a direita � nulo
			if (no-> getDir () == NULL )
			{
				no * novo_no = novo  no (chave);
				no-> setDir (novo_no); // seta o novo_no � direita
			}
			else
			{
				// sen�o, continua percorrendo recursivamente
				inserirAux (no-> getDir (), chave);
			}
		}
		// se for igual, n�o vai inserir
		// n�o pode existir 2 chaves iguais
	}

	no * getRaiz ()
	{
		return raiz;
	}

	void  emOrdem (no * no)
	{
		if (no! = NULL )
		{
			emOrdem (no-> getEsq ());
			cout << no-> getChave () << "  " ;
			emOrdem (no-> getDir ());
		}
	}
};

int  main ( int argc, char * argv [])
{
	Arvore arv;

	// insere as chaves
	arv. inserir ( 8 );
	arv. inserir ( 3 );
	arv. inserir ( 10 );
	arv. inserir ( 14 );
	arv. inserir ( 13 );
	arv. inserir ( 1 );
	arv. inserir ( 6 );
	arv. inserir ( 4 );
	arv. inserir ( 7 );

	// percorre em ordem iniciando da raiz
	cout << " Percorrendo em ordem ... \ n " ;
	arv. emOrdem (arv. getRaiz ());

	return  0 ;
}