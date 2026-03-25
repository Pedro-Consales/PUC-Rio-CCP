
public class Matematica {

	
	static double pi(int n){

	    double soma = 0.0;

	    for(int i = 0; i < n; i++){

	        double denominador = 2*i + 1;

	        if(i % 2 == 0){
	            soma += 1.0/denominador;
	        }else{
	            soma -= 1.0/denominador;
	        }

	    }

	    return 4*soma;
	}
	
	
}
