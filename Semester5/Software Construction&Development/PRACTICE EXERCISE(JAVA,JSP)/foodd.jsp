<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<html>
<head>
<title>ORDER FOOD NOW</title>
<link rel="stylesheet"
	href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"
	integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T"
	crossorigin="anonymous">
</head>
<body>

	<header>
		<nav class="navbar navbar-expand-md navbar-dark"
			style="background-color: orange">
			<div>
				<a href="https://www.xadmin.net" class="navbar-brand"> ORDER FOOD NOW
					 </a>
			</div>

			<ul class="navbar-nav">
				
			</ul>
		</nav>
	</header>
	<br>

	<div class="row">


		<div class="container">
			
			<hr>
			<div class="container text-left">

				<a href="<%=request.getContextPath()%>/new" class="btn btn-success">Add Food Detail</a>
			</div>
			<br>
			<table class="table table-bordered">
				<thead>
					<tr>
						<th>Food_Id</th>
						<th>Food_title</th>
						<th>Food_type</th>
						<th>price</th>
						<th>Actions</th>
					</tr>
				</thead>
				<tbody>
				
					<c:forEach var="user" items="${food}">

						<tr>
							<td><c:out value="${user.food_id}" /></td>
							<td><c:out value="${user.food_title}" /></td>
							<td><c:out value="${user.food_type}" /></td>
							<td><c:out value="${user.price}" /></td>
							<td><a href="edit?id=<c:out value='${user.food_id}' />">Insert</a>
								&nbsp;&nbsp;&nbsp;&nbsp; <a
								href="delete?id=<c:out value='${user.food_id}' />">Delete</a></td>
						</tr>
					</c:forEach>
		
				</tbody>

			</table>
		</div>
		<table class="table table-bordered">
				<thead>
					<tr>
						<th>Food_Id</th>
						<th>Rate_Food</th>
						<th>Review_Food</th>
						
						<th>Edit</th>
					</tr>
				</thead>
				<tbody>
				
					<c:forEach var="user" items="${food}">

						<tr>
							<td><c:out value="${user.food_id}" /></td>
							<td><c:out value="${user.rate}" /></td>
							<td><c:out value="${user.review}" /></td>
							
							
						</tr>
					</c:forEach>
		
				</tbody>

			</table>
	</div>
</body>
</html>