package com.example.intent2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;

public class DisplayActivity extends AppCompatActivity {


    private ImageView imageViewDisplay;
    private TextView textViewDisplay;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_display);

        imageViewDisplay = (ImageView)findViewById(R.id.imageView_id);
        textViewDisplay = (TextView)findViewById(R.id.textView_display);

        Intent intent = getIntent();
        String title = intent.getStringExtra("title");
        setTitle(title);

        int image = intent.getIntExtra("image", R.drawable.banner1);
        int text = intent.getIntExtra("text", R.string.taiwan_info);

        imageViewDisplay.setImageResource(image);
        textViewDisplay.setText(text);

    }
}
