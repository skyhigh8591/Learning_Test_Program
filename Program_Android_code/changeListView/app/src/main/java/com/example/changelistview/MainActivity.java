package com.example.changelistview;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;

import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    EditText etSearchbox;
    ListView lvFirst;
    ArrayAdapter<String> adapter1;
    String[] data = {"mehul joisar", "amit mishra", "amitabh", "Aamir khan", "jesica", "katrina"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        etSearchbox = (EditText) findViewById(R.id.etSearchbox);
        lvFirst = (ListView) findViewById(R.id.lvFirst);
        lvFirst.setTextFilterEnabled(true);

        adapter1 = new ArrayAdapter<String>(MainActivity.this, android.R.layout.simple_list_item_1, data);
        lvFirst.setAdapter(adapter1);

        etSearchbox.addTextChangedListener(new TextWatcher() {
            @Override
            public void onTextChanged(CharSequence arg0, int arg1, int arg2, int arg3) {
                // TODO Auto-generated method stub
                MainActivity.this.adapter1.getFilter().filter(arg0);
            }
            @Override
            public void beforeTextChanged(CharSequence arg0, int arg1, int arg2, int arg3) {
                // TODO Auto-generated method stub
            }
            @Override
            public void afterTextChanged(Editable arg0) {
                // TODO Auto-generated method stub
            }
        });
    }
}
