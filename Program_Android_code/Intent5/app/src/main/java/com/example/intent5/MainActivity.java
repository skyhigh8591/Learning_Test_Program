package com.example.intent5;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    private EditText editTextShareData;
    private Button buttonSend;
    private EditText editTextMyIntent;
    private Button buttonMyIntent;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        editTextShareData = (EditText)findViewById(R.id.editText_sharedata);

        buttonSend = (Button)findViewById(R.id.button_snedto);
        buttonSend.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String shareData = editTextShareData.getText().toString();
                String action = Intent.ACTION_SEND;
                Intent intent = new Intent(action);
                intent.putExtra(Intent.EXTRA_TEXT,shareData);
                intent.setType("text/plain");
                startActivity(intent);
              //  startActivity(Intent.createChooser(intent,"Share Data"));

            }
        });

        editTextMyIntent = (EditText)findViewById(R.id.editText_mydata);

        buttonMyIntent = (Button)findViewById(R.id.button_myintent);
        buttonMyIntent.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String myData = editTextMyIntent.getText().toString();
                Intent intent = new Intent();
                intent.setAction("MyIntent");
                intent.putExtra("data",myData);
                intent.putExtra("number",1);
                startActivity(intent);
            }
        });

    }
}
