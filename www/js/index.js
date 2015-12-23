var storage = window.localStorage;
if (!storage.getItem("pixel_content"))
	storage.setItem("pixel_content", JSON.stringify([""]));
content = JSON.parse(storage.getItem("pixel_content"));
$(document).ready(
function () {
	var editor = ace.edit("editor");
	editor.setTheme("ace/theme/monokai");
	editor.setHighlightActiveLine(false);
	editor.getSession().setMode("ace/mode/pixel");
	editor.getSession().setUseSoftTabs(false);
	editor.$blockScrolling = Infinity;
	$('#image>svg').mousedown(
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
	$('#image>#left').mousedown(
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
	$('#image>#right').mousedown(
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
	$('#image>#top').mousedown(
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
	$('#image>#bottom').mousedown(
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
		val = editor.getValue();
		content[parseInt($("#tab li.active").attr("tabid")) - 1] = val;
		storage.setItem("pixel_content", JSON.stringify(content));
		if (val == "") {
			aid = null;
			showSvg("");
		} else {
			aid = $.ajax({
				type: "POST",
				url: "http://127.0.0.1:8123/",
				data: {
					width: $('#image').width(),
					height: $('#image').height(),
					code: val
				},
				cache: false,
				success: function (data) {showSvg(data);},
				error: function (a, b) {
					showSvg("Network connection timed out.");
				},
				complete: function () {aid = null;}
			});
			}
		editor.focus();
	}
	editor.getSession().on("change", function(e) {
		if (tid)
			window.clearTimeout(tid);
		tid = window.setTimeout(run, e.lines.length <= 1 ? 2000 : 50);
	});
	function click_tab() {
		if ($(this).hasClass("active")) {
			content.splice(parseInt($(this).attr("tabid")) - 1, 1);
			if ($(this).next().attr("id") == "add") {
				if ($(this).attr("tabid") == "1") {
					content = [""];
				} else {
					$(this).prev().addClass("active");
					$(this).remove();
				}
			} else
				$("#tab li:not(#add):last").remove();
		} else {
			last_active = $("#tab li.active");
			content[parseInt(last_active.attr("tabid")) - 1] = editor.getValue();
			last_active.removeClass("active");
			$(this).addClass("active");
		}
		editor.setValue(content[parseInt($("#tab li.active").attr("tabid")) - 1], -1);
		storage.setItem("pixel_content", JSON.stringify(content));
		if (tid)
			window.clearTimeout(tid);
		tid = window.setTimeout(run, 50);
	}
	$("#tab ul").append($('<li tabid="1" class="active"><div></div></li>').click(click_tab));
	if (content[0] != "") {
		editor.setValue(content[0], -1);
		if (tid)
			window.clearTimeout(tid);
		tid = window.setTimeout(run, 50);
	}
	for (i = 2; i <= content.length; i++) {
		$("#tab ul").append($('<li tabid="' + i + '"><div></div></li>').click(click_tab));
	}
	$("#tab ul").append($('<li id="add"><div></div></li>'));
	$("#tab li#add").click(function () {
		new_tab = parseInt($("#tab li:not(#add):last").attr("tabid")) + 1;
		last_active = $("#tab li.active");
		content[parseInt(last_active.attr("tabid")) - 1] = editor.getValue();
		last_active.removeClass("active");
		content.push("");
		editor.setValue("", -1);
		if (tid)
			window.clearTimeout(tid);
		tid = window.setTimeout(run, 50);
		$(this).before($('<li tabid="' + new_tab + '" class="active"><div></div></li>').click(click_tab));
	});
}
);
function showSvg(s) {
	start = s.indexOf('<');
	if (start == 0 || s.trim() == '') {
		$('#log_content').css("background-color", "rgb(200, 234, 200)");
		$('#log_content').html("<div><span>success.</span></div>");
		$('#image>svg').html(s);
	} else {
		$('#log_content').css("background-color", "rgb(234, 200, 200)");
		msg = (start == -1 ? s : s.substr(0, start))
				.trim()
				.split('\n')
				.join('</span></div><div><span>');
		msg = "<div><span>" +
				(msg ? msg : "Compile error.") +
				"</span></div>";
		$('#log_content').html(msg);
		if (start != -1) {
			$('#image>svg').html(s.substr(start));
		}
	}
}