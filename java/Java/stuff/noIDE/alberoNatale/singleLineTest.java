public class singleLineTest {
	public static void clearScreen() {
		System.out.print("\033[H\033[2J");
		System.out.flush();
	}

	public static void main(String[] args) {
		try {
			int height = 1;
			clearScreen();
			System.out.println(" # # # # ");
			Thread.sleep(500);
			clearScreen();
			System.out.println("# # # # #");
			Thread.sleep(500);
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}
}
