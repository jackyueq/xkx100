// /d/changan/center.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "����㳡");
	set  ("long",  @LONG
������ǳ����ǵ����ģ���������������ֽ����ڴˡ��㳡����һ
��Ρ��ߴ����¥������ǰ�����б��Ĺ�¥ң���Ӧ��������Щ���ơ�
ÿ���峿�����������������ŵ����������򳤰��ǵĴ��С�·��
��ˮ�����������˳����ϡ�
LONG);
	//set("item_desc",  (["  ***  "  :  "  ***  ",  ]));

	set("exits",  ([  //sizeof()  ==  4
		"north" :  __DIR__"northroad2",
		"south" :  __DIR__"southroad2",
		"west"  :  __DIR__"westroad2",
		"east"  :  __DIR__"eastroad2",
		"up"    :  __DIR__"zhonglou",
	]));
	set("objects",  ([  //sizeof()  ==  1
//		__DIR__"npc/libai"  :  1,
	]));
	set("outdoors",  "changan");
	set("coor/x", -5040);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
