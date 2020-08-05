package com.example.intent_ex02;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private Button buttonRegister,buttonOrder;
    private Context context;
    private TextView ruturnintent;
    private int RegisterCode = 100;
    private int OrderCode = 200;
    private  int reCode = 10;
    private  int OrCode=20;
    private String message;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

     context = this;
     buttonRegister = (Button)findViewById(R.id.button_Register);
     buttonOrder = (Button)findViewById(R.id.button_order);

     ruturnintent = (TextView)findViewById(R.id.textView_ex);
     ruturnintent.setText("");


     buttonRegister.setOnClickListener(new View.OnClickListener() {
         @Override
         public void onClick(View v) {
             Intent intent = new Intent(context,RegisterActivity.class);
             startActivityForResult(intent , RegisterCode);
         }
     });

     buttonOrder.setOnClickListener(new View.OnClickListener() {
         @Override
         public void onClick(View v) {
             Intent intent = new Intent(context,OrderActivity.class);
             startActivityForResult(intent,OrderCode);
         }
     });

    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
            super.onActivityResult(requestCode, resultCode, data);

        if(requestCode == RegisterCode){
            if(resultCode == reCode){
                message = data.getStringExtra("re");
                ruturnintent.setText(message);
            }
        }else if(requestCode == OrderCode){
            if(resultCode == OrCode){
                message = data.getStringExtra("Or");
                ruturnintent.setText(message);
            }

        }




    }
}
