package com.example.widget5;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

public class MainActivity extends AppCompatActivity {

    private EditText editTextName,editTextDate,editTextInput;
    private TextView textViewResult;
    private Button buttonCancel,buttonOK;
    private Context context;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        context = this;

        editTextName = (EditText)findViewById(R.id.editText_name);
        editTextDate = (EditText)findViewById(R.id.editText_data);
        editTextInput = (EditText)findViewById(R.id.editText_input);

        textViewResult = (TextView)findViewById(R.id.textView_result);
        textViewResult.setText("");

        buttonCancel = (Button)findViewById(R.id.button_cancel);
        buttonOK = (Button)findViewById(R.id.button_ok);

        buttonCancel.setOnClickListener(new MyButton());
        buttonOK.setOnClickListener(new MyButton());
    }

    private class MyButton implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (v.getId()){
                case R.id.button_cancel:
                    editTextName.setText("");
                    editTextDate.setText("");
                    editTextInput.setText("");
                    textViewResult.setText("");
                    break;

                case R.id.button_ok:
                    String name = editTextName.getText().toString();
                    String date = editTextDate.getText().toString();
                    String data = editTextInput.getText().toString();

                    if(name.length()==0){
                        Toast.makeText(context, "Please input your name",Toast.LENGTH_SHORT).show();

                    }else{
                        textViewResult.setText("Name = " + name + "\n");
                        textViewResult.append("Date : " + date + "\n\n");
                        textViewResult.append(data);
                    }
                    break;
            }
        }
    }
}
