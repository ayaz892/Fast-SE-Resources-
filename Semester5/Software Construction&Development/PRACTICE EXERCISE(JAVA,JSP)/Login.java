package lab8qs;

import java.io.IOException;
import java.io.PrintWriter;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

public class Login extends HttpServlet{
	public void service(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException{
		String name = request.getParameter("name");
		String password = request.getParameter("password");
		
		if(password.equals("servlet")) {
			request.setAttribute("name", name);
			HttpSession session = request.getSession();
			session.setAttribute("name", name);
			session.setAttribute("password", password);
			response.sendRedirect("welcome");
		}
		else {
			response.setContentType("text/html");
			PrintWriter out = response.getWriter();
			out.print("<p>Sorry Username or password error.<p>");
		
			RequestDispatcher rd = request.getRequestDispatcher("index.html");
			rd.forward(request, response);			
		}
	}

}
