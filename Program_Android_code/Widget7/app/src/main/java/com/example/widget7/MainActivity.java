package com.example.widget7;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private Context context;
    private RadioGroup radioGroupDrink;
    private boolean colaFlage, teaFlag, coffeeFlag;
    private static final String TAG = "main";
    private CheckBox checkBoxWaffle, checkBoxMuffin, checkBoxPancake;
    private boolean waffleFlag, muffinFlag, pancakeFlag;
    private Button buttonCancel, buttonOK;
    private TextView textViewResult;
    private final int colaPrice = 50, teaPrice = 60, coffeePrice = 80;
    private final int wafflePrice = 100, pancakePrice = 120, muffinPruce = 150;
    private int sum;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

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

        buttonCancel = (Button) findViewById(R.id.button_cancel);
        buttonOK = (Button) findViewById(R.id.button_OK);

        buttonCancel.setOnClickListener(new MyButton());
        buttonOK.setOnClickListener(new MyButton());

        textViewResult = (TextView) findViewById(R.id.textView_result);
        textViewResult.setText("");

    }

    private class MyButton implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (v.getId()) {
                case R.id.button_cancel:
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

                    textViewResult.setText("");

                    break;

                case R.id.button_OK:
                    sum = 0;
                    textViewResult.setText("You have ordered :\n");

                    if (colaFlage) {
                        textViewResult.append("cola \n ");
                        sum += colaPrice;
                    } else if (teaFlag) {
                        textViewResult.append("tea \n");
                        sum += teaPrice;
                    } else if (colaFlage) {
                        textViewResult.append("coffee \n");
                        sum += coffeePrice;
                    } else {
                        Toast.makeText(context, "Please select drink.", Toast.LENGTH_SHORT).show();
                    }

                    if (waffleFlag) {
                        textViewResult.append("waffle ");
                        sum += pancakePrice;
                    }
                    if (pancakeFlag) {
                        textViewResult.append("muffin ");
                        sum += muffinPruce;
                    }
                    if (muffinFlag) {
                        textViewResult.append("muffin");
                        sum += muffinPruce;
                    }

                    textViewResult.append("\nThe total fee is :" + sum);

                    break;
            }

        }
    }
}
