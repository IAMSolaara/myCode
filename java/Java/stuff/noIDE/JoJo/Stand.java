public class Stand {
	private String name;
	private String ability;
	private String battleCry;

	public Stand(){
		name = "Power Cord Extension";
		ability = "Extend its length.";
		battleCry = "NHGNHNGH";
	}

	public Stand(String name, String ability, String battleCry) {
		if (name != null && ability != null && battleCry != null) {
			this.name = name;
			this.ability = ability;
			this.battleCry = battleCry;
		}
		else {
			name = "Power Cord Extension";
			ability = "Extend its length.";
			battleCry = "NHGNHNGH";

		}
	}

	public Stand(Stand in) {
		if (in != null) {
			name = in.getName();
			ability = in.getAbility();
			battleCry = in.getBattleCry();
		}
		else {
			name = "Power Cord Extension";
			ability = "Extend its length.";
			battleCry = "NHGNHNGH";

		}
	}

	public String getName(){return name;}

	public String getAbility(){return ability;}

	public String getBattleCry(){return battleCry;}

	public void cry(){System.out.println(battleCry);}

	public String toString(){
		String nameString = "「Ｓｔａｎｄ　ｎａｍｅ：　" + name + "」 ";
		String abilityString = "「Ｓｔａｎｄ　ａｂｉｌｉｔｙ：　" + ability + "」 ";
		String battleCryString = "「Ｓｔａｎｄ　ｃｒｙ：　" + battleCry + "」 ";
		return nameString + abilityString + battleCryString;
	}

	public boolean equals(Object o) {
		boolean out = true;
		if (o != null && o instanceof Stand) {
		
		}
		else out = false;
		return out;
	}
}
