package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TextView textViewText1;
    private TextView textViewText2;
    private TextView textViewText3;
    private Button button1;
    private Button button2;
    private Button button3;
    private TextView textViewTitle;
    private Button buttonOK;
    private Button buttonCancel;
    private TextView textViewTitle2;
    private boolean button1Flag;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setTitle("APP2");
        int i = 1;
        textViewText1 = (TextView)findViewById(R.id.textView_1);
        textViewText1.setText("TextView 1 is changed !");

        textViewText2 = (TextView)findViewById(R.id.textView_2);
        textViewText2.setText("Hello word!!");

        textViewText3 = (TextView)findViewById(R.id.textView_3);
        textViewText3.setText("OLOLOLOLOL");

        button1=(Button) findViewById(R.id.button_1);

//        button1.setOnClickListener(new View.OnClickListener(){
//            @Override
//            public void onClick(View v){
//                textViewText1.setText("Button 1 is pressed");
//                textViewText2.setText("Button 1 is running");
//            }
//
//        });

        button2=(Button) findViewById(R.id.button_2);

//        button2.setOnClickListener(new View.OnClickListener(){
//            @Override
//            public void onClick(View v){
//                textViewText1.setText("Button 2 is pressed");
//                textViewText2.setText("Button 2 is playing");
//            }
//
//        });

        button3=(Button) findViewById(R.id.button_3);


//        button3.setOnClickListener(new View.OnClickListener(){
//            @Override
//            public void onClick(View v){
//                textViewText1.setText("Button 3 is fly");
//                textViewText2.setText("Button 3 is GO");
//            }
//
//        });

        boolean button1Flag = true;
        button1.setOnClickListener(new MyClick2());
        button2.setOnClickListener(new MyClick2());
        button3.setOnClickListener(new MyClick2());

        textViewTitle = (TextView)findViewById(R.id.textView_text1);
        textViewTitle2 = (TextView)findViewById(R.id.textView_test2);

        buttonOK = (Button)findViewById(R.id.button_ok);
        buttonCancel = (Button)findViewById(R.id.button_cancel);

        buttonOK.setOnClickListener(new MyClick());
        buttonCancel.setOnClickListener(new MyClick());








    }

    private class MyButton implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            textViewTitle.setText("Button OK is pressed.");
        }
    }

    private class MyButton2 implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            textViewTitle.setText("ButtonCancel is ready");
        }
    }

    private class MyClick2 implements  View.OnClickListener{

        @Override
        public void onClick(View v) {
            switch (v.getId()){
                case R.id.button_1:
                    if(button1Flag){
                        textViewText1.setText("Button 1 is fly");
                        textViewText2.setText("Button 1 is fly");
                        button1Flag = false;
                        break;
                    }
                    else{
                        textViewText1.setText("Button 1 is GO");
                        textViewText2.setText("Button 1 is GO");
                        button1Flag = true;
                        break;
                    }




                case R.id.button_2:
                    if(button1Flag){
                        textViewText1.setText("Button 2 is fly");
                        textViewText2.setText("Button 2 is fly");
                        button1Flag = false;
                        break;
                    }
                    else{
                        textViewText1.setText("Button 2 is GO");
                        textViewText2.setText("Button 2 is GO");
                        button1Flag = true;
                        break;
                    }


                case R.id.button_3:
                    if(button1Flag){
                        textViewText1.setText("Button 3 is fly");
                        textViewText2.setText("Button 3 is fly");
                        button1Flag = false;
                        break;
                    }
                    else{
                        textViewText1.setText("Button 3 is GO");
                        textViewText2.setText("Button 3 is GO");
                        button1Flag = true;
                        break;
                    }



            }

        }
    }


    private class MyClick implements  View.OnClickListener{

        @Override
        public void onClick(View v) {
            switch (v.getId()){
                case R.id.button_ok:
                    textViewTitle.setText("Button OK is pressed.");
                    break;

                case R.id.button_cancel:
                    textViewTitle.setText("ButtonCancel is ready");
                    break;



            }

        }
    }
}
