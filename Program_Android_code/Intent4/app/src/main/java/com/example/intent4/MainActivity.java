package com.example.intent4;

import androidx.appcompat.app.AppCompatActivity;

import android.app.SearchManager;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private Context context;
    private EditText editTextInput;
    private Button buttonClean;
    private ImageButton imageButtonPhone, imageButtonEmail, imageButtonHttp, imageButtonSearch;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        context = this;

        editTextInput = (EditText) findViewById(R.id.editText_input);

        buttonClean = (Button) findViewById(R.id.button_clear);
        buttonClean.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                editTextInput.setText("");
            }
        });

        imageButtonPhone = (ImageButton) findViewById(R.id.imageButton_phone);
        imageButtonEmail = (ImageButton) findViewById(R.id.imageButton_email);
        imageButtonHttp = (ImageButton) findViewById(R.id.imageButton_http);
        imageButtonSearch = (ImageButton) findViewById(R.id.imageButton_search);

        imageButtonEmail.setOnClickListener(new MyButton());
        imageButtonHttp.setOnClickListener(new MyButton());
        imageButtonPhone.setOnClickListener(new MyButton());
        imageButtonSearch.setOnClickListener(new MyButton());

    }

    private class MyButton implements View.OnClickListener {
        private String action;
        private String data;
        private Uri uri;
        private Intent intent;

        @Override
        public void onClick(View v) {

            if(editTextInput.length()==0){
                Toast.makeText(context,"Please input data.",Toast.LENGTH_SHORT).show();
            }
            else {

                data = editTextInput.getText().toString();
                switch (v.getId()) {
                    case R.id.imageButton_phone:
                        action = Intent.ACTION_DIAL;
                        uri = Uri.parse("tel:"+data);
                        Log.d("main","uri="+uri);
                        intent = new Intent(action,uri);
                        startActivity(intent);
                        break;

                    case R.id.imageButton_email:
                        action = Intent.ACTION_SENDTO;
                        uri = Uri.parse("mailto:"+data);
                        Log.d("main","uri="+uri);
                        intent = new Intent(action,uri);
                        startActivity(intent);
                        break;

                    case R.id.imageButton_http:
                        action = Intent.ACTION_VIEW;
                        uri=Uri.parse("http:"+data);
                        Log.d("main","uri="+uri);
                        intent = new Intent(action,uri);
                        startActivity(intent);
                        break;

                    case R.id.imageButton_search:
                        action = Intent.ACTION_WEB_SEARCH;
                        intent = new Intent(action);
                        intent.putExtra(SearchManager.QUERY,data);
                        startActivity(intent);
                        break;
                }
            }
        }
    }
}
