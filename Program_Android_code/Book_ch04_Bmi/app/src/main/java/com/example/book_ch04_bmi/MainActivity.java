package com.example.book_ch04_bmi;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private EditText edWeight;
    private EditText edHeight;
    private Button bDescription;
    private EditText edWeight1;
    private Button bHelp;


    public void bmi(View v){
        String w = edWeight.getText().toString();
        String h = edHeight.getText().toString();
        float weight = Float.parseFloat(w);
        float height = Float.parseFloat(h);
        float bmi = weight/(height*height);
        Log.d("Bmi",String.valueOf(bmi));//除錯工具
        Toast.makeText(this,String.valueOf(bmi),Toast.LENGTH_LONG).show();

        //Intent 轉換 Activity
        Intent intent = new Intent(this,ResultActivity.class);
        intent.putExtra("BMI_EXTRA",bmi);
        startActivity(intent);


        //對話框按鈕
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setMessage(bmi + "");
        builder.setTitle("BMI運算");
        //按鈕OK
        builder.setPositiveButton("OK",null);
        //按鈕Cancel
        builder.setNegativeButton("Cancel",null);
        builder.show();











    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        edWeight = (EditText) findViewById(R.id.editText_weight);
        //findViewById 可以用先前畫面上的元件設定ID值取得元件
        //Ctrl+Alt+F 快速把區域變數>>>>類別屬性
        edHeight = (EditText) findViewById(R.id.editText_hight);
        bDescription = (Button)findViewById(R.id.button_help);

        //按鈕事件處理
        bHelp = (Button)findViewById(R.id.button_help);
        bHelp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new AlertDialog.Builder(MainActivity.this)
                        .setTitle("BMI說明")
                        .setMessage("體重(Kg)/身高的平方(m)")
                        .setPositiveButton("OK",null)
                        .show();
            }
        });

    }





}
