// /d/changan/eastgate.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "������");
	set  ("long",  @LONG
������ǳ�������----�����š�����Ϊ�೯�Ŷ�����Ȼ��ͬ���죬
��ǽ��ʯ�ҡ�Ŵ�׺������ɣ��������������˳����������Ǻӣ�������
���������š�
LONG);
	//set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"eastroad1",
		"east"  :  __DIR__"baqiao",
	]));
	set("objects",  ([  //sizeof()  ==  1
		"/d/city/npc/wujiang"  :  1,
		"/d/city/npc/bing"  :  3,
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5010);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
