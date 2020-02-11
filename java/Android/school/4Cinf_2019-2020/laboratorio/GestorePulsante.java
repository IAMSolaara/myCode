package app.saluti;

import android.view.*;
import android.view.View.*;
import android.widget.*;
import android.app.Activity;
import android.os.Bundle;

public class GestorePulsante implements OnClickListener {
	public void onClick(View v) {
		Activity parentActivity = v.getContext();
		Toast t = Toast.makeText(v.getContext(), "Test", Toast.LENGTH_LONG);
		t.show();
	}
}
