package com.example.exlistview_01;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private Context context;
    String[] Balls = new String[]{"basketball", "soccer", "baseball", "籃球", "足球", "棒球", "其他"};
    private ListView lstPrefer;
    private TextView txtResult;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        context = this;
        txtResult = (TextView) findViewById(R.id.textView_Result);
        lstPrefer = (ListView) findViewById(R.id.lstPrefer);


        ArrayAdapter<String> adapterBalls = new ArrayAdapter<String>(
                context,
                android.R.layout.simple_list_item_multiple_choice,
                Balls);

        lstPrefer.setAdapter(adapterBalls);
        lstPrefer.setOnItemClickListener(lstPreferListener);

        lstPrefer.setTextFilterEnabled(true);
        lstPrefer.setSelector(R.drawable.green);

    }

    private ListView.OnItemClickListener lstPreferListener =
            new ListView.OnItemClickListener() {
                @Override
                public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                    // 顯示 ListView 的選項內容
                    String sel = parent.getItemAtPosition(position).toString();
                    txtResult.setText("我最喜歡的球類運動是 : " + sel);
                }
            };
}
