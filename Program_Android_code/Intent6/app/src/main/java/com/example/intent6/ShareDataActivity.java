package com.example.intent6;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class ShareDataActivity extends AppCompatActivity {

    private TextView textViewData;
    private Intent intent;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_share_data);

        setTitle("share data");

        textViewData = (TextView)findViewById(R.id.textView_shareData);
        textViewData.setText("");

        intent = getIntent();
        String data = intent.getStringExtra(Intent.EXTRA_TEXT);
        textViewData.setText(data);
    }
}
