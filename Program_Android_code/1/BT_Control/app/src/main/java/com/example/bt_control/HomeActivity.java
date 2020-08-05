package com.example.bt_control;

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
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.Spinner;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;


public class HomeActivity extends AppCompatActivity {

    private Context context;
    private String btData;
    private TextView textViewBT;
    private Spinner spinnerSong;
    private ArrayAdapter<CharSequence> spinnerAdapter;
    private static final String TAG = "home";
    private String songCmd;
    private final String Song_off = "0";
    private final String Song_1 = "1";
    private final String Song_2 = "2";
    private final String Song_3 = "3";
    private final String Song_4 = "4";
    private final String Song_5 = "5";
    private BluetoothAdapter btAdapter;
    private BTChatService myChatService;
    private String btMacAddress;
    private BluetoothDevice remoteDevice;
    private Button buttonLink;
    private Button buttonPlay;
    private TextView textViewData;

    private  final String Lamp1_ON="x";
    private  final String Lamp1_OFF="y";
    private  final String Lamp2_ON="c";
    private  final String Lamp2_OFF="d";
    private  final String Lamp3_ON="h";
    private  final String Lamp3_OFF="i";
    private  final String Fan1_ON="k";
    private  final String Fan1_OFF="j";
    private  final String Melody_ON="m";
    private  final String Melody_OFF="n";
    private Switch switchLamp1,switchLamp2,switchLamp3,switchFan1,switchMelody;
    private String lampCMD,fan1CMD,melodyCMD;
    private  final String Get_Temp="t";
    private  final String Get_Hum="u";
    private Button buttonTemp,buttonHum;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);

        setTitle("Home Control");
        context = this;

        //強制手機直放顯示
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);

        Intent intent = getIntent();
        btData = intent.getStringExtra("btdata");

        textViewBT = (TextView) findViewById(R.id.textView_homeBT);
        textViewBT.setText(btData);   //bluetooth

        btAdapter = BluetoothAdapter.getDefaultAdapter();

        myChatService = new BTChatService(context, myHandler);

        if (btData != null) {
            Toast.makeText(context,"Linking with BT",Toast.LENGTH_SHORT).show();
            btMacAddress = btData.substring(btData.length() - 17);
            Log.d(TAG, "btMacAddress=" + btMacAddress);
            remoteDevice = btAdapter.getRemoteDevice(btMacAddress);
            myChatService.connect(remoteDevice);
        }

        //手機當 client
        buttonLink = (Button) findViewById(R.id.button_homeLink);
        buttonLink.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(context, "Link with BT again", Toast.LENGTH_SHORT).show();
                if (btMacAddress != null) {
                    Log.d(TAG, "btMacAddress=" + btMacAddress);
                    remoteDevice = btAdapter.getRemoteDevice(btMacAddress);
                    myChatService.connect(remoteDevice);
                } else {
                    Toast.makeText(context, "no MAC address", Toast.LENGTH_SHORT).show();
                }
            }
        });

        spinnerSong = (Spinner) findViewById(R.id.spinner_song);
        spinnerAdapter = ArrayAdapter.createFromResource(context, R.array.songNumber, android.R.layout.simple_spinner_item);
        spinnerSong.setAdapter(spinnerAdapter);

        songCmd = Song_off;
        spinnerSong.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String songData = (String) parent.getItemAtPosition(position);
                Log.d(TAG, "songData" + songData);

                switch (position) {
                    case 0:
                        songCmd = Song_off;
                        Log.d(TAG, "songCmd" + songCmd);
                        break;
                    case 1:
                        songCmd = Song_1;
                        Log.d(TAG, "songCmd" + songCmd);
                        break;
                    case 2:
                        songCmd = Song_2;
                        Log.d(TAG, "songCmd" + songCmd);
                        break;
                    case 3:
                        songCmd = Song_3;
                        Log.d(TAG, "songCmd" + songCmd);
                        break;
                    case 4:
                        songCmd = Song_4;
                        Log.d(TAG, "songCmd" + songCmd);
                        break;
                    case 5:
                        songCmd = Song_5;
                        Log.d(TAG, "songCmd" + songCmd);
                        break;
                }
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });

        buttonPlay = (Button) findViewById(R.id.button_homePlay);
        buttonPlay.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendCMD(songCmd);
            }
        });

        textViewData = (TextView) findViewById(R.id.textView_homeData);
        textViewData.setText("");

        switchLamp1= (Switch) findViewById(R.id.switch_lamp1);
        switchLamp1.setChecked(false);
        switchLamp1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (isChecked){
                    lampCMD=Lamp1_ON;
                }else{
                    lampCMD=Lamp1_OFF;
                }
                sendCMD(lampCMD);
            }
        });
        switchLamp2= (Switch) findViewById(R.id.switch_lamp2);
        switchLamp2.setChecked(false);
        switchLamp2.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (isChecked){
                    lampCMD=Lamp2_ON;
                }else{
                    lampCMD=Lamp2_OFF;
                }
                sendCMD(lampCMD);
            }
        });
        switchLamp3= (Switch) findViewById(R.id.switch_lamp3);
        switchLamp3.setChecked(false);
        switchLamp3.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (isChecked){
                    lampCMD=Lamp3_ON;
                }else{
                    lampCMD=Lamp3_OFF;
                }
                sendCMD(lampCMD);
            }
        });
        switchFan1= (Switch) findViewById(R.id.switch_fan1);
        switchFan1.setChecked(false);
        switchFan1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (isChecked){
                    fan1CMD=Fan1_ON;
                }else{
                    fan1CMD=Fan1_OFF;
                }
                sendCMD(fan1CMD);
            }
        });
        switchMelody= (Switch) findViewById(R.id.switch_meloay);
        switchMelody.setChecked(false);
        switchMelody.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (isChecked){
                    melodyCMD=Melody_ON;
                }else{
                    melodyCMD=Melody_OFF;
                }
                sendCMD(melodyCMD);
            }
        });

        buttonTemp =(Button) findViewById(               R.id.button_homeTemp);
        buttonHum=(Button) findViewById(R.id.button_homeHum );
        buttonTemp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendCMD(Get_Temp);
            }
        });
        buttonHum.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textViewData.setText("");
                sendCMD(Get_Hum);
            }
        });

    }//onCreate

    private final Handler myHandler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            switch (msg.what) {
                case (Constants.MESSAGE_READ):           //手機收(讀)到資料
                    byte[] data = (byte[]) msg.obj;
                    String dataString = new String(data, 0, msg.arg1);
                    textViewData.append(dataString);
                    //textViewData.setText(dataString);
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

    //完全結束 Activity 前呼叫
    protected void onDestroy() {
        super.onDestroy();
        if (myChatService != null) {
            myChatService.stop();
            myChatService = null;
        }
    }
}
