package app.saluti;

import android.app.Activity;
import android.os.Bundle;
import android.view.*;
import android.view.View.*;
import android.widget.*;

public class Saluti extends Activity
{
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

		//creare edittext per far mettere il nome alla persona
		EditText textField = new EditText(this);

		//creare textview per chiedere il nome
		TextView msg = new TextView(this);
		msg.setText("Come ti chiami?");

		//creare textview per il nome della persona
		TextView tv = new TextView(this);
		tv.setVisibility(View.INVISIBLE);

		//creare pulsante per fare le cose
		Button btn = new Button(this);
		btn.setOnClickListener(new GestorePulsante());

		LinearLayout topBar = new LinearLayout(this);
		topBar.setOrientation(LinearLayout.VERTICAL);
		topBar.addView(msg);
		topBar.addView(textField);
		topBar.addView(btn);

		LinearLayout outerLayout = new LinearLayout(this);
		outerLayout.setOrientation(LinearLayout.VERTICAL);
		outerLayout.addView(topBar);
		outerLayout.addView(tv);

        setContentView(outerLayout);
    }
}
