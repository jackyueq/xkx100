// /d/changan/southgate.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "������");
	set  ("long",  @LONG
������ǳ�������----�����š�����Ϊ�೯�Ŷ�����Ȼ��ͬ���죬
��ǽ��ʯ�ҡ�Ŵ�׺������ɣ��������������˳��ű��ǹٵ��������ٱ�
�������š����м�������ֵ�Ĺٱ�������¥����Ϣ��
LONG);
	//set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
	set("exits",  ([  //sizeof()  ==  4
		"north"  :  __DIR__"southroad1",
		"south"  :  __DIR__"road5",
		"up"     :  __DIR__"kuixinglou",
	]));
	set("objects",  ([  //sizeof()  ==  1
		"/d/city/npc/wujiang"  :  1,
		"/d/city/npc/bing"  :  3,
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5040);
	set("coor/y", 970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
