
public class Voo {
	
	private Assento assentos[][];
	private int nFila;
	private int nAssentos;
	private char as;
	
	public Voo(int nf,int na) {
		char as;
		this.nFila=nf;
		this.nAssentos=na;
		this.assentos=new Assento[nf][na]; //alocação dinâmica da matriz
		
		for(int i = 0; i < this.nFila; i+=1) {
			//[[x,x,x],[x,x,x],[x,x,x]]			
			for(int j = 0; j < this.nAssentos; j+=1) {
				
				char as_final = (char) ('A' + j);

				this.assentos[i][j] = new Assento(i+1, as_final);	
			}	
		}
	}
	
	
	public boolean reserva(int fila, char assento) {
		
		
		Assento ass = this.assentos[fila-1][assento - 'A'];
		
		boolean is_livre = ass.getEstado();
		
		if(is_livre == true) {
			ass.reserva();
			return true;
		}
		else
		{
			return false;
		}
		
	}
	
	
	public void imprimeMapa() {
		
		
		for(int i = 0; i < this.nFila; i+=1) {
			//[[x,x,x],[x,x,x],[x,x,x]]			
			
			System.out.printf("%d - ", i+1);
			
			for(int j = 0; j < this.nAssentos; j+=1) {
				
				if(this.assentos[i][j].getEstado() == false) {
					
					System.out.printf("X ");
				}
				else{
					System.out.printf("L ");
				}
				
			}	
			System.out.printf("\n");
		}
		
		
	}
}
