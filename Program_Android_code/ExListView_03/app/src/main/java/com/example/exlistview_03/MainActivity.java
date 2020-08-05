package com.example.exlistview_03;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    String [] Balls = new String[] {"籃球","足球","棒球","其他"};
    private Context context;
    private Button btnDO;
    private TextView txtResult;
    private ListView istPrefer;
    private int count;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        context = this;

        btnDO = (Button)findViewById(R.id.btnDo);
        txtResult = (TextView)findViewById(R.id.txtResult);
        istPrefer = (ListView)findViewById(R.id.lstPrefer);

        ArrayAdapter<String> adapterBalls = new ArrayAdapter<String>(
                context,
                android.R.layout.simple_list_item_multiple_choice,
                Balls);

        istPrefer.setChoiceMode(ListView.CHOICE_MODE_MULTIPLE);

        count = adapterBalls.getCount();

        istPrefer.setAdapter(adapterBalls);

        btnDO.setOnClickListener(new btnDOListener());

        istPrefer.setOnItemClickListener(new lstpreferLisrener());

    }

    private class btnDOListener implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            String selAll = " ";
            for (int p = 0 ; p < count ; p++){
                if(istPrefer.isItemChecked(p)){
                    selAll += Balls[p] + " ";
                }
            }
            txtResult.setText("我最喜歡的球類運動是 :" + selAll);
        }
    }

    private class lstpreferLisrener implements android.widget.AdapterView.OnItemClickListener {
        @Override
        public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

            String sel = parent.getItemAtPosition(position).toString();
            if(istPrefer.isItemChecked(position)){
                setTitle("目前選擇 :" + sel);
            }else{
                setTitle("取消選擇 :" + sel);
            }

        }
    }
}
