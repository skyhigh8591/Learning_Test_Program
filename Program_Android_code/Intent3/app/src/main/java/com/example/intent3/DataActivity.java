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
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

public class DataActivity extends AppCompatActivity {
    private EditText editTextName, editTextID;
    private TextView textViewResult;
    private RadioGroup radioGroupSex;
    private static final String TAG = "main";
    private boolean maleFlag, femaleFlag;
    private Context context;
    private CheckBox checkBoxSport, checkBoxReading, checkBoxPainting;
    private boolean sportFlag, readingFlag, paintingFlag;
    private Button buttonOK, buttonCancel;
    private Intent intent;
    private String message;
    private final int ReturnData = 10;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_data);


//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);

        context = this;      // ???

        editTextName = (EditText) findViewById(R.id.editText_nameData);
        editTextID = (EditText) findViewById(R.id.editText_idData);

        textViewResult = (TextView) findViewById(R.id.textView_data);
        textViewResult.setText("");

        radioGroupSex = (RadioGroup) findViewById(R.id.radioGroup_id);
        radioGroupSex.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                switch (checkedId) {
                    case R.id.radioButton_male:
                        Log.d(TAG, "male");
                        maleFlag = true;
                        femaleFlag = false;
                        break;
                    case R.id.radioButton_female:
                        Log.d(TAG, "female");
                        maleFlag = false;
                        femaleFlag = true;
                        break;
                }
            }
        });
        //------------------------------
        sportFlag = false;
        readingFlag = false;
        paintingFlag = false;

        checkBoxSport = (CheckBox) findViewById(R.id.checkBox_sport);
        checkBoxSport.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                sportFlag = isChecked;
                Log.d(TAG, "sportFlag=" + sportFlag);
            }
        });

        checkBoxReading = (CheckBox) findViewById(R.id.checkBox_reading);
        checkBoxReading.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                readingFlag = isChecked;
                Log.d(TAG, "readingFlag=" + readingFlag);
            }
        });

        checkBoxPainting = (CheckBox) findViewById(R.id.checkBox_painting);
        checkBoxPainting.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                paintingFlag = isChecked;
                Log.d(TAG, "paintingFlag=" + paintingFlag);
            }
        });
        //------------------------------------------------
        buttonOK = (Button) findViewById(R.id.button_okData);
        buttonCancel = (Button) findViewById(R.id.button_cancelData);
        buttonOK.setOnClickListener(new MyButton());
        buttonCancel.setOnClickListener(new MyButton());

    }

    private class MyButton implements View.OnClickListener {

        @Override
        public void onClick(View v) {
            switch (v.getId()) {
                case R.id.button_cancelData:
                    editTextName.setText("");
                    editTextID.setText("");
                    radioGroupSex.clearCheck();
                    checkBoxSport.setChecked(false);
                    checkBoxReading.setChecked(false);
                    checkBoxPainting.setChecked(false);

                    maleFlag = false;
                    femaleFlag = false;
                    sportFlag = false;
                    readingFlag = false;
                    paintingFlag = false;
                    textViewResult.setText("");
                    break;
                case R.id.button_okData:
                    if (editTextName.length() == 0 || editTextID.length() == 0) {
                        Toast.makeText(context, "Please input name and id.", Toast.LENGTH_SHORT).show();
                    } else {
                        String data = "Name:" + editTextName.getText().toString() + ", ID:" + editTextID.getText().toString() + "\n";
                        textViewResult.setText(data);

                        if (maleFlag) {
                            textViewResult.append("Sex: Male\n");

                        } else if (femaleFlag) {
                            textViewResult.append("Sex: Female\n");
                        } else {
                            Toast.makeText(context, "Please select  sex.", Toast.LENGTH_SHORT).show();
                        }

                        textViewResult.append("Hobby:");
                        if (sportFlag)
                            textViewResult.append("Sport, ");

                        if (readingFlag)
                            textViewResult.append("Reading,\n");

                        if (paintingFlag)
                            textViewResult.append("Painting,\n");
                    }
                    intent = new Intent();
                    message = textViewResult.getText().toString();
                    intent.putExtra("datamessage", message);
                    setResult(ReturnData, intent);
                    showDialog_1();
                    break;
            }
        }
    }

    private void showDialog_1() {
        AlertDialog.Builder builder = new AlertDialog.Builder(context);
        builder.setIcon(R.drawable.information);
        builder.setTitle("Data Information");
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
