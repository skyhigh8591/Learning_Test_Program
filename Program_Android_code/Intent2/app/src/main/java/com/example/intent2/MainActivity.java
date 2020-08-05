package com.example.intent2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageButton;

public class MainActivity extends AppCompatActivity {

    private ImageButton imageButtonTaiwan,imageButtonSanya,imageButtonChengde,imageButtonGreatwall,imageButtonChong;
    private Context context;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        context = this;

        imageButtonTaiwan = (ImageButton)findViewById(R.id.imageButton_taiwan);
        imageButtonSanya = (ImageButton)findViewById(R.id.imageButton_sanya);
        imageButtonChengde =(ImageButton)findViewById(R.id.imageButton_chengde);
        imageButtonGreatwall =(ImageButton)findViewById(R.id.imageButton_greatwall);
        imageButtonChong =(ImageButton)findViewById(R.id.imageButton_chongcing);

        imageButtonTaiwan.setOnClickListener(new MyButton());
        imageButtonSanya.setOnClickListener(new MyButton());
        imageButtonChengde.setOnClickListener(new MyButton());
        imageButtonGreatwall.setOnClickListener(new MyButton());
        imageButtonChong.setOnClickListener(new MyButton());
    }

    private class MyButton implements View.OnClickListener {


        private String name;

        @Override
        public void onClick(View v) {
            Intent intent = new Intent(context, DisplayActivity.class);

            switch (v.getId())
            {
                case R.id.imageButton_taiwan:
                    name = getResources().getString(R.string.taiwan);
                    Log.d("main","name =" +name);
                    intent.putExtra("title",name);
                    intent.putExtra("image",R.drawable.banner1);
                    intent.putExtra("text",R.string.taiwan_info);
                    break;

                case R.id.imageButton_sanya:
                    name = getResources().getString(R.string.sanya);
                    Log.d("main","name =" +name);
                    intent.putExtra("title",name);
                    intent.putExtra("image",R.drawable.banner2);
                    intent.putExtra("text",R.string.sanya_info);

                    break;

                case R.id.imageButton_chengde:
                    name = getResources().getString(R.string.chengde);
                    Log.d("main","name =" +name);
                    intent.putExtra("title",name);
                    intent.putExtra("image",R.drawable.banner3);
                    intent.putExtra("text",R.string.chengde_info);


                    break;

                case R.id.imageButton_greatwall:
                    name = getResources().getString(R.string.great_wall);
                    Log.d("main","name =" +name);
                    intent.putExtra("title",name);
                    intent.putExtra("image",R.drawable.banner4);
                    intent.putExtra("text",R.string.great_wall_info);

                    break;

                case R.id.imageButton_chongcing:
                    name = getResources().getString(R.string.chong_cing);
                    Log.d("main","name =" +name);
                    intent.putExtra("title",name);
                    intent.putExtra("image",R.drawable.banner5);
                    intent.putExtra("text",R.string.chong_cing_info);


                    break;
            }
            startActivity(intent);
        }
    }
}
