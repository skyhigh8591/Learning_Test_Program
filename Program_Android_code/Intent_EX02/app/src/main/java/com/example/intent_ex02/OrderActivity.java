package com.example.intent_ex02;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
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

public class OrderActivity extends AppCompatActivity {
    private Context context;
    private RadioGroup radioGroupDrink;
    private boolean colaFlage, teaFlag, coffeeFlag;
    private static final String TAG = "main";
    private CheckBox checkBoxWaffle, checkBoxMuffin, checkBoxPancake;
    private boolean waffleFlag, muffinFlag, pancakeFlag;
    private Button buttonCancel, buttonOK;
    private TextView textViewRe;
    private final int colaPrice = 50, teaPrice = 60, coffeePrice = 80;
    private final int wafflePrice = 100, pancakePrice = 120, muffinPruce = 150;
    private int Drink,waffle,pancake,muffin;
    private int sum;
    private EditText DrinkNumber,waffleNumber,pancakeNumber,muffinNumber;
    private String D,w,p,m;
    private String message;
    private Intent intent;
    private  int OrCode=20;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_order);

        waffleNumber = (EditText)findViewById(R.id.editText_waffle);

        pancakeNumber = (EditText)findViewById(R.id.editText_pancake);

        muffinNumber =(EditText)findViewById(R.id.editText_muffin);

        DrinkNumber=(EditText)findViewById(R.id.editText_Drink);

        context = this;

        colaFlage = false;
        teaFlag = false;
        colaFlage = false;

        radioGroupDrink = (RadioGroup) findViewById(R.id.radioGroup_id);
        radioGroupDrink.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                switch (checkedId) {
                    case R.id.radioButton_cola:
                        colaFlage = true;
                        teaFlag = false;
                        coffeeFlag = false;
                        break;
                    case R.id.radioButton_tea:
                        colaFlage = false;
                        teaFlag = true;
                        coffeeFlag = false;
                        break;
                    case R.id.radioButton_coffee:
                        colaFlage = false;
                        teaFlag = false;
                        coffeeFlag = true;
                        break;
                }
                Log.d(TAG, "colaFlag =" + colaFlage);
                Log.d(TAG, "teaFlag =" + teaFlag);
                Log.d(TAG, "coffeeFlag =" + coffeeFlag);
            }
        });
        checkBoxWaffle = (CheckBox) findViewById(R.id.checkBox_waffle);
        checkBoxPancake = (CheckBox) findViewById(R.id.checkBox_pancake);
        checkBoxMuffin = (CheckBox) findViewById(R.id.checkBox_muffin);

        waffleFlag = false;
        pancakeFlag = false;
        muffinFlag = false;

        checkBoxWaffle.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                waffleFlag = isChecked;
                Log.d(TAG, "waffleFlag =" + waffleFlag);
            }
        });

        checkBoxPancake.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                pancakeFlag = isChecked;
                Log.d(TAG, "pancakeFlag =" + pancakeFlag);
            }
        });

        checkBoxMuffin.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                muffinFlag = isChecked;
                Log.d(TAG, "muffinFlag =" + muffinFlag);
            }
        });

        buttonCancel = (Button) findViewById(R.id.button_CancelRegister);
        buttonOK = (Button) findViewById(R.id.button_OKRegister);

        buttonCancel.setOnClickListener(new MyButton());
        buttonOK.setOnClickListener(new MyButton());

        textViewRe = (TextView) findViewById(R.id.textView_or);
        textViewRe.setText("");


    }

    private class MyButton implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (v.getId()) {
                case R.id.button_CancelRegister:
                    radioGroupDrink.clearCheck();
                    colaFlage = false;
                    teaFlag = false;
                    colaFlage = false;

                    checkBoxMuffin.setChecked(false);
                    muffinFlag = false;
                    checkBoxPancake.setChecked(false);
                    pancakeFlag = false;
                    checkBoxWaffle.setChecked(false);
                    waffleFlag = false;

                    textViewRe.setText("");

                    break;

                case R.id.button_OKRegister:
                    sum = 0;
                    textViewRe.setText("You have ordered :\n");

                    if (colaFlage) {
                        D = DrinkNumber.getText().toString();
                        Drink = Integer.parseInt(D);
                        textViewRe.append("cola \n ");
                        sum += colaPrice*Drink;
                    } else if (teaFlag) {
                        D = DrinkNumber.getText().toString();
                        Drink = Integer.parseInt(D);
                        textViewRe.append("tea \n");
                        sum += teaPrice*Drink;
                    } else if (coffeeFlag) {
                        D = DrinkNumber.getText().toString();
                        Drink = Integer.parseInt(D);
                        textViewRe.append("coffee \n");
                        sum += coffeePrice*Drink;
                    } else {
                        Toast.makeText(context, "Please select drink.", Toast.LENGTH_SHORT).show();
                    }

                    if (waffleFlag) {
                        w = waffleNumber.getText().toString();
                        waffle = Integer.parseInt(w);
                        textViewRe.append("waffle ");
                        sum += wafflePrice*waffle;
                    }
                    if (pancakeFlag) {
                        p = pancakeNumber.getText().toString();
                        pancake = Integer.parseInt(p);
                        textViewRe.append("muffin ");
                        sum += pancakePrice*pancake;
                    }
                    if (muffinFlag) {
                        m = muffinNumber.getText().toString();
                        muffin = Integer.parseInt(m);
                        textViewRe.append("muffin");
                        sum += muffinPruce*muffin;
                    }

                    textViewRe.append("\nThe total fee is :" + sum);

                    message=textViewRe.getText().toString();
                    intent =new Intent();
                    intent.putExtra("Or",message);
                    setResult(OrCode,intent);
                    showDialog_2();
                    break;
            }

        }


    }

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

