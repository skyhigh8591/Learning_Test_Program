package com.example.listview_ex;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MainActivity extends AppCompatActivity {

    private Context context;
    private ListView listViewCat;
    private List<Map<String, Object>> itemList;
    private int[] cat_image = {R.drawable.a, R.drawable.b, R.drawable.c,
            R.drawable.d, R.drawable.e, R.drawable.f, R.drawable.g, R.drawable.h};
    private String message;
    private Intent intent;
    private String cat_name,cat_description;
    private int catimage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        context = this;
        listViewCat = (ListView) findViewById(R.id.listView_id);

        Map<String, Object> cocaLight = new HashMap<>();
        cocaLight.put("name", "布偶貓");
        cocaLight.put("description", "布偶貓是家貓的一個品種，擁有柔軟而修長的毛，需要經常梳理、清洗以防止打結，因性子溫順、抱起來就好像柔軟的布偶一般而得名。");
        cocaLight.put("image", R.drawable.a);

        itemList = new ArrayList<>();
        itemList.add(cocaLight);

        String[] catName = getResources().getStringArray(R.array.cat_name);
        String[] catDescription = getResources().getStringArray(R.array.cat_description);

        for (int i = 1; i < catName.length; i++) {
            Map<String, Object> data = new HashMap<>();
            data.put("name", catName[i]);
            data.put("description", catDescription[i]);
            data.put("image", cat_image[i]);

            itemList.add(data);
        }

        SimpleAdapter adapter = new SimpleAdapter(context, itemList, R.layout.item_layout,
                new String[]{"name", "image"},
                new int[]{R.id.textView_name, R.id.imageView_id});
        listViewCat.setAdapter(adapter);


        listViewCat.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Map<String, Object> item = (Map<String, Object>) parent.getItemAtPosition(position);
                String name = (String) item.get("name");
                String description = (String) item.get("description");

                Toast.makeText(context, "You select:" + name, Toast.LENGTH_SHORT).show();

                message="你是否選擇"+name;
                cat_name = name ;
                cat_description = description;
                catimage = position;
                showDialog_2();


            }
        });
    }

    private void showDialog_2() {
        AlertDialog.Builder builder = new AlertDialog.Builder(context);
        builder.setIcon(R.drawable.report3);
        builder.setTitle("You select Cat");
        builder.setMessage(message);
        builder.setPositiveButton("Yes", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                intent = new Intent(context,catDescriptionActivity.class);
                intent.putExtra("name",cat_name);
                intent.putExtra("description",cat_description);
                intent.putExtra("image",catimage);
                startActivity(intent);
                dialog.dismiss();
            }
        });

        builder.setNegativeButton("No", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                dialog.dismiss();
            }
        });
        builder.create().show();
    }
}
