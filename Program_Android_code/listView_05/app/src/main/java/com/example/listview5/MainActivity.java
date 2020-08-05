package com.example.listview5;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.GridView;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MainActivity extends AppCompatActivity {

    private Context context;
    private GridView gridViewPicture;
    private TextView twxtViewResult;

    private  int[] image = {R.drawable.butterfly,R.drawable.cat,R.drawable.flower,R.drawable.hippo,R.drawable.monkey,R.drawable.mushroom
    ,R.drawable.panda,R.drawable.rabbit,R.drawable.raccoon};

    private String[] imageName = {"butterfly","cat","flower","hippo","money","mushroom","panda","rabbit","raccon"};


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        context = this;
        gridViewPicture = (GridView)findViewById(R.id.gridView_id);
        twxtViewResult = (TextView)findViewById(R.id.textView_result);
        twxtViewResult.setText("");

        List<Map<String,Object>> itemList = new ArrayList<>();
        for(int i = 0 ; i<image.length ; i++){
            Map<String,Object>data = new HashMap<>();
            data.put("image",image[i]);
            data.put("name",imageName[i]);

            itemList.add(data);
        }

        GridAdapter adapter = new GridAdapter(context, itemList, R.layout.item_layout);
        gridViewPicture.setNumColumns(3);
        gridViewPicture.setAdapter(adapter);

        gridViewPicture.setOnItemClickListener(new AdapterView.OnItemClickListener() {


            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Map<String,Object> item = (Map<String, Object>)parent.getItemAtPosition(position);
                twxtViewResult.setText("You select :" + item.get("name"));
            }
        });

    }
}
