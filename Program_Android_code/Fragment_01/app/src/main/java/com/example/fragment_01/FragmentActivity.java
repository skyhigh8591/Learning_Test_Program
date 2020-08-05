package com.example.fragment_01;

import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

public class FragmentActivity extends Fragment {

    private static final String TAG = "main";
    private TextView textViewFrag1, textViewFrag2;
    private Button buttonFrag1, buttonFrag2;

    @Override
    public void onAttach(@NonNull Context context) {
        super.onAttach(context);
        Log.d(TAG, "onAttach()-F");
    }

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.d(TAG, "onCreate()-F");
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View fragView;
        fragView = inflater.inflate(R.layout.fragment_layout, container, false);
        textViewFrag1 = (TextView) fragView.findViewById(R.id.textView_frag1);
        textViewFrag2 = (TextView) fragView.findViewById(R.id.textView_frag2);
        buttonFrag1 = (Button) fragView.findViewById(R.id.button_frag1);
        buttonFrag2 = (Button) fragView.findViewById(R.id.button_frag2);
        return fragView;
    }

    @Override
    public void onActivityCreated(@Nullable Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        Log.d(TAG, "onActivityCreated()-F");
        buttonFrag1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textViewFrag1.setText("Button 1 is pressed");
            }
        });

        buttonFrag2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textViewFrag2.setText("Button 2 is pressed");
            }
        });
    }

    @Override
    public void onStart() {
        super.onStart();
        Log.d(TAG, "onStart()-F");
    }

    @Override
    public void onResume() {
        super.onResume();
        Log.d(TAG, "onResume()-F");
    }

    @Override
    public void onPause() {
        super.onPause();
        Log.d(TAG, "onPause()-F");

    }

    @Override
    public void onStop() {
        super.onStop();
        Log.d(TAG, "onStop()-F");
    }

    @Override
    public void onDestroyView() {
        super.onDestroyView();
        Log.d(TAG, "onDestroyView()-F");
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        Log.d(TAG, "onDestroy()-F");
    }

    @Override
    public void onDetach() {
        super.onDetach();
        Log.d(TAG, "onDetach()-F");
    }
}
