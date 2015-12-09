$(document).ready(
function () {
	$('#image').mousedown(
		function (event) {
			var startX = event.pageX + $(window).width() - $('#image').offset().left - $('#image').width();
			var startY = event.pageY + $(window).height() - $('#image').offset().top - $('#image').height();
			$(document).mousemove(
				function (event) {
					var obj = $('#image');
					obj.css({'right': startX - event.pageX, 'bottom': startY - event.pageY});
				}
			).mouseup(
				function () {
					$(document).unbind("mousemove");
					$(document).unbind("mousemup");
					editor.focus();
				}
			);
		}
	);
	var id = -1;
	function run() {
		id = -1;
		$.ajax({
			type: "POST",
			url: "http://127.0.0.1:8123/",
			data: {
				width: $('#image').width(),
				height: $('#image').height(),
				code: editor.getValue()
			},
			cache: false,
			success: function (data) {showSvg(data);},
			error: function () {}
		});
	}
	editor.getSession().on("change", function(e) {
		if (id != -1)
			window.clearTimeout(id);
		id = window.setTimeout(run, 500);
	});
}
);
function showSvg(s) {
	$("svg").html(s);
}