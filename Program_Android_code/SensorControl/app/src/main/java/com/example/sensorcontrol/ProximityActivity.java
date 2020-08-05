package com.example.sensorcontrol;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.util.Log;
import android.widget.ImageView;
import android.widget.TextView;

public class ProximityActivity extends AppCompatActivity {

    private Context context;
    private TextView textViewPro;
    private ImageView imageViewPro;
    private SensorManager sensorManager;
    private Sensor sensor;
    private MyProximityListener sensorListener;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_proximity);

        context =this;

        textViewPro =(TextView) findViewById(R.id.textView_proximity);
        textViewPro.setText("");

        imageViewPro =(ImageView) findViewById(R.id.imageView_proximity);

        sensorManager =(SensorManager) getSystemService(SENSOR_SERVICE);
        sensor =sensorManager.getDefaultSensor(Sensor.TYPE_PROXIMITY);
        sensorListener =new MyProximityListener();
        sensorManager.registerListener(sensorListener,sensor,sensorManager.SENSOR_DELAY_NORMAL);




    }

    private class MyProximityListener implements SensorEventListener {


        @Override
        public void onSensorChanged(SensorEvent event) {
            Log.d("pro","sensor change");
            StringBuilder sb = new StringBuilder();
            sb.append("sensor:" + event.sensor.getName()+"\n");
           float proxValue = event.values[0];
           sb.append("proximity value =" + proxValue + "cm\n");
           textViewPro.setText(sb.toString());

           if(proxValue < 1){
               imageViewPro.setImageResource(R.drawable.p2);
               textViewPro.append("Too close!!!");
           }else{
               imageViewPro.setImageResource(R.drawable.p1);
           }


        }

        @Override
        public void onAccuracyChanged(Sensor sensor, int accuracy) {

        }
    }

    @Override
    protected void onDestroy() {
        sensorManager.unregisterListener(sensorListener);
        super.onDestroy();
    }
}
