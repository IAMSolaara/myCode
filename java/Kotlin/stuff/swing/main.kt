package com.mentalabs.swingTst

import javax.swing.*;
import java.awt.EventQueue;

class KotlinSwingExample(title: String) : JFrame(){
	init {
		createUI(title)
	}	

	private fun createUI(title: String) {
		setTitle(title);
		defaultCloseOperation = JFrame.EXIT_ON_CLOSE;
		val labellio = JLabel("RICCO GAI");
		val testBtn = JButton("Close");
		testBtn.addActionListener{System.exit(0);};
		createLayout(labellio, testBtn);
		setSize(300, 200);
		setLocationRelativeTo(null);
	}

	private fun createLayout(vararg arg: JComponent) {
		val gl = GroupLayout(contentPane);
		contentPane.layout = gl;
		gl.autoCreateContainerGaps = true;

		gl.setHorizontalGroup(gl.createSequentialGroup()
				.addComponent(arg[0])
				.addComponent(arg[1])
        )

        gl.setVerticalGroup(gl.createSequentialGroup()
                .addComponent(arg[0])
				.addComponent(arg[1])
        )

        pack()
	}

}

private fun createAndShowGUI() {
	val frame = KotlinSwingExample("test mentoso");
	frame.isVisible = true;
}

fun main(args: Array<String>) {
	EventQueue.invokeLater(::createAndShowGUI);
}
