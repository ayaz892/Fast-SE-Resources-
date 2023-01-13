<%  
    String name = request.getParameter("name");
	String password = request.getParameter("pwd");
	if(name.equals("ayaz") && password.equals("abcde"))
	{
		session.setAttribute("username",name);
		response.sendRedirect("NextPageAfterFirst.jsp");
	}
	else
	{
		response.sendRedirect("SessionManagement.html");
	}
	%>