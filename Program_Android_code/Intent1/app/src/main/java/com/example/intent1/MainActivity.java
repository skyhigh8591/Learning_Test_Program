package com.example.intent1;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.Toast;

import java.time.Instant;

public class MainActivity extends AppCompatActivity {

    private Context context;
    private ImageButton buttonStart;
    private EditText editTextName,editTextAge,editTextHeight,editTextWeight;
    private static final String TAG = "main";
    private String name;
    private String age;
    private int BMIRequsetCode = 200;
    private TextView textViewResult;
    private final int ReturnData = 10;
    private final int ReturnError = 20;
    private String message;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        context = this;

        editTextName = (EditText)findViewById(R.id.editText_name);
        editTextAge = (EditText)findViewById(R.id.editText_age);
        editTextHeight = (EditText)findViewById(R.id.editText_height);
        editTextWeight = (EditText)findViewById(R.id.editText_weight);

        buttonStart = (ImageButton)findViewById(R.id.imageButton_start);
        buttonStart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

              name = editTextName.getText().toString();
              if(name.length()==0){
                  Toast.makeText(context,"Please input name.",Toast.LENGTH_SHORT).show();
                  name = "";
              }
                Log.d(TAG,"name =" + name);

              age = editTextAge.getText().toString();
              if(age.length()==0){
                  Toast.makeText(context,"Please input age",Toast.LENGTH_SHORT).show();
                  age = "0";
              }
              Log.d(TAG,"age = " + age);

                String height = editTextHeight.getText().toString();
                String weight = editTextWeight.getText().toString();

                if(height.length()==0||weight.length()==0){
                    Toast.makeText(context,"Please input height and weight",Toast.LENGTH_SHORT).show();

                }else{
                    Log.d(TAG,"height =" + height);
                    Log.d(TAG,"weight =" + weight);

                    int heightValue = Integer.parseInt(height);
                    int weighValue = Integer.parseInt(weight);


                    Intent bmiIntent = new Intent(context,BMIActivity.class);

                    bmiIntent.putExtra("name",name);
                    bmiIntent.putExtra("age",age);
                    bmiIntent.putExtra("height",heightValue);
                    bmiIntent.putExtra("weight",weighValue);




//                    startActivity(bmiIntent);
                    startActivityForResult(bmiIntent,BMIRequsetCode);
                }
            }
        });

        textViewResult = (TextView)findViewById(R.id.textView_result);
        textViewResult.setText("");
    }


    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if(requestCode == BMIRequsetCode){
            Log.d(TAG,"requestCode = " + requestCode);
            switch (resultCode){
                case ReturnData:
                    Log.d(TAG,"resultCode Data =" +resultCode);
                    message = data.getStringExtra("bmivalue");
                    textViewResult.setText("bmi value = "+message+"\n");
                    message = data.getStringExtra("bmirecord");
                    textViewResult.append(message);
                    break;

                case ReturnError:
                    Log.d(TAG,"resultCode Error =" +resultCode);
                    message = data.getStringExtra("bmierror");
                    textViewResult.setText(message);
                    break;
            }
        }
    }
}
