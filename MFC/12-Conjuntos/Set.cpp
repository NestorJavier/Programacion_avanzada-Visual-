// Set.cpp: implementation of the CSet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Conjuntos.h"
#include "Set.h"
#include <time.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSet::CSet()
{

}

CSet::~CSet()
{

}

CSet& CSet::operator =(CSet &l)//Asignacion
{
	this->AddHead(&l);

	return *this;
}

CSet& CSet::operator !()//Coplemento
{
	CNodo *aux, *nodo;
	int n = 0;
	POSITION pos;
	CSet *listaCp = new CSet();
	
	pos = this->GetHeadPosition();
	while(pos)
	{
		aux = (CNodo*)this->GetAt(pos);
		if(n != aux->numero)
		{
			while(n != aux->numero)
			{
				nodo = new CNodo(n);
				listaCp->AddTail(nodo);
				n++;
			}
			n++;
			this->GetNext(pos);
		}
		else
		{
			n++;
			this->GetNext(pos);
		}
	}
	return *listaCp;
}


void CSet::CrearLista(int i)
{
	int num;
	POSITION pos;
	CNodo *aux, *nodo;

//	srand( (unsigned)time( NULL ) );//Semilla del random
	while(i--)
	{
		num = rand()%5+3;
		nodo = new CNodo(num);

		if(this->IsEmpty())
			this->AddHead(nodo);
		else
		{
			pos = this->GetHeadPosition();
			aux = (CNodo*)this->GetAt(pos);
			if(aux->numero > nodo->numero)
				this->AddHead(nodo);
			else
			{
				if(aux->numero < nodo->numero)
				{
					while(pos)
					{
						aux = (CNodo*)this->GetAt(pos);
						if(aux->numero > nodo->numero)
							break;
						this->GetNext(pos);
					}
				}
				if(!pos)
				{
					if(aux->numero != nodo->numero)
					{
						this->AddTail(nodo);
					}
				}
				else
				{
					if(aux->numero != nodo->numero)
					{
						this->GetPrev(pos);
						if(!pos)
						{
							aux = (CNodo*)this->GetAt(pos);
							if(aux->numero != nodo->numero)
							{
								this->InsertAfter(pos, nodo);
							}
						}
					}
				}
			}
		}
	}
}


void CSet::Destructor()
{
	POSITION pos;
	CNodo *aux;

	pos = this->GetTailPosition();
	while(pos)
	{
		aux = (CNodo*)this->GetPrev(pos);
		this->RemoveTail();
		delete aux;
	}
	this->RemoveAll();
}

CSet& CSet::operator ^(CSet &s)
{
	CNodo *aux, *aux2, *nodo;
	POSITION pos, pos2;
	CSet *inter = new CSet();


	pos2 = s.GetHeadPosition();
	pos = this->GetHeadPosition();
	
	while(pos && pos2)
	{
		aux = (CNodo*)this->GetAt(pos);
		aux2 = (CNodo*)s.GetAt(pos2);

		if(aux->numero == aux2->numero)
		{
			nodo = new CNodo(aux->numero);
			inter->AddTail(nodo);

			this->GetNext(pos);
			s.GetNext(pos2);

			if(pos && pos2)
			{
				aux2 = (CNodo*)s.GetAt(pos2);
				aux = (CNodo*)this->GetAt(pos);
			}
		}
		else
		{
			if(aux->numero > aux2->numero)
			{
				s.GetNext(pos2);
				if(pos2)
					aux2 = (CNodo*)s.GetAt(pos2);
			}
			else
			{
				this->GetNext(pos);
				if(pos)
					aux = (CNodo*)this->GetAt(pos);
			}
		}
	}
	return *inter;
}

CSet& CSet::operator +(CSet &s)
{
	CNodo *aux, *aux2, *nodo;
	POSITION pos, pos2;
	CSet *inter = new CSet();


	pos2 = s.GetHeadPosition();
	pos = this->GetHeadPosition();
	
	while(pos && pos2)
	{
		aux = (CNodo*)this->GetAt(pos);
		aux2 = (CNodo*)s.GetAt(pos2);

		if(aux2->numero != aux->numero)
		{
			if(aux2->numero < aux->numero)
			{
				aux2 = (CNodo*)s.GetAt(pos2);
				nodo = new CNodo(aux2->numero);
				this->InsertBefore(pos, nodo);
				s.GetNext(pos2);
			}
			else
			{
				this->GetNext(pos);

				if(!pos && pos2)
				{
					aux2 = (CNodo*)s.GetAt(pos2);
					nodo = new CNodo(aux2->numero);
					this->AddTail(nodo);
					pos = this->GetTailPosition();
				}
			}
		}
		else
		{
			this->GetNext(pos);
			s.GetNext(pos2);

			if(!pos && pos2)
			{
				aux2 = (CNodo*)s.GetAt(pos2);
				nodo = new CNodo(aux2->numero);
				this->AddTail(nodo);
				pos = this->GetTailPosition();
			}
		}
	}
	return *this;
}
