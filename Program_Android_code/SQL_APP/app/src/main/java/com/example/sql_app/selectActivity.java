package com.example.sql_app;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.SimpleCursorAdapter;

public class selectActivity extends AppCompatActivity {

    private Context context;
    private ListView listViewData;
    private DBHelper dbHelper;
    private SQLiteDatabase userDB;
    private Cursor dataCursor;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_select);

        setTitle("List all data");
        context = this;

        listViewData = (ListView)findViewById(R.id.listView_id);
        dbHelper = new DBHelper(context);
        userDB = dbHelper.getReadableDatabase();

        dataCursor = userDB.rawQuery("select * from user_table",null);

        SimpleCursorAdapter adapter = new SimpleCursorAdapter(context, R.layout.item_layout, dataCursor,
                new String[]{"_id", "username", "password", "email", "created_time"},
                new int[]{R.id.textView_id, R.id.textView_username, R.id.textView_password, R.id.textView_email, R.id.textView_time}, 0);

        listViewData.setAdapter(adapter);

    }
}
