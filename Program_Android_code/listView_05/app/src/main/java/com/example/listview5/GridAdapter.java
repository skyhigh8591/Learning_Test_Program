package com.example.listview5;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.List;
import java.util.Map;

class GridAdapter extends BaseAdapter {
    private final LayoutInflater myInflater;
    private final List<Map<String, Object>> myItemList;
    private final int myItemLayout;


    public GridAdapter(Context context, List<Map<String, Object>> itemList, int item_layout) {
        myInflater = LayoutInflater.from(context);
        myItemList = itemList;
        myItemLayout = item_layout;


    }

    @Override
    public int getCount() {
        return myItemList.size();
    }

    @Override
    public Object getItem(int position) {
        return myItemList.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    private class ViewHolder {
        ImageView imageViewPic;
        TextView textViewName;


    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder holder;
        if (convertView == null) {
            convertView = myInflater.inflate(myItemLayout, null);
            holder = new ViewHolder();
            holder.imageViewPic = (ImageView) convertView.findViewById(R.id.imageView_id);
            holder.textViewName = (TextView) convertView.findViewById(R.id.textView_name);
            convertView.setTag(holder);

        } else {
            holder = (ViewHolder) convertView.getTag();
        }

        Map<String, Object> item = myItemList.get(position);

        int image = (int) item.get("image");
        holder.imageViewPic.setImageResource(image);
        String name = (String) item.get("name");
        holder.textViewName.setText(name);

        return convertView;
    }
}
