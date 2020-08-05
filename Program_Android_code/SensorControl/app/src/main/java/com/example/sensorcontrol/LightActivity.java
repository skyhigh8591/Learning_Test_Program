package com.example.sensorcontrol;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.app.SearchManager;
import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;

public class LightActivity extends AppCompatActivity {

    private Context context;
    private TextView textViewLight;
    private ImageView imageViewLight;
    private SensorManager sensorManager;
    private Sensor sensor;

    private MylistenerLight listenerLight;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_light);

        context = this;

        textViewLight = (TextView)findViewById(R.id.textView_light);
        textViewLight.setText("");
        imageViewLight = (ImageView)findViewById(R.id.imageView_light);

        sensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
        sensor = sensorManager.getDefaultSensor(Sensor.TYPE_LIGHT);

        listenerLight = new MylistenerLight();
        sensorManager.registerListener(listenerLight,sensor,sensorManager.SENSOR_DELAY_NORMAL);
    }

    private class MylistenerLight implements SensorEventListener {
        @Override
        public void onSensorChanged(SensorEvent event) {

            StringBuilder sb = new StringBuilder();
            sb.append("sensor =" + event.sensor.getName()+"\n");
            float lightValue = event.values[0];
            sb.append("Light  value =" + lightValue + "\n");
            textViewLight.setText(sb.toString());

            if(lightValue < 40){
                imageViewLight.setImageResource(R.drawable.dark_light);
                textViewLight.append("Too dark");
            }else{
                imageViewLight.setImageResource(R.drawable.imageslight);
            }

        }

        @Override
        public void onAccuracyChanged(Sensor sensor, int accuracy) {

        }
    }
}
