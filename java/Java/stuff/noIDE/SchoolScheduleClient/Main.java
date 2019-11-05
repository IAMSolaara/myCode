package com.mentalabs.SchoolScheduleClient;

import java.sql.*;

public class Main {
	public static void main(String[] args) {
		try{
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://192.168.1.2:3306/SchoolScheduleDB", "school", "school");
			Statement stmt = con.createStatement();
			ResultSet rs = stmt.executeQuery("select * from SchoolSchedule");
			while (rs.next()) System.out.println(rs.getArray("Monday").toString());
			con.close();
		}
		catch (Exception e) {
			System.out.println(e);
		}

	}
}
