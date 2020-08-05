package com.example.intent3;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private Button buttonData, buttonScore;
    private TextView textViewReturn;
    private Context context;
    private Intent intent;
    private final int DataRequestCode = 100;
    private final int ScoreRequestCode = 200;
    private static final String TAG = "main";
    private String message;
    private int DataRequestScore;
    private  final int ReturnData= 10;
    private final int ReturnScore=20;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        context = this;

        buttonData = (Button) findViewById(R.id.button_data);
        buttonScore = (Button) findViewById(R.id.button_score);

        textViewReturn = (TextView) findViewById(R.id.textView_return);
        textViewReturn.setText("");

        buttonData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                intent = new Intent(context, DataActivity.class);
                startActivityForResult(intent, DataRequestCode);
            }
        });
        buttonScore.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                intent = new Intent(context, ScoreActivity.class);
                startActivityForResult(intent, ScoreRequestCode);
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == DataRequestCode) {
            Log.d(TAG, "requestCode Data=" + requestCode);
            if (resultCode == ReturnData) {
                message = data.getStringExtra("datamessage");
                textViewReturn.setText(message);
            }
        } else if (requestCode == ScoreRequestCode) {
            Log.d(TAG, "requestCode Score=" + requestCode);
            if (resultCode == ReturnScore) {
                message = data.getStringExtra("scoremessage");
                textViewReturn.setText(message);
            }
        }
    }
}
