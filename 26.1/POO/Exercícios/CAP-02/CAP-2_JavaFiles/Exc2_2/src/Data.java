public class Data{
	
	int dia, mes, ano;
	
	public Data(int d,int m,int a) {
		dia=d;
		mes=m;
		ano=a;
	}
	
	
	public int get(int e) {
		
		if (e == 1){
			return dia;
		}
		else if (e == 2){
			return mes;
		}
		else if (e == 3){
			return ano;
		}
		else {
			return -1;
		}
		
		
	}
	
	public String getString() {
		
		String d = Integer.toString(dia);
		String m = Integer.toString(mes);
		String a = Integer.toString(ano);
		
		return d + '/' + m + '/' + a;
	}
	
	
}