public class Utils {
	public final int map(int n, int start1, int stop1, int start2, int stop2) {
		return (n - start1) / (stop1 - start1) * (stop2 - start2)+ start2; 
	}
}
