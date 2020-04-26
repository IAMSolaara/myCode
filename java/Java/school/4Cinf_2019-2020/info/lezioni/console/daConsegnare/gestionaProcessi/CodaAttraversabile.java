/**
 * @author Yvan Lai 4^C
 * @version 0.1 
 */

/*
  CodaAttraversabile
  
  attributi
  -head:Nodo
  -rear:Nodo

  metodi costruttori
  + CodaAttraversabile()
  
  metodi modificatori
  + pushFromEnd(in p:Processo):boolean
  + pop():Processo

  altri metodi
  + toString():String
  + empty():boolean
 */

public class CodaAttraversabile{

    private Nodo head;
    private Nodo rear;

    /**
     * Crea una coda attraversabile  
     */
    public CodaAttraversabile()
    {
	head=null;
	rear=null;
    }

    /**
     * Inserisce un processo in coda
     * @param p Il processo da inserire
     * @return true successo <br> false fallimento
     */
    public boolean pushFromEnd(Processo p)
    {
	boolean ris=false;
	Nodo tmp;
	
	if(p!=null)
	    {
		ris= true;
		tmp= new Nodo(p);
		if(rear == null)
		    {
			head=tmp;
		    }
		else
		    {
			rear.setNext(tmp);
		    }
		rear=tmp;

	    }
	return ris;
    }//pushFromEnd

    /**
     * Restituisce il processo contenuto nella testa
     * @return Il processo
     */
    public Processo pop()
    {
	Processo p=null;

	if(rear != null)
	    {
		p=head.getProcesso();
		head=head.getNext();
		if(head==null)
		    rear=null;
	    }
	
	return p;
    }

    /**
     * Controlla se la coda e' vuota
     * @return true se lo e' <br> false se c'e' almeno un nodo
     */
    public boolean empty()
    {
	boolean ris=false;

	if(head==null)
	    ris=true;

	return ris;
    }

    /**
     * Restituisce una stringa con lo stato dell'oggetto
     * @return La stringa
     */
    public String toString()
    {
	return toString(head);
    }

    private String toString(Nodo n)
    {
	String s="";

	if(n!=null)
	    s=s+n.toString()+toString(n.getNext());

	return s;
    }
}


