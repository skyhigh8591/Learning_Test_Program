package com.example.asynctask_app;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private TextView textViewData;
    private ImageView imageViewPic;
    private ProgressBar progressBar;
    private int progressMax;
    private int currentProgress;
    private int progressInc;
    private TextView textViewStatus;
    private int value;
    private Button button1, button2, button3;
    private Context context;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        context=this;

        textViewData = (TextView) findViewById(R.id.textView_data);
        textViewData.setText("");

        imageViewPic = (ImageView) findViewById(R.id.imageView_id);
        imageViewPic.setVisibility(View.INVISIBLE);

        progressBar = (ProgressBar) findViewById(R.id.progressBar_id);
        progressMax = 20;
        progressBar.setMax(progressMax);
        currentProgress = 0;
        progressBar.setProgress(currentProgress);
        progressInc = 2;
        progressBar.incrementProgressBy(progressInc);

        textViewStatus = (TextView) findViewById(R.id.textView_pro);
        value = (currentProgress * 100) / progressMax;
        textViewStatus.setText(value + "%");

        button1 = (Button) findViewById(R.id.button_1);
        button2 = (Button) findViewById(R.id.button_2);
        button3 = (Button) findViewById(R.id.button_3);

        button1.setOnClickListener(new MyButton());
        button2.setOnClickListener(new MyButton());
        button3.setOnClickListener(new MyButton());
    }

    private class MyButton implements View.OnClickListener {
        @Override
        public void onClick(View v) {

            switch (v.getId()) {
                case R.id.button_1:
                    MyJob1 myJob1 = new MyJob1();
                    myJob1.execute();
                    break;
                case R.id.button_2:
                    MyJob2 myJob2 = new MyJob2();
                    myJob2.execute(8);
                    break;
                case R.id.button_3:
                    MyJob3 myJob3 = new MyJob3();
                    myJob3.execute(5);

                    break;
            }

        }
    }

    private class MyJob1 extends AsyncTask<Void, Void, Void> {
        @Override
        protected Void doInBackground(Void... voids) {

            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            return null;
        }

        @Override
        protected void onPreExecute() {
            Toast.makeText(context,"onPreExecute()",Toast.LENGTH_SHORT).show();
            super.onPreExecute();
        }

        @Override
        protected void onPostExecute(Void aVoid) {
            super.onPostExecute(aVoid);
            textViewData.setText("Button 1 is pressed.");
            imageViewPic.setImageResource(R.drawable.img_1);
            imageViewPic.setVisibility(View.VISIBLE);


        }
    }

    private class MyJob2 extends AsyncTask<Integer,Integer,Void>{
        @Override
        protected Void doInBackground(Integer... integers) {
            int time = integers[0];

            try {
                for (int i=0 ; i<time ; i++) {
                    Thread.sleep(1000);
                    publishProgress(new Integer[]{i+1});
                }

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            return null;

        }

        @Override
        protected void onProgressUpdate(Integer... values) {
            super.onProgressUpdate(values);
            currentProgress =values[0]*2;
            progressBar.setProgress(currentProgress);
            value = (currentProgress*100)/progressMax;
            textViewStatus.setText(value+"%");
        }

        @Override
        protected void onPostExecute(Void aVoid) {
            super.onPostExecute(aVoid);
            textViewData.setText("Button 2 is pressed.");
            imageViewPic.setImageResource(R.drawable.img_2);
            imageViewPic.setVisibility(View.VISIBLE);
        }
    }

    private class MyJob3 extends AsyncTask<Integer,Integer,String>{
        @Override
        protected String doInBackground(Integer... integers) {
            String result;
            int time = integers[0];

            try {
                for (int i=0 ; i<time ; i++) {
                    Thread.sleep(1000);
                    publishProgress(new Integer[]{i+1});
                }

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            result = "Button 3 is pressed.";
            return result;
        }

        @Override
        protected void onProgressUpdate(Integer... values) {
            super.onProgressUpdate(values);
            currentProgress =values[0]*2;
            progressBar.setProgress(currentProgress);
            value = (currentProgress*100)/progressMax;
            textViewStatus.setText(value+"%");
        }

        @Override
        protected void onPostExecute(String s) {
            super.onPostExecute(s);
            textViewData.setText(s);
            imageViewPic.setImageResource(R.drawable.img_3);
            imageViewPic.setVisibility(View.VISIBLE);
        }
    }
}
