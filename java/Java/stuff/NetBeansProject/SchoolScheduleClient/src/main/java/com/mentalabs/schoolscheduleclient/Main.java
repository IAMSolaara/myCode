/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mentalabs.schoolscheduleclient;

import java.sql.*;

/**
 *
 * @author lorecast162
 */
public class Main {

    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(
                    "jdbc:mysql://192.168.1.2:3306/SchoolScheduleDB", "school", "school");
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("select * from SchoolSchedule");
            System.out.println(rs.getRow());
            for (int i = 1; i <= 11; i++) {
                rs.absolute(i);
                for (int j = 1; j <= 6; j++) {
                    System.out.println("Row " + i + " Col " + j + ": " + rs.getString(j));
                }
            }
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
