package lista;

public class Exc4_3 {
	
	 public static void main(String[] args) {

	        Lista l = new Lista();

	        // Criando vetores
	        Vetor v1 = new Vetor(1, 2);
	        Vetor v2 = new Vetor(3, 4);
	        Vetor v3 = new Vetor(5, 6);
	        Vetor v4 = new Vetor(7, 8);

	        // Inserindo na lista
	        l.insIni(v1);  // [v1]
	        l.insFin(v2);  // [v1, v2]
	        l.insIni(v3);  // [v3, v1, v2]
	        l.insFin(v4);  // [v3, v1, v2, v4]

	        // Posiciona no início
	        l.posIni();

	        // Percorre a lista
	        Object obj;

	        while ((obj = l.prox()) != null) {

	            Vetor v = (Vetor) obj;

	            System.out.println(v.toString());
	            System.out.println("x = " + v.getX() + ", y = " + v.getY());
	        }
	        
	        //Como faço com for?
	        // Resultado: Com while é muito melhor pq para fazer o for precisariamos do tamaho da lista que é uma instancia private e só pode ser acessada por um método da class.
	        // Mas como não tem um método, eu teria que criar e o exercíco não pede isso. Então while é a melhor forma, pois consigo naegar pelo próximo até que seja null(fim da lista)
	    }
}
