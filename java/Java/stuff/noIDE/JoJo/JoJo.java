public class JoJo {
	public static final long gay = Long.MAX_VALUE;
	private String name;
	private Date birthDay;
	private Stand stand;

	public JoJo() {
		name = "Giovanni GioStar";
		birthDay = new Date();
		stand = new Stand();
	}

	public JoJo(String name, Date birthDay, Stand stand){
		if (name != null && date != null && stand != null) {
			this.name = name;
			this.birthDay = new Date(birthDay.getTime());
			this.stand = new Stand(stand);
		}
	}

	public JoJo(JoJo in){
		if (in != null) {
			
		}
	}
}
