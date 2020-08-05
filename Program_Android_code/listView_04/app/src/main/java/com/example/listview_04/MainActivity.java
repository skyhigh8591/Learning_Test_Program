package com.example.listview_04;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.SimpleAdapter;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MainActivity extends AppCompatActivity {

    private Context context;
    private String[] countryName;
    private String[] countryCode;
    private ListView listViewCounty;
    private List<Map<String, String>> itemList;
    private SimpleAdapter adapter;
    private String message;
    private int itemPosition;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        context = this;

        listViewCounty = (ListView)findViewById(R.id.listView_id);

        countryName = getResources().getStringArray(R.array.country);
        countryCode = getResources().getStringArray(R.array.country_code);

        Log.d("main","countryName =" + countryName);
        Log.d("main","countryCode =" + countryCode);

        itemList = new ArrayList<Map<String, String>>();

        for(int i = 0 ; i<countryName.length ; i++){
            Log.d("main","countryName =" + countryName[i]);
            Log.d("main","countryCode =" + countryCode[i]);

            Map<String,String> data = new HashMap<String, String>();
            data.put("country",countryName[i]);
            data.put("code",countryCode[i]);

            itemList.add(data);

        }

        //adapter = new SimpleAdapter(context,itemList,R.layout.item_layout,new String[]{"country","code"},
        //        new int[]{R.id.textView_name,R.id.textView_code});

        adapter = new SimpleAdapter(context,itemList,R.layout.new_expandable_list_item_2,new String[]
                {"country","code"},new int[]{android.R.id.text1,android.R.id.text2});

        listViewCounty.setAdapter(adapter);

        listViewCounty.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Map<String,String> item = (Map<String, String>) parent.getItemAtPosition(position);

                message = item.get("country")+",country code :"+item.get("code");
                Log.d("main","message =" +message);
                itemPosition = position;
                Log.d("main","item position =" + itemPosition);

                showDialog_delete();
            }
        });

    }

    private void showDialog_delete() {
        AlertDialog.Builder builder = new AlertDialog.Builder(context);
        builder.setTitle("Delete item");
        builder.setIcon(android.R.drawable.ic_menu_delete);
        builder.setMessage("Are you sure to delete item?\n"+message);
        builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                itemList.remove(itemPosition);
                adapter.notifyDataSetChanged();
                dialog.dismiss();
            }
        });

            builder.setNegativeButton("Canael", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                dialog.dismiss();
            }
        });

        builder.create().show();

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        super.onCreateOptionsMenu(menu);
        getMenuInflater().inflate(R.menu.setup,menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        showDialog_add();
        return super.onOptionsItemSelected(item);
    }

    private void showDialog_add() {
        LayoutInflater inflater = getLayoutInflater();
        View dialogView = inflater.inflate(R.layout.dialog_layout, (ViewGroup) findViewById(R.id.dialog_id));

        final EditText editTextName = (EditText) dialogView.findViewById(R.id.editText_name);
        final EditText editTextCode = (EditText) dialogView.findViewById(R.id.editText_code);

        editTextName.setText("");
        editTextCode.setText("");

        AlertDialog.Builder builder = new AlertDialog.Builder(context);
        builder.setTitle("Add item");
        builder.setIcon(android.R.drawable.ic_menu_add);
        builder.setView(dialogView);
        builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                String name = editTextName.getText().toString();
                String code = "+" + editTextCode.getText().toString();

                Map<String,String>data = new HashMap<>();
                data.put("country",name);
                data.put("code",code);
                itemList.add(data);
                adapter.notifyDataSetChanged();
                listViewCounty.setSelection(adapter.getCount()-1);
                dialog.dismiss();
            }
        });
        builder.create().show();

    }
}
