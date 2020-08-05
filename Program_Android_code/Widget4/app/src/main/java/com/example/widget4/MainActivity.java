package com.example.widget4;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.text.Editable;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private Context context;
    private EditText editTextName,editTextID,editTextMath,editTextEng;
    private TextView textViewResult;
    private Button buttonCancel,buttonOK;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        context = this;

        editTextName = (EditText)findViewById(R.id.editText_name);
        editTextID = (EditText)findViewById(R.id.editText_id);
        editTextMath = (EditText)findViewById(R.id.editText_math);
        editTextEng = (EditText)findViewById(R.id.editText_english);

        textViewResult = (TextView)findViewById(R.id.textView_result);

        buttonCancel = (Button)findViewById(R.id.button_cancel);
        buttonOK=(Button)findViewById(R.id.button_ok);

        buttonCancel.setOnClickListener(new Mybutton());
        buttonOK.setOnClickListener(new Mybutton());




    }

    private class Mybutton implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch(v.getId()){
                case R.id.button_cancel:
                    editTextName.setText("");
                    editTextID.setText("");
                    editTextMath.setText("");
                    editTextEng.setText("");
                    textViewResult.setText("");
                    break;

                case R.id.button_ok:
                    String name = editTextName.getText().toString();
                    String id = editTextID.getText().toString();
                    String math = editTextMath.getText().toString();
                    String english = editTextEng.getText().toString();
                    Log.d("main","math = " +math);
                    Log.d("main","english = "+english);

                    if(name.length()== 0 || id.length() == 0){
                        Toast.makeText(context,"Please input your name and id.",Toast.LENGTH_SHORT).show();
                    }else{
                        if(math.length()==0){
                            Toast.makeText(context,"Please input math score.",Toast.LENGTH_SHORT).show();
                            math = "0";
                        }


                        if(english.length()==0)
                            english="0";

                        int sum = Integer.parseInt(math) + Integer.parseInt(english);
                        Log.d("main","sum ="+sum);

                        textViewResult.setText("Name :"+name+"\n");
                        textViewResult.append("ID :"+id+"\n");
                        textViewResult.append("math = "+math+",english =" +english+ "\n");
                        textViewResult.append("The sum =" + sum);

                    }

                    break;
            }

        }
    }
}
