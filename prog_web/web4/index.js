!(function (t) {
	var e = {};
	function i(s) {
		if (e[s]) return e[s].exports;
		var n = (e[s] = { i: s, l: !1, exports: {} });
		return t[s].call(n.exports, n, n.exports, i), (n.l = !0), n.exports;
	}
	(i.m = t),
		(i.c = e),
		(i.d = function (t, e, s) {
			i.o(t, e) || Object.defineProperty(t, e, { enumerable: !0, get: s });
		}),
		(i.r = function (t) {
			"undefined" != typeof Symbol &&
				Symbol.toStringTag &&
				Object.defineProperty(t, Symbol.toStringTag, { value: "Module" }),
				Object.defineProperty(t, "__esModule", { value: !0 });
		}),
		(i.t = function (t, e) {
			if ((1 & e && (t = i(t)), 8 & e)) return t;
			if (4 & e && "object" == typeof t && t && t.__esModule) return t;
			var s = Object.create(null);
			if (
				(i.r(s),
				Object.defineProperty(s, "default", { enumerable: !0, value: t }),
				2 & e && "string" != typeof t)
			)
				for (var n in t)
					i.d(
						s,
						n,
						function (e) {
							return t[e];
						}.bind(null, n)
					);
			return s;
		}),
		(i.n = function (t) {
			var e =
				t && t.__esModule
					? function () {
							return t.default;
					  }
					: function () {
							return t;
					  };
			return i.d(e, "a", e), e;
		}),
		(i.o = function (t, e) {
			return Object.prototype.hasOwnProperty.call(t, e);
		}),
		(i.p = ""),
		i((i.s = 1));
})([
	function (t, e, i) {
		var s = i(2),
			n = i(3);
		"string" == typeof (n = n.__esModule ? n.default : n) && (n = [[t.i, n, ""]]);
		var o = { insert: "head", singleton: !1 };
		s(n, o);
		t.exports = n.locals || {};
	},
	function (t, e, i) {
		i(6), (t.exports = i(5));
	},
	function (t, e, i) {
		"use strict";
		var s,
			n = function () {
				return (
					void 0 === s &&
						(s = Boolean(window && document && document.all && !window.atob)),
					s
				);
			},
			o = (function () {
				var t = {};
				return function (e) {
					if (void 0 === t[e]) {
						var i = document.querySelector(e);
						if (window.HTMLIFrameElement && i instanceof window.HTMLIFrameElement)
							try {
								i = i.contentDocument.head;
							} catch (t) {
								i = null;
							}
						t[e] = i;
					}
					return t[e];
				};
			})(),
			h = [];
		function a(t) {
			for (var e = -1, i = 0; i < h.length; i++)
				if (h[i].identifier === t) {
					e = i;
					break;
				}
			return e;
		}
		function r(t, e) {
			for (var i = {}, s = [], n = 0; n < t.length; n++) {
				var o = t[n],
					r = e.base ? o[0] + e.base : o[0],
					l = i[r] || 0,
					g = "".concat(r, " ").concat(l);
				i[r] = l + 1;
				var c = a(g),
					d = { css: o[1], media: o[2], sourceMap: o[3] };
				-1 !== c
					? (h[c].references++, h[c].updater(d))
					: h.push({ identifier: g, updater: f(d, e), references: 1 }),
					s.push(g);
			}
			return s;
		}
		function l(t) {
			var e = document.createElement("style"),
				s = t.attributes || {};
			if (void 0 === s.nonce) {
				var n = i.nc;
				n && (s.nonce = n);
			}
			if (
				(Object.keys(s).forEach(function (t) {
					e.setAttribute(t, s[t]);
				}),
				"function" == typeof t.insert)
			)
				t.insert(e);
			else {
				var h = o(t.insert || "head");
				if (!h)
					throw new Error(
						"Couldn't find a style target. This probably means that the value for the 'insert' parameter is invalid."
					);
				h.appendChild(e);
			}
			return e;
		}
		var g,
			c =
				((g = []),
				function (t, e) {
					return (g[t] = e), g.filter(Boolean).join("\n");
				});
		function d(t, e, i, s) {
			var n = i
				? ""
				: s.media
				? "@media ".concat(s.media, " {").concat(s.css, "}")
				: s.css;
			if (t.styleSheet) t.styleSheet.cssText = c(e, n);
			else {
				var o = document.createTextNode(n),
					h = t.childNodes;
				h[e] && t.removeChild(h[e]),
					h.length ? t.insertBefore(o, h[e]) : t.appendChild(o);
			}
		}
		function p(t, e, i) {
			var s = i.css,
				n = i.media,
				o = i.sourceMap;
			if (
				(n ? t.setAttribute("media", n) : t.removeAttribute("media"),
				o &&
					btoa &&
					(s += "\n/*# sourceMappingURL=data:application/json;base64,".concat(
						btoa(unescape(encodeURIComponent(JSON.stringify(o)))),
						" */"
					)),
				t.styleSheet)
			)
				t.styleSheet.cssText = s;
			else {
				for (; t.firstChild; ) t.removeChild(t.firstChild);
				t.appendChild(document.createTextNode(s));
			}
		}
		var u = null,
			m = 0;
		function f(t, e) {
			var i, s, n;
			if (e.singleton) {
				var o = m++;
				(i = u || (u = l(e))),
					(s = d.bind(null, i, o, !1)),
					(n = d.bind(null, i, o, !0));
			} else
				(i = l(e)),
					(s = p.bind(null, i, e)),
					(n = function () {
						!(function (t) {
							if (null === t.parentNode) return !1;
							t.parentNode.removeChild(t);
						})(i);
					});
			return (
				s(t),
				function (e) {
					if (e) {
						if (e.css === t.css && e.media === t.media && e.sourceMap === t.sourceMap)
							return;
						s((t = e));
					} else n();
				}
			);
		}
		t.exports = function (t, e) {
			(e = e || {}).singleton ||
				"boolean" == typeof e.singleton ||
				(e.singleton = n());
			var i = r((t = t || []), e);
			return function (t) {
				if (
					((t = t || []), "[object Array]" === Object.prototype.toString.call(t))
				) {
					for (var s = 0; s < i.length; s++) {
						var n = a(i[s]);
						h[n].references--;
					}
					for (var o = r(t, e), l = 0; l < i.length; l++) {
						var g = a(i[l]);
						0 === h[g].references && (h[g].updater(), h.splice(g, 1));
					}
					i = o;
				}
			};
		};
	},
	function (t, e, i) {
		(e = i(4)(!1)).push([
			t.i,
			".stf__wrapper {\n  position: relative;\n  display: block;\n  box-sizing: border-box;\n  transform: translateZ(0);\n}\n\n.stf__wrapper canvas {\n  position: absolute;\n  width: 100%;\n  height: 100%;\n  left: 0;\n  top: 0;\n}\n\n.stf__block {\n  position: absolute;\n  width: 100%;\n  height: 100%;\n  box-sizing: border-box;\n}\n\n.stf__item {\n  display: none;\n  position: absolute;\n}\n\n.stf__outerShadow {\n  position: absolute;\n}\n\n.stf__innerShadow {\n  position: absolute;\n}",
			""
		]),
			(t.exports = e);
	},
	function (t, e, i) {
		"use strict";
		t.exports = function (t) {
			var e = [];
			return (
				(e.toString = function () {
					return this.map(function (e) {
						var i = (function (t, e) {
							var i = t[1] || "",
								s = t[3];
							if (!s) return i;
							if (e && "function" == typeof btoa) {
								var n =
										((h = s),
										(a = btoa(unescape(encodeURIComponent(JSON.stringify(h))))),
										(r = "sourceMappingURL=data:application/json;charset=utf-8;base64,".concat(
											a
										)),
										"/*# ".concat(r, " */")),
									o = s.sources.map(function (t) {
										return "/*# sourceURL=".concat(s.sourceRoot || "").concat(t, " */");
									});
								return [i].concat(o).concat([n]).join("\n");
							}
							var h, a, r;
							return [i].join("\n");
						})(e, t);
						return e[2] ? "@media ".concat(e[2], " {").concat(i, "}") : i;
					}).join("");
				}),
				(e.i = function (t, i, s) {
					"string" == typeof t && (t = [[null, t, ""]]);
					var n = {};
					if (s)
						for (var o = 0; o < this.length; o++) {
							var h = this[o][0];
							null != h && (n[h] = !0);
						}
					for (var a = 0; a < t.length; a++) {
						var r = [].concat(t[a]);
						(s && n[r[0]]) ||
							(i && (r[2] ? (r[2] = "".concat(i, " and ").concat(r[2])) : (r[2] = i)),
							e.push(r));
					}
				}),
				e
			);
		};
	},
	function (t, e, i) {},
	function (t, e, i) {
		"use strict";
		i.r(e);
		class s {
			constructor(t) {
				(this.state = {
					angle: 0,
					area: [],
					corners: null,
					position: { x: 0, y: 0 }
				}),
					(this.render = t);
			}
			setPosition(t) {
				this.state.position = t;
			}
			setAngle(t) {
				this.state.angle = t;
			}
			setArea(t) {
				this.state.area = t;
			}
			setCorners(t) {
				this.state.corners = t;
			}
			getAngle() {
				return this.state.angle;
			}
		}
		class n extends s {
			constructor(t, e) {
				super(t),
					(this.image = null),
					(this.isLoad = !1),
					(this.loadingAngle = 0),
					(this.image = new Image()),
					(this.image.src = e);
			}
			draw() {
				const t = this.render.getContext(),
					e = this.render.convertToGlobal(this.state.position),
					i = this.render.getRect().pageWidth,
					s = this.render.getRect().height;
				t.save(), t.translate(e.x, e.y), t.beginPath();
				for (let i of this.state.area)
					null !== i &&
						((i = this.render.convertToGlobal(i)), t.lineTo(i.x - e.x, i.y - e.y));
				if ((t.rotate(this.state.angle), t.clip(), this.isLoad))
					t.drawImage(this.image, 0, 0, i, s);
				else {
					t.beginPath(),
						(t.strokeStyle = "rgb(200, 200, 200)"),
						(t.fillStyle = "rgb(255, 255, 255)"),
						(t.lineWidth = 1),
						t.rect(1, 1, i - 1, s - 1),
						t.stroke(),
						t.fill();
					const e = { x: i / 2, y: s / 2 };
					t.beginPath(),
						(t.lineWidth = 10),
						t.arc(
							e.x,
							e.y,
							20,
							this.loadingAngle,
							(3 * Math.PI) / 2 + this.loadingAngle
						),
						t.stroke(),
						t.closePath(),
						(this.loadingAngle += 0.07),
						this.loadingAngle >= 2 * Math.PI && (this.loadingAngle = 0);
				}
				t.restore();
			}
			simpleDraw(t) {
				const e = this.render.getRect(),
					i = this.render.getContext(),
					s = e.pageWidth,
					n = e.height,
					o = 1 === t ? e.left + e.pageWidth : e.left,
					h = e.top;
				if (this.isLoad) i.drawImage(this.image, o, h, s, n);
				else {
					i.beginPath(),
						(i.strokeStyle = "rgb(200, 200, 200)"),
						(i.fillStyle = "rgb(255, 255, 255)"),
						(i.lineWidth = 1),
						i.rect(o + 1, h + 1, s - 1, n - 1),
						i.stroke(),
						i.fill();
					const t = { x: o + s / 2, y: h + n / 2 };
					i.beginPath(),
						(i.lineWidth = 10),
						i.arc(
							t.x,
							t.y,
							20,
							this.loadingAngle,
							(3 * Math.PI) / 2 + this.loadingAngle
						),
						i.stroke(),
						i.closePath(),
						(this.loadingAngle += 0.07),
						this.loadingAngle >= 2 * Math.PI && (this.loadingAngle = 0);
				}
			}
			load() {
				this.isLoad ||
					(this.image.onload = () => {
						this.isLoad = !0;
					});
			}
		}
		class o {
			constructor(t, e) {
				(this.pages = []), (this.render = e), (this.app = t);
			}
			getPageCount() {
				return this.pages.length;
			}
			getPages() {
				return this.pages;
			}
			getPage(t) {
				if (t >= 0 && t < this.pages.length) return this.pages[t];
				throw new Error("Invalid page number");
			}
			show(t) {
				t < 0 ||
					t >= this.pages.length ||
					(this.app.updatePage(t),
					"portrait" === this.render.getOrientation()
						? (this.render.setLeftPage(null), this.render.setRightPage(this.pages[t]))
						: (t === this.pages.length - 1 && t--,
						  this.render.setLeftPage(this.pages[t]),
						  this.render.setRightPage(this.pages[t + 1])));
			}
		}
		class h extends o {
			constructor(t, e, i) {
				super(t, e), (this.imagesHref = i);
			}
			load() {
				for (const t of this.imagesHref) {
					const e = new n(this.render, t);
					e.load(), this.pages.push(e);
				}
			}
		}
		class a {
			static GetDestinationFromTwoPoint(t, e) {
				return null === t || null === e
					? 1 / 0
					: Math.sqrt(Math.pow(e.x - t.x, 2) + Math.pow(e.y - t.y, 2));
			}
			static GetSegmentLength(t) {
				return a.GetDestinationFromTwoPoint(t[0], t[1]);
			}
			static GetAngleFromTwoLine(t, e) {
				const i = t[0].y - t[1].y,
					s = e[0].y - e[1].y,
					n = t[1].x - t[0].x,
					o = e[1].x - e[0].x;
				return Math.acos(
					(i * s + n * o) / (Math.sqrt(i * i + n * n) * Math.sqrt(s * s + o * o))
				);
			}
			static PointInRect(t, e) {
				return null === e
					? null
					: e.x >= t.left &&
					  e.x <= t.width + t.left &&
					  e.y >= t.top &&
					  e.y <= t.top + t.height
					? e
					: null;
			}
			static GetRotatedPoint(t, e, i) {
				return {
					x: t.x * Math.cos(i) + t.y * Math.sin(i) + e.x,
					y: t.y * Math.cos(i) - t.x * Math.sin(i) + e.y
				};
			}
			static GetIntersectByLineAndCircle(t, e, i) {
				if (a.GetDestinationFromTwoPoint(t, i) <= e) return i;
				const s = t.x,
					n = t.y,
					o = i.x,
					h = i.y;
				let r =
					Math.sqrt(
						(Math.pow(e, 2) * Math.pow(s - o, 2)) /
							(Math.pow(s - o, 2) + Math.pow(n - h, 2))
					) + s;
				i.x < 0 && (r *= -1);
				let l = ((r - s) * (n - h)) / (s - o) + n;
				return s - o + n === 0 && (l = e), { x: r, y: l };
			}
			static GetIntersectByTwoSegment(t, e, i) {
				return a.PointInRect(t, a.GetIntersectByTwoLine(e, i));
			}
			static GetIntersectByTwoLine(t, e) {
				const i = t[0].y - t[1].y,
					s = e[0].y - e[1].y,
					n = t[1].x - t[0].x,
					o = e[1].x - e[0].x,
					h = t[0].x * t[1].y - t[1].x * t[0].y,
					a = e[0].x * e[1].y - e[1].x * e[0].y,
					r = i * a - s * h,
					l = n * a - o * h,
					g = -(h * o - a * n) / (i * o - s * n),
					c = -(i * a - s * h) / (i * o - s * n);
				if (isFinite(g) && isFinite(c)) return { x: g, y: c };
				if (Math.abs(r - l) < 0.1) throw new Error("Segment included");
				return null;
			}
			static GetCordsFromTwoPoint(t, e) {
				const i = Math.abs(t.x - e.x),
					s = Math.abs(t.y - e.y),
					n = Math.max(i, s),
					o = [t];
				function h(t, e, i, s, n) {
					return e > t ? t + n * (i / s) : e < t ? t - n * (i / s) : t;
				}
				for (let a = 1; a <= n; a++)
					o.push({ x: h(t.x, e.x, i, n, a), y: h(t.y, e.y, s, n, a) });
				return o;
			}
		}
		class r extends s {
			constructor(t, e) {
				super(t),
					(this.copiedElement = null),
					(this.isLoad = !1),
					(this.element = e),
					this.element.classList.add("stf__item"),
					(this.element.style.position = "absolute"),
					(this.element.style.left = "0"),
					(this.element.style.top = "0"),
					(this.element.style.boxSizing = "border-box");
			}
			draw() {
				const t = this.render.convertToGlobal(this.state.position),
					e = this.render.getRect().pageWidth,
					i = this.render.getRect().height;
				this.element.classList.remove("--simple"),
					(this.element.style.display = "block"),
					(this.element.style.left = "0"),
					(this.element.style.top = "0"),
					(this.element.style.transformOrigin = "0 0"),
					(this.element.style.width = e + "px"),
					(this.element.style.height = i + "px");
				let s = "polygon( ";
				for (const t of this.state.area)
					if (null !== t) {
						let e =
							1 === this.render.getDirection()
								? { x: -t.x + this.state.position.x, y: t.y - this.state.position.y }
								: { x: t.x - this.state.position.x, y: t.y - this.state.position.y };
						(e = a.GetRotatedPoint(e, { x: 0, y: 0 }, this.state.angle)),
							(s += e.x + "px " + e.y + "px, ");
					}
				(s = s.slice(0, -2)),
					(s += ")"),
					(this.element.style.clipPath = s),
					this.element.style.setProperty("-webkit-clip-path", s),
					(this.element.style.transform =
						"translate3d(" +
						t.x +
						"px, " +
						t.y +
						"px, 0) rotate(" +
						this.state.angle +
						"rad)");
			}
			simpleDraw(t) {
				if (this.element.classList.contains("--simple")) return;
				null === this.copiedElement &&
					((this.copiedElement = this.element.cloneNode(!0)),
					this.element.parentElement.appendChild(this.copiedElement));
				const e = this.render.getRect(),
					i = e.pageWidth,
					s = e.height,
					n = 1 === t ? e.left + e.pageWidth : e.left,
					o = e.top;
				this.element.classList.add("--simple"),
					(this.copiedElement.style.cssText =
						"position: absolute; display: block; height: " +
						s +
						"px; left: " +
						n +
						"px; top: " +
						o +
						"px; width: " +
						i +
						"px; z-index: " +
						(this.render.getSettings().startZIndex + 1) +
						";"),
					(this.element.style.cssText = "display: none");
			}
			clearSaved() {
				this.element.classList.remove("--simple"),
					null !== this.copiedElement &&
						(this.copiedElement.remove(), (this.copiedElement = null));
			}
			getElement() {
				return this.element;
			}
			load() {
				this.isLoad = !0;
			}
		}
		class l extends o {
			constructor(t, e, i, s) {
				super(t, e), (this.element = i), (this.pagesElement = s);
			}
			load() {
				for (const t of this.pagesElement) {
					const e = new r(this.render, t);
					e.load(), this.pages.push(e);
				}
			}
		}
		class g {
			constructor(t, e, i, s) {
				(this.direction = t),
					(this.corner = e),
					(this.pageWidth = i),
					(this.pageHeight = s),
					(this.topIntersectPoint = null),
					(this.sideIntersectPoint = null),
					(this.bottomIntersectPoint = null);
			}
			calc(t) {
				try {
					(this.position = this.preparePosition(t)),
						this.calculateIntersectPoint(this.position);
				} catch (t) {}
			}
			getPageRect(t) {
				return "top" === this.corner
					? this.getRectFromBasePoint(
							[
								{ x: 0, y: 0 },
								{ x: this.pageWidth, y: 0 },
								{ x: 0, y: this.pageHeight },
								{ x: this.pageWidth, y: this.pageHeight }
							],
							t
					  )
					: this.getRectFromBasePoint(
							[
								{ x: 0, y: -this.pageHeight },
								{ x: this.pageWidth, y: -this.pageHeight },
								{ x: 0, y: 0 },
								{ x: this.pageWidth, y: 0 }
							],
							t
					  );
			}
			getRectFromBasePoint(t, e) {
				return {
					topLeft: this.getRotatedPoint(t[0], e),
					topRight: this.getRotatedPoint(t[1], e),
					bottomLeft: this.getRotatedPoint(t[2], e),
					bottomRight: this.getRotatedPoint(t[3], e)
				};
			}
			getRotatedPoint(t, e) {
				return {
					x: t.x * Math.cos(this.angle) + t.y * Math.sin(this.angle) + e.x,
					y: t.y * Math.cos(this.angle) - t.x * Math.sin(this.angle) + e.y
				};
			}
			updateAngleAndGeometry(t) {
				(this.angle = this.calculateAngle(t)), (this.rect = this.getPageRect(t));
			}
			calculateIntersectPoint(t) {
				const e = {
					left: -1,
					top: -1,
					width: this.pageWidth + 2,
					height: this.pageHeight + 2
				};
				"top" === this.corner
					? ((this.topIntersectPoint = a.GetIntersectByTwoSegment(
							e,
							[t, this.rect.topRight],
							[
								{ x: 0, y: 0 },
								{ x: this.pageWidth, y: 0 }
							]
					  )),
					  (this.sideIntersectPoint = a.GetIntersectByTwoSegment(
							e,
							[t, this.rect.bottomLeft],
							[
								{ x: this.pageWidth, y: 0 },
								{ x: this.pageWidth, y: this.pageHeight }
							]
					  )),
					  (this.bottomIntersectPoint = a.GetIntersectByTwoSegment(
							e,
							[this.rect.bottomLeft, this.rect.bottomRight],
							[
								{ x: 0, y: this.pageHeight },
								{ x: this.pageWidth, y: this.pageHeight }
							]
					  )))
					: ((this.topIntersectPoint = a.GetIntersectByTwoSegment(
							e,
							[this.rect.topLeft, this.rect.topRight],
							[
								{ x: 0, y: 0 },
								{ x: this.pageWidth, y: 0 }
							]
					  )),
					  (this.sideIntersectPoint = a.GetIntersectByTwoSegment(
							e,
							[t, this.rect.topLeft],
							[
								{ x: this.pageWidth, y: 0 },
								{ x: this.pageWidth, y: this.pageHeight }
							]
					  )),
					  (this.bottomIntersectPoint = a.GetIntersectByTwoSegment(
							e,
							[this.rect.bottomLeft, this.rect.bottomRight],
							[
								{ x: 0, y: this.pageHeight },
								{ x: this.pageWidth, y: this.pageHeight }
							]
					  )));
			}
			checkPositionAtCenterLine(t, e, i) {
				let s = t;
				const n = a.GetIntersectByLineAndCircle(e, this.pageWidth, s);
				s !== n && ((s = n), this.updateAngleAndGeometry(s));
				const o = Math.sqrt(
					Math.pow(this.pageWidth, 2) + Math.pow(this.pageHeight, 2)
				);
				let h = this.rect.bottomRight,
					r = this.rect.topLeft;
				if (
					("bottom" === this.corner &&
						((h = this.rect.topRight), (r = this.rect.bottomLeft)),
					h.x <= 0)
				) {
					const t = a.GetIntersectByLineAndCircle(i, o, r);
					t !== s && ((s = t), this.updateAngleAndGeometry(s));
				}
				return s;
			}
			preparePosition(t) {
				let e = t;
				if (
					(this.updateAngleAndGeometry(e),
					(e =
						"top" === this.corner
							? this.checkPositionAtCenterLine(
									e,
									{ x: 0, y: 0 },
									{ x: 0, y: this.pageHeight }
							  )
							: this.checkPositionAtCenterLine(
									e,
									{ x: 0, y: this.pageHeight },
									{ x: 0, y: 0 }
							  )),
					Math.abs(e.x - this.pageWidth) < 1 && Math.abs(e.y) < 1)
				)
					throw new Error("Point is too small");
				return e;
			}
			calculateAngle(t) {
				const e = this.pageWidth - t.x,
					i = "bottom" === this.corner ? this.pageHeight - t.y : t.y;
				let s = 2 * Math.acos(e / Math.sqrt(i * i + e * e));
				i < 0 && (s = -s);
				const n = Math.PI - s;
				if (!isFinite(s) || (n >= 0 && n < 0.003))
					throw new Error("The G point is too small");
				return "bottom" === this.corner && (s = -s), s;
			}
			getAngle() {
				return 0 === this.direction ? -this.angle : this.angle;
			}
			getRect() {
				return this.rect;
			}
			getPosition() {
				return this.position;
			}
			getActiveCorner() {
				return 0 === this.direction ? this.rect.topLeft : this.rect.topRight;
			}
			getDirection() {
				return this.direction;
			}
			getIntersectPoint() {
				return {
					top: this.topIntersectPoint,
					bottom: this.bottomIntersectPoint,
					side: this.sideIntersectPoint
				};
			}
			getSegmentToShadowLine() {
				const t = this.getShadowStartPoint();
				return [
					t,
					t !== this.sideIntersectPoint && null !== this.sideIntersectPoint
						? this.sideIntersectPoint
						: this.bottomIntersectPoint
				];
			}
			getShadowStartPoint() {
				return "top" === this.corner
					? this.topIntersectPoint
					: null !== this.sideIntersectPoint
					? this.sideIntersectPoint
					: this.topIntersectPoint;
			}
			getShadowAngle() {
				const t = a.GetAngleFromTwoLine(this.getSegmentToShadowLine(), [
					{ x: 0, y: 0 },
					{ x: this.pageWidth, y: 0 }
				]);
				return 0 === this.direction ? t : Math.PI - t;
			}
			getShadowLength() {
				return a.GetSegmentLength(this.getSegmentToShadowLine());
			}
			getFlippingProgress() {
				return Math.abs(
					((this.position.x - this.pageWidth) / (2 * this.pageWidth)) * 100
				);
			}
			getFlippingClipArea() {
				const t = [];
				let e = !1;
				return (
					t.push(this.rect.topLeft),
					t.push(this.topIntersectPoint),
					null === this.sideIntersectPoint
						? (e = !0)
						: (t.push(this.sideIntersectPoint),
						  null === this.bottomIntersectPoint && (e = !1)),
					t.push(this.bottomIntersectPoint),
					(e || "bottom" === this.corner) && t.push(this.rect.bottomLeft),
					t
				);
			}
			getCorner() {
				return this.corner;
			}
			getBottomClipArea() {
				const t = [];
				return (
					t.push(this.topIntersectPoint),
					"top" === this.corner
						? t.push({ x: this.pageWidth, y: 0 })
						: (null !== this.topIntersectPoint && t.push({ x: this.pageWidth, y: 0 }),
						  t.push({ x: this.pageWidth, y: this.pageHeight })),
					null !== this.sideIntersectPoint
						? a.GetDestinationFromTwoPoint(
								this.sideIntersectPoint,
								this.topIntersectPoint
						  ) >= 10 && t.push(this.sideIntersectPoint)
						: "top" === this.corner &&
						  t.push({ x: this.pageWidth, y: this.pageHeight }),
					t.push(this.bottomIntersectPoint),
					t.push(this.topIntersectPoint),
					t
				);
			}
			getBottomPagePosition() {
				return 1 === this.direction ? { x: this.pageWidth, y: 0 } : { x: 0, y: 0 };
			}
		}
		class c {
			constructor(t, e) {
				(this.flippingPage = null),
					(this.bottomPage = null),
					(this.calc = null),
					(this.state = "read"),
					(this.render = t),
					(this.app = e);
			}
			getCalculation() {
				return this.calc;
			}
			start(t) {
				this.reset();
				const e = this.render.convertToBook(t),
					i = this.getBoundsRect();
				let s = 0;
				"portrait" === this.render.getOrientation()
					? e.x - i.pageWidth <= i.width / 5 && (s = 1)
					: e.x < i.width / 2 && (s = 1);
				const n = e.y >= i.height / 2 ? "bottom" : "top";
				if (!this.checkDirection(s)) return !1;
				try {
					return (
						(this.flippingPage = this.getFlippingPage(s)),
						(this.bottomPage = this.getBottomPage(s)),
						this.flippingPage && this.bottomPage
							? (this.render.setDirection(s),
							  (this.calc = new g(s, n, i.pageWidth, i.height)),
							  !0)
							: !1
					);
				} catch (t) {
					return !1;
				}
			}
			showCorner(t) {
				if (!this.checkState("read", "fold_corner")) return;
				const e = this.getBoundsRect(),
					i = e.pageWidth,
					s = Math.sqrt(Math.pow(i, 2) + Math.pow(e.height, 2)) / 5,
					n = this.render.convertToBook(t);
				if (
					n.x > 0 &&
					n.y > 0 &&
					n.x < e.width &&
					n.y < e.height &&
					(n.x < s || n.x > e.width - s) &&
					(n.y < s || n.y > e.height - s)
				)
					if (null === this.calc) {
						if (!this.start(t)) return;
						this.setState("fold_corner"), this.calc.calc({ x: i - 1, y: 1 });
						const s = 50,
							n = "bottom" === this.calc.getCorner() ? e.height - 1 : 1,
							o = "bottom" === this.calc.getCorner() ? e.height - s : s;
						this.animateFlippingTo({ x: i - 1, y: n }, { x: i - s, y: o }, !1, !1);
					} else this.do(this.render.convertToPage(t));
				else this.setState("read"), this.render.finishAnimation(), this.stopMove();
			}
			fold(t) {
				this.setState("user_fold"),
					null === this.calc && this.start(t),
					this.do(this.render.convertToPage(t));
			}
			flip(t) {
				if ((null !== this.calc && this.render.finishAnimation(), !this.start(t)))
					return;
				const e = this.getBoundsRect();
				this.setState("flipping");
				const i = e.height / 10,
					s = "bottom" === this.calc.getCorner() ? e.height - i : i,
					n = "bottom" === this.calc.getCorner() ? e.height : 0;
				this.calc.calc({ x: e.pageWidth - i, y: s }),
					this.animateFlippingTo(
						{ x: e.pageWidth - i, y: s },
						{ x: -e.pageWidth, y: n },
						!0
					);
			}
			flipNext(t) {
				this.flip({
					x: this.render.getRect().left + 2 * this.render.getRect().pageWidth,
					y: "top" === t ? 1 : this.render.getRect().height - 2
				});
			}
			flipPrev(t) {
				this.flip({ x: 10, y: "top" === t ? 1 : this.render.getRect().height - 2 });
			}
			stopMove() {
				if (null === this.calc) return;
				const t = this.calc.getPosition(),
					e = this.getBoundsRect(),
					i = "bottom" === this.calc.getCorner() ? e.height : 0;
				t.x <= 0
					? this.animateFlippingTo(t, { x: -e.pageWidth, y: i }, !0)
					: this.animateFlippingTo(t, { x: e.pageWidth, y: i }, !1);
			}
			do(t) {
				null !== this.calc &&
					(this.calc.calc(t),
					this.flippingPage.setArea(this.calc.getFlippingClipArea()),
					this.flippingPage.setPosition(this.calc.getActiveCorner()),
					this.flippingPage.setAngle(this.calc.getAngle()),
					this.bottomPage.setArea(this.calc.getBottomClipArea()),
					this.bottomPage.setPosition(this.calc.getBottomPagePosition()),
					this.bottomPage.setAngle(0),
					this.render.setPageRect(this.calc.getRect()),
					this.render.setBottomPage(this.bottomPage),
					this.render.setFlippingPage(this.flippingPage),
					this.render.drawShadow(
						this.calc.getShadowStartPoint(),
						this.calc.getShadowAngle(),
						this.calc.getFlippingProgress(),
						this.calc.getDirection(),
						this.calc.getShadowLength()
					));
			}
			animateFlippingTo(t, e, i, s = !0) {
				const n = a.GetCordsFromTwoPoint(t, e),
					o = [];
				for (const t of n) o.push(() => this.do(t));
				const h = this.getAnimationDuration(n.length);
				this.render.startAnimation(o, h, () => {
					this.calc &&
						(i &&
							(1 === this.calc.getDirection()
								? this.app.turnToPrevPage()
								: this.app.turnToNextPage()),
						s &&
							(this.render.setBottomPage(null),
							this.render.setFlippingPage(null),
							this.render.clearShadow(),
							(this.state = "read"),
							this.reset()));
				});
			}
			getAnimationDuration(t) {
				const e = this.app.getSettings().flippingTime;
				return t >= 1e3 ? e : (t / 1e3) * e;
			}
			getFlippingPage(t) {
				const e = this.app.getCurrentPageIndex();
				return "portrait" === this.render.getOrientation()
					? 0 === t
						? this.app.getPage(e)
						: this.app.getPage(e - 1)
					: e < this.app.getPageCount() - 1 && e >= 0
					? 0 === t
						? this.app.getPage(e + 2)
						: this.app.getPage(e - 1)
					: null;
			}
			getNextPage() {
				const t = this.app.getCurrentPageIndex(),
					e = "portrait" === this.render.getOrientation() ? 0 : 2;
				return t < this.app.getPageCount() - e ? this.app.getPage(t + e + 1) : null;
			}
			getPrevPage() {
				const t = this.app.getCurrentPageIndex(),
					e = "portrait" === this.render.getOrientation() ? 0 : 2;
				return t - e >= 0 ? this.app.getPage(t - e) : null;
			}
			getBottomPage(t) {
				return 0 === t ? this.getNextPage() : this.getPrevPage();
			}
			checkDirection(t) {
				return 0 === t
					? this.app.getCurrentPageIndex() <= this.app.getPageCount() - 1
					: this.app.getCurrentPageIndex() >= 1;
			}
			reset() {
				(this.calc = null), (this.flippingPage = null), (this.bottomPage = null);
			}
			getBoundsRect() {
				return this.render.getRect();
			}
			getPageWidth() {
				return this.getBoundsRect().width / 2;
			}
			getPageHeight() {
				return this.getBoundsRect().height;
			}
			setState(t) {
				this.app.updateState(t), (this.state = t);
			}
			checkState(...t) {
				for (const e of t) if (this.state === e) return !0;
				return !1;
			}
		}
		class d {
			constructor(t, e) {
				(this.leftPage = null),
					(this.rightPage = null),
					(this.flippingPage = null),
					(this.bottomPage = null),
					(this.shadow = null),
					(this.pageRect = null),
					(this.animation = null),
					(this.timer = 0),
					(this.direction = null),
					(this.orientation = null),
					(this.boundsRect = null),
					(this.setting = e),
					(this.app = t);
			}
			drawShadow(t, e, i, s, n) {
				if (!this.app.getSettings().drawShadow) return;
				const o = 100 * this.getSettings().maxShadowOpacity;
				this.shadow = {
					pos: t,
					angle: e,
					width: (((3 * this.getRect().pageWidth) / 4) * i) / 100,
					opacity: ((100 - i) * o) / 100 / 100,
					direction: s,
					length: n
				};
			}
			clearShadow() {
				this.shadow = null;
			}
			setPageRect(t) {
				this.pageRect = t;
			}
			getOrientation() {
				return this.orientation;
			}
			startAnimation(t, e, i) {
				this.finishAnimation(),
					(this.animation = {
						frames: t,
						duration: e,
						durationFrame: e / t.length,
						onAnimateEnd: i,
						startedAt: this.timer
					});
			}
			finishAnimation() {
				null !== this.animation &&
					(this.animation.frames[this.animation.frames.length - 1](),
					null !== this.animation.onAnimateEnd && this.animation.onAnimateEnd()),
					(this.animation = null);
			}
			render(t) {
				if (null !== this.animation) {
					const e = Math.round(
						(t - this.animation.startedAt) / this.animation.durationFrame
					);
					e < this.animation.frames.length
						? this.animation.frames[e]()
						: (this.animation.onAnimateEnd(), (this.animation = null));
				}
				(this.timer = t), this.drawFrame(t);
			}
			getRect() {
				return (
					null === this.boundsRect && this.calculateBoundsRect(), this.boundsRect
				);
			}
			calculateBoundsRect() {
				let t = "landscape";
				const e = this.getBlockWidth(),
					i = e / 2,
					s = this.getBlockHeight() / 2,
					n = this.setting.width / this.setting.height;
				let o = this.setting.width,
					h = this.setting.height,
					a = i - o;
				return (
					"stretch" === this.setting.size
						? (e < 2 * this.setting.minWidth &&
								this.app.getSettings().usePortrait &&
								(t = "portrait"),
						  (o =
								"landscape" === t ? this.getBlockWidth() / 2 : this.getBlockWidth()),
						  o > this.setting.maxWidth && (o = this.setting.maxWidth),
						  (h = o / n),
						  h > this.getBlockHeight() && ((h = this.getBlockHeight()), (o = h * n)),
						  (a = "landscape" === t ? i - o : i - o / 2 - o))
						: e < 2 * o &&
						  this.app.getSettings().usePortrait &&
						  ((t = "portrait"), (a = i - o / 2 - o)),
					(this.boundsRect = {
						left: a,
						top: s - h / 2,
						width: 2 * o,
						height: h,
						pageWidth: o
					}),
					t
				);
			}
			update() {
				this.boundsRect = null;
				const t = this.calculateBoundsRect();
				this.orientation !== t &&
					((this.orientation = t), this.app.updateOrientation(t));
			}
			convertToBook(t) {
				const e = this.getRect();
				return { x: t.x - e.left, y: t.y - e.top };
			}
			convertToPage(t, e) {
				e || (e = this.direction);
				const i = this.getRect();
				return {
					x: 0 === e ? t.x - i.left - i.width / 2 : i.width / 2 - t.x + i.left,
					y: t.y - i.top
				};
			}
			convertToGlobal(t, e) {
				if ((e || (e = this.direction), null == t)) return null;
				const i = this.getRect();
				return {
					x: 0 === e ? t.x + i.left + i.width / 2 : i.width / 2 - t.x + i.left,
					y: t.y + i.top
				};
			}
			convertRectToGlobal(t, e) {
				return (
					e || (e = this.direction),
					{
						topLeft: this.convertToGlobal(t.topLeft, e),
						topRight: this.convertToGlobal(t.topRight, e),
						bottomLeft: this.convertToGlobal(t.bottomLeft, e),
						bottomRight: this.convertToGlobal(t.bottomRight, e)
					}
				);
			}
			start() {
				this.update();
				const t = (e) => {
					this.render(e), requestAnimationFrame(t);
				};
				requestAnimationFrame(t);
			}
			setDirection(t) {
				this.direction = t;
			}
			getDirection() {
				return this.direction;
			}
			setFlippingPage(t) {
				this.flippingPage = t;
			}
			setBottomPage(t) {
				this.bottomPage = t;
			}
			setRightPage(t) {
				this.rightPage = t;
			}
			setLeftPage(t) {
				this.leftPage = t;
			}
			getSettings() {
				return this.app.getSettings();
			}
		}
		class p extends d {
			constructor(t, e, i) {
				super(t, e), (this.canvas = i), (this.ctx = i.getContext("2d"));
			}
			getBlockWidth() {
				return this.canvas.offsetWidth;
			}
			getBlockHeight() {
				return this.canvas.offsetHeight;
			}
			getContext() {
				return this.ctx;
			}
			drawFrame(t) {
				this.clear(),
					"portrait" !== this.orientation &&
						null != this.leftPage &&
						this.leftPage.simpleDraw(0),
					null != this.rightPage && this.rightPage.simpleDraw(1),
					null != this.bottomPage && this.bottomPage.draw(),
					this.drawBookShadow(),
					null != this.flippingPage && this.flippingPage.draw(),
					null != this.shadow && (this.drawOuterShadow(), this.drawInnerShadow());
				const e = this.getRect();
				"portrait" === this.orientation &&
					(this.ctx.beginPath(),
					this.ctx.rect(e.left + e.pageWidth, e.top, e.width, e.height),
					this.ctx.clip());
			}
			drawBookShadow() {
				const t = this.getRect();
				this.ctx.save(), this.ctx.beginPath();
				const e = t.width / 20;
				this.ctx.rect(t.left, t.top, t.width, t.height);
				const i = { x: t.left + t.width / 2 - e / 2, y: 0 };
				this.ctx.translate(i.x, i.y);
				const s = this.ctx.createLinearGradient(0, 0, e, 0);
				s.addColorStop(0, "rgba(0, 0, 0, 0)"),
					s.addColorStop(0.4, "rgba(0, 0, 0, 0.2)"),
					s.addColorStop(0.49, "rgba(0, 0, 0, 0.1)"),
					s.addColorStop(0.5, "rgba(0, 0, 0, 0.5)"),
					s.addColorStop(0.51, "rgba(0, 0, 0, 0.4)"),
					s.addColorStop(1, "rgba(0, 0, 0, 0)"),
					this.ctx.clip(),
					(this.ctx.fillStyle = s),
					this.ctx.fillRect(0, 0, e, 2 * t.height),
					this.ctx.restore();
			}
			drawOuterShadow() {
				const t = this.getRect();
				this.ctx.save(),
					this.ctx.beginPath(),
					this.ctx.rect(t.left, t.top, t.width, t.height);
				const e = this.convertToGlobal({
					x: this.shadow.pos.x,
					y: this.shadow.pos.y
				});
				this.ctx.translate(e.x, e.y),
					this.ctx.rotate(Math.PI + this.shadow.angle + Math.PI / 2);
				const i = this.ctx.createLinearGradient(0, 0, this.shadow.width, 0);
				0 === this.shadow.direction
					? (this.ctx.translate(0, -100),
					  i.addColorStop(0, "rgba(0, 0, 0, " + this.shadow.opacity + ")"),
					  i.addColorStop(1, "rgba(0, 0, 0, 0)"))
					: (this.ctx.translate(-this.shadow.width, -100),
					  i.addColorStop(0, "rgba(0, 0, 0, 0)"),
					  i.addColorStop(1, "rgba(0, 0, 0, " + this.shadow.opacity + ")")),
					this.ctx.clip(),
					(this.ctx.fillStyle = i),
					this.ctx.fillRect(0, 0, this.shadow.width, 2 * t.height),
					this.ctx.restore();
			}
			drawInnerShadow() {
				const t = this.getRect();
				this.ctx.save(), this.ctx.beginPath();
				const e = this.convertToGlobal({
						x: this.shadow.pos.x,
						y: this.shadow.pos.y
					}),
					i = this.convertRectToGlobal(this.pageRect);
				this.ctx.moveTo(i.topLeft.x, i.topLeft.y),
					this.ctx.lineTo(i.topRight.x, i.topRight.y),
					this.ctx.lineTo(i.bottomRight.x, i.bottomRight.y),
					this.ctx.lineTo(i.bottomLeft.x, i.bottomLeft.y),
					this.ctx.translate(e.x, e.y),
					this.ctx.rotate(Math.PI + this.shadow.angle + Math.PI / 2);
				const s = (3 * this.shadow.width) / 4,
					n = this.ctx.createLinearGradient(0, 0, s, 0);
				0 === this.shadow.direction
					? (this.ctx.translate(-s, -100),
					  n.addColorStop(1, "rgba(0, 0, 0, " + this.shadow.opacity + ")"),
					  n.addColorStop(0.9, "rgba(0, 0, 0, 0.05)"),
					  n.addColorStop(0.7, "rgba(0, 0, 0, " + this.shadow.opacity + ")"),
					  n.addColorStop(0, "rgba(0, 0, 0, 0)"))
					: (this.ctx.translate(0, -100),
					  n.addColorStop(0, "rgba(0, 0, 0, " + this.shadow.opacity + ")"),
					  n.addColorStop(0.1, "rgba(0, 0, 0, 0.05)"),
					  n.addColorStop(0.3, "rgba(0, 0, 0, " + this.shadow.opacity + ")"),
					  n.addColorStop(1, "rgba(0, 0, 0, 0)")),
					this.ctx.clip(),
					(this.ctx.fillStyle = n),
					this.ctx.fillRect(0, 0, s, 2 * t.height),
					this.ctx.restore();
			}
			clear() {
				(this.ctx.fillStyle = "white"),
					this.ctx.fillRect(0, 0, this.canvas.width, this.canvas.height);
			}
		}
		class u {
			constructor(t, e, i) {
				(this.touchPoint = null),
					(this.swipeTimeout = 250),
					(this.swipeDistance = 80),
					(this.wrapper = t),
					this.wrapper.classList.add("stf__wrapper"),
					(this.app = e);
				const s = this.app.getSettings().usePortrait ? 1 : 2;
				(this.wrapper.style.minWidth = i.minWidth * s + "px"),
					(this.wrapper.style.minHeight = i.minHeight * s + "px"),
					"fixed" === i.size &&
						((this.wrapper.style.minWidth = i.width * s + "px"),
						(this.wrapper.style.minHeight = i.height * s + "px")),
					i.autoSize &&
						((this.wrapper.style.width = "100%"),
						(this.wrapper.style.maxWidth = 2 * i.maxWidth + "px")),
					(this.wrapper.style.display = "block");
			}
			getDistElement() {
				return this.distElement;
			}
			getWrapper() {
				return this.wrapper;
			}
			setOrientationStyle(t) {
				this.wrapper.classList.remove("--portrait", "--landscape"),
					"portrait" === t
						? (this.app.getSettings().autoSize &&
								(this.wrapper.style.paddingBottom =
									(this.app.getSettings().height / this.app.getSettings().width) * 100 +
									"%"),
						  this.wrapper.classList.add("--portrait"))
						: (this.app.getSettings().autoSize &&
								(this.wrapper.style.paddingBottom =
									(this.app.getSettings().height / (2 * this.app.getSettings().width)) *
										100 +
									"%"),
						  this.wrapper.classList.add("--landscape")),
					this.update();
			}
			setHandlers() {
				this.distElement.addEventListener("mousedown", (t) => {
					const e = this.getMousePos(t.clientX, t.clientY);
					this.app.startUserTouch(e), t.preventDefault();
				}),
					this.distElement.addEventListener("touchstart", (t) => {
						if (t.changedTouches.length > 0) {
							const e = t.changedTouches[0],
								i = this.getMousePos(e.clientX, e.clientY);
							(this.touchPoint = { point: i, time: Date.now() }),
								setTimeout(() => {
									null !== this.touchPoint && this.app.startUserTouch(i);
								}, this.swipeTimeout),
								t.preventDefault();
						}
					}),
					window.addEventListener("mousemove", (t) => {
						const e = this.getMousePos(t.clientX, t.clientY);
						this.app.userMove(e, !1);
					}),
					window.addEventListener("touchmove", (t) => {
						if (t.changedTouches.length > 0) {
							const e = t.changedTouches[0];
							this.app.userMove(this.getMousePos(e.clientX, e.clientY), !0);
						}
					}),
					window.addEventListener("mouseup", (t) => {
						const e = this.getMousePos(t.clientX, t.clientY);
						this.app.userStop(e);
					}),
					window.addEventListener("touchend", (t) => {
						if (t.changedTouches.length > 0) {
							const e = t.changedTouches[0],
								i = this.getMousePos(e.clientX, e.clientY);
							let s = !1;
							if (null !== this.touchPoint) {
								const t = i.x - this.touchPoint.point.x,
									e = Math.abs(i.y - this.touchPoint.point.y);
								Math.abs(t) > this.swipeDistance &&
									e < 2 * this.swipeDistance &&
									Date.now() - this.touchPoint.time < this.swipeTimeout &&
									(t > 0
										? this.app.flipPrev(
												this.touchPoint.point.y < this.app.getRender().getRect().height / 2
													? "top"
													: "bottom"
										  )
										: this.app.flipNext(
												this.touchPoint.point.y < this.app.getRender().getRect().height / 2
													? "top"
													: "bottom"
										  ),
									(s = !0)),
									(this.touchPoint = null);
							}
							this.app.userStop(i, s);
						}
					});
			}
			getMousePos(t, e) {
				const i = this.distElement.getBoundingClientRect();
				return { x: t - i.left, y: e - i.top };
			}
		}
		class m extends u {
			constructor(t, e, i, s) {
				super(t, e, i),
					t.insertAdjacentHTML("afterbegin", '<div class="stf__block"></div>'),
					(this.distElement = t.querySelector(".stf__block"));
				for (const t of s) this.distElement.appendChild(t);
				window.addEventListener(
					"resize",
					() => {
						this.update();
					},
					!1
				),
					this.setHandlers();
			}
			update() {
				this.app.getRender().update();
			}
		}
		class f extends u {
			constructor(t, e, i) {
				super(t, e, i),
					(t.innerHTML = '<canvas class="stf__canvas"></canvas>'),
					(this.canvas = t.querySelectorAll("canvas")[0]),
					window.addEventListener(
						"resize",
						() => {
							this.update();
						},
						!1
					),
					(this.distElement = this.canvas),
					this.resizeCanvas(),
					this.setHandlers();
			}
			resizeCanvas() {
				const t = getComputedStyle(this.canvas),
					e = parseInt(t.getPropertyValue("width"), 10),
					i = parseInt(t.getPropertyValue("height"), 10);
				(this.canvas.width = e), (this.canvas.height = i);
			}
			getCanvas() {
				return this.canvas;
			}
			update() {
				this.resizeCanvas(), this.app.getRender().update();
			}
		}
		class y extends d {
			constructor(t, e, i, s) {
				super(t, e),
					(this.outerShadow = null),
					(this.innerShadow = null),
					(this.element = i),
					(this.items = s);
			}
			getBlockWidth() {
				return this.element.offsetWidth;
			}
			getBlockHeight() {
				return this.element.offsetHeight;
			}
			clearShadow() {
				super.clearShadow(),
					this.outerShadow.remove(),
					this.innerShadow.remove(),
					(this.outerShadow = null),
					(this.innerShadow = null);
			}
			drawShadow(t, e, i, s, n) {
				super.drawShadow(t, e, i, s, n),
					null === this.outerShadow &&
						(this.element.insertAdjacentHTML(
							"beforeend",
							'<div class="stf__outerShadow"></div>'
						),
						(this.outerShadow = this.element.querySelector(".stf__outerShadow")),
						(this.outerShadow.style.zIndex = (
							this.getSettings().startZIndex + 10
						).toString(10)),
						(this.outerShadow.style.left = "0px"),
						(this.outerShadow.style.top = "0px")),
					null === this.innerShadow &&
						(this.element.insertAdjacentHTML(
							"beforeend",
							'<div class="stf__innerShadow"></div>'
						),
						(this.innerShadow = this.element.querySelector(".stf__innerShadow")),
						(this.innerShadow.style.zIndex = (
							this.getSettings().startZIndex + 10
						).toString(10)),
						(this.innerShadow.style.left = "0px"),
						(this.innerShadow.style.top = "0px"));
			}
			drawInnerShadow() {
				const t = this.getRect(),
					e = (3 * this.shadow.width) / 4,
					i = 0 === this.getDirection() ? e : 0,
					s = 0 === this.getDirection() ? "to left" : "to right",
					n = this.convertToGlobal(this.shadow.pos),
					o = this.shadow.angle + (3 * Math.PI) / 2;
				(this.innerShadow.style.width = e + "px"),
					(this.innerShadow.style.height = 2 * t.height + "px"),
					(this.innerShadow.style.background =
						"linear-gradient(" +
						s +
						", rgba(0, 0, 0, " +
						this.shadow.opacity +
						") 5%, rgba(0, 0, 0, 0.05) 15%,rgba(0, 0, 0, " +
						this.shadow.opacity +
						") 35%, rgba(0, 0, 0, 0) 100% )"),
					(this.innerShadow.style.transformOrigin = i + "px 100px"),
					(this.innerShadow.style.transform =
						"translate3d(" +
						(n.x - i) +
						"px, " +
						(n.y - 100) +
						"px, 0) rotate(" +
						o +
						"rad)");
				const h = [
					this.pageRect.topLeft,
					this.pageRect.topRight,
					this.pageRect.bottomRight,
					this.pageRect.bottomLeft
				];
				let r = "polygon( ";
				for (const t of h) {
					let e =
						1 === this.getDirection()
							? { x: -t.x + this.shadow.pos.x, y: t.y - this.shadow.pos.y }
							: { x: t.x - this.shadow.pos.x, y: t.y - this.shadow.pos.y };
					(e = a.GetRotatedPoint(e, { x: i, y: 100 }, o)),
						(r += e.x + "px " + e.y + "px, ");
				}
				(r = r.slice(0, -2)),
					(r += ")"),
					(this.innerShadow.style.clipPath = r),
					this.innerShadow.style.setProperty("-webkit-clip-path", r);
			}
			drawOuterShadow() {
				const t = this.getRect(),
					e = this.convertToGlobal({ x: this.shadow.pos.x, y: this.shadow.pos.y }),
					i = this.shadow.angle + (3 * Math.PI) / 2,
					s = 1 === this.getDirection() ? this.shadow.width : 0,
					n = 0 === this.getDirection() ? "to right" : "to left";
				(this.outerShadow.style.width = this.shadow.width + "px"),
					(this.outerShadow.style.height = 2 * t.height + "px"),
					(this.outerShadow.style.background =
						"linear-gradient(" +
						n +
						", rgba(0, 0, 0, " +
						this.shadow.opacity +
						"), rgba(0, 0, 0, 0))"),
					(this.outerShadow.style.transformOrigin = s + "px 100px"),
					(this.outerShadow.style.transform =
						"translate3d(" +
						(e.x - s) +
						"px, " +
						(e.y - 100) +
						"px, 0) rotate(" +
						i +
						"rad)");
				const o = [];
				o.push(
					{ x: 0, y: 0 },
					{ x: t.pageWidth, y: 0 },
					{ x: t.pageWidth, y: t.height },
					{ x: 0, y: t.height }
				);
				let h = "polygon( ";
				for (const t of o)
					if (null !== t) {
						let e =
							1 === this.getDirection()
								? { x: -t.x + this.shadow.pos.x, y: t.y - this.shadow.pos.y }
								: { x: t.x - this.shadow.pos.x, y: t.y - this.shadow.pos.y };
						(e = a.GetRotatedPoint(e, { x: s, y: 100 }, i)),
							(h += e.x + "px " + e.y + "px, ");
					}
				(h = h.slice(0, -2)),
					(h += ")"),
					(this.outerShadow.style.clipPath = h),
					this.outerShadow.style.setProperty("-webkit-clip-path", h);
			}
			drawFrame(t) {
				this.clear(),
					"portrait" !== this.orientation
						? null != this.leftPage && this.leftPage.simpleDraw(0)
						: null != this.leftPage && this.leftPage.clearSaved(),
					null != this.rightPage && this.rightPage.simpleDraw(1),
					null != this.bottomPage &&
						(("portrait" === this.orientation && 1 === this.direction) ||
							((this.bottomPage.getElement().style.zIndex = (
								this.getSettings().startZIndex + 3
							).toString(10)),
							this.bottomPage.draw())),
					null != this.flippingPage &&
						((this.flippingPage.getElement().style.zIndex = (
							this.getSettings().startZIndex + 4
						).toString(10)),
						this.flippingPage.draw()),
					null != this.shadow && (this.drawOuterShadow(), this.drawInnerShadow());
			}
			clear() {
				const t = [];
				this.leftPage && t.push(this.leftPage.getElement()),
					this.rightPage && t.push(this.rightPage.getElement()),
					this.flippingPage && t.push(this.flippingPage.getElement()),
					this.bottomPage && t.push(this.bottomPage.getElement());
				for (const e of this.items)
					t.includes(e) ||
						((e.style.display = "none"),
						(e.style.zIndex = (this.getSettings().startZIndex + 1).toString(10)),
						(e.style.transform = ""));
			}
			clearClass(t) {
				null !== t && t.getElement().classList.remove("--left", "--right");
			}
			setRightPage(t) {
				this.clearClass(this.rightPage),
					null !== this.rightPage &&
						t !== this.rightPage &&
						this.rightPage.clearSaved(),
					null !== t && t.getElement().classList.add("--right"),
					super.setRightPage(t);
			}
			setLeftPage(t) {
				this.clearClass(this.leftPage),
					null !== this.leftPage &&
						t !== this.rightPage &&
						this.leftPage.clearSaved(),
					null !== t && t.getElement().classList.add("--left"),
					super.setLeftPage(t);
			}
			setBottomPage(t) {
				null !== t &&
					t.getElement().classList.add(1 === this.direction ? "--left" : "--right"),
					super.setBottomPage(t);
			}
			setFlippingPage(t) {
				null !== t &&
					t.getElement().classList.add(1 === this.direction ? "--right" : "--left"),
					super.setFlippingPage(t);
			}
			update() {
				super.update(),
					null !== this.rightPage &&
						(this.rightPage.getElement().classList.add("--right"),
						this.rightPage.clearSaved()),
					null !== this.leftPage &&
						(this.leftPage.getElement().classList.add("--left"),
						this.leftPage.clearSaved());
			}
		}
		let x = (() => {
			class t {
				static GetSettings(t) {
					const e = this._default;
					if ((Object.assign(e, t), "stretch" !== e.size && "fixed" !== e.size))
						throw new Error(
							'Invalid size type. Available only "fixed" and "stretch" value'
						);
					if (e.width <= 0 || e.height <= 0)
						throw new Error("Invalid width or height");
					if (e.flippingTime <= 0) throw new Error("Invalid flipping time");
					return (
						e.minWidth <= 0 && (e.minWidth = e.width),
						e.maxWidth < e.minWidth && (e.maxWidth = e.minWidth),
						e.minHeight <= 0 && (e.minHeight = e.height),
						e.maxHeight < e.minHeight && (e.maxHeight = e.minHeight),
						e
					);
				}
			}
			return (
				(t._default = {
					startPage: 0,
					size: "fixed",
					width: 0,
					height: 0,
					minWidth: 0,
					maxWidth: 0,
					minHeight: 0,
					maxHeight: 0,
					drawShadow: !0,
					flippingTime: 1e3,
					usePortrait: !0,
					startZIndex: 0,
					autoSize: !0,
					maxShadowOpacity: 1
				}),
				t
			);
		})();
		i(0);
		class w extends class {
			constructor() {
				this.events = {};
			}
			on(t, e) {
				return (
					t in this.events ? this.events[t].push(e) : (this.events[t] = [e]), this
				);
			}
			off(t) {
				delete this.events[t];
			}
			trigger(t, e, i = null) {
				t in this.events &&
					this.events[t].forEach((t) => {
						t({ data: i, object: e });
					});
			}
		} {
			constructor(t, e) {
				super(),
					(this.isUserTouch = !1),
					(this.isUserMove = !1),
					(this.pages = null),
					(this.currentPage = 0),
					(this.setting = null);
				try {
					(this.setting = x.GetSettings(e)), (this.block = t);
				} catch (t) {}
			}
			update() {
				this.render.update(), this.pages.show(this.currentPage);
			}
			turnToPrevPage() {
				const t = "portrait" === this.render.getOrientation() ? 1 : 2;
				this.currentPage < t ||
					((this.currentPage -= t), this.pages.show(this.currentPage));
			}
			turnToNextPage() {
				const t = "portrait" === this.render.getOrientation() ? 1 : 2;
				this.currentPage > this.pages.getPageCount() - t ||
					((this.currentPage += t), this.pages.show(this.currentPage));
			}
			turnToPage(t) {
				this.checkPage(t) &&
					((this.currentPage = t), this.pages.show(this.currentPage));
			}
			flipNext(t = "top") {
				this.flip.flipNext(t);
			}
			flipPrev(t = "top") {
				this.flip.flipPrev(t);
			}
			loadFromImages(t) {
				this.ui = new f(this.block, this, this.setting);
				const e = this.ui.getCanvas();
				(this.render = new p(this, this.setting, e)),
					(this.flip = new c(this.render, this)),
					(this.pages = new h(this, this.render, t)),
					this.pages.load(),
					this.render.start(),
					(this.currentPage = this.setting.startPage),
					this.pages.show(this.setting.startPage);
			}
			loadFromHTML(t) {
				(this.ui = new m(this.block, this, this.setting, t)),
					(this.render = new y(this, this.setting, this.ui.getDistElement(), t)),
					(this.flip = new c(this.render, this)),
					(this.pages = new l(this, this.render, this.ui.getDistElement(), t)),
					this.pages.load(),
					this.render.start(),
					(this.currentPage = this.setting.startPage),
					this.pages.show(this.setting.startPage);
			}
			updateState(t) {
				this.trigger("changeState", this, t);
			}
			updatePage(t) {
				this.trigger("flip", this, t);
			}
			updateOrientation(t) {
				"landscape" === t
					? (this.currentPage % 2 != 0 && this.currentPage--, this.update())
					: (this.currentPage++, this.update()),
					this.ui.setOrientationStyle(t),
					this.trigger("changeOrientation", this, t);
			}
			getPageCount() {
				return this.pages.getPageCount();
			}
			getCurrentPageIndex() {
				return this.currentPage;
			}
			getCurrentPage() {
				return this.pages.getPage(this.currentPage);
			}
			getPage(t) {
				return this.pages.getPage(t);
			}
			getRender() {
				return this.render;
			}
			getFlipObject() {
				return this.flip;
			}
			getOrientation() {
				return this.render.getOrientation();
			}
			getBoundsRect() {
				return this.render.getRect();
			}
			getSettings() {
				return this.setting;
			}
			getUI() {
				return this.ui;
			}
			startUserTouch(t) {
				(this.mousePosition = t), (this.isUserTouch = !0), (this.isUserMove = !1);
			}
			userMove(t, e) {
				this.isUserTouch || e
					? this.isUserTouch &&
					  a.GetDestinationFromTwoPoint(this.mousePosition, t) > 5 &&
					  ((this.isUserMove = !0), this.flip.fold(t))
					: this.flip.showCorner(t);
			}
			userStop(t, e = !1) {
				this.isUserTouch &&
					((this.isUserTouch = !1),
					e || (this.isUserMove ? this.flip.stopMove() : this.flip.flip(t)));
			}
			checkPage(t) {
				return t >= 0 && t < this.pages.getPageCount();
			}
		}
		document.addEventListener("DOMContentLoaded", function () {
			const t = new w(document.getElementById("canvasBookExample"), {
				width: 550,
				height: 733,
				size: "stretch",
				minWidth: 350,
				maxWidth: 700,
				minHeight: 467,
				maxHeight: 933
			});
			t.loadFromImages([
				"https://cdn.pixabay.com/photo/2015/05/03/14/40/woman-751236__340.jpg",
				"https://cdn.pixabay.com/photo/2015/03/04/12/59/bells-flower-658751__340.jpg",
				"https://cdn.pixabay.com/photo/2014/04/10/11/27/flower-320874__340.jpg",
				"https://cdn.pixabay.com/photo/2017/04/12/23/23/wild-flower-2226095__340.jpg",
				"https://cdn.pixabay.com/photo/2015/05/15/14/47/woman-768702__340.jpg",
				"https://cdn.pixabay.com/photo/2015/02/23/20/49/flowers-646637__340.jpg",
				"https://cdn.pixabay.com/photo/2016/07/12/17/30/flower-1512646__340.jpg",
				"https://cdn.pixabay.com/photo/2020/03/10/15/54/dandelion-4919334__340.jpg",
				"https://cdn.pixabay.com/photo/2020/04/29/16/10/vase-5109481__340.jpg",
				"https://cdn.pixabay.com/photo/2014/02/10/00/32/rose-263234__340.jpg",
				"https://cdn.pixabay.com/photo/2020/03/10/15/54/dandelion-4919334__340.jpg",
				"https://cdn.pixabay.com/photo/2016/03/09/09/30/flowers-1245828__340.jpg",
				"https://cdn.pixabay.com/photo/2012/03/03/23/59/flowers-21708__340.jpg",
				"https://cdn.pixabay.com/photo/2015/01/07/10/24/aster-591311__340.jpg"
			]);
			const e = new w(document.getElementById("htmlBookExample"), {
					width: 550,
					height: 733,
					size: "stretch",
					minWidth: 350,
					maxWidth: 700,
					minHeight: 467,
					maxHeight: 933,
					autoSize: !0,
					maxShadowOpacity: 0.5
				}),
				i = document.getElementById("htmlBook"),
				s = document.getElementById("canvasBook"),
				n = document.getElementById("buttonDemoSelection"),
				o = n.querySelectorAll("button");
			let h = e;
			for (const a of o)
				a.addEventListener("click", (o) => {
					const a = n.querySelector(".btn-primary");
					a.classList.remove("btn-primary"), a.classList.add("btn-secondary");
					const r = o.target;
					r.classList.add("btn-primary"), r.classList.remove("btn-secondary");
					"html" === r.dataset.dest
						? ((h = e),
						  (s.style.display = "none"),
						  (i.style.display = "block"),
						  e.getUI().update(),
						  e.update())
						: ((h = t),
						  (s.style.display = "block"),
						  (i.style.display = "none"),
						  t.getUI().update(),
						  t.update());
				});
			document.querySelector(".btn-book-next").addEventListener("click", () => {
				h.flipNext();
			}),
				document.querySelector(".btn-book-prev").addEventListener("click", () => {
					h.flipPrev();
				}),
				t.on("flip", (e) => {
					const i = parseInt(e.data.toString(), 10) + 1;
					(document.querySelector(".page-count").innerHTML = i.toString(10)),
						(document.querySelector(
							".page-total"
						).innerHTML = t.getPageCount().toString(10));
				}),
				e.on("flip", (t) => {
					const i = parseInt(t.data.toString(), 10) + 1;
					(document.querySelector(".page-count").innerHTML = i.toString(10)),
						(document.querySelector(
							".page-total"
						).innerHTML = e.getPageCount().toString(10));
				}),
				e.loadFromHTML(document.querySelectorAll(".page"));
		});
	}
]);
