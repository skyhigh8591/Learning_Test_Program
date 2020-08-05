package com.example.http_app;

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

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

public class MainActivity extends AppCompatActivity {

    private final int ChannelField = 1;
    private final int ChannelFeed = 2;
    private final int ChannelStatus = 3;
    private int getFlag;
    private EditText editTextField1, editTextField2;
    private TextView textViewResult;
    private Button buttonGet, buttonPost, buttonGetData;

    private String webAddress = "https://api.thingspeak.com/";
    private String channelField = "channels/1048023/fields/1.json?api_key=AI40GW610Q0J88NH&results=2";
    private String channelFeed = "channels/1048023/feeds.json?api_key=AI40GW610Q0J88NH&results=2";
    private String channelStatus = "channels/1048023/status.json?api_key=AI40GW610Q0J88NH";
    private StringBuilder thingSpeakURL;
    private URL url;
    private HttpURLConnection conn;
    private int code;
    private String getApiKey = "update?api_key=U8LSPEZBUTFRKDZS&field1=0";
    private String field1 = "&field1=";
    private String field2 = "&fireld2=";
    private String postApiKey = "api_key=U8LSPEZBUTFRKDZS&field1=0";
    private Context context;
    private String fieldData1, fieldData2;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        getFlag = ChannelStatus;
        context = this;

        editTextField1 = (EditText) findViewById(R.id.editText_field1);
        editTextField2 = (EditText) findViewById(R.id.editText_field2);

        textViewResult = (TextView) findViewById(R.id.textView_result);
        textViewResult.setText("");

        buttonGet = (Button) findViewById(R.id.button_get);
        buttonPost = (Button) findViewById(R.id.button_post);
        buttonGetData = (Button) findViewById(R.id.button_getdata);

        buttonGet.setOnClickListener(new MyButton());
        buttonPost.setOnClickListener(new MyButton());
        buttonGetData.setOnClickListener(new MyButton());
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
            case R.id.get_field:
                getFlag = ChannelField;
                break;
            case R.id.get_feed:
                getFlag = ChannelFeed;
                break;
            case R.id.get_status:
                getFlag = ChannelStatus;
                break;
        }
        return super.onOptionsItemSelected(item);
    }

    private class MyButton implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (v.getId()) {
                case R.id.button_get:
                    if (editTextField1.length() == 0) {
                        fieldData1 = "0";
                        Toast.makeText(context, "Please input field 1 data.", Toast.LENGTH_SHORT).show();
                    } else {
                        fieldData1 = editTextField1.getText().toString();
                    }

                    if (editTextField2.length() == 0) {
                        fieldData2 = "0";
                        Toast.makeText(context, "Please input field 2 data.", Toast.LENGTH_SHORT).show();
                    } else {
                        fieldData2 = editTextField2.getText().toString();
                    }

                    UpdataData_Get myGet = new UpdataData_Get();
                    myGet.execute();
                    break;

                case R.id.button_post:

                    if (editTextField1.length() == 0) {
                        fieldData1 = "0";
                        Toast.makeText(context, "Please input field 1 data.", Toast.LENGTH_SHORT).show();
                    } else {
                        fieldData1 = editTextField1.getText().toString();
                    }

                    if (editTextField2.length() == 0) {
                        fieldData2 = "0";
                        Toast.makeText(context, "Please input field 2 data.", Toast.LENGTH_SHORT).show();
                    } else {
                        fieldData2 = editTextField2.getText().toString();
                    }


                    updataData_Post myPost = new updataData_Post();
                    myPost.execute();

                    break;
                case R.id.button_getdata:
                    GetChannelData myGetData = new GetChannelData();
                    myGetData.execute();
                    break;
            }
        }
    }

    private class GetChannelData extends AsyncTask<Void, Void, String> {
        @Override
        protected String doInBackground(Void... voids) {
            String result = null;

            thingSpeakURL = new StringBuilder();
            thingSpeakURL.append(webAddress);
            switch (getFlag) {
                case ChannelField:
                    thingSpeakURL.append(channelField);
                    break;

                case ChannelFeed:
                    thingSpeakURL.append(channelFeed);
                    break;

                case ChannelStatus:
                    thingSpeakURL.append(channelStatus);
                    break;
            }

            Log.d("main", "thingSpeakURL =" + thingSpeakURL);
            try {
                url = new URL(thingSpeakURL.toString());
                conn = (HttpURLConnection) url.openConnection();
                conn.setRequestMethod("GET");
                code = conn.getResponseCode();
                Log.d("main", "code =" + code);

                if (code == HttpURLConnection.HTTP_OK) {
                    InputStream inputStream = conn.getInputStream();
                    InputStreamReader reader = new InputStreamReader(inputStream);
                    BufferedReader strigReader = new BufferedReader(reader);
                    result = strigReader.readLine();
                    inputStream.close();

                }

            } catch (MalformedURLException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }

            return result;
        }

        @Override
        protected void onPostExecute(String s) {
            textViewResult.setText(s);
            super.onPostExecute(s);
        }
    }

    private class UpdataData_Get extends AsyncTask<Void, Void, String> {
        @Override
        protected String doInBackground(Void... voids) {
            String data = null;

            thingSpeakURL = new StringBuilder();
            thingSpeakURL.append(webAddress);

            String param = getApiKey + field1 + fieldData1 + field2 + fieldData2;
            thingSpeakURL.append(param);

            Log.d("main", "thingSpeakURL =" + thingSpeakURL);

            try {
                url = new URL(thingSpeakURL.toString());
                conn = (HttpURLConnection) url.openConnection();
                conn.setDoOutput(true);
                conn.setRequestMethod("GET");

                code = conn.getResponseCode();
                Log.d("main", "code =" + code);


                if (code == HttpURLConnection.HTTP_OK) {
                    InputStream inputStream = conn.getInputStream();
                    InputStreamReader reader = new InputStreamReader(inputStream);
                    char[] buffer = new char[50];
                    int number = reader.read(buffer);
                    data = String.valueOf(buffer);
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
            textViewResult.setText(s);
            super.onPostExecute(s);
        }
    }

    private class updataData_Post extends AsyncTask<Void,Void,String> {
        @Override
        protected String doInBackground(Void... voids) {


            String data = null;

            thingSpeakURL = new StringBuilder();
            thingSpeakURL.append(webAddress);
            thingSpeakURL.append("update");

            String param = postApiKey + field1 + fieldData1 + field2 + fieldData2;
            Log.d("main", "thingSpeakURL =" + thingSpeakURL);

            try {
                url = new URL(thingSpeakURL.toString());
                conn = (HttpURLConnection) url.openConnection();
                conn.setDoOutput(true);
                conn.setRequestMethod("POST");
                OutputStream outputStream = conn.getOutputStream();
                OutputStreamWriter writer = new OutputStreamWriter(outputStream);
                writer.write(param);
                writer.flush();
                outputStream.close();

                code = conn.getResponseCode();
                Log.d("main", "code =" + code);


                if (code == HttpURLConnection.HTTP_OK) {
                    InputStream inputStream = conn.getInputStream();
                    InputStreamReader reader = new InputStreamReader(inputStream);
                    char[] buffer = new char[50];
                    int number = reader.read(buffer);
                    data = String.valueOf(buffer);
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
            textViewResult.setText(s);
            super.onPostExecute(s);
        }
    }
}
