package com.example.intent1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.text.DecimalFormat;
import java.text.NumberFormat;

public class BMIActivity extends AppCompatActivity {

    private static final String TAG = "main";
    private TextView textViewBMI;
    private Intent intent;
    private Intent returnIntent;
    private final int ReturnData = 10;
    private final int ReturnError = 20;
    private Button buttonBack;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_bmi);

        setTitle("BMI");

        textViewBMI = (TextView)findViewById(R.id.textView_BMI);
        textViewBMI.setText("");

        intent = getIntent();

        String name = intent.getStringExtra("name");
        Log.d(TAG,"bmi_name =" +name);

        String age = intent.getStringExtra("age");
        Log.d(TAG,"bmi_age"+age);

        int height = intent.getIntExtra("height",1);
        int weight = intent.getIntExtra("weight",1);
        Log.d(TAG,"bmi_height =" +height);
        Log.d(TAG,"weight =" +weight);

        if(height > 250){
            Log.d(TAG,"height > 250");
            returnIntent = new Intent();
            returnIntent.putExtra("bmierror","You height is worng.");
            setResult(ReturnError,returnIntent);
            finish();
        }
        double bmiValue = (weight * 100 * 100) / (height * height);

        Log.d(TAG,"bmiValue =" + bmiValue);

        NumberFormat nf = new DecimalFormat("##.00");
        String bmiString = nf.format(bmiValue);
        Log.d(TAG,"bmiString = "+ bmiString);

        textViewBMI.setText("Name :"+name+" ,age :"+age+"\n\n");
        textViewBMI.append("height ="+height+" ,weight ="+weight+"\n\n");
        textViewBMI.append("BMI ="+bmiString+"\n\n");

        String message = getBMIMessage(bmiValue);
        textViewBMI.append(message);

        returnIntent = new Intent();
        returnIntent.putExtra("bmirecord",message);
        returnIntent.putExtra("bmivalue",bmiString);
        setResult(ReturnData,returnIntent);

        buttonBack = (Button)findViewById(R.id.button_back);
        buttonBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });

    }

    private String getBMIMessage(double bmiValue) {

        String message = null;

        if(bmiValue<20){
            message = "BMI value is too low";
        }else if(bmiValue>=20 && bmiValue<26){
            message="BMI value is standard";
        }else if(bmiValue>=26 && bmiValue<30){
            message = "BMI value is high";
        }else{
            message="BMI value is error";
        }
        return message;
    }
}
