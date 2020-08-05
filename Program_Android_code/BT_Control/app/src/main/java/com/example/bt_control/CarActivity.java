package com.example.bt_control;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.ImageButton;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

public class CarActivity extends AppCompatActivity {

    private final String Song_off = "0";
    private final String Song_1 = "1";
    private final String Song_2 = "2";
    private final String Song_3 = "3";
    private final String Song_4 = "4";
    private final String Song_5 = "5";
    private String songCmd;
    private Context context;
    private String btData;
    private BluetoothAdapter btAdapter;
    private BTChatService myChatService;
    private TextView textViewBt;
    private String btMacAddress;
    private static final String TAG = "home";
    //private static final String TAG = "adc";
    private BluetoothDevice remoteDevice;
    private Button buttonLink;
    private  final  String Car_Forward="f";
    private  final  String Car_Backward="b";
    private  final  String Car_Left="l";
    private  final  String Car_Right="r";
    private  final  String Car_Stop="p";
    private ImageButton imageButtonTop,imageButtonDown,imageButtonRight,imageButtonLeft,imageButtonStop;
    private String carCmd;


    private  final String ADC_on="v";
    private  final  String ADC_off="z";
    private Switch switchADC;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_car);

        context = this;
        setTitle("Car control");
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);

        Intent intent = getIntent();
        btData = intent.getStringExtra("btdata");

        textViewBt =(TextView) findViewById(R.id.textView_carBT);
        textViewBt.setText(btData);

        btAdapter = BluetoothAdapter.getDefaultAdapter();
        myChatService = new BTChatService(context, myHandler);

        if (btData != null) {
            Toast.makeText(context, "Linking with BT", Toast.LENGTH_SHORT).show();
            btMacAddress = btData.substring(btData.length() - 17);
            Log.d(TAG, "btMacAddress=" + btMacAddress);
            remoteDevice = btAdapter.getRemoteDevice(btMacAddress);
            myChatService.connect(remoteDevice);
        }

        buttonLink =(Button) findViewById(R.id.button_carLink);
        buttonLink.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                remoteDevice=btAdapter.getRemoteDevice(btMacAddress);
                myChatService.connect(remoteDevice);
            }
        });

        imageButtonTop=(ImageButton) findViewById(R.id.imageButton_carTop);
        imageButtonDown=(ImageButton) findViewById(R.id.imageButton_carDown);
        imageButtonRight=(ImageButton) findViewById(R.id.imageButton_carRight);
        imageButtonLeft=(ImageButton) findViewById(R.id.imageButton_carLeft);
        imageButtonStop=(ImageButton) findViewById(R.id.imageButton_carStop);

        imageButtonTop.setOnClickListener(new MyButton());
        imageButtonDown.setOnClickListener(new MyButton());
        imageButtonLeft.setOnClickListener(new MyButton());
        imageButtonRight.setOnClickListener(new MyButton());
        imageButtonStop.setOnClickListener(new MyButton());

        switchADC =(Switch) findViewById(R.id.switch_adcEnable);
        switchADC.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (isChecked){
                    sendCMD((ADC_on));
                    Log.d(TAG,"ADC_on");
                }else{
                    sendCMD(ADC_off);
                    Log.d(TAG,"ADC_off");
                }
            }
        });

    }

    //建立選單
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        super.onCreateOptionsMenu(menu);
        getMenuInflater().inflate(R.menu.car_menu, menu);
        return true;
    }

    //取得點選項目
    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {

        switch (item.getItemId()) {
            case R.id.car_songoff:
                songCmd = Song_off;
                Toast.makeText(context, "Select : Song off", Toast.LENGTH_SHORT).show();
                sendCMD(songCmd);
                break;
            case R.id.car_song1:
                songCmd = Song_1;
                Toast.makeText(context, "Select : Song_1", Toast.LENGTH_SHORT).show();
                sendCMD(songCmd);
                break;
            case R.id.car_song2:
                songCmd = Song_2;
                Toast.makeText(context, "Select : Song_2", Toast.LENGTH_SHORT).show();
                sendCMD(songCmd);
                break;
            case R.id.car_song3:
                songCmd = Song_3;
                Toast.makeText(context, "Select : Song_3", Toast.LENGTH_SHORT).show();
                sendCMD(songCmd);
                break;
            case R.id.car_song4:
                songCmd = Song_4;
                Toast.makeText(context, "Select : Song_4", Toast.LENGTH_SHORT).show();
                sendCMD(songCmd);
                break;
            case R.id.car_song5:
                songCmd = Song_5;
                Toast.makeText(context, "Select : Song_5", Toast.LENGTH_SHORT).show();
                sendCMD(songCmd);
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

    //
    protected void onDestroy() {
        super.onDestroy();
        if (myChatService != null) {
            myChatService.stop();
            myChatService = null;
        }
    }
    //for imageButtom
    private class MyButton implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (v.getId()){
                case R.id.imageButton_carDown:
                    carCmd=Car_Backward;
                    sendCMD(carCmd);
                    break;
                case R.id.imageButton_carTop:
                    carCmd=Car_Forward;
                    sendCMD(carCmd);
                    break;
                case R.id.imageButton_carLeft:
                    carCmd=Car_Left;
                    sendCMD(carCmd);
                    break;
                case R.id.imageButton_carRight:
                    carCmd=Car_Right;
                    sendCMD(carCmd);
                    break;
                case R.id.imageButton_carStop:
                    carCmd=Car_Stop;
                    sendCMD(carCmd);
                    break;
            }
        }
    }
}//CarActivity


