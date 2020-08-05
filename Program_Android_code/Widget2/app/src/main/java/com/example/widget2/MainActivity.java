package com.example.widget2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "main";
    private Button buttonPic1;
    private Button buttonPic2;
    private Button buttonPic3;
    private ImageView imageViewPic;
    private TextView textViewResult;
    private Object butt1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.d(TAG,"onCreate()");

        buttonPic1 = (Button)findViewById(R.id.button_p1);
        buttonPic2 = (Button)findViewById(R.id.button_p2);
        buttonPic3 = (Button)findViewById(R.id.button_p3);

        
        //butt1 = findViewById(R.id.button_p3);

        imageViewPic = (ImageView)findViewById(R.id.imageView_picture);
        imageViewPic.setVisibility(View.INVISIBLE);

        textViewResult = (TextView)findViewById(R.id.textView_result);
        textViewResult.setText(" ");

        buttonPic1.setOnClickListener(new MyClass());
        buttonPic2.setOnClickListener(new MyClass());
        buttonPic3.setOnClickListener(new MyClass());


    }

    private class MyClass implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (v.getId())
            {
                case R.id.button_p1:
                    Log.d(TAG,"value = " + R.id.button_p1);
                    imageViewPic.setVisibility(View.VISIBLE);
                    imageViewPic.setImageResource(R.drawable.line1);
                    textViewResult.setText("This is Line 1.");
                break;

                case R.id.button_p2:
                    Log.d(TAG,"value = " + R.id.button_p2);
                    imageViewPic.setVisibility(View.VISIBLE);
                    imageViewPic.setImageResource(R.drawable.line2);
                    textViewResult.setText("This is Line 2.");
                    break;

                case R.id.button_p3:
                    Log.d(TAG,"value = " + R.id.button_p3);
                    imageViewPic.setVisibility(View.VISIBLE);
                    imageViewPic.setImageResource(R.drawable.line3);
                    textViewResult.setText("This is Line 3.");
                    break;

            }
        }
    }

    @Override
    protected void onStart() {
        super.onStart();
        Log.d(TAG,"onStart()");
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        Log.d(TAG,"onRestart()");
    }

    @Override
    protected void onResume() {
        super.onResume();
        Log.d(TAG,"onResume()");
    }

    @Override
    protected void onStop() {
        super.onStop();
        Log.d(TAG,"onStop()");
    }

    @Override
    protected void onPause() {
        super.onPause();
        Log.d(TAG,"onPause()");
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Log.d(TAG,"onDestroy()");
    }
}
