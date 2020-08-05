package com.example.widget_ex;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "";
    private Button button1;
    private Button button2;
    private Button button3;
    private TextView testView1;
    private TextView testView2;
    private TextView testView3;
    private Context context;
    private ImageButton imageButton1,imageButton2,imageButton3,imageButton4,imageButton5,imageButton6;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        context=this;

        button1 = (Button)findViewById(R.id.button_1);
        button2 = (Button)findViewById(R.id.button_2);
        button3 = (Button)findViewById(R.id.button_3);

        testView1 = (TextView)findViewById(R.id.textView_1);
        testView2 = (TextView)findViewById(R.id.textView_2);
        testView3 = (TextView)findViewById(R.id.textView_3);

        testView1.setTextSize(20);
        testView2.setTextSize(20);
        testView3.setTextSize(20);

        testView1.setTextColor(0xFF000088);
        testView2.setTextColor(ContextCompat.getColor(context,android.R.color.holo_blue_bright));
        testView3.setTextColor(ContextCompat.getColor(context,R.color.myColor_1));

        testView1.setText("");
        testView2.setText("");
        testView3.setText((""));

        button1.setOnClickListener(new MyClass());
        button2.setOnClickListener(new MyClass());
        button3.setOnClickListener(new MyClass());

        imageButton1=(ImageButton)findViewById(R.id.imageButton);
        imageButton2=(ImageButton)findViewById(R.id.imageButton2);
        imageButton3=(ImageButton)findViewById(R.id.imageButton3);
        imageButton4=(ImageButton)findViewById(R.id.imageButton4);
        imageButton5=(ImageButton)findViewById(R.id.imageButton5);
        imageButton6=(ImageButton)findViewById(R.id.imageButton6);

        imageButton1.setOnClickListener(new MyClick());
        imageButton2.setOnClickListener(new MyClick());
        imageButton3.setOnClickListener(new MyClick());
        imageButton4.setOnClickListener(new MyClick());
        imageButton5.setOnClickListener(new MyClick());
        imageButton6.setOnClickListener(new MyClick());


    }
    private class MyClass implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (v.getId())
            {
                case R.id.button_1:
                    testView1.setText("Button1 is pressed.");
                    testView2.setText("");
                    testView3.setText("");
                    break;

                case R.id.button_2:
                    String message = getResources().getString(R.string.myString_1);
                    Log.d(TAG,"message = " + message);
                    testView2.setText(message);
                    testView1.setText("");
                    testView3.setText("");
                    break;

                case R.id.button_3:
                    testView3.setText(getResources().getString(R.string.myString_2));
                    testView1.setText("");
                    testView2.setText("");
                    break;

            }

        }
    }

    private class MyClick implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (v.getId()){
                case R.id.imageButton:
                    Toast.makeText(context,"ImageButton 1 is pressed.",Toast.LENGTH_LONG).show();
                    break;

                case R.id.imageButton2:
                    Toast.makeText(context,"ImageButton 2 is pressed.",Toast.LENGTH_LONG).show();
                    break;

                case R.id.imageButton3:
                    Toast.makeText(context,"ImageButton 3 is pressed.",Toast.LENGTH_LONG).show();
                    break;

                case R.id.imageButton4:
                    Toast.makeText(context,"ImageButton 4 is pressed.",Toast.LENGTH_LONG).show();
                    break;

                case R.id.imageButton5:
                    Toast.makeText(context,"ImageButton 5 is pressed.",Toast.LENGTH_LONG).show();
                    break;

                case R.id.imageButton6:
                    Toast.makeText(context,"ImageButton 6 is pressed.",Toast.LENGTH_LONG).show();
                    break;

            }
        }
    }
}
