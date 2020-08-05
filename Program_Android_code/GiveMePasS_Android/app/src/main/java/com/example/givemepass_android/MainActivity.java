package com.example.givemepass_android;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity<setOnKeyListener> extends AppCompatActivity {

    private EditText inputText;
    private ListView listInput;
    private ArrayAdapter<String> adapter;
    private ArrayList<String> items;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        inputText = (EditText)findViewById(R.id.inputText);
        listInput = (ListView)findViewById(R.id.listInputText);
        items = new ArrayList<>();
        adapter = new ArrayAdapter(this,android.R.layout.simple_list_item_1,items);
        listInput.setAdapter(adapter);

//        listInput.setOnItemClickListener(new AdapterView.OnItemClickListener() {
//            @Override
//            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
//                final int pos = position;
//                new AlertDialog.Builder(MainActivity.this)
//                        .setTitle("刪除列")
//                        .setMessage("你確定要刪除？")
//                        .setPositiveButton("是", new DialogInterface.OnClickListener() {
//
//                            @Override
//                            public void onClick(DialogInterface dialog, int which) {
//                                items.remove(pos);
//                                listInput.setAdapter(adapter);
//                            }
//                        })
//                        .setNegativeButton("否", new DialogInterface.OnClickListener() {
//
//                            @Override
//                            public void onClick(DialogInterface dialog, int which) {
//
//                            }
//                        })
//                        .show();
//            }
//        });

        listInput.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> arg0, View view, int position, long id) {
                final int pos = position;
                new AlertDialog.Builder(MainActivity.this)
                        .setTitle("刪除列")
                        .setMessage("你確定要刪除？")
                        .setPositiveButton("是", new DialogInterface.OnClickListener() {

                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                items.remove(pos);
                                listInput.setAdapter(adapter);
                            }
                        })
                        .setNegativeButton("否", new DialogInterface.OnClickListener() {

                            @Override
                            public void onClick(DialogInterface dialog, int which) {

                            }
                        })
                        .show();

                return false;
            }

        });

        inputText.setOnEditorActionListener(new TextView.OnEditorActionListener() {
            @Override
            public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {
                if(!inputText.getText().toString().equals("")){
                    items.add(inputText.getText().toString());
                    listInput.setAdapter(adapter);
                    inputText.setText("");
                }
                return false;
            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        menu.add(Menu.NONE, Menu.FIRST , Menu.NONE, "離開程式");
        return super.onCreateOptionsMenu(menu);
    }



    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case Menu.FIRST :
                new AlertDialog.Builder(MainActivity.this)
                        .setTitle("離開此程式")
                        .setMessage("你確定要離開？")
                        .setPositiveButton("是", new DialogInterface.OnClickListener() {

                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                finish();
                            }
                        })
                        .setNegativeButton("否", new DialogInterface.OnClickListener() {

                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                            }
                        })
                        .show();
                break;
        }
        return super.onOptionsItemSelected(item);
    }


}
