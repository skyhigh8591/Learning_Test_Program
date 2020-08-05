package com.example.sql_app;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class DBHelper extends SQLiteOpenHelper {
    private static final String DataBase_Name = "user.db" ;
    private static final int Database_version = 1;
    private  final String Creat_Table = "CREATE TABLE user_table(_id INTEGER PRIMARY KEY,username TEXT,password TEXT,email TEXT," +
                                    "created_time TIMESTAMP default CURRENT_TIMESTAMP)";
    private final String Drop_Table = "DROP TABLE IF EXISTS user_table";

    public DBHelper(@Nullable Context context, @Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version) {
        super(context, name, factory, version);
    }

    public DBHelper(Context context){
        super(context,DataBase_Name,null,Database_version);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(Creat_Table);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL(Drop_Table);
        onCreate(db);

    }
}
