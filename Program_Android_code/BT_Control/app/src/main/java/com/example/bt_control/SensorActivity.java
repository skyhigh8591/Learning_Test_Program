package com.example.bt_control;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Context;
import android.content.Intent;
import android.content.Loader;
import android.content.pm.ActivityInfo;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import java.text.CollationElementIterator;
import java.util.Timer;
import java.util.TimerTask;

public class SensorActivity extends AppCompatActivity {

    private Context context;

    private final String Car_Forward = "f";
    private final String Car_Backward = "b";
    private final String Car_Left = "l";
    private final String Car_Right = "r";
    private final String Car_Stop = "p";
    private String btData;
    private TextView textViewBT;
    private BluetoothAdapter btAdapter;
    private BTChatService myChatService;
    private String btMacAddress;
    private static final String TAG = "sensor";
    private BluetoothDevice remoteDevice;
    private TextView textViewSensor;
    private ImageView imageViewTop, imageViewLeft, imageViewRight;
    private ImageView imageViewDown;
    private boolean startFlag;
    private String directionCmd;
    private ImageButton imageButtonStart;
    private SensorManager sm;
    private Sensor sensor;
    private MyACCListener accListener;
    private boolean delayFlag;
    private Timer timer;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sensor);

        context = this;
        setTitle("Sensor control");
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);

        Intent intent = getIntent();
        btData = intent.getStringExtra("btdata");

        textViewBT = (TextView) findViewById(R.id.textView_sensorBT);
        textViewBT.setText(btData);

        btAdapter = BluetoothAdapter.getDefaultAdapter();
        myChatService = new BTChatService(context, myHandler);

        textViewSensor = (TextView) findViewById(R.id.textView_sensor);
        textViewSensor.setText("");

        imageViewTop = (ImageView) findViewById(R.id.imageView_sensorTop);
        imageViewDown = (ImageView) findViewById(R.id.imageView_sensorDown);
        imageViewLeft = (ImageView) findViewById(R.id.imageView_sensorLeft);
        imageViewRight = (ImageView) findViewById(R.id.imageView_sensorRight);

        imageViewDown.setVisibility(View.INVISIBLE);
        imageViewTop.setVisibility(View.INVISIBLE);
        imageViewLeft.setVisibility(View.INVISIBLE);
        imageViewRight.setVisibility(View.INVISIBLE);

        startFlag = false;
        directionCmd = Car_Stop;

        imageButtonStart = (ImageButton) findViewById(R.id.imageButton_sensorStop);
        imageButtonStart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (startFlag) {
                    startFlag = false;
                    imageButtonStart.setImageResource(R.drawable.ok);
                    directionCmd = Car_Stop;
                    sendCMD(directionCmd);
                    imageViewDown.setVisibility(View.INVISIBLE);
                    imageViewTop.setVisibility(View.INVISIBLE);
                    imageViewLeft.setVisibility(View.INVISIBLE);
                    imageViewRight.setVisibility(View.INVISIBLE);
                } else {
                    startFlag = true;
                    imageButtonStart.setImageResource(R.drawable.stop_icon);
                }
            }
        });

        delayFlag = false;
        timer = new Timer();
        timer.schedule(new TimerTask() {
            @Override
            public void run() {
                if (startFlag) {
                    delayFlag = true;
                    Log.d(TAG, "delayFlag=" + delayFlag);
                }
            }
        }, 0, 300);         //300 ms

        //通過 SensorManager 來獲取 Sensor 資料
        //為 sensor 宣告
        sm = (SensorManager) getSystemService(SENSOR_SERVICE);
        //sensor 設定加速度感測器
        sensor = sm.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        //建立 class 實作介面 SensorEventListener
        accListener = new MyACCListener();
        //為 sensor 註冊 listener，設定獲取 sensor 資料的速度為標準延遲
        sm.registerListener(accListener, sensor, SensorManager.SENSOR_DELAY_NORMAL);

    } //onCreate

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        super.onCreateOptionsMenu(menu);
        getMenuInflater().inflate(R.menu.sensor_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()) {

            case R.id.sensor_menu:
                if (btData != null) {
                    Toast.makeText(context, "Linking with BT", Toast.LENGTH_SHORT).show();
                    btMacAddress = btData.substring(btData.length() - 17);
                    Log.d(TAG, "btMacAddress=" + btMacAddress);
                    remoteDevice = btAdapter.getRemoteDevice(btMacAddress);
                    myChatService.connect(remoteDevice);
                }
                break;

        }
        return super.onOptionsItemSelected(item);
    }

    private final Handler myHandler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            switch (msg.what) {
                case (Constants.MESSAGE_READ):           //手機收(讀)到資料
                    byte[] data = (byte[]) msg.obj;
                    String dataString = new String(data, 0, msg.arg1);
                    //textViewData.append(dataString);
                    break;
                case (Constants.MESSAGE_DEVICE_NAME):   //與 bluetooth 連線
                    String btName = msg.getData().getString(Constants.DEVICE_NAME);
                    Toast.makeText(context, "Link with " + btName, Toast.LENGTH_SHORT).show();
                    break;
                case (Constants.MESSAGE_TOAST):         //無法與 bluetooth 連線
                    String errMsg = msg.getData().getString(Constants.TOAST);
                    Toast.makeText(context, errMsg, Toast.LENGTH_SHORT).show();  //unable to connect device
                    break;
            }
        }
    };

    //手機送出資料
    private void sendCMD(String message) {
        int btState = myChatService.getState();

        if (btState == BTChatService.STATE_CONNECTED) {
            if (message.length() > 0) {
                byte[] data = message.getBytes();
                myChatService.BTWrite(data);
            }
        }
    }

    //關閉 bluetooth 物件
    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (myChatService != null) {
            myChatService.stop();
            myChatService = null;
        }
    }
    //實作介面 SensorEventListener
    private class MyACCListener implements SensorEventListener {
        @Override
        public void onSensorChanged(SensorEvent event) {
            StringBuilder sb = new StringBuilder();
            if (startFlag && delayFlag) {
                float xValue = event.values[0];
                float yValue = event.values[1];
                float zValue = event.values[2];
                textViewSensor.setText("");
                textViewSensor.append("X value=" + xValue + "\n");
                textViewSensor.append("Y value=" + yValue + "\n");
                textViewSensor.append("Z value=" + zValue + "\n");

                if (zValue > 8.0) {
                    imageViewTop.setVisibility(View.VISIBLE);
                    imageViewDown.setVisibility(View.INVISIBLE);
                    imageViewRight.setVisibility(View.INVISIBLE);
                    imageViewLeft.setVisibility(View.INVISIBLE);
                    directionCmd = Car_Forward;
                    sendCMD(directionCmd);

                } else if (zValue < 1.0) {
                    imageViewTop.setVisibility(View.INVISIBLE);
                    imageViewDown.setVisibility(View.VISIBLE);
                    imageViewRight.setVisibility(View.INVISIBLE);
                    imageViewLeft.setVisibility(View.INVISIBLE);
                    directionCmd = Car_Backward;
                    sendCMD(directionCmd);
                } else {
                    if (yValue > 3.0) {
                        imageViewTop.setVisibility(View.INVISIBLE);
                        imageViewDown.setVisibility(View.INVISIBLE);
                        imageViewRight.setVisibility(View.VISIBLE);
                        imageViewLeft.setVisibility(View.INVISIBLE);
                        directionCmd = Car_Right;
                        sendCMD(directionCmd);

                    } else if (yValue < -3.0) {
                        imageViewTop.setVisibility(View.INVISIBLE);
                        imageViewDown.setVisibility(View.INVISIBLE);
                        imageViewRight.setVisibility(View.INVISIBLE);
                        imageViewLeft.setVisibility(View.VISIBLE);
                        directionCmd = Car_Left;
                        sendCMD(directionCmd);
                    } else {
                        imageViewTop.setVisibility(View.INVISIBLE);
                        imageViewDown.setVisibility(View.INVISIBLE);
                        imageViewRight.setVisibility(View.INVISIBLE);
                        imageViewLeft.setVisibility(View.INVISIBLE);
                    }
                }
                delayFlag=false;
            }
        }
        @Override
        public void onAccuracyChanged(Sensor sensor, int accuracy) {

        }
    }
}






