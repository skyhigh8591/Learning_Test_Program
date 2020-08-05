package com.example.sensorcontrol;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.hardware.Sensor;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.GridView;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private Context context;
    private ListView textViewSensor;
    private SensorManager sensorManager;
    private List<Sensor> sensorList;
    private List<String> sensorName;
    private ArrayAdapter<String> adapter;
    private ListView listViewSensor;
    private Sensor sensor;
    private Intent intent;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        context = this;

        listViewSensor = (ListView) findViewById(R.id.listView_id);
        sensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);

        sensorList = sensorManager.getSensorList(Sensor.TYPE_ALL);
        //放在 list上
        sensorName = new ArrayList<String>();

        for (Sensor sensorItem : sensorList) {
            String message = sensorItem.getType() + "-" + sensorItem.getName() + ":"
                    + sensorItem.getPower() + "mA\n" + sensorItem.getVendor();
            Log.d("main", "sensor=" + message);

            sensorName.add(message);
        }

        adapter = new ArrayAdapter<String>(context, android.R.layout.simple_list_item_1, sensorName);
        listViewSensor.setAdapter(adapter);

        setTitle("Sensor number:" + sensorName.size());


        listViewSensor.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

                Sensor item = sensorList.get(position);
                int sensorID=item.getType();
                Log.d("main", "SensorID=" + sensorID);
                switch (sensorID){
                    case Sensor.TYPE_PROXIMITY:
                        sensor =sensorManager.getDefaultSensor( Sensor.TYPE_PROXIMITY);

                        if (sensor==null){
                            Toast.makeText(context, "No Proximity", Toast.LENGTH_SHORT).show();
                        }else {
                            intent  =new Intent( context,ProximityActivity.class);
                            startActivity(intent);
                        }
                        break;
                    case Sensor.TYPE_LIGHT:
                        sensor = sensorManager.getDefaultSensor(Sensor.TYPE_LIGHT);
                        if(sensor ==null){
                            Toast.makeText(context,"no light sensor",Toast.LENGTH_SHORT).show();
                        }else{
                            intent = new Intent(context,LightActivity.class);
                            startActivity(intent);
                        }

                        break;
                    case Sensor.TYPE_ACCELEROMETER:
                        sensor = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
                        if(sensor == null){
                            Toast.makeText(context,"no ACC sensor",Toast.LENGTH_SHORT).show();
                        }else{
                            intent = new Intent(context,ACCActivity.class);
                            startActivity(intent);
                        }
                        break;

                }


            }
        });

    }
}
