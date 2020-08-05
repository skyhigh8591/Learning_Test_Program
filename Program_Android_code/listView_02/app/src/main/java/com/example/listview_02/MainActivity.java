package com.example.listview_02;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Spinner;
import android.widget.Toast;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private Context context;
    private Spinner spinnerCity;
    private ListView listViewCode;
    private ArrayAdapter<CharSequence> spinnerAdapter;
    private String[] code;
    private List<String> codeList;
    private ArrayAdapter<String> listViewAdapter;
    private int[] codeTable = {R.array.taipei_code,R.array.hsinchu_code,R.array.taichung_code};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        context = this;

        spinnerCity = (Spinner)findViewById(R.id.spinner_city);
        listViewCode = (ListView)findViewById(R.id.listView_id);

        spinnerAdapter = ArrayAdapter.createFromResource(context,R.array.city,android.R.layout.simple_spinner_item);
        spinnerAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinnerCity.setAdapter(spinnerAdapter);

        code = getResources().getStringArray(R.array.taipei_code);
        codeList = new ArrayList<String>(Arrays.asList(code));

        listViewAdapter = new ArrayAdapter<String>(context,android.R.layout.simple_expandable_list_item_1);
        listViewCode.setAdapter(listViewAdapter);

        spinnerCity.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                code = getResources().getStringArray(codeTable[position]);
                codeList = new ArrayList<String>(Arrays.asList(code));

                listViewAdapter.clear();
                listViewAdapter.addAll(codeList);
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });

        listViewCode.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
               String data = parent.getItemAtPosition(position).toString();
                Toast.makeText(context,data,Toast.LENGTH_SHORT).show();
            }
        });

    }
}
