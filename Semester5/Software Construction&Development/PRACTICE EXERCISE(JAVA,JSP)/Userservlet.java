package com.xadmin.jdbcex.web;


import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.xadmin.jdbcex.bean.user;
import com.xadmin.jdbcex.dao.userDao;


public class Userservlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private userDao userDAO;
	
	public void init() {
		userDAO = new userDao();
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String action = request.getServletPath();

		try {
			switch (action) {
			case "/new":
				showNewForm(request, response);
				break;
			case "/insert":
				insertUser(request, response);
				break;
			case "/delete":
				deleteUser(request, response);
				break;
			case "/edit":
				showEditForm(request, response);
				break;
			case "/update":
				updateUser(request, response);
				break;
			default:
				food(request, response);
				break;
			}
		} catch (SQLException ex) {
			throw new ServletException(ex);
		}
	}

	private void food(HttpServletRequest request, HttpServletResponse response) {
		// TODO Auto-generated method stub
		
	}

	private void listfood(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, IOException, ServletException {
		List<user> food = userDAO.selectAllfood();
		request.setAttribute("foodlist", food);
		RequestDispatcher dispatcher = request.getRequestDispatcher("user-list.jsp");
		dispatcher.forward(request, response);
	}

	private void showNewForm(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		RequestDispatcher dispatcher = request.getRequestDispatcher("user-form.jsp");
		dispatcher.forward(request, response);
	}

	private void showEditForm(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, ServletException, IOException {
		int id = Integer.parseInt(request.getParameter("food_id"));
		user existingUser = userDAO.selectfood(id);
		

	}

	private void insertUser(HttpServletRequest request, HttpServletResponse response) 
			throws SQLException, IOException {
		String food_title = request.getParameter("food_title");
		String food_type = request.getParameter("food_type");
		String price = request.getParameter("price");
		user newUser = new user(food_title, food_type, price);
		userDAO.insertfood(newUser);
		response.sendRedirect("list");
	}

	private void updateUser(HttpServletRequest request, HttpServletResponse response) 
			throws SQLException, IOException {
		int food_id = Integer.parseInt(request.getParameter("food_id"));
		String food_title = request.getParameter("food_title");
		String food_type = request.getParameter("food_type");
		String price = request.getParameter("price");

		user book = new user(food_id, food_title, food_type, price);
		userDAO.updateUser(book);
		response.sendRedirect("list");
	}

	private void deleteUser(HttpServletRequest request, HttpServletResponse response) 
			throws SQLException, IOException {
		int id = Integer.parseInt(request.getParameter("food_id"));
		userDAO.deletefood(id);
		response.sendRedirect("list");

	}

}