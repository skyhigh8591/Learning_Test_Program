package com.example.intent_ex02;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class RegisterActivity extends AppCompatActivity {

    private EditText editname, editemail, editphone;
    private Button buttonOK, buttonCancel;
    private Context context;
    private Intent intent;
    private String message;
    private  int reCode = 10;
    private String TAG = "main";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);
        context = this;

        editname = (EditText) findViewById(R.id.editText_name);
        editemail = (EditText) findViewById(R.id.editText_email);
        editphone = (EditText) findViewById(R.id.editText_phone1);

        buttonOK = (Button) findViewById(R.id.button_okRegister);
        buttonCancel = (Button) findViewById(R.id.button_CancelRegister);

        buttonOK.setOnClickListener(new MyButton());
        buttonCancel.setOnClickListener(new MyButton());


    }

    private class MyButton implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (v.getId()){
                case R.id.button_CancelRegister:
                    editname.setText("");
                    editemail.setText("");
                    editphone.setText("");
                    break;
                case R.id.button_okRegister:
                    String nameRegister = editname.getText().toString();
                    String emailRegister = editemail.getText().toString();
                    String phoneRegister = editphone.getText().toString();
                    Log.d("main", "phoneRegister=" + emailRegister);
                   if(nameRegister.length()==0){
                       Toast.makeText(context,"Please input name.",Toast.LENGTH_LONG).show();
                   }else
                       if(emailRegister.length()==0){
                       Toast.makeText(context,"Please input email.",Toast.LENGTH_SHORT).show();
                   }else if(phoneRegister.length()==0){
                       Toast.makeText(context,"Please input phone.",Toast.LENGTH_SHORT).show();
                   }else{
                       intent = new Intent();
                       message = nameRegister+"\n"+ emailRegister + "\n" +  phoneRegister + "\n" ;
                       intent.putExtra("re",message);
                       setResult(reCode,intent);
                       finish();
                   }
                    break;

            }

        }
    }
}
