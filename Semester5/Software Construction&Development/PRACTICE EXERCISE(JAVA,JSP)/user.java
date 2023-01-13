package com.xadmin.jdbcex.bean;

public class user {
	
	private int food_id;
	private String food_title;
	private  String food_type;
	private  String price;
	
	private int rate;
	private String review;
	
	
	public user(String food_title, String food_type, String price) {
		super();
		this.food_title = food_title;
		this.food_type = food_type;
		this.price = price;
	}
	public user(int food_id, String food_title, String food_type, String price) {
		super();
		this.food_id = food_id;
		this.food_title = food_title;
		this.food_type = food_type;
		this.price = price;
	}
	public int getfood_id() {
		return food_id;
	}
	public void setfood_Id(int food_id) {
		this.food_id = food_id;
	}
	public String getfood_title() {
		return food_title;
	}
	public void setfood_title( String food_title) {
		this.food_title = food_title;
	}
	public String getfood_type() {
		return food_type;
	}
	public void setfood_type_type( String food_type) {
		this.food_type = food_type;
	}
	public String getprice() {
		return price;
	}
	public void setprice( String price) {
		this.price = price;
	}

}
