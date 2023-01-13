package com.xadmin.jdbcex.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import com.xadmin.jdbcex.bean.user;




public class userDao {
	private String jdbcURL = "jdbc:mysql://localhost:3306/userdb?useSSL=false";
	private String jdbcUsername = "root";
	private String jdbcPassword = "abc123456789";

	private static final String INSERT_DB1_SQL = "INSERT FOOD DETAILS" + "  (FOOD_TITILE, FOOD_TYPE, PRICE) VALUES "
			+ " (?, ?, ?);";

	private static final String SELECT_DB1_BY_ID = "select food_id,food_title,food_type,price from DB1 where food_id =?";
	private static final String SELECT_ALL_DB1 = "select * from db";
	private static final String DELETE_DB1_SQL = "delete from DB1 where food_id = ?;";
	private static final String UPDATE_DB1_SQL = "update DB1 set food_title = ?,food_type= ?, price =? where food_id = ?;";
	

	public userDao() {
	}

	protected Connection getConnection() {
		Connection connection = null;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			connection = DriverManager.getConnection(jdbcURL, jdbcUsername, jdbcPassword);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return connection;
	}

	public void insertfood(user user) throws SQLException {
		System.out.println(INSERT_DB1_SQL);
		try (Connection connection = getConnection();
				PreparedStatement preparedStatement = connection.prepareStatement(INSERT_DB1_SQL)) {
			preparedStatement.setString(1, user.getfood_title());
			preparedStatement.setString(2, user.getfood_type());
			preparedStatement.setString(3, user.getprice());
			System.out.println(preparedStatement);
			preparedStatement.executeUpdate();
		} catch (SQLException e) {
			printSQLException(e);
		}
	}

	public user selectfood(int food_id) {
		user user = null;
		try (Connection connection = getConnection();
				PreparedStatement preparedStatement = connection.prepareStatement(SELECT_DB1_BY_ID);) {
			preparedStatement.setInt(1, food_id);
			System.out.println(preparedStatement);
			ResultSet rs = preparedStatement.executeQuery();
			while (rs.next()) {
				String food_title = rs.getString("food_title");
				String food_type = rs.getString("food_type");
				String price = rs.getString("price");
				user = new user(food_id, food_title, food_type, price);
			}
		} catch (SQLException e) {
			printSQLException(e);
		}
		return user;
	}

	public List<user> selectAllfood() {

		List<user> users = new ArrayList<>();
		try (Connection connection = getConnection();

			PreparedStatement preparedStatement = connection.prepareStatement(SELECT_ALL_DB1);) {
			System.out.println(preparedStatement);
			ResultSet rs = preparedStatement.executeQuery();
			while (rs.next()) {
				int food_id = rs.getInt("food_id");
				String food_title = rs.getString("food_title");
				String food_type = rs.getString("food_type");
				String price = rs.getString("price");
				users.add(new user(food_id, food_title, food_type, price));
			}
		} catch (SQLException e) {
			printSQLException(e);
		}
		return users;
	}

	public boolean deletefood(int food_id) throws SQLException {
		boolean rowDeleted;
		try (Connection connection = getConnection();
				PreparedStatement statement = connection.prepareStatement(DELETE_DB1_SQL);) {
			statement.setInt(1, food_id);
			rowDeleted = statement.executeUpdate() > 0;
		}
		return rowDeleted;
	}

	public boolean updateUser(user user) throws SQLException {
		boolean rowUpdated;
		try (Connection connection = getConnection();
				PreparedStatement statement = connection.prepareStatement(UPDATE_DB1_SQL);) {
			System.out.println("updated USer:"+statement);
			statement.setString(1, user.getfood_title());
			statement.setString(2, user.getfood_type());
			statement.setString(3, user.getprice());
			statement.setInt(4, user.getfood_id());

			rowUpdated = statement.executeUpdate() > 0;
		}
		return rowUpdated;
	}

	private void printSQLException(SQLException ex) {
		for (Throwable e : ex) {
			if (e instanceof SQLException) {
				e.printStackTrace(System.err);
				System.err.println("SQLState: " + ((SQLException) e).getSQLState());
				System.err.println("Error Code: " + ((SQLException) e).getErrorCode());
				System.err.println("Message: " + e.getMessage());
				Throwable t = ex.getCause();
				while (t != null) {
					System.out.println("Cause: " + t);
					t = t.getCause();
				}
			}
		}
	}

}