$(document).ready(
function () {
	$('#image').mousedown(
		function (event) {
			var isMove = true;
			var startX = event.pageX + $(window).width() - $('#image').offset().left - $('#image').width();
			var startY = event.pageY + $(window).height() - $('#image').offset().top - $('#image').height();
			$(document).mousemove(
				function (event) {
					if (isMove) {
						var obj = $('#image');
						obj.css({'right': startX - event.pageX, 'bottom': startY - event.pageY});
					}
				}
			).mouseup(
				function () {
					isMove = false;
					editor.focus();
				}
			);
		}
	);
	$("#run").click(
		function () {
			$.ajax({
				type: "POST",
				url: "http://127.0.0.1:8123/",
				data: {'code': editor.getValue()},
				cache: false,
				success: function (data) {showSvg(data);},
				error: function () {showSvg('<circle cx="150" cy="80" r="50" stroke="black" stroke-width="2" fill="gray"/>');}
			});
		}
	);
}
);
function showSvg(s) {
	$("svg").html(s);
}