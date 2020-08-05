package com.example.bt_control;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.PersistableBundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;


public class MainActivity extends AppCompatActivity {

    private final int BT_REQUEST_CODE = 100;
    private final int HomeControl = 1;
    private final int CarControl = 2;
    private final int SensorControl = 3;
    private static int mode=1;
    private Context context;
    private ListView listViewBT;
    private BluetoothAdapter btAdapter;
    private Intent intent;
    private Set<BluetoothDevice> btDeviceList;
    private List<String> btNameList;
    private ArrayAdapter<String> adapter;
    private String itemData;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //mode = HomeControl; mode 非 static 手機轉向時，onCreate會再次執行
        context = this;

        listViewBT = (ListView) findViewById(R.id.listView_id);

        //初始化 bluetooth 需 setup BluetoothAdapter
        btAdapter = BluetoothAdapter.getDefaultAdapter();
        if (btAdapter == null) {
            Toast.makeText(context, "No BT hardware", Toast.LENGTH_SHORT).show();
            finish();
        } else if (!btAdapter.isEnabled()) {
            intent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);          //隱性 intent
            startActivityForResult(intent, BT_REQUEST_CODE);
        }
    }
    //
    @Override
    protected void onResume() {
        super.onResume();
        btDeviceList = btAdapter.getBondedDevices();
        //資料取出放 list
        btNameList = new ArrayList<String>();
        if (btDeviceList.size() > 0) {
            for (BluetoothDevice device : btDeviceList) {
                String message = device.getName() + "\n" + device.getAddress();
                btNameList.add(message);
            }
            //產生 ArrayAdapter 並設定
            adapter = new ArrayAdapter<String>(context, android.R.layout.simple_list_item_1, btNameList);
            listViewBT.setAdapter(adapter);
        }

        listViewBT.setOnItemClickListener((new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                itemData =parent.getItemAtPosition(position).toString();
                if (mode==HomeControl){
                    intent=new Intent(context,HomeActivity.class);
                    intent.putExtra("btdata",itemData);       //使用intent類別的方法 putExtra 傳遞資料
                    startActivity(intent);
                }else if (mode==CarControl){
                    intent=new Intent(context,CarActivity.class);
                    intent.putExtra("btdata",itemData);
                    startActivity(intent);
                }else if (mode==SensorControl){
                    intent=new Intent(context,SensorActivity.class);
                    intent.putExtra("btdata",itemData);
                    startActivity(intent);
                }

            }
        }));


    }
    //建立選單
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        super.onCreateOptionsMenu(menu);
        getMenuInflater().inflate(R.menu.setup, menu);
        return true;
    }
    //取得點選項目
    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {

        switch (item.getItemId()) {
            case R.id.menu_homeControl:
                mode = HomeControl;
                break;
            case R.id.menu_carControl:
                mode = CarControl;
                break;
            case R.id.menu_sensorControl:
                mode = SensorControl;
                break;
        }
        Log.d("main", "mode=" + mode);
        return super.onOptionsItemSelected(item);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == BT_REQUEST_CODE) {
            if (resultCode == RESULT_CANCELED) {
                Toast.makeText(context, "User refuses to enable BT", Toast.LENGTH_SHORT).show();
                finish();

            } else if (resultCode == RESULT_OK) {
                Toast.makeText(context, "BT is enabled", Toast.LENGTH_SHORT).show();
            }
        }
    }
}
