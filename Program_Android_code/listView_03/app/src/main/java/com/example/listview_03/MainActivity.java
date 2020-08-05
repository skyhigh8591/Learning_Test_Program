package com.example.listview_03;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
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
    private ListView listViewFood;
    private List<Map<String,Object>> itemList;
    private int[] food_image = {R.drawable.coca_cola,R.drawable.coca_cola_light,R.drawable.coca_cola_zero,
                                R.drawable.french_fries,R.drawable.hamburger,R.drawable.kfc_small};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        context = this;
        listViewFood = (ListView)findViewById(R.id.listView_id);

        Map<String,Object> cocaLight = new HashMap<>();
        cocaLight.put("name","Coca Light");
        cocaLight.put("price",40);
        cocaLight.put("image",R.drawable.coca_cola_light);

        itemList = new ArrayList<>();
        itemList.add(cocaLight);

        String[] foodName = getResources().getStringArray(R.array.food_name);
        int[] foodPrice = getResources().getIntArray(R.array.food_price);

        for(int i = 1 ; i < foodName.length ; i++){
            Map<String,Object> data = new HashMap<>();
            data.put("name",foodName[i]);
            data.put("price",foodPrice[i]);
            data.put("image",food_image[i]);

            itemList.add(data);
        }

        SimpleAdapter adapter = new SimpleAdapter(context, itemList, R.layout.item_layout,
                new String[]{"name", "price", "image"},
                new int[]{R.id.textView_name, R.id.textView_price, R.id.imageView_id});
        listViewFood.setAdapter(adapter);


        listViewFood.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Map<String,Object> item = (Map<String, Object>) parent.getItemAtPosition(position);

                String name = (String) item.get("name");
                int price = (int) item.get("price");
                Toast.makeText(context,"You select:"+name+", price =" + price , Toast.LENGTH_SHORT).show();


            }
        });
    }
}
