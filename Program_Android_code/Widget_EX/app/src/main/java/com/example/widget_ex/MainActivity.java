package com.example.widget_ex;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private ImageButton imageButton1,imageButton2,imageButton3,imageButton4,
                        imageButton5,imageButton6,imageButton7,imageButton8;

    private ImageView imageView1;

    private TextView textView1;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        imageButton1 = (ImageButton)findViewById(R.id.imageButton_1);
        imageButton2 = (ImageButton)findViewById(R.id.imageButton_2);
        imageButton3 = (ImageButton)findViewById(R.id.imageButton_3);
        imageButton4 = (ImageButton)findViewById(R.id.imageButton_4);
        imageButton5 = (ImageButton)findViewById(R.id.imageButton_5);
        imageButton6 = (ImageButton)findViewById(R.id.imageButton_6);
        imageButton7 = (ImageButton)findViewById(R.id.imageButton_7);
        imageButton8 = (ImageButton)findViewById(R.id.imageButton_8);

        imageView1 = (ImageView)findViewById(R.id.imageView_1);
        imageView1.setVisibility(View.INVISIBLE);

        textView1 = (TextView)findViewById(R.id.textView_1);
        textView1.setText("");

        imageButton1.setOnClickListener(new MyClick());
        imageButton2.setOnClickListener(new MyClick());
        imageButton3.setOnClickListener(new MyClick());
        imageButton4.setOnClickListener(new MyClick());
        imageButton5.setOnClickListener(new MyClick());
        imageButton6.setOnClickListener(new MyClick());
        imageButton7.setOnClickListener(new MyClick());
        imageButton8.setOnClickListener(new MyClick());

    }
    private class MyClick implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (v.getId())
            {
                case R.id.imageButton_1:
                    imageView1.setVisibility(View.VISIBLE);
                    imageView1.setImageResource(R.drawable.a);
                    textView1.setText("布偶貓是家貓的一個品種，擁有柔軟而修長的毛，需要經常梳理、清洗以防止打結，因性子溫順、抱起來就好像柔軟的布偶一般而得名。");
                    break;
                case R.id.imageButton_2:
                    imageView1.setVisibility(View.VISIBLE);
                    imageView1.setImageResource(R.drawable.b);
                    textView1.setText("英國短毛貓，恬靜、溫馴，易於相處。看似泰迪熊。英國短毛貓是主人的良伴，易於適應城市或鄉村的生活（在鄉村有它們天性愛好的捕獵的機會）。");
                    break;
                case R.id.imageButton_3:
                    imageView1.setVisibility(View.VISIBLE);
                    imageView1.setImageResource(R.drawable.c);
                    textView1.setText("埃及貓，中型短毛貓品種。是唯一天然豹紋的家貓。埃及貓的皮膚和毛色上都有像豹的斑紋。");
                    break;
                case R.id.imageButton_4:
                    imageView1.setVisibility(View.VISIBLE);
                    imageView1.setImageResource(R.drawable.d);
                    textView1.setText("挪威森林貓，好動活潑，勇敢，幾乎是唯一一種從高處面向地面俯沖而下，仍毫無懼色的貓，喜歡小孩，性格溫順。");
                    break;
                case R.id.imageButton_5:
                    imageView1.setVisibility(View.VISIBLE);
                    imageView1.setImageResource(R.drawable.e);
                    textView1.setText("曼切堪貓又叫短腿貓或臘腸貓，有著極短四肢的小矮貓。不擅於爬或跳等動作，且只適於室內生活，但性格異常的好動、喜歡奔跑。 ");
                    break;
                case R.id.imageButton_6:
                    imageView1.setVisibility(View.VISIBLE);
                    imageView1.setImageResource(R.drawable.f);
                    textView1.setText("熱帶草原貓由於是非洲山貓的後代，承接著父系的血統，全身均有亮麗的斑紋，它們的四肢肌肉發達，再加上其流線外型，全身均散發著野性的味道");
                    break;
                case R.id.imageButton_7:
                    imageView1.setVisibility(View.VISIBLE);
                    imageView1.setImageResource(R.drawable.g);
                    textView1.setText("緬因貓是美國貓種當中數量最多的種群，除了其聰穎與活潑廣為人知以外，其獨一無二巨大的體型也令人過目難忘。");
                    break;
                case R.id.imageButton_8:
                    imageView1.setVisibility(View.VISIBLE);
                    imageView1.setImageResource(R.drawable.h);
                    textView1.setText("蘇格蘭摺耳貓是一種耳朵有基因突變的貓。這種貓在軟骨部份有一個摺，使耳朵向前屈摺，並指向頭的前方。");
                    break;

            }

        }
    }
}
