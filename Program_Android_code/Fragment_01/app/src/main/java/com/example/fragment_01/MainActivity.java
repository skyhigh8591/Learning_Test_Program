package com.example.fragment_01;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {
    private static final String TAG = "main";
    private TextView textViewMain,buttonMain;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.d(TAG, "onCreate()-F");
        textViewMain = (TextView)findViewById(R.id.textView_main);
        buttonMain = (Button)findViewById(R.id.button_main);
        buttonMain.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textViewMain.setText("Button main is pressed");
            }
        });




    }

    @Override
    public void onStart() {
        super.onStart();
        Log.d(TAG, "onStart()-F");
    }

    @Override
    public void onResume() {
        super.onResume();
        Log.d(TAG, "onResume()-F");
    }

    @Override
    public void onPause() {
        super.onPause();
        Log.d(TAG, "onPause()-F");

    }

    @Override
    public void onStop() {
        super.onStop();
        Log.d(TAG, "onStop()-F");
    }



    @Override
    public void onDestroy() {
        super.onDestroy();
        Log.d(TAG, "onDestroy()-F");
    }


}
