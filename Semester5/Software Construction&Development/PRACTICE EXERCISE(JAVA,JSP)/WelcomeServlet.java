package lab8qs;

import java.io.IOException;
import java.io.PrintWriter;

import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

public class WelcomeServlet extends HttpServlet{
	public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException{
		HttpSession session = request.getSession();
		String name = (String) session.getAttribute("name");
		PrintWriter out = response.getWriter();
		out.print("Welcome "+name);
	}
}
