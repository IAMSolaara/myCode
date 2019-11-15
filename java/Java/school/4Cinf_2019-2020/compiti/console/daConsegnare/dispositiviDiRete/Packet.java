import java.util.regex.*;

/**
	@author Lorenzo Cauli
	@version 0.1
  */

/*






   */

public class Packet {
	private String senderMACAddress;
	private String receiverMACAddress;
	private String sentInfo;

	public Packet(){
		this.senderMACAddress = "00:11:22:33:44:55";
		this.receiverMACAddress = "AA:BB:CC:DD:EE:FF";
		this.sentInfo = "ciaoCIAO:##D";
	}

	public Packet(String senderMACAddress, String receiverMACAddress, String sentInfo) {
		if (senderMACAddress != null && receiverMACAddress != null && sentInfo != null) {
			if (Pattern.matches("..:..:..:..:..:..", senderMACAddress) && Pattern.matches("..:..:..:..:..:..", receiverMACAddress) && !receiverMACAddress.equals(senderMACAddress))  { 
				this.senderMACAddress = senderMACAddress;
				this.receiverMACAddress = receiverMACAddress;
				this.sentInfo = sentInfo;
			}
			else {
				this.senderMACAddress = "00:11:22:33:44:55";
				this.receiverMACAddress = "AA:BB:CC:DD:EE:FF";
				this.sentInfo = "ciaoCIAO:##D";
			}
		}
		else {
			this.senderMACAddress = "00:11:22:33:44:55";
			this.receiverMACAddress = "AA:BB:CC:DD:EE:FF";
			this.sentInfo = "ciaoCIAO:##D";
		}
	}

	public Packet(Packet in) {
		if (in != null) {
			senderMACAddress = in.getSenderMACAddress();
			receiverMACAddress = in.getReceiverMACAddress();
			sentInfo = in.getSentInfo();
		}
		else {
			this.senderMACAddress = "00:11:22:33:44:55";
			this.receiverMACAddress = "AA:BB:CC:DD:EE:FF";
			this.sentInfo = "ciaoCIAO:##D";
		
		}
	}

	public String getSenderMACAddress() {return senderMACAddress;}

	public String getReceiverMACAddress(){return receiverMACAddress;}

	public String getSentInfo(){return sentInfo;}

	public String toString(){
		return "Sender address: " + senderMACAddress + ", Receiver address: " + receiverMACAddress + ", Sent info: " + sentInfo;
	}

	public boolean equals(Object o) {
		boolean out = true;
		if (o == null && !(o instanceof Packet)) out = false;
		else {
			if ( !senderMACAddress.equals(((Packet)o).getSenderMACAddress()) || !receiverMACAddress.equals(((Packet)o).getReceiverMACAddress()) || !sentInfo.equals(((Packet)o).getSentInfo()))out = false;
		}
		return out;
	}
}
