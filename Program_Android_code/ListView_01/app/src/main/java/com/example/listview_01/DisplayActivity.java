package com.example.listview_01;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;

public class DisplayActivity extends AppCompatActivity {

    private TextView textViewFood;
    private  int[] foodImage = {R.drawable.coca_cola_light,R.drawable.coca_cola_zero,R.drawable.coca_cola,R.drawable.french_fries
        ,R.drawable.hamburger,R.drawable.kfc};
    private ImageView imageViewDisplay;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_display);

        Intent intent = getIntent();
        String title = intent.getStringExtra("city");
        setTitle(title);

        textViewFood = (TextView)findViewById(R.id.textView_title);
        String food = intent.getStringExtra("food");
        textViewFood.setText(food);

        imageViewDisplay = (ImageView)findViewById(R.id.imageView_id);
        int index = intent.getIntExtra("index",2);
        imageViewDisplay.setImageResource(foodImage[index]);


    }
}
