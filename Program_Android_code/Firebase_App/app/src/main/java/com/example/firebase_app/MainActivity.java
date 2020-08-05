package com.example.firebase_app;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.Spinner;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.Query;
import com.google.firebase.database.ValueEventListener;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MainActivity extends AppCompatActivity {

    private Context context;
    private ListView listViewData;
    private List<Map<String, String>> datalist;
    private SimpleAdapter adapter;
    private DatabaseReference myFireBase;
    private HashMap<String, String> mapData;
    private String name,phone;
    private int dataCount;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        context =  this;

        listViewData = (ListView) findViewById(R.id.listView_id);
        datalist = new ArrayList<Map<String,String>>();
        datalist.clear();

        adapter = new SimpleAdapter(context,datalist,R.layout.item_layout,new String[]{"name","phone"},
                    new int[] {R.id.textView_name,R.id.textView_phone});

        listViewData.setAdapter(adapter);



        myFireBase = FirebaseDatabase.getInstance().getReference("contacts");



 //       myFireBase.child("3").child("name").setValue("Mary");
 //       myFireBase.child("3").child("phone").setValue("35356");

        myFireBase.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                datalist.clear();
                dataCount = (int) dataSnapshot.getChildrenCount();
                Log.d("main","dataCount" + dataCount);

                for (DataSnapshot ds : dataSnapshot.getChildren()) {
                    Log.d("main","ds =  " + ds);
                    mapData = new HashMap<String,String>();
                    String nameData = (String) ds.child("name").getValue();
                    Log.d("main","nameData =  " + nameData);
                    if (nameData == null)
                        mapData.put("name","no name");
                    else
                        mapData.put("name",nameData);

                    String phoneData = (String) ds.child("phone").getValue();
                    Log.d("main","phoneData =  " + phoneData);
                    if (phoneData == null)
                        mapData.put("phone","no number");
                    else
                        mapData.put("phone",phoneData);

                    datalist.add(mapData);
                }
                Log.d("main","mapData =  " + mapData.get(1));
                adapter.notifyDataSetChanged();
            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {

            }
        });

        listViewData.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

                Map<String,String> item = (Map<String,String>) parent.getItemAtPosition(position);

                String message = "name : " + item.get("name") + "\nphone number : " + item.get("phone") + "\n";
                Log.d("main","message = " + message);
                name = item.get("name").toString();
                phone = item.get("phone").toString();

                AlertDialog.Builder builder = new AlertDialog.Builder(context);
                builder.setTitle("Delete item");
                builder.setIcon(android.R.drawable.ic_menu_delete);
                builder.setMessage(message);
                builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Query nameList = myFireBase.orderByChild("name").equalTo(name);
                        nameList.addListenerForSingleValueEvent(new ValueEventListener() {
                            @Override
                            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                                for (DataSnapshot ds: dataSnapshot.getChildren()) {
                                    String phoneValue = (String) ds.child("phone").getValue();
                                    Log.d("main","phoneValue = " + phoneValue);
                                    if (phoneValue.equals(phone)) ds.getRef().removeValue();

                                }
                            }

                            @Override
                            public void onCancelled(@NonNull DatabaseError databaseError) {

                            }
                        });
                        dialog.dismiss();
                    }
                });

                builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {

                        dialog.dismiss();
                    }
                });

                builder.create().show();

            }
        });

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        super.onCreateOptionsMenu(menu);
        getMenuInflater().inflate(R.menu.setup,menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        
        switch (item.getItemId()) {
            case R.id.add_item:
                addDialog();
                break;
        }
        return super.onOptionsItemSelected(item);
    }

    private void addDialog() {
        View layoutView = getLayoutInflater().inflate(R.layout.add_layout,(ViewGroup) findViewById(R.id.dialog_id));
        final EditText editTextName = (EditText) layoutView.findViewById(R.id.editText_name);
        final EditText editTextPhone = (EditText) layoutView.findViewById(R.id.editText_phone);
        editTextName.setText("");
        editTextPhone.setText("");

        AlertDialog.Builder builder = new AlertDialog.Builder(context);
        builder.setTitle("Add item");
        builder.setIcon(android.R.drawable.ic_input_add);
        builder.setView(layoutView);

        builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                name = editTextName.getText().toString();
                phone = editTextPhone.getText().toString();

                Map<String, String> data = new HashMap<>();
                data.put("name",name);
                data.put("phone",phone);

//                myFireBase.child("").push().setValue(data);

                myFireBase.child(Integer.toString(dataCount+1)).setValue(data);
                dialog.dismiss();
            }
        });

        builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {

                dialog.dismiss();
            }
        });

        builder.create().show();
    }
}
