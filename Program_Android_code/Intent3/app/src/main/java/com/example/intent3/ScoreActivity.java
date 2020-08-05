package com.example.intent3;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class ScoreActivity extends AppCompatActivity {
    private Context context;
    private EditText editTextName, editTextID, editTextMath, editTextEng;
    private TextView textViewResult;

    private Button buttonOK, buttonCancel;
    private  String message;
    private  Intent intent;
    private final int ReturnScore=20;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_score);

        context = this;
        editTextName = (EditText) findViewById(R.id.editText_nameScore);
        editTextID = (EditText) findViewById(R.id.editText_idScore);
        editTextMath = (EditText) findViewById(R.id.editText_math);
        editTextEng = (EditText) findViewById(R.id.editText_english);

        textViewResult = (TextView) findViewById(R.id.textView_score);
        buttonCancel = (Button) findViewById(R.id.button_cancelScore);
        buttonOK = (Button) findViewById(R.id.button_okScore);

        buttonCancel.setOnClickListener(new MyButton());
        buttonOK.setOnClickListener(new MyButton());
    }

    private class MyButton implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (v.getId()) {
                case R.id.button_cancelScore:
                    editTextName.setText("");
                    editTextID.setText("");
                    editTextEng.setText("");
                    editTextMath.setText("");
                    break;
                case R.id.button_okScore:
                    String name = editTextName.getText().toString();
                    String id = editTextID.getText().toString();
                    String math = editTextMath.getText().toString();
                    String english = editTextEng.getText().toString();

                    Log.d("main", "math=" + math);
                    Log.d("main", "english=" + english);

                    if (name.length() == 0 || id.length() == 0) {
                        Toast.makeText(context, "Please input your name and id.",
                                Toast.LENGTH_SHORT).show();
                    } else {
                        if (math.length() == 0) {
                            Toast.makeText(context, "Please input math.score.",
                                    Toast.LENGTH_SHORT).show();
                            math = "0";
                        }
                        if (english.length() == 0)
                            english = "0";
                        int sum = Integer.parseInt(math) + Integer.parseInt(english);
                        Log.d("main", "sum,=" + sum);

                        textViewResult.setText("name: " + name + "\n");
                        textViewResult.append("ID: " + id + "\n");
                        textViewResult.append("math=" + math + ", english=" + english + "\n");
                        textViewResult.append("The sum=" + sum);

                        message=textViewResult.getText().toString();
                        intent =new Intent();
                        intent.putExtra("scoremessage",message);
                        setResult(ReturnScore,intent);

                        showDialog_2();
                    }
                    break;
            }
        }
    }//MyButton
    private void showDialog_2(){
        AlertDialog.Builder builder =new AlertDialog.Builder(context);
        builder.setIcon(R.drawable.information);
        builder.setTitle("Score Information");
        builder.setMessage(message);
        builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                finish();
                dialog.dismiss();
            }
        });

        builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                dialog.dismiss();
            }
        });
        builder.create().show();
    }
}

