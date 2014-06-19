{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 552.0, 417.0, 645.0, 537.0 ],
		"bgcolor" : [ 0.215686, 0.215686, 0.215686, 1.0 ],
		"bglocked" : 0,
		"defrect" : [ 552.0, 417.0, 645.0, 537.0 ],
		"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Helvetica",
		"gridonopen" : 0,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 0,
		"toolbarvisible" : 1,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"boxes" : [ 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "s stop",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 200.0, 181.0, 41.0, 20.0 ],
					"fontsize" : 11.595187,
					"id" : "obj-21",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t 1 1",
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 573.0, 349.0, 34.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "int", "int" ],
					"id" : "obj-61",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "target 0, 0",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 313.0, 382.0, 63.0, 18.0 ],
					"fontsize" : 11.595187,
					"outlettype" : [ "" ],
					"id" : "obj-60",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "0",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 491.0, 377.0, 32.5, 18.0 ],
					"fontsize" : 11.595187,
					"outlettype" : [ "" ],
					"id" : "obj-57",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r stop",
					"numinlets" : 0,
					"numoutlets" : 1,
					"patching_rect" : [ 573.0, 323.0, 41.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"id" : "obj-54",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "play sounds",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 392.0, 70.0, 73.0, 20.0 ],
					"frgb" : [ 0.8, 0.611765, 0.380392, 1.0 ],
					"fontsize" : 12.0,
					"id" : "obj-53",
					"fontname" : "Helvetica",
					"textcolor" : [ 0.8, 0.611765, 0.380392, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "load files",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 526.0, 71.0, 73.0, 20.0 ],
					"frgb" : [ 0.8, 0.611765, 0.380392, 1.0 ],
					"fontsize" : 12.0,
					"id" : "obj-47",
					"fontname" : "Helvetica",
					"textcolor" : [ 0.8, 0.611765, 0.380392, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "select folder",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 525.0, 42.0, 73.0, 20.0 ],
					"frgb" : [ 0.8, 0.611765, 0.380392, 1.0 ],
					"fontsize" : 12.0,
					"id" : "obj-38",
					"fontname" : "Helvetica",
					"textcolor" : [ 0.8, 0.611765, 0.380392, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 500.0, 71.0, 20.0, 20.0 ],
					"outlettype" : [ "bang" ],
					"id" : "obj-34"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "del 1000",
					"numinlets" : 2,
					"hidden" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 368.0, 41.0, 57.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "bang" ],
					"id" : "obj-29",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadmess 1",
					"numinlets" : 1,
					"hidden" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 368.0, 16.0, 72.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"id" : "obj-27",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "s voices",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 569.0, 160.0, 52.0, 20.0 ],
					"fontsize" : 11.595187,
					"id" : "obj-67",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 368.0, 71.0, 20.0, 20.0 ],
					"outlettype" : [ "bang" ],
					"id" : "obj-65"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "+ 1",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 376.0, 156.0, 32.5, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "int" ],
					"id" : "obj-64",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "s topoly",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 376.0, 230.0, 54.0, 20.0 ],
					"fontsize" : 11.595187,
					"id" : "obj-63",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r voices",
					"numinlets" : 0,
					"numoutlets" : 1,
					"patching_rect" : [ 395.0, 98.0, 50.0, 20.0 ],
					"fontsize" : 11.595187,
					"outlettype" : [ "" ],
					"id" : "obj-59",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r voices",
					"numinlets" : 0,
					"numoutlets" : 1,
					"patching_rect" : [ 272.0, 412.0, 50.0, 20.0 ],
					"fontsize" : 11.595187,
					"outlettype" : [ "" ],
					"id" : "obj-58",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r voices",
					"numinlets" : 0,
					"numoutlets" : 1,
					"patching_rect" : [ 466.0, 295.0, 50.0, 20.0 ],
					"fontsize" : 11.595187,
					"outlettype" : [ "" ],
					"id" : "obj-56",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "uzi 6",
					"numinlets" : 2,
					"numoutlets" : 3,
					"patching_rect" : [ 368.0, 126.0, 46.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "bang", "bang", "int" ],
					"id" : "obj-33",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r stop",
					"numinlets" : 0,
					"numoutlets" : 1,
					"patching_rect" : [ 378.0, 299.0, 39.0, 20.0 ],
					"fontsize" : 11.595187,
					"outlettype" : [ "" ],
					"id" : "obj-50",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p osc",
					"numinlets" : 2,
					"numoutlets" : 2,
					"patching_rect" : [ 378.0, 330.0, 107.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "int", "float" ],
					"id" : "obj-48",
					"fontname" : "Helvetica",
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 53.0, 594.0, 465.0, 347.0 ],
						"bgcolor" : [ 0.215686, 0.215686, 0.215686, 1.0 ],
						"bglocked" : 0,
						"defrect" : [ 53.0, 594.0, 465.0, 347.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"visible" : 1,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "- 1",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 39.0, 147.0, 32.5, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int" ],
									"id" : "obj-26",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "+ 2",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 25.0, 197.0, 32.5, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int" ],
									"id" : "obj-23",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "print play",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 64.0, 249.0, 59.0, 20.0 ],
									"fontsize" : 12.0,
									"id" : "obj-2",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "number",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 9.0, 76.0, 50.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int", "bang" ],
									"id" : "obj-25",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "change",
									"numinlets" : 1,
									"numoutlets" : 3,
									"patching_rect" : [ 63.0, 81.0, 50.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "", "int", "int" ],
									"id" : "obj-22",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "print stopFile",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 64.0, 300.0, 79.0, 20.0 ],
									"fontsize" : 12.0,
									"id" : "obj-14",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "send stop last selected file",
									"linecount" : 2,
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 197.0, 204.0, 98.0, 34.0 ],
									"frgb" : [ 0.8, 0.611765, 0.380392, 1.0 ],
									"fontsize" : 12.0,
									"id" : "obj-47",
									"fontname" : "Helvetica",
									"textcolor" : [ 0.8, 0.611765, 0.380392, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "bgcolor 55 55 55",
									"numinlets" : 4,
									"hidden" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 370.0, 310.0, 88.0, 17.0 ],
									"fontsize" : 9.0,
									"color" : [ 0.156863, 0.8, 0.54902, 1.0 ],
									"id" : "obj-30",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "sel -1",
									"numinlets" : 2,
									"numoutlets" : 2,
									"patching_rect" : [ 63.0, 105.0, 40.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "bang", "" ],
									"id" : "obj-12",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "print selectFile",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 64.0, 272.0, 88.0, 20.0 ],
									"fontsize" : 12.0,
									"id" : "obj-17",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"patching_rect" : [ 164.0, 223.0, 20.0, 20.0 ],
									"outlettype" : [ "bang" ],
									"id" : "obj-24"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "i",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 164.0, 248.0, 32.5, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int" ],
									"id" : "obj-18",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "%",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 25.0, 171.0, 32.5, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int" ],
									"id" : "obj-10",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"patching_rect" : [ 424.0, 13.0, 25.0, 25.0 ],
									"outlettype" : [ "" ],
									"id" : "obj-8",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 324.0, 209.0, 25.0, 25.0 ],
									"id" : "obj-6",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 25.0, 226.0, 25.0, 25.0 ],
									"id" : "obj-5",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"patching_rect" : [ 164.0, 192.0, 25.0, 25.0 ],
									"outlettype" : [ "" ],
									"id" : "obj-3",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 344.0, 166.0, 62.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "float", "bang" ],
									"id" : "obj-19",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "number",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 288.0, 166.0, 50.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int", "bang" ],
									"id" : "obj-20",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "unpack 0 0. 0",
									"numinlets" : 1,
									"numoutlets" : 3,
									"patching_rect" : [ 288.0, 123.0, 89.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int", "float", "int" ],
									"id" : "obj-21",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/stopMemoryId $1",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 164.0, 277.0, 117.0, 18.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"id" : "obj-16",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "number",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 221.0, 166.0, 50.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int", "bang" ],
									"id" : "obj-15",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 155.0, 166.0, 50.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "float", "bang" ],
									"id" : "obj-13",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "number",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 96.0, 166.0, 50.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int", "bang" ],
									"id" : "obj-11",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "unpack 0 0. 0",
									"numinlets" : 1,
									"numoutlets" : 3,
									"patching_rect" : [ 63.0, 56.0, 89.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int", "float", "int" ],
									"id" : "obj-9",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "route /meshTrackerDataAction /meshTrackerData",
									"numinlets" : 1,
									"numoutlets" : 3,
									"patching_rect" : [ 63.0, 31.0, 342.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "", "", "" ],
									"id" : "obj-7",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "udpreceive 3884",
									"numinlets" : 1,
									"numoutlets" : 1,
									"patching_rect" : [ 63.0, 6.0, 107.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"id" : "obj-4",
									"fontname" : "Arial"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "udpsend localhost 3885",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 164.0, 302.0, 149.0, 20.0 ],
									"fontsize" : 12.0,
									"id" : "obj-1",
									"fontname" : "Arial"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-9", 2 ],
									"destination" : [ "obj-15", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 1 ],
									"destination" : [ "obj-13", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-9", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 1 ],
									"destination" : [ "obj-21", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-7", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-24", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-24", 0 ],
									"destination" : [ "obj-18", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-21", 1 ],
									"destination" : [ "obj-6", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-21", 0 ],
									"destination" : [ "obj-20", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-21", 1 ],
									"destination" : [ "obj-19", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-18", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-18", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-16", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-12", 0 ],
									"destination" : [ "obj-24", 0 ],
									"hidden" : 0,
									"midpoints" : [ 72.5, 220.5, 173.5, 220.5 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-12", 1 ],
									"destination" : [ "obj-11", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-18", 1 ],
									"hidden" : 0,
									"midpoints" : [ 105.5, 245.5, 187.0, 245.5 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-17", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-22", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-22", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-25", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-12", 1 ],
									"destination" : [ "obj-10", 0 ],
									"hidden" : 0,
									"midpoints" : [ 93.5, 140.5, 34.5, 140.5 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-23", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-23", 0 ],
									"destination" : [ "obj-5", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-26", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-26", 0 ],
									"destination" : [ "obj-10", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"globalpatchername" : "",
						"default_fontname" : "Arial",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontsize" : 12.0,
						"fontname" : "Arial"
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 466.0, 397.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "float", "bang" ],
					"id" : "obj-49",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "zmap 0 500 0. 1.",
					"numinlets" : 5,
					"numoutlets" : 1,
					"patching_rect" : [ 466.0, 355.0, 100.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"id" : "obj-37",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "target $1, 1",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 378.0, 398.0, 69.0, 18.0 ],
					"fontsize" : 11.595187,
					"outlettype" : [ "" ],
					"id" : "obj-28",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "bgcolor 55 55 55",
					"numinlets" : 4,
					"hidden" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 519.0, 545.0, 88.0, 17.0 ],
					"fontsize" : 9.0,
					"color" : [ 0.156863, 0.8, 0.54902, 1.0 ],
					"id" : "obj-30",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "target 0, $1",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 526.0, 419.0, 80.0, 18.0 ],
					"fontsize" : 11.595187,
					"outlettype" : [ "" ],
					"id" : "obj-45",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadmess 1",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 526.0, 376.0, 72.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"id" : "obj-44",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 526.0, 398.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "float", "bang" ],
					"id" : "obj-41",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 376.0, 183.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "int", "bang" ],
					"id" : "obj-36",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "target $1, $1",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 376.0, 207.0, 88.0, 18.0 ],
					"fontsize" : 11.595187,
					"outlettype" : [ "" ],
					"id" : "obj-23",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "print",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 557.0, 185.0, 37.0, 20.0 ],
					"fontsize" : 11.595187,
					"id" : "obj-14",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "voices $1",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 500.0, 161.0, 65.0, 18.0 ],
					"fontsize" : 11.595187,
					"outlettype" : [ "" ],
					"id" : "obj-35",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "s topoly",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 500.0, 185.0, 50.0, 20.0 ],
					"fontsize" : 11.595187,
					"id" : "obj-18",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r topoly",
					"numinlets" : 0,
					"numoutlets" : 1,
					"patching_rect" : [ 272.0, 441.0, 52.0, 20.0 ],
					"fontsize" : 11.595187,
					"outlettype" : [ "" ],
					"id" : "obj-31",
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadmess 127",
					"numinlets" : 1,
					"hidden" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 19.0, 23.0, 85.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"id" : "obj-26",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadbang",
					"numinlets" : 1,
					"hidden" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 480.0, 19.0, 60.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "bang" ],
					"id" : "obj-25",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 500.0, 42.0, 20.0, 20.0 ],
					"outlettype" : [ "bang" ],
					"id" : "obj-16"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p load_audio",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 500.0, 133.0, 83.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "int" ],
					"id" : "obj-13",
					"fontname" : "Arial",
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 1231.0, 69.0, 597.0, 775.0 ],
						"bglocked" : 0,
						"defrect" : [ 1231.0, 69.0, 597.0, 775.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 10.0,
						"default_fontface" : 0,
						"default_fontname" : "Helvetica",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "+ 1",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 458.0, 356.0, 32.5, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int" ],
									"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
									"id" : "obj-1",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "+ 1000",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 109.0, 490.0, 48.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int" ],
									"id" : "obj-29",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pack 0 s",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 109.0, 520.0, 55.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"id" : "obj-28",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "prepend preload",
									"numinlets" : 1,
									"numoutlets" : 1,
									"patching_rect" : [ 109.0, 555.0, 106.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
									"id" : "obj-27",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t i b",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 220.0, 421.0, 32.5, 18.0 ],
									"fontsize" : 10.0,
									"outlettype" : [ "int", "bang" ],
									"id" : "obj-4",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "random 8000",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 266.0, 466.0, 81.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int" ],
									"id" : "obj-2",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 464.0, 210.0, 26.0, 26.0 ],
									"id" : "obj-3",
									"comment" : "number of files in folder"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t b s",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 298.0, 283.0, 86.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "bang", "" ],
									"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
									"id" : "obj-5",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t i i",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 458.0, 332.0, 52.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int", "int" ],
									"id" : "obj-7",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pack 0 s 0",
									"numinlets" : 3,
									"numoutlets" : 1,
									"patching_rect" : [ 220.0, 497.0, 65.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"id" : "obj-8",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "gate 1 0",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 261.0, 352.0, 60.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
									"id" : "obj-9",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "tosymbol",
									"numinlets" : 1,
									"numoutlets" : 1,
									"patching_rect" : [ 261.0, 378.0, 65.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
									"id" : "obj-10",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "prepend preload",
									"numinlets" : 1,
									"numoutlets" : 1,
									"patching_rect" : [ 220.0, 554.0, 106.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
									"id" : "obj-11",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t 0 b 1",
									"numinlets" : 1,
									"numoutlets" : 3,
									"patching_rect" : [ 414.0, 276.0, 50.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int", "bang", "int" ],
									"id" : "obj-12",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t b i",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 414.0, 216.0, 33.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "bang", "int" ],
									"id" : "obj-13",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "- 1",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 492.0, 357.0, 33.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int" ],
									"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
									"id" : "obj-14",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "uzi",
									"numinlets" : 2,
									"numoutlets" : 3,
									"patching_rect" : [ 429.0, 304.0, 48.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "bang", "bang", "int" ],
									"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
									"id" : "obj-15",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t s s",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 97.0, 83.0, 38.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "", "" ],
									"id" : "obj-16",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "r init",
									"numinlets" : 0,
									"numoutlets" : 1,
									"patching_rect" : [ 322.0, 67.0, 40.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"id" : "obj-17",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "clear",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 322.0, 95.0, 42.0, 18.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"id" : "obj-18",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadbang",
									"numinlets" : 1,
									"numoutlets" : 1,
									"patching_rect" : [ 226.0, 62.0, 61.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "bang" ],
									"id" : "obj-19",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "sprintf %s%s",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 298.0, 314.0, 93.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
									"id" : "obj-20",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"patching_rect" : [ 198.0, 244.0, 110.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "int", "", "" ],
									"items" : [ "013_10.3.2012.21.50.28.aif", ",", "020_10.3.2012.21.59.52.aif", ",", "021_10.3.2012.22.1.36.aif", ",", "023_10.3.2012.22.2.31.aif", ",", "024_10.3.2012.22.3.5.aif", ",", "025_10.3.2012.22.5.40.aif", ",", "033_10.3.2012.22.8.33.aif", ",", "036_10.3.2012.22.9.58.aif", ",", "038_10.3.2012.22.11.46.aif", ",", "040_10.3.2012.22.12.35.aif", ",", "045_10.3.2012.22.21.6.aif", ",", "048_10.3.2012.22.25.53.aif", ",", "053_10.3.2012.22.29.17.aif", ",", "055_10.3.2012.22.32.11.aif" ],
									"types" : [  ],
									"id" : "obj-21",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "folder",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 198.0, 120.0, 285.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "", "int" ],
									"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
									"id" : "obj-22",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "types AIFF",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 226.0, 96.0, 68.0, 18.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"id" : "obj-23",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"patching_rect" : [ 97.0, 60.0, 15.0, 15.0 ],
									"outlettype" : [ "" ],
									"id" : "obj-24",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "sflist~ Ame",
									"numinlets" : 1,
									"numoutlets" : 1,
									"patching_rect" : [ 220.0, 595.0, 69.0, 20.0 ],
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"id" : "obj-25",
									"fontname" : "Helvetica",
									"save" : [ "#N", "sflist~", "Ame", 0, ";" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "print preload",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 295.0, 595.0, 77.0, 20.0 ],
									"fontsize" : 12.0,
									"id" : "obj-26",
									"fontname" : "Helvetica"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-4", 0 ],
									"hidden" : 0,
									"midpoints" : [ 467.5, 398.0, 229.5, 398.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-22", 1 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-10", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-11", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 1 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-20", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 1 ],
									"destination" : [ "obj-20", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-8", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-29", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 1 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-29", 0 ],
									"destination" : [ "obj-28", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-28", 0 ],
									"destination" : [ "obj-27", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-27", 0 ],
									"destination" : [ "obj-26", 0 ],
									"hidden" : 0,
									"midpoints" : [ 118.5, 584.5, 304.5, 584.5 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-27", 0 ],
									"destination" : [ "obj-25", 0 ],
									"hidden" : 0,
									"midpoints" : [ 118.5, 584.5, 229.5, 584.5 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-24", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-23", 0 ],
									"destination" : [ "obj-22", 0 ],
									"hidden" : 0,
									"midpoints" : [ 235.5, 115.0, 207.5, 115.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-22", 0 ],
									"destination" : [ "obj-21", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-22", 1 ],
									"destination" : [ "obj-13", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-21", 1 ],
									"destination" : [ "obj-5", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-20", 0 ],
									"destination" : [ "obj-9", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-8", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-19", 0 ],
									"destination" : [ "obj-23", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-19", 0 ],
									"destination" : [ "obj-18", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-18", 0 ],
									"destination" : [ "obj-21", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-17", 0 ],
									"destination" : [ "obj-18", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-16", 0 ],
									"destination" : [ "obj-22", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-16", 1 ],
									"destination" : [ "obj-20", 0 ],
									"hidden" : 0,
									"midpoints" : [ 125.5, 207.0, 307.5, 207.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-15", 2 ],
									"destination" : [ "obj-7", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-14", 0 ],
									"destination" : [ "obj-21", 0 ],
									"hidden" : 0,
									"midpoints" : [ 501.5, 239.0, 161.0, 239.0, 161.0, 231.0, 207.5, 231.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-13", 1 ],
									"destination" : [ "obj-15", 1 ],
									"hidden" : 0,
									"midpoints" : [ 437.5, 242.0, 467.5, 242.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-13", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-12", 0 ],
									"destination" : [ "obj-9", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-12", 2 ],
									"destination" : [ "obj-9", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-12", 1 ],
									"destination" : [ "obj-15", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-26", 0 ],
									"hidden" : 0,
									"midpoints" : [ 229.5, 582.0, 304.5, 582.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-25", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-8", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-28", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"globalpatchername" : "",
						"default_fontname" : "Helvetica",
						"fontface" : 0,
						"fontsize" : 10.0,
						"default_fontsize" : 10.0,
						"fontname" : "Helvetica"
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p SelectFolder",
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 500.0, 108.0, 124.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"color" : [ 0.156863, 0.8, 0.54902, 1.0 ],
					"id" : "obj-20",
					"fontname" : "Helvetica",
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 935.0, 50.0, 474.0, 576.0 ],
						"bglocked" : 0,
						"defrect" : [ 935.0, 50.0, 474.0, 576.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 10.0,
						"default_fontface" : 0,
						"default_fontname" : "Helvetica",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"patching_rect" : [ 200.0, 16.0, 25.0, 25.0 ],
									"outlettype" : [ "bang" ],
									"id" : "obj-5",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"patching_rect" : [ 153.0, 13.0, 25.0, 25.0 ],
									"outlettype" : [ "bang" ],
									"id" : "obj-4",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numinlets" : 1,
									"numoutlets" : 1,
									"patching_rect" : [ 68.0, 66.0, 20.0, 20.0 ],
									"outlettype" : [ "bang" ],
									"id" : "obj-2"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "C:/Users/Jordi/Desktop/of_v0071_vs2010_release/apps/myApps/svn-a-me/max/App_3/bons/",
									"linecount" : 3,
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 111.0, 103.0, 156.0, 36.0 ],
									"fontsize" : 9.0,
									"outlettype" : [ "" ],
									"id" : "obj-31",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "prepend set",
									"numinlets" : 1,
									"numoutlets" : 1,
									"patching_rect" : [ 111.0, 82.0, 58.0, 17.0 ],
									"fontsize" : 9.0,
									"outlettype" : [ "" ],
									"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
									"id" : "obj-30",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "- 1",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 141.0, 262.0, 27.0, 17.0 ],
									"fontsize" : 9.0,
									"outlettype" : [ "int" ],
									"id" : "obj-6",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "uzi",
									"numinlets" : 2,
									"numoutlets" : 3,
									"patching_rect" : [ 158.0, 208.0, 47.0, 17.0 ],
									"fontsize" : 9.0,
									"outlettype" : [ "bang", "bang", "int" ],
									"id" : "obj-9",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "print Root",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 167.0, 161.0, 55.0, 17.0 ],
									"fontsize" : 9.0,
									"color" : [ 1.0, 0.360784, 0.682353, 1.0 ],
									"id" : "obj-13",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadmess clear",
									"numinlets" : 1,
									"numoutlets" : 1,
									"patching_rect" : [ 249.0, 244.0, 77.0, 17.0 ],
									"fontsize" : 9.0,
									"outlettype" : [ "" ],
									"id" : "obj-14",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "print folder1",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 120.0, 377.0, 68.0, 17.0 ],
									"fontsize" : 9.0,
									"color" : [ 1.0, 0.360784, 0.682353, 1.0 ],
									"id" : "obj-15",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "gate 4 1",
									"numinlets" : 2,
									"numoutlets" : 4,
									"patching_rect" : [ 186.0, 310.0, 53.0, 17.0 ],
									"fontsize" : 9.0,
									"outlettype" : [ "", "", "", "" ],
									"id" : "obj-17",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t s s",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 111.0, 161.0, 30.0, 17.0 ],
									"fontsize" : 9.0,
									"outlettype" : [ "", "" ],
									"id" : "obj-18",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadmess types fold",
									"numinlets" : 1,
									"numoutlets" : 1,
									"patching_rect" : [ 174.0, 184.0, 99.0, 17.0 ],
									"fontsize" : 9.0,
									"outlettype" : [ "" ],
									"id" : "obj-19",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "sprintf %s%s/",
									"numinlets" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 111.0, 352.0, 78.0, 17.0 ],
									"fontsize" : 9.0,
									"outlettype" : [ "" ],
									"id" : "obj-20",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"patching_rect" : [ 131.0, 286.0, 127.0, 17.0 ],
									"fontsize" : 9.0,
									"outlettype" : [ "int", "", "" ],
									"items" : "<empty>",
									"types" : [  ],
									"id" : "obj-21",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "folder",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 131.0, 184.0, 37.0, 17.0 ],
									"fontsize" : 9.0,
									"outlettype" : [ "", "int" ],
									"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
									"id" : "obj-22",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 111.0, 428.0, 15.0, 15.0 ],
									"id" : "obj-23",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "opendialog fold",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 111.0, 62.0, 76.0, 17.0 ],
									"fontsize" : 9.0,
									"outlettype" : [ "", "bang" ],
									"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
									"id" : "obj-27",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "conformpath",
									"numinlets" : 1,
									"numoutlets" : 2,
									"patching_rect" : [ 111.0, 129.0, 69.0, 17.0 ],
									"fontsize" : 9.0,
									"outlettype" : [ "", "int" ],
									"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
									"id" : "obj-28",
									"fontname" : "Helvetica"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-9", 2 ],
									"destination" : [ "obj-6", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 2 ],
									"destination" : [ "obj-17", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-21", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-31", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-27", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-31", 0 ],
									"destination" : [ "obj-28", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-30", 0 ],
									"destination" : [ "obj-31", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-28", 0 ],
									"destination" : [ "obj-18", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-28", 0 ],
									"destination" : [ "obj-13", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-27", 0 ],
									"destination" : [ "obj-30", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-22", 1 ],
									"destination" : [ "obj-9", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-22", 0 ],
									"destination" : [ "obj-21", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-21", 1 ],
									"destination" : [ "obj-17", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-20", 0 ],
									"destination" : [ "obj-23", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-20", 0 ],
									"destination" : [ "obj-15", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-27", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-19", 0 ],
									"destination" : [ "obj-22", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-18", 1 ],
									"destination" : [ "obj-22", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-18", 0 ],
									"destination" : [ "obj-20", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-17", 0 ],
									"destination" : [ "obj-20", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-14", 0 ],
									"destination" : [ "obj-21", 0 ],
									"hidden" : 0,
									"midpoints" : [ 258.5, 282.0, 140.5, 282.0 ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"globalpatchername" : "",
						"default_fontname" : "Helvetica",
						"fontface" : 0,
						"fontsize" : 10.0,
						"default_fontsize" : 10.0,
						"fontname" : "Helvetica"
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "poly~ player",
					"numinlets" : 4,
					"numoutlets" : 2,
					"patching_rect" : [ 277.0, 476.0, 171.0, 20.0 ],
					"fontsize" : 12.0,
					"outlettype" : [ "signal", "" ],
					"id" : "obj-15",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- 24",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 108.0, 259.0, 49.0, 29.0 ],
					"frgb" : [ 0.8, 0.611765, 0.380392, 1.0 ],
					"fontsize" : 20.0,
					"id" : "obj-1",
					"fontname" : "C Futura Condensed",
					"textcolor" : [ 0.8, 0.611765, 0.380392, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "+ 6",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 107.0, 71.0, 42.0, 29.0 ],
					"frgb" : [ 0.8, 0.611765, 0.380392, 1.0 ],
					"fontsize" : 20.0,
					"id" : "obj-2",
					"fontname" : "C Futura Condensed",
					"textcolor" : [ 0.8, 0.611765, 0.380392, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- 6",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 107.0, 165.0, 39.0, 29.0 ],
					"frgb" : [ 0.8, 0.611765, 0.380392, 1.0 ],
					"fontsize" : 20.0,
					"id" : "obj-3",
					"fontname" : "C Futura Condensed",
					"textcolor" : [ 0.8, 0.611765, 0.380392, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- 12",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 107.0, 212.0, 49.0, 29.0 ],
					"frgb" : [ 0.8, 0.611765, 0.380392, 1.0 ],
					"fontsize" : 20.0,
					"id" : "obj-4",
					"fontname" : "C Futura Condensed",
					"textcolor" : [ 0.8, 0.611765, 0.380392, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "- 0",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 107.0, 118.0, 36.0, 29.0 ],
					"frgb" : [ 0.8, 0.611765, 0.380392, 1.0 ],
					"fontsize" : 20.0,
					"id" : "obj-5",
					"fontname" : "C Futura Condensed",
					"textcolor" : [ 0.8, 0.611765, 0.380392, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "scale 0 127 0 1 1.03",
					"numinlets" : 6,
					"hidden" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 117.0, 311.0, 105.0, 17.0 ],
					"fontsize" : 9.0,
					"outlettype" : [ "" ],
					"id" : "obj-6",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "dB",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 146.0, 358.0, 33.0, 29.0 ],
					"frgb" : [ 0.8, 0.611765, 0.380392, 1.0 ],
					"fontsize" : 20.0,
					"id" : "obj-7",
					"fontname" : "C Futura Condensed",
					"textcolor" : [ 0.8, 0.611765, 0.380392, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numinlets" : 1,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 1.0 ],
					"htextcolor" : [ 0.870588, 0.870588, 0.870588, 1.0 ],
					"triangle" : 0,
					"numoutlets" : 2,
					"patching_rect" : [ 106.0, 354.0, 38.0, 29.0 ],
					"fontsize" : 20.0,
					"cantchange" : 1,
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"id" : "obj-8",
					"fontname" : "Futura Condensed"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "AtodB",
					"numinlets" : 1,
					"hidden" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 117.0, 334.0, 39.0, 18.0 ],
					"fontsize" : 10.0,
					"outlettype" : [ "" ],
					"id" : "obj-9",
					"fontname" : "Courier"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "dac~ 1 2",
					"numinlets" : 2,
					"hidden" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 197.0, 501.0, 50.0, 17.0 ],
					"fontsize" : 9.0,
					"id" : "obj-10",
					"fontname" : "Helvetica"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "speaker 2",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 91.0, 407.0, 59.0, 17.0 ],
					"frgb" : [ 0.8, 0.611765, 0.380392, 1.0 ],
					"fontsize" : 9.0,
					"id" : "obj-17",
					"fontname" : "Verdana",
					"textcolor" : [ 0.8, 0.611765, 0.380392, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "speaker 1",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 29.0, 407.0, 59.0, 17.0 ],
					"frgb" : [ 0.8, 0.611765, 0.380392, 1.0 ],
					"fontsize" : 9.0,
					"id" : "obj-19",
					"fontname" : "Verdana",
					"textcolor" : [ 0.8, 0.611765, 0.380392, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "output gain",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 34.0, 45.0, 63.0, 17.0 ],
					"frgb" : [ 0.8, 0.611765, 0.380392, 1.0 ],
					"fontsize" : 9.0,
					"id" : "obj-11",
					"fontname" : "Verdana",
					"textcolor" : [ 0.8, 0.611765, 0.380392, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "gain~",
					"numinlets" : 2,
					"numoutlets" : 2,
					"patching_rect" : [ 32.0, 62.0, 65.0, 327.0 ],
					"outlettype" : [ "signal", "int" ],
					"orientation" : 2,
					"interp" : 119.0,
					"inc" : 1.03,
					"id" : "obj-12"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "gains",
					"text" : "p gains",
					"numinlets" : 3,
					"hidden" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 196.0, 456.0, 51.0, 17.0 ],
					"fontsize" : 9.0,
					"outlettype" : [ "signal", "signal" ],
					"id" : "obj-39",
					"fontname" : "Helvetica",
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 221.0, 201.0, 225.0, 275.0 ],
						"bglocked" : 0,
						"defrect" : [ 221.0, 201.0, 225.0, 275.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Helvetica",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadmess 1",
									"numinlets" : 1,
									"numoutlets" : 1,
									"patching_rect" : [ 98.0, 32.0, 60.0, 17.0 ],
									"fontsize" : 9.0,
									"outlettype" : [ "" ],
									"id" : "obj-1",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "preset",
									"numinlets" : 1,
									"margin" : 4,
									"numoutlets" : 4,
									"patching_rect" : [ 98.0, 56.0, 47.0, 27.0 ],
									"bubblesize" : 8,
									"outlettype" : [ "preset", "int", "preset", "int" ],
									"spacing" : 2,
									"id" : "obj-2",
									"preset_data" : [ 										{
											"number" : 1,
											"data" : [ 6, "<invalid>", "gain~", "list", 128, 10.0, 6, "<invalid>", "gain~", "list", 128, 10.0, 6, "<invalid>", "gain~", "list", 132, 21.5, 6, "<invalid>", "gain~", "list", 132, 10.0, 6, "<invalid>", "gain~", "list", 131, 10.0, 6, "<invalid>", "gain~", "list", 132, 10.0, 6, "<invalid>", "gain~", "list", 128, 21.5, 6, "<invalid>", "gain~", "list", 128, 10.0 ]
										}
 ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "gain~",
									"numinlets" : 2,
									"numoutlets" : 2,
									"patching_rect" : [ 63.0, 97.0, 20.0, 121.0 ],
									"outlettype" : [ "signal", "int" ],
									"orientation" : 2,
									"id" : "obj-25"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "gain~",
									"numinlets" : 2,
									"numoutlets" : 2,
									"patching_rect" : [ 37.0, 97.0, 20.0, 121.0 ],
									"outlettype" : [ "signal", "int" ],
									"orientation" : 2,
									"id" : "obj-26"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"patching_rect" : [ 164.0, 41.0, 15.0, 15.0 ],
									"outlettype" : [ "int" ],
									"id" : "obj-27",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"numinlets" : 1,
									"bgcolor" : [ 0.866667, 0.866667, 0.866667, 1.0 ],
									"htextcolor" : [ 0.870588, 0.870588, 0.870588, 1.0 ],
									"numoutlets" : 2,
									"patching_rect" : [ 164.0, 62.0, 35.0, 17.0 ],
									"fontsize" : 9.0,
									"outlettype" : [ "float", "bang" ],
									"triscale" : 0.9,
									"id" : "obj-28",
									"fontname" : "Helvetica"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 62.0, 227.0, 15.0, 15.0 ],
									"id" : "obj-33",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"patching_rect" : [ 62.0, 68.0, 15.0, 15.0 ],
									"outlettype" : [ "signal" ],
									"id" : "obj-34",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 36.0, 227.0, 15.0, 15.0 ],
									"id" : "obj-35",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"patching_rect" : [ 36.0, 68.0, 15.0, 15.0 ],
									"outlettype" : [ "signal" ],
									"id" : "obj-36",
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-36", 0 ],
									"destination" : [ "obj-26", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-34", 0 ],
									"destination" : [ "obj-25", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-28", 0 ],
									"destination" : [ "obj-26", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-28", 0 ],
									"destination" : [ "obj-25", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-27", 0 ],
									"destination" : [ "obj-28", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-26", 0 ],
									"destination" : [ "obj-35", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-25", 0 ],
									"destination" : [ "obj-33", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 2 ],
									"destination" : [ "obj-28", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 2 ],
									"destination" : [ "obj-26", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 2 ],
									"destination" : [ "obj-25", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"globalpatchername" : "",
						"default_fontname" : "Helvetica",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontsize" : 12.0,
						"fontname" : "Helvetica"
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "meter~",
					"warmcolor" : [ 0.388235, 0.168627, 1.0, 1.0 ],
					"ntepidleds" : 5,
					"numinlets" : 1,
					"bgcolor" : [ 0.0, 0.184314, 0.211765, 1.0 ],
					"numleds" : 18,
					"hotcolor" : [ 0.811765, 0.356863, 0.635294, 1.0 ],
					"numoutlets" : 1,
					"patching_rect" : [ 92.0, 425.0, 54.0, 88.0 ],
					"outlettype" : [ "float" ],
					"coldcolor" : [ 0.552941, 1.0, 0.803922, 1.0 ],
					"overloadcolor" : [ 1.0, 0.498039, 0.0, 1.0 ],
					"tepidcolor" : [ 0.270588, 0.694118, 0.898039, 1.0 ],
					"id" : "obj-42"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "meter~",
					"warmcolor" : [ 0.388235, 0.168627, 1.0, 1.0 ],
					"ntepidleds" : 5,
					"numinlets" : 1,
					"bgcolor" : [ 0.0, 0.184314, 0.211765, 1.0 ],
					"numleds" : 18,
					"hotcolor" : [ 0.811765, 0.356863, 0.635294, 1.0 ],
					"numoutlets" : 1,
					"patching_rect" : [ 30.0, 425.0, 54.0, 88.0 ],
					"outlettype" : [ "float" ],
					"coldcolor" : [ 0.552941, 1.0, 0.803922, 1.0 ],
					"overloadcolor" : [ 1.0, 0.498039, 0.0, 1.0 ],
					"tepidcolor" : [ 0.270588, 0.694118, 0.898039, 1.0 ],
					"id" : "obj-43"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "stop all sounds",
					"linecount" : 2,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 252.0, 128.0, 76.0, 34.0 ],
					"frgb" : [ 0.8, 0.611765, 0.380392, 1.0 ],
					"fontsize" : 12.0,
					"id" : "obj-24",
					"fontname" : "Helvetica",
					"textcolor" : [ 0.8, 0.611765, 0.380392, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 200.0, 127.0, 40.0, 40.0 ],
					"outlettype" : [ "bang" ],
					"id" : "obj-32"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"numinlets" : 1,
					"bgcolor" : [ 0.058824, 0.25098, 0.25098, 1.0 ],
					"numoutlets" : 0,
					"patching_rect" : [ 192.0, 118.0, 142.0, 58.0 ],
					"border" : 1,
					"rounded" : 0,
					"id" : "obj-40"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 199.0, 66.0, 33.0, 33.0 ],
					"id" : "obj-46"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Start Audio",
					"linecount" : 2,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 252.0, 65.0, 66.0, 34.0 ],
					"frgb" : [ 0.8, 0.611765, 0.380392, 1.0 ],
					"fontsize" : 12.0,
					"id" : "obj-51",
					"fontname" : "Helvetica",
					"textcolor" : [ 0.8, 0.611765, 0.380392, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"numinlets" : 1,
					"bgcolor" : [ 0.058824, 0.25098, 0.25098, 1.0 ],
					"numoutlets" : 0,
					"patching_rect" : [ 192.0, 55.0, 142.0, 58.0 ],
					"border" : 1,
					"rounded" : 0,
					"id" : "obj-52"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-32", 0 ],
					"destination" : [ "obj-21", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-54", 0 ],
					"destination" : [ "obj-61", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-61", 1 ],
					"destination" : [ "obj-15", 3 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-61", 0 ],
					"destination" : [ "obj-41", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-60", 0 ],
					"destination" : [ "obj-15", 3 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-60", 0 ],
					"destination" : [ "obj-15", 2 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-48", 0 ],
					"destination" : [ "obj-60", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 0 ],
					"destination" : [ "obj-41", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-57", 0 ],
					"destination" : [ "obj-41", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-48", 0 ],
					"destination" : [ "obj-57", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 0 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-65", 0 ],
					"destination" : [ "obj-33", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-64", 0 ],
					"destination" : [ "obj-36", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 0 ],
					"destination" : [ "obj-9", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-59", 0 ],
					"destination" : [ "obj-33", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-58", 0 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-56", 0 ],
					"destination" : [ "obj-48", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-50", 0 ],
					"destination" : [ "obj-48", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-48", 1 ],
					"destination" : [ "obj-37", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-48", 0 ],
					"destination" : [ "obj-28", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-45", 0 ],
					"destination" : [ "obj-15", 2 ],
					"hidden" : 0,
					"midpoints" : [ 535.5, 459.0, 387.833344, 459.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-44", 0 ],
					"destination" : [ "obj-41", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 0 ],
					"destination" : [ "obj-45", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 0 ],
					"destination" : [ "obj-43", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 1 ],
					"destination" : [ "obj-42", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 0 ],
					"destination" : [ "obj-10", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 1 ],
					"destination" : [ "obj-10", 1 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 0 ],
					"destination" : [ "obj-49", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-36", 0 ],
					"destination" : [ "obj-23", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 0 ],
					"destination" : [ "obj-18", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 0 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-34", 0 ],
					"destination" : [ "obj-20", 1 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-33", 2 ],
					"destination" : [ "obj-64", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-65", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-28", 0 ],
					"destination" : [ "obj-15", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-28", 0 ],
					"destination" : [ "obj-15", 2 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-26", 0 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-34", 0 ],
					"hidden" : 1,
					"midpoints" : [ 489.5, 64.5, 509.5, 64.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-63", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-20", 0 ],
					"destination" : [ "obj-13", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-16", 0 ],
					"destination" : [ "obj-20", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-15", 0 ],
					"destination" : [ "obj-39", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-13", 0 ],
					"destination" : [ "obj-67", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-13", 0 ],
					"destination" : [ "obj-35", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-12", 1 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-12", 1 ],
					"destination" : [ "obj-39", 2 ],
					"hidden" : 1,
					"midpoints" : [ 87.5, 396.0, 237.5, 396.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-15", 0 ],
					"destination" : [ "obj-39", 1 ],
					"hidden" : 1,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
