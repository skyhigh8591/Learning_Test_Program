package com.example.sql_app;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.ContentValues;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private int actionFlag;
    private final int AddData = 1;
    private final int UpdataData = 2;
    private final int DeleteData = 3;
    private final int SelectData = 4;
    private Context context;
    private DBHelper dbHelper;
    private SQLiteDatabase userDB;
    private EditText editTextUserName,editTextPassword,editTextEmail;
    private TextView textViewResult;
    private Button buttonCancel,buttonOK;
    private String userNameDate,passwordData,emailData;
    private ContentValues cv;
    private long idNumber;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        actionFlag = SelectData;
        context = this;

        dbHelper = new DBHelper(context);
        userDB = dbHelper.getReadableDatabase();

        editTextUserName = (EditText)findViewById(R.id.editText_name);
        editTextUserName.setText("");

        editTextPassword = (EditText)findViewById(R.id.editText_password);
        editTextPassword.setTransformationMethod(null);

        editTextEmail = (EditText)findViewById(R.id.editText_email);

        textViewResult = (TextView)findViewById(R.id.textView_result);
        textViewResult.setText("");

        buttonCancel = (Button)findViewById(R.id.button_cancel);
        buttonCancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                editTextUserName.setText("");
                editTextPassword.setText("");
                editTextEmail.setText("");
            }
        });

        buttonOK = (Button)findViewById(R.id.button_ok);
        buttonOK.setOnClickListener(new MyButton());


    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
         super.onCreateOptionsMenu(menu);
        getMenuInflater().inflate(R.menu.setup,menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()){
            case R.id.add_data:
                actionFlag = AddData;
                break;
            case R.id.updata_data:
                actionFlag = UpdataData;
                break;
            case R.id.delete_data:
                actionFlag = DeleteData;
                break;
            case R.id.select_data:
                actionFlag = SelectData;
                break;
            case R.id.select_alldata:
                Intent intent = new Intent(context, selectActivity.class);
                startActivity(intent);
                break;
        }
        return super.onOptionsItemSelected(item);
    }

    private class MyButton implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (actionFlag){
                case AddData:
                    if(editTextUserName.length()!=0){
                        userNameDate = editTextUserName.getText().toString();
                    }else {
                        Toast.makeText(context,"Please input user name.",Toast.LENGTH_SHORT).show();
                        break;
                    }

                    if(editTextPassword.length() !=0){
                        passwordData = editTextPassword.getText().toString();
                    }else {
                        Toast.makeText(context,"Please input user password.",Toast.LENGTH_SHORT).show();
                        break;
                    }

                    if(editTextEmail.length() !=0){
                        emailData = editTextEmail.getText().toString();
                    }else {
                        Toast.makeText(context,"Please input user email.",Toast.LENGTH_SHORT).show();
                        break;
                    }

                    cv = new ContentValues();
                    cv.put("username",userNameDate);
                    cv.put("password",passwordData);
                    cv.put("email",emailData);

                    idNumber = userDB.insert("user_table",null,cv);
                    textViewResult.setText("add data id =" + idNumber);
                    break;
                case UpdataData:
                    if(editTextUserName.length()!=0){
                        userNameDate = editTextUserName.getText().toString();
                    }else {
                        Toast.makeText(context,"Please input user name.",Toast.LENGTH_SHORT).show();
                        break;
                    }

                    if(editTextPassword.length() !=0){
                        passwordData = editTextPassword.getText().toString();
                    }else {
                        Toast.makeText(context,"Please input user password.",Toast.LENGTH_SHORT).show();
                        break;
                    }

                    if(editTextEmail.length() !=0){
                        emailData = editTextEmail.getText().toString();
                    }else {
                        Toast.makeText(context,"Please input user email.",Toast.LENGTH_SHORT).show();
                        break;
                    }

                    cv = new ContentValues();
                    cv.put("username",userNameDate);
                    cv.put("password",passwordData);
                    cv.put("email",emailData);

                    String[] matchDate = {userNameDate};
                    int count = userDB.update("user_table", cv, "username=?", matchDate);
                    if(count != 0){
                        textViewResult.setText(userNameDate + " has been update.\n" + "user = " + count);
                    } else {
                        textViewResult.setText("Update data is error");
                    }


                    break;
                case DeleteData:

                    if(editTextUserName.length()!=0){
                        userNameDate = editTextUserName.getText().toString();
                    }else {
                        Toast.makeText(context,"Please input user name.",Toast.LENGTH_SHORT).show();
                        break;
                    }

                    String[] matchDate1 = {userNameDate};
                    int count1 = userDB.delete("user_table","username=?",matchDate1);

                    if(count1 != 0){
                        textViewResult.setText(userNameDate + " has been deleted.\n" + "user = " + count1);
                    } else {
                        textViewResult.setText("Deleted data is error");
                    }


                    break;
                case SelectData:

                    if(editTextUserName.length()!=0){
                        userNameDate = editTextUserName.getText().toString();
                    }else {
                        Toast.makeText(context,"Please input user name.",Toast.LENGTH_SHORT).show();
                        break;
                    }

                    String[] matchDate2 = {userNameDate};
                    String selectString = "SELECT * FROM user_table WHERE username=?";

                    Cursor dataCursor = userDB.rawQuery(selectString, matchDate2);
                    textViewResult.setText("");
                    dataCursor.moveToFirst();
                    while (!dataCursor.isAfterLast()){

                        int id =dataCursor.getInt(dataCursor.getColumnIndex("_id"));
                        textViewResult.append("id =" + id + " , ");
                        String userName = dataCursor.getString(dataCursor.getColumnIndex("username"));
                        textViewResult.append("user name =" + userName + "\n");

                        String password = dataCursor.getString(dataCursor.getColumnIndex("password"));
                        textViewResult.append("password =" + password + "\n");

                        String email = dataCursor.getString(dataCursor.getColumnIndex("email"));
                        textViewResult.append("email =" + email + "\n");

                        String time = dataCursor.getString(dataCursor.getColumnIndex("created_time"));
                        textViewResult.append("created_time =" + time + "\n");

                        dataCursor.moveToNext();

                    }
                    break;


            }
        }
    }
}
