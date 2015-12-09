$(document).ready(
function () {
	$('svg').mousedown(
		function (event) {
			var startX = event.pageX + $(window).width() - $('#image').offset().left - $('#image').width();
			var startY = event.pageY + $(window).height() - $('#image').offset().top - $('#image').height();
			$(document).mousemove(
				function (event) {
					$('#image').css({'right': startX - event.pageX, 'bottom': startY - event.pageY});
				}
			).mouseup(
				function () {
					$(document).unbind("mousemove");
					$(document).unbind("mouseup");
					editor.focus();
				}
			);
		}
	);
	$('#image #left').mousedown(
		function (event) {
			var startW = event.pageX + $('#image').width();
			$(document).mousemove(
				function (event) {
					if (startW - event.pageX > 50) {
						$('#image').css({'width': startW - event.pageX});
					}
				}
			).mouseup(
				function () {
					$(document).unbind("mousemove");
					$(document).unbind("mouseup");
					editor.focus();
				}
			);
		}
	);
	$('#image #right').mousedown(
		function (event) {
			var startW = event.pageX - $('#image').width();
			var startX = event.pageX + $(window).width() - $('#image').offset().left - $('#image').width();
			$(document).mousemove(
				function (event) {
					if (event.pageX - startW > 50) {
						$('#image').css({'width': event.pageX - startW, 'right': startX - event.pageX});
					}
				}
			).mouseup(
				function () {
					$(document).unbind("mousemove");
					$(document).unbind("mouseup");
					editor.focus();
				}
			);
		}
	);
	$('#image #top').mousedown(
		function (event) {
			var startH = event.pageY + $('#image').height();
			$(document).mousemove(
				function (event) {
					if (startH - event.pageY > 50) {
						$('#image').css({'height': startH - event.pageY});
					}
				}
			).mouseup(
				function () {
					$(document).unbind("mousemove");
					$(document).unbind("mouseup");
					editor.focus();
				}
			);
		}
	);
	$('#image #bottom').mousedown(
		function (event) {
			var startH = event.pageY - $('#image').height();
			var startY = event.pageY + $(window).height() - $('#image').offset().top - $('#image').height();
			$(document).mousemove(
				function (event) {
					if (event.pageY - startH > 50) {
						$('#image').css({'height': event.pageY - startH, 'bottom': startY - event.pageY});
					}
				}
			).mouseup(
				function () {
					$(document).unbind("mousemove");
					$(document).unbind("mouseup");
					editor.focus();
				}
			);
		}
	);
	var tid = null;
	var aid = null;
	function run() {
		tid = null;
		if (aid)
			aid.abort();
		aid = $.ajax({
			type: "POST",
			url: "http://127.0.0.1:8123/",
			data: {
				width: $('#image').width(),
				height: $('#image').height(),
				code: editor.getValue()
			},
			cache: false,
			success: function (data) {showSvg(data);},
			error: function () {},
			complete: function () {aid = null;}
		});
	}
	editor.getSession().on("change", function(e) {
		if (tid)
			window.clearTimeout(id);
		tid = window.setTimeout(run, 500);
	});
}
);
function showSvg(s) {
	start = s.search('<');
	svgcode = start == -1 ? '' : s.substr(start + 1);
	$("svg").html(svgcode);
}