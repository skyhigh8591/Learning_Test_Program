package com.example.pi_app;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.URL;

public class MainActivity extends AppCompatActivity {

    private Context context;
    private final int AddDataGet = 1;
    private final int GetAllData = 2;
    private String webAddress = "http://192.168.58.189/code/";
    private String addCmd = "get_api.php?";
    private String userid = "userid=";
    private String temperature = "temperature=";
    private EditText editTextUserid, editTextTemp;
    private TextView textViewResult;
    private Button buttonCancel;
    private Button buttonOK;
    private int actionFlag;
    private String useridData;
    private StringBuilder myURL;
    private String TempData;
    private String getAllDataCmd ="get_all_api.php";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        context = this;
        actionFlag = AddDataGet;

        editTextUserid = (EditText) findViewById(R.id.editText_userid);
        editTextTemp = (EditText) findViewById(R.id.editText_temp);

        textViewResult = (TextView) findViewById(R.id.textView_result);
        textViewResult.setText("");

        buttonCancel = (Button) findViewById(R.id.button_cancel);
        buttonCancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                editTextTemp.setText("");
                editTextUserid.setText("");
            }
        });

        buttonOK = (Button) findViewById(R.id.button_ok);
        buttonOK.setOnClickListener(new MyButton());


    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        super.onCreateOptionsMenu(menu);
        getMenuInflater().inflate(R.menu.setup, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()) {
            case R.id.set_data_get:
                actionFlag = AddDataGet;
                break;
            case R.id.get_alldata:
                actionFlag = GetAllData;
                break;
        }

        return super.onOptionsItemSelected(item);
    }

    private class MyButton implements View.OnClickListener {
        @Override
        public void onClick(View v) {

            switch (actionFlag) {
                case AddDataGet:
                    if (editTextUserid.length() != 0) {
                        useridData = editTextUserid.getText().toString();
                    } else {
                        Toast.makeText(context, "Please input user id.", Toast.LENGTH_SHORT).show();
                        break;
                    }
                    if (editTextTemp.length() != 0) {
                        TempData = editTextTemp.getText().toString();
                    } else {
                        Toast.makeText(context, "Please input temperayure", Toast.LENGTH_SHORT).show();
                        break;
                    }
                    SetSQLData myGet = new SetSQLData();
                    myGet.execute();
                    break;

                case GetAllData:
                    SetSQLData myGet1 = new SetSQLData();
                    myGet1.execute();
                    break;
            }
        }

        private class SetSQLData extends AsyncTask<Void, Void, String> {
            @Override
            protected String doInBackground(Void... voids) {
                String data = null;

                myURL = new StringBuilder();
                myURL.append(webAddress);

                switch (actionFlag){
                    case AddDataGet:
                        myURL.append(addCmd);
                        String param = userid + useridData + "&" + temperature + TempData;

                        myURL.append(param);
                        Log.d("main","myURL=" + myURL);
                        break;
                    case GetAllData:
                        myURL.append(getAllDataCmd);
                        break;
                }


                try {
                    URL url = new URL(myURL.toString());
                    HttpURLConnection conn = (HttpURLConnection) url.openConnection();
                    conn.setRequestMethod("GET");
                    int code = conn.getResponseCode();
                    Log.d("main","code=" + code);

                    if(code==HttpURLConnection.HTTP_OK){
                        InputStream inputStream = conn.getInputStream();
                        InputStreamReader reader = new InputStreamReader(inputStream);
                        //BufferedReader stringReader = new BufferedReader(reader);
                        //data = stringReader.readLine();
                        char [] buffer = new char[4096];
                        int number = reader.read(buffer);
                        Log.d("main","number=" + number);
                        data = String.valueOf(buffer);

                        Log.d("main","data=" + data);
                        inputStream.close();
                    }
                } catch (MalformedURLException e) {
                    e.printStackTrace();
                } catch (IOException e) {
                    e.printStackTrace();
                }


                return data;
            }

            @Override
            protected void onPostExecute(String s) {
                super.onPostExecute(s);
                if(actionFlag==GetAllData){
                    try {
                        JSONArray jsonArray = new JSONArray(s);
                        StringBuffer jsonData = new StringBuffer();

                        for(int i=0 ; i <jsonArray.length();i++){
                            JSONObject jsonObj = jsonArray.getJSONObject(i);

                            String id = jsonObj.getString("ID");
                            jsonData.append("ID="+id+" , ");
                            String useridValue = jsonObj.getString("userid");
                            jsonData.append("userid=" + useridValue + " , ");
                            String tempValue = jsonObj.getString("temperature");
                            jsonData.append("temperature =" + tempValue+" , ");

                            String time = jsonObj.getString("datetime");
                            jsonData.append("created time=" + time + "\n");


                        }
                        textViewResult.setText(jsonData.toString());

                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                }else {
                    textViewResult.setText(s);
                }


            }
        }
    }
}
