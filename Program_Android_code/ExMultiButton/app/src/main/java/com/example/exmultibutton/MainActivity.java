package com.example.exmultibutton;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private TextView txtshow,btnOne,btnTwo,btnThree,btnFour,btnFives,btnSix,btnSeven,btnEight,btnNine,btnZero,btnClear,btnOK;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txtshow = (TextView)findViewById(R.id.textView_show);

        btnOne = (Button)findViewById(R.id.button1);
        btnTwo = (Button)findViewById(R.id.button2);
        btnThree = (Button)findViewById(R.id.button3);
        btnFour = (Button)findViewById(R.id.button4);
        btnFives = (Button)findViewById(R.id.button5);
        btnSix = (Button)findViewById(R.id.button6);
        btnSeven = (Button)findViewById(R.id.button7);
        btnEight = (Button)findViewById(R.id.button8);
        btnNine = (Button)findViewById(R.id.button9);
        btnZero = (Button)findViewById(R.id.button0);

        btnClear = (Button)findViewById(R.id.button_clear);
        btnOK = (Button)findViewById(R.id.button_OK);

        btnOne.setOnClickListener(new  myLostener());
        btnTwo.setOnClickListener(new myLostener());
        btnThree.setOnClickListener(new myLostener());
        btnFour.setOnClickListener(new myLostener());
        btnFives.setOnClickListener(new myLostener());
        btnSix.setOnClickListener(new myLostener());
        btnSeven.setOnClickListener(new myLostener());
        btnEight.setOnClickListener(new myLostener());
        btnNine.setOnClickListener(new myLostener());
        btnZero.setOnClickListener(new myLostener());
        btnClear.setOnClickListener(new myLostener());
        btnOK.setOnClickListener(new myLostener());







    }

    private class myLostener implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            String s = txtshow.getText().toString();

            switch (v.getId())
            {
                case R.id.button1:
                    txtshow.setText(s + "1");
                    break;
                case R.id.button2:
                    txtshow.setText(s + "2");
                    break;
                case R.id.button3:
                    txtshow.setText(s + "3");
                    break;
                case R.id.button4:
                    txtshow.setText(s + "4");
                    break;
                case R.id.button5:
                    txtshow.setText(s + "5");
                    break;
                case R.id.button6:
                    txtshow.setText(s + "6");
                    break;
                case R.id.button7:
                    txtshow.setText(s + "7");
                    break;
                case R.id.button8:
                    txtshow.setText(s + "8");
                    break;
                case R.id.button9:
                    txtshow.setText(s + "9");
                    break;
                case R.id.button0:
                    txtshow.setText(s + "0");
                    break;
                case R.id.button_clear:
                    txtshow.setText((s = "電話號碼 : ") );
                    break;
                case R.id.button_OK:
                    Toast.makeText(MainActivity.this,s,Toast.LENGTH_SHORT).show();
                    break;
            }

        }
    }
}
