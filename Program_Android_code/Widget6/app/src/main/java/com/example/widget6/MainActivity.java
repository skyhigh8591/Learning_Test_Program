package com.example.widget6;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Context;
import android.nfc.Tag;
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

public class MainActivity extends AppCompatActivity {

    private EditText editTextId;
    private EditText editTextName;
    private TextView textViewResult;
    private RadioGroup radioGroupSex;
    private static  final String TAG = "main";
    private boolean maleFlag,femaleFlag;
    private Context context;

    private boolean sportFlag,readingFlag,paintingFalg;
    private CheckBox checkBoxSport;
    private CheckBox checkBoxReading;
    private CheckBox checkBoxPainting;
    private Button buttonCancel,buttonOK;

    @SuppressLint("WrongViewCast")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        context = this;

        editTextName = (EditText)findViewById(R.id.editText_name);
        editTextId = (EditText)findViewById(R.id.editText_id);

        textViewResult = (TextView)findViewById(R.id.textView_result);
        textViewResult.setText("");

        maleFlag = false;
        femaleFlag = false;

        radioGroupSex = (RadioGroup)findViewById(R.id.radioGroup_id);
        radioGroupSex.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                switch (checkedId)
                {
                    case R.id.radioButton_male:
                        Log.d(TAG,"male");
                        maleFlag = true;
                        femaleFlag = false;
                        break;

                    case R.id.radioButton_female:
                        Log.d(TAG,"female");
                        maleFlag = false;
                        femaleFlag = true;
                        break;
                }
            }
        });

        sportFlag = false;
        readingFlag = false;
        paintingFalg = false;

        checkBoxSport = (CheckBox)findViewById(R.id.checkBox_sport);
        checkBoxSport.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {

                sportFlag = isChecked;
                Log.d(TAG,"sportFlag = " + sportFlag);
            }
        });

        checkBoxReading = (CheckBox)findViewById(R.id.checkBox_reading);
        checkBoxReading.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {

                readingFlag = isChecked;
                Log.d(TAG,"readingFlag = " + readingFlag);
            }
        });

        checkBoxPainting = (CheckBox)findViewById(R.id.checkBox_painting);
        checkBoxPainting.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {

                paintingFalg = isChecked;
                Log.d(TAG,"paintingFalg = " + paintingFalg);
            }
        });
        buttonCancel = (Button)findViewById((R.id.button_cancel));
        buttonOK = (Button)findViewById(R.id.button_OK);
        buttonCancel.setOnClickListener(new MyButton());
        buttonOK.setOnClickListener(new MyButton());

    }

    private class MyButton implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (v.getId()){
                case R.id.button_cancel:
                    editTextId.setText("");
                    editTextName.setText("");
                    radioGroupSex.clearCheck();
                    checkBoxSport.setChecked(false);
                    checkBoxPainting.setChecked(false);
                    checkBoxReading.setChecked(false);
                    maleFlag = false;
                    femaleFlag = false;
                    sportFlag = false;
                    paintingFalg = false;
                    textViewResult.setText("");
                    break;
                case R.id.button_OK:
                    if(editTextName.length()==0||editTextId.length()==0){
                        Toast.makeText(context,"Please input name and id",Toast.LENGTH_SHORT).show();

                    }else{
                        String data = "Name : " + editTextName.getText().toString() + " , ID :" + editTextId.getText().toString() + "\n";
                        textViewResult.setText(data);

                        if(maleFlag){
                            textViewResult.append("Sex : male \n");
                        }else if (femaleFlag){
                            textViewResult.append("Sex : Female\n");
                        } else{
                            Toast.makeText(context,"Please select sex",Toast.LENGTH_SHORT).show();
                        }

                        textViewResult.append("Hobby");
                        if(sportFlag){
                            textViewResult.append("Sport , ");
                        }
                        if(readingFlag){
                            textViewResult.append("Reading , ");
                        }
                        if (paintingFalg){
                            textViewResult.append("Painting");
                        }
                }
                    break;
            }
        }
    }
}
