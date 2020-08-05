package com.example.menu1;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ImageView;
import android.widget.Switch;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private Context context;
    private TextView textViewTitle, textViewReturn;
    private int currentColor, newColor;
    private boolean colorFlag, pictureFlag;
    private ImageView imageViewPicture;
    private final int ChangePicture = 1;
    private final int ChangeColor = 2;
    private final int SelectInfo = 3;
    private Intent intent;
    private final int InfoRequestCode = 100;
    private final int ReturnInfo = 10;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        context = this;
        textViewTitle = (TextView) findViewById(R.id.textView_title);
        currentColor = textViewTitle.getCurrentTextColor();
        newColor = 0xff800080;
        colorFlag = true;
        pictureFlag = true;
        imageViewPicture = (ImageView) findViewById(R.id.imageView_id);
        textViewReturn = (TextView) findViewById(R.id.textView_return);
        textViewReturn.setText("");
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        super.onCreateOptionsMenu(menu);

        menu.add(1, ChangePicture, Menu.NONE, "Change Picture");
        menu.add(1, ChangeColor, Menu.NONE, "Change Color");
        menu.add(1, SelectInfo, Menu.NONE, "Select Info");
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        Log.d("main", "item id=" + item.getItemId());

        switch (item.getItemId()) {
            case ChangePicture:
                if (pictureFlag) {
                    imageViewPicture.setImageResource(R.drawable.steak);
                    textViewTitle.setText("You select Steak.");
                    pictureFlag = false;
                } else {
                    imageViewPicture.setImageResource(R.drawable.soup);
                    textViewTitle.setText("You select Soup.");
                    pictureFlag = true;
                }
                break;
            case ChangeColor:
                if (colorFlag) {
                    textViewTitle.setTextColor(newColor);
                    colorFlag = false;
                } else {
                    textViewTitle.setTextColor(currentColor);
                    colorFlag = true;
                }
                break;
            case SelectInfo:
                intent = new Intent(context, InfoActivity.class);
                startActivityForResult(intent, InfoRequestCode);
                break;
        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == InfoRequestCode) {
            if (resultCode == ReturnInfo) {
                String message =data.getStringExtra("inputdata");
                textViewReturn.setText(message);
            }
        }
    }
}
