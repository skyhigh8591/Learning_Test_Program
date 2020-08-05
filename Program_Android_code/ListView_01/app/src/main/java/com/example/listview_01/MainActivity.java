package com.example.listview_01;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Spinner;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private Context context;
    private Spinner spinnerCity;
    private ListView listViewFood;
    private ArrayAdapter<CharSequence> spinnerAdaper;
    private String cityMessage;
    private String[] foodData;
    private String foodMessage;
    private int foodIndes;
    private Intent intent;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        context = this;

        spinnerCity = (Spinner)findViewById(R.id.spinner_id);
        listViewFood = (ListView)findViewById(R.id.listView_id);

        //spinnerAdaper = ArrayAdapter.createFromResource(context,R.array.city,android.R.layout.simple_spinner_item);
        spinnerAdaper = ArrayAdapter.createFromResource(context,R.array.city,R.layout.simple_spinner_item);
        spinnerAdaper.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinnerCity.setAdapter(spinnerAdaper);

        spinnerCity.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                cityMessage = parent.getItemAtPosition(position).toString();
                Toast.makeText(context,cityMessage,Toast.LENGTH_SHORT).show();

            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });

        foodData = getResources().getStringArray(R.array.fastfood);
        //ArrayAdapter<String> listViewAsapter = new ArrayAdapter<String>(context,android.R.layout.simple_expandable_list_item_1,foodData);
        ArrayAdapter<String> listViewAsapter = new ArrayAdapter<String>(context,R.layout.simple_expandable_list_item_1,foodData);
        listViewFood.setAdapter(listViewAsapter);

        listViewFood.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                foodMessage = parent.getItemAtPosition(position).toString();
                foodIndes = position;
                       Toast.makeText(context,foodMessage+foodIndes,Toast.LENGTH_SHORT).show();

                       dialogShow();
            }
        });
    }

    private void dialogShow() {
        AlertDialog.Builder builder = new AlertDialog.Builder(context);
        builder.setTitle("Select Drink");
        builder.setMessage(foodMessage);

        builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                intent = new Intent(context,DisplayActivity.class);
                intent.putExtra("city",cityMessage);
                intent.putExtra("food",foodMessage);
                intent.putExtra("index",foodIndes);
                startActivity(intent);
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
