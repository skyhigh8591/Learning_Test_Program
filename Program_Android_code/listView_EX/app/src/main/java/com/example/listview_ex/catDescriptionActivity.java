package com.example.listview_ex;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

public class catDescriptionActivity extends AppCompatActivity {

    private TextView textViewCat;
    private ImageView imageViewDisplay;
    private  int[] catImage = {R.drawable.a,R.drawable.b,R.drawable.c,R.drawable.d
            ,R.drawable.e,R.drawable.f,R.drawable.g,R.drawable.h};
    private Button BK;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cat_description);


        Intent intent = getIntent();
        String title = intent.getStringExtra("name");
        setTitle(title);

        textViewCat = (TextView)findViewById(R.id.textView_description_id);
        String cat = intent.getStringExtra("description");
        textViewCat.setText(cat);

        imageViewDisplay = (ImageView)findViewById(R.id.imageView_description_pc);
        int index = intent.getIntExtra("image",2);
        imageViewDisplay.setImageResource(catImage[index]);

        BK = (Button)findViewById(R.id.button_Bk);

        BK.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });


    }
}
