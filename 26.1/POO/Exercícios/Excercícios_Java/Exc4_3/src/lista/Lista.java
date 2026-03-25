package lista;

public class Lista {
	private int tam=0;
	private No ini=null;
	private No fin=null;
	private No corr=null;
	
	
	public boolean vazio() {

		if(this.ini == null && this.fin == null) {
			this.tam = 0;
			return true;
		}
		
		else {return false;}
		
	}
	
	public void insIni(Object x) {
		
		//Eu não preciso checar se está vazio, pois é o prim elemento já que eu to inserindo no início
		
		No novo_no = new No(x, this.ini); //Cria novo elemento com filho == null
		this.ini = novo_no;
		
		if(this.fin == null) {
			this.fin = this.ini; //O final é null, é por que eu só inseri o primeiro elemento. Então o final é o início, já que ele só tem um elemento;
			//Depois da peimeira vez não entra mais nesse if pois ele não torna a ser null. A não ser no momento inicial de uma lista
		}
	
		this.tam+=1;
			
	}
	
	public void insFin(Object x) {	
		
		No novo_no = new No(x, null);
		
		if(vazio() == true) {
			
			this.fin = novo_no;
			this.ini = this.fin;
			tam+=1;
		}
		else {
			
			this.fin.setProx(novo_no);
			this.fin = novo_no;
			
			tam+=1;
			
		}
	}
	
	public Object retIni() {
		
		if( vazio() == true ) {
			return null;
		}
		
		No removido = this.ini;
		
		No prox = removido.getProx(); //Pega o próximo do removido
		
		if(prox == null) {//Quer dizer que lista não tem próximo, então ela vai fixar vazia ao retirar o primeiro (e único)
			
			removido.setProx(null);//Não é obrigatório. Apenas quero desreferenciar o "ponteiro" do cara que vai ser removido para ninguém. Então ele fica perdido no espaço...
			this.ini = null;
			this.fin = null;
		
		}
		else {
			
			removido.setProx(null); //Não é obrigatório. Apenas quero desreferenciar o "ponteiro" do cara que vai ser removido para ninguém. Então ele fica perdido no espaço...
			this.ini = prox;
			
		}
		tam-=1;
		
		
		return removido.getElem();
		
	}
	
	public Object retFin() {
		
		if( vazio() == true ) {
			return null;
		}
		
		No ultimo = this.fin;
		
	
		if(ultimo == this.ini) {
			this.ini = null;
			this.fin = null;
			this.tam = 0;
		}
		else {
			
			this.corr = this.ini;
			while(this.corr.getProx() != ultimo) { 
				this.corr = this.corr.getProx();
			}
			//Exemplo desse while:
			// [A]->[B]->[C]->null
			// ini = A fin = C
			// corr = A o porx de corr (B) é o ultimo (C) -> Não, então continua
			// corr = A -> B : corr = B
			// corr = B o proximod e corr (C) é o ultimo (C) -> Sim! Então para e sai do while
			
			//Corr parou no penúltimo
			
			this.corr.setProx(null); // Seto o próximo do penúltimo (o último) para null
			this.fin = this.corr;
			
			this.tam-=1;
		}
		return ultimo.getElem();
		
	}
	
	public void posIni() {
		this.corr = this.ini;		
	}
	
	
	public Object prox() {
		
		if(this.corr == null) {
			return null;
		}
		
		Object elem =  this.corr.getElem();
		
		this.corr = this.corr.getProx();
		
		return elem;
	}
	
	
		
}
