package com.example.sensorcontrol;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.pm.ActivityInfo;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;

public class ACCActivity extends AppCompatActivity {

    private Context conext;
    private TextView textViewACC;
    private ImageView imagerViewLeft, imagerViewRight, imagerViewTop, imagerViewDown;
    private ImageButton imagerButtonStop;
    private boolean stopFlag;
    private SensorManager sensorManager;
    private Sensor sensor;
    private MyACCListener accListener;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_acc);

        conext = this;

        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);

        textViewACC = (TextView) findViewById(R.id.textView_acc);
        textViewACC.setText("");

        imagerViewLeft = (ImageView) findViewById(R.id.imageView_sensorLeft);
        imagerViewRight = (ImageView) findViewById(R.id.imageView_sensorRight);
        imagerViewTop = (ImageView) findViewById(R.id.imageView_sensorTop);
        imagerViewDown = (ImageView) findViewById(R.id.imageView_sensorDown);

        imagerViewLeft.setVisibility(View.INVISIBLE);
        imagerViewRight.setVisibility(View.INVISIBLE);
        imagerViewTop.setVisibility(View.INVISIBLE);
        imagerViewDown.setVisibility(View.INVISIBLE);

        imagerButtonStop = (ImageButton) findViewById(R.id.imageButton_sensorStop);
        stopFlag = true;

        imagerButtonStop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (stopFlag) {
                    stopFlag = false;
                    imagerButtonStop.setImageResource(R.drawable.cancel_1);

                } else {
                    stopFlag = true;
                    imagerButtonStop.setImageResource(R.drawable.ok_1);
                    imagerViewRight.setVisibility(View.INVISIBLE);
                    imagerViewLeft.setVisibility(View.INVISIBLE);
                    imagerViewTop.setVisibility(View.INVISIBLE);
                    imagerViewDown.setVisibility(View.INVISIBLE);

                }
            }
        });

        sensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
        sensor = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        accListener = new MyACCListener();
        sensorManager.registerListener(accListener, sensor, SensorManager.SENSOR_DELAY_NORMAL);

    }

    private class MyACCListener implements SensorEventListener {
        @Override
        public void onSensorChanged(SensorEvent event) {
            StringBuilder sb = new StringBuilder();
            sb.append("sensor :" + event.sensor.getName() + "\n");
            textViewACC.setText(sb.toString());
            if (stopFlag == false) {
                float xValue = event.values[0];
                float yValue = event.values[1];
                float zValue = event.values[2];
                textViewACC.append("Xvalue = " + xValue + "\n");
                textViewACC.append("Yvalue = " + yValue + "\n");
                textViewACC.append("Zvalue = " + zValue + "\n");

                if (xValue < -4.0) {
                    imagerViewRight.setVisibility(View.VISIBLE);
                    imagerViewLeft.setVisibility(View.INVISIBLE);
                    imagerViewTop.setVisibility(View.INVISIBLE);
                    imagerViewDown.setVisibility(View.INVISIBLE);
                } else if (xValue > 4.0) {
                    imagerViewLeft.setVisibility(View.VISIBLE);
                    imagerViewRight.setVisibility(View.INVISIBLE);
                    imagerViewTop.setVisibility(View.INVISIBLE);
                    imagerViewDown.setVisibility(View.INVISIBLE);
                } else {
                    if (zValue > 7) {
                        imagerViewTop.setVisibility(View.VISIBLE);
                        imagerViewRight.setVisibility(View.INVISIBLE);
                        imagerViewLeft.setVisibility(View.INVISIBLE);
                        imagerViewDown.setVisibility(View.INVISIBLE);
                    } else if (zValue < 0) {
                        imagerViewDown.setVisibility(View.VISIBLE);
                        imagerViewRight.setVisibility(View.INVISIBLE);
                        imagerViewLeft.setVisibility(View.INVISIBLE);
                        imagerViewTop.setVisibility(View.INVISIBLE);

                    } else {
                        imagerViewRight.setVisibility(View.INVISIBLE);
                        imagerViewLeft.setVisibility(View.INVISIBLE);
                        imagerViewTop.setVisibility(View.INVISIBLE);
                        imagerViewDown.setVisibility(View.INVISIBLE);
                    }
                }
            }
        }

        @Override
        public void onAccuracyChanged(Sensor sensor, int accuracy) {

        }
    }

    protected void onDestroy() {

        
        sensorManager.unregisterListener(accListener);
        super.onDestroy();

    }
}
