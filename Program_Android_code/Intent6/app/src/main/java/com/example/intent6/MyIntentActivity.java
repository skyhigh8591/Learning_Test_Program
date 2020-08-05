package com.example.intent6;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;

public class MyIntentActivity extends AppCompatActivity {

    private TextView textViewData;
    private ImageView imageViewPic;
    private Intent intent;
    private int[] picArray ={R.drawable.img_1,R.drawable.img_2};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_my_intent);

        setTitle("My Intent");

        textViewData = (TextView)findViewById(R.id.textView_myIntent);
        textViewData.setText("");

        imageViewPic = (ImageView)findViewById(R.id.imageView_id);

        intent = getIntent();
        String data = intent.getStringExtra("data");
        textViewData.setText(data);
        int number = intent.getIntExtra("number",0);
        imageViewPic.setImageResource(picArray[number]);


    }
}
