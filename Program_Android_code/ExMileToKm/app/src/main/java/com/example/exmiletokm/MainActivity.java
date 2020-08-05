package com.example.exmiletokm;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private EditText edtMile;
    private TextView txtKm;
    private Button btnTran;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        edtMile = (EditText) findViewById(R.id.editText_mile);
        txtKm = (TextView) findViewById(R.id.textView_km);
        btnTran = (Button) findViewById(R.id.button_tran);

        btnTran.setOnClickListener(new View.OnClickListener() {
            private double km;

            @Override
            public void onClick(View v) {
                double miles = Double.parseDouble(edtMile.getText().toString());
                km = 1.61 * miles;
                txtKm.setText("時速 =" + km + "公里");

            }
        });

    }
}
